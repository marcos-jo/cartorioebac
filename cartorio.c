#include <stdio.h> //biblioteca de comunicalçao com o usuário
#include <stdlib.h> //boblioteca que cuida da alocalçao de espaço na memoria
#include <locale.h> //biblioteca que libera acentos
#include <string.h> //biblioteca que cuida das strings

int registro(){
    printf("*** Registro ***\n\n");
    char nome[50];
    char cpf[40];
    char cargo[40];
    char arquivo[40];

    printf("\n\nIsira o valor: CPF 'somete numeros'\n\n");
    fgets(cpf, 40, stdin);
    cpf[strcspn(cpf, "\n")] = 0; // remove o \n no final que tava causando um bug muito chato
 
    printf("\n\nIsira o valor: Nome completo\n\n");
    fgets(nome, 50, stdin); // estou usando o fgets pois tem pessoas que tem mais de um sobrenome, e o fgets aceita espaços podendo por o nome completo em uma variavel
    nome[strcspn(nome, "\n")] = 0;

    printf("\n\nInsira o valor: Cargo\n\n");
    fgets(cargo, 40, stdin);
    cargo[strcspn(cargo, "\n")] = 0;

    strcpy(arquivo, cpf); // copia o valor para a variavel 'arquivo' o valor de 'cpf'

    FILE *file = fopen(arquivo, "w"); // cria/nomeia o arquivo
    fprintf(file, "Nome: "); // salva o valor no arquivo
    fprintf(file, nome);
    fprintf(file, ". - Cargo: ");
    fprintf(file, cargo);
    fprintf(file, ". - CPF: ");
    fprintf(file, cpf);
    fclose(file); // fecha o arquivo

    system("cls");
    printf("*** Registro realizado com sucesso. ***\n\n");
    system("pause");
    return 0;
}

int consulta(){
    char cpf[40];
    char conteudo[200];

    printf("*** Consulta ***\n\nDigite o CPF 'somente números': ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");

    if(file == NULL) {
        printf("\nArquivo não localizado\n\n\n");
        system("pause");
    }

    while(fgets(conteudo, 200, file) != NULL) {
        printf("\nEssas são as informações do usuário:\n\n");
        printf("%s", conteudo);
        printf("\n\n");
        fclose(file);
        system("pause");
    }

}

int deletar(){
    char cpf[40];

    printf("*** Deletar Registro ***\n\nDigite o CPF 'somente números':\n\n");
    scanf("%s", cpf);
    remove(cpf);

    FILE *file = fopen(cpf, "r");

    if (file == NULL){
        printf("O usuário Não existe mais!\n\n  HUHOHAHAHAHA!!!\n\n");
        system("pause");
    }
    else{
        system("cls");
        printf("\n\nOcorreu algum erro, tente novamente\n\n");
        fclose(file);
        system("pause");
    }

}

int main(){
    system("chcp 1252 > nul"); //habilita os caracteres que faltam no terminal windows.
    setlocale(LC_ALL, "Portuguese_Brazil"); //define a linguagem

    int opcao=0; //opção escolhida pelo usuário

    while(1){
        system("cls"); //limpa a tela

        printf("*** Meu cartório *** \n\n"); //inicio do menu
        printf("Menu. Escolha a opção desejada: \n\n");
        printf("\t1 - Registrar pessoas. \n");
        printf("\t2 - Consultar pessoas. \n");
        printf("\t3 - Deletar registro. \n");
        printf("\t0 - Sair do programa. \n\n");
        printf("Opção: "); //fim do menu

        scanf("%d", &opcao); //armazena a escolha do usuário
        while ((getchar()) != '\n'); // limpa o enter do bufer que tava causando um bug chato de ignorar a primeira pergunta nas funções do menu 

        system("cls"); //limpa a tela

        switch(opcao){ //decide o que acontece dependendo da opção escolhida
            case 1:
            registro();
            break;

            case 2:
            consulta();
            break;

            case 3:
            deletar();
            break;

            case 0:
            printf("Encerrando o programa... \n");
            system("pause");
            return 0;

            default:
            printf("Esta opção não está disponível \n");
            system("pause");
            break;
        }
    }
}
