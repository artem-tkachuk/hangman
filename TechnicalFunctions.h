#ifndef TechnicalFunctions_h
#define TechnicalFunctions_h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int i;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void rules(void);
char * get_word(char * s, unsigned short N);
void eatline(void);
void fill_in(char * b, char * a, unsigned short N);
void output(char * b, unsigned short N);
int find_length(char * a, unsigned short N);
char enter_letter(void);
void show_letter(char * a, char * b, char ch, unsigned short N);
void punishment(unsigned short stages);
unsigned short find_end(char * s, unsigned short N);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void rules(void)
{
    puts("Welcome to \"hangman\" game!\n"
         "1) 1st player should enter any word or "
         "phrase in English\n(it may include different chars like ',' or '!')\n"
         "2) 1st player can enter either capital or small letters,\n"
         "but finally they all become capital\n"
         "3) A sentence or a word shouldn't be longer then 30 symbols\n"
         "4) 2nd player has 9 attempts to guess all letters"
         "\n\nWarning! Please, while "
         "guessing, enter only letters of English alphabet!\n\n"
         "Let's begin!\n");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char * get_word(char * s, unsigned short N)
{
    char ch;
    int i = 0, length;
    while (((ch = getch()) != '\r'))
    {
        s[i] = ch;
        i++;
        putch('#');
    }
    s[i] = '\0';
    length = i;
    for (i = 0; i < length; i++)
    {
        if (!isupper(s[i]))
            s[i] = toupper(s[i]);
    }
    return s;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void fill_in(char * b, char * a, unsigned short N)
{
    for (i = 0; i < N; i++)
    {
        if (isalpha(a[i]))
            b[i] = '_';
        else if (ispunct(a[i]) || isspace(a[i]))
            b[i] = a[i];
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void output(char * b, unsigned short N)
{
    for (i = 0; i < N; i++)
        printf("%2c", b[i]);
    puts("\n");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int find_length(char * a, unsigned short N)
{
    puts("Give a word or a little phrase:");
    get_word(a, N);
    return (int)strlen(a);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char enter_letter(void)
{
    char ch = getchar();
    if (isalpha(ch))
    {
        eatline();
        return toupper(ch);
    }
    else
    {
        do
        {
            getchar();
            puts("You didn't enter any letter of "
                 "English Alphabet. Try again:");
        }
        while (!isalpha(ch = getchar()));
    }
    return toupper(ch);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void show_letter(char * a, char * b, char ch, unsigned short N)
{
    for (i = 0; i < N; i++)
    {
        if (a[i] == ch)
            b[i] = ch;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void punishment(unsigned short stages)
{
    switch(stages)
    {
        case 1:
        {
            puts("  \n"
                 "  \n"
                 "  \n"
                 "  \n"
                 "  \n"
                 "  \n"
                 "  \n"
                 "  - - - -\n");
            break;
        }
        case 2:
        {
            puts("  |\n"
                 "  |\n"
                 "  |\n"
                 "  |\n"
                 "  |\n"
                 "  |\n"
                 "  |\n"
                 "  |\n"
                 "  - - - -\n");
            break;
        }
        case 3:
        {
            puts("  _ _ _ _ _ _ _\n"
                 "  |    /\n"
                 "  |   /\n"
                 "  |  /\n"
                 "  | /\n"
                 "  |/\n"
                 "  |\n"
                 "  |\n"
                 "  |\n"
                 "  - - - -\n");
            break;
        }
        case 4:
        {
            puts("  _ _ _ _ _ _ _\n"
                 "  |    /    |\n"
                 "  |   /     |\n"
                 "  |  /      |\n"
                 "  | /\n"
                 "  |/\n"
                 "  |\n"
                 "  |\n"
                 "  |\n"
                 "  - - - -\n");
            break;
        }
        case 5:
        {
            puts("  _ _ _ _ _ _ _\n"
                 "  |    /    |\n"
                 "  |   /     |\n"
                 "  |  /      |\n"
                 "  | /       O\n"
                 "  |/\n"
                 "  |\n"
                 "  |\n"
                 "  |\n"
                 "  - - - -\n");
            break;
        }
        case 6:
        {
            puts("  _ _ _ _ _ _ _\n"
                 "  |    /    |\n"
                 "  |   /     |\n"
                 "  |  /      |\n"
                 "  | /       O\n"
                 "  |/       /|\n"
                 "  |         |\n"
                 "  |\n"
                 "  |\n"
                 "  - - - -\n");
            break;
        }
        case 7:
        {
            puts("  _ _ _ _ _ _ _\n"
                 "  |    /    |\n"
                 "  |   /     |\n"
                 "  |  /      |\n"
                 "  | /       O\n"
                 "  |/       /|\\\n"
                 "  |         |\n"
                 "  |\n"
                 "  |\n"
                 "  - - - -\n");
            break;
        }
        case 8:
        {
            puts("  _ _ _ _ _ _ _\n"
                 "  |    /    |\n"
                 "  |   /     |\n"
                 "  |  /      |\n"
                 "  | /       O\n"
                 "  |/       /|\\\n"
                 "  |         |\n"
                 "  |        / \n"
                 "  |\n"
                 "- - - -\n");
            break;
        }
        case 9:
        {
            puts("  _ _ _ _ _ _ _\n"
                 "  |    /    |\n"
                 "  |   /     |\n"
                 "  |  /      |\n"
                 "  | /       O\n"
                 "  |/       /|\\\n"
                 "  |         |\n"
                 "  |        / \\\n"
                 "  |\n"
                 "  - - - -\n");
            break;
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif /* TechnicalFunctions_h */
