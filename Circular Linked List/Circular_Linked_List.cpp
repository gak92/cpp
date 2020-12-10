# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

struct Node 
{
    int data;
    struct Node* next;
};

void Display_Circular_Linked_List(struct Node* head)
{
    struct Node* ptr = head;
    cout << "First Element: " << ptr->data <<endl;
    ptr = ptr->next;

    while(ptr != head)
    {
        cout << "Others Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}


int main(void)
{
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third = (struct Node*) malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*) malloc(sizeof(struct Node));

    head->data = 3;
    head->next = second;
    second->data = 5;
    second->next = third;
    third->data = 7;
    third->next = fourth;
    fourth->data = 9;
    fourth->next = head;

    // Display Circular Linked List
    Display_Circular_Linked_List(head);



    return 0;
}