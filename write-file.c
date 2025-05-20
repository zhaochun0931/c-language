#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Name of the file to create/open */
    const char *filename = "output.txt";

    /* Open the file for writing ("w" creates/truncates) */
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    /* Write some lines of text to the file */
    fprintf(fp, "Hello, world!\n");
    fprintf(fp, "This is a sample text written by a C program.\n");
    fprintf(fp, "Have a great day!\n");

    /* Close the file to flush buffers and release resources */
    if (fclose(fp) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    printf("Successfully wrote to %s\n", filename);
    return EXIT_SUCCESS;
} /* end of main */
