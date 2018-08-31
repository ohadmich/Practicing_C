/*******************************************************************************************************
For a tree with N nodes where each node has one color out of C different colors, print for each node the
closest ancestor with the same color. If it does not exist, print -1.
********************************************************************************************************/

#include <iostream>
using namespace std;
#define Nmax 100000

int main()
{
    /* Read inputs */
    int N, C;
    int parents[Nmax]={}, color[Nmax]={};
    // Read Number of nodes and number of colors
    cin >> N;
    cin >> C;
    // Read parents list
    for(int i=2; i<N+1; i++)
    {
        cin >> parents[i];
    }
    // Read colors of nodes
    for(int i=1; i<N+1; i++)
    {
        cin >> color[i];
    }

    /* Analysis */
    // The root has no ancestors with the same color, so print -1
    cout << -1 << " ";
    // Traverse the tree nodes
    for(int i=2; i<N+1; i++)
    {
        // Initialize current to be the parent of the node in question
        int current = parents[i];
        // Move from one parent to the next until you find the same color or pass the root 
        while(current != 0 && color[current] != color[i])
        {
            current = parents[current];
        }
        // Print the node number of the closest parent with same color
        if(current) cout << current << " ";
        // Print -1 if it does not exist
        else cout << -1 << " ";
    }
    return 0;
}