/*
 Program Name : File Handling in C
 Operations   : Write, Append, Read
*/

#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    // Write to file
    fp = fopen("sample.txt", "w");
    fprintf(fp, "This is file handling in C.\n");
    fclose(fp);

    // Append to file
    fp = fopen("sample.txt", "a");
    fprintf(fp, "Appending new line.\n");
    fclose(fp);

    // Read from file
    fp = fopen("sample.txt", "r");
    printf("File Content:\n");
    while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);
    fclose(fp);

    return 0;
}
