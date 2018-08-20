#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// define a Node with dataularity data and pointer to next Node
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
    // set next Node to head
    node->next = *head;
    // set head to be node
    *head = node;
}

// a function to delete the node that comes after current
void delNode(struct Node** current, bool delhead)
{
    if (delhead)
    {
        struct Node* tempNode = *current;
        *current = (*current)->next;
        free(tempNode);
    }
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
int top = 0;

void push(struct Node* node)
{
    top = top+1;
    listStack[top] = node;
}

bool isEmpty()
{
    return top == -1;
}

void pop()
{
    if (isEmpty()) return;
    else top = top-1;
}

struct Node* topElement()
{
    return listStack[top];
}

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
        // read list of popularity values into our linked list
        while(N--)
        {
            scanf("%d", &temp);
            addNode(&head, temp);
        }
        // reverse list
        head = revlist(head);
        // delete K freinds
        while(K--)
        {
            bool deleteFriend = 0;
            // first check if the head should be deleted
            if(head->next->data > head->data)
            {
                delNode(&head,1);
                continue;
            }
            // check the the rest of the list
            struct Node* current = head;
            while(current->next->next != NULL)
            {
                if( (current->next->next->data) > (current->next->data) )
                {
                    delNode(&current,0);
                    deleteFriend = 1;
                    break;
                }
                current = current->next;
            }
            // delete last node if we didn't find any node to delete
            if(!deleteFriend) delNode(&current,0);
        }
        printList(head);
        printf("\n");
    }

    return 0;
}