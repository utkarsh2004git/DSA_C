#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    // Find the leftmost leaf node
    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    // Recursive calls for deletion
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // Node with only one child or no child
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node *temp = minValueNode(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int findMin(struct Node *root)
{
    if (root == NULL)
        return -1; // Error: Tree is empty

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int findMax(struct Node *root)
{
    if (root == NULL)
        return -1; // Error: Tree is empty

    while (root->right != NULL)
        root = root->right;

    return root->data;
}

void displayMenu()
{
    printf("\n=== Binary Search Tree Operations ===\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. In-order Traversal\n");
    printf("4. Pre-order Traversal\n");
    printf("5. Post-order Traversal\n");
    printf("6. Delete\n");
    printf("7. Find Minimum\n");
    printf("8. Find Maximum\n");
    printf("9. Exit\n");
    printf("-->Enter your choice: ");
}

int main()
{
    struct Node *root = NULL;
    int choice, key;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("-->Enter the key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 2:
            printf("-->Enter the key to search: ");
            scanf("%d", &key);
            struct Node *searchResult = search(root, key);
            if (searchResult)
                printf("-->%d found in the BST.\n", key);
            else
                printf("-->%d not found in the BST.\n", key);
            break;

        case 3:
            printf("-->In-order traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;

        case 4:
            printf("-->Pre-order traversal: ");
            preOrderTraversal(root);
            printf("\n");
            break;

        case 5:
            printf("-->Post-order traversal: ");
            postOrderTraversal(root);
            printf("\n");
            break;

        case 6:
            printf("-->Enter the key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            printf("-->%d deleted from the BST.\n", key);
            break;

        case 7:
            printf("-->Minimum element: %d\n", findMin(root));
            break;

        case 8:
            printf("-->Maximum element: %d\n", findMax(root));
            break;

        case 9:
            printf("-->Exiting the program.\n");
            break;

        default:
            printf("-->Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 9);

    return 0;
}