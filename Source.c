#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <locale>
#define MAX 100

typedef struct pacotes
{
	int ocupado;
	char escreve[1000];
}PACOTE;

typedef struct cliente
{
	int ncliente;
	char nome[100];
	int nif;
	char morada[100];
	int contacto;
	int ocupado;
}CLIENTE;

typedef struct pacoteFerias
{
	int noites;
	int precoF;
	char pacote[10];
}FERIAS;

typedef struct radical
{
	char tRadical[20];
	int pessoas;
}RADICAL;

typedef struct quarto
{
	char tQuarto[20];
}QUARTO;

typedef struct regime
{
	char tRegime[20];
}REGIME;

typedef struct ferias
{
	char tRegime[20];
	char tQuarto[20];
	char tRadical[20];
	int pessoas;
	int noites;
	int precoF;
	char estado[20];
	char pacote[10];
	int ocupado;
	int preco;
	int opp;
	int nviagem;
	float pagamentof;
	int cliente;
}FINAL;

typedef struct contratosterminados
{
	int ocupado;
}TERMINADO;

typedef struct inquerito
{
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	int ocupado;
}INQUERITO;


void iniciarInquerito(INQUERITO *inq, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		inq[i].ocupado = 0;
	}
}

void lerInquerito(INQUERITO *inq, int n)  // l� os inqueritos que est�o no ficheiro
{
	FILE *finq;
	finq = fopen("inqu�ritos.dat", "rb");
	while (!feof(finq)) // enquanto n�o chegar ao fim do ficheiro 
	{
		fread(inq, sizeof(INQUERITO), 1, finq);
		inq++;
	}
	fclose(finq);
}

void guardaInqueritos(INQUERITO *inq, FINAL *e, int n)   // guarda os inqueritos no ficheiro
{
	FILE *finq;
	finq = fopen("inqu�ritos.dat", "w");
	fwrite(inq, sizeof(INQUERITO), n, finq);
	fclose(finq);
}

void mostrarInqu�rito(INQUERITO *inq, FINAL *e,int n)  //mostra todos os inqueritos no ecr�
{
	for (int i = 0; i < n; i++)
	{
		if (inq[i].ocupado == 1)
		{

				printf("\nSimpatia e cortesia: %d\n",inq[i].n1);
				printf("\nProfissionalismo: %d\n",inq[i].n2);
				printf("\nCompreensao das suas necessidades: %d\n",inq[i].n3);
				printf("\nConhecimento dos servi�os oferecidos por parte do agente: %d\n",inq[i].n4);
				printf("\nInstala��es em geral: %d\n", inq[i].n5);
				printf("\nQualidade do seu quarto: %d\n", inq[i].n6);
				printf("\nServi�os prestados e atitude dos funcionarios do hotel: %d\n", inq[i].n7);	
				printf("\nHigiene e limpeza do hotel: %d\n", inq[i].n8);
				printf("\nQualidade de entretenimento do hotel: %d\n", inq[i].n9);
				printf("\nA sua viagem de f�rias correspondeu �s expectativas? %d\n", inq[i].n10);
				printf("\nEst� satisfeito com o pacote oferecido? %d\n", inq[i].n11);
				printf("\nUtilizaria a nossa ag�ncia novamente no futuro? %d\n", inq[i].n12);	
				system("pause");
				system("cls");
		}
	}

}


void iniciarcterminados(TERMINADO *t, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		t[i].ocupado = 0;
	}
}

void lerCterminados(TERMINADO *t, int n)  // l� os contratos terminados que est�o no ficheiro
{
	FILE *fc;
	fc = fopen("contratos terminados.dat", "rb");
	while (!feof(fc))
	{
		fread(t, sizeof(TERMINADO), 1, fc);
		t++;
	}
	fclose(fc);
}

void guardaClientesterminado(TERMINADO *t, FINAL *e, int n)   // guarda os contratos terminados no ficheiro
{
	FILE *fc;
	fc = fopen("contratos terminados.dat", "w");
	fwrite(e, sizeof(TERMINADO), n, fc);
	fclose(fc);
}

