#include "library.h"

void load_file(void)
{
    FILE *fp1, *fp2;
    BOOK *newb, *btemp;
    ISSUE *newi, *itemp;

    /* Load Books */
    fp1 = fopen("books.txt", "r");

    if(fp1 != NULL)
    {
        while(1)
        {
            newb = (BOOK *)malloc(sizeof(BOOK));

            if(fscanf(fp1,"%d %s %s %d",
                &newb->id,
                newb->title,
                newb->author,
                &newb->quantity) != 4)
            {
                free(newb);
                break;
            }

            newb->next = NULL;

            if(head == NULL)
            {
                head = newb;
            }
            else
            {
                btemp = head;

                while(btemp->next)
                    btemp = btemp->next;

                btemp->next = newb;
            }
        }

        fclose(fp1);
    }

    /* Load Issued Books */
    fp2 = fopen("issued.txt","r");

    if(fp2 != NULL)
    {
        while(1)
        {
            newi = (ISSUE *)malloc(sizeof(ISSUE));

            if(fscanf(fp2,"%d %d %d %s %s %s %s %d",
                &newi->issue_id,
                &newi->book_id,
                &newi->user_id,
                newi->user_name,
                newi->issue_date,
                newi->due_date,
                newi->return_date,
                &newi->fine) != 8)
            {
                free(newi);
                break;
            }

            newi->next = NULL;

            if(ihead == NULL)
            {
                ihead = newi;
            }
            else
            {
                itemp = ihead;

                while(itemp->next)
                    itemp = itemp->next;

                itemp->next = newi;
            }
        }

        fclose(fp2);
    }
}
