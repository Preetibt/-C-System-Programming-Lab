/*
 Program Name : Simple Lexical Analyzer
 Identifies   : Keywords, Identifiers, Operators
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char buffer[]) {
    char keywords[5][10] = {"int", "float", "if", "else", "while"};
    for (int i = 0; i < 5; i++)
        if (strcmp(buffer, keywords[i]) == 0)
            return 1;
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[15];
    int i = 0;

    fp = fopen("input.txt", "r");

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            buffer[i++] = ch;
        } else {
            buffer[i] = '\0';
            if (i > 0) {
                if (isKeyword(buffer))
                    printf("Keyword: %s\n", buffer);
                else
                    printf("Identifier: %s\n", buffer);
                i = 0;
            }
            if (ch == '+' || ch == '-' || ch == '=')
                printf("Operator: %c\n", ch);
        }
    }
    fclose(fp);
    return 0;
}
