#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

//declaração de variáveis e funções
static int ncadasLogin = 100, senha;
int tempo();
void menuI();
void menuII();
void cadasLogin();
void fazerLogin();
void cadasEmpresa();
void cadasFuncionario();
void cadasResiduo();
void consulCadEmpresa();
void consulCadFuncionario();
void consulCadResiduo();

//função principal
int main(void){

    setlocale(LC_ALL,"portuguese");
    menuI ();

    return 0;
}

//função de data e hora local
int tempo(){
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );

  return asctime(timeinfo);
}

//menu inicial
void menuI(){
    system("cls");
    fflush(stdin);
	int opcao = 0, j;
    printf("***************************************\n");
    printf("*           SEJA BEM VINDO(A)         *\n");
    printf("*        AO PROGRAMA DE SOLUÇÕES      *\n");
    printf("*             AMBIENTAIS!             *\n");
    printf("***************************************\n");

    printf("\nEscolha uma opção: \n");
    printf("\n[1] Acessar o menu principal \n[2] Sair do programa \n\nOpção Escolhida: ");
    scanf("%d", &j);

    if (j==1){
        printf("\nO que deseja fazer? \n");
        printf("\n[1] Efetuar novo cadastro de login.\n");
        printf("[2] Realizar Login.\n");
        printf("[3] Sair do programa.\n");
        printf("\nOpção Escolhida: ");

        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
                cadasLogin();
                break;
            case 2:
                fazerLogin();
                break;
            case 3:
                printf("\nSaindo do programa...\n");
                Sleep(1000);
                exit(0);
                break;
            default:
                printf("\nOpção inválida! Tente novamente, por favor.\n\n");
                system("pause");
                menuI();
        }
    } else if (j==2) {
        printf("\nSaindo do programa...\n");
        Sleep(1000);
        exit(0);
    } else {
        printf("\nOpção inválida! Tente novamente, por favor.\n\n");
        system("pause");
        menuI();
    }
}

//menu principal
void menuII(){
    system("cls");
    fflush(stdin);
	int opcao = 0;
    printf("***************************************\n");
    printf("*             PROGRAMA DE             *\n");
    printf("*         SOLUÇÕES AMBIENTAIS         *\n");
    printf("***************************************\n");

    printf("\nEscolha a opção desejada: \n");
	printf("\n[1] Cadastrar empresas.\n");
	printf("\n[2] Cadastrar funcionários.\n");
	printf("\n[3] Cadastrar resíduos ambientais.\n");
	printf("\n[4] Consultar cadastros de empresas.\n");
    printf("\n[5] Consultar cadastros de funcionários.\n");
    printf("\n[6] Consultar cadastros de resíduos ambientais.\n");
	printf("\n[7] Voltar ao menu principal.\n");
	printf("\nOpção Escolhida: ");
	scanf("%d", &opcao);
	getchar();

	switch(opcao){
		case 1:
            cadasEmpresa();
			break;
        case 2:
			cadasFuncionario();
			break;
        case 3:
            cadasResiduo();
            break;
		case 4:
			consulCadEmpresa();
			break;
        case 5:
            consulCadFuncionario();
            break;
        case 6:
            consulCadResiduo();
            break;
		case 7:
			printf("\nRetornando ao menu principal...\n");
			Sleep(3000);
			menuI();
			break;
		default:
			printf("\nOpção inválida! Tente novamente, por favor.\n\n");
			system("pause");
			menuII();
	}
}

//cadastro de login
void cadasLogin() {
    system("cls");
	int opcao = 0;
    printf("***************************************\n");
    printf("*        PROGRAMA DE SOLUÇÕES         *\n");
    printf("*             AMBIENTAIS              *\n");
    printf("*      CADASTRE SEU LOGIN AGORA       *\n");
    printf("***************************************\n");

    char nome[50];
    int segundos = time(0);
    srand(segundos);

    printf ("\n\nSiga as instruções a seguir para a criação de seu ID de login e senha.\n");
    printf("\nDigite seu nome: ");
    scanf("%s", &nome);
    ncadasLogin++;
    printf("\nO número do seu ID de login é: %d\n", ncadasLogin);
    senha = rand();
    printf("\nSua senha é: %d\n", senha);
    printf("\nCadastro realizado com sucesso!\n");
    printf("\nRetorne ao menu principal.\n\n");
    system("pause");
    menuI();

}

