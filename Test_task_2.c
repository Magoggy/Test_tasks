#include <stdio.h>
#include <stdlib.h>

int CAESAR_CONST = -3;

void Reading_the_text(char *text, int Length_of_the_text)
{
    free(text);
    text = malloc(Length_of_the_text*sizeof(char));
    printf("Please wright your text: ");
    gets(text);
    if (text[Length_of_the_text-1] != '\0')
    {
        printf("Your text is too long, please wright length of your text or print -1 if you want to try another text");
        int c;
        scanf("%d", &c);
        if (c >= Length_of_the_text)
        {
            Length_of_the_text = c+1;
        }

        Reading_the_text(text, Length_of_the_text);
    }
}

void Caesar_cipher(char *text)
{
    int i = 0;
    char letter;
    while(text[i] != '\0')
    {
        if ((text[i] >= "D" && text[i] <= "Z") || (text[i] >= "d" && text[i] <= "z"))
            {
                text[i] += CAESAR_CONST;
            }
        else if ((text[i] >= 'A' && text[i] <= 'C') || (text[i] >= 'a' && text[i] <= 'c'))
            {
                text[i] += CAESAR_CONST + 'Z' - 'A' + 1; //'Z'-'A' + 1 is the length of the alphabet
            }
            //else
            //{
            //    printf("Text contains a non-alphabet symbol\n");
            //}
        i++;
    }
}

int main()
{
    int Length_of_the_text = 15;
    char *text = malloc(Length_of_the_text*sizeof(char));
    if (text == NULL)
    {
        fprintf(stderr, "allocation error\n");
        return 1;
    }
    Reading_the_text(text, Length_of_the_text);
if (text == NULL)
    {
        fprintf(stderr, "allocation error\n");
        return 1;
    }
    Caesar_cipher(text);
    printf("%s", text);
    return 0;
}
