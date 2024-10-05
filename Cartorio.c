#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


//inicio da fun��o de registro
int registro() //fun��o respons�vel por registrar/cadastrar os usu�rios no sistemas
{		
		//inicio da cria��o de vari�veis/string
		char arquivo[40]; //vari�vel do tipo char (onde ser�o guardado os dados) //n�mero de caracteres
		char cpf[40]; //vari�vel do tipo char (onde ser�o guardado os cpf) //n�mero de caracteres
		char nome[40]; //vari�vel do tipo char (onde ser�o guardado os nomes) //n�mero de caracteres
		char sobrenome[40]; //vari�vel do tipo char (onde ser�o guardado os sobrenomes) //n�mero de caracteres
		char cargo[40]; //vari�vel do tipo char (onde ser�o guardado os cargos) //n�mero de caracteres
		//fim da cria��o de vari�veis/string
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio 
		scanf("%s", cpf); //escanea a resposta do usu�rio e armazena na string cpf
		
		strcpy(arquivo, cpf); //respons�vel por copiar os valores das string e guarda em outra
		
		printf("\n"); //pular linha
		FILE *file; //chama o FILE para criar um arquivo
		file = fopen(arquivo, "w"); //abre e criar (escrever = Write) o arquivo na pasta do projeto
		fprintf(file," CPF: "); //abre para guardar dentro do arquivo
		fprintf(file, cpf); //salva o valor da vari�vel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //abre para Altera��o 
		fprintf(file, "\n Nome Completo: "); //abre e adiciona o que esta escrito 
		fclose(file);//fecha o arquivo
		printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio 
		scanf("%s", nome); //escanea a resposta do usu�rio e armazena na string
		
		file=fopen(arquivo, "a"); //abre o file para altera��o
		fprintf(file, nome); //salva o valor da vari�vel
		fclose(file); //fecha o arquivo
		
		file=fopen(arquivo, "a"); //abre o file para altera��o
		fprintf(file, " ");  //abre e adiciona espa�o
		fclose(file); //fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
		scanf("%s", sobrenome); //escanea a resposta do usu�rio e armazena na string
		
		file=fopen(arquivo, "a"); //abre file para altera��o
		fprintf(file, sobrenome); //salva o valor da vari�vel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //abre para Altera��o 
		fprintf(file, "\n Cargo: "); //abre e adiciona o que esta escrito
		fclose(file); //fecha o arquivo
		
		
		printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usu�rio
		scanf("%s" , cargo); //escanea a resposta do usu�rio e armazena na string
		
		file = fopen(arquivo, "a"); //abre o file para altera��o
		fprintf(file, cargo); //salva o valor da vari�vel
		fprintf(file, "\n"); //adiciona quebra de linha 
	
		fclose(file); //fecha o arquivo
		
		printf("\n"); //pula linha
		system("pause"); //pausa para o usu�rio ler
}
//fim da fun��o de registro