//verificação de login
void fazerLogin() {
    system("cls");
    fflush(stdin);
    printf("***************************************\n");
    printf("*        PROGRAMA DE SOLUÇÕES         *\n");
    printf("*             AMBIENTAIS              *\n");
    printf("*       REALIZE SEU LOGIN AGORA       *\n");
    printf("***************************************\n");

    int id, se, j;

    printf("\nDigite seu ID: ");
    scanf("%d", &id);
    getchar();
    if (id == ncadasLogin && id > 100){
        printf("\nID válido!\n");
    } else {
        printf("\nID inválido!\n");
        printf("\nRetorne ao menu principal e realize seu cadastro ou tente novamente.\n");
        printf("\n[1] Menu principal. \n[2] Tentar novamente.\n");
        printf("\nOpção Escolhida: ");
        scanf("%d", &j);
        switch (j){
            case 1:
                printf("\nRetornando ao menu principal...\n");
                Sleep(3000);
                menuI();
                break;
            case 2:
                printf("\nOk, vamos tentar novamente!\n");
                Sleep(1000);
                fazerLogin();
                break;
            default:
                printf("\nLogin inválido! Tente novamente, por favor.\n\n");
                system("pause");
                menuI();
        }
    }

    printf("\nDigite sua senha: ");
    scanf("%d", &se);
    if (se == senha) {
        printf("\nSenha válida!\n");
    } else if(se > senha || se < senha) {
        printf("\nSenha inválida!\n");
        printf("\nRetorne ao menu principal e realize seu cadastro ou tente novamente:\n");
        printf("\n[1] Menu principal. \n[2] Tentar novamente.\n");
        printf("\nOpção Escolhida: ");
        scanf("%d", &j);
        switch (j){
            case 1:
                printf("\nRetornando ao menu principal...\n");
                Sleep(3000);
                menuI();
                break;
            case 2:
                printf("\nOk, vamos tentar novamente!\n");
                Sleep(1000);
                fazerLogin();
                break;
            default:
                printf("\nSenha inválida! Tente novamente, por favor.\n\n");
                system("pause");
                menuI();
        }

    }

    printf("\nLogin realizado com sucesso!\n\n");
    system("pause");;
    menuII();

}

//cadastro de empresas
void cadasEmpresa(){
    system("cls");
    fflush(stdin);
    printf("***************************************\n");
    printf("*        PROGRAMA DE SOLUÇÕES         *\n");
    printf("*             AMBIENTAIS              *\n");
    printf("*        CADASTRO DE EMPRESAS         *\n");
    printf("***************************************\n");

    char razaosocial[50], email[50],rua[50], bairro[50], cidade[50], estado[50],cnpj[14],cep[10];
    int numero, dia, mes, ano, op, telefone, ddd;

    FILE *file;

    file = fopen("cadastroempresa.txt", "a");
    if(file == NULL) {
        printf("\nNão foi possível acessar ao arquivo cadastro.txt\n Verifique se ele já está em uso e tente novamente.\n\n");
        system("pause");
        menuII();
    }

    fprintf(file,"\n");
    fprintf(file,"\nRecorded at %s\n", tempo());

    printf("\nPrezado(a),\n");
    printf("Informe todos os dados necessários para realizar o cadastro das empresas cliente.\n");
    printf("\nRazão Social: ");
    scanf("%[^\n]s", &razaosocial);
    fprintf(file,"Razão Social: ");
    fprintf(file,"%s", razaosocial);
    fflush(stdin);

    printf("\nE-mail: ");
    scanf("%s",&email);
    fprintf(file,"\nE-mail: ");
    fprintf(file,"%s", email);
    fflush(stdin);

    printf("\nCNPJ: ");
    scanf("%s",&cnpj);
    fprintf(file,"\nCNPJ: ");
    fprintf(file,"%s", cnpj);
    fflush(stdin);

    printf("\nDDD: ");
    scanf("%d", &ddd);
    fprintf(file,"\nTelefone: (");
    fprintf(file,"%d", ddd);
    fflush(stdin);
    printf("\nTelefone: ");
    scanf("%d", &telefone);
    fprintf(file,")");
    fprintf(file,"%d", telefone);
    fflush(stdin);

    printf("\nData de abertura da empresa.\n");
    printf("\n- Dia: ");
    scanf("%d", &dia);
    fprintf(file,"\nData de abertura da empresa: %d/", dia);
    fflush(stdin);
    printf("\n- Mês: ");
    scanf("%d", &mes);
    fprintf(file,"%d/", mes);
    fflush(stdin);
    printf("\n- Ano: ");
    scanf("%d", &ano);
    fprintf(file,"%d", ano);
    fflush(stdin);

    printf("\nEndereço\n");
    printf("\n- Rua: ");
    scanf("%[^\n]s", &rua);
    fprintf(file,"\nEndereço: ");
    fprintf(file,"Rua - %s | ", rua);
    fflush(stdin);
    printf("\n- Número: ");
    scanf("%d", &numero);
    fprintf(file,"Número - %d | ", numero);
    fflush(stdin);
    printf("\n- Bairro: ");
    scanf("%[^\n]s", &bairro);
    fprintf(file,"Bairro - %s ", bairro);
    fflush(stdin);
    printf("\n- Cidade: ");
    scanf("%[^\n]s", &cidade);
    fprintf(file,"\nCidade - %s | ", cidade);
    fflush(stdin);
    printf("\n- Estado: ");
    scanf("%[^\n]s", &estado);
    fprintf(file,"Estado - %s | ", estado);
    fflush(stdin);
    printf("\n- CEP: ");
    scanf("%s", &cep);
    fprintf(file,"CEP - %s", cep);
    fflush(stdin);

    printf("\nCadastro realizado com sucesso!\n");
    printf("\nDeseja voltar ao menu anterior?\n\n[1] Sim.\n[2] Não (sair do programa).\n");
    printf("\nOpção Escolhida: ");
    scanf("%d",&op);

            switch (op) {
        case 1:
            printf("\nRetornando ao menu anterior...\n");
			Sleep(3000);
            menuII();
            break;
        case 2:
            printf("\nSaindo do programa...\n");
            Sleep(1000);
            exit(0);
            break;
        default:
            printf("\nOpção inválida! Tente novamente, por favor.\n\n");
            system("pause");
            cadasEmpresa();
    }

    fclose(file);

}

