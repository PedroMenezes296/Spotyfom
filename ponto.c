#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
///////// LISTA 
struct desc_LSE *criaDescritor() {
  struct desc_LSE *novoDescLista =
      (struct desc_LSE *)malloc(sizeof(struct desc_LSE));
  novoDescLista->tamanho = 0;
  novoDescLista->lista = NULL;
  return novoDescLista;
}
////////// CRIA NODO AUXILIAR
struct nodo *crianodoplaylist(){
	struct nodo *novoElemento = (struct nodo *)malloc(sizeof(struct nodo));
  novoElemento->informacao = NULL;
  novoElemento->prox = NULL;
	return novoElemento;
	
	}
///////// NODO PARA INSERCAO
struct nodo *crianodo(char *frase) {
  struct nodo *novoElemento = (struct nodo *)malloc(sizeof(struct nodo));
  novoElemento->informacao = NULL;
  novoElemento->prox = NULL;

  struct musica *novaMusica = (struct musica *)malloc(sizeof(struct musica));
  

  char titulo[256], artista[256], letra[256];
  int codigo = 0;
  printf("\n\n===================================\n");
  strcpy(artista, strtok(frase,";"));
  printf("artista é: %s \n",artista);
  codigo=atoi(strtok(NULL,";"));
  printf("codigo é: %i \n",codigo);
  strcpy(titulo, strtok(NULL,";"));
  printf("titulo é: %s \n",titulo);
  strcpy(letra, strtok(NULL,";"));
  printf("letra é: %s \n",letra);
  printf("===================================\n");
  strcpy(novaMusica->titulo, titulo);
  strcpy(novaMusica->letra, letra);
  strcpy(novaMusica->artista, artista);
  novaMusica->codigo=codigo;
  novaMusica->execucoes=0;
  
  novoElemento->informacao = novaMusica;

  return novoElemento;
}
/////////////// INSERCAO
struct desc_LSE *insere(struct desc_LSE *minhaLista, struct nodo *novoElemento) {
 

  if (minhaLista->lista== NULL) { 
    novoElemento->prox = minhaLista->lista;
    minhaLista->lista=novoElemento;
    minhaLista->tamanho++;
    return minhaLista;
  } else {
	  struct nodo *aux=minhaLista->lista;
	  while(aux->prox!=NULL){
		  aux=aux->prox;
		  }
		  aux->prox=novoElemento;
			minhaLista->tamanho++;
    return minhaLista;
        }}

///////// PESQUISA POR CODIGO
void pesquisacodigo(struct desc_LSE *minhaLista){
  
  int codigo;
  printf("\nInforme o codigo da musica:\n");
  setbuf(stdin, NULL);
  scanf("%i", &codigo);
  struct nodo *aux = minhaLista->lista;
  while(aux!=NULL){
  
    if(aux->informacao->codigo==codigo){
	 printf("==============================================\n" );
     printf("\n Titulo:%s\n Artista:%s \n Letra:%s\n Codigo: %i\n Execucoes: %i \n", aux->informacao->titulo, aux->informacao->artista,aux->informacao->letra,aux->informacao->codigo,aux->informacao->execucoes);
     printf("==============================================\n" );
      return;
    }
    aux=aux->prox;
  }
  printf("\nSEU CODIGO NAO FOI ENCONTRADO\n");
  return ;}
  
void pesquisatitulo(struct desc_LSE *minhaLista){
	struct nodo *aux=minhaLista->lista;
	char titulo[256];
	
	printf("\nInforme o Titilo da musica:\n");
	setbuf(stdin,NULL);
	scanf("%[^\n]s",titulo);
	
	while(aux!=NULL){
		
	if(stricmp(titulo,aux->informacao->titulo)==0){
	printf("==============================================\n" );
	printf("\n Titulo:%s\n Artista:%s \n Letra:%s\n Codigo: %i \n", aux->informacao->titulo, aux->informacao->artista,aux->informacao->letra,aux->informacao->codigo);
	printf("==============================================\n" );
		}
	aux=aux->prox;
	}
	
	//if(stricmp(titulo,aux->informacao->titulo)==1){
	//printf("\nTITULO NAO ENCONTRADO\n");	
	//}

	return;}
