
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


