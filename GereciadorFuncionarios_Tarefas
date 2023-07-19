//ESTRUTURA DE DADOS E ANÁLISE DE ALGORÍTMOS
//PROJETO FINAL - PROJETO GERENCIADOR DE FUNCIONÁRIOS E TAREFAS DA EMPRESA
//Fernando Henrique Oliveira Silva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------TYPEDEF-----------------------------------
typedef struct CelulaT{
 char *nometarefa;
 char *prazo;
 char *reg;
struct CelulaT *prox;
}CelulaT;

typedef struct Tarefa{
  struct CelulaT *tail;
  struct CelulaT *head;
  int count;
}Tarefa;

typedef struct Celula{//Estrutura célula para LDDE do colaborador
  struct Celula *proximo;
  struct Celula *anterior;
  char *nome;
  char *dpto;
  char *cargo;
  struct Tarefa *tarefa;
  int posicao;
}Celula;


typedef struct LDDE{//lista do colaborador 
  Celula *primeiro;
  int qtde;
  
}LDDE;

//-------------------------------FUNÇÕES-----------------------------------

LDDE *inicializa_lista(){                    //Funcão que inicia a lista 
  LDDE *lista = malloc(sizeof(LDDE));        //Aloca memoria para a lista
  lista->primeiro = NULL;                    //Declara lista vazia
  lista->qtde = 0;                           //Declara a quantidade de funcionarios como zero
  return lista;
}

Tarefa *inicializa_fila(){
	 Tarefa *tarefa = (Tarefa*) malloc(sizeof(Tarefa));
   tarefa->head=NULL;
   tarefa->tail=NULL;
   tarefa->count=0;
	return tarefa;
}

Celula *inicializa_celula(){
  Celula *celula = malloc(sizeof(Celula));
  Celula *proximo = NULL;
  Celula *anterior = NULL;
  celula->nome = "";
  celula->dpto = "";
  celula->cargo = "";
  celula->posicao = 0;
  celula->tarefa = inicializa_fila();
  return celula;
}

Celula *buscar(LDDE *lista)                    
{
  char nomed[100];
  Celula *celula = lista->primeiro;         
  if(lista->qtde != 0)                      
  {
    printf("Digite o nome do funcionário que deseja encontrar: ");
    scanf("%s", nomed);  
    while(celula != NULL && strcmp(nomed, celula->nome) != 0) 
      {
        celula = celula->proximo;           
      }
        if(celula == NULL)                
        {
          printf("Funcionário não encontrado!\n\n");
          return NULL;
        }
     printf("\nVocê escolheu o funcionário: ");         //Mostra ao usuário que o funcionário foi encontrado
     printf("%s\n", celula->nome);
     printf("Departamento: %s \n", celula->dpto);
     printf("Cargo: %s \n", celula->cargo);
     if(celula->tarefa!=NULL){
       CelulaT *percorre_tarefa = celula->tarefa->head;
       int i = 1;
       while(percorre_tarefa != NULL){
         printf("Tarefa %d: %s\n", i, percorre_tarefa->nometarefa);
         printf("Prazo %d: %s\n", i, percorre_tarefa->prazo);
         printf("Deata de registro %d: %s\n", i, percorre_tarefa->reg);
         printf("Count da tarefa %d: %d\n", i, celula->tarefa->count);
         percorre_tarefa = percorre_tarefa->prox;
         i++;
       }
     }
    return celula;      
  }
    //imprimo os dados do funcionario encontrado    
  else{
    printf("Não existem colaboradores cadastrados!\n\n");          //caso a lista esteja vazia
    //sleep(2);
    //system("clear");
  }  
  return NULL;
}


void inserir_nome(Celula *celula, char *nome){          //Função para inserir o nome
  celula->nome = nome;                                  //Nome digitado é igual ao ponteiro nome da celula
}

void inserir_departamento(Celula *celula, char *dpto){   //Função para inserir o departamento 
  celula->dpto = dpto;  
}
void inserir_cargo(Celula *celula, char *cargo){       //Função para inserir o cargo
  celula->cargo = cargo;  
}

