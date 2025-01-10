#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Please provide exactly one argument (file path).\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        fprintf(stderr, "Error: File does not exist or cannot be opened.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fclose(file);

    if (fileSize < 0) {
        fprintf(stderr, "Error: Unable to determine file size.\n");
        return 1;
    }

    printf("File size: %ld bytes\n", fileSize);
    return 0;
}
