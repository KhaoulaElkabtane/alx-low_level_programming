#ifndef MAIN_H
#define MAIN_H

<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


=======
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int _putchar(char c);
>>>>>>> 74cf82cf048581139b8d714721547884c1a7aad0
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

<<<<<<< HEAD
#endif
=======
#endif /*MAIN_H*/
>>>>>>> 74cf82cf048581139b8d714721547884c1a7aad0
