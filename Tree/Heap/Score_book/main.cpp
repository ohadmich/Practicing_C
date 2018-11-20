/*******************************************************************************************************
 This code creates a score book with 5 different operations: Push # - add a number to the book. 
 Diff - Print the difference between the largest and smallest values in the book and then delete one
 instance of each one. CountHigh - Print the number of instances of the highest score that exist in the
 book. CountLow - Same as CountHigh, but for the lowest value in the book. Print - Print a max heap and
 min heap of the current data in the book.
 ******************************************************************************************************/

#include <iostream>
using namespace std;
#define L int(1e5 + 1)

// Define arrays for max and min heaps and a frequency array to keep account for repeating scores
int Amax[L] = {}, Amin[L] = {}, Freq[L] = {}, Nmin = 0, Nmax = 0;

// Print max and min heaps
void print()
{ 
    for(int i=1; i<=Nmax; i++)
    {
        cout << Amax[i] << " ";
    }
    cout << endl;
    for(int i=1; i<=Nmax; i++)
    {
        cout << Freq[Amax[i]] << " ";
    }
    cout << endl;
    for(int i=1; i<=Nmin; i++)
    {
        cout << Amin[i] << " ";
    }
    cout << endl;
}

// Bubble the max value up - for ordering heaps after addition from the tail
void Bubblemax(int i)
{
    // Return if the heap is empty
    if(Nmax<1) return;
    // Define parent index
    int p = i/2;
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
void Bubblemin(int i)
{
    // Return if the heap is empty
    if(Nmin<1) return;
    // Define parent index
    int p = i/2;
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
void maxHeapify(int i)
{
    // Define left and right node indices
    int left = 2*i, right = 2*i +1;
    // Initialize largest to be i, then change if needed
    int largest = i;
    // If left is within the array bounds and its element is larger, change largest
    if( left <= Nmax && Amax[left] > Amax[largest]) largest = left;
    // If right is within the array bounds and its element is larger, change largest
    if(right <= Nmax && Amax[right] > Amax[largest]) largest = right;
    // If i is not the largest element, swap places and then check the new subtree
    if(largest != i)
    {
        int temp = Amax[i];
        Amax[i] = Amax[largest];
        Amax[largest] = temp;
        maxHeapify(largest);
    }
}

// Order the min heap top down
void minHeapify(int i)
{
    // Define left and right node indices
    int left = 2*i, right = 2*i +1;
    // Initialize smallest to be i, then change if needed
    int smallest = i;
    // If left is within the array bounds and its element is smaller, change smallest
    if( left <= Nmin && Amin[left] < Amin[smallest]) smallest = left;
    // If right is within the array bounds and its element is smaller, change smallest
    if(right <= Nmin && Amin[right] < Amin[smallest]) smallest = right;
    // If i is not the smallest element, swap places and then check the new subtree
    if(smallest != i)
    {
        int temp = Amin[i];
        Amin[i] = Amin[smallest];
        Amin[smallest] = temp;
        minHeapify(smallest);
    }
}

// Push new element to each heap and then order them
void Push(int X)
{
    // Add element to max heap and min heap
    Nmax++;
    Nmin++;
    Amax[Nmax] = X;
    Amin[Nmin] = X;
    // Update frequency array
    Freq[X]++;
    // Order heaps
    Bubblemax(Nmax);
    Bubblemin(Nmin);

}
// Find the difference between the largest and smallest elements
void Diff()
{
    // Clear elements with zero frequency from heaps
    while(Nmax>0 && Freq[Amax[1]] == 0)
    {
        Amax[1] = Amax[Nmax];
        Nmax--;
        maxHeapify(1);
    }
    while(Nmin>0 && Freq[Amin[1]] == 0)
    {
        Amin[1] = Amin[Nmin];
        Nmin--;
        minHeapify(1);
    }
    // When the array is empty print -1
    if(Nmax == 0 || Nmin == 0){
        cout << -1 << endl;
        return;
    }
    // When there is only one element in the array, print zero and reduce N to 0  
    if(Amax[1] == Amin[1]){
        cout << 0 << endl;
        Freq[Amax[1]]--;
        return;
    }
    // Compute max - min difference
    int diff = Amax[1] - Amin[1];
    // Print diff
    cout << diff << endl;
    // Reduce frequency of min and max elements
    Freq[Amax[1]]--;
    Freq[Amin[1]]--;
    // Delete min and max elements
    Amax[1] = Amax[Nmax];
    Amin[1] = Amin[Nmin];
    Nmax--;
    Nmin--;
    // Order heaps
    maxHeapify(1);
    minHeapify(1);

}
// Print how many instances of the largest element exist
void CountHigh()
{
    // Clear elements with zero frequency from heaps
    while(Nmax>0 && Freq[Amax[1]] == 0)
    {
        Amax[1] = Amax[Nmax];
        Nmax--;
        maxHeapify(1);
    }
    // if the heap is empty, print -1 and return
    if(Nmax < 1)
    {
        cout << -1 << endl;
        return;
    }
    // print number of max value elements
    cout << Freq[Amax[1]] << endl;

}
// Count how many instances of the smallest element exist
void CountLow()
{
    // Clear elements with zero frequency from heaps
    while(Nmin>0 && Freq[Amin[1]] == 0)
    {
        Amin[1] = Amin[Nmin];
        Nmin--;
        minHeapify(1);
    }
    // if the heap is empty, print -1 and return
    if(Nmin < 1)
    {
        cout << -1 << endl;
        return;
    }
    // print number of min value elements
    cout << Freq[Amin[1]] << endl;
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
        else if(Op == "Print")
        {
            print();
        }
    }

    return 0;
}