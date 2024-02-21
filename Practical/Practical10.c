#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void add_at_end(struct node *head,int data)
{
    struct node *temp,*ptr;
    ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}
struct node *add_at_beg(struct node *head,int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    ptr->link=head;
    head=ptr;
    return head;
}
void add_at_pos(struct node *head,int pos,int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    struct node *ptr2=malloc(sizeof(struct node));
    ptr=head;
    ptr2->data=data;
    ptr2->link=NULL;
    pos--;
    while(pos!=1)
    {
        ptr=ptr->link;
        pos--; 
    }
    ptr2->link=ptr->link;
    ptr->link=ptr2;
}
struct node* del_at_first(struct node* head)
{
    if(head==NULL)
    {
        printf("linked list is empty\n");
    }
    else 
    {
        struct node* temp=head;
        head=head->link;
        free(temp);
        temp=NULL;
        return head;
    }
}
void del_at_end(struct node *head)
{
    if(head==NULL)
    {
        printf("linked list is empty\n");
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp=head;
        while(temp->link->link!=NULL)
        {
            temp=temp->link;
        }
        free(temp->link);
        temp->link=NULL;
    }
}

void del_at_pos(struct node *head,int pos)
{
    struct node *ptr=head;
    struct node *ptr2=head;
    if(head==NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        while(pos!=1)
        {
            ptr2=ptr;
            ptr=ptr->link;
            pos--;
        }
        ptr2->link=ptr->link;
        free(ptr);
        ptr=NULL;
    }
}
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=23;
    head->link=NULL;
    struct node *current=malloc(sizeof(struct node));
    current->data=24;
    current->link=NULL;
    head->link=current;
    current=malloc(sizeof(struct node));
    current->data=25;
    current->link=NULL;
    head->link->link=current;
    current=malloc(sizeof(struct node));
    current->data=26;
    current->link=NULL;
    head->link->link->link=current;
    add_at_end(head,27);
    head=add_at_beg(head,22);
    add_at_pos(head,3,32);
    struct node *ptr=NULL;
    ptr=head;
    printf("After adding element in linked list :");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

    head=del_at_first(head);
    del_at_end(head);
    del_at_pos(head,3);
    ptr=head;
    printf("\nAfter delecting element in linked list :");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
