#include <stdio.h>
#include <stdlib.h>
struct node {
    int R;
    struct node *left, *right;
};
 struct node* newNode(int item)
{
    struct node* tm
        = (struct node*)malloc(sizeof(struct node));
    tm->R = item;
    tm->left = tm->right = NULL;
    return tm;
}
 void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->R);
        inorder(root->right);
    }
}
 struct node* insert(struct node* node, int R)
{
    if (node == NULL)
        return newNode(R);
 
    if (R< node->R)
        node->left = insert(node->left,R);
    else if (R> node->R)
        node->right = insert(node->right,R);
 
    return node;
}
 
int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 100);
    insert(root, 52);
    insert(root, 560);
    insert(root, 0);
    insert(root, 4);
    
 
    inorder(root);
 
    return 0;
}