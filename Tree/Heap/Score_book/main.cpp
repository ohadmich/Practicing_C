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

// Order the max heap
void maxHeapify()
{
    // Return if the heap is empty
    if(N<1) return;
    // define current node index and parent index
    int i = N, p = N/2;
    /* Order the heap*/
    while(p >= 1)
    {
        // Swap parent and child if they are not ordered
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

// Order the min heap
void minHeapify()
{
    // Return if the heap is empty
    if(N<1) return;
    // define current node index and parent index
    int i = N, p = N/2;
    /* Order the heap*/
    while(p >= 1)
    {
        // Swap parent and child if they are not ordered
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

// Push new element to each heap and then order them
void Push(int X)
{
    // Add element to max heap and min heap
    N = N+1;
    Amax[N] = X;
    Amin[N] = X;
    // Order heaps
    maxHeapify();
    minHeapify();

}

void Diff()
{
    // When the array is empty print -1
    if(N == 0){
        cout << -1;
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
    maxHeapify();
    minHeapify();

}

void CountHigh()
{

}

void CountLow()
{

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