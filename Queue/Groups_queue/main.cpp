#include <iostream>
using namespace std;
#define Nmax 100000

int queue[Nmax]={}, queue1[Nmax]={}, queue2[Nmax]={}, queue3[Nmax]={}, queue4[Nmax]={};
int front = 0, front1 = 0, front2 = 0, front3 = 0, front4 = 0;
int rear = 0, rear1 = 0, rear2 = 0, rear3 = 0, rear4 = 0;

bool exist(int gr){
    int current = front;
    while(current < rear)
    {
        if(queue[current] == gr)
        return true;
        current = current + 1;
    }
    return false;
}

int main()
{
    int N, group, roll;
    char ch;

    cin >> N;
    while(N--)
    {
        cin >> ch;
        if(ch == 'E')
        {
            cin >> group;
            cin >> roll;
            if(group==1)
            {
                if(!exist(1))
                {
                    queue[rear] = 1;
                    rear = rear + 1;
                }
                queue1[rear1] = roll;
                rear1 = rear1 + 1;
            }
            else if(group==2)
            {
                if(!exist(2))
                {
                    queue[rear] = 2;
                    rear = rear + 1;
                }
                queue2[rear2] = roll;
                rear2 = rear2 + 1;
            }
            else if(group==3)
            {
                if(!exist(3))
                {
                    queue[rear] = 3;
                    rear = rear + 1;
                }
                queue3[rear3] = roll;
                rear3 = rear3 + 1;
            }
            else if(group==4)
            {
                if(!exist(4))
                {
                    queue[rear] = 4;
                    rear = rear + 1;
                }
                queue4[rear4] = roll;
                rear4 = rear4 + 1;
            }
        }
        else if(ch == 'D')
        {
            if(queue[front] == 1) 
            {
                cout << 1 << ' ' << queue1[front1] << '\n';
                front1 = front1 +1;
                if(front1 == rear1) front = front +1;
            }
            else if(queue[front] == 2)
            {
                cout << 2 << ' ' << queue2[front2] << '\n';
                front2 = front2 +1;
                if(front2 == rear2) front = front +1;
            }
            else if(queue[front] == 3)
            {
                cout << 3 << ' ' << queue3[front3] << '\n';
                front3 = front3 +1;
                if(front3 == rear3) front = front +1;
            }
            else if(queue[front] == 4)
            {
                cout << 4 << ' ' << queue4[front4] << '\n';
                front4 = front4 +1;
                if(front4 == rear4) front = front +1;
            }
        }
    }
    return 0;
}