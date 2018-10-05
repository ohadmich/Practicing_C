/*****************************************************************************************************
 This code gets an array of length N as an input, builds a heap out of it and then apply q operations
 each one of then is either insertion of a new element while maintaining order or printing max value.
 ****************************************************************************************************/

#include <iostream>
using namespace std;
#define L int(2e5)

// A utility function for swapping two elements in an array
void Swap(int* A, int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}
// A utility function for printing arrays
void printArray(int* A, int N)
{
    for(int i=1; i<=N; i++) cout << A[i] << " ";
}
// A function for ordering a max heap after replacing the root 
void maxHeapify(int* A, int indx, int N)
{
    // Define the indices of the left and right children
    int left = 2*indx, right = 2*indx +1;
    int largest = indx;

    // If the node doesn't have children - return
    if(left > N) return;
    // Check if the left child is the largest
    if(A[left] > A[indx] && A[left] >= A[right]) largest = left;
    // Check if the right child is the largest
    else if (A[right] > A[indx] && A[right] >= A[left]) largest = right;
    // If the root node is not the largest
    if(largest != indx)
    {
        Swap(A, indx, largest); // Swap nodes
        maxHeapify(A, largest, N); // Run function again on the next subtree
    }
}
// A function that orders an array in a max heap form
void orderMaxheap(int* A, int N)
{
    for(int i = N/2; i>0; i--) maxHeapify(A, i, N);
}
// A function to insert a new element and maintains max heap ordering
void insertNum(int* A, int num, int &N)
{
    N = N + 1; // increase array size
    A[N] = num; // add new element at the end
    int i = N; // initialize index
    // while A[i] is larger than its parent, swap them 
    while(i > 1 & A[i/2] < A[i])
    {
        Swap(A, i/2, i);
        i = i/2;
    }
}

void printMax(int* A)
{
    cout << A[1] << endl;
}

int main()
{
    int N, q, temp, A[L] = {};
    // Read size of initial array
    cin >> N;
    // Read array
    for(int i=1; i<=N; i++)
    {
        cin >> temp;
        A[i] = temp;
    }
    // Ordering the heap
    orderMaxheap(A, N);
    // Applying operations
    cin >> q;
    while(q--)
    {
        // Read operation type
        int type;
        cin >> type;
        // If you get an "inset" operation
        if(type == 1)
        {
            int newnum;
            cin >> newnum;
            insertNum(A, newnum, N);
        }
        // If you get a "max" operation
        else if(type == 2)
        {
            printMax(A);
        }
    }
    return 0;
}