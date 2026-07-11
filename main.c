#include "library.h"

BOOK *head = NULL;
ISSUE *ihead = NULL;

int main()
{
    int choice;


    load_file();

    while(1)
    {
        printf("\n=========================================\n");
        printf("      LIBRARY MANAGEMENT SYSTEM\n");
        printf("=========================================\n");
        printf("1. Add New Book\n");
        printf("2. Update Book Details\n");
        printf("3. Remove Book\n");
        printf("4. Search Book\n");
        printf("5. View All Books\n");
        printf("6. Issue Book\n");
        printf("7. Return Book\n");
        printf("8. List Issued Books\n");
        printf("9. Save Data\n");
        printf("10. Exit\n");
        printf("-----------------------------------------\n");
	printf("Enter your choice : ");

	if(scanf("%d", &choice) != 1)
	{
    	printf("\nInvalid Input...\n");

    	while(getchar() != '\n');   

    	continue;
	}
        switch(choice)
        {
            case 1:
                book_add();
                break;

            case 2:
                book_update();
                break;

            case 3:
                book_delete();
                break;

            case 4:
                book_search();
                break;

            case 5:
                book_show();
                break;

            case 6:
                book_issue();
                break;

            case 7:
                book_return();
                break;

            case 8:
                issued_list();
                break;

            case 9:
                save_file();
                printf("\nData Saved Successfully...\n");
                break;

            case 10:
                save_file();
                printf("\nThank You...\n");
                return 0;

            default:
                printf("\nInvalid Choice...\n");
        }
    }

    return 0;
}
