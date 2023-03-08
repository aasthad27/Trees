#include <stdio.h>
#include <stdlib.h>

typedef struct tree_type
{
    struct tree_type *left;
    int info;
    struct tree_type *right;
} tree;

int height(tree *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = height(p->left);
    y = height(p->right);
    return x > y ? x + 1 : y + 1;
}

tree *inorpred(tree *p)
{
    while (p && p->right != NULL)
    {
        p = p->right;
    }
    return p;
}

tree *inorsucc(tree *p)
{
    while (p && p->left != NULL)
    {
        p = p->left;
    }
    return p;
}

tree *delete_node(tree *p, int key)
{
    if (p == NULL)
        return NULL;

    if (key < p->info)
    {
        p->left = delete_node(p->left, key);
    }
    else if (key > p->info)
    {
        p->right = delete_node(p->right, key);
    }
    else
    {
        if (p->left == NULL && p->right == NULL)
        { // Case 1: Leaf node
            free(p);
            return NULL;
        }
        else if (p->left == NULL)
        { // Case 2: Node with only right child
            tree *temp = p->right;
            free(p);
            return temp;
        }
        else if (p->right == NULL)
        { // Case 2: Node with only left child
            tree *temp = p->left;
            free(p);
            return temp;
        }
        else
        { // Case 3: Node with both left and right children
            if (height(p->left) > height(p->right))
            { // Predessor
                tree *pred = inorpred(p->left);
                p->info = pred->info;
                p->left = delete_node(p->left, pred->info);
            }
            else
            { // Successor
                tree *succ = inorsucc(p->right);
                p->info = succ->info;
                p->right = delete_node(p->right, succ->info);
            }
        }
    }
    return p;
}

tree *create_node(int num)
{
    tree *temp = (tree *)malloc(sizeof(tree));
    temp->info = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

tree *insert_node(tree *root, tree *temp)
{
    if (root == NULL)
    {
        root = temp;
    }
    else if (temp->info < root->info)
    {
        root->left = insert_node(root->left, temp);
    }
    else
    {
        root->right = insert_node(root->right, temp);
    }
    return root;
}

int main()
{
    tree *root = NULL;
    tree *temp;
    int num;
    int ch;

    do
    {
        printf("Enter number: ");
        scanf("%d", &num);
        temp = create_node(num);
        root = insert_node(root, temp);
        printf("Want to continue? Press 1 to continue or 0 to exit: ");
        scanf("%d", &ch);
    } while (ch != 0);

    root = delete_node(root, 20);

    return 0;
}
