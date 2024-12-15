#include "utils.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main(int argc, char *argv[]) {

    if (argc > 3) {
        printf("Too many arguments. Exiting...\n");
        exit(1);
    }

    int first_arg_is_filename = ends_with_txt(argv[1]);

    if (argc == 3) {
        int second_arg_is_filename = ends_with_txt(argv[2]);
        if (first_arg_is_filename == -1 && second_arg_is_filename == -1) {
            printf("Only choose one option. Exiting...\n");
            exit(1);
        }
    }

    char *file_name;
    file_name = NULL;
    if (first_arg_is_filename == -1 && argc == 3) {
        file_name = argv[2];
    }
    if (first_arg_is_filename == 0 && argc == 2) {
        file_name = argv[1];
    }

    // pointer is a reference to a particular position in the opened file
    FILE *file_ptr;
    file_ptr = fopen(file_name, "rb");
    // handle case where input gets piped from another command
    if ((argc == 2) && (file_name == NULL)) {
        file_ptr = stdin;
    }

    // check if the file is opened successfully
    if (file_ptr == NULL) {
        printf("The file is not opened. Exiting...\n");
        exit(1);
    }

    int count;
    count = 0;

    if (first_arg_is_filename == 0) {
        count_bytes(file_ptr, &count);
        printf("%d\t", count);

        reset_condition(file_ptr, &count);

        count_lines(file_ptr, &count);
        printf("%d\t", count);

        reset_condition(file_ptr, &count);

        count_words(file_ptr, &count);
        printf("%d\t", count);

        printf("%s\n", file_name);

    } else {
        if (strcmp(argv[1], "-c") == 0) {
            count_bytes(file_ptr, &count);
        } else if (strcmp(argv[1], "-l") == 0) {
            count_lines(file_ptr, &count);
        } else if (strcmp(argv[1], "-w") == 0) {
            count_words(file_ptr, &count);
        } else if (strcmp(argv[1], "-m") == 0) {
            count_characters(file_ptr, &count);
        }

        if (file_name != NULL) {
            printf("%d %s\n", count, file_name);
        } else {
            printf("%d \n", count);
        }
    }

    return 0;
}
