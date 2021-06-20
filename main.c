#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{   FILE* fp;
    char name[] = "text.txt";
    if ((fp = fopen(name, "rt")) == NULL)          
    {
        printf("error");
        getchar();
        return 0;
    }
    else
    {
        int  simvl, allwrds = 0,cnt = 0;
        do
        {
            simvl = fgetc(fp);
            allwrds++;
            printf("%c", simvl);
            if (simvl == '/')
            {
                simvl = fgetc(fp);
                printf("%c", simvl);
                allwrds++;
                if (simvl == '/')
                {
                    cnt +=2;
                    while (simvl != '\n')
                    {
                        simvl = fgetc(fp);

                        printf("%c", simvl);
                        allwrds++;
                        cnt++;
                    }
                    cnt--;
                }
                else if (simvl == '*')
                {
                    cnt += 2;
                    while(1)
                    {
                        simvl = fgetc(fp);
                        printf("%c", simvl);
                        cnt++;
                        allwrds++;
                        if (simvl == '*')
                        {
                            simvl = fgetc(fp);
                            printf("%c", simvl);
                            cnt++;
                            allwrds++;
                            if (simvl == '/')
                                break;
                        }
                    }
                }
            }
        } while (simvl != EOF);
        double end1 = cnt, end2 = allwrds;
        double end = end1 / end2;
        printf("\nall:%d comments:%d  End:%.2f procents",allwrds,cnt, end*100);
    }
    fclose(fp);
    getchar();
}