void joga_direita(LDDE *lista, int posicaoIns){//ao inserir uma celula, aumenta a posição de todas as celulas a direita dela
  if(lista->primeiro != NULL){ //A lista nao vazia
    if(lista->primeiro->proximo == NULL) //so tem um cara na lista
    {
      lista->primeiro->posicao++;
      return;
    }    
  Celula *atual = lista->primeiro;
  while(atual->posicao != posicaoIns)
     atual=atual->proximo;
	while(atual != NULL){
    atual->posicao++;
		atual = atual->proximo;
	}
  }
  printf("A lista esta vazia!");
  return;
}

void joga_esquerda(LDDE *lista, int posicaoRem){//ao remover uma celula, diminui uma unidade de posição de todas as células que estão a direita
  Celula *atual = lista->primeiro;
  while(atual->posicao != posicaoRem)
     atual=atual->proximo;
	while(atual != NULL){
    atual->posicao--;
		atual = atual->proximo;
	}
}

int valid_posc(LDDE *lista, int posicao){//valida se uma posição inseriida para alguma função é válida 
  int valido=0;
  if (lista->qtde == 0 && lista->primeiro == NULL && posicao != 0){
    printf("\nDesculpe, a lista está vazia. Portanto não temos como realizar a ação nesta posição");
  }else {
    Celula *valid = lista->primeiro;
    while(valid!=NULL && valid->posicao != posicao){
      valid=valid->proximo;
    }
    if(valid==NULL){
       printf("Desculpe, a posição que você escolheu não existe na lista, por favor selecione outra");
      //colocar algum comando de voltar pra o menu
    }else{
      valido=1;
    }
  }return valido;
}

void inserir_inicio(LDDE *lista, char *nome, char *dpto, char *cargo){ //(adicionar tarefa futuramente)

  Celula *novo = inicializa_celula();
  inserir_nome(novo, nome);
  inserir_departamento(novo, dpto);
  inserir_cargo(novo, cargo);
  novo->posicao=0;
  //inserir_tarefa(celula, tarefa);
  if (lista->primeiro == NULL && lista->qtde == 0){
    lista->primeiro = novo;
  }else{
    joga_direita(lista, novo->posicao);
    //colocar a nova celula na posição primeiro
    //todas as outras celulas devem ir para a direita (aumenta a posição)
    //
    novo->proximo = lista->primeiro;
    lista->primeiro->anterior = novo;
    lista->primeiro = novo;
  }
  lista->qtde++;
}

void inserir_fim(LDDE *lista, char *nome, char *dpto, char *cargo){ //(adicionar tarefa futuramente)
  Celula *novo = inicializa_celula();
  inserir_nome(novo, nome);
  inserir_departamento(novo, dpto);
  inserir_cargo(novo, cargo);
  novo->posicao = lista->qtde;
  Celula *atual = lista->primeiro;
    if (lista->primeiro == NULL && lista->qtde == 0){
    lista->primeiro = novo;
  }else{
  while (atual->proximo != NULL){
    atual=atual->proximo;
  }
  atual->proximo = novo;
  novo->anterior = atual;
}  lista->qtde++;
}

void inserir_meio(LDDE *lista, char *nome, char *dpto, char *cargo, int posicao){ 
  Celula *atual = lista->primeiro;
  Celula *anterior=NULL;
  posicao = posicao - 1;
  if (lista->primeiro == NULL || posicao <= 0){ //caso 1: lista vazia e posição 1=0 (ou qualquer outra)
    inserir_inicio(lista, nome, dpto, cargo);
    return;
  }//else if (lista->primeiro != NULL && posicao <= 0){//caso 2: lista nao vazia e posicao 1=0
    //inserir_inicio(lista, nome, dpto, cargo);
    //return;
   //}
  else if(posicao > lista->qtde-1){//caso 3: Insercao em uma posicao maior do que a lista tem (considear que o usuario digita uma lista comecando do 1)
    inserir_fim(lista, nome, dpto, cargo);
    return;
  }else if (lista->primeiro != NULL && posicao > 0){ // caso 4: lista não vazia e posicao != 1=0
  Celula *novo = inicializa_celula();
  inserir_nome(novo, nome);
  inserir_departamento(novo, dpto);
  inserir_cargo(novo, cargo);
  novo->posicao = posicao;
  while (atual->posicao != posicao){
    anterior = atual;
    atual=atual->proximo;
  }
    joga_direita(lista, posicao);
    anterior->proximo = novo;
    novo->anterior = anterior;
    novo->proximo = atual;
    atual->anterior = novo;
    lista->qtde++;
  }
}

