#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings


//inicio da função de registro
int registro() //função responsável por cadastrar os usuários no sistemas
{		
		//inicio da criação de variáveis/string
		char arquivo[40]; 
		char cpf[40]; //número de caracteres
		char nome[40];
		
		char sobrenome[40];
		char cargo[40];
		//fim da criação de variáveis/string
		
		printf("\tDigite o CPF a ser cadastrado: "); //coletando informações do usuário 
		scanf("%s", cpf); //escanea a resposta do usuário e armazena na string
		
		strcpy(arquivo, cpf); //responsável por copiar os valores das string
		
		printf("\n"); //pular linha
		FILE *file; //chama o FILE para criar um arquivo
		file = fopen(arquivo, "w"); //abre e criar (escrever = Write) o arquivo na pasta do projeto
		fprintf(file," CPF: "); //abre para guardar dentro do arquivo
		fprintf(file, cpf); //salva o valor da variável
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //abre para Alteração 
		fprintf(file, "\n Nome Completo: "); //abre e adiciona o que esta escrito 
		fclose(file);//fecha o arquivo
		printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário 
		scanf("%s", nome); //escanea a resposta do usuário e armazena na string
		
		file=fopen(arquivo, "a"); //abre o file para alteração
		fprintf(file, nome); //salva o valor da variável
		fclose(file); //fecha o arquivo
		
		file=fopen(arquivo, "a"); //abre o file para alteração
		fprintf(file, " ");  //abre e adiciona espaço
		fclose(file); //fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
		scanf("%s", sobrenome); //escanea a resposta do usuário e armazena na string
		
		file=fopen(arquivo, "a"); //abre file para alteração
		fprintf(file, sobrenome); //salva o valor da variável
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //abre para Alteração 
		fprintf(file, "\n Cargo: "); //abre e adiciona o que esta escrito
		fclose(file); //fecha o arquivo
		
		
		printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuário
		scanf("%s" , cargo); //escanea a resposta do usuário e armazena na string
		
		file = fopen(arquivo, "a"); //abre o file para alteração
		fprintf(file, cargo); //salva o valor da variável
		fprintf(file, "\n"); //adiciona quebra de linha 
	
		fclose(file); //fecha o arquivo
		
		printf("\n"); //pula linha
		system("pause"); //pausa para o usuário ler
}
//fim da função de registro

//inicio da função de consulta
int consulta() //função responsável por consultar os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//fim da criação de variáveis/string
	
	printf("\tDigite o CPF a ser consultado: "); //coletando informações do usuário
	scanf("%s", cpf); //escanea a resposta do usuário e armazena na string
	
	FILE *file; //chamado o file
	file=fopen(cpf,"r"); //abrindo o file para lê a variável cpf
	
	if(file==NULL) //igual a nulo /não existe   // != (diferente de)
	{	
		printf("\n"); //quebra de linha
		printf("Não foi possível abrir o arquivo, não localizado!\n\n"); //aviso ao usuário
		

	}
	
	else //caso contrário
	{
		system("cls"); //função de limpar a tela
		printf("\t Essas são as informações do usuário:\n\n"); //inicio das informações pedidas
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto(buscar(string conteudo(quantidade de caracteres(dentro da pasta/file)
	{
		
		printf("%s", conteudo); //mostra o as informações salvas na variável conteudo
	
	}
		printf("\n"); //quebra de linha
		fclose(file); //fecha o arquivo
		system("pause"); //pausa para o usuário poder ler
}
//fim da função de consulta

//inicio da função de consulta
int deletar() //função responsável por deletar os usuários do sistema
{
	
	char cpf[40]; //variável do tipo char para o cpf do usuário
	
	printf("\tDigite o CPF a ser deletado: "); //coletando informações do usuário
	scanf("%s", cpf); //escanea a resposta do usuário e armazena na string

	printf("\n"); //quebra de linha

	FILE *file; //chamando o file
	file=fopen(cpf, "r"); // read = ele lê o arquivo
	
	
	if(file==NULL) // se o for igual a nulo, arquivo não encontrado
	{
		printf("O usuário não se encontra no sistema!\n\n"); //aviso ao usuário
		system("pause"); //pausa para usuário poder ler
		
	}
	
	else //caso contrário
	{
	
		fclose(file); //fechamos o arquivo antes de deletar
	}
	
	if (remove(cpf) == 0) //se remove retornar à 0 conseguiu deletar o arquivo com sucesso
	{
  	  	system("cls"); //limpar a tela
		printf("Usuário deletado com sucesso!\n\n"); //aviso ao usuário
  	 	system("pause"); //pausa para o usuário poder ler
	} 
	else //caso remove retorne a um valor diferente de 0 houve algum erro.
	{
    	system("cls"); //limpar a tela
		printf("Erro ao deletar o usuário!\n\n"); //aviso ao usuário
    	system("pause"); //pausa para o usuário poder ler
	}
}
//fim da função de registro

int main() //função principal, aparece primeiro
{
	int opcao=0; //int=tipo inteiro //definindo variáveis
	int laco=1; //definindo variável seu valor
	
	for(laco=1;laco=1;) 
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("\t « Registro de usuários da EBAC » \n\n"); //inicio do menu
    	printf("> Escolha a opção desejada do menu: \n\n");
    	printf("\t1-Registrar nomes;\n");
    	printf("\t2-Consultar nomes;\n");
    	printf("\t3-Deletar nomes;\n");
    	printf("\t4-Sair do sistema.\n\n");
    	
    	printf("Opção: "); //fim do menu
    	
    	scanf("%d", &opcao); //escanea a resposta do usuário //%d = para números inteiros (resposta anterior do usuário)
    	
    	system("cls"); //para limpar a tela //system=para falar com o sistema
    	
    	switch(opcao) 
		{
    		case 1:
    		registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
    	 	break;
    	 	
    	 	case 3:
    	 	deletar(); //chamada de funções
    		break;
    		
    		case 4:
    		printf("\tObrigado por utilizar o sistema!\n");
    		return 0;
    		break;
    		
    		default:
    		printf("Essa opção não está disponível!\n\n"); //aviso ao usuário
			system("pause");
			break;
			
			
		}
	}
	
}
