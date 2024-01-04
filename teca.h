#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct produto{
	int codigo;
	int qtd_estoque;
	char descricao[50];	
	float valor;
}Produto, *PProduto, **PPProduto;

typedef struct carrinho{
	int codigo;
	int qtd_estoque;
	char descricao[50];
	float valor;
	int receita;
}Carrinho, *PCarrinho, **PPCarrinho;

void i_estoque(PPProduto ppp){
	int i;
	for(i=0; i<MAX; i++){     
    	ppp[i] = NULL; 
  	}   
}

void i_carrinho(PPCarrinho ppc){
	int i;
	for(i = 0; i<MAX; i++){
		ppc[i] = NULL;
	}
}

int primeiro_acesso(PPProduto ppp){
    int qtd_prod, i; 
    
    printf("\n-----------------------\nBem vindo ao aplicativo de vendas!!\n-----------------------\n");
    printf("\nPara comecar, digite quantos itens deseja cadastrar:\n ");
    scanf("%d",&qtd_prod);
        
    for(i=0; i<qtd_prod; i++){     
      	ppp[i] = (PProduto) malloc(sizeof(Produto));
      	if (ppp[i] == NULL){
         	printf("\n\nMemoria insuficiente\n\n");
        	 exit(1);           
      	}
      	system("cls");
      	printf("insira as informacoes do produto %d:\n", i+1);
		printf("Codigo: ");
		scanf("%d", &ppp[i]->codigo);
		printf("Descricao: ");
		scanf(" %[^\n]", ppp[i]->descricao);		
		printf("Quantidade do produto: ");
		scanf("%d", &ppp[i]->qtd_estoque);
		printf("valor: ");
		scanf("%f", &ppp[i]->valor);
    }            
   return qtd_prod;  
}

int incluir_produtos(PPProduto ppp, int aux){
    int qtd_prod, i; 

    printf("\nNumero de produtos que serao cadastrados:  ");
    scanf("%d",&qtd_prod);

    for(i=aux; i<qtd_prod + aux; i++){     
      ppp[i] = (PProduto) malloc(sizeof(Produto));
      if (ppp[i] == NULL){
         printf("\nMemoria insuficiente\n");
         exit(1);           
      }
      	printf("insira as informacoes do produto %d:\n\n", i+1);
		printf("Codigo: ");
		scanf("%d", &ppp[i]->codigo);
		printf("Descricao: ");
		scanf(" %[^\n]", ppp[i]->descricao);		
		printf("Quantidade do produto: ");
		scanf("%d", &ppp[i]->qtd_estoque);	
		printf("valor: ");
		scanf("%f", &ppp[i]->valor);
    }
    aux += qtd_prod;               
   return aux;  
}

void alterar_produtos(int qtd_prod, PPProduto ppp){
	int i;

    listar_produtos(qtd_prod, ppp);
    printf("\nInforme o produto que deseja alterar: ");
    scanf("%d", &i);
    printf("insira as informacoes do produto: %d:\n", i);
    printf("Codigo: ");
    scanf("%d", &ppp[i]->codigo);
    printf("Descricao: ");
    scanf(" %[^\n]", ppp[i]->descricao);
    printf("Quantidade do produto: ");
    scanf("%d", &ppp[i]->qtd_estoque);
    printf("valor: ");
    scanf("%f", &ppp[i]->valor);
    printf("\nAlteracao realizada com sucesso");
}

int excluir_produtos(PPProduto ppp, int qtd_prod){
	int i, j;

    printf("\nInforme o indice do produto que deseja excluir: ");
    scanf("%d", &i);
    if(qtd_prod == 2 && i == 1){
		return (qtd_prod - 1);
	}else if(qtd_prod == 2 && i == 0){
		for(j = i; j < qtd_prod; j++){
			ppp[j] = ppp[j+1];
		}
		return (qtd_prod - 1);
	}else if(i == qtd_prod - 1 && i != 0){
		return (qtd_prod - 1);
	}else if(i == qtd_prod - 1 && i == 0){
		return (qtd_prod - 1);
	}else{
		for(j = i; j < qtd_prod - 1; j++){
    		ppp[j] = ppp[j+1];
		}
		return (qtd_prod - 1);
	}
	
}

