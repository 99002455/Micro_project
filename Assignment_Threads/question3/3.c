#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char path[100];
    char ch;
    int character, word, line;
    //printf("Enter source file path: ");
    //scanf("%s", path);
    file = fopen("file1.txt", "r");
    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }

    character = word = line = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        character++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            line++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            word++;
    }
    if (character > 0)
    {
        word++;
        line++;
    }
    printf("\n");
    printf("Total characters = %d\n", character);
    printf("Total words      = %d\n", word);
    printf("Total lines      = %d\n", line);

    fclose(file);

    return 0;
}
