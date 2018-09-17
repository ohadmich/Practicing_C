/******************************************************************************************************
 This code gets a binary tree as an input, Builds a tree, measures it's height and prints the result
 *****************************************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

// Define a node for our tree
struct Node{
    int data;
    Node* left;
    Node* right;
};

// A function to add a node to the left of current (when addleft is 1) or to the right
void addNode(Node* current, int data, bool addleft)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    if (addleft) current->left = node;
    else current->right = node;
}

// A recursive function to find the tree height
int findHeight(Node* current)
{
    if (current == NULL) return 0;
    return max(findHeight(current->left)+1, findHeight(current->right) +1);
}

int main()
{
    int N, temp;
    Node* root = NULL;
    // Read number of nodes
    cin >> N;
    /**** Build the tree ****/
    while(N--)
    {
        // Read data
        cin >> temp;
        Node* current = root, *previous = root;
        bool addleft = false;
        // Add the root if needed
        if (root == NULL)
        {
            root = (Node*)malloc(sizeof(Node));
            root->data = temp;
            root->left = NULL;
            root->right = NULL;
            continue;
        }
        // Traverse the tree and look for the right place for the next node
        while(current != NULL)
        {
            // if the new node is smaller go left
            if(temp <= current->data)
            {
                previous = current;
                current = current->left;
                // if the left node is empty, toggle addleft to true
                if(current == NULL) addleft=true;
            }
            // if the new node is larger go right
            else if(temp > current->data) previous = current, current = current->right;
        }
        addNode(previous, temp, addleft);
    }

    /**** Find the tree's height and print it ****/
    int h = findHeight(root);
    cout << h;
    return 0;
}