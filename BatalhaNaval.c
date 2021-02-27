#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_BLUE "\033[1;34m"
#define ANSI_COLOR_RED "\033[1;31m"
#define ANSI_COLOR_GREEN "\033[1;32m"
#define ANSI_COLOR_RESET "\x1b[0m"

void limpaTela() /*Funciona para limpar a tela do terminal*/
{
#ifdef __WIN32__
system("CLS");
#else
    system("clear");
#endif
}

void tabuleiro_zero(int tabuleiro[9][9]) /*essa funcao inicia todos os  elementos da matriz com 0*/
{
	int i, j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			tabuleiro[i][j] = 0;
		}
	}
}

void rand_9(int tabuleiro[9][9])/*essa funcao utiliza da funcao random para determinar aonde os barcos ficarao alocados no tabuleiro*/
{
	int navio_1[2];
	int navio_1b[2], navio_1c[2], navio_1d[2], navio_2[2], navio_3[2], navio_3b[2], navio_4[2], navio_4b[2], navio_5[2],i,j;
	navio_5[0] = rand()%9;
	navio_5[1] = rand()%3;
	for(i=navio_5[1],j=0;j<5;j++,i++)/*barco de 5 posicoes*/
	{
		tabuleiro[navio_5[0]][i] = 1;
	}
	do
	{
	navio_4[0] = rand()%9;
	navio_4[1] = rand()%4;
	}while(navio_4[0]==navio_5[0]);
	for(i=navio_4[1],j=0;j<4;j++,i++)/*barco de 4 posicoes*/
	{
		tabuleiro[navio_4[0]][i] = 1;
	}
	do
	{
	navio_4b[0] = rand()%9;
	navio_4b[1] = rand()%4;
	}while(navio_4b[0]==navio_5[0] || navio_4b[0] == navio_4[0]);
	for(i=navio_4b[1],j=0;j<4;j++,i++)/*barco de 4 posicoes*/
	{
		tabuleiro[navio_4b[0]][i] = 1;
	}

	do
	{
	navio_3[0] = rand()%9;
	}while(navio_3[0]==navio_4[0] || navio_3[0]==navio_4b[0] || navio_3[0]==navio_5[0]);
	navio_3[1] = rand()%7;
	for(i=navio_3[1],j=0;j<3;j++,i++)/*barco de 3 posicoes*/
	{
		tabuleiro[navio_3[0]][i] = 1;
	}

	do
	{
		navio_3b[0] = rand()%9;
	}while(navio_3b[0]==navio_4[0] || navio_3b[0]==navio_4b[0] || navio_3b[0]==navio_5[0] || navio_3b[0]==navio_3[0]);
	navio_3b[1] = rand()%7;
	for(i=navio_3[1],j=0;j<3;j++,i++)/*barco de 3 posicoes*/
	{
		tabuleiro[navio_3b[0]][i] = 1;
	}

	do
	{
		navio_2[0] = rand()%9;
	}while(navio_2[0]==navio_4[0] || navio_2[0]==navio_3[0] || navio_2[0]==navio_3b[0] || navio_2[0]==navio_4b[0] || navio_2[0]==navio_5[0]);
	navio_2[1] = rand()%8;
	for(i=navio_2[1],j=0;j<2;i++,j++)/*barco de 2 posicoes*/
	{
		tabuleiro[navio_2[0]][i] = 1;
	}
	do
	{
		navio_1[0] = rand()%9;
		navio_1[1] = rand()%9;
	}while(tabuleiro[navio_1[0]][navio_1[1]] != 0);
	tabuleiro[navio_1[0]][navio_1[1]] = 1;/*barco de 1 posicao*/

	do
	{
		navio_1b[0] = rand()%9;
		navio_1b[1] = rand()%9;
	}while(tabuleiro[navio_1b[0]][navio_1b[1]] != 0);
	tabuleiro[navio_1b[0]][navio_1b[1]] = 1;/*barco de 1 posicao*/

	do
	{
		navio_1c[0] = rand()%9;
		navio_1c[1] = rand()%9;
	}while(tabuleiro[navio_1c[0]][navio_1c[1]] != 0);
	tabuleiro[navio_1c[0]][navio_1c[1]] = 1;/*barco de 1 posicao*/


	do
	{
		navio_1d[0] = rand()%9;
		navio_1d[1] = rand()%9;
	}while(tabuleiro[navio_1d[0]][navio_1d[1]] != 0);
	tabuleiro[navio_1d[0]][navio_1d[1]] = 1;/*barco de 1 posicao*/

	}