void pesquisaartista(struct desc_LSE *minhaLista){
	struct nodo *aux=minhaLista->lista;
	char artista[256];
	printf("\nInforme o Artista da musica:\n");
	setbuf(stdin,NULL);
	scanf("%[^\n]s",artista);
	while(aux!=NULL){
	if(stricmp(artista,aux->informacao->artista)==0){
	printf("==============================================\n" );
	printf("\n Titulo:%s\n Artista:%s \n Letra:%s\n Codigo: %i\n Execucoes: %i \n", aux->informacao->titulo, aux->informacao->artista,aux->informacao->letra,aux->informacao->codigo,aux->informacao->execucoes);
	printf("==============================================\n" );
		}
	aux=aux->prox;
	}
	//if(stricmp(artista,aux->informacao->artista)==1){
	//	printf("\nARTISTA NAO ENCONTRADO\n");
	//	}
	
	}
  
  
///////// IMPRIME A LISTA
void imprime(struct desc_LSE *minhaLista){
  struct nodo *aux = minhaLista->lista;
  
  while(aux!=NULL){
	printf("========================Musica======================\n" );
     printf("\n titulo:[%s]\n Artista:[%s] \n Letra:[%s]\n codigo: [%i] \n", aux->informacao->titulo, aux->informacao->artista,aux->informacao->letra,aux->informacao->codigo);
    aux=aux->prox;
    
}
  printf("===================================================\n" );
}




///////// EXECUTA A MUSICA
struct desc_LSE *executarplaylist(struct desc_LSE *minhalista, struct playlist *pessoal){
	
	struct nodo *auxplaylist=pessoal->play;
	
	if(pessoal->play==NULL){
		printf("\nPLAYLIST VAZIA\n");
		return 0;
		}
	while(auxplaylist!=NULL){
		struct nodo *auxlista=minhalista->lista;
		while(auxlista!=NULL){
			if(auxplaylist->informacao->codigo==auxlista->informacao->codigo){
				auxlista->informacao->execucoes=auxlista->informacao->execucoes+1;
				}
		auxlista=auxlista->prox;
			}
		auxplaylist=auxplaylist->prox;
		}
return minhalista;
	}
struct desc_LSE *executaraleatoria(struct desc_LSE *minhalista, struct playlistaleatoria *aleatoria){
	
	struct nodo *auxplaylist=aleatoria->play;
	
	if(aleatoria->play==NULL){
		printf("\nPLAYLIST VAZIA\n");
		return 0;
		}
	while(auxplaylist!=NULL){
		struct nodo *auxlista=minhalista->lista;
		while(auxlista!=NULL){
			if(auxplaylist->informacao->codigo==auxlista->informacao->codigo){
				auxlista->informacao->execucoes=auxlista->informacao->execucoes+1;
				}
		auxlista=auxlista->prox;
			}
		auxplaylist=auxplaylist->prox;
		}	
	
	return minhalista;
	}






struct desc_LSE *executar(struct desc_LSE *minhaLista, struct playlist *minhaplaylist){
	int codigo;
  printf("\nInforme o codigo da musica:\n");
  setbuf(stdin, NULL);
  scanf("%i", &codigo);
  struct nodo *aux = minhaLista->lista;
  while(aux!=NULL){
    if(aux->informacao->codigo==codigo){
	 aux->informacao->execucoes=aux->informacao->execucoes+1;
	 printf("\nSUA MUSICA FOI ENCONTRADA\n");
	 return minhaLista;
    }
    aux=aux->prox;
  }
	printf("\nMUSICA NAO ENCONTRADA\n");
	
	return minhaLista;
	}
	
	
//////PLAYLIST 

struct playlistaleatoria *iniciaplaylistaleatoria(){
		struct playlistaleatoria *minhaplaylist=(struct playlistaleatoria *)malloc(sizeof(struct playlistaleatoria));
		minhaplaylist->play=NULL;
		return minhaplaylist;
		}
struct playlist	*iniciaplaylist(){
		struct playlist *minhaplaylist=(struct playlist *)malloc(sizeof(struct playlist));
		minhaplaylist->play=NULL;
		return minhaplaylist;
		}
		
