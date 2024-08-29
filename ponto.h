struct musica{
char artista[256];
int codigo;
char titulo[256];
char letra[256];
int execucoes;
};
struct nodo{
struct nodo *prox;
struct musica *informacao;
};
struct desc_LSE{
struct nodo *lista;
int tamanho;
};
struct playlist{
	struct nodo *play;
	};
struct playlistaleatoria{
	struct nodo *play;
	};


void relatorio(struct desc_LSE *minhalista);


/////PLAYLIST 
struct nodo *crianodoplaylist();
struct playlist	*iniciaplaylist();
struct playlistaleatoria *iniciaplaylistaleatoria();
struct playlist *criaplaylist(struct desc_LSE *minhalista, struct playlist *minhaplaylist, struct nodo *meunodo);
void imprimeplaylist(struct playlist *minhaplaylist);
void imprimeplaylistaletoria(struct playlistaleatoria *minhaplaylist);
struct nodo *crianodo(char *minhafrase);
struct playlistaleatoria *criaplayaleatoria (struct desc_LSE *minhalista, struct playlistaleatoria *minhaplaylist, struct nodo *meunodo);

///////LISTA
struct desc_LSE *criaDescritor();
//////PESQUISA 
void pesquisacodigo(struct desc_LSE *minhaLista);
void pesquisatitulo(struct desc_LSE *minhaLista);
void pesquisaartista(struct desc_LSE *minhaLista);
//////INSERCAO
struct desc_LSE *insere(struct desc_LSE *minhaLista, struct nodo *novo_elemento);
//////IMPRIME LISTA
void imprime(struct desc_LSE *minhaLista);
//////EXECUTA MUSICA
struct desc_LSE *executarplaylist(struct desc_LSE *minhalista, struct playlist *pessoal);
struct desc_LSE *executaraleatoria(struct desc_LSE *minhalista, struct playlistaleatoria *aleatoria);
struct desc_LSE *executar(struct desc_LSE *minhaLista, struct playlist *minhaplaylist);
