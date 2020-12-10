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

// Insertion at first in Circular Linked List(CLL)
struct Node* Insert_At_First_CLL(struct Node* head, int data)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));     // create a node
    temp->data = data;                                                  // insert data
    temp->next = head;                                                  // point its next to current first node
    
    struct Node* ptr = head;        // create a pointer that point to head
    ptr = ptr->next;                // move it to next node

    while(ptr->next != head)        // run it until its next point to head
    {
        ptr = ptr->next;
    }
    ptr->next = temp;               // when its next point to head, update it to temp node (which create earlier)
    head = temp;                    // update head pointer to temp

    return head;
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
    cout << "Initial CLL: " << endl;
    Display_Circular_Linked_List(head);


    // Insertion in CLL
    int data = 1;
    head = Insert_At_First_CLL(head, data);
    cout << "After insertion " << data << "at first position:" << endl;
    Display_Circular_Linked_List(head);


    return 0;
}