#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teca.h"
#define MAX 100

	
int main(int argc, char *argv[]) {	
	int saida = 0, opcao;
	int voltar1 = 0, opcao1;
	int voltar2 = 0, opcao2;
	Produto* produtos[MAX];
	Carrinho* carrinhos[MAX]; 
	int qtd_produtos, aux, aux2, aux3;
	int qtd_prod_carrin, aux_c, aux_c2, aux_c3, aux_c4;
	i_estoque(produtos);
	i_carrinho(carrinhos);
	
	aux2 = primeiro_acesso(produtos);
	aux3 = primeiro_acesso(produtos);
	qtd_prod_carrin = 0;	
	
	do{
		system("cls");
		printf("\nLoja de Produtos:\n");
		printf("\n(1) Gerenciar produtos");
		printf("\n(2) Registrar Pedido de Compra");	
		printf("\n(3) Sair\n");
		printf("\nSelecione a opcao desejada: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
	
				do{					
					system("cls");
					printf("Modificacoes no estoque:\n");					
					printf("\n1- Listar itens do estoque ");					
					printf("\n2- Incluir itens no estoque");
					printf("\n3- Alterar itens do estoque");
					printf("\n4- Consultar itens do estoque");	
					printf("\n5- Excluir itens do estoque");	
					printf("\n6- Voltar\n");
					printf("\nSelecione a opcao desejada: ");
					scanf("%d", &opcao1);
					
					switch(opcao1){
						case 1:
							system("cls");
							listar_produtos(aux3, produtos, qtd_prod_carrin); 
							getch();
							break;
						case 2:
							system("cls");
							qtd_produtos = incluir_produtos(produtos, aux3);
							aux2 = qtd_produtos;
							aux3 = qtd_produtos;
							getch();
							break;
						case 3:
							system("cls");
							alterar_produtos(aux2, produtos);
							getch();
							break;
						case 4:
							system("cls");
							consultar_produtos(produtos, aux3);
							getch();
							break;
						case 5:
							system("cls");
							listar_produtos(aux3, produtos, qtd_prod_carrin);
							aux3 = excluir_produtos(produtos, aux2);
							getch();
							break;
						case 6:
							voltar1 = 1;							
					}
				}while(!voltar1);
				break;				
			case 2:
				system("cls");
				do{					
					system("cls");
					printf("\nRegistrar Pedido de Compra:\n");
					printf("\n1- Adicionar produto no carrinho");
					printf("\n2- Consultar carrinho de compras");						
					printf("\n3- Alterar a quantidade de um produto do carrinho de compras");
					printf("\n4- Remover um produto do carrinho de compras");
					printf("\n5- Finalizar pedido");					
					printf("\n6- Voltar\n");
					printf("\nSelecione a opcao desejada: ");
					scanf("%d", &opcao1);
					
					switch(opcao1){
						case 1:
							system("cls");
							listar_produtos(aux3, produtos, qtd_prod_carrin);
							qtd_prod_carrin = adicionar_carrinho(carrinhos, produtos, aux_c3);
							aux_c = qtd_prod_carrin;
							aux_c2 = qtd_prod_carrin;
							aux_c3 = qtd_prod_carrin;
							aux_c4 = qtd_prod_carrin;
							getch();
							break;
						case 2:
							system("cls");
							listar_carrinho(aux_c4, carrinhos);
							getch();
							break;
						case 3:
							system("cls");
							listar_carrinho(aux_c4, carrinhos);
							aux_c3 = alterar_carrinho(carrinhos, aux_c4);
							aux_c4 = aux_c3;
							getch();
							break;     
						case 4:
							system("cls");
							listar_carrinho(aux_c4, carrinhos);
							aux_c2 = excluir_carrinho(carrinhos, aux_c4);
							aux_c4 = aux_c2;
							getch();
							break; 
						case 5:
							system("cls");
							concluir_compra(carrinhos, aux_c3, produtos);
							getch();
							exit(1);
							break; 
						case 6:
							voltar2 = 1;								
					}
				}while(!voltar2);			
				break;			
			case 3:
				saida = 1;
				break;					
			default:
				printf("\nOpcao invalida!\nFavor escolher uma opcao valida. ");
				getch();			
		}			
	}while(!saida);		
	return 0;
}
