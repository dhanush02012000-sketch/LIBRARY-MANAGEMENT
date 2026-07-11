#include "library.h"

void book_add(void)
{
    BOOK *new, *temp;
    int id = 1, found;

    new = (BOOK *)malloc(sizeof(BOOK));

    if(new == NULL)
    {
        printf("Memory Allocation Failed...\n");
        return;
    }

    /* Find the smallest available Book ID */
    while(1)
    {
        found = 0;
        temp = head;

        while(temp)
        {
            if(temp->id == id)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if(found == 0)
            break;

        id++;
    }

    new->id = id;

    printf("\nBook ID : %d\n", new->id);

    printf("Enter Book Title : ");
    scanf(" %[^\n]", new->title);

    printf("Enter Author Name : ");
    scanf(" %[^\n]", new->author);

    printf("Enter Quantity : ");
    scanf("%d", &new->quantity);

    new->next = NULL;

    /* Insert into Linked List */
    if(head == NULL)
    {
        head = new;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new;
    }

    printf("\nBook Added Successfully...\n");
}
