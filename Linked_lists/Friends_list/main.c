#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a Node with popularity data and pointer to next Node
struct Node{
    int pop;
    struct Node* next;
};

// A function to add a Node at the head of the list
void addNode(struct Node** head, int newpop)
{
    // Create a new node with the new data
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->pop = newpop;
    // set next Node to head
    node->next = *head;
    // set head to be node
    *head = node;
}

void delNode(struct Node* current)
{
    struct Node* tempNode = current->next;
    current->next = current->next->next;
    free(tempNode);
    tempNode = NULL;
}

// recursive function to reverse a list
void reverseList(struct Node** head)
{
    // devide list to first node and the rest
    struct Node* first = *head;
    struct Node* rest = first->next;
    // if the list is empty - return
    if(*head == NULL) return;
    // if rest is NULL - return
    if (rest == NULL) return;
    // reverse the rest of the list
    reverseList(&rest);
    // link the reversed list to first and set the next of the first to NULL
    first->next->next = first;
    first->next = NULL;
    // change head pointer to rest
    *head = rest;
}    

void printList(struct Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->pop);
        head = head->next;
    }
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
        reverseList(&head);
        // delete K freinds
        while(K--)
        {
            bool deleteFriend = 0;
            // first check if the head should be deleted
            if(head->next->pop > head->pop)
            {
                struct Node* tempNode = head;
                head = head->next;
                free(tempNode);
                continue;
            }
            // check the the rest of the list
            struct Node* current = head;
            while(current->next->next != NULL)
            {
                if( (current->next->next->pop) > (current->next->pop) )
                {
                    delNode(current);
                    deleteFriend = 1;
                    break;
                }
                current = current->next;
            }
            // delete last node if we didn't find any node to delete
            if(!deleteFriend) delNode(current);
        }
        printList(head);
        printf("\n");
    }
    
    return 0;
}