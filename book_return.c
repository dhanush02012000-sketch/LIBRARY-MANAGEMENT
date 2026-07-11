#include "library.h"

void book_return(void)
{
    ISSUE *itemp;
    BOOK *btemp;
    int book_id, user_id;
    int late_days;

    if(ihead == NULL)
    {
        printf("\nNo Issued Books...\n");
        return;
    }

    printf("\nEnter Book ID : ");
    scanf("%d", &book_id);

    printf("Enter User ID : ");
    scanf("%d", &user_id);

    /* Search Issued Record */
    itemp = ihead;

    while(itemp)
    {
        if(itemp->book_id == book_id &&
           itemp->user_id == user_id &&
           strcmp(itemp->return_date, "Not Returned") == 0)
        {
            break;
        }

        itemp = itemp->next;
    }

    if(itemp == NULL)
    {
        printf("\nIssue Record Not Found...\n");
        return;
    }

    /* Search Book List */
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
        printf("\nBook Record Not Found...\n");
        return;
    }

    printf("Enter Return Date (dd/mm/yyyy) : ");
    scanf("%s", itemp->return_date);

    printf("Enter Number of Late Days : ");
    scanf("%d", &late_days);

    if(late_days > 0)
        itemp->fine = late_days * 5;
    else
        itemp->fine = 0;

    /* Increase Book Quantity */
    btemp->quantity++;

    printf("\nBook Returned Successfully...\n");
    printf("Fine Amount : Rs.%d\n", itemp->fine);
}
