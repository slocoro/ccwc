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

int main(int argc, char *argv[]) {
    printf("Hello world!\n");
    // pointer is a reference to a particular position in the opened file

    FILE *file_ptr;
    file_ptr = fopen(argv[2], "rb");

    // check if the file is opened successfully
    if (file_ptr == NULL) {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }

    int count;
    count = 0;

    if (strcmp(argv[1], "-c") == 0) {
        count_bytes(file_ptr, &count);
    } else if (strcmp(argv[0], "xxx") == 0) {
    }

    printf("%d\n", count);
    return 0;
}
