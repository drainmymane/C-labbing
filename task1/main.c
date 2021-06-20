#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Size(const char* s )
{
    int i = 0;
    for (; s[i] != '\0'; i++);
    return i;
}

int main()
{
    char text[200];
    gets(text);
    int size = Size(text);
    int i=0,b=0, c, d, longsent=1, sl=0, maxwrds=0, maxsent;
        
    for (i = 0; i < size; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            maxsent = i;
            break;
        }
    }
    for (i = maxsent+1; i < size; i++)
    {
        
        if (text[i]=='!'||text[i]=='?'||text[i] == '.')
        {
            for (b = i-1; text[b] != '!' && text[b] != '?' && text[b] != '.'; b--)
            
                if (maxsent < i - b)
                {
                    maxsent = i - b;
                    c = b+1;
                    d = i;
                }
                longsent++;
        }
        
    }
    printf("\nSentences:%d\nLongest sentence:", longsent);
    for (; c <= d; c++)
        printf("%c",text[c]);
    for (i = 0; i < size; i++)
    {
        if (isalpha(text[i]))
        {
            b = i;
            for (; isalpha(text[i]); i++);
            if (maxwrds < i - b)
            {
                maxwrds = i - b;
                c = b;
                d = i;
            }
            sl++;
        }
    }
    printf("\nWords count:%d\nLongest word:",sl);
    for (; c <= d; c++)
        printf("%c", text[c]);
    getch();
}