//cadastro de funcionários
void cadasFuncionario(){
    system("cls");
    fflush(stdin);
    printf("***************************************\n");
    printf("*        PROGRAMA DE SOLUÇÕES         *\n");
    printf("*             AMBIENTAIS              *\n");
    printf("*       CADASTRO DE FUNCIONÁRIOS      *\n");
    printf("***************************************\n");

    char nomefun[50], email[50],rua[50], bairro[50], cidade[50], estado[50],cpf[10],cep[10];
    int numero, dia, mes, ano, op, telefone, ddd;

    FILE *file;

    file = fopen("cadastrofuncionario.txt", "a");
    if(file == NULL) {
        printf("\nNão foi possível acessar ao arquivo cadastro.txt\n Verifique se ele já está em uso e tente novamente.\n\n");
        system("pause");
        menuII();
    }

    fprintf(file,"\n");
    fprintf(file,"\nRecorded at %s\n", tempo());

    printf("\nPrezado (a),\n");
    printf("Informe todos os dados necessários para realizar o cadastro dos funcionários.\n");
    printf("\nNome Completo: ");
    scanf("%[^\n]s", &nomefun);
    fprintf(file,"Nome do funcionário: ");
    fprintf(file,"%s", nomefun);
    fflush(stdin);

    printf("\nE-mail: ");
    scanf("%s",&email);
    fprintf(file,"\nE-mail: ");
    fprintf(file,"%s", email);
    fflush(stdin);

    printf("\nCPF: ");
    scanf("%s",&cpf);
    fprintf(file,"\nCPF: ");
    fprintf(file,"%s", cpf);
    fflush(stdin);

    printf("\nDDD: ");
    scanf("%d", &ddd);
    fprintf(file,"\nTelefone: (");
    fprintf(file,"%d", ddd);
    fflush(stdin);
    printf("\ntelefone: ");
    scanf("%d", &telefone);
    fprintf(file,")");
    fprintf(file,"%d", telefone);
    fflush(stdin);

    printf("\nData de nascimento.\n");
    printf("\n- Dia: ");
    scanf("%d", &dia);
    fprintf(file,"\nData de nascimento: %d/", dia);
    fflush(stdin);
    printf("\n- Mês: ");
    scanf("%d", &mes);
    fprintf(file,"%d/", mes);
    fflush(stdin);
    printf("\n- Ano: ");
    scanf("%d", &ano);
    fprintf(file,"%d", ano);
    fflush(stdin);

    printf("\nEndereço.\n");
    printf("\n- Rua: ");
    scanf("%[^\n]s", &rua);
    fprintf(file,"\nEndereço: ");
    fprintf(file,"Rua - %s | ", rua);
    fflush(stdin);
    printf("\n- Número: ");
    scanf("%d", &numero);
    fprintf(file,"Número - %d | ", numero);
    fflush(stdin);
    printf("\n- Bairro: ");
    scanf("%[^\n]s", &bairro);
    fprintf(file,"Bairro - %s ", bairro);
    fflush(stdin);
    printf("\n- Cidade: ");
    scanf("%[^\n]s", &cidade);
    fprintf(file,"\nCidade - %s | ", cidade);
    fflush(stdin);
    printf("\n- Estado: ");
    scanf("%[^\n]s", &estado);
    fprintf(file,"Estado - %s | ", estado);
    fflush(stdin);
    printf("\n- CEP: ");
    scanf("%s", &cep);
    fprintf(file,"CEP - %s", cep);
    fflush(stdin);

    printf("\nCadastro realizado com sucesso!\n");
    printf("\nDeseja voltar ao menu anterior?\n\n[1] Sim.\n[2] Não (sair do programa).\n");
    printf("\nOpção Escolhida: ");
    scanf("%d",&op);

            switch (op) {
        case 1:
            printf("\nRetornando ao menu anterior...\n");
			Sleep(3000);
            menuII();
            break;
        case 2:
            printf("\nSaindo do programa...\n");
            Sleep(1000);
            exit(0);
            break;
        default:
            printf("\nOpção inválida! Tente novamente, por favor.\n\n");
            system("pause");
            cadasFuncionario();
    }

    fclose(file);

}