void mostrar(int tabuleiro[9][9]) /*Essa funcao mostra na tela o tabuleiro que sera visto pelo usuario durante o jogo*/
{
	int j, i;
	for(j=-1;j<9;j++)
	{
		if(j!=-1)/*Faz as Linhas*/
		{
			printf("%d+ ", j+1);
		}
		for(i=0;i<9;i++)
		{
			if(j==-1)/*Faz as Colunas*/
			{
				printf("   1 2 3 4 5 6 7 8 9\n   + + + + + + + + + ");
				break;
			}
			if(tabuleiro[j][i]==1 || tabuleiro[j][i] == 0)
			{
				printf(ANSI_COLOR_BLUE"~ "ANSI_COLOR_RESET);
			}
			else if(tabuleiro[j][i]==-1)
			{
				printf(ANSI_COLOR_GREEN"O "ANSI_COLOR_RESET);
			}
			else if(tabuleiro[j][i]==-2)
			{
				printf(ANSI_COLOR_RED"X "ANSI_COLOR_RESET);
			}
		}
		printf("\n");
		
	}
}

int tiro_linha(int tam) /*essa funcao eh responsavel por ler a linha em que o jogador deseja realizar a jogada e retorna o valor da mesma menos 1*/
{
	int linha;
	printf("\nDigite a linha do tiro: ");
	scanf("%d", &linha);
	if(linha<1 || linha>tam)
	{
		while(linha<1 || linha>tam)
		{
			printf("Linha invalida digite novamente: ");
			scanf("%d", &linha);
		}
	}
	return linha-1;
}
int tiro_coluna(int tam) /*essa funcao eh responsavel por ler a coluna em que o jogador deseja realizar a jogada e retorna o valor da mesma menos 1*/
{
	int coluna;
	printf("Digite a coluna do tiro: ");
	scanf("%d", &coluna);
	if(coluna<1 || coluna>tam)
	{
		while(coluna<1 || coluna>tam)
		{
			printf("Coluna invalida digite novamente: ");
			scanf("%d", &coluna);
		}
	}
	return coluna-1;
}

