#include <stdio.h> //biblioteca de comunicaï¿½ï¿½o com o usuï¿½rio
#include <stdlib.h> //biblioteca de alocaï¿½ï¿½o de espaï¿½o em memï¿½ria (banco de dados)
#include <locale.h> //biblioteca de alocaï¿½ï¿½es de texto por regiï¿½o
#include <string.h> //biblioteca responsï¿½vel por cuidar das string

int registro(){ //registra usuÃ¡rios 

    //criaÃ§Ã£o de variÃ¡veis

    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];


    printf("Digite o CPF a ser cadastrado"); //coletando informaÃ§Ãµes do usuÃ¡rios
    scanf("%s", cpf);   //%s refere-se a string

    strcpy(arquivo, cpf); //copia valores das string

    FILE *file; //criaï¿½ao do arquivo de banco de dados
    file = fopen(arquivo, "w"); //cria o arquivo "w" = write 
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a"); // "a" = atualizar
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado ");
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome o sobrenome a ser cadastrado ");
    scanf("%s",sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);

    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);

    system("pause");
}

int consulta_de_nomes(){
    
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    char cpf[40];
    char  conteudo[200];

    printf("digite o CPF a ser consultado:  ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r"); //"r" = read

    if(file ==  NULL){
        printf("Não localizado.\n");
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário:  ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    fclose(file);
    system("pause");
    

}
int deletar_nomes(){

    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL){
        printf("Usuário não encontrado");
        system("pause");
    }

}
int main(){
    
    int opcao=0; //variaveis   
    int laco=1;
    char senhadigitada[]="a";
    int comparacao;

    printf("### Cartório da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite a seua senha: ");
    scanf("%s",senhadigitada);

    comparacao = strcmp(senhadigitada, "admin");
    if(comparacao == 0)
    {

        system("cls");
    for(laco=1;laco=1;)
    {
            
        system("cls");

        setlocale(LC_ALL, "Portuguese_Brazil"); //linguagem

        printf("### Cartório da EBAC ###\n\n"); //inicio do menu
        printf("Escolha a opção que mais lhe agrada\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("opcao: "); //fim do menu

        scanf("%d", &opcao); //armazenando a escolha do usuario

        system("cls"); //responsavel por limpar a tela


        switch (opcao){ //menu
        case 1:
            registro();
            break;
        case 2:
            consulta_de_nomes();
            break;
        case 3:
            deletar_nomes();
            break;
        case 4: 
        printf("Obrigado por utilizar o sistema!\n");
        return 0;
        break;

        default:
            printf("Essa opção existe.\n");
            system("pause");
            break;
        }
    }//fim das escolhas
}
}