void remover_inicio(LDDE *lista){ //(adicionar tarefa futuramente)

  if (lista->primeiro == NULL && lista->qtde == 0){
    printf("Desculpe a lista está vazia");
    return;
    //Ação próxima
  }else{
    joga_esquerda(lista, 0);
    Celula *atual = lista->primeiro;
    lista->primeiro=atual->proximo;
    free(atual);
    lista->qtde--;
  }
}
/*
void remover_fim(LDDE *lista){ //(adicionar tarefa futuramente)
  if (lista->primeiro == NULL && lista->qtde == 0){
    printf("Desculpe a lista está vazia\n");
    sleep(2);
    system("clear");
    //Ação próxima
    return;
  }
  else{
  Celula *atual = lista->primeiro;
  Celula *anterior=NULL;
  if(atual->proximo == NULL){
    lista->primeiro =  NULL;
    free(atual);
  }else{
    anterior->proximo = NULL;
    free(atual);    
  }
  while (atual->proximo != NULL){
    anterior = atual;
    atual=atual->proximo;
  lista->qtde--;
  return;
  }
 
}*/

void remover_fim(LDDE *lista){ //(adicionar tarefa futuramente)
  if (lista->primeiro == NULL && lista->qtde == 0){
    printf("Desculpe a lista está vazia");
    sleep(2);
    system("clear");
    //Ação próxima
    return;
  }
  Celula *atual = lista->primeiro;
  if(atual->proximo == NULL){
    remover_inicio(lista);
    return;
  }
  Celula *anterior=NULL;
  while (atual->proximo != NULL){
    anterior = atual;
    atual=atual->proximo;
  }
  anterior->proximo = NULL;
  free(atual);
  lista->qtde--;
  return;
}


void remover_meio(LDDE *lista, int posicao){ 
  if (lista->primeiro == NULL && lista->qtde == 0){//caso 1: lista vazia
    printf("Desculpe a lista está vazia");
    //Ação próxima
    return;
}else{//se lista cheia
  posicao = posicao - 1;
  if (lista->primeiro != NULL && posicao <= 0){//caso:2 posição negativa
    remover_inicio(lista);
    return;
   }else if(posicao > lista->qtde){//caso 3: posição maior do que o tamanho da fila
    int mf_opc=0;
    printf("Você selecionou uma posição que não existe na fila. \nVocê deseja remover o último item da lista?\n\n");

    printf("1 - Sim quero remover o último item da lista\n");
    printf("2 - Não, quero escolher outra posição da lista\n");
    
    printf(" Digite o número da opção que deseja escolher: \n");
    scanf("%d", &mf_opc);
    printf(" Você escolheu a opção %d!\n", mf_opc);

    if (mf_opc == 1){
      remover_fim(lista);
      return;
    }else if(mf_opc == 2){
      //system(clear);
      int pos;
      printf(" Digite o número da opção que deseja escolher: \n");
      scanf("%d", &pos);
      remover_meio(lista, pos);
      return;
  }
  }else if (lista->primeiro != NULL && posicao >= lista->qtde-1){//caso 4: posição no fim
      remover_fim(lista);
      return;
  }else if(lista->primeiro != NULL && posicao < lista->qtde-1){//caso 5: posição no meio da lista
  Celula *atual = lista->primeiro;
  Celula *anterior=NULL;
  while (atual->posicao != posicao){
    anterior = atual;
    atual=atual->proximo;
  }
  joga_esquerda(lista, posicao);
  anterior->proximo = atual->proximo;
  atual->proximo->anterior = anterior;
  free(atual);
  lista->qtde--;
    return;
    }
  return;
}
  return;
}

