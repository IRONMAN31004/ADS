#include<stdio.h>
#include<stdlib.h>
struct node{
int key;
struct node *left, *right;  
};

struct node *newnode(int val)
{
struct node *temp =(struct node *)malloc(sizeof (struct node));
temp->key= val;
temp->left=temp->right=NULL;
return temp;
}
struct node* insert(struct node* node,int key)
{
if(node==NULL)
return newnode(key);
if(key<node->key){
node->left=insert(node->left,key);}
else{
node->right=insert(node->right,key);}
return node;
}
void inorder(struct node *root)
{
if(root!=NULL)
{
    inorder(root->left);
    printf("%d \n",root->key);
    inorder(root->right);
}
}
struct node  * minValueNode(struct node* node) {
     struct node* current = node;
  

     while (current->left != NULL)
         current = current->left;
  
    return current; }
struct node* search(struct node* root, int key)
{
    
    if (root == NULL || root->key == key)
        return root;
 
    
    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}
struct node* deletenode(struct node* root,int key)
{
if(root==NULL){
return root;}
if(key<root->key)
{

    root->left=deletenode(root->left,key);
}
else if(key>root->key)
{

root->right=deletenode(root->right,key);

}
else{

if(root->left==NULL)
{

    
    struct node *temp=root->right;
    free(root);
    return temp;
}
else if(root->right==NULL)
{
struct node *temp=root->left;
free(root);
return temp;


}
else{

struct node* temp = minValueNode(root->right);
         root->key=temp->key;
          
    root->right=deletenode(root->right,temp->key);


}
return root;
}


}
 


int main()
{
struct node *root=NULL;
root=insert(root,45 );
root=insert(root,15 );
root=insert(root,79 );
root=insert(root,10 );
root=insert(root, 20);
root=insert(root, 55);
root=insert(root, 90);
root=insert(root, 12);
root=insert(root, 50);
 
printf("Inorder traversal of the given tree is \n");
inorder(root);

/*int key = ;
if (search(root, key) == NULL)
{        printf("%d not found\n", key);}
    else
        printf("%d found\n", key);*/
deletenode(root,45);
printf("\nInorder traversal of the given tree after deletion fo node is \n");
inorder(root);
return 0;
}