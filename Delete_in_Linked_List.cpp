# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void Display_Linked_List(struct Node* head)
{
    while(head != NULL)
    {
        cout << "Elements: " << head->data << endl;
        head = head->next;
    }
}

struct Node* Delete_First_Element(struct Node* head)
{
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node* Delete_At_Index(struct Node* head, int index)
{
    struct Node* p = head;
    struct Node* q = head->next;

    int i = 0;
    while(i < index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);
    return head;
}

struct Node* Delete_Last_Element(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

struct Node* Delete_Element(struct Node* head, int element)
{
    struct Node* p = head;
    struct Node* q = head->next;

    while(q->data != element && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if(q->data == element)
    {
        p->next = q->next;
        free(q);
    }

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
    second->data = 4;
    second->next = third;
    third->data = 7;
    third->next = fourth;
    fourth->data = 9;
    fourth->next = NULL;

    cout << "Initial List: " << endl;
    Display_Linked_List(head);


    // head = Delete_First_Element(head);
    // cout << "List after Delete First Element: " << endl;
    // Display_Linked_List(head);


    // int index = 2;
    // head = Delete_At_Index(head, index);
    // cout << "List After Delete at Index: " << index << endl;
    // Display_Linked_List(head);

    // head = Delete_Last_Element(head);
    // cout << "List After Delete Last Element: " << endl;
    // Display_Linked_List(head);

    int element = 4;
    head = Delete_Element(head, element);
    cout << "List After Delete particular Element: " << endl;
    Display_Linked_List(head);


    return 0;
}