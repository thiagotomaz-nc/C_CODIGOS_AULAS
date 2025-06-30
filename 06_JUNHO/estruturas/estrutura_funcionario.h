
//  diretivas, se não funcionario.h não estiver definido, defina o funcionario.h e crie a estrutura.
#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

    // desinir uma estrutura de dado
    //definido pelo usuario
    typedef struct Funcionario
    {
        int idade;
        float salario;
        int rg;
    };

    typedef struct Gerente{
        int idade;
        float salario;
        int rg;
    };

#endif