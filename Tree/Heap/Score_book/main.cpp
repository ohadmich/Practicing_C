#include <iostream>
using namespace std;
#define L int(1e5 + 1)

// Define arrays for max and min heaps
int Amax[L] = {}, Amin[L] = {}, N = 0;

// Print max and min heaps
void print()
{ 
    for(int i=1; i<=N; i++)
    {
        cout << Amax[i] << " ";
    }
    cout << endl;
    for(int i=1; i<=N; i++)
    {
        cout << Amin[i] << " ";
    }
    cout << endl;
}

// Bubble the max value up - for ordering heaps after addition from the tail
void Bubblemax()
{
    // Return if the heap is empty
    if(N<1) return;
    // Define current node index and parent index
    int i = N, p = N/2;
    /* Order the heap*/
    while(p >= 1)
    {
        // Swap parent and child if the child is larger
        if(Amax[p] < Amax[i])
        {
            int temp = Amax[i];
            Amax[i] = Amax[p];
            Amax[p] = temp;
        }
        i = i/2;
        p = p/2;
    }
}

// Bubble the min value up - for ordering heaps after addition from the tail
void Bubblemin()
{
    // Return if the heap is empty
    if(N<1) return;
    // Define current node index and parent index
    int i = N, p = N/2;
    /* Order the heap*/
    while(p >= 1)
    {
        // Swap parent and child if the child is smaller
        if(Amin[p] > Amin[i])
        {
            int temp = Amin[i];
            Amin[i] = Amin[p];
            Amin[p] = temp;
        }
        i = i/2;
        p = p/2;
    }
}


// Order the max heap top down
void maxHeapify(int A[L], int n, int i)
{
    // Define left and right node indices
    int left = 2*i, right = 2*i +1;
    // Initialize largest to be i, then change if needed
    int largest = i;
    // If left is within the array bounds and its element is larger, change largest
    if( left <= n && A[left] > A[i]) largest = left;
    // If right is within the array bounds and its element is larger, change largest
    if(right <= n && A[right] > A[i]) largest = right;
    // If i is not the largest element, swap places and then check the new subtree
    if(largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, n, largest);
    }
}

// Order the min heap top down
void minHeapify(int A[L], int n, int i)
{
    // Define left and right node indices
    int left = 2*i, right = 2*i +1;
    // Initialize smallest to be i, then change if needed
    int smallest = i;
    // If left is within the array bounds and its element is smaller, change smallest
    if( left <= n && A[left] < A[i]) smallest = left;
    // If right is within the array bounds and its element is smaller, change smallest
    if(right <= n && A[right] < A[i]) smallest = right;
    // If i is not the smallest element, swap places and then check the new subtree
    if(smallest != i)
    {
        int temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
        maxHeapify(A, n, smallest);
    }
}

// Push new element to each heap and then order them
void Push(int X)
{
    // Add element to max heap and min heap
    N = N+1;
    Amax[N] = X;
    Amin[N] = X;
    // Order heaps
    Bubblemax();
    Bubblemin();

}

void Diff()
{
    // When the array is empty print -1
    if(N == 0){
        cout << -1 << endl;
        return;
    }
    // Compute max - min difference
    int diff = Amax[1] - Amin[1];
    // Print diff
    cout << diff << endl;
    // Delete elements
    Amax[1] = Amax[N];
    Amax[N] = 0;
    Amin[1] = Amin[N];
    Amin[N] = 0;
    N = N - 1;
    // Order heaps
    maxHeapify(Amax, N, 1);
    minHeapify(Amin, N, 1);

}

void CountHigh()
{
    // Create a copy of the max heap
    int A[L]={};
    for(int i = 1; i<=N; i++)
    {
        A[i] = Amax[i];
    }
    // Initialize count and save max value
    int count = 0, max = A[1], n = N;
    // Pop max and reorder until you get a different max
    while(A[1] == max)
    {
        // Pop max and move the last element to the top
        A[1] = A[n];
        A[n] = 0;
        n = n-1;
        // Order heap
        maxHeapify(A, n, 1);
        // Count
        count++;
    }
    // print number of max value elements
    cout << count << endl;

}

void CountLow()
{
    // Create a copy of the min heap
    int A[L]={};
    for(int i = 1; i<=N; i++)
    {
        A[i] = Amin[i];
    }
    // Initialize count and save min value
    int count = 0, min = A[1], n = N;
    // Pop max and reorder until you get a different min
    while(A[1] == min)
    {
        // Pop min and move the last element to the top
        A[1] = A[n];
        A[n] = 0;
        n = n-1;
        // Order heap
        minHeapify(A, n, 1);
        // Count
        count++;
    }
    // print number of min value elements
    cout << count << endl;
}

int main()
{
    // Define variables
    int Q, X;
    string Op;
    // Read number of operations to perform
    cin >> Q;
    while(Q--)
    {
        // Read operation name
        cin >> Op;
        if(Op == "Push")
        {
            cin >> X;
            Push(X);
            print();
        }
        else if(Op == "Diff")
        {
            Diff();
        }
        else if(Op == "CountHigh")
        {
            CountHigh();
        }
        else if(Op == "CountLow")
        {
            CountLow();
        }
    }

    return 0;
}