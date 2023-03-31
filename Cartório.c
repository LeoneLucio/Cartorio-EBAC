#include <stdio.h> //Biblioteca de comunica��o com usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca das strings

int registro()// Fun��o para cadastro dos usu�rios
{
	//Cria��o de vari�veis/strings
	char arquivo[40]; // o colchete indica que isto � uma string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informa��es com usu�rio
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf); //strcpy copia para um arquivo a string cpf

	FILE *file; //FILE cria o arquivo que, aqui, se chama file
	file = fopen(arquivo, "w"); //abre o arquivo com fopen e usa w para escrever -write- no arquivo
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a");//abre o arquivo para atualizar
	fprintf (file, ", ");//inclui uma v�rgula para organiza��o
	fclose (file);//fecha
	
	printf("Digite o nome a ser cadastrado: ");//Coleta de dados com usu�rio
	scanf("%s", nome);//%s salva os dados do usu�rio na string nome
	
	file = fopen(arquivo, "a");// abre o arquivo, comando "a" para atualizar
	fprintf(file,nome);// fprint dentro do arquivo file para inserir a string nome
	fclose(file);// fecha
	
	printf("Digite o sobrenome: ");//coleta de dados com usu�rio
	scanf("%s", sobrenome);//%s salva as vari�veis na string sobrenome
	
	file = fopen(arquivo, "a");//abrindo o arquivo para atulizar
	fprintf(file, " ");//inserindo espa�o entre nome e sobrenome
	fclose (file);//Fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,sobrenome); //printf dentro do file para inserir a string sobrenome
	fclose (file); //fecha
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar
	fprintf(file, ", ");// inserindo virgula e espa�o para organiza��o
	fclose (file); //Fecha
	
	printf("Digite o cargo: ");//Coletando dados com usu�ro
	scanf("%s", cargo);//Salvando os dados coletados em uma string com %s
	
	file = fopen(arquivo, "a");//abrindo o arquivo para atualizar
	fprintf(file, cargo);//printf dentro do file para inserir a string cargo
	fclose (file); //fecha
	
	system("pause"); //Pausa no sistema
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char cpf [40];//Criando strings
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");//coletando dados que ser�o consultados(CPF)
	scanf("%s", cpf);//salvando os dados do usu�rio na string
	
	FILE *file;//Cria o file
	file = fopen(cpf, "r");//abre o file para ler
	
	if(file == NULL)//comando "se" file for igual a NULL (inexistente) abre o comando dentro do {
	{
		printf("Arquivo n�o localizado. \n");// mensagem para comando NULL
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deleta()
{
	char cpf [40];//String CPF que pode ter 40 vari�veis/caracteres
	
	printf("Qual CPF deseja deletar?\n");//Mensagem ao usu�rio solicitando o CPF
	scanf("%s", cpf);//Salva o CPF na string com %s
	
	remove(cpf); //comando para deletar a string CPF
	
	FILE *file; //File chama o file
	file = fopen(cpf,"r");//dentro do file, fopen em CPF, "r" para remove
	
	printf("Deletado com sucesso");
	system("pause");
	
	if(file == NULL)	//Se o file n�o existe retorna a mensagem
	{
		printf("Arquivo n�o existe.\n");
		system("pause");		
	}
}

int main ()
{
	int opcao=0; //Definindo variaveis
	int laco=1; //Criando um la�o para retornar ao menu principal ao fim de cada a��o (registro, consulta, deleta)
	char senhadigitada [10]="a";
	
	printf ("\tBem vindo ao seu cart�rio digital\n\n");
	printf("Login de administrador!\n\n Digite sua senha: ");
	scanf("%s", senhadigitada);
	
	if(senhadigitada[10] == "admin")
	{
		for(laco=1;laco=1;)
	
		{
		setlocale (LC_ALL, "Portuguese");//Definindo linguagem
		
			system("cls"); //Comando para limpar a tela
			
			printf ("\tBem vindo ao seu cart�rio digital\n\n");//�nicio do menu
			printf ("O que deseja fazer hoje, senhor?\n\n");
			printf ("\t1 - Registrar nomes\n");
			printf ("\t2 - Consultar registros\n");
			printf ("\t3 - Excluir registros\n");
			printf ("\t4 - Sair do sistema\n\n");
			printf ("Digite o n�mero da sua op��o: ");//Fim do menu
		
			scanf("%d", &opcao);//Armazenando a escolha do usu�rio em &opcao (acho que � isso, tenho d�vidas)
		
			system ("cls");//Limpa tela
			
				switch(opcao)//Inicio da sele��o do menu, cada case � um n�mero que o usu�rio pode digitar para &opcao e assim chamar a fun��o equivalente.
				{
								
				case 1:
					registro(); //Chamada de fun��o
					break;//Encerra esse case
					
				case 2:
					consulta();//Chamada de fun��o
					break;//Encerra esse case
					
				case 3:
					deleta();//Chamada de fun��o
					break;//Encerra esse case
					
				case 4:
					printf("Obrigado por escolher nosso sistema!\n");
					return 0;
					break;
					
				default://para qualquer resposta invalida (default) envia o printf com mensagem de recysa
					printf("Op��o inv�lida\n");//mensagem de recusa
					system("pause");//Pausa o sistema
					break;//Encerra a situa��o
			}
		}
	}
else
	printf("senha incorreta");	
} 


	

