#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include <string.h>

void quebraFrase(char *frase,int n);

int main(){
	struct nodo *novonodo;
	struct nodo *nodoplaylist;
	struct nodo *nodoplaylistaleatoria;
	struct desc_LSE *minhalista;
	struct playlist *minhaplaylist;
	struct playlistaleatoria *playaleatoria;
	int op=0, op1=0, opcase4=0, opcao=0, opdnv=0;
	int  n=0;
	char caractere;
	char frase[256];
	playaleatoria=iniciaplaylistaleatoria();
	minhalista=criaDescritor();
	FILE *arquivoEntrada;
	arquivoEntrada = fopen("musicas.txt","r");
	if(arquivoEntrada ==NULL){
		printf("não foi possivel abrir o arquivo\n");
		exit(-1);
	}
	int tamanhoAcervo;
	fscanf(arquivoEntrada,"%d",&tamanhoAcervo);
	printf("tamanho do acervo sera %d\n",tamanhoAcervo);
	//aloca a struct musica com o tamanho do acervo
	while(1){
	printf("\n============Menu=============\n");
	printf("1.Inserir musicas no Spotyfom\n");
	printf("2.Esvaziar a playlist\n");
	printf("3.Criar uma Playlist\n");
	printf("4.Buscar musica\n");
	printf("5.Imprimir musicas\n");
	printf("6.Relatorio do programa\n");
	printf("7.Executar musica\n");
	printf("8.Imprimir sua Playlist\n");
	printf("9.Sair do programa\n");
	printf("\n=============================\n");
	printf("informe a opcao:");
	setbuf(stdin,NULL);
	scanf("%i", &op);
	
	
	
	
	switch(op){
		
	case 1:

	while((caractere = fgetc(arquivoEntrada))!= EOF){
		if(caractere != '\n'){ //caractere diferente de \n guarda em frase
			
			frase[n]=caractere;
			n++;
		}
		else{//encontrou \n
			if(n > 0){
			    
				frase[n]='\0';
				//quebraFrase(frase,n);
				novonodo=crianodo(frase);
				minhalista=insere(minhalista,novonodo);
				
			}
			n=0;
			frase[n]='\0';
		}
	}
	break;
	
	case 2:
	minhaplaylist=iniciaplaylist();
	playaleatoria=iniciaplaylistaleatoria();
	printf("\nNova Playlist alocada com sucesso\n");
	break;
	case 3:
	if (minhalista->lista==NULL){
		printf("\n=============================\n");
		printf("\nInsira as musicas na lista\n");
		printf("\n=============================\n");
		break;
		}
		
	nodoplaylist=crianodoplaylist();
	nodoplaylistaleatoria=crianodoplaylist();
	printf("\n=============================\n");
	printf("\n1.Playlist de sua escolha\n");
	printf("\n2.Playlist Aleatoria\n");
	printf("\n=============================\n");
	printf("\ninforme sua opcao\n");
	setbuf(stdin,NULL);
	scanf("%i", &op1);
	switch(op1){
	case 1:
	minhaplaylist=criaplaylist(minhalista,minhaplaylist,nodoplaylist);
	 break;
	 case 2:
	playaleatoria=criaplayaleatoria(minhalista,playaleatoria,nodoplaylistaleatoria);
	 break;
	 default:
	printf("\n=============================\n");
	printf("\nOpcao invalida\n");
	printf("\n=============================\n");
	break;
	}
	
	break;
	case 4:
	if (minhalista->lista==NULL){
		printf("\n=============================\n");
		printf("\nInsira as musicas na lista\n");
		printf("\n=============================\n");
		break;
		}
	printf("\n=============================\n");
	printf("\n1.Pesquisar por codigo\n");
	printf("\n2.Pesquisar por Titulo\n");
	printf("\n3.Pesquisar por Artista\n");
	printf("\n=============================\n");
	printf("\nInforme sua opcao\n");
	setbuf(stdin,NULL);
	scanf("%i", &opcase4);
		switch(opcase4){
		case 1:
		printf("\n=============================\n");
		printf("\nVoce escolheu opcao 1\n");
		printf("\n=============================\n");
		pesquisacodigo(minhalista);
		break;
		case 2:
		printf("\n=============================\n");
		printf("\nVoce escolheu opcao 2\n");
		printf("\n=============================\n");
		pesquisatitulo(minhalista);
		break;
		case 3:
		printf("\n=============================\n");
		printf("\nVoce escolheu opcao 3\n");
		printf("\n=============================\n");
		pesquisaartista(minhalista);
		break;
		default:
		printf("\n=============================\n");
		printf("\nOpcao invalida\n");
		printf("\n=============================\n");
	break;
	}
	break;
	case 5:
	if (minhalista->lista==NULL){
		printf("\n=============================\n");
		printf("\nInsira as musicas na lista\n");
		printf("\n=============================\n");
		break;
		}
	imprime(minhalista);
	break;
	case 6:
	if (minhalista->lista==NULL){
		printf("\n=============================\n");
		printf("\nInsira as musicas na lista\n");
		printf("\n=============================\n");
		break;
		}
	relatorio(minhalista);
	break;
	case 7:
	if (minhalista->lista==NULL){
		printf("\n=============================\n");
		printf("\nInsira as musicas na lista\n");
		printf("\n=============================\n");
		break;
		}
	printf("\n=============================\n");
		printf("\n1.Executar playlist pessoal\n2.Executar playlist aleatoria\n3.Executar musica\n");
		printf("\n=============================\n");
		printf("\nInforme a opcao\n");
		scanf("%i",&opdnv);
		switch(opdnv){
	case 1:
	minhalista=executarplaylist(minhalista,minhaplaylist);
	break;
	case 2:
	minhalista=executaraleatoria(minhalista,playaleatoria);
	break;
	case 3:	
	minhalista=executar(minhalista,minhaplaylist);
	break;
	default:
		printf("\n=============================\n");
		printf("\nOpcao invalida\n");
		printf("\n=============================\n");
	break;
	
}
	break;
	case 8:
	if (minhalista->lista==NULL){
		printf("\n=============================\n");
		printf("\nInsira as musicas na lista\n");
		printf("\n=============================\n");
		break;
		}
	printf("\n1.Imprimir playlista pessoal\n2.Imprimir playlista aleatoria\n");
	setbuf(stdin,NULL);
	scanf("%i", &opcao);
	switch(opcao){
	case 2:
	printf("\n=============================\n");
	printf("\nIMPRIMINDO PLAYLIST ALEATORIA\n");
	printf("\n=============================\n");
	imprimeplaylistaletoria(playaleatoria);
	break;
	case 1:
	printf("\n=============================\n");
	printf("\nIMPRIMINDO PLAYLIST PESSOAL\n");
	printf("\n=============================\n");
	imprimeplaylist(minhaplaylist);
	break;
	default:
		printf("\n=============================\n");
		printf("\nOpcao invalida\n");
		printf("\n=============================\n");
	break;
	}
	break;
	case 9:
	printf("\nSaindo do programa\n");
	return 0;
	break;
	default:
	printf("\n=============================\n");
	printf("\nOpcao invalida\n");
	printf("\n=============================\n");
	break;
	
	
	
	
	
}}
	return 0;
}

void quebraFrase(char *frase,int n){
	//com a frase em mãos é só dividir a frase e adicionar nas structs musica
	printf("\n\n===================================\n");
	
	printf("artista é: %s \n",strtok(frase,";"));
	printf("codigo é: %s \n",strtok(NULL,";"));
	printf("titulo é: %s \n",strtok(NULL,";"));
	printf("letra é: %s \n",strtok(NULL,";")); 
	printf("===================================\n");
	return;
}


/* exemplo de como inserir do acervo na lista criando uma copia da musica do acervo
 * 
insernaLista(struct musica *Acervo,int indice,struct descLista *lista){
	struct musicaLista *nova = criaMusicaLista(Acervo[indice]->artista,Acervo[indice]->titulo,Acervo[indice]->codigo,Acervo[indice]->letra);
	struct nodo* novo = criaNodoLista(lista,nova);
	insereLista(lista,novo);
}
*/