void consultar_produtos(PPProduto ppp, int qtd_prod){
	int i, j, opcao_consulta, sair;
	for(i=0; i<qtd_prod; i++){    
    	printf("**********\nIndice: %d\nDescricao: %s\nCodigo: %d\n**********\n",i, ppp[i]->descricao, ppp[i]->codigo);
  	}
  	printf("\nInforme o indice do produto a ser consultado: ");
  	scanf("%d", &j);
  	do{
  		system("cls");                
        printf("\n1- Quantidade disponivel");        
        printf("\n2- Valor ");
        printf("\n3- Sair ");
  		printf("\n\nEscolha a alternativa para detalhes: ");
  		scanf("%d", &opcao_consulta);
	  	switch(opcao_consulta){
	  		case 1:
                printf("\n%d disponivel em estoque", ppp[j]->qtd_estoque);
                getch();
                system("cls");
                break;
            case 2:
                printf("\nO produto custa: %.2f", ppp[j]->valor);
                getch();
            	system("cls");
                break;
	  		case 3:
	  			sair = 1;
	  			break;
		}
  	}while(sair == 0);	
}

void listar_produtos(int qtd_prod, PPProduto ppp, int qtd_prod_carrin){
  int i, j;
  for(i=0; i<qtd_prod; i++){
    printf("**********\nIndice %d\nCodigo: %d \nDescricao: %s\n**********\n",i, ppp[i]->codigo, ppp[i]->descricao);
  }
}

int adicionar_carrinho(PPCarrinho ppc, PPProduto ppp, int qtd_prod_carrin){
	int i, escolha, escolha2, aux, aux2; 
	int aux_c = 0;
	int j = 0;
	printf("\nEscolha um item: ");
	scanf("%d", &escolha);
	printf("\nInforme a quantidade a ser adicionado: ");
	scanf("%d", &escolha2);
	
	int x = 0;
	for(i=0;i<qtd_prod_carrin;i++){
		if(ppc[i]->codigo==ppp[escolha]->codigo){
			x = x + 1;
		}
	}

	if(ppp[escolha]->qtd_estoque >= (escolha2+x)){
		escolha2 = escolha2 + qtd_prod_carrin;
		if(qtd_prod_carrin == 1){
			for(i = 0; i < escolha2; i++){
				ppc[i] = (PCarrinho) malloc(sizeof(Carrinho));
				ppc[i]->codigo = ppp[escolha]->codigo;
				strcpy(ppc[i]->descricao, ppp[escolha]->descricao);
				ppc[i]->qtd_estoque = ppp[escolha]->qtd_estoque;
				ppc[i]->valor = ppp[escolha]->valor;
			}
		}else{
			for(i = qtd_prod_carrin; i < escolha2; i++){
				ppc[i] = (PCarrinho) malloc(sizeof(Carrinho));
				ppc[i]->codigo = ppp[escolha]->codigo;
				strcpy(ppc[i]->descricao, ppp[escolha]->descricao);
				ppc[i]->qtd_estoque = ppp[escolha]->qtd_estoque;
				ppc[i]->valor = ppp[escolha]->valor;
			}
		}
	}else{
		printf("Quantidade no estoque insuficiente");
	}
	getch();
	return escolha2;
}

void listar_carrinho(int qtd_prod_carrin, PPCarrinho ppc){
	int i, j; 
	float soma = 0;
	   
	for(i=0; i<qtd_prod_carrin; i++){
		if(ppc[i]->valor )    
    printf("**********\n%d \nCodigo: %d \nDescricao: %s \nQuantidade: %d\nValor: %.2f\n**********\n",i+1 ,ppc[i]->codigo, ppc[i]->descricao,  ppc[i]->qtd_estoque, ppc[i]->valor);
    	soma = soma + ppc[i]->valor;
	}
	printf("\n\nTotal: %.2f", soma);
}

