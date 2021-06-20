#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int check(unsigned ****cube, unsigned N);

int array_create(unsigned ****cube, unsigned N)
{
    if(!(*cube = (unsigned ***)malloc(N * (sizeof(unsigned **))))) {
        printf("memory problem");
        return 1;
        }
 
    for(int x = 0; x < N; x++) {
        (*cube)[x] = (unsigned **) malloc(N * sizeof(unsigned *));
 
        for(int y = 0; y < N; y++)
            (*cube)[x][y] = (unsigned *) malloc(N * sizeof(unsigned ));
    }
    return 0;
}
 
void cube_init(unsigned ****cube, unsigned N)
{
    for(int x  = 0; x < N; x++)
        for(int y = 0; y < N; y++)
            for(int z = 0; z < N; z++)
                (*cube)[x][y][z] = 0;
 
    int count = 0, n = N - 1;
    n *= n * n;
    srand((unsigned int)(time(NULL)));
 
    while(count != n) {
 
        int x = rand() % N;
        int y = rand() % N;
        int z = rand() % N;
        (*cube)[x][y][z] = 1;
        count = check(cube, N);
    }
}
 
void cube_show(unsigned ****cube, unsigned N)
{
    for(int x  = 0; x < N; x++){
        for(int y = 0; y < N; y++) {
            for(int z = 0; z < N; z++)
                printf("%4d", (*cube)[x][y][z]);
 
            printf("\n");
        }
        printf("\n");
    }
}
 
void cube_muddy(unsigned ****cube, unsigned N)
{
    for(int x  = 0; x < N; x++){
        for(int y = 0; y < N; y++) {
            for(int z = 0; z < N; z++) {
                (*cube)[x][y][z] = 1;
                printf("%4d", (*cube)[x][y][z]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
 
int check(unsigned ****cube, unsigned N)
{
    int count = 0;
 
    for(int x  = 0; x < N; x++)
        for(int y = 0; y < N; y++)
            for(int z = 0; z < N; z++)
                if ((*cube)[x][y][z] == 1)
                    count++;
    return count;
}
 
void array_clear(unsigned ****cube, unsigned N)
{
    for(int x = 0; x < N; x++)
        for(int y = 0; y < N; y ++)
            free((*cube)[x][y]);
 
    for(int z = 0; z < N; z++)
        free((*cube)[z]);
 
    free((*cube));
}

int main(void)
{
    unsigned ***cube, N;
 
    printf("Enter cube size: ");
    while(!scanf("%u", &N)) {
        printf("Error input.\nN = ");
        getchar();
    }
 
    if(array_create(&cube, N))
        return 0;
 
    cube_init(&cube, N);
 
    printf("Cube:\n");
    cube_show(&cube, N);
 
    printf("Muddy cube:\n");
    cube_muddy(&cube, N - 1);
 
    array_clear(&cube, N);
    getch();
    return 0;
}