void removerCt(TERMINADO *t, FINAL *e, int n)
{
	int i;
	char estado1[20];
	for (i = 0; i < n; i++)
	{
		if ((strcmp(e[i].estado, "terminado") == 0)&&(e[i].ocupado==1))
		{
			printf("\nDados de contrato: ");
			printf("\nN�mero de Cliente:%d\nN�mero de viagem: %d\nPacote:%s\nQuarto:%s\nRegime:%s\nPre�o:%d\nEstado:%s\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].tQuarto, e[i].tRegime, e[i].precoF, e[i].estado);
			guardaClientesterminado(t, e, MAX);
			e[i].ocupado = 0;
			printf("\nRegisto eliminado\n");
		}

	}
}

//---------CONTRATOS---------

int pacoteFerias(FERIAS *f)
{
	int opf;
	printf("Bem vindo ao Menu dos Pacotes de F�rias\n");
	printf("Todos os menus incluem um quarto single e pequeno almo�o\n");
	printf("Outro tipo de quarto ou outro regime de pens�o ter� um valor acrescido\n");
	printf("Escolha o pacote de f�rias\n\n");
	printf("1-Cruzeiro\n2-Hotel\n3-Resort\n4-Radical\n");
	scanf("%d", &opf);
	return opf;
}
int quarto(QUARTO *q)
{
	int opq;
	printf("\nQual o quarto que pretende?\n");
	printf("1-Duplo\n2-Triple\n3-Suite\n");
	scanf("%d", &opq);
	return opq;
}

int regime(REGIME *r)
{
	int opr;
	printf("\nQual o Regime que pretende escolher?\n");
	printf("\n1-Regime de Meia-Pens�o (inclui pequeno-almo�o e jantar)\n2-Regime de Pens�o Completa (inclui pequeno-almo�o,almo�o e jantar)\n\n");
	scanf("%d", &opr);
	return opr;
}

void iniciarContratos(FINAL*e, int n)   //inicializa os contratos
{
	int i;
	for (i = 0; i < n; i++)
	{
		e[i].ocupado = 0;
	}
}

void lerContratos(FINAL*e, int n)  // l� os contratos que est�o no ficheiro
{
	FILE *fi;
	fi = fopen("contratos.dat", "rb");
	while (!feof(fi))
	{
		fread(e, sizeof(FINAL), 1, fi);
		e++;
	}
	fclose(fi);
}


void escolhaComp(REGIME *r, QUARTO *q, FERIAS *f, RADICAL *ra, FINAL *e, CLIENTE *p, int n, int *codigoviagem)  //regista novo contrato
{
	int cdg, validacaoc;
	int i, opf, opq, opr, j;
	char l, a, b;
	char pacote[20];
	i = 0;
	j = 0;
	opf = pacoteFerias(f);
	validacaoc = 0;
	while ((e[i].ocupado != 0))
	{
		i++;
	}
	printf("Digite o n�mero de cliente: ");
	scanf("%d", &cdg);
	for (j = 0; j < n; j++)
	{
		if (p[j].ncliente == cdg)
			validacaoc = 1;
	}
	if (validacaoc == 1)
	{
		e[i].cliente = cdg;
		if (opf == 1)
		{
			strcpy(e[i].pacote, "Cruzeiro");
			e[i].preco = 1000;
			do
			{
				printf("Quer alterar o tipo de quarto ou regime de Pens�o?(S/N) \n");
				scanf(" %c", &l);
			} while ((l != 'S') && (l != 's')&& (l != 'N') && (l != 'n'));
			if ((l == 'S') || (l == 's'))
			{
				do
				{
					printf("Pretende alterar o quarto?(S/N)\n");
					scanf(" %c", &a);
				} while ((a != 'S') && (a != 's') && (a != 'N') && (a != 'n'));
				if ((a == 'S') || (a == 's'))
				{
					opq = quarto(q);
					if (opq == 1)
					{
						e[i].precoF = e[i].preco + 350;
						strcpy(e[i].tQuarto, "Quarto duplo");
					}
					if (opq == 2)
					{
						e[i].precoF = e[i].preco + 700;
						strcpy(e[i].tQuarto, "Quarto triple");
					}
					if (opq == 3) {
						e[i].precoF = e[i].preco + 1050;
						strcpy(e[i].tQuarto, "Quarto suite");
					}
					printf("Quarto alterado\n");
					do
					{
					printf("Pretende alterar o regime?(S/N)\n");
					scanf(" %c", &b);
					} while ((b != 'S') && (b != 's') && (b != 'N') && (b != 'n'));
					if ((b == 'S') || (b == 's'))
					{
						opr = regime(r);
						if (opr == 1)
						{
							e[i].precoF = e[i].preco + 500;
							strcpy(e[i].tRegime, "Meia-Pens�o");

						}
						if (opr == 2)
						{
							e[i].precoF = e[i].preco + 1000;
							strcpy(e[i].tRegime, "Pens�o Completa");
						}
						printf("Regime alterado\n");
					}
					else
					{
						strcpy(e[i].tRegime, "Pequeno Almo�o");
						printf("Regime n�o alterado\n");
					}
				}
				else if ((a == 'N') || (a == 'n'))
				{
					printf("Quarto n�o alterado\n");
					strcpy(e[i].tQuarto, "Quarto single");
					do
					{
					printf("Pretende alterar o regime?(S/N)\n");
					scanf(" %c", &b);
					} while ((b != 'S') && (b != 's') && (b != 'N') && (b != 'n'));
					if ((b == 'S') || (b == 's'))
					{
						opr = regime(r);
						if (opr == 1)
						{
							e[i].precoF = e[i].preco + 500;
							strcpy(e[i].tRegime, "Meia-Pens�o");
						}
						if (opr == 2)
						{
							e[i].precoF = e[i].preco + 1000;
							strcpy(e[i].tRegime, "Pens�o Completa");
						}
						printf("Regime alterado\n");
					}
					else
					{
						strcpy(e[i].tRegime, "Pequeno-Almo�o");
						printf("Regime n�o alterado\n");
						e[i].precoF = e[i].preco;
					}
				}


			}
			else if ((l == 'N') || (l == 'n'))
			{
				strcpy(e[i].tQuarto, "Quarto single");
				strcpy(e[i].tRegime, "Pequeno-Almo�o");
				printf("Pre�o=1000 euros\n");
				e[i].precoF = e[i].preco;
			}
			e[i].opp = 1;
		}

		if (opf == 2)
		{
			strcpy(e[i].pacote, "Hotel");
			int noite;
			printf("Digite o n�mero de noites\n");
			scanf("%d", &noite);
			e[i].noites = noite;
			e[i].preco = (50)*(noite);
			do
			{
				printf("Quer alterar o tipo de quarto ou regime de Pens�o?(S/N)\n");
				scanf(" %c", &l);
			
			} while ((l != 'S') && (l != 's') && (l != 'N') && (l != 'n'));
			if ((l == 'S') || (l == 's'))
			{
				do
				{
				printf("Pretende alterar o quarto?(S/N)\n");
				scanf(" %c", &a);
				} while ((a != 'S') && (a != 's') && (a != 'N') && (a != 'n'));
				if ((a == 'S') || (a == 's'))
				{
					opq = quarto(q);
					if (opq == 1)
					{
						strcpy(e[i].tQuarto, "Quarto duplo");
						e[i].precoF = 100 * noite;
					}
					if (opq == 2)
					{
						e[i].precoF = 200 * noite;
						strcpy(e[i].tQuarto, "Quarto triple");
					}
					if (opq == 3)
					{
						e[i].precoF = 500 * noite;
						strcpy(e[i].tQuarto, "Suite");
					}
					printf("Quarto alterado\n");
					do
					{
					printf("Pretende alterar o regime?(S/N)\n");
					scanf(" %c", &b);
					} while ((b != 'S') && (b != 's') && (b != 'N') && (b != 'n'));
					if ((b == 'S') || (b == 's'))
					{
						opr = regime(r);
						if (opr == 1)
						{
							e[i].precoF = e[i].preco + 500;
							strcpy(e[i].tRegime, "Meia-Pens�o");
						}
						if (opr == 2)
						{
							e[i].precoF = e[i].preco + 1000;
							strcpy(e[i].tRegime, "Pens�o Completa");
						}
						printf("Regime alterado\n");
						printf("Pre�o=%d\n", e[i].precoF);
					}
					else
					{
						strcpy(e[i].tRegime, "Pequeno-Almo�o");
						printf("Regime n�o alterado\n");
						printf("Pre�o=%d\n", e[i].precoF);

					}
				}
				else if ((a == 'N') || (a == 'n'))
				{
					printf("Quarto n�o alterado\n");
					strcpy(e[i].tQuarto, "Quarto single");
					do
					{
					printf("Pretende alterar o regime?(S/N)\n");
					scanf(" %c", &b);
					} while ((b != 'S') && (b != 's') && (b != 'N') && (b != 'n'));
					if ((b == 'S') || (b == 's'))
					{
						opr = regime(r);
						if (opr == 1)
						{
							e[i].precoF = e[i].preco + 500;
							strcpy(e[i].tRegime, "Meia-Pens�o");
						}
						if (opr == 2)
						{
							e[i].precoF = e[i].preco + 1000;
							strcpy(e[i].tRegime, "Pens�o Completa");
						}
						printf("Regime alterado\n");
						printf("Pre�o=%d\n", e[i].precoF);
					}
					else
					{
						printf("Regime n�o alterado\n");
						strcpy(e[i].tRegime, "Pequeno-Almo�o");
						e[i].precoF = e[i].preco;
					}

				}

			}
			else if ((l == 'N') || (l == 'n'))
			{
				strcpy(e[i].tQuarto, "Quarto single");
				strcpy(e[i].tRegime, "Pequeno-Almo�o");
				e[i].precoF = e[i].preco;
			}
			e[i].opp = 2;
		}
		if (opf == 3)
		{
			strcpy(e[i].pacote, "Resort");
			int noite;
			printf("Temos v�rias atividades para si,inclu�das na estadia do nosso resort,nomeadamente:\n");
			printf("Servi�os de Est�tica (spa,massagens)\n");
			printf("Atividades F�sicas (yoga,dan�a,campo de golf)\n");
			printf("Para que a sua estadia seja o mais c�moda poss�vel, por favor:\n");
			printf("Digite o n�mero de noites\n");
			scanf("%d", &noite);
			e[i].noites = noite;
			e[i].preco = (50)*(noite);
			do
			{
			printf("Quer alterar o tipo de quarto ou regime de Pens�o?(S/N)\n");
			scanf(" %c", &l);
			} while ((l != 'S') && (l != 's') && (l != 'N') && (l != 'n'));
			if ((l == 'S') || (l == 's'))
			{
				do
				{
				printf("Pretende alterar o quarto?(S/N)\n");
				scanf(" %c", &a);
				} while ((a != 'S') && (a != 's') && (a != 'N') && (a != 'n'));
				if ((a == 'S') || (a == 's'))
				{
					opq = quarto(q);
					if (opq == 1)
					{
						e[i].precoF = 100 * noite;
						strcpy(e[i].tQuarto, "Quarto duplo");
					}
					if (opq == 2)
					{
						e[i].precoF = 200 * noite;
						strcpy(e[i].tQuarto, "Quarto triple");
					}
					if (opq == 3)
					{
						e[i].precoF = 500 * noite;
						strcpy(e[i].tQuarto, "suite");
					}
					printf("Quarto alterado\n");
					do
					{
					printf("Pretende alterar o regime?(S/N)\n");
					scanf(" %c", &b);
					} while ((b != 'S') && (b != 's') && (b != 'N') && (b != 'n'));
					if ((b == 'S') || (b == 's'))
					{
						opr = regime(r);
						if (opr == 1)
						{
							e[i].precoF = e[i].preco + 500;
							strcpy(e[i].tRegime, "Meia-Pens�o");
						}
						if (opr == 2)
						{
							e[i].precoF = e[i].preco + 1000;
							strcpy(e[i].tRegime, "Pens�o Completa");
						}
						printf("Regime alterado\n");
						printf("Pre�o=%d\n", e[i].precoF);
					}
					else
					{
						printf("Regime n�o alterado\n");
						printf("Pre�o=%d\n", e[i].precoF);
						strcpy(e[i].tRegime, "Pequeno-Almo�o");
					}
				}
				else if ((a == 'N') || (a == 'n'))
				{
					printf("Quarto n�o alterado\n");
					strcpy(e[i].tQuarto, "Quarto single");
					do
					{
					printf("Pretende alterar o regime?(S/N)\n");
					scanf(" %c", &b);
					} while ((b != 'S') && (b != 's') && (b != 'N') && (b != 'n'));
					if ((b == 'S') || (b == 's'))
					{
						opr = regime(r);
						if (opr == 1)
						{
							e[i].precoF = e[i].preco + 500;
							strcpy(e[i].tRegime, "Meia Pens�o");
						}
						if (opr == 2)
						{
							e[i].precoF = e[i].preco + 1000;
							strcpy(e[i].tRegime, "Pens�o Completa");
						}
						printf("Regime alterado\n");
						printf("Pre�o2=%d\n", e[i].precoF);
					}
					else
					{
						printf("Regime n�o alterado\n");
						strcpy(e[i].tRegime, "Pequeno-Almo�o");
						e[i].precoF = e[i].preco;
					}
					e[i].precoF = e[i].preco;
				}
			}
			else if ((l == 'N') || (l == 'n'))
			{
				strcpy(e[i].tQuarto, "Quarto single");
				strcpy(e[i].tRegime, "Pequeno-Almo�o");
				e[i].precoF = e[i].preco;
			}

			e[i].opp = 3;
		}
		else if (opf == 4)
		{
			strcpy(e[i].pacote, "Radical");
			int ativ, pack, p;
			printf("A nossa empresa proporciona-lhe um dia fant�stico,cheio das mais diversas atividades\n");
			printf("Para que viva oportunidades �nicas, temos ao seu disp�r 3 packs\n");
			printf("O pre�o de cada pack inclui seguro pessoal\n");
			printf("Os Packs apenas podem ser escolhidos por grupos com minimo de 10 pessoas e no m�ximo de 20 pessoas\n");
			printf("A atividade de Paintball apenas pode ser realizada com minimo de 10 pessoas e m�ximo de 20 pessoas\n");
			printf("As restantes atividades t�m o m�ximo de 20 pessoas\n");
			printf("Por�m, se pretender realizar apenas uma das atividades, tamb�m � poss�vel\n");
			printf("Escolha uma op��o:\n");
			do
			{
				printf("1-Packs\n2-Atividades individuais\n");
				scanf("%d", &ativ);
			} while ((ativ != 1) && (ativ != 2));
			switch (ativ)
			{
			case 1:		
				printf("Apresentamos os Packs dispon�veis\n");
				printf("Pack 1- Paintball, Escalada e Tiro com Arco (25 euros/pessoa)\n");
				printf("Pack 2- Paintball e Circuito de Pontes (20 euros/pessoa)\n");
				printf("Pack 3- Escalada,Circuito de Pontes e BTT (25 euros/pessoa)\n");
				do
				{
					printf("Escolha um dos Packs(atrav�s do n�mero)\n");
					scanf("%d", &pack);
				} while ((pack != 1) && (pack != 2) && (pack != 3));
				if (pack == 1)
				{
					strcpy(e[i].tRadical, "Pack 1");
					printf("Escolheu o Pack 1\n");
					do
					{
						printf("Digite o n�mero de pessoas (minimo 10, m�ximo 20)\n");
						scanf("%d", &p);
					} while (p < 10 || p>20);
					printf("O pre�o total � de %d\n", p * 25);
					e[i].pessoas = p;
					e[i].precoF = p * 25;
				}
				if (pack == 2)
				{
					strcpy(e[i].tRadical, "Pack 2");
					printf("Escolheu o Pack 2\n");
					do
					{
						printf("Digite o n�mero de pessoas (minimo 10, m�ximo 20)\n");
						scanf("%d", &p);
					} while (p < 10 || p>20);
					printf("O pre�o total � de %d\n", p * 20);
					e[i].pessoas = p;
					e[i].precoF = p * 20;
				}
				if (pack == 3)
				{
					strcpy(e[i].tRadical, "Pack 3");
					do
					{
						printf("Digite o n�mero de pessoas (minimo 10, m�ximo 20)\n");
						scanf("%d", &p);
					} while (p < 10 || p>20);
					printf("O pre�o total � de %d\n", p * 25);
					e[i].pessoas = p;
					e[i].precoF = p * 25;
				}
				break;

			case 2: 
				int ind;
				printf("Apresentamos as atividades\n");
				do
				{
					printf("Escolha a Atividade:\n");
					printf("1-Paintball(15euros/pessoa)\n2-Escalada(5 euros/pessoa)\n3-Tiro com Arco(5 euros/pessoa)\n4-Circuito de Pontes(10 euros/pessoa)\n5-BTT(15 euros/pessoa)\n");
					printf("Escolha a Atividade:\n");
					scanf("%d", &ind);
				} while ((ind != 1) && (ind != 2) && (ind != 3) && (ind != 4) && (ind != 5));
				switch (ind)
				{
				case 1: strcpy(e[i].tRadical, "Paintball");
					do
					{
						printf("Digite o n�mero de pessoas (minimo 10, m�ximo 20)\n");
						scanf("%d", &p);
					} while (p < 10 || p>20);
					printf("O pre�o total � de %d\n", p * 15);
					e[i].pessoas = p;
					e[i].precoF = p * 15;
					break;
				case 2:
					strcpy(e[i].tRadical, "Escalada");
					do
					{
						printf("Digite o n�mero de pessoas (minimo 10, m�ximo 20)\n");
						scanf("%d", &p);
					} while (p <= 0 || p > 20);
					printf("O pre�o total � de %d\n", p * 5);
					e[i].pessoas = p;
					e[i].precoF = p * 5;
					break;
				case 3:
					strcpy(e[i].tRadical, "Tiro com Arco");
					do
					{
						printf("Digite o n�mero de pessoas (minimo 10, m�ximo 20)\n");
						scanf("%d", &p);
					} while (p <= 0 || p > 20);
					printf("O pre�o total � de %d\n", p * 5);
					e[i].pessoas = p;
					e[i].precoF = p * 5;
					break;
				case 4:
					strcpy(e[i].tRadical, "Circuito de Pontes");
					do
					{
						printf("Digite o n�mero de pessoas (minimo 10, m�ximo 20)\n");
						scanf("%d", &p);
					} while (p <= 0 || p > 20);
					printf("O pre�o total � de %d\n", p * 10);
					e[i].pessoas = p;
					e[i].precoF = p * 10;
					break;
				case 5:
					strcpy(e[i].tRadical, "BTT");
					do
					{
						printf("Digite o n�mero de pessoas (minimo 10, m�ximo 20)\n");
						scanf("%d", &p);
					} while (p <= 0 || p > 20);
					printf("O pre�o total � de %d\n", p * 15);
					e[i].pessoas = p;
					e[i].precoF = p * 15;
					break;
				}

				break;
			}

			e[i].opp = 4;
		}e[i].ocupado = 1;
		e[i].nviagem = (*codigoviagem);
		(*codigoviagem)++;
		e[i].pagamentof = e[i].precoF;

		if (opf == 1)
		{
			strcpy(e[i].estado, "Interesse");
			system("cls");
			printf("N�mero de Cliente:%d\nN�mero de viagem: %d\nPacote:%s\nQuarto:%s\nRegime:%s\nPre�o:%d\nEstado:%s\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].tQuarto, e[i].tRegime, e[i].precoF, e[i].estado);
			printf("\n\nPara a sua reserva ser confirmada, ter� que efetuar o pagamento parcial da viagem, no m�nimo 50\n");
			printf("\nPor favor, diriga-se ao menu principal, op��o de pagamentos e transfira a quantia desejada.\n\n");

		}
		if (opf == 2 || opf == 3)
		{
			strcpy(e[i].estado, "Interesse");
			system("cls");
			printf("N�mero de Cliente:%d\nC�digo da Viagem: %d\nPacote:%s\nQuarto:%s\nRegime:%s\nNoites:%d\nPre�o:%d\nEstado:%s\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].tQuarto, e[i].tRegime, e[i].noites, e[i].precoF, e[i].estado);
		}
		else if (opf == 4)
		{
			strcpy(e[i].estado, "Interesse");
			system("cls");
			printf("N�mero de Cliente:%d\nC�digo da Viagem: %d\nPacote:%s\nPessoas:%d\nAtividades:%s\nPre�o:%d\nEstado:%s\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].pessoas, e[i].tRadical, e[i].precoF, e[i].estado);
		}

	}
}

void guardaContratos(FINAL*e, int n)   // guarda os contratos no ficheiro
{
	FILE *fi;
	fi = fopen("contratos.dat", "w");
	fwrite(e, sizeof(FINAL), n, fi);
	fclose(fi);
}

void mostrarContratos( FINAL*e , int n)  //mostra todos os contratos no ecr�
{

	int i, j,opq, opr;
	char l, a, b;
	char pacote[20], estado[20];
	i = 0;
	for (int i = 0; i < n; i++) {
		if (e[i].ocupado == 1)
		{
			if (e[i].opp == 1)
			{
				strcpy(estado, "Interesse");
				system("cls");
				printf("\nN�mero de Cliente:%d\nN�mero de viagem: %d\nPacote:%s\nQuarto:%s\nRegime:%s\nPre�o:%d\nEstado:%s\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].tQuarto, e[i].tRegime, e[i].precoF, e[i].estado);
			}
			if (e[i].opp == 2 || e[i].opp == 3)
			{
				strcpy(estado, "Interesse");
				system("cls");
				printf("\nN�mero de Cliente:%d\nC�digo da Viagem: %d\nPacote:%s\nQuarto:%s\nRegime:%s\nNoites:%d\nPre�o:%d\nEstado:%s\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].tQuarto, e[i].tRegime, e[i].noites, e[i].precoF, e[i].estado);
			}
			else if (e[i].opp == 4)
			{
				strcpy(estado, "Interesse");
				system("cls");
				printf("\nN�mero de Cliente:%d\nC�digo da Viagem: %d\nPacote:%s\nPessoas:%d\nAtividades:%s\nPre�o: %d\nEstado:%s\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].pessoas, e[i].tRadical, e[i].precoF, e[i].estado);
			}
			system("pause");

		}

	}
}

void mostrarContrato(FINAL*e, CLIENTE*p, int n)  //mostra apenas o contrato do cliente
{

	int i, j,opq, opr, num,numero;
	char l, a, b;
	char pacote[20], estado[20];
	i = 0;
	printf("\nDigite o numero de cliente: ");
	scanf("%d", &num);
	
		for (i = 0; i < n; i++)
		{
			if ((e[i].cliente == num) && (e[i].ocupado == 1))
			{
				if (e[i].opp == 1)
				{
					strcpy(estado, "Interesse");
					system("cls");
					printf("\n\nN�mero de Cliente:%d\nN�mero de viagem: %d\nPacote:%s\nQuarto:%s\nRegime:%s\nPre�o:%d\nEstado:%s\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].tQuarto, e[i].tRegime, e[i].precoF, e[i].estado);
				}
				if (e[i].opp == 2 || e[i].opp == 3)
				{
					strcpy(estado, "Interesse");
					system("cls");
					printf("\nN�mero de Cliente:%d\nC�digo da Viagem: %d\nPacote:%s\nQuarto:%s\nRegime:%s\nNoites:%d\nPre�o:%d\nEstado:%s\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].tQuarto, e[i].tRegime, e[i].noites, e[i].precoF, e[i].estado);
				}
				else if (e[i].opp == 4)
				{
					strcpy(estado, "Interesse");
					system("cls");
					printf("\nN�mero de Cliente:%d\nC�digo da Viagem: %d\nPacote:%s\nPessoas:%d\nAtividades:%s\nEstado:%s\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].pessoas, e[i].tRadical, e[i].estado);
				}
				system("pause");
			}
		}

	
}
void pagamentos(REGIME *r, QUARTO *q, FERIAS *f, RADICAL *ra, FINAL*e, CLIENTE*p, int n)
{
	int nv, i;
	float pagamento, preco;
	pagamento = 0;
	printf("Digite o c�digo da viagem: ");
	scanf("%d", &nv);
	
	for (i = 0; i < n; i++)
	{
		if ((nv == e[i].nviagem) && (e[i].ocupado == 1))
		{
			if (e[i].opp == 1)
			{
				preco = e[i].pagamentof;
				printf("\nDados da viagem: \n");
				if (preco == 0)
				{
					printf("N�mero de Cliente:%d\nN�mero de viagem: %d\nPacote:%s\nQuarto:%s\nRegime:%s\nPre�o:%d\nJ� est� tudo pago\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].tQuarto, e[i].tRegime, e[i].precoF);
					break;
				}
				else
					printf("N�mero de Cliente:%d\nN�mero de viagem: %d\nPacote:%s\nQuarto:%s\nRegime:%s\nPre�o:%d\nFalta pagar %.2f\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].tQuarto, e[i].tRegime, e[i].precoF, e[i].pagamentof);

				do
				{
					printf("\n\nQuanto pretende pagar? ");
					scanf("%f", &pagamento);
				} while ((pagamento > preco) || (pagamento < 50));
				preco = preco - pagamento;
				e[i].pagamentof = preco;
				strcpy(e[i].estado, "Contratado");
				if (preco != 0)
					printf("\n\nAinda falta pagar %.2f, pode pagar em presta��es suavizadas at� uma semana antes da viagem.", preco);
				else
				{
					printf("\n\nA viagem est� paga na totalidade.\nObrigado");
					strcpy(e[i].estado, "Pago");
				}
				
			}
			if (e[i].opp == 2 || e[i].opp == 3)
			{
				preco = e[i].pagamentof;
				printf("\nDados da viagem: \n");
				if (preco == 0)
				{
					printf("N�mero de Cliente:%d\nC�digo da Viagem: %d\nPacote:%s\nQuarto:%s\nRegime:%s\nNoites:%d\nPre�o:%d\nEstado:%s\nJ� est� tudo pago\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].tQuarto, e[i].tRegime, e[i].noites, e[i].precoF, e[i].estado);
					break;
				}
				else 
					printf("N�mero de Cliente:%d\nC�digo da Viagem: %d\nPacote:%s\nQuarto:%s\nRegime:%s\nNoites:%d\nPre�o:%d\nEstado:%s\nFalta pagar: %.2f\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].tQuarto, e[i].tRegime, e[i].noites, e[i].precoF, e[i].estado, e[i].pagamentof);

				do
				{
					printf("\n\nQuanto pretende pagar? ");
					scanf("%f", &pagamento);
				} while ((pagamento > preco) || (pagamento < 50));
				preco = preco - pagamento;
				e[i].pagamentof = preco;
				strcpy(e[i].estado, "Contratado");
				if (preco != 0)
					printf("\n\nAinda falta pagar %.2f, pode pagar em presta��es suavizadas at� uma semana antes da viagem.", preco);
				else
				{
					printf("\n\nA viagem est� paga na totalidade.\nObrigado");
					strcpy(e[i].estado, "Pago");
				}
			
			}
			else if (e[i].opp == 4)
			{
				preco = e[i].pagamentof;
				printf("\nDados da viagem: \n");
				if (preco == 0)
				{
					printf("N�mero de Cliente:%d\nC�digo da Viagem: %d\nPacote:%s\nPessoas:%d\nAtividades:%s\nEstado:%s\nJ� est� tudo pago\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].pessoas, e[i].tRadical, e[i].estado);
					break;
				}
				else 
					printf("N�mero de Cliente:%d\nC�digo da Viagem: %d\nPacote:%s\nPessoas:%d\nAtividades:%s\nEstado:%s\nFalta pagar: %.2f\n", e[i].cliente, e[i].nviagem, e[i].pacote, e[i].pessoas, e[i].tRadical, e[i].estado, e[i].pagamentof);

				do
				{
					printf("\n\nQuanto pretende pagar? ");
					scanf("%f", &pagamento);
				} while ((pagamento > preco) || (pagamento < 50));
				preco = preco - pagamento;
				e[i].pagamentof = preco;
				strcpy(e[i].estado, "Contratado");
				if (preco != 0)
					printf("\n\nAinda falta pagar %.2f, pode pagar em presta��es suavizadas at� uma semana antes da viagem.", preco);
				else
				{
					printf("\n\nA viagem est� paga na totalidade.\nObrigado");
					strcpy(e[i].estado, "Pago");
				}
				
			}
			printf("\n");
		}
	}
}
void contratoElevado(FINAL *e, CLIENTE *p, int n)
{
	int i, num, elevado;

	elevado = 0;
	num = 0;

	for (i = 0; i < n; i++)
	{
		if (e[i].precoF > elevado)
		{
			elevado = e[i].precoF;
			num = e[i].nviagem;
		}
	}
	printf("\n\nO contrato mais elevado � o contrato n� %d\npre�o: %d\n", num, elevado);
}

void inquerito(INQUERITO * inq,FINAL*e, int n)
{
	char l;
	int  j,i,cod;
	j = 0;
	printf("Para verificar a qualidade dos nossos servicos e a satisfacao dos clientes, pedimos que nos de a sua opiniao respondendo a este breve questionario:\n\n");
	printf("O inqu�rito ser� an�nimo\n\n");

	while ((inq[j].ocupado != 0) && (j < n))
	{
		j++;
	}
	printf("Digite o c�digo da viagem: \n\n");
	scanf("%d", &cod);
	for (i = 0; i < n; i++)
	{
		if (inq[j].ocupado == 0)
		{
			if ((e[i].nviagem==cod) && (e[i].ocupado == 1))
			{
				if (strcmp(e[i].estado, "Pago") == 0)
				{
					printf("Para cada uma das perguntas responda com 1-Excelente/2Muito Bom/3-Bom/4-Razoavel/5-Mau\n\n");

					printf("Como classifica o nosso atendimento em termos de:\n\n");

					do
					{
						printf("1-Simpatia e cortesia: ");
						scanf("%d", &inq[i].n1);
					} while ((inq[i].n1 < 1) || (inq[i].n1 > 5));
					do
					{
						printf("2-Profissionalismo: ");
						scanf("%d", &inq[i].n2);

					} while ((inq[i].n2 < 1) || (inq[i].n2 > 5));
					do
					{

						printf("3-Compreensao das suas necessidades: ");
						scanf("%d", &inq[i].n3);

					} while ((inq[i].n3 < 1) || (inq[i].n3 > 5));
					do
					{
						printf("4-Conhecimento dos servi�os oferecidos por parte do agente: ");
						scanf("%d", &inq[i].n4);
					} while ((inq[i].n4 < 1) || (inq[i].n4 > 5));

					printf("\n");
					printf("Como classifica a qualidade de:\n\n ");
					do
					{
						printf("1-Instala��es em geral: ");
						scanf("%d", &inq[i].n5);
					} while ((inq[i].n5 < 1) || (inq[i].n5 > 5));

					do
					{
						printf("2-Qualidade do seu quarto: ");
						scanf("%d", &inq[i].n6);
					} while ((inq[i].n6 < 1) || (inq[i].n6 > 5));

					do
					{
						printf("3-Servi�os prestados e atitude dos funcionarios do hotel: ");
						scanf("%d", &inq[i].n7);
					} while ((inq[i].n7 < 1) || (inq[i].n7 > 5));

					do
					{
						printf("4-Higiene e limpeza do hotel: ");
						scanf("%d", &inq[i].n8);
					} while ((inq[i].n8 < 1) || (inq[i].n8 > 5));

					do
					{
						printf("5-Qualidade de entretenimento do hotel: ");
						scanf("%d", &inq[i].n9);
					} while ((inq[i].n9 < 1) || (inq[i].n9 > 5));


					printf("Para cada uma das perguntas responda com 1-Muito/2-Sim/3-Mais ou menos/4-Pouco/5-Muito Pouco\n\n ");

					do
					{
						printf("1-A sua viagem de f�rias correspondeu �s expectativas?\n ");
						scanf("%d", &inq[i].n10);
					} while ((inq[i].n10 < 1) || (inq[i].n10 > 5));
					do
					{
						printf("2-Est� satisfeito com o pacote oferecido?\n ");
						scanf("%d", &inq[i].n11);
					} while ((inq[i].n11 < 1) || (inq[i].n11 > 5));
					do
					{
						printf("3-Utilizaria a nossa ag�ncia novamente no futuro?\n ");
						scanf("%d", &inq[i].n12);
					} while ((inq[i].n12 < 1) || (inq[i].n12 > 5));

					printf("Obrigado!!!");
					strcpy(e[i].estado, "terminado");
					inq[i].ocupado = 1;
				}
				else
					inq[i].ocupado = 0;
			}
			
			
		}
		
	}
}




//-------CLIENTES-------

void iniciarCliente(CLIENTE*p, int n)   //inicializa os clientes
{
	int i;
	for (i = 0; i < n; i++)
	{
		p[i].ocupado = 0;
	}
}

void lerClientes(CLIENTE *p, int n)  // l� os clientes que est�o no ficheiro
{
	FILE *f;
	f = fopen("clientes.dat", "rb");
	while (!feof(f))
	{
		fread(p, sizeof(CLIENTE), 1, f);
		p++;
	}
	fclose(f);
}

void registarcliente(CLIENTE *p, int n, int *codigocliente)  //regista clientes
{
	int i;
	i = 0;
	char op;
	int validacao;
	int validarcontacto;
	char pref, pac;
	int verificacao;
	verificacao = 1;
	while ((p[i].ocupado != 0) && (i < n))
	{
		i++;
	}
	if (i < n)
	{

		fseek(stdin, 0, 2);
		printf("\nNome completo: ");
		gets_s(p[i].nome);
		fseek(stdin, 0, 2);

		int nif;
		do {
			printf("\nNif: ");
			scanf("%d", &nif);
		} while (nif <= 99999999 || nif > 999999999);   // valida��o nif
		for (int j = 0; j < n; j++)
		{
			if (p[j].ocupado == 1)
			{
				if (nif == p[j].nif)   // verifica��o de exist�ncia de nif no ficheiro
				{
					printf("\nO nif introduzido j� existe!\n");
					printf("\nCliente numero: %d\nNome: %s\nNif: %d\nMorada: %s\nContacto: %d\n\n", p[j].ncliente, p[j].nome, p[j].nif, p[j].morada, p[j].contacto);
					verificacao = 0;
					break;
				}
			}
		}
		if (verificacao == 1)
		{
			p[i].nif = nif;
			fseek(stdin, 0, 2);
			printf("\nMorada: ");
			gets_s(p[i].morada);
			do
			{
				printf("\nContacto: ");
				scanf("%d", &p[i].contacto);  // valida��o do contacto
				if ((p[i].contacto >= 910000000) && (p[i].contacto < 939999999))
					validarcontacto = 1;
				else
					if ((p[i].contacto >= 960000000) && (p[i].contacto < 969999999))
						validarcontacto = 1;
					else
						if ((p[i].contacto >= 210000000) && (p[i].contacto <= 299999999))
							validarcontacto = 1;
						else
						{
							printf("\nContacto inv�lido, por favor digite um contacto correto.\n");
							validarcontacto = 0;
						}
			} while (validarcontacto == 0);
			p[i].ocupado = 1;
			p[i].ncliente = *codigocliente;
			(*codigocliente)++;
		}
	}
	else
		printf("\nLista de clientes cheia\n");
}

void guardaClientes(CLIENTE *p, int n)   // guarda os clientes no ficheiro
{
	FILE *f;
	f = fopen("clientes.dat", "w");
	fwrite(p, sizeof(CLIENTE), n, f);
	fclose(f);
}

void mostrarClientes(CLIENTE *p, int n)  //mostra todos clientes no ecr�
{
	for (int i = 0; i < n; i++)
	{
		if (p[i].ocupado == 1)
		{
			printf("\nN�mero de Cliente: %d\nNome: %s\nNIF: %d\nMorada: %s\nContacto: %d\n", p[i].ncliente, p[i].nome, p[i].nif, p[i].morada, p[i].contacto);
			system("pause");
			system("cls");
		}
	}

}

void mostrarCliente(CLIENTE *p, int n)  //mostra apenas os dados do cliente no ecr�
{
	int j;
	char nome[50];

	do
	{
		system("cls");
		printf("\nDigite o seu nome completo: ");
		(gets_s(nome));
	} while (strcmp(nome, "") == 0);
	
	for (int j = 0; j < n; j++)
	{
		if (strcmp(nome,p[j].nome)==0)
		{
			printf("\nN�mero de Cliente: %d\nNome: %s\nNif: %d\nMorada: %s\nContacto: %d\n\n", p[j].ncliente, p[j].nome, p[j].nif, p[j].morada, p[j].contacto);

		}
	}
}

void removerCliente(CLIENTE *p, int n)
{
	int ncliente, i;
	printf("\nDigite o n�mero de cliente: ");
	scanf("%d", &ncliente);
	for (i = 0; i < n; i++)
	{
		if (p[i].ocupado == 0)
			printf("O n�mero de cliente n�o � v�lido\n");
		if (p[i].ncliente == ncliente)
		{

			p[i].ocupado = 0;
			printf("\nRegisto eliminado\n");
			break;
		}

	}
}



void alterarDados(CLIENTE *p, int n)
{
	int nc, i, verificacao, validarcontacto, op;
	verificacao = 1;
	printf("Digite o n�mero de cliente ");
	scanf("%d", &nc);
	for (i = 0; i < n; i++)
	{
		if ((nc == p[i].ncliente) && (p[i].ocupado == 1))
		{

			printf("\nOs seus dados s�o: ");
			printf("\nNome: %s\nNIF: %d\nMorada: %s\nContacto: %d\n", p[i].nome, p[i].nif, p[i].morada, p[i].contacto);
			printf("Digite a op��o que pretende alterar\n\n1-Nome;\n2-NIF;\n3-Morada;\n4-Contacto;\n ");
			scanf("%d", &op);
			switch (op)
			{
			case 1:

				fseek(stdin, 0, 2);
				printf("\nNome completo: ");
				gets_s(p[i].nome);
				break;
			case 2:
				int nif;
				do {
					printf("\nNIF: ");
					scanf("%d", &nif);
				} while (nif <= 99999999 || nif > 999999999);
				for (int j = 0; j < n; j++)
				{
					if (nif == p[j].nif)
					{
						printf("O NIF introduzido j� existe!");
						printf("\nN�mero de Cliente: %d\nNome: %s\nNif: %d\nMorada: %s\nContacto: %d\n\n", p[j].ncliente, p[j].nome, p[j].nif, p[j].morada, p[j].contacto);
						verificacao = 0;
						break;
					}
				}
				if (verificacao == 1)
					p[i].nif = nif;
				break;
			case 3:
				fseek(stdin, 0, 2);
				printf("\nMorada: ");
				gets_s(p[i].morada);
				break;
			case 4:
				do
				{
					printf("\nContacto: ");
					scanf("%d", &p[i].contacto);
					if ((p[i].contacto >= 910000000) && (p[i].contacto < 939999999))
						validarcontacto = 1;
					else
						if ((p[i].contacto >= 960000000) && (p[i].contacto < 969999999))
							validarcontacto = 1;
						else
							if ((p[i].contacto >= 210000000) && (p[i].contacto <= 299999999))
								validarcontacto = 1;
							else
							{
								printf("\nContacto inv�lido, por favor digite um contacto v�lido\n");
								validarcontacto = 0;
							}
				} while (validarcontacto == 0); // vai verificar se o n� de telemovel � v�lido
				break;
			default:
				break;
			}
		}

	}
}
void criarpacotesfich(PACOTE *pc)
{
	strcpy(pc[0].escreve, "Bem vindo � nossa ag�ncia de viagens.\nTodos os pacotes incluem um quarto single e pequeno almo�o.\nOutro tipo de quarto ou outro regime de pens�o ter� um valor acrescido\n\n\n");
	strcpy(pc[1].escreve, "Pre�o base dos pacotes:\n\n\n-Cruzeiro - 1000;\ncom altera��o de quarto: \nduplo ->  +350\ntriplo -> +700\nsuite -> +1050\n\ncom altera��o de regime:\nmeia pen��o -> +500\npens�o completa -> +1000\n\n");
	strcpy(pc[2].escreve, "-Hotel e resort - 50 por noite;\ncom altera��o de quarto: \nduplo ->  +100 por noite\ntriplo -> +200 por noite\nsuite -> +500 por noite\ncom altera��o de regime:\nmeia pen��o -> +500\npens�o completa -> +1000\n\n");
	strcpy(pc[3].escreve, "-Radical:\npack 1: 25 por pessoa;\npack 2: 20 por pessoa;\npack 3: 25 por pessoa;\n\nAtividades:\npaintball: 15;\nEscalada:5\nTiro com arco:5\nCircuito de pontes:10\nBTT:15\n\n");
}

void mostrarpacotes(PACOTE *pc, int n)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%s", pc[i].escreve);
		system("pause");
		system("cls");
	}
}

void iniciarPacote(PACOTE *pc, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		pc[i].ocupado = 0;
	}
}

void lerPacote(PACOTE *pc, int n)  // l� os contratos que est�o no ficheiro
{
	FILE *fpac;
	fpac = fopen("pacotes.dat", "r");
	while (!feof(fpac))
	{
		fread(pc, sizeof(PACOTE), 1, fpac);
		pc++;
	}
	fclose(fpac);
}

void guardaPacote(PACOTE *pc, int n)   // guarda os clientes no ficheiro
{
	FILE *fpac;
	fpac = fopen("pacotes.dat", "w");
	fwrite(pc, sizeof(PACOTE), n, fpac);
	fclose(fpac);
}
void main()
{
	int i, op, op2, tipo;
	int codigocliente, codigoviagem;
	char passe[15];
	tipo = 0;
	setlocale(LC_CTYPE, "portuguese");
	CLIENTE *cl;
	cl = (CLIENTE *)malloc(sizeof(CLIENTE)*MAX);
	FERIAS *v;
	QUARTO *q;
	REGIME *r;
	RADICAL *ra;
	FINAL *en;
	PACOTE *paco;
	paco = (PACOTE *)malloc(sizeof(PACOTE)*MAX);
	en = (FINAL *)malloc(sizeof(FINAL)*MAX);
	v = (FERIAS *)malloc(sizeof(FERIAS)*MAX);
	q = (QUARTO *)malloc(sizeof(QUARTO)*MAX);
	r = (REGIME *)malloc(sizeof(REGIME)*MAX);
	ra = (RADICAL *)malloc(sizeof(RADICAL)*MAX);
	TERMINADO *t;
	t = (TERMINADO *)malloc(sizeof(TERMINADO)*MAX);
	INQUERITO *in;
	in = (INQUERITO *)malloc(sizeof(INQUERITO)*MAX);
	
	//FICHEIRO PARA PACOTES
	FILE *fpac;
	fpac = fopen("pacotes.dat", "r");
	if (!fpac)  // se der erro ao abrir o ficheiro
	{
		iniciarPacote(paco, MAX);
		criarpacotesfich(paco);
		guardaPacote(paco, MAX);
	}
	else
	{
		fclose(fpac);
		lerPacote(paco, MAX);
	}

	//FIHEIRO DOS CONTRATOS
	FILE *fi;
	fi = fopen("contratos.dat", "r");
	if (!fi)  // se der erro ao abrir o ficheiro
	{
		iniciarContratos(en, MAX);
		codigoviagem = 1;
	}
	else
	{
		fclose(fi);
		lerContratos(en, MAX);
		codigoviagem = en[0].nviagem;
		for (i = 1; i < MAX; i++)
		{
			if (en[i].nviagem > codigoviagem)
				codigoviagem = en[i].nviagem; 
		}
		codigoviagem++;
	}
	//FICHEIRO DOS CLIENTES
	FILE *f;
	f = fopen("clientes.dat", "r");
	if (!f)  // se der erro ao abrir o ficheiro
	{
		iniciarCliente(cl, MAX);
		codigocliente = 1;
	}
	else
	{
		fclose(f);
		lerClientes(cl, MAX);
		codigocliente = cl[0].ncliente;
		for (i = 1; i < MAX; i++)
		{
			if (cl[i].ncliente > codigocliente)
				codigocliente = cl[i].ncliente;
		}
		codigocliente++;
	}
	//FICHEIRO PARA CONTRATOS REMOVIDOS
	FILE *fc;
	fc = fopen("contratos terminados.dat", "r");
	if (!fc)
	{
		iniciarcterminados(t, MAX);
	}
	else
	{
		lerCterminados(t, MAX);
	}

	//FICHEIRO PARA INQU�RITOS
	FILE *finq;
	finq = fopen("inqu�ritos.dat", "r");
	if (!finq)
	{
		iniciarInquerito(in, MAX);
	}
	else
	{
		lerInquerito(in, MAX);
	}
	//MENU
	do
	{
		printf("------MENU------\n");
		printf("1-ADMIN\n2-CLIENTE\n");
		scanf("%d", &op2);

		switch (op2)
		{
		case 1:	printf("ADMIN\nDigite a password:\n");
			scanf("%s", passe);

			if (strcmp(passe, "1a2b") != 0)
			{
				printf("N�O AUTORIZADO\n");
				
			}
			else
			{
				printf("\nBEM VINDO ADMIN\n");
				tipo = 1;
			}
			break;
		case 2: printf("BEM VINDO CLIENTE\n");
			tipo = 2;
			break;

		default:printf("\nOpcao invalida!\n\n");
			break;

		}
	} while ((op2 != 1) && (op2 != 2));
	if (tipo == 1)
	{
		system("cls");
		do					//menu de administrador
		{
			printf("\n\n\tMENU\n\n");
			printf("1 - Registar cliente\n");
			printf("2 - Guardar registo de cliente\n");
			printf("3 - ver dados dos clientes\n"); // apenas admin
			printf("4 - Remover clientes\n");  // apenas admin
			printf("5 - Alterar dados de cliente\n");
			printf("6 - Ver pacotes de f�rias\n");
			printf("7 - Registar Reserva\n");
			printf("8 - Ver reservas\n"); // apenas admin
			printf("9 - guardar reservas\n");
			printf("10 - Pagamentos\n");
			printf("11 - Ver contrato mais valioso\n"); // apenas admin
			printf("12 - Inqu�rito\n");
			printf("13 - Mostrar inqu�ritos\n"); // apenas admin
			printf("14 - mostrar contratos terminados\n"); // apenas admin
			printf("15 - Sair\n");
			printf("\nDigite opcao: ");
			scanf("%d", &op);
			switch (op)
			{
			case 1:        
				system("cls");
				registarcliente(cl, MAX, &codigocliente);
			break;
			case 2:			
				system("cls");
				guardaClientes(cl, MAX);
				break;
			case 3:			 
				system("cls");
				mostrarClientes(cl, MAX);
				break;
			case 4:       

				system("cls");
				removerCliente(cl, MAX);
				break;
			case 5:
				system("cls");
				alterarDados(cl, MAX);
				break;
			case 6:
			
				system("cls");
				mostrarpacotes(paco,MAX);
				break;
			
			case 7:
				system("cls");
				escolhaComp(r, q, v, ra, en, cl, MAX, &codigoviagem);
				break;
			case 8:
				system("cls");
				mostrarContratos(en,MAX);
				break;
			case 9:
				system("cls");
				guardaContratos(en, MAX);
				break;
			case 10:
				system("cls");
				pagamentos(r, q, v, ra, en, cl, MAX);
				break;
			case 11:
				system("cls");
				contratoElevado(en, cl, MAX);
				break;
			
			case 12:
				system("cls");
				inquerito(in,en,  MAX);
				guardaInqueritos(in, en, MAX);
				break;
			case 13:
			
				system("cls");
				mostrarInqu�rito(in, en, MAX);
				break;
			
			case 14:
				system("cls");
				removerCt(t, en, MAX);
				guardaClientesterminado(t, en, MAX);
				break;
			case 15:
				system("cls");
				printf("\nAdeus\n");
				guardaClientes(cl, MAX);
				guardaContratos(en, MAX);
				break;
			default:printf("\nOpcao invalida!\n\n");
				break;
			}
			system("pause");
			system("cls");
		} while (op != 15);
	}
	else
		if (tipo == 2)
		{
			system("cls");
			do						//menu de cliente
			{
				printf("\n\n\tMENU\n\n");
				printf("1 - Registar cliente\n");
				printf("2 - Guardar registo de cliente\n");
				printf("3 - ver dados do cliente\n");
				printf("4 - Alterar dados de cliente\n");
				printf("5 - Ver pacotes de f�rias\n");
				printf("6 - Registar Reserva\n");
				printf("7 - guardar reservas\n");
				printf("8 - Ver reservas\n");
				printf("9 - Pagamentos\n");
				printf("10 - Inqu�rito\n");
				printf("11 - Sair\n");
				printf("\nDigite opcao: ");
				scanf("%d", &op);
				switch (op)
				{
				case 1:         
					system("cls");
					registarcliente(cl, MAX, &codigocliente);
					break;
				case 2:
					system("cls");
					guardaClientes(cl, MAX);
					break;
				case 3:
					system("cls");
					mostrarCliente(cl, MAX);
					break;
				case 4:
					system("cls");
					alterarDados(cl, MAX);
					break;
				case 5:
					system("cls");
					mostrarpacotes(paco, MAX);
					break;
				case 6:
					system("cls");
					escolhaComp(r, q, v, ra, en, cl, MAX, &codigoviagem);
					break;
				case 7:
					system("cls");
					guardaContratos(en, MAX);
					break;
				case 8:
					system("cls");
					mostrarContrato(en, cl, MAX);
					break;
				case 9:
					system("cls");
					pagamentos(r, q, v, ra, en, cl, MAX);
					break;
				case 10:
					system("cls");
					inquerito(in,en, MAX);
					guardaInqueritos(in, en, MAX);
					break;
			
				case 11:
					system("cls");
					printf("\nAdeus\n");
					guardaClientes(cl, MAX);
					guardaContratos(en, MAX);
					break;
				default:printf("\nOpcao invalida!\n\n"); break;
				}
				system("pause");
				system("cls");
			} while (op != 11);
		}
}