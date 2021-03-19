#include<conio.h>
#include<math.h>
#include<stdio.h>

double fact_2n1(int n){
    int b=1;
    for (int i = 1; i <= 2*n-1; i++) {
			b*=i;
    }
    return b;
}

int decomp(float x, float e){ 
    int n=0; 
    double s=0,a;                            //разложение
    while (fabs(sin(x) - s)>e)
    {
        ++n;
        a=powl(-1,n-1)*powl(x,2*n-1)/fact_2n1(n);
        s+=a;
        /*printf("fact = %lf\n",a);
        printf("s = %lf\n",s);*/
    }
    printf("sin(x) = %lf\n",sin(x));
    printf("s = %lf\n",s);
    return n;
}


void main(){
    double x,e=0.001;
    int n;
    printf("Enter x\n");
    scanf("%lf", &x);
    n=decomp(x,e);
    printf("%d",n);
    _getch(); 
}