/*
 * "hangman" game
 * Version 1.1
 * ⓒ Artem Tkachuk
*/


#include "TechnicalFunctions.h"

int main(void)
{
    const unsigned short MAX = 30; //Max word length

    char a[MAX]; //Array for source word

    rules();

    int k = find_length(a, MAX);
    short stages = 0;
    char ch;

    char b[k]; //Array for guessing
    fill_in(b, a, k);

    int alphabet[26];
    for(i = 0; i < 26; i++)
        alphabet[i] = 0;

    do //game itself...
    {
        printf("\n%s", (strchr(a, ' ')) ? "Phrase: " : "Word: ");
        output(b, k);
        puts("Letters available:");
        for(i = 0; i < 26; i++)
        {
            if (!alphabet[i])
                printf("%c ", i + 65);
        }
        puts("\n");
        do {
            puts("Enter a letter:");
            ch = enter_letter();
            if(!alphabet[ch - 65])
            {
                alphabet[ch - 65] = 1;
                break;
            }
            else
                puts("You already used this letter! Try another one:");
        } while (alphabet[ch - 65]);
        if (strchr(a, ch))
        {
            show_letter(a, b, ch, k);
            if (strchr(b, '_') == NULL)
            {
                printf("\n%s", (strchr(a, ' ')) ? "Phrase: " : "Word: ");
                output(b, k);
                printf("Great! It was \"%s\". Thank you for the game! Goodbye!\n", a);
                getchar();
                exit(0);
            }
        }
        else
        {
            printf("There's no letter \"%c\" in %s!\n", ch, (strchr(a, ' ') ? "phrase" : "word"));
            stages++;
            puts("Your hangman:");
            punishment(stages);
        }
    } while (stages < 9);
    printf("Disappointing... This was simply \"%s\"...\nGoodbye!\n", a);
    getchar();
}



//VERSION 2.0
//MAKE RUSSIAN LANGUAGE AVAILABLE
//MAKE MANY GAMES AT ONE RUN AVAILABLE
