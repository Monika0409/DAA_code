
#include<stdio.h>
#include<stdlib.h>
#define size 4
int top=-1,inp_array[size];
void push();
void pop();
void show();

int main()
{
  int choice;
  while(1)
  {
    printf("operation performed by the stack\n");
    printf("1.push the element\n2.pop the element\n3.show the element\n");
    printf("enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:push();
             break;
      case 2:pop();
             break;
      case 3:show();
             break;
      default:
             printf("enter valid choice\n"); 
    }
  }
}
void push()
{
  int x;
  if(top==size-1)
  {
    printf("overflow!!\n");
  }
  else
  {
     printf("\nenter element to be inserted to the stack\n");
     scanf("%d",&x);
     top=top+1;
     inp_array[top]=x;
  }
}
void pop()
{
  int x;
  if(top==-1)
  {
    printf("Underflow!!\n");
  }
  else
  {
    printf("popped element:%d\n",inp_array[top]);
    top=top-1;
  }
}
void show(){
  for (int i=top;i>=0;i--)  
    {  
        printf("\nprinting value...");
        printf("%d\n",inp_array[i]);  
    }  
    if(top == -1)   
    {  
        printf("Stack is empty\n");  
    }  
}





#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
void display();  
struct node   
{  
int val;  
struct node *next;  
};  
struct node *head;  
  
void main ()  
{  
    int choice=0;     
    printf("Stack operations using linked list\n");  
    while(choice != 4)  
    {  
        printf("\nChose one from the below options...\n");  
        printf("1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\nEnter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
        };  
    }  
}  
void push ()  
{  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("not able to push the element");   
    }  
    else   
    {  
        printf("Enter the value");  
        scanf("%d",&val);  
        if(head==NULL)  
        {         
            ptr->val = val;  
            ptr -> next = NULL;  
            head=ptr;  
        }   
        else   
        {  
            ptr->val = val;  
            ptr->next = head;  
            head=ptr;  
               
        }  
        printf("Item pushed");            
    }  
}  
  
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item popped");  
          
    }  
}  
void display()  
{  
    int i;  
    struct node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->val);  
            ptr = ptr->next;  
        }  
    }  
}  