int jogoPlayer_Comp(int tabuleiro[9][9], int tabuleiro2[9][9]) /*Essa funcao eh responsavel pelo modo de jogo PLAYER X COMP*/
{
	int i=0, linha, coluna, pontos=0, multiplicador = 1,linha2,coluna2,j=0;/*variaveis para orientação do gabarito do tabuleiro*/
	tabuleiro_zero(tabuleiro);
	rand_9(tabuleiro);
	tabuleiro_zero(tabuleiro2);
	rand_9(tabuleiro2);
	for(i=25,j=25;i>0 && j>0;)/*i e j servem como verificadores da quantidade de barcos nos tabuleiros*/
	{	

		printf("--------Tabuleiro Player--------\n");
		mostrar(tabuleiro2);
		printf("\n\n---------------------------------------\n\n");
		printf("--------Tabuleiro COMP--------\n");
		mostrar(tabuleiro);
		linha = tiro_linha(9);
		coluna = tiro_coluna(9);
		limpaTela();
		do{
			linha2 = rand()%9;
			coluna2 = rand()%9;
		}
		while(tabuleiro2[linha2][coluna2] == -1 || tabuleiro2[linha2][coluna2] == -2);
		if(tabuleiro2[linha2][coluna2]==1)
		{
			printf("\n----------A Comp acertou!(%d,%d)----------\n",linha2,coluna2);
			j--;
			tabuleiro2[linha2][coluna2] = -1;
		}
		else if(tabuleiro2[linha2][coluna2]==0)
		{
			printf("\n----------A Comp errou!(%d,%d)----------\n",linha2+1,coluna2+1);
			tabuleiro2[linha2][coluna2] = -2;
		}


		if(tabuleiro[linha][coluna]==1)
		{
			printf("\n----------Voce acertou!----------\n\n");
			i--;
			tabuleiro[linha][coluna] = -1;
			pontos = pontos + 10*multiplicador;
			multiplicador++;
		}
		else if(tabuleiro[linha][coluna]==0)
		{	
			printf("\n----------Voce errou!----------\n\n");
			tabuleiro[linha][coluna] = -2;
			multiplicador=1;
		}
		else
		{
			printf("\nCoordenadas ja escolhidas, tente novamente\n\n");
		}
	}
	if(j==0)
	{	
		limpaTela();
		printf("VOCE Perdeu! VOCE FEZ %d PONTOS\n\n", pontos);
	}
	else if(i==0)
	{
		limpaTela();
		printf("VOCE GANHOU! VOCE FEZ %d PONTOS\n\n", pontos);
	}
	return pontos;
}





int jogoPlayer_Player(int tabuleiro[9][9], int tabuleiro2[9][9]) /*Essa funcao eh responsavel pelo modo de jogo PLAYER X PLAYER*/
{
	int i=0, linha, coluna,linha2,coluna2,j=25,pontos=0;/*variaveis para orientação do gabarito do tabuleiro*/
	tabuleiro_zero(tabuleiro);
	rand_9(tabuleiro);
	tabuleiro_zero(tabuleiro2);
	rand_9(tabuleiro2);
	for(i=25,j=25;i>0 && j>0;)/*i e j servem como verificadores da quantidade de barcos nos tabuleiros*/
	{	

		printf("--------Tabuleiro Player 1 --------\n");
		mostrar(tabuleiro2);
		printf("\n\n---------------------------------------\n\n");
		printf("--------Tabuleiro Player 2 --------\n");
		mostrar(tabuleiro);
		printf("\n----------Player 1----------\n\n");
		linha2 = tiro_linha(9);
		coluna2 = tiro_coluna(9);
		printf("\n----------Player 2----------\n\n");
		linha = tiro_linha(9);
		coluna = tiro_coluna(9);
		limpaTela();
		
		if(tabuleiro[linha2][coluna2]==1)
		{
			printf("\n----------Player 1 acertou!----------\n\n");
			j--;
			tabuleiro
			[linha2][coluna2] = -1;
		}
		else if(tabuleiro[linha2][coluna2]==0)
		{
			printf("\n----------Player 1 errou!----------\n\n");
			tabuleiro[linha2][coluna2] = -2;
		}
		else
		{
			printf("\n------Coordenadas ja escolhidas, Player 1 perdeu a vez-------\n\n");
		}


		if(tabuleiro2[linha][coluna]==1)
		{
			printf("\n----------Player 2 acertou!----------\n\n");
			i--;
			tabuleiro2[linha][coluna] = -1;

		}
		else if(tabuleiro2[linha][coluna]==0)
		{	
			printf("\n----------Player 2 errou!----------\n\n");
			tabuleiro2[linha][coluna] = -2;
		}
		else
		{
			printf("\n------Coordenadas ja escolhidas, Player 2 perdeu a vez-------\n\n");
		}
	}
	if(j==0)
	{	
		limpaTela();
		printf("PLAYER 1 GANHOU!\n\n");
	}
	else if(i==0)
	{
		limpaTela();
		printf("PLAYER 2 GANHOU!\n\n");
	}
	return pontos;
}