void imprimir(LDDE *lista){
   if(lista->qtde != 0)                      
  {
	Celula *atual = lista->primeiro;
  printf("\n\n----- Informações do Colaborador -----\n\n");
	while(atual != NULL){
    printf("\n -- Colaborador %d: \n", atual->posicao+1);
		printf("\n %s ", atual->nome);
    printf("\n %s ", atual->dpto);
    printf("\n %s \n", atual->cargo);
    if(atual->tarefa->count != 0 && atual->tarefa->head != NULL && atual->tarefa->tail != NULL){
      printf("\n\n--Lista de Tarefas do colaborador\n\n");
      CelulaT *percorre_tarefa = atual->tarefa->head;
      int i = 1;
      while(percorre_tarefa != NULL){
        printf("Tarefa %d: %s\n", i, percorre_tarefa->nometarefa);
        printf("Prazo %d: %s\n", i, percorre_tarefa->prazo);
        printf("Deata de registro %d: %s\n", i, percorre_tarefa->reg);
        printf("Count da tarefa %d: %d\n", i, atual->tarefa->count);
        printf("\n");
        percorre_tarefa = percorre_tarefa->prox;
        i++;
      }
      printf("%d", lista->qtde);
    }else{
      printf("\n Ops! Colaborador não possui tarefas, ta achando que a vida é um morango em...\n\n");
    }
		atual = atual->proximo;
	}
	printf("\n");
}else{
  printf("A lista está vazia");
  }
}

void adiciona_tarefa(Celula *colaborador, char *nomet, char *reg, char *prazo){
  CelulaT *novo = malloc(sizeof(CelulaT));
  novo->nometarefa = nomet;
  novo->reg = reg;
  novo->prazo = prazo;
  if(colaborador == NULL){
    return;
  }
  else if(colaborador->tarefa->head==NULL && colaborador->tarefa->count == 0){ // caso 1:fila vazia
    colaborador->tarefa->head = novo;
    colaborador->tarefa->tail = novo;
    colaborador->tarefa->count++;
  }
  else{//caso 2: fila não vazia, insere no final
    colaborador->tarefa->tail->prox = novo;
    colaborador->tarefa->tail = novo;
    colaborador->tarefa->count++;
  }
  return;
}

void remove_tarefa( Celula *colaborador){
  if(colaborador == NULL){
    return;
  } else if(colaborador->tarefa->head==NULL && colaborador->tarefa->count == 0){ // caso 1:fila vazia
    printf("Não posso fazer isso pois a fila está vazia");
    return;
  }
  else{//caso 2: fila não vazia, insere no final só exclui neste caso
    CelulaT* excluir = colaborador->tarefa->head;
    colaborador->tarefa->head = colaborador->tarefa->head->prox;
    free(excluir);
    colaborador->tarefa->count--;
  }
  return;
}

void imprime_tarefa(Celula *colaborador){//funcao para mostrar toda a lista de tarefas de um colaborador
  if(colaborador->tarefa!=NULL){
      printf("\n\n--Lista de Tarefas do colaborador\n\n");
      CelulaT *percorre_tarefa = colaborador->tarefa->head;
      int i = 1;
      while(percorre_tarefa != NULL){
        printf("Tarefa %d: %s\n", i, percorre_tarefa->nometarefa);
        printf("Prazo %d: %s\n", i, percorre_tarefa->prazo);
        printf("Deata de registro %d: %s\n", i, percorre_tarefa->reg);
        printf("Count da tarefa %d: %d\n", i, colaborador->tarefa->count);
        printf("\n");
        percorre_tarefa = percorre_tarefa->prox;
        i++;
      }
    return;
    }else{
      printf("\n Ops! Colaborador não possui tarefas, ta achando que a vida é um morango em...\n\n");
    return;
    }
	printf("\n");
  return;
	}

void buscar_tarefa(Celula *celula, char *nomet){
  if(celula->tarefa->head == NULL && celula->tarefa->tail == NULL && celula->tarefa->count==0){
    printf("A fila de tarefas está vazia");
    return;
  }
  CelulaT *tarefa = celula->tarefa->head;
  int i=0;
    while(tarefa != NULL && strcmp(nomet, tarefa->nometarefa) != 0) // percorre toda a lista
      {
        tarefa = tarefa->prox;
        i++;
        //printf("\ncontador %d \n", i);
        //printf("\nlista qtde %d \n", lista->qtde);
      }
        if(tarefa == NULL)
        {
          printf("Tarefa não encontrada!\n\n");
          sleep(2);
          system("clear");
          return;
        }else{
    printf("\nVoce escolheu a tarefa: ");
    printf("%s\n", tarefa->nometarefa);
    printf("Prazo: %s \n", tarefa->prazo);
    printf("Registro: %s \n", tarefa->reg);
    return;
    //imprimo os dados do funcionario encontrado    
  }
  return;
}

