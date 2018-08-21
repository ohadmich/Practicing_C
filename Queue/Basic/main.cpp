#include <iostream>
using namespace std;
#define Nmax 100

int queue[Nmax]={}, front = 0, rear = 0; 

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

int frontElement()
{
    return queue[front];
}

int main()
{
    int N, temp;
    char ch;
    cin >> N;
    while(N--)
    {
        cin >> ch;
        if (ch == 'E')
        {
            cin >> temp;
            enqueue(temp);
            cout << rear - front << "\n";
        }
        else if (ch == 'D')
        {
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