struct playlistaleatoria *criaplayaleatoria (struct desc_LSE *minhalista, struct playlistaleatoria *minhaplaylist, struct nodo *meunodo){
	int tamanho=0;
	int x, auxiliar=0, aleatorio=0;
	if(minhaplaylist->play!=NULL){
		 printf("\n===================================================\n" );
		printf("\nEsvaziar a playlist\n");
		 printf("\n===================================================\n" );
		return 0;
		}
	printf("\nInforme o tamanho da playlist:\n");
	setbuf(stdin,NULL);
	scanf("%i", &tamanho);
	srand(time(NULL));
	for(x=0;x<tamanho;x++){
		struct nodo *aux=minhalista->lista;
		aleatorio=rand() %5000;
		for(auxiliar=0;auxiliar<aleatorio;auxiliar++){
			aux=aux->prox;
			}
		if(minhaplaylist->play==NULL){
		meunodo->informacao=aux->informacao;
		minhaplaylist->play=meunodo;
		}else{
		meunodo=crianodoplaylist();
		struct nodo *auxplaylist=minhaplaylist->play;
		while(auxplaylist->prox!=NULL){
		 auxplaylist=auxplaylist->prox;
		  }
		meunodo->informacao=aux->informacao;
		auxplaylist->prox=meunodo;
		}
		}
	return minhaplaylist;
	}		

struct playlist *criaplaylist(struct desc_LSE *minhalista, struct playlist *minhaplaylist, struct nodo *meunodo){
	struct nodo *aux=minhalista->lista;
 
	int codigo=0;
	printf("\nInforme o codigo da musica para adicionar na sua Playlist:\n");
	setbuf(stdin,NULL);
	scanf("%i", &codigo);
	while(aux!=NULL){
		if(aux->informacao->codigo==codigo){
			if(minhaplaylist->play==NULL){
    printf("\nPlaylist vazia inserindo no primeiro elemento\n");
    meunodo->informacao=aux->informacao;
    minhaplaylist->play=meunodo;
    return minhaplaylist;
  }
  else{
    printf("\nInserindo em Playlist ja alocada\n");
    meunodo->informacao=aux->informacao;
    meunodo->prox=minhaplaylist->play;
    minhaplaylist->play=meunodo;
    return minhaplaylist;
  }}
		aux=aux->prox;
		}
		printf("\nAVISO:Seu codigo nao foi encontrado\n");
	return minhaplaylist;
}

	void imprimeplaylist(struct playlist *minhaplaylist){
		if (minhaplaylist->play==NULL){
		printf("\n=============================\n");
		printf("\nPLAYLIST VAZIA\n");
		printf("\n=============================\n");
		return;
		}
		struct nodo *aux = minhaplaylist->play;
  while(aux!=NULL){
	printf("========================Musica======================\n" );
     printf("\n Titulo:%s\n Artista:%s \n Letra:%s\n Codigo: %i\n Execucoes: %i \n", aux->informacao->titulo, aux->informacao->artista,aux->informacao->letra,aux->informacao->codigo,aux->informacao->execucoes);
    aux=aux->prox;
    
}
  printf("===================================================\n" );
		
}
void imprimeplaylistaletoria(struct playlistaleatoria *minhaplaylist){
	if (minhaplaylist->play==NULL){
		printf("\n=============================\n");
		printf("\nPLAYLIST VAZIA\n");
		printf("\n=============================\n");
		return;
		}
		struct nodo *aux = minhaplaylist->play;
  while(aux!=NULL){
	printf("========================Musica======================\n" );
     printf("\n Titulo:%s\n Artista:%s \n Letra:%s\n Codigo: %i\n Execucoes: %i \n", aux->informacao->titulo, aux->informacao->artista,aux->informacao->letra,aux->informacao->codigo,aux->informacao->execucoes);
    aux=aux->prox;
    
}
  printf("===================================================\n" );
	}
void relatorio(struct desc_LSE *minhalista){
	
	FILE *arquivos;

arquivos = fopen("arquivos.txt", "w");
if(arquivos == NULL){
	printf("o arquivo de relatorio não foi aberto\n");
	exit(-1);
}

struct nodo *aux = minhalista->lista;
while(aux!=NULL){
printf("\nMusica:[%s]\nExecucoes:[%i]\n",aux->informacao->titulo, aux->informacao->execucoes);

fprintf(arquivos,"\nMusica:[%s]\nExecucoes:[%i]\n",aux->informacao->titulo, aux->informacao->execucoes);

aux=aux->prox;
}

	}
	
	
	
	
	
	
	
	
	
	
	
	
