#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book
{
    int id;
    char title[50];
    char author[50];
    int quantity;
    struct book *next;
}BOOK;

typedef struct issue
{
    int issue_id;
    int book_id;
    int user_id;
    char user_name[50];
    char issue_date[20];
    char due_date[20];
    char return_date[20];
    int fine;
    struct issue *next;
}ISSUE;

extern BOOK *head;
extern ISSUE *ihead;

void book_add(void);
void book_show(void);
void book_delete(void);
void book_update(void);
void book_search(void);

void book_issue(void);
void book_return(void);
void issued_list(void);

void save_file(void);
void load_file(void);