int excluir_carrinho(PPCarrinho ppc, int qtd_prod_carrin){
	int i, j;

    printf("\nEscreva o indice do produto que deseja excluir: ");
    scanf("%d", &i);
    if(qtd_prod_carrin == 2 && i == 1){
		return (qtd_prod_carrin - 1);
	}else if(qtd_prod_carrin == 2 && i == 0){
		for(j = i; j < qtd_prod_carrin; j++){
			ppc[j] = ppc[j+1];
		}
		return (qtd_prod_carrin - 1);
	}else if(i == qtd_prod_carrin - 1){
		return (qtd_prod_carrin - 1);
	}else{
		for(j = i; j < qtd_prod_carrin; j++){
    		ppc[j] = ppc[j+1];
		}
		return (qtd_prod_carrin - 1);
	}
}

int alterar_carrinho(PPCarrinho ppc, int qtd_prod_carrin){
	int i, j, opcao, qtd, opcao2;
	
    printf("\nInforme o produto a ser alterado: ");
    scanf("%d", &i);
    printf("\nMudar quantidade do produto: \n1- Somar \n2- excluir:\n ");
    scanf("%d", &opcao);
    if(opcao == 1){
    	printf("\nInforme a quantidade a ser somada: ");
    	scanf("%d", &opcao2);
    	opcao2 += qtd_prod_carrin;
    	printf("%d", qtd_prod_carrin);
    	getch();
	    for(j = qtd_prod_carrin; j < opcao2; j++){
	    	ppc[j] = (PCarrinho) malloc(sizeof(Carrinho));
			ppc[j]->codigo = ppc[i]->codigo;
			strcpy(ppc[j]->descricao, ppc[i]->descricao);
			ppc[j]->qtd_estoque = ppc[i]->qtd_estoque;
			ppc[j]->valor = ppc[i]->valor;
		}
		return opcao2;
	}else{
		printf("\nInforme a quantidade a ser subtraida: ");
		scanf("%d", &opcao2);
			if(qtd_prod_carrin == 2 && j == 1){
				return (qtd_prod_carrin - opcao2);
			}else if(qtd_prod_carrin == 2 && j == 0){
				for(j = i; j < qtd_prod_carrin; j++){
					ppc[j] = ppc[j+1];
				}
			}else if(qtd == qtd_prod_carrin - 1){
				return (qtd_prod_carrin - opcao2);
			}else{
				for(j = i; j < qtd_prod_carrin - 1; j++){
    				ppc[j] = ppc[j+1];
				}
				return (qtd_prod_carrin - opcao2);
			}
		}
	}

void concluir_compra(PPCarrinho ppc, int qtd_prod_carrin, PPProduto ppp){
	int i;
	float soma;
	int valor_rand = rand();
	
	srand(time(0));
	printf("\nCompra %d finalizada!!\n", rand());
	
	FILE * arq;
	
	arq = fopen("historico_de_vendas.txt","w");
	if(arq == NULL){
		printf("\nNao foi possivel abrir o arquivo");
		exit(1);
	}	
	fprintf(arq,"\n****************\nCOMPROVANTE/HISTORICO:\n*****************\n");	
    for(i=0;i<qtd_prod_carrin;i++){  
		fprintf(arq,"**********\n%d \nCodigo: %d \nDescricao: %s \nQuantidade: %d\nvalor: %.2f\n**********\n",i+1,ppc[i]->codigo, ppc[i]->descricao, qtd_prod_carrin, ppc[i]->valor);  		
    	soma = soma + ppc[i]->valor;
	}
	fprintf(arq,"Preco total: %.2f", soma);
	fclose(arq);
}
