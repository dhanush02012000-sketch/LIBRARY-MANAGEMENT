#include "library.h"

void book_issue(void)
{
    BOOK *btemp;
    ISSUE *new, *temp;
    int book_id;

    if(head == NULL)
    {
        printf("\nNo Books Available...\n");
        return;
    }

    printf("\nEnter Book ID : ");
    scanf("%d", &book_id);

    /* Search Book */
    btemp = head;

    while(btemp)
    {
        if(btemp->id == book_id)
        {
            break;
        }

        btemp = btemp->next;
    }

    if(btemp == NULL)
    {
        printf("\nBook Not Found...\n");
        return;
    }

    if(btemp->quantity == 0)
    {
        printf("\nBook Not Available...\n");
        return;
    }

    /* Create Issue Record */
    new = (ISSUE *)malloc(sizeof(ISSUE));

    if(new == NULL)
    {
        printf("\nMemory Allocation Failed...\n");
        return;
    }

    /* Generate Issue ID */
    new->issue_id = 1;

    temp = ihead;

    while(temp)
    {
        if(temp->issue_id >= new->issue_id)
            new->issue_id = temp->issue_id + 1;

        temp = temp->next;
    }

    new->book_id = btemp->id;

    printf("Enter User ID : ");
    scanf("%d", &new->user_id);

    printf("Enter User Name : ");
    scanf(" %[^\n]", new->user_name);

    printf("Enter Issue Date (dd/mm/yyyy) : ");
    scanf("%s", new->issue_date);

    printf("Enter Due Date (dd/mm/yyyy) : ");
    scanf("%s", new->due_date);

    strcpy(new->return_date, "Not Returned");

    new->fine = 0;
    new->next = NULL;

    /* Reduce Book Quantity */
    btemp->quantity--;

    /* Insert Issue Record */
    if(ihead == NULL)
    {
        ihead = new;
    }
    else
    {
        temp = ihead;

        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = new;
    }

    printf("\nBook Issued Successfully...\n");
}
