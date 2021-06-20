#include<conio.h>
#include<math.h>
#include<stdio.h>

void kv_num(int pos){										//ряд чисел из квадратов
	int c;
	int s=0;
	int i=0;
	int kv;
	int n=10;
	while (i<pos){  
            s++;
			kv=s*s;
				while (kv / n != 0)	{
						 n=n*10;
						 c=c+1;
					 }
			i+=c;
			printf("%d", kv);
		}
}

void num_pos(int i,int pos,int kv,int n){			//число позиции
	int num;
	while (i!=pos){
			 num=kv / n %10;
			 n=n / 10;
			 i+=1;
         }
	printf("%d", num);
}

int main(){

	int pos,i,kv,c=1,n=10,s;
	printf("pos =");
	scanf("%d", &pos);
	s=0;
	i=0;
    while (i<pos){  
            s++;
			kv=s*s;
				while (kv / n != 0){		//проверяет колво разрядов числа
					
						 n=n*10;
						 c=c+1;
					 }
			i+=c;
			printf("%d", kv);
		}
    i-=c;
    printf("\n");
	n=n / 10;
	num_pos(i,pos,kv,n);
    _getch();
	return 0;
}