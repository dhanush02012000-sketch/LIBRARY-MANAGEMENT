#include "library.h"

void save_file(void)
{
    FILE *fp1, *fp2;
    BOOK *btemp;
    ISSUE *itemp;

    /* Save Books */
    fp1 = fopen("books.txt", "w");

    if(fp1 == NULL)
    {
        printf("Unable to Open books.txt\n");
        return;
    }

    btemp = head;

    while(btemp)
    {
        fprintf(fp1,
                "%d %s %s %d\n",
                btemp->id,
                btemp->title,
                btemp->author,
                btemp->quantity);

        btemp = btemp->next;
    }

    fclose(fp1);

    /* Save Issued Books */
    fp2 = fopen("issued.txt", "w");

    if(fp2 == NULL)
    {
        printf("Unable to Open issued.txt\n");
        return;
    }

    itemp = ihead;

    while(itemp)
    {
        fprintf(fp2,
                "%d %d %d %s %s %s %s %d\n",
                itemp->issue_id,
                itemp->book_id,
                itemp->user_id,
                itemp->user_name,
                itemp->issue_date,
                itemp->due_date,
                itemp->return_date,
                itemp->fine);

        itemp = itemp->next;
    }

    fclose(fp2);

    printf("\nData Saved Successfully...\n");
}
