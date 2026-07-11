CC = gcc

OBJ = main.o \
      book_add.o \
      book_show.o \
      book_delete.o \
      book_update.o \
      book_search.o \
      book_issue.o \
      book_return.o \
      issued_list.o \
      save_file.o \
      load_file.o

library: $(OBJ)
	$(CC) -o library $(OBJ)

main.o: main.c library.h
	$(CC) -c main.c

book_add.o: book_add.c library.h
	$(CC) -c book_add.c

book_show.o: book_show.c library.h
	$(CC) -c book_show.c

book_delete.o: book_delete.c library.h
	$(CC) -c book_delete.c

book_update.o: book_update.c library.h
	$(CC) -c book_update.c

book_search.o: book_search.c library.h
	$(CC) -c book_search.c

book_issue.o: book_issue.c library.h
	$(CC) -c book_issue.c

book_return.o: book_return.c library.h
	$(CC) -c book_return.c

issued_list.o: issued_list.c library.h
	$(CC) -c issued_list.c

save_file.o: save_file.c library.h
	$(CC) -c save_file.c

load_file.o: load_file.c library.h
	$(CC) -c load_file.c

clean:
	rm -f *.o library