//cadastro de residuos
void cadasResiduo(){
    system("cls");
    fflush(stdin);
    printf("***************************************\n");
    printf("*        PROGRAMA DE SOLUÇÕES         *\n");
    printf("*             AMBIENTAIS              *\n");
    printf("*        CADASTRO DE RESÍDUOS         *\n");
    printf("***************************************\n");

    char nomeemp[50], residuo[20],rua[50], bairro[50], cidade[50], estado[50],cep[10];
    float quantidade, total;
    int numero, dia, mes, ano, op;

    FILE *file;

    file = fopen("cadastroresiduos.txt", "a");
    if(file == NULL) {
        printf("\nNão foi possível acessar ao arquivo cadastro.txt\n Verifique se ele já está em uso e tente novamente.\n\n");
        system("pause");
        menuII();
    }

    fprintf(file,"\n");
    fprintf(file,"\nRecorded at %s\n", tempo());

    printf("\nPrezado(a),\n");
    printf("Informe todos os dados necessários para realizar o cadastro de resíduos ambientais.\n");
    printf("\nNome da Empresa: ");
    scanf("%[^\n]s", &nomeemp);
    fprintf(file,"Nome da Empresa: ");
    fprintf(file,"%s", nomeemp);
    fflush(stdin);

    printf("\nTipo de Resíduo: ");
    scanf("%s",&residuo);
    fprintf(file,"\nTipo de Resíduo: ");
    fprintf(file,"%s", residuo);
    fflush(stdin);

    printf("\nQuantidade (em kg): ");
    scanf("%0.2f",&quantidade);
    fprintf(file,"\nQuantidade (kg): ");
    fprintf(file,"%0.2f", quantidade);
    fflush(stdin);

    printf("\nDia da coleta.\n");
    printf("\n- Dia: ");
    scanf("%d", &dia);
    fprintf(file,"\nDia da coleta: %d/", dia);
    fflush(stdin);
    printf("\n- Mês: ");
    scanf("%d", &mes);
    fprintf(file,"%d/", mes);
    fflush(stdin);
    printf("\n- Ano: ");
    scanf("%d", &ano);
    fprintf(file,"%d", ano);
    fflush(stdin);

    printf("\nEndereço da coleta.\n");
    printf("\n- Rua: ");
    scanf("%[^\n]s", &rua);
    fprintf(file,"\nEndereço da coleta: ");
    fprintf(file,"Rua - %s | ", rua);
    fflush(stdin);
    printf("\n- Número: ");
    scanf("%d", &numero);
    fprintf(file,"Número - %d | ", numero);
    fflush(stdin);
    printf("\n- Bairro: ");
    scanf("%[^\n]s", &bairro);
    fprintf(file,"Bairro - %s ", bairro);
    fflush(stdin);
    printf("\n- Cidade: ");
    scanf("%[^\n]s", &cidade);
    fprintf(file,"\nCidade - %s | ", cidade);
    fflush(stdin);
    printf("\n- Estado: ");
    scanf("%[^\n]s", &estado);
    fprintf(file,"Estado - %s | ", estado);
    fflush(stdin);
    printf("\n- CEP: ");
    scanf("%s", &cep);
    fprintf(file,"CEP - %s | ", cep);
    fflush(stdin);

    if (quantidade <= 10) {
        total = quantidade * 1.5;
        printf("\nValor Total: %.2f\n", total);
        fprintf(file,"Valor Total: ");
        fprintf(file,"%.2f", total);
        fflush(stdin);
    } else if (quantidade > 10) {
        total = quantidade * 2.0;
        printf("\nValor Total: %.2f\n", total);
        fprintf(file,"Valor Total: ");
        fflush(stdin);
    } else {
        printf("\n*Valor inválido! Verifique a quantidade informada.*\n");
    }

    printf("\nCadastro realizado com sucesso!\n");
    printf("\nDeseja voltar ao menu anterior?\n\n[1] Sim.\n[2] Não (sair do programa).\n");
    printf("\nOpção Escolhida: ");
    scanf("%d",&op);

        switch (op) {
        case 1:
            printf("\nRetornando ao menu anterior...\n");
			Sleep(3000);
            menuII();
            break;
        case 2:
            printf("\nSaindo do programa...\n");
            Sleep(1000);
            exit(0);
            break;
        default:
            printf("\nOpção inválida! Tente novamente, por favor.\n\n");
            system("pause");
            cadasResiduo();
    }

    fclose(file);

}

