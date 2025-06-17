#include <stdio.h>
#include <ctype.h>

int main(){
    char genero = 'M', aux;
    int altura;
    int altura_media_masculino = 0 , altura_media_feminino = 0, cont_media_masculino = 0, cont_media_feminino = 0;

    printf("\n-> Digite o seu genero (M -> Masculineo ou F-> Feminino): ");
    scanf("%c",&genero);

    printf("\n-> Digite a sua Altura em centimetros: ");
    scanf("%i", &altura);

    while((toupper(genero)=='M' || toupper(genero)=='F') && altura > 0){
       

        if (toupper(genero)=='M'){
            altura_media_masculino += altura;
            cont_media_masculino ++;
        }else{
              altura_media_feminino += altura;
              cont_media_feminino++;  
        }
        scanf("%c",&aux);
        printf("\n-> Digite o seu genero (M -> Masculineo ou F-> Feminino): ");
        scanf("%c",&genero);

        printf("\n-> Digite a sua Altura em centimetros: ");
        scanf("%i", &altura);
    }
    
    float media_altura_masculino = ((float) altura_media_masculino) / cont_media_masculino;
    float media_altura_feminino = ((float)altura_media_feminino) / cont_media_feminino;

    
    printf("\n A media das altura dos homens eh: %f", media_altura_masculino);
    printf("\n A media das altura das mulheres eh: %f", media_altura_feminino);
    
   

    return 0;
}