#include "library.h"

void book_delete(void)
{
    BOOK *temp, *prev;
    int choice, id;
    char title[50];

    if(head == NULL)
    {
        printf("\nNo Books Available...\n");
        return;
    }

    printf("\n----- Remove Book -----\n");
    printf("1. Delete By Book ID\n");
    printf("2. Delete By Book Name\n");
    printf("3. Back\n");
    printf("Enter Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:

            printf("Enter Book ID : ");
            scanf("%d", &id);

            temp = head;
            prev = NULL;

            while(temp)
            {
                if(temp->id == id)
                {
                    if(prev == NULL)
                    {
                        head = temp->next;
                    }
                    else
                    {
                        prev->next = temp->next;
                    }

                    free(temp);
                    printf("\nBook Deleted Successfully...\n");
                    return;
                }

                prev = temp;
                temp = temp->next;
            }

            printf("\nBook ID Not Found...\n");
            break;

        case 2:

            printf("Enter Book Name : ");
            scanf(" %[^\n]", title);

            temp = head;
            prev = NULL;

            while(temp)
            {
                if(strcmp(temp->title, title) == 0)
                {
                    if(prev == NULL)
                    {
                        head = temp->next;
                    }
                    else
                    {
                        prev->next = temp->next;
                    }

                    free(temp);
                    printf("\nBook Deleted Successfully...\n");
                    return;
                }

                prev = temp;
                temp = temp->next;
            }

            printf("\nBook Name Not Found...\n");
            break;

        case 3:
            return;

        default:
            printf("\nInvalid Choice...\n");
    }
}