//relatório de empresas
void consulCadEmpresa(){
    system("cls");
    fflush(stdin);
    printf("***************************************\n");
    printf("*        PROGRAMA DE SOLUÇÕES         *\n");
    printf("*             AMBIENTAIS              *\n");
    printf("*        CONSULTAR RELATÓRIOS         *\n");
    printf("***************************************\n");

    FILE *file;
    file = fopen("cadastroempresa.txt", "r");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
    }

    char texto [2000];

    while (fgets(texto,2000, file) != NULL){
        printf("%s", texto);
    }
    fclose(file);

    printf("\n");

    int opcao;

    printf("\nDeseja voltar ao menu anterior?\n");
    printf("\n[1] Sim. \n[2] Não (sair do programa).\n");
    printf("\nOpção Escolhida: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            printf("\nRetornando ao menu anterior...\n");
			Sleep(3000);
            menuII();
            break;
        case 2:
            printf("\nSaindo do programa...\n");
            Sleep(1000);
            exit(0);
            break;
        default:
            printf("\nOpção inválida! Tente novamente, por favor.\n\n");
            system("pause");
            consulCadEmpresa();
    }
}

//relatório de funcionários
void consulCadFuncionario(){
    system("cls");
    fflush(stdin);
    printf("***************************************\n");
    printf("*        PROGRAMA DE SOLUÇÕES         *\n");
    printf("*             AMBIENTAIS              *\n");
    printf("*        CONSULTAR RELATÓRIOS         *\n");
    printf("***************************************\n");


    FILE *file;
    file = fopen("cadastrofuncionario.txt", "r");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
    }

    char texto [2000];

    while (fgets(texto,2000, file) != NULL){
        printf("%s", texto);
    }
    fclose(file);

    printf("\n");

    int opcao;

    printf("\nDeseja voltar ao menu anterior?\n");
    printf("\n[1] Sim. \n[2] Não (sair do programa).\n");
    printf("\nOpção Escolhida: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            printf("\nRetornando ao menu anterior...\n");
			Sleep(3000);
            menuII();
            break;
        case 2:
            printf("\nSaindo do programa...\n");
            Sleep(1000);
            exit(0);
            break;
        default:
            printf("\nOção inválida! Tente novamente, por favor.\n\n");
            system("pause");
            consulCadFuncionario();
    }
}

//relatório de resíduos
void consulCadResiduo(){
    system("cls");
    fflush(stdin);
    printf("***************************************\n");
    printf("*        PROGRAMA DE SOLUÇÕES         *\n");
    printf("*             AMBIENTAIS              *\n");
    printf("*        CONSULTAR RELATÓRIOS         *\n");
    printf("***************************************\n");


    FILE *file;
    file = fopen("cadastroresiduos.txt", "r");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
    }

    char texto [2000];

    while (fgets(texto,2000, file) != NULL){
        printf("%s", texto);
    }
    fclose(file);

    printf("\n");

    int opcao;

    printf("\nDeseja voltar ao menu anterior?\n");
    printf("\n[1] Sim. \n[2] Não (sair do programa).\n");
    printf("\nOpção Escolhida: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            printf("\nRetornando ao menu anterior...\n");
			Sleep(3000);
            menuII();
            break;
        case 2:
            printf("\nSaindo do programa...\n");
            Sleep(1000);
            exit(0);
            break;
        default:
            printf("\nOpção inválida! Tente novamente, por favor.");
            consulCadResiduo();
    }
}
