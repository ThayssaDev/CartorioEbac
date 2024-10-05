#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings


//inicio da função de registro
int registro() //função responsável por registrar/cadastrar os usuários no sistemas
{		
		//inicio da criação de variáveis/string
		char arquivo[40]; //variável do tipo char (onde serão guardado os dados) //número de caracteres
		char cpf[40]; //variável do tipo char (onde serão guardado os cpf) //número de caracteres
		char nome[40]; //variável do tipo char (onde serão guardado os nomes) //número de caracteres
		char sobrenome[40]; //variável do tipo char (onde serão guardado os sobrenomes) //número de caracteres
		char cargo[40]; //variável do tipo char (onde serão guardado os cargos) //número de caracteres
		//fim da criação de variáveis/string
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário 
		scanf("%s", cpf); //escanea a resposta do usuário e armazena na string cpf
		
		strcpy(arquivo, cpf); //responsável por copiar os valores das string e guarda em outra
		
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
	char senhadigitada[10] ="a"; //criando função do tipo char e inicializando com "a"
	int comparacao;

	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		while (1) // Loop infinito até a senha correta
	{
			system("cls"); //limpa a tela
			printf("\t « Login para o Registro de usuários da EBAC » \n\n\n"); //indicação ao usuário de local do sistema
			printf("* Senha do Administrador: "); //pedido de senha para acesso
			scanf("%s", senhadigitada); //coleta e salva em 'senhadigitada'
	
		comparacao = strcmp(senhadigitada, "123"); //compara as duas strings
	
		if (comparacao == 0) //validação, se 'senhadigitada' for igual a 0 (nem maior e nem menor que zero) está correta (igual a certa)
		{
	   	 break; // Sai do loop se a senha estiver correta para entrar no menu principal
		} 
		else //caso contrário
		{
			system("cls"); //limpa a tela
			printf("\tSenha incorreta! Tente novamente!\n\n"); //aviso ao usuário
			system("pause"); //pause para ler
		}
	}


	system("cls"); //limpa a tela


	{

		for(laco=1;laco=1;) //for=loop (inicialização(1 foi usado para iniciar); condição(caso igual a inicialização o loop será infinito); incremento(não foi posto)
		{
			system("cls"); //limpa a tela
			
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
			printf("\t « Registro de usuários da EBAC » \n\n"); //inicio do menu
    		printf("> Escolha a opção desejada do menu: \n\n");  //menu opções
    		printf("\t1-Registrar nomes;\n"); //para registrar nomes digitar '1'
    		printf("\t2-Consultar nomes;\n"); //para consultar nomes digitar '2'
    		printf("\t3-Deletar nomes;\n"); //para deletar nomes digitar '3'
    		printf("\t4-Sair do sistema.\n\n"); //para encerrar o sistema digitar '4'
    		//fim do menu
    		printf("Opção: "); //local para inserir a opção
    	
    		scanf("%d", &opcao); //escanea a resposta do usuário //%d = para números inteiros (resposta anterior do usuário)
    	
    		system("cls"); //para limpar a tela //system=para falar com o sistema
    	
    		switch(opcao) //switch avalia a variável 'opcao' e compara com um dos casos abaixo 
			{
    			case 1: //caso 1 (se 'opcao' for igual à '1')
    			registro(); //chamada da função 'registro ()'
				break; //quebra do loop
			
				case 2: //caso 2 (se 'opcao' for igual à '2')
				consulta(); //chamada da função 'consulta ()'
    	 		break; //quebra do loop
    	 	
    	 		case 3: //caso 3 (se 'opcao' for igual à '3')
    	 		deletar(); //chamada da função 'deletar ()'
    			break; //quebra do loop
    		
    			case 4: //caso 4 (se 'opcao' for igual à '4')
    			printf("\tObrigado por utilizar o sistema!\n"); //aviso ao usuário
    			return 0; //interrompe imediatamente a execução do programa
    			break; //quebra do loop
    		
    			default: //caso não seja igual a nenhum dos casos anteriores..(caso contrário) 
    			printf("Essa opção não está disponível!\n\n"); //aviso ao usuário
				system("pause"); //pause para ler
				break; //quebra do loop
			
			} // fim do switch case
		} //fim do for
	}
	
	
}
