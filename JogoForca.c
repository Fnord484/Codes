/* Projeto jogo da forca e dicionário feito pelo aluno Fernando Henrique Oliveira Silva de RA: 11.120.064-8
Vale avisar que por certas dificuldades o programa esta incompleto, contendo apenas o menu e o jogo da forca funcional, mas como ele não escolhe a palavra do dicionário, a palavra utilizada para jogar é escrito pelo jogador1 e adivinhada pelo jogador2
O menu criado, está completo e com todas as informações, permitindo selecionar a função que deseja, mas as funções de inserir e consultar a palavra se encontram indisponíveis, fazendo o programa retornar ao menu para selecionar outra opção
*/


//Imporatando as bibliotecas usadas
#include <stdio.h>
#include <string.h>
#include <unistd.h> //biblioteca incluida para utilização da função sleep(tempo)

//função de exibição da forca para até 6 erros
void forca (int erro){
  if (erro == 0){
    printf("\n\n################\n\n");
    printf("  ----------\n");
    printf(" /         |\n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf("_/_____________\n\n");   
  }  
  else if (erro == 1){
    printf("\n\n################\n\n");
    printf("  ----------\n");
    printf(" /         |\n");
    printf(" |         0\n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf("_/_____________\n\n"); 
    printf("\tNúmero de erros, por enquanto: %d \n\n", erro);
  }
  else if (erro == 2){
    printf("\n\n################\n\n");
    printf("  ----------\n");
    printf(" /         |\n");
    printf(" |         0\n");
    printf(" |         |\n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf("_/_____________\n\n"); 
    printf("\tNúmero de erros, por enquanto: %d \n\n", erro);
  }
  else if (erro == 3){
    printf("\n\n################\n\n");
    printf("  ----------\n");
    printf(" /         |\n");
    printf(" |         0\n");
    printf(" |         |\\\n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf("_/_____________\n\n"); 
    printf("\tNúmero de erros, por enquanto: %d \n\n", erro);
  }
  else if (erro == 4){
    printf("\n\n################\n\n");
    printf("  ----------\n");
    printf(" /         |\n");
    printf(" |         0\n");
    printf(" |        /|\\\n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf("_/_____________\n\n"); 
    printf("\tNúmero de erros, por enquanto: %d \n\n", erro);
  }
  else if (erro == 5){
    printf("\n\n################\n\n");
    printf("  ----------\n");
    printf(" /         |\n");
    printf(" |         0\n");
    printf(" |        /|\\\n");
    printf(" |          \\\n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf("_/_____________\n\n");
    //printf("\n\n Esta quase morrendo, se você tem fé já deixe o seu F\n\n");
    printf("\tNúmero de erros, por enquanto: %d \n\n", erro);
  }
  else if (erro == 6){ // no sexto erro o jogador perde
    printf("\n\n################\n\n");
    printf("  ----------\n");
    printf(" /         |\n");
    printf(" |         0\n");
    printf(" |        /|\\\n");
    printf(" |        / \\\n");
    printf(" |          \n");
    printf(" |          \n");
    printf(" |          \n");
    printf("_/_____________");
     printf("\n\nSinto muito, você perdeu! :(\nMais sorte na próxima vez\n");
    //depois de 4 segundos o programa quebrar o while da função jogo_forca e retornar ao menu
        sleep(4);
    }
}

//função criada apenas para exibir apenas a mensagem de vitória caso o jogador acerte a palavra
void venceu(int igual){
  printf("Parabéns você ganhouu!! Conseguiu acertar as %d letras!!\n", igual);
  printf("\nEnvie o sua chave pix abaixo para receber o seu prêmio!(brincadeira!)\n\n");
  printf("Aguarde um momento, em instantes vamos retornar ao menu...\n");
  //espera 4 segundos para programa quebrar o while da função jogo_forca e retornar ao menu
  sleep(10); 
}

//função da lógica do jogo da forca
void jogo_forca (){
  int ndig = 0, erro = 0, igual = 0;
  char palavra[100]; //declaração da variável que armazena a palavra que o jogador1 selecionou e que o jogador 2 deve adivinhar
  printf("***********Bem-vindo ao jogo da Forca***********\n\n");
  forca(erro); //inicia exibindo a forca com erro = 0, mostrando o desenho dela apenas
  printf("Digite a palavra a ser descoberta: ");
  fgets(palavra, 100, stdin); //o jogador 1 escreve a palavra desejada para o jogo
  ndig = strlen(palavra); //numero de caractéres contando com o enter
  ndig=ndig - 1; //numero de carctéres da palavra
  printf("A palavra digitada tem %d", ndig); //exibe o numero de digitos da palavra
  system("clear||cls"); //limpa a terminal

  //declarando a variável que armazena os caractéretes digitados pelo jogador 2
  char tela[ndig];
  for (int i =0; i<ndig; i++){
    //inicia a variável com undelines no lugar das letras da palavra
    tela[i]='_';
  }

  //loop com a lógica do jogo da forca
  while (1){
    system("clear||cls");
    //inicia sempre exibindo a forca com o número de erros exibidos no desenho da pessoa
    forca(erro);
    
    //se o jogador já tiver cometido 6 erros, a mensagem ja foi exibida na função forca(6), então o loop é quebrado
    if(erro == 6){
      break; 
    }
      
    //se o numero de digitos já digitados for igual ao num. dig total da palavra, inicia venceu e quebra o loop
    else if(igual == ndig){
      venceu(igual);
      break;
    }
    
    //se não, exibe as letras que faltam e as já digitadas e segue o jogo
    printf("\tAdivinhe: ");
    for(int i=0; i<ndig; i++){
      printf("%c ", tela[i]);
    }
    int auxerro = 1; // se for 1 = errou a letra, se for 0 = acertou a letra e inicia como 1

    //cria a variável letra e recebe ela pelo teclado
    char letra; 
    printf("\n\nDigite o seu chute: ");    
    scanf(" %c", &letra);

    //verifica se a letra é igual a algum caracter da variável palavra
    for(int i=0; i<ndig; i++){
      if (letra == palavra[i]){
        tela [i] = letra;
        auxerro = 0; //se for igual o auxerro se muda para 0 (acertou a letra)
      }
    }
    //verifica quantas letras acertou e acrescenta e registra o numero de acertos e igual
    for(int i=0; i<ndig; i++){
      if (tela[i]==palavra[i]){
        igual++;
        }
      }
    //se igual ainda for diferente de zero, não acertou a palavra toda
    if (igual != ndig){
      igual = 0; //volta a ser zero para recontar
    }
    //se não foi alterado continua como 1 (não acertou a letra)
    if (auxerro != 0){
      erro++;
    }
    }
   
}

//função principal com o menu e a lógica de seleção do programa
int main(void) {
  //loop infinito para função menu, sempre retorna a ela
    while(1){
      //limpa o terminal
      system("clear||cls");

      //exibe a interface e instruções do Menu
      printf("**********************************************\n");
      printf("\n\tBem-vindo ao jogo da Forca do Fe\n");
      printf("\n**********************************************\n");
      printf("\n\tAluno: Fernando Henrique Oliveira Silva \n\tRA: 11.120.064-8\n");
      printf("\n**********************************************\n\n");
      printf("\t\t\t\t|**********|\n\t\t\t\t|---Menu---|\n\t\t\t\t|**********|\n\n");
      printf("O que você deseja fazer em neste programa: \n");
      printf("- Jogo da forca (Digite 'forca').\n");
      printf("- Inserir palavra (Digite 'inserir').\n");
      printf("- Consultar palavra (Digite 'consultar').\n");
      printf("- sair do jogo (Digite 'sair').\n");

      //Solicita o usuário digitar a função desejada
      char escolha[100];
      printf("Insira a palavra para a opção que deseja no código: \n");
      fgets(escolha,100,stdin);

      //Caso a função digitada seja forca
      if (strcmp(escolha, "forca\n") == 0){
        system("clear||cls"); //limpa o terminal
        jogo_forca();//inicia o jogo da forca, mas após o jogo, não encerra o loop
        }

      //Caso a função digitada seja inserir a palavra
      else if (strcmp(escolha, "inserir\n") == 0){
        //Como a função está inválida no programa, exibe a mensagem de invalidez e após 4 segundos retorna ao menu
        printf("Esta função está inválida no momento\nRetornando ao menu...\n");
        sleep(4);
        }
      //Caso a função digitada seja consultar a palavra
      else if (strcmp(escolha, "consultar\n") == 0){
        //Como a função está inválida no programa, exibe a mensagem de invalidez e após 4 segundos retorna ao menu
        printf("Esta função está inválida no momento\nRetornando ao menu...\n");
        sleep(4);
        }
      //Caso a função digitada seja sair
      else if (strcmp(escolha, "sair\n") == 0){
        printf("Saindo do programa");//exibe a mensagem de saída
        break;//encerra o loop
        }
      else{//caso seja digitado algo diferente das opções, exibir a mensagem de erro e retornar 
        printf("\n\nOPÇÃO INVÁLIDA\n\nRetornando ao menu\n");
        sleep(4);
      }
        }
  return 0;
}
