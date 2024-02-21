#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node* right;
};
struct node* createNode(int data)
{
    struct node *p=malloc(sizeof(struct node));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void Inorder(struct node* root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}
struct node* preOrder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct node* postOrder(struct node* root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    struct node* p=createNode(2);
    struct node* p1=createNode(1);
    struct node* p2=createNode(4);
    struct node* p3=createNode(6);
    struct node* p4=createNode(5);
    struct node* p5=createNode(7);
    struct node* p6=createNode(8);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;
    printf("The Preorder Traversal of given tree is: ");
    preOrder(p);
    printf("\n");
    printf("The Inorder Traversal of given tree is: ");
    Inorder(p);
    printf("\n");
    printf("The Postorder Traversal of given tree is: ");
    postOrder(p);
}
