# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;


struct Stack
{
    int size;       // size of the stack
    int top;        // point to top element of stack
    int *arr;       // array to hold the elements

};

int isEmpty(struct Stack *st)
{
    if(st->top == -1)
    {
        // cout << "Stack is Empty" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int isFull(struct Stack *st)
{
    if(st->top == st->size-1)
    {
        // cout << "Stack is Full" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void push(struct Stack *st, int data)
{
    if(isFull(st))
    {
        cout << "Stack is overflow cannot push " << data << " into Stack." << endl;
    }
    else
    {
        st->top++;
        st->arr[st->top] = data;
    }   
}

int pop(struct Stack *st)
{
    int data;
    if(isEmpty(st))
    {
        cout << "Stack in underflow." << endl;
        return -1;
    }
    else
    {
        data = st->arr[st->top];
        st->top--;
        return data;
    }
}

/*
                                   top
    i =     0   1   2   3   4   5   6   7   8
    arr=    11  12  13  14  15  16  19

    i = 1 ====>   index =  6 - 1 + 1 = 6    ====>   arr[index] = arr[6] =   19
    i = 2 ====>   index =  6 - 2 + 1 = 5    ====>   arr[index] = arr[5] =   16
    i = 3 ====>   index =  6 - 3 + 1 = 4    ====>   arr[index] = arr[4] =   15
    i = 4 ====>   index =  6 - 4 + 1 = 3    ====>   arr[index] = arr[3] =   14
    i = 5 ====>   index =  6 - 5 + 1 = 2    ====>   arr[index] = arr[2] =   13
    i = 6 ====>   index =  6 - 6 + 1 = 1    ====>   arr[index] = arr[1] =   12
    i = 7 ====>   index =  6 - 7 + 1 = 0    ====>   arr[index] = arr[0] =   11
 
    i = 8 ====>   index =  6 - 8 + 1 = -1    ====>   (-1 < 0) ===> return -1

*/

int peek(struct Stack *st, int i)
{
    int index = st->top - i + 1;
    if(index<0)
    {
        cout << "Invalid Index" << endl;
        return -1;
    }
    else
    {
        return st->arr[index];
    }
}

int stack_Top(struct Stack *st)
{
    return st->arr[st->top];
}

int stack_Bottom(struct Stack *st)
{
    return st->arr[0];
}


int main(void)
{
    // struct Stack st;
    // st.size = 8;
    // st.top = -1;
    // st.arr = (int *) malloc(st.size * sizeof(int));

    struct Stack *st = (struct Stack *) malloc(sizeof(struct Stack));
    st->size = 8;
    st->top = -1;
    st->arr = (int *) malloc(st->size * sizeof(int));

    // Check if Stack is Empty or Full
    cout << "Initial Stack is Empty and check isEmpty() & isFull()" << endl;
    cout << "isEmpty = " << isEmpty(st) << endl;
    cout << "isFull = " << isFull(st) << endl;

    // Pushing an element into stack
    for(int i=0; i<8; i++)
    {
        push(st, i+11);
    }

    // Check if Stack is Empty or Full after pushing an element
    cout << "After pushing all elements, check isEmpty() & isFull()" << endl;
    cout << "isEmpty = " << isEmpty(st) << endl;
    cout << "isFull = " << isFull(st) << endl;

    // pushing Element after stack is full
    push(st, 19);


    // Now pop few elements and then push new elements
    cout << "Poped Element:" << pop(st) << endl;
    cout << "Poped Element:" << pop(st) << endl;
    push(st, 19);

    cout << "Top Element: " << st->arr[st->top] << endl;

    // printting Element of Stack
    for(int i=1; i<=st->top+1; i++)
    {
        cout << "Elements ---> " << peek(st, i) << endl;
    }

    // Stack Top and Bottom
    cout << "Stack Top: " << stack_Top(st) << endl;
    cout << "Stack Bottom: " << stack_Bottom(st) << endl;

    return 0;
}