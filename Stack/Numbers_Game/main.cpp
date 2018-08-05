#include <stdio.h>
#include <iostream>
using namespace std;

// Define global variables for handling stack
int top, stack[30001];

/***** Define utility stack functions *****/

bool isEmpty()
{
    if(top == -1) return 1;
    else return 0;
}

void push(int n)
{
    top++;
    stack[top] = n;
}

void pop()
{
    if(isEmpty()) cout << "Stack empty";
    else top--;
}

int topElement()
{
    if(isEmpty()) return -1;
    else return stack[top];
}

void clearStack()
{
    top = -1;
}


int main()
{
    long long A[30001];
    int x[30001], y[30001], N;

    // read number of elements
    cin >> N;
    // read all elements into array A
    for(int i=0; i<N; i++)
    {
        cin >> A[i];
    }
    
    /***** find x - the closest larger number with larger index in array A  *****/
    clearStack();
    // The last element has no x -> so set it to -1
    x[N-1] = -1;
    // push last element index into stack
    push(N-1);
    // traverse array A from end to begining
    for(int i=N-2; i>=0; i--)
    {
        // set compare index to the top element in stack
        int indx = topElement();
        // pop elements from stack until you reach the end or a larger element
        while(!isEmpty() && A[indx]<=A[i])
        {
            pop();
            indx = topElement();
        }
        // keep index in array x
        x[i] = indx;
        // push last element index to stack
        push(i);
    }

    /***** find y - the closest smaller number with larger index in array A  *****/
    clearStack();
    y[N-1] = -1;
    push(N-1);
    for(int i=N-2; i>=0; i--)
    {
        int indx = topElement();
        while(!isEmpty() && A[indx]>=A[i])
        {
            pop();
            indx = topElement();
        }
            y[i] = indx;
            push(i);
    }

    /***** print y[x] *****/
    for(int i=0; i<N; i++)
    {
        if (x[i] == -1) cout << -1 << " ";
        else
        {
            if(y[x[i]] == -1) cout << -1 << " ";
            else cout << A[y[x[i]]] << " ";
        }
    }

    return 0;
}
