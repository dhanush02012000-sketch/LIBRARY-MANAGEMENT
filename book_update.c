#include "library.h"

void book_update(void)
{
    BOOK *temp;
    int choice, id;
    char title[50];

    if(head == NULL)
    {
        printf("\nNo Books Available...\n");
        return;
    }

    printf("\n------ Update Book ------\n");
    printf("1. Update By Book ID\n");
    printf("2. Update By Book Name\n");
    printf("3. Back\n");
    printf("Enter Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:

            printf("Enter Book ID : ");
            scanf("%d", &id);

            temp = head;

            while(temp)
            {
                if(temp->id == id)
                {
                    printf("\nEnter New Book Title : ");
                    scanf(" %[^\n]", temp->title);

                    printf("Enter New Author Name : ");
                    scanf(" %[^\n]", temp->author);

                    printf("Enter New Quantity : ");
                    scanf("%d", &temp->quantity);

                    printf("\nBook Updated Successfully...\n");
                    return;
                }

                temp = temp->next;
            }

            printf("\nBook ID Not Found...\n");
            break;

        case 2:

            printf("Enter Book Name : ");
            scanf(" %[^\n]", title);

            temp = head;

            while(temp)
            {
                if(strcmp(temp->title, title) == 0)
                {
                    printf("\nEnter New Book Title : ");
                    scanf(" %[^\n]", temp->title);

                    printf("Enter New Author Name : ");
                    scanf(" %[^\n]", temp->author);

                    printf("Enter New Quantity : ");
                    scanf("%d", &temp->quantity);

                    printf("\nBook Updated Successfully...\n");
                    return;
                }

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
