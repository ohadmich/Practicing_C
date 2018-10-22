/********************************************************************************************************
This code takes a list of N ranks of people and deletes K of them based on a rule described below.
inputs: The number of test cases - T, the number of people in the list - N and the number of people to be
deleted - K, a list of N numbers representing the rank/popularity of each person. The code creates a 
linked list out of the ranks and deletes K persons from the list based on the following rule: if the 
next person has higher rank - delete the current person, if there is no next person with higher rank 
(which means you reached the end of the list) delete the last person on the list.
Finally the program prints the resulting list.
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// define a Node that contains data and pointer to next Node
struct Node{
    int data;
    struct Node* next;
};

// a function to add a Node at the head of the list
void addNode(struct Node** head, int newdata)
{
    // Create a new node with the new data
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = newdata;
    // set next Node to be the current head
    node->next = *head;
    // set head to be our new node
    *head = node;
}

// a function to delete the node that comes after "current"
void delNode(struct Node** current, bool delhead)
{
    // if the node to be deleted is the head
    if (delhead)
    {
        struct Node* tempNode = *current;
        *current = (*current)->next;
        free(tempNode);
    }
    // else, for any other node
    else
    {
        struct Node* tempNode = (*current)->next;
        (*current)->next = (*current)->next->next;
        free(tempNode);
        tempNode = NULL;
    }
}

// non recursive function for reversing lists:
struct Node* revlist(struct Node* head)
{
    struct Node* current = head, *PREV = NULL, *NEXT = NULL;
    if (current == NULL) return current;
    while(current->next != NULL)
    {
        NEXT = current->next;
        current->next = PREV;
        PREV = current;
        current = NEXT;
    }
    current->next = PREV;
    return current;
}

// a helper function to reverse a linked list
struct Node* rev(struct Node* current, struct Node* PREV)
{
    // if the list is empty, return empty list
    if (current == NULL) return current;
    // if the end of the list was reached, connect the node to previous and return node
    else if (current->next == NULL)
    {
        current->next = PREV;
        return current;
    }
    // in the general case
    else
    {
        // save next node into NEXT
        struct Node* NEXT = current->next;
        // set the next node to be the previous one
        current->next = PREV;
        // update previos node to be the current node for next iteration
        PREV = current;
        return rev(NEXT, PREV);
    }
}

// recursive function to reverse a list
struct Node* reverseList(struct Node* head)
{
    return rev(head, NULL);
}

// a function to print the linked list
void printList(struct Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

// create a stack for Node pointers
struct Node* listStack[100000] = {};
int top = -1;

// a function for pushing a node to the stack
void push(struct Node* node)
{
    top = top+1;
    listStack[top] = node;
}

// a function to check if stack is empty
bool isEmpty()
{
    return top == -1;
}

// a function for popping elements off of the stack
void pop()
{
    if (isEmpty()) return;
    else top = top-1;
}

// a function that returns the top element in the stack
struct Node* topElement()
{
    return listStack[top];
}

// a function to initialize the stack
void intstack()
{
    top = -1;
}

int main()
{
    int T, N, K, temp;
    // read number of test cases
    scanf("%d", &T);
    while(T--)
    {
        struct Node* head = NULL;
        // read number of friends, N, and who many of them should be deleted, K
        scanf("%d", &N);
        scanf("%d", &K);
        /**** read list of popularity values into the linked list****/
        while(N--)
        {
            scanf("%d", &temp);
            addNode(&head, temp);
        }
        // reverse the list to allow easier operations on the list
        head = revlist(head);
        /**** delete K freinds for which the next friend has higher popularity ****/
        intstack();
        push(head);
        while(K--)
        {
            struct Node* current = topElement();
            // keep in stack every node that obeys the rule
            while(current->next != NULL && current->data >= current->next->data)
            {
                current = current->next;
                push(current);
            }
            // pop the node that doesn't obey the rule
            pop();
            // if the stack is empty, delete the head
            if (isEmpty())
            {
                delNode(&head,1);
                push(head);
            }
            // else delete intermediate node
            else
            {
                current = topElement();
                delNode(&current,0);
            }
        }
        // print the resulting list
        printList(head);
        printf("\n");
    }

    return 0;
}