# include <stdio.h>
# include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void Display_Linked_List(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Value: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


int main(void)
{
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third = (struct Node*) malloc(sizeof(struct Node));
    struct Node* forth = (struct Node*) malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 19;
    third->next = forth;

    forth->data = 27;
    forth->next = NULL;

    Display_Linked_List(head);
    return 0;

}