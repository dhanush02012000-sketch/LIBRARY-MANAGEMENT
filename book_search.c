#include "library.h"

void book_search(void)
{
    BOOK *temp;
    int choice, id;
    char name[50], author[50];
    int found = 0;

    if(head == NULL)
    {
        printf("\nNo Books Available...\n");
        return;
    }

    printf("\n------ Search Book ------\n");
    printf("1. Search By Book ID\n");
    printf("2. Search By Book Name\n");
    printf("3. Search By Author Name\n");
    printf("4. Back\n");
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
                    printf("\nBook Found\n");
                    printf("-------------------------------\n");
                    printf("Book ID   : %d\n", temp->id);
                    printf("Title     : %s\n", temp->title);
                    printf("Author    : %s\n", temp->author);
                    printf("Quantity  : %d\n", temp->quantity);
                    return;
                }

                temp = temp->next;
            }

            printf("\nBook ID Not Found...\n");
            break;

        case 2:

            printf("Enter Book Name : ");
            scanf(" %[^\n]", name);

            temp = head;

            while(temp)
            {
                if(strcmp(temp->title, name) == 0)
                {
                    printf("\nBook Found\n");
                    printf("-------------------------------\n");
                    printf("Book ID   : %d\n", temp->id);
                    printf("Title     : %s\n", temp->title);
                    printf("Author    : %s\n", temp->author);
                    printf("Quantity  : %d\n", temp->quantity);
                    return;
                }

                temp = temp->next;
            }

            printf("\nBook Name Not Found...\n");
            break;

        case 3:

            printf("Enter Author Name : ");
            scanf(" %[^\n]", author);

            temp = head;

            while(temp)
            {
                if(strcmp(temp->author, author) == 0)
                {
                    if(found == 0)
                    {
                        printf("\nBooks by %s\n", author);
                        printf("-------------------------------------------------\n");
                        printf("ID\tTITLE\t\t\tQUANTITY\n");
                    }

                    printf("%d\t%-20s\t%d\n",
                            temp->id,
                            temp->title,
                            temp->quantity);

                    found = 1;
                }

                temp = temp->next;
            }

            if(found == 0)
            {
                printf("\nAuthor Not Found...\n");
            }

            break;

        case 4:
            return;

        default:
            printf("\nInvalid Choice...\n");
    }
}
