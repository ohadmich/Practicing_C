#include <stdio.h>
#include <stdlib.h>

// Define a Node with popularity data and pointer to next Node
struct Node{
    int pop;
    struct Node* next;
};

// A function to add a Node to the list
void addNode(struct Node** head, int newpop)
{
    // Create a new node with the new data
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->next = NULL;
    node->pop = newpop;

    // if the list is empty, add the node as head
    if (*head == NULL) *head = node;
    // else, traverse the list and add node at the end
    else
    {
        struct Node* current = *head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = node;
    }
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
    int N, temp;
    struct Node* head = NULL;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d", &temp);
        addNode(&head, temp);
    }

    printList(head);
    
    return 0;
}