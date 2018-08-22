/* A basic program to practice queues */

#include <iostream>
using namespace std;
#define Nmax 100

int queue[Nmax]={}, front = 0, rear = 0; 

// a function for adding an element to the queue from the rear
void enqueue(int num)
{
    if (rear == Nmax-1 )
    {
        cout << "OverFlow";
        return;
    }
    queue[rear] = num;
    rear = rear+1;
}

// a function for deleting an element from the front
void dequeue()
{
    if (front == rear)
    {
        cout << "UnderFlow";
        return;
    }
    queue[front] = 0;
    front = front+1;
}

// returns the front element
int frontElement()
{
    return queue[front];
}

int main()
{
    int N, temp;
    char ch;
    // read N, number of operations
    cin >> N;
    while(N--)
    {
        // read the char symbol that represents the action needed to be done
        cin >> ch;
        // if 'E' was recieved, enque the next number and print the length of the queue
        if (ch == 'E')
        {
            cin >> temp;
            enqueue(temp);
            cout << rear - front << "\n";
        }
        // if 'D' was recieved, print the front element, dequeue it and print the length of the queue
        else if (ch == 'D')
        {
            // if the queue is empty, print -1
            if (front == rear) cout << -1 << " ";
            else 
            {
                cout << frontElement() << " ";
                dequeue();
            }
            cout << rear - front << "\n";
        }
    }
    return 0;
}