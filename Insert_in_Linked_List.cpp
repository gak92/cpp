# include <stdio.h>
# include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void Display_Linked_List(struct Node* ptr)
{
    while(ptr != NULL)
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* Insert_At_Begin(struct Node* head, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = data;
    temp->next = head;
    return temp;
}

struct Node* Insert_At_Index(struct Node* head, int data, int index)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = data;
    struct Node* p = head;

    int i = 0;
    while(i<index-1){
        p = p->next;
        i++;
    }

    temp->next = p->next;
    p->next = temp;
    return head;

}

struct Node* Insert_At_End(struct Node* head, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = data;
    struct Node* p = head;

    while(p->next != NULL)
    {
        p = p->next;
    }

    temp->next = p->next;
    p->next = temp;

    return head;
}

struct Node* Insert_After(struct Node* head, struct Node* curr, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = data;

    temp->next = curr->next;
    curr->next = temp;
    return head;

}

int main(void)
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* forth = (struct Node*)malloc(sizeof(struct Node*));

    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 19;
    third->next = forth;
    forth->data = 27;
    forth->next = NULL;

    // Show all elements in link list
    printf("\nInitial Linked List: ");
    Display_Linked_List(head);

    // Insert At the Begining of List, return head
    head = Insert_At_Begin(head, 3);
    printf("\nAfter Insert at the begining of list: ");
    Display_Linked_List(head);

    // Insert At the given Index
    head = Insert_At_Index(head, 40, 2);
    printf("\nAfter Insert at the given index of list: ");
    Display_Linked_List(head);

    // Insert At the End of the list
    head = Insert_At_End(head, 92);
    printf("\nAfter Insert at the end of list: ");
    Display_Linked_List(head);

    head = Insert_After(head, third, 41);
    printf("\nAfter Insert at given node in the list: ");
    Display_Linked_List(head);

    return 0;
}