void menu_funcao(LDDE *lista)
{
  int mf_opc=0;
  printf(" - - - - - FEFEL ENTERPRISE - - - - - \n");
  printf(" - - - - - - - FUNÇÕES - - - - - - - - \n\n");
  printf(" 1- Cadastrar no início da lista \n");
  printf(" 2- Cadastrar no meio da lista \n");
  printf(" 3- Cadastrar no final da lista \n");
  printf(" 4- Remover no início da lista \n");
  printf(" 5- Remover no meio da lista \n");
  printf(" 6- Remover no final da lista \n\n");

  printf(" Digite o número da opção que deseja escolher: \n");
  scanf("%d", &mf_opc);
  printf(" Você escolheu a opção %d!\n", mf_opc);

  if(mf_opc <= 0 || mf_opc >= 7)
  {
    printf(" Essa opção não existe!\n");
    sleep(2);
    system("clear");
  }
  else
  {
    sleep(2);
    system("clear");    
  }

  if(mf_opc == 1)
  {
    char *nome = malloc(sizeof(char));                 //sizeof(char)*50 -> caso dê errado
    char *departamento = malloc(sizeof(char));
    char *cargo = malloc(sizeof(char));
    printf("Digite os parâmetros do funcionário: \n\n");
    printf("Nome: ");
    scanf("%s", &*nome);
    printf("\nDepartamento: ");
    scanf("%s", &*departamento);
    printf("\nCargo: ");
    scanf("%s", &*cargo);
    inserir_inicio(lista, nome, departamento, cargo);
    printf("\nInformações inseridas com sucesso!\n\n"); 
    sleep(2);
    system("clear");
    return;
  }
  else if(mf_opc == 2)
  {
    char *nome = malloc(sizeof(char));
    char *departamento = malloc(sizeof(char));
    char *cargo = malloc(sizeof(char));
    int posicao=0;
    printf("Digite os parâmetros do funcionário: \n\n");
    printf("Nome: ");
    scanf("%s", &*nome);
    printf("\nDepartamento: ");
    scanf("%s", &*departamento);
    printf("\nCargo: ");
    scanf("%s", &*cargo);
    printf("\nPosição: ");
    scanf("%d", &posicao);
    inserir_meio(lista, nome, departamento, cargo, posicao);
    printf("\nInformações inseridas com sucesso!\n\n"); 
    sleep(2);
    system("clear");
    return;    
  }
  else if(mf_opc == 3)
  {
    char *nome = malloc(sizeof(char));
    //char *nome2 = malloc(sizeof(char));
    char *departamento = malloc(sizeof(char));
    char *cargo = malloc(sizeof(char));
    printf("Digite os parâmetros do funcionário: \n\n");
    printf("Nome: ");
    //scanf("%s %s", &*nome, &*nome2);
    scanf("%s", &*nome);
    printf("\nDepartamento: ");
    scanf("%s", &*departamento);
    printf("\nCargo: ");
    scanf("%s", &*cargo);
    inserir_fim(lista, nome, departamento, cargo);
    printf("\nInformações inseridas com sucesso!\n\n"); 
    sleep(2);
    system("clear");
    return;
  }
  else if(mf_opc == 4)
  {
    remover_inicio(lista); 
    sleep(2);
    system("clear");
  }  
  else if(mf_opc == 5)
  {
    int posicao = 0;
    printf("Qual a posição que deseja remover? \n");
    scanf("%d", &posicao);
    remover_meio(lista, posicao);
    sleep(2);
    system("clear");
  }
  else if(mf_opc == 6)
  {
    remover_fim(lista);
    sleep(2);
    system("clear");
  }
}
void menu_colaborador2(Celula *colab)     //ERRO DE PARAMETRO DA FUNÇÃO
{
  system("clear");
  printf(" - - - - - FEFEL ENTERPRISE - - - - - \n");
  printf(" - - - - - MENU COLABORADOR - - - - - \n\n");
  printf(" COLABORADOR: %s\n\n", colab->nome);
  
  printf(" 1 - Adicionar tarefa \n");
  printf(" 2 - Remover tarefa \n");
  printf(" 3 - Buscar tarefa \n");
  printf(" 4 - Mostra lista \n\n");
  printf(" 5 - Voltar \n\n");

  int m_opc;
  printf(" Digite o número da opção que deseja escolher: \n");
  scanf("%d", &m_opc);
  printf(" Você escolheu a opção %d!\n", m_opc);

  if(m_opc <= 0 || m_opc >= 6)
  {
    printf(" Essa opção não existe!\n");
    sleep(2);
    system("clear");
    return;
  }
  else
  {
    sleep(2);
    system("clear");    
  }

  if(m_opc == 1)
  {
    //adicionar tarefa
    char *nomeT = malloc(sizeof(char));
    char *prazo = malloc(sizeof(char));
    char *regist = malloc(sizeof(char));
    printf("Digite os parâmetros da tarefa: \n\n");
    printf("Tarefa: ");
    //scanf("%s %s", &*nome, &*nome2);
    scanf("%s", &*nomeT);
    printf("\nPrazo: ");
    scanf("%s", &*prazo);
    printf("\nData de registro: ");
    scanf("%s", &*regist);
    adiciona_tarefa(colab, nomeT, regist, prazo);
    printf("\nInformações inseridas com sucesso!\n\n"); 
    sleep(2);
    system("clear");
    menu_colaborador2(colab);
    }
  else if(m_opc == 2)
  {
    remove_tarefa(colab);
    printf("\n Tarefa removida com sucesso!\n\n");
    sleep(2);
    system("clear");
    menu_colaborador2(colab);  
  }  
  else if(m_opc == 3)
  {
    char *nomeT = malloc(sizeof(char));
    printf("Digite o nome da tarefa que deseja buscar: \n\n");
    scanf("%s", &*nomeT);
    
    buscar_tarefa(colab, nomeT);
    sleep(5);
    system("clear");
    menu_colaborador2(colab);    
  }else if(m_opc == 4)
  {
    imprime_tarefa(colab);
    sleep(5);
    system("clear");
    menu_colaborador2(colab);
  }else if(m_opc == 5)
  {
    system("clear");
    return;
}
return;
  
}