//inicio da fun��o de consulta
int consulta() //fun��o respons�vel por consultar os usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de vari�veis/string
	
	printf("\tDigite o CPF a ser consultado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //escanea a resposta do usu�rio e armazena na string
	
	FILE *file; //chamado o file
	file=fopen(cpf,"r"); //abrindo o file para l� a vari�vel cpf
	
	if(file==NULL) //igual a nulo /n�o existe   // != (diferente de)
	{	
		printf("\n"); //quebra de linha
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n\n"); //aviso ao usu�rio
		

	}
	
	else //caso contr�rio
	{
		system("cls"); //fun��o de limpar a tela
		printf("\t Essas s�o as informa��es do usu�rio:\n\n"); //inicio das informa��es pedidas
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto(buscar(string conteudo(quantidade de caracteres(dentro da pasta/file)
	{
		
		printf("%s", conteudo); //mostra o as informa��es salvas na vari�vel conteudo
	
	}
		printf("\n"); //quebra de linha
		fclose(file); //fecha o arquivo
		system("pause"); //pausa para o usu�rio poder ler
}
//fim da fun��o de consulta

//inicio da fun��o de consulta
int deletar() //fun��o respons�vel por deletar os usu�rios do sistema
{
	
	char cpf[40]; //vari�vel do tipo char para o cpf do usu�rio
	
	printf("\tDigite o CPF a ser deletado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //escanea a resposta do usu�rio e armazena na string

	printf("\n"); //quebra de linha

	FILE *file; //chamando o file
	file=fopen(cpf, "r"); // read = ele l� o arquivo
	
	
	if(file==NULL) // se o for igual a nulo, arquivo n�o encontrado
	{
		printf("O usu�rio n�o se encontra no sistema!\n\n"); //aviso ao usu�rio
		system("pause"); //pausa para usu�rio poder ler
		
	}
	
	else //caso contr�rio
	{
	
		fclose(file); //fechamos o arquivo antes de deletar
	}
	
	if (remove(cpf) == 0) //se remove retornar � 0 conseguiu deletar o arquivo com sucesso
	{
  	  	system("cls"); //limpar a tela
		printf("Usu�rio deletado com sucesso!\n\n"); //aviso ao usu�rio
  	 	system("pause"); //pausa para o usu�rio poder ler
	} 
	else //caso remove retorne a um valor diferente de 0 houve algum erro.
	{
    	system("cls"); //limpar a tela
		printf("Erro ao deletar o usu�rio!\n\n"); //aviso ao usu�rio
    	system("pause"); //pausa para o usu�rio poder ler
	}
}
//fim da fun��o de registro

int main() //fun��o principal, aparece primeiro
{
	int opcao=0; //int=tipo inteiro //definindo vari�veis
	int laco=1; //definindo vari�vel seu valor
	char senhadigitada[10] ="a"; //criando fun��o do tipo char e inicializando com "a"
	int comparacao;

	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		while (1) // Loop infinito at� a senha correta
	{
			system("cls"); //limpa a tela
			printf("\t � Login para o Registro de usu�rios da EBAC � \n\n\n"); //indica��o ao usu�rio de local do sistema
			printf("* Senha do Administrador: "); //pedido de senha para acesso
			scanf("%s", senhadigitada); //coleta e salva em 'senhadigitada'
	
		comparacao = strcmp(senhadigitada, "123"); //compara as duas strings
	
		if (comparacao == 0) //valida��o, se 'senhadigitada' for igual a 0 (nem maior e nem menor que zero) est� correta (igual a certa)
		{
	   	 break; // Sai do loop se a senha estiver correta para entrar no menu principal
		} 
		else //caso contr�rio
		{
			system("cls"); //limpa a tela
			printf("\tSenha incorreta! Tente novamente!\n\n"); //aviso ao usu�rio
			system("pause"); //pause para ler
		}
	}


	system("cls"); //limpa a tela


	{

		for(laco=1;laco=1;) //for=loop (inicializa��o(1 foi usado para iniciar); condi��o(caso igual a inicializa��o o loop ser� infinito); incremento(n�o foi posto)
		{
			system("cls"); //limpa a tela
			
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
			printf("\t � Registro de usu�rios da EBAC � \n\n"); //inicio do menu
    		printf("> Escolha a op��o desejada do menu: \n\n");  //menu op��es
    		printf("\t1-Registrar nomes;\n"); //para registrar nomes digitar '1'
    		printf("\t2-Consultar nomes;\n"); //para consultar nomes digitar '2'
    		printf("\t3-Deletar nomes;\n"); //para deletar nomes digitar '3'
    		printf("\t4-Sair do sistema.\n\n"); //para encerrar o sistema digitar '4'
    		//fim do menu
    		printf("Op��o: "); //local para inserir a op��o
    	
    		scanf("%d", &opcao); //escanea a resposta do usu�rio //%d = para n�meros inteiros (resposta anterior do usu�rio)
    	
    		system("cls"); //para limpar a tela //system=para falar com o sistema
    	
    		switch(opcao) //switch avalia a vari�vel 'opcao' e compara com um dos casos abaixo 
			{
    			case 1: //caso 1 (se 'opcao' for igual � '1')
    			registro(); //chamada da fun��o 'registro ()'
				break; //quebra do loop
			
				case 2: //caso 2 (se 'opcao' for igual � '2')
				consulta(); //chamada da fun��o 'consulta ()'
    	 		break; //quebra do loop
    	 	
    	 		case 3: //caso 3 (se 'opcao' for igual � '3')
    	 		deletar(); //chamada da fun��o 'deletar ()'
    			break; //quebra do loop
    		
    			case 4: //caso 4 (se 'opcao' for igual � '4')
    			printf("\tObrigado por utilizar o sistema!\n"); //aviso ao usu�rio
    			return 0; //interrompe imediatamente a execu��o do programa
    			break; //quebra do loop
    		
    			default: //caso n�o seja igual a nenhum dos casos anteriores..(caso contr�rio) 
    			printf("Essa op��o n�o est� dispon�vel!\n\n"); //aviso ao usu�rio
				system("pause"); //pause para ler
				break; //quebra do loop
			
			} // fim do switch case
		} //fim do for
	}
	
	
}
