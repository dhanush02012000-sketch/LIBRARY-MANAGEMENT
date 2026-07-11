#include "library.h"

void issued_list(void)
{
    ISSUE *temp;

    if(ihead == NULL)
    {
        printf("\nNo Issued Books...\n");
        return;
    }

    temp = ihead;

    printf("\n=============================================================================================================\n");
    printf("IssueID\tBookID\tUserID\tUser Name\tIssue Date\tDue Date\tReturn Date\tFine\n");
    printf("=============================================================================================================\n");

    while(temp)
    {
        printf("%d\t%d\t%d\t%-15s%-15s%-15s%-15s%d\n",
                temp->issue_id,
                temp->book_id,
                temp->user_id,
                temp->user_name,
                temp->issue_date,
                temp->due_date,
                temp->return_date,
                temp->fine);

        temp = temp->next;
    }

    printf("=============================================================================================================\n");
}
