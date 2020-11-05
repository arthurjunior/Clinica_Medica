#include <stdio.h>
#include <stdlib.h>
#include <locale.h>	
#include <string.h>
#include <locale.h>
#include <unistd.h>

typedef struct{
	char nome[20];
	char telefone[10];
	int matricula;
	char email[50];
	char login[15];
    char senha[15];
	
}Funcionario;

typedef struct{
	char rua[20];
	int casa;
	char bairro[20];
}Endereco;

typedef struct{
	char nome[20];
	int codigo;
}Espec;

typedef struct{
	char nome[20];
	char cpf[12];
	char crm[6];
	
}medico;

typedef struct{
	char nome[20];
	char telefone[10];
	char email[50];
}paciente;

char loginAdm[15];
char senhaAdm[15];
int countFunc = 0;
int countEsp = 0;
Funcionario vetfun[2];
Espec vetesp[2]; 

void Login();
void MenuAdmin();
void MenuFunc();
void Especialidade();
void Func();
void cadMedico();
void Paciente();
void cadEspecialidade();



main(){
	setlocale(LC_ALL,"portuguese");
	do {
		Login();
	} while(true);
}//fim main


void Login(){
	system("cls");
	strcpy(loginAdm,"ADM");
	strcpy(senhaAdm,"123");
	int op = 0, checked = 0;
	char login[15], senha[15];

	printf("---SEJA BEM VINDO---\n");
	printf("Login: ");
	fflush(stdin);
	gets(login);
	printf("Senha: ");
	fflush(stdin);
	gets(senha);
	
	if(stricmp(login,loginAdm)== 0 && stricmp(senha,senhaAdm) == 0){	
		checked = 1;
		MenuAdmin();	
	}
	
	for(int i = 0; i < countFunc; i++) {
		if(stricmp(vetfun[i].login, login) == 0 && stricmp(vetfun[i].senha, senha) == 0) {
			checked = 1;
			MenuFunc();
		}
	}
	
	if (checked == 0) {
		printf("\nLogin ou senha inv�lida, tente novamente...");
		sleep(2);
	
	}
	
	
	
}
void MenuAdmin(){
	
int op;

	 do{
	 system("cls");	
	 printf("------------MENU------------\n");
	 printf("1-Gerenciar.\n");
	 printf("0-Sair\n");
	 scanf("%d",&op);
	 switch(op){
		case 1:
		 do{
	 system("cls");	
	 printf("------------GERENCIAR------------\n");
	 printf("1-Especialidade\n");
	 printf("2-Funcionario\n");
	 printf("3-Medico\n");
	 printf("4-Paciente\n");
	 printf("0-voltar\n");
	 scanf("%d",&op);
	 switch(op){
		case 1:
		 Especialidade();
			break;
		case 2:
		Func();
			break;
		case 3:
		cadMedico();
			break;
		case 4:
		Paciente();
			break;			
		case 0:
			op = 0;
			break;
		default:
		printf("Op��o inv�lida\n");	
			
     }//fim switch Gerenciar
     system("pause");
	}while(op!=0);//fim do while gerenciar
			break;
		case 0:
			op = 0;
			break;
		default:
		printf("Op��o inv�lida\n");	
			
     }//fim switch menu
     system("pause");
	}while(op!=0);//fim do while menu	
	
}//fim procedimento menu
void MenuFunc(){
	
int op;

	 do{
	 system("cls");	
	 printf("------------MENU FUNCIONARIO------------\n");
	 printf("1-Gerenciar.\n");
	 printf("0-Sair\n");
	 scanf("%d",&op);
	 switch(op){
		case 1:
		printf("** OK Fun��o em contru��o**\n");
			break;
		case 0:
			op = 0;
			break;
		default:
		printf("Op��o inv�lida\n");	
			
     }//fim switch menu
     system("pause");
	}while(op!=0);//fim do while funcionario	
	
}//fim procedimento funcionario
void Especialidade(){
	int op;
 do{
 	
	 system("cls");	
	 printf("------------ESPECIALIDADE------------\n");
	 printf("1-Cadastrar\n");
	 printf("2-Alterar\n");
	 printf("3-Pesquisar\n");
	 printf("4-Excluir\n");
	 printf("0-voltar\n");
	 scanf("%d",&op);
	 switch(op){
		case 1:
		 cadEspecialidade();
			break;
		case 2:
		
			break;
		case 3:
		
			break;
		case 4:
		
			break;			
		case 0:
			op = 0;
			break;
		default:
		printf("Op��o inv�lida\n");	
			
     }//fim switch Gerenciar
     system("pause");
	}while(op!=0);//fim do while gerenciar	
}
void cadEspecialidade(){
   	int op = 2;
	if (countFunc <= 1) {
			do{
			 system("cls");	
			 printf("------------CADASTRO DE ESPECIALIDADE------------\n");
			 
			 printf("Digite o nome da especialidade: ");
			 fflush(stdin);
			 gets(vetesp[countEsp].nome);
			 
			 printf("\nDigite o codigo da especialidade: ");
			 fflush(stdin);
			 scanf("%d", &vetesp[countEsp].codigo);
			 
			
			 do {
			 	printf("\nEspecialidade cadastrado com sucesso! Deseja cadastrar mais? 1 - SIM, 0 - N�O");
			 	fflush(stdin);
			 	scanf("%d", &op);
			 	
			 	if (op != 0 && op != 1) {
			 		printf("\nOp��o inv�lida, escolha uma das op��es!!");
				} else {
					countEsp++;
				}
				
				if (countEsp >= 2){
					printf("\nBase de Especialidade j� est� cheia");
					op = 0;
				}
			 } while(op != 0 && op != 1);
		}while(op!=0);//fim do while menu	
	} else {
		printf("\n Base de dados das especialidades est� cheia!!");
	}
}
void cadMedico(){
	printf("**OK Fun��o em contru��o**\n");
}
void Paciente(){
	printf("**OK Fun��o em contru��o**\n");
}
void Func(){
		int op = 2;
	if (countFunc <= 1) {
			do{
			 system("cls");	
			 printf("------------CADASTRO DE FUNCION�RIO------------\n");
			 
			 printf("Digite o nome do funcionario: ");
			 fflush(stdin);
			 gets(vetfun[countFunc].nome);
			 
			 printf("\nDigite a matr�cula do funcionario: ");
			 fflush(stdin);
			 scanf("%d", &vetfun[countFunc].matricula);
			 
			 printf("\nTelefone: ");
			 fflush(stdin);
			 gets(vetfun[countFunc].telefone);
			 
			 printf("\nEmail: ");
			 fflush(stdin);
			 gets(vetfun[countFunc].email);		
			 
			 printf("\nLogin: ");
			 fflush(stdin);
			 gets(vetfun[countFunc].login);	
			 
			 printf("\nSenha: ");
			 fflush(stdin);
			 gets(vetfun[countFunc].senha);	
			 
			 do {
			 	printf("\nFuncionario cadastrado com sucesso! Deseja cadastrar mais? 1 - SIM, 0 - N�O");
			 	fflush(stdin);
			 	scanf("%d", &op);
			 	
			 	if (op != 0 && op != 1) {
			 		printf("\nOp��o inv�lida, escolha uma das op��es!!");
				} else {
					countFunc++;
				}
				
				if (countFunc >= 2){
					printf("\nBase de funcionarios j� est� cheia");
					op = 0;
				}
			 } while(op != 0 && op != 1);
		}while(op!=0);//fim do while menu	
	} else {
		printf("\n Base de dados dos funcionarios est� cheia!!");
	}
}
