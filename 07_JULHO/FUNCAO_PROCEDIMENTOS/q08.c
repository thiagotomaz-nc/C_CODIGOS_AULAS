#include <stdio.h>

int combinacao(int n, int p);
int fat(int n);
int fatorial(int n);

int main(void)
{

    printf("C_4,2 = %i", combinacao(4, 2));
    printf("\nC_6,2 = %i", combinacao(6, 2));
    printf("\nC_8,3 = %i", combinacao(8, 3));

    return 0;
}


int combinacao(int n, int p)
{
    int c;


    c = fat(n) / fat(p) * fat(n-p);
   
    return c;
}

int fatorial(int n)
{
    int f = 1;

    for (int i = n; i > 1; i--)
    {
        f = i * f;
    }

    return f;
}

int fat(int n){
    if(n == 0){
        return 1;
    }else{
        return n * fat(n-1);
    }

}