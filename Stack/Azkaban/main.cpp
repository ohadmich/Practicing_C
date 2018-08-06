/************************************************************************************
 Computes for each element in a number series, the closest larger number with smaller index - x, 
 the next colsest number with larger index - y and outputs their sum. 
 ************************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;
#define L int(1e5 +1)

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
    long long A[L];
    int x[L], y[L], N;

    // read number of elements
    cin >> N;
    // read all elements into array A
    for(int i=0; i<N; i++)
    {
        cin >> A[i];
    }
    
    /***** find y - the closest larger number with larger index in array A  *****/
    clearStack();
    // The last element has no y -> so set it to -1
    y[N-1] = -1;
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
        // keep index in array y, add 1 since we asked to print indices starting at 1
        if (indx == -1) y[i] = -1;
        else y[i] = indx +1;
        // push last element index to stack
        push(i);
    }

    /***** find x - the closest larger number with smaller index in array A  *****/
    clearStack();
    x[0] = -1;
    push(0);
    for(int i=1; i<N; i++)
    {
        int indx = topElement();
        while(!isEmpty() && A[indx]<=A[i])
        {
            pop();
            indx = topElement();
        }
            if (indx == -1) x[i] = -1;
            else x[i] = indx + 1;
            push(i);
    }

    /***** print x+y *****/
    for(int i=0; i<N; i++)
    {
        cout << x[i] + y[i] << " ";
    }

    return 0;
}
