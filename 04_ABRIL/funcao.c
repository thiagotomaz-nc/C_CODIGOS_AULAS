#include <stdio.h>
#include <math.h>  

int main(void) {
    float x; 
    
    printf(" -> Digite o valor de x: ");
    scanf("%f",&x);

    //float fx = x*x + 2*x - 5;
    float fx = pow(x,2) + 2*x - 5;
    // funcão de pow é realizar uma potenciação, um valor elevado a um expoente;
    
    printf("\n f(x = %.2f) = %.2f",x,fx);

    return 0;
}