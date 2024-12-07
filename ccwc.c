#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cases to parse
// ccwc test.txt
// ccwc -h
// ccwc -c test.txt
// ccwc -l test.txt
// ccwc -w test.txt

void count_bytes(FILE *file_ptr, int *count) {
    while (getc(file_ptr) != EOF) {
        // count is a pointer so incrementing it directly increments the address
        // dereference count and then increment it to get the correct behaviour
        (*count)++;
    }
}

void count_lines(FILE *file_ptr, int *count) {
    // no need to release memory from this array as allocated in stack
    // only with malloc function does memory get allocated on heap and needs to be
    // released using `free`
    char line[512];
    while (fgets(line, sizeof(line), file_ptr)) {
        (*count)++;
    }
}

void count_words(FILE *file_ptr, int *count) {
    char word[512];
    // reads next "sequence of characters" "%s"
    while (fscanf(file_ptr, "%s", word) == 1) {
        (*count)++;
    }
}

int ends_with_txt(char *file_name) {
    // find first occurence of '.' and return pointer to this character
    file_name = strrchr(file_name, '.');

    if (file_name != NULL)
        // use pointer to '.' to get the rest of the string (i.e. .txt)
        return strcmp(file_name, ".txt");
    return -1;
}

int main(int argc, char *argv[]) {
    // printf("Hello world!\n");

    int first_arg_is_filename = ends_with_txt(argv[1]);
    char *file_name;

    if (first_arg_is_filename == -1) {
        file_name = argv[2];
    } else {
        file_name = argv[1];
    }

    // pointer is a reference to a particular position in the opened file
    FILE *file_ptr;
    file_ptr = fopen(file_name, "rb");

    // check if the file is opened successfully
    if (file_ptr == NULL) {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }

    int count;
    count = 0;

    if (first_arg_is_filename == 0 || strcmp(argv[1], "-c") == 0) {
        count_bytes(file_ptr, &count);
    } else if (strcmp(argv[1], "-l") == 0) {
        count_lines(file_ptr, &count);
    } else if (strcmp(argv[1], "-w") == 0) {
        count_words(file_ptr, &count);
    }

    printf("%d %s\n", count, file_name);
    return 0;
}
