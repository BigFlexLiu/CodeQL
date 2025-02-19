#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");  // Open file in binary mode
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);  // Move to end of file
    long filesize = ftell(file);  // Get current position (file size)
    fclose(file);  // Close the file

    if (filesize == -1) {
        perror("Error determining file size");
        return 1;
    }

    printf("%ld\n", filesize);
    return 0;
}
