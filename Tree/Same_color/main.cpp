#include <iostream>
using namespace std;
#define Nmax 100000

int main()
{
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
    cout << -1 << " "; // The root has no ancestors with the same color
    for(int i=2; i<N+1; i++)
    {
        int current = parents[i]; 
        while(current != 0 && color[current] != color[i])
        {
            current = parents[current];
        }
        if(current) cout << current << " ";
        else cout << -1 << " ";
    }
    return 0;
}
