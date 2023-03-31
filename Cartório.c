#include <stdio.h> //Biblioteca de comunicação com usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca das strings

int registro()// Função para cadastro dos usuários
{
	//Criação de variáveis/strings
	char arquivo[40]; // o colchete indica que isto é uma string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informações com usuário
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf); //strcpy copia para um arquivo a string cpf

	FILE *file; //FILE cria o arquivo que, aqui, se chama file
	file = fopen(arquivo, "w"); //abre o arquivo com fopen e usa w para escrever -write- no arquivo
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a");//abre o arquivo para atualizar
	fprintf (file, ", ");//inclui uma vírgula para organização
	fclose (file);//fecha
	
	printf("Digite o nome a ser cadastrado: ");//Coleta de dados com usuário
	scanf("%s", nome);//%s salva os dados do usuário na string nome
	
	file = fopen(arquivo, "a");// abre o arquivo, comando "a" para atualizar
	fprintf(file,nome);// fprint dentro do arquivo file para inserir a string nome
	fclose(file);// fecha
	
	printf("Digite o sobrenome: ");//coleta de dados com usuário
	scanf("%s", sobrenome);//%s salva as variáveis na string sobrenome
	
	file = fopen(arquivo, "a");//abrindo o arquivo para atulizar
	fprintf(file, " ");//inserindo espaço entre nome e sobrenome
	fclose (file);//Fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,sobrenome); //printf dentro do file para inserir a string sobrenome
	fclose (file); //fecha
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar
	fprintf(file, ", ");// inserindo virgula e espaço para organização
	fclose (file); //Fecha
	
	printf("Digite o cargo: ");//Coletando dados com usuáro
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
	
	printf("Digite o CPF a ser consultado: ");//coletando dados que serão consultados(CPF)
	scanf("%s", cpf);//salvando os dados do usuário na string
	
	FILE *file;//Cria o file
	file = fopen(cpf, "r");//abre o file para ler
	
	if(file == NULL)//comando "se" file for igual a NULL (inexistente) abre o comando dentro do {
	{
		printf("Arquivo não localizado. \n");// mensagem para comando NULL
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deleta()
{
	char cpf [40];//String CPF que pode ter 40 variáveis/caracteres
	
	printf("Qual CPF deseja deletar?\n");//Mensagem ao usuário solicitando o CPF
	scanf("%s", cpf);//Salva o CPF na string com %s
	
	remove(cpf); //comando para deletar a string CPF
	
	FILE *file; //File chama o file
	file = fopen(cpf,"r");//dentro do file, fopen em CPF, "r" para remove
	
	printf("Deletado com sucesso");
	system("pause");
	
	if(file == NULL)	//Se o file não existe retorna a mensagem
	{
		printf("Arquivo não existe.\n");
		system("pause");		
	}
}

int main ()
{
	int opcao=0; //Definindo variaveis
	int laco=1; //Criando um laço para retornar ao menu principal ao fim de cada ação (registro, consulta, deleta)
	char senhadigitada [10]="a";
	
	printf ("\tBem vindo ao seu cartório digital\n\n");
	printf("Login de administrador!\n\n Digite sua senha: ");
	scanf("%s", senhadigitada);
	
	if(senhadigitada[10] == "admin")
	{
		for(laco=1;laco=1;)
	
		{
		setlocale (LC_ALL, "Portuguese");//Definindo linguagem
		
			system("cls"); //Comando para limpar a tela
			
			printf ("\tBem vindo ao seu cartório digital\n\n");//Ínicio do menu
			printf ("O que deseja fazer hoje, senhor?\n\n");
			printf ("\t1 - Registrar nomes\n");
			printf ("\t2 - Consultar registros\n");
			printf ("\t3 - Excluir registros\n");
			printf ("\t4 - Sair do sistema\n\n");
			printf ("Digite o número da sua opção: ");//Fim do menu
		
			scanf("%d", &opcao);//Armazenando a escolha do usuário em &opcao (acho que é isso, tenho dúvidas)
		
			system ("cls");//Limpa tela
			
				switch(opcao)//Inicio da seleção do menu, cada case é um número que o usuário pode digitar para &opcao e assim chamar a função equivalente.
				{
								
				case 1:
					registro(); //Chamada de função
					break;//Encerra esse case
					
				case 2:
					consulta();//Chamada de função
					break;//Encerra esse case
					
				case 3:
					deleta();//Chamada de função
					break;//Encerra esse case
					
				case 4:
					printf("Obrigado por escolher nosso sistema!\n");
					return 0;
					break;
					
				default://para qualquer resposta invalida (default) envia o printf com mensagem de recysa
					printf("Opção inválida\n");//mensagem de recusa
					system("pause");//Pausa o sistema
					break;//Encerra a situação
			}
		}
	}
else
	printf("senha incorreta");	
} 


	