void menu_colaborador1(LDDE *lista)     //ERRO DE PARAMETRO DA FUNÇÃO
{
  
  system("clear");
  printf(" - - - - - FEFEL ENTERPRISE - - - - - \n");
  printf(" - - - - - MENU COLABORADOR - - - - - \n\n");
  Celula * colab = buscar(lista);
  if(colab == NULL){
    printf("O colaborador não está cadastrado na lista. Digite corretamente");
    menu_colaborador1(lista);
  }
  menu_colaborador2(colab);
  
}

void menu(LDDE *lista)
{
  system("clear");  
  int m_opc=0;
  system("clear");
  printf(" - - - - - FEFEL ENTERPRISE - - - - - \n");
  printf(" - - - - - - - - MENU - - - - - - - - \n\n");
  
  printf(" 1- Consultar lista de colaboratores \n");
  printf(" 2- Funções \n");
  printf(" 3- Interação Colaborador \n\n");
  
  printf(" Digite o número da opção que deseja escolher: \n");
  scanf("%d", &m_opc);
  printf(" Você escolheu a opção %d!\n", m_opc);

  if(m_opc <= 0 || m_opc >= 4)
  {
    printf(" Essa opção não existe!\n");
    sleep(2);
    system("clear");
  }
  else
  {
    sleep(2);
    system("clear");    
  }

  if(m_opc == 1)
  {
    //consultar lista de colaboradores
    if (lista->primeiro == NULL && lista->qtde == 0){
    printf("Desculpe a lista está vazia\n");
    sleep(2);
    system("clear");
    }else{
    imprimir(lista);
    sleep(5);
    system("clear");
    menu(lista);
    }
  }
  else if(m_opc == 2)
  {
    menu_funcao(lista);
  }  
  else if(m_opc == 3)
  {
    menu_colaborador1(lista);
    sleep(2);
    system("clear");
    menu(lista);    
  }
}

int main(void) {
  LDDE *lista = inicializa_lista();
  while (1)
    {
      menu(lista);
    }
  return 0;
}
