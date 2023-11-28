#include <stdio.h>
#include <stdlib.h>

struct Dnode
{
    int data;
    struct Dnode *next;
    struct Dnode *prev;
};
struct Dnode *Head;

void create()
{
    if (Head == NULL)
    {
        printf("-->Enter Head Element: ");
        Head = (struct Dnode *)malloc(sizeof(struct Dnode));
        scanf("%d", &Head->data);
        Head->prev = NULL;
        Head->next = NULL;
    }
    else
    {
        printf("**List Exists**\n");
    }
}

void insert_begin(int element)
{
    struct Dnode *t;
    t = (struct Dnode *)malloc(sizeof(struct Dnode));
    t->data = element;
    t->next = Head;
    t->prev = NULL;
    Head->prev = t;
    Head = t;
    printf("**New Head added**\n");
}

void append(int ele)
{
    struct Dnode *temp, *newnode;
    temp = Head;

    if (Head == NULL)
    {
        printf("**Calling create function**\n");
        create();
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        newnode = (struct Dnode *)malloc(sizeof(struct Dnode));
        newnode->data = ele;
        newnode->next = NULL;
        newnode->prev = temp;
        temp->next = newnode;
        printf("**Element appended**\n");
    }
}

void insert_between(int element, int position)
{
    struct Dnode *temp, *newnode;
    int count = 1;
    temp = Head;
    newnode = (struct Dnode *)malloc(sizeof(struct Dnode));
    newnode->data = element;

    while (temp != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("**Invalid position for insertion.**\n");
    }
    else
    {
        newnode->next = temp;
        newnode->prev = temp->prev;
        temp->prev = newnode;

        if (newnode->prev != NULL)
        {
            newnode->prev->next = newnode;
        }
        else
        {
            Head = newnode; // Update Head if inserting at the beginning.
        }
        printf("**Element Inserted**\n");
    }
}

void traverse()
{
    struct Dnode *t;
    t = Head;
    while (t != NULL)
    {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

void delete_head()
{
    struct Dnode *temp;
    temp = Head;
    Head = Head->next;
    Head->prev = NULL;
    free(temp);
    printf("**Head Deleted**\n");
}

void delete_end()
{
    struct Dnode *temp;
    temp = Head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        Head = NULL;
    }
    free(temp);
    printf("**Last Element deleted**\n");
}

void delete_between(int position)
{
    if (Head == NULL)
    {
        printf("**List is empty**\n");
        return;
    }

    if (position == 1)
    {
        delete_head();
        return;
    }

    struct Dnode *temp = Head;
    int count = 1;
    while (temp != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("**Invalid position**\n");
    }
    else
    {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        free(temp);
        printf("**Element deleted**\n");
    }
}

void search(int element)
{
    struct Dnode *t;
    t = Head;
    int count = 0;
    while (t != NULL)
    {
        count++;
        if (t->data == element)
        {
            printf("-->Element found at node %d\n", count);
            return;
        }
        t = t->next;
    }
    printf("**No element found**\n");
}

int main()
{
    int element, choice, position;
    create();
    while (choice != 9)
    {
        printf("1. Append\n");
        printf("2. Insert begin\n");
        printf("3. Insert between\n");
        printf("4. Traverse\n");
        printf("5. Delete Head\n");
        printf("6. Delete end\n");
        printf("7. Delete between\n");
        printf("8. Search\n");
        printf("9. To terminate\n");
        printf("-->Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("-->Enter element to append: ");
            scanf("%d", &element);
            append(element);
            break;
        case 2:
            printf("-->Enter New Head: ");
            scanf("%d", &element);
            insert_begin(element);
            break;
        case 3:
            printf("-->Enter element to insert: ");
            scanf("%d", &element);
            printf("-->Enter position: ");
            scanf("%d", &position);
            insert_between(element, position);
            break;
        case 4:
            printf(" ** Your Doubly Linked List **\n");
            traverse();
            break;
        case 5:
            delete_head();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            printf("-->Enter position:");
            scanf("%d", &position);
            delete_between(position);
            break;
        case 8:
            printf("-->Enter element to find:");
            scanf("%d", &element);
            search(element);
            break;
        case 9:
            printf("** Terminating program **.\n");
            break;
        default:
            printf("** Invalid choice **\n");
            break;
        }
    }
}