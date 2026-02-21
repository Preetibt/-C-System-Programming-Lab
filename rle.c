/*
 Program Name : Run Length Encoding
 Operations   : Compression & Decompression
*/

#include <stdio.h>

void compress() {
    FILE *in = fopen("original.txt", "r");
    FILE *out = fopen("compressed.txt", "w");

    char curr, prev;
    int count = 1;

    prev = fgetc(in);
    while ((curr = fgetc(in)) != EOF) {
        if (curr == prev)
            count++;
        else {
            fprintf(out, "%c%d", prev, count);
            prev = curr;
            count = 1;
        }
    }
    fprintf(out, "%c%d", prev, count);
    fclose(in);
    fclose(out);
}

void decompress() {
    FILE *in = fopen("compressed.txt", "r");
    FILE *out = fopen("decompressed.txt", "w");

    char ch;
    int count;
    while (fscanf(in, "%c%d", &ch, &count) != EOF) {
        for (int i = 0; i < count; i++)
            fputc(ch, out);
    }
    fclose(in);
    fclose(out);
}

int main() {
    compress();
    decompress();
    printf("RLE Compression & Decompression Done\n");
    return 0;
}
