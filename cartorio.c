#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema

{
	//Inicio criação de variáveis/string
 char arquivo[40];
 char cpf[40];
 char nome[40];
 char sobrenome[40];
 char cargo[40];
 //Final criação de variáveis/string

 printf("Digite o CPF a ser cadastrado: ");  //Coletando informação do usuario
 scanf("%s", cpf); //refere-se a string

 strcpy(arquivo, cpf); //Responsavel de copiar os valores de string 
 
 FILE *file; //cria o arquivo
 file = fopen(arquivo, "w"); //abrir arquivo e o "w" significa escrever
 fprintf(file,cpf); //salva o valor da variavel
 fclose(file); // fecha o arquivo
 
 file = fopen(arquivo, "a"); //abrir arquivo e o "a" significa atualizar o arquivo
 fprintf(file, ",");//salva o valor da variavel e o ","  é o que vamos gravar no arquivo
 fclose(file); // fecha o arquivo
 
 printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuario
 scanf("%s" ,nome);//refere-se a string
 
 file = fopen(arquivo, "a");  //abrir arquivo
 fprintf(file, " NOME: "); //salva o valor da variavel
 fclose(file); // fecha o arquivo
 
 file = fopen(arquivo, "a");//abrir arquivo
 fprintf(file,nome);//salva o valor da variavel
 fclose(file); // fecha o arquivo

 
 printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuario
 scanf("%s" ,sobrenome);//refere-se a string
 
 file = fopen(arquivo, "a"); //cria o arquivo
 fprintf(file, ", SOBRENOME: ");//salva o valor da variavel
 fclose(file); // fecha o arquivo
 
 file = fopen(arquivo, "a"); //abrir arquivo
 fprintf(file,sobrenome);//salva o valor da variavel
 fclose(file); // fecha o arquivo
 
 printf("Digite o cargo a ser cadastrado: ");  //Coletando informação do usuario
 scanf("%s" ,cargo);//refere-se a string
 
 file = fopen(arquivo, "a"); //abrir arquivo
 fprintf(file, ", CARGO: ");//salva o valor da variavel
 fclose(file); // fecha o arquivo
 
 file = fopen(arquivo, "a"); //abrir arquivo
 fprintf(file,cargo);//salva o valor da variavel
 fclose(file); // fecha o arquivo
 
}

int consulta() //função responsavel por consultar
  
{
    setlocale(LC_ALL, "portuguese"); // definindo a linguagem
    
         //Inicio criação de variáveis/string
	 char cpf[40];
	 char conteudo[200];//Final criação de variáveis/string
	 
	 printf("Digiteo CPF a ser consultado: "); //Coletando informação do usuario
	 scanf("%s",cpf); //refere-se a string
	 
	 FILE *file; //cria o arquivo
	 file = fopen(cpf,"r"); //abrir e "r"  ler arquivo
	 
	 if(file == NULL)
	 {
	 	 printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	 }

    
	 while(fgets(conteudo, 200, file) != NULL)
	 {
	    printf("\nEssas são as informaçoes do usuario: "); 
	 	printf("%s", conteudo);
	 	printf("\n\n");

	 }
	 
	 system("pause");
	 
}

int deletar()

{
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");//Coletando informação do usuario
	scanf("%s", cpf); //refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r"); //abrir e ler arquivo
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!. \n");
		
	}
	else if (file != NULL)
	{
		fclose(file);
		printf("Arquivo foi deletado com sucesso!");
		system("pause");
		remove(cpf);
	}
	
	
	
}

int main()
{
	int opcao=0; // definindo variaveis
	int laco=1;
	
	for (laco=1;laco=1;) 
{
	      system("cls"); //responsavel por limpar a tela
	      

 setlocale(LC_ALL, "portuguese"); // definindo a linguagem
           // inicio do menu
    printf("***Cartorio EBAC***");
	printf("escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registra nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n"); 
	printf("opção:"); 
	// final do menu
    
     scanf("%d", &opcao); //armazenando escolhas do usuario
  
      system("cls"); //responsavel por limpar a tela
      
      switch(opcao) // inicio da seleão do menu
    {
	      	case 1:
	         registro();
			 break;
			
			case 2:
		     consulta();
	            break;
	            
	        case 3:
	         deletar();
	         break;
	            
	        default:
	            printf("desculpa, escolha uma das opções disponiveis!\n");
                system("pause");  	
		     break; 
          
    }// fim da seleção


  }

}

