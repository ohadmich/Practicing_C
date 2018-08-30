/****************************************************************************************************
A queue based on 4 groups, 'E' operation enqueue an element and place it behind the the last member of the
same group who is already in the queue. If there is no other member of that group, the element is added
at the end of the queue. 'D' operation print the group name and roll number of the element and dequeues
****************************************************************************************************/

#include <iostream>
using namespace std;
#define Nmax 100000

// Define four queues[1-4] to keep elements of each group and additional queue[0] for the the order of
// group appearance.
int queue[5][Nmax]={};
int front[5] = {}, rear[5] = {};
bool exist[5] = {};

int main()
{
    int N, group, roll;
    char ch;
    // Read number of operations to be done
    cin >> N;
    while(N--)
    {
        // Read the char that represents the operation
        cin >> ch;
        // Enqueue case
        if(ch == 'E')
        {
            // Read group number and roll number of the element
            cin >> group;
            cin >> roll;
            // Run over group numbers
            for(int i=1; i<5; i++)
            {
                // Check to which group the element is related
                if (group == i)
                {
                    // if the group doesn't exist in queue[0] then enqueue it
                    if(!exist[i])
                    {
                        queue[0][rear[0]] = i;
                        rear[0] = rear[0] + 1;
                        exist[i] = true;
                    }
                    // enqueue the roll number to the groups' queue
                    queue[i][rear[i]] = roll;
                    rear[i] = rear[i] + 1;
                }
            }
        }
        // Dequeue case
        else if(ch == 'D')
        {
            // Check which group is in the front
            group = queue[0][front[0]]; 
            {
                // Print the group number and roll number of the front element
                cout << group << ' ' << queue[group][front[group]] << '\n';
                // Deque element
                front[group] = front[group] +1;
                // If the dequeued element was the last one, then deque the group from queue[0]
                if(front[group] == rear[group]) front[0] = front[0] +1, exist[group] = false;
            }
        }
    }
    return 0;
}