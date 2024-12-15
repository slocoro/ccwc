#include <stdio.h>

#ifndef _CCWC // "include guard" makes sure header file only included once
#define _CCWC

void count_bytes(FILE *file_ptr, int *count);
void count_characters(FILE *file_ptr, int *count);
void count_lines(FILE *file_ptr, int *count);
void count_words(FILE *file_ptr, int *count);
int ends_with_txt(char *file_name);
void reset_condition(FILE *file_ptr, int *count);

#endif // _CCWC