void menu() /*orienta o programa em si*/
{

	int tabuleiro_1[9][9];
	int tabuleiro_2[9][9];
	int opcao;
	int aux,aux2,resp,a;
	printf("\n----------------Batalha Naval----------------\n");
	printf("Digite:\n1 - Jogar\n2 - Como Jogar\n3 - Creditos\n4 - Encerrar\n");
	scanf("%d", &opcao);

	limpaTela();
	switch(opcao)
	{
	case 1:
		printf("\n1 - Player vs Comp\n2 - Player vs Player\n3 - Voltar\n");
		scanf("%d",&aux2);
		limpaTela();
		if(aux2==1)
		{
			jogoPlayer_Comp(tabuleiro_1,tabuleiro_2);
		}
		else if(aux2==2)
		{
			jogoPlayer_Player(tabuleiro_1,tabuleiro_2);
		}
		else
		{
			menu();
		}
		printf("Deseja Jogar Novamente?\n1 - Sim\n2 - Nao\n");
		scanf("%d", &resp);
		limpaTela();
		while(resp ==1)
		{
			if(resp == 1)
			{
				printf("\n1 - Player vs Comp\n2 - Player vs Player\n");
				scanf("%d", &a);
				limpaTela();

				if((a != 1) && (a != 2))
				{
					while((a != 1) && (a != 2))
					{
						printf("Escolha o Modo \n1 - Player vs Comp\n2 - Player vs Player\n");
						scanf("%d",&a);
						limpaTela();
					}
				}

				if(a == 1)
				{
					jogoPlayer_Comp(tabuleiro_1,tabuleiro_2);
				}else if(a == 2)
				{
					jogoPlayer_Player(tabuleiro_1,tabuleiro_2);
				}
			}
			else if(resp == 2)
			{
				menu();
			}
			else
			{
				menu();
			}
			printf("Deseja Jogar Novamente?\n1 - Sim\n2 - Nao\n");
			scanf("%d", &resp);
			limpaTela();
		}

		if(resp != 1)
		{	
			menu();
		}
	break;

	case 2:
		printf("\n-> Voce deve selecionar as coordenadas(coluna e linha) em que deseja realizar o tiro.\n");
		printf("\n-> Em caso de acerto, o \"~\", que representa a agua no tabuleiro, sera trocado por um \"O\", e em caso de erro por um \"X\".\n");
		printf("\n-> O jogo encerra apos todas as posicoes dos barcos serem acertadas.\n");
		printf("\n-> Caso o tiro seja em uma coordenada ja escolhida anteriormente, o jogador perde a vez.\n\n");
		printf("\n\n\n--------------------------------------------------------\n");
		printf("Digite um inteiro qualquer para retornar ao menu\n\n");
		scanf("%d", &opcao);
		limpaTela();
		if(opcao != 0)
		{
			menu();
		}else
		{
			menu();
		}
	break;

	case 3:
		printf("\nDensenvolvido por:\nCarlos Eduardo e Gabriela de Valnisio\n");
		printf("Projeto de Introducao a C/C++\n");
		printf("\n\n\n--------------------------------------------------------\n");
		printf("Digite um inteiro qualquer para retornar ao menu\n");
		scanf("%d", &opcao);
		limpaTela();
		if(opcao != 0)
		{
			menu();
		}else
		{
			menu();
		}
		
	break;
	case 4:
		printf("\nTem certeza que deseja encerra o jogo?\n");
		printf("1 - Sim\n2 - Nao\n\n");
		scanf("%d",&aux);
		limpaTela();
		if(aux==1)
		{
			exit(0);
		}
		else if(aux==2)
		{
			menu();
		}
		else
		{
			exit(0);
		}
	break;

	default:
		printf("\nValor Invalido\n");
		menu();

	}
}

int main()
{
	menu();
	return 0;
}