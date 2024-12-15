#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

void count_bytes(FILE *file_ptr, int *count) {
    while (getc(file_ptr) != EOF) {
        // count is a pointer so incrementing it directly increments the address
        // dereference count and then increment it to get the correct behaviour
        (*count)++;
    }
}

// TODO: revisit as not giving right result
void count_characters(FILE *file_ptr, int *count) {
    char buffer[MB_CUR_MAX]; // Buffer for multibyte characters
    wchar_t wc;              // Wide character
    mbstate_t state;         // Multibyte state
    size_t bytes_read;
    int char_count = 0;    // Multibyte character counter
    int bytes_in_file = 0; // Total bytes read

    // Initialize the state object
    memset(&state, 0, sizeof(mbstate_t));
    while (1) {
        // Read one byte at a time to build a multibyte character
        // and store it in buffer
        if (fread(buffer + bytes_in_file, 1, 1, file_ptr) == 0) {
            // End of file
            break;
        }
        // printf("%s", buffer);
        bytes_in_file++;

        // Try to convert the buffer to a wide character
        // (reads one additional byte at every iteration)
        bytes_read = mbrtowc(&wc, buffer, bytes_in_file, &state);

        if (bytes_read == (size_t)-1) {
            // Encoding error
            perror("Encoding error");
        } else if (bytes_read == (size_t)-2) {
            // Incomplete character: continue reading
            printf("-> Wide char: %lc\n", wc);
            continue;
        } else if (bytes_read > 0) {
            // printf("-> Wide char: %lc\n", wc);
            // Valid multibyte character found
            (*count)++;
            // Shift the buffer forward to handle next multibyte character
            memmove(buffer, buffer + bytes_read, bytes_in_file - bytes_read);
            // printf("bytes read: %d\n", (int)bytes_read);
            // printf("bytes read: %d\n", bytes_in_file);
            bytes_in_file -= bytes_read;
        }
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

void reset_condition(FILE *file_ptr, int *count) {
    rewind(file_ptr);
    *count = 0; // Dereference the pointer to set the value to 0!
}
