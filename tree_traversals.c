#include <stdio.h>
#include <stdlib.h>
typedef struct tree_type
{
    struct tree_type *left;
    int info;
    struct tree_type *right;
} tree;
void inorder(tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d", root->info);
    inorder(root->right);
}
void preorder(tree *root)
{
    if (root == NULL)
        return;
    printf("%d", root->info);
    preorder(root->left);
    preorder(root->right);
}
void postorder(tree *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->info);
}
tree *create(int num)
{
    tree *temp;
    temp = (tree *)malloc(sizeof(tree));
    temp->info = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void insert(tree *root, tree *temp)
{
    if (temp->info < root->info)
    {
        if (temp->left == NULL)
        {
            root->left = temp;
        }
        else
        {
            insert(root->left, temp);
        }
    }
    else
    {
        if (temp->right == NULL)
        {
            root->right = temp;
        }
        else
        {
            insert(root->right, temp);
        }
    }
}
int main()
{
    tree *root = NULL, *temp;
    int num;
    int ch;
    do
    {

        printf("enter number \n");
        scanf("%d", &num);
        temp = create(num);
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            insert(root, temp);
        }
        printf("want to continue press 1 else 0 to exit");
        scanf("%d", &ch);

    } while (ch != 0);
    printf("preorder traversal\n");
    preorder(root);
    printf("\n");
    printf("inorder traversal\n");
    inorder(root);
    printf("\n");
    printf("postorder traversal\n");
    postorder(root);
    printf("\n");
}