/*
TRABALHO DE ALGORITMOS e ESTRUTURA DE DADOS
SISTEMA DE BIBLIOTECA
AUTOR: Thiago Silva.
DATA: 25/02/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Structs
struct Area{
	char area[40];
};

struct Livros{
	int isbn, area, ano, qtdc, qtdemp, empac; //num do livro; área (números); ano; qtd de cópias; qtd emprestada; empréstimo acumulado.
	char title[50], editora[50], autor[50]; //título; editora; autor.
};

//Função inicial
void cadArea (struct Area v[]){ //cadastro de cópias; cópias de 0 a 9
	int i;
	printf("Por favor, cadastre 10 areas");
	for(i=0; i<10; i++){
		printf("\nCadastre a area %d: ", i);
		fgets(v[i].area,39,stdin);
		fflush(stdin);
	}
	system ("cls");
}

//Funções

//Exibir as cópias
void exibirArea (struct Area v[]){
	int i;
	for(i=0; i<10; i++){
		printf("\nArea: %s\n\tNum: %d", v[i].area, i);
		printf("\n");
	}
}

//Inserir um Livro | struct Livros para as informações e struct Area para confirmação das cópias.
void insLivro (struct Livros v[], struct Area k[], int *nLivros){
	int aux=0, x=0;
	
	printf("Cadastro de Livro\n\n");
	printf("\nCadastre o isbn do livro: ");
	scanf("%d", &v[*nLivros].isbn);
	//fflush(stdin) para limpar o buffer, principalmente usando fgets e não ir alguma string para outra leitura.
	//Estaremos adotando fflush(stdin) em toda leitura de string para evitar qualquer problema
	fflush(stdin);
	
	printf("\nCadastre o Titulo do livro: ");
	fgets(v[*nLivros].title,49,stdin);
	fflush(stdin);
	
	printf("\nCadastre a Editora do livro: ");
	fgets(v[*nLivros].editora,49,stdin);
	fflush(stdin);
	
	printf("\nCadastre o Autor do livro: ");
	fgets(v[*nLivros].autor,49,stdin);
	fflush(stdin);
	
	//Loop para a confirmação da área.
	while(x==0){
		printf("\nCadastre a area (numero da area): ");
		scanf("%d", &v[*nLivros].area);
		fflush(stdin);
		
		aux = v[*nLivros].area;
		printf("\n\tArea: %s", k[aux].area);
		printf("\n\tDeseja confirmar esta area? (0 = nao | 1 = sim) ");
		scanf("%d", &x);
	}
	
	printf("\nCadastre o ano do livro: ");
	scanf("%d", &v[*nLivros].ano);
	fflush(stdin);
	
	printf("\nQuantidade de Copias: ");
	scanf("%d", &v[*nLivros].qtdc);
	fflush(stdin);
	
	//Set qtd emprestada e empréstimo acumulado em 0.
	v[*nLivros].qtdemp = 0;
	v[*nLivros].empac = 0;
	++*nLivros;
	system ("cls");
}

//Inserir vários livros
void insVLivros(struct Livros v[], struct Area k[], int *nLivros){
	//x para controlar o loop e nLivros para ver em qual livro está
	int exec = 1;

	while(exec == 1){
		printf("\nLivro numero: %d", *nLivros+1);
		printf("\n");
		insLivro(v,k, nLivros);
		printf("----------------------------------------------");
		printf("\n\tDeseja continuar? (0 = nao | 1 = sim)\n ");
		scanf("%d", &exec);
	}
	system ("cls");
}

//Exibir a relação de livros
void relLivros(struct Livros v[], struct Area k[], int *nLivros){
	int i, aux=0;
	if(*nLivros != 0){
		printf("\tRelacao de livros:");
		for(i = 0; i < *nLivros; i++){
		aux = v[i].area;
		
		printf("\n--Informacoes do livro--");
		printf("\n\tISBN: %d\n\tTITULO: %s", v[i].isbn, v[i].title);
		printf("\n\tAREA: %d - %s\n\tANO: %d", v[i].area, k[aux].area, v[i].ano);
		printf("\n\tQTD DE COPIAS: %d\n\tQTD EMPRESTADA: %d\n\t", v[i].qtdc, v[i].qtdemp);
		printf("\n------------------------------");
		}
		printf("\nQuantidade de livros: %d", *nLivros);
		printf("\n------------------------------\n");
	}
}

//Exibir os dados de um livro por isbn
void dataisbn(struct Livros v[], struct Area k[], int *nLivros){
	//inteiro x = var local para isbn | aux para a área | found para indicar se encontrou
	int i, x, aux=0, found=0;
	printf("Informe o isbn do livro desejado: ");
	scanf("%d", &x);
	fflush(stdin);
	
	for(i=0; i<*nLivros; i++){
		if(v[i].isbn == x){
			aux = v[i].area;
			printf("\n--Informacoes do livro--");
			printf("\n\tISBN: %d\n\tTITULO: %s\n\tEDITORA: %s\t\tAUTOR(A): %s", v[i].isbn, v[i].title, v[i].editora, v[i].autor);
			printf("\n\tAREA: %d - %s\n\tANO: %d", v[i].area, k[aux].area, v[i].ano);
			printf("\n\tQTD DE COPIAS: %d\n\tQTD EMPRESTADA: %d\n\t\tEMPRESTIMO ACUMULADO: %d", v[i].qtdc, v[i].qtdemp, v[i].empac);
			printf("\n------------------------------");
			//indicador se encontrou ou não.
			found = 1;
			//sair do loop no primeiro que achar
			i=100;
		}
	}
	if(found == 0){
		printf("\nLivro nao encontrado.");
	}	
}

//Exibir os dados pelo título
void datatitle(struct Livros v[], struct Area k[], int *nLivros){
	//char str para armazenar o titulo | aux para a área | found para indicar se encontrou | x resultado strcmp
	int i, aux=0, found=0, x;
	char str[50];
	printf("Informe o titulo do livro desejado: ");
	fgets(str,49,stdin);
	fflush(stdin);
	
	for(i=0; i < *nLivros; i++){
		x = strcmp(str, v[i].title);
		if(x == 0){
			aux = v[i].area;
			printf("\n--Informacoes do livro--");
			printf("\n\tISBN: %d\n\tTITULO: %s\n\tEDITORA: %s\t\tAUTOR(A): %s", v[i].isbn, v[i].title, v[i].editora, v[i].autor);
			printf("\n\tAREA: %d - %s\n\tANO: %d", v[i].area, k[aux].area, v[i].ano);
			printf("\n\tQTD DE COPIAS: %d\n\tQTD EMPRESTADA: %d\n\t\tEMPRESTIMO ACUMULADO: %d", v[i].qtdc, v[i].qtdemp, v[i].empac);
			printf("\n------------------------------");
			//indicador se encontrou ou não.
			found = 1;
			//sair do loop no primeiro que achar
			i=100;
		}
	}
	if(found == 0){
		printf("\nLivro nao encontrado.");
	}
}

//Buscar livros sabendo inicias do titulo
void busctitle(struct Livros v[], struct Area k[], int *nLivros){
	int i, x, aux=0, found = 0;
	
	char str[50];
	printf("Buscar livro pelo titulo: ");
	fgets(str,49,stdin);
	fflush(stdin);
	//armazena o tamanho da string para futura comparação
	x = strlen(str);
	if(*nLivros != 0){
		for(i = 0; i < *nLivros; i++){
			aux = v[i].area;
			//strncmp verifica se uma string é igual a outra, analizando o mesmo tamanho
			if(strncmp(v[i].title, str,--x) == 0){
				printf("\n--Informacoes do livro--");
				printf("\n\tISBN: %d\n\tTITULO: %s\n\tEDITORA: %s\t\tAUTOR(A): %s", v[i].isbn, v[i].title, v[i].editora, v[i].autor);
				printf("\n\tAREA: %d - %s\n\tANO: %d", v[i].area, k[aux].area, v[i].ano);
				printf("\n\tQTD DE COPIAS: %d\n\tQTD EMPRESTADA: %d\n\t\tEMPRESTIMO ACUMULADO: %d", v[i].qtdc, v[i].qtdemp, v[i].empac);
				printf("\n------------------------------");
				
				found = 1;
				break;
			}
		}
		if(found == 0){
			printf("\nSem resultados");
		}
	}
}

//Editar livros
void editbook(struct Livros v[], struct Area k[], int *nLivros){
	//inteiro x = var local para isbn | aux para a área | found para indicar se encontrou | edit para confirmar se deseja alterar | a para auxiliar na area
	//secure para guardar o valor de *nLivros, sem comprometer a contagem
	int i, x, aux=0, found=0, edit, a=0, secure=0;
	printf("Informe o isbn para alterar as informacoes: ");
	scanf("%d", &x);
	fflush(stdin);
	
	for(i=0; i<*nLivros; i++){
		if(v[i].isbn == x){
			aux = v[i].area;
			
			secure = *nLivros;
			*nLivros = i;
			
			printf("\n--Informacoes do livro--");
			printf("\n\tISBN: %d\n\tTITULO: %s\n\tEDITORA: %s\t\tAUTOR(A): %s", v[i].isbn, v[i].title, v[i].editora, v[i].autor);
			printf("\n\tAREA: %d - %s\n\tANO: %d", v[i].area, k[aux].area, v[i].ano);
			printf("\n\tQTD DE COPIAS: %d\n\tQTD EMPRESTADA: %d\n\t\tEMPRESTIMO ACUMULADO: %d", v[i].qtdc, v[i].qtdemp, v[i].empac);
			printf("\n------------------------------");
			//indicador se encontrou ou não.
			found = 1;
			//sair do loop no primeiro que achar
			i=100;
		}
	}
	

	
	if(found == 0){
		printf("\nLivro nao encontrado.");
	}
	else{
		
		//titulo
		printf("\nDeseja editar o titulo? (1 = sim | 0 = nao) ");
		scanf("%d", &edit);
		fflush(stdin);
		if(edit == 1){
			printf("\nTitulo do livro: ");
			fgets(v[*nLivros].title,49,stdin);
			fflush(stdin);
		}
		
		//editora
		printf("\nDeseja editar a editora? (1 = sim | 0 = nao) ");
		scanf("%d", &edit);
		fflush(stdin);
		if(edit == 1){
			printf("\nEditora do livro: ");
			fgets(v[*nLivros].editora,49,stdin);
			fflush(stdin);
		}
		
		//autor
		printf("\nDeseja editar o autor? (1 = sim | 0 = nao) ");
		scanf("%d", &edit);
		fflush(stdin);
		if(edit == 1){
			printf("\nAutor do livro: ");
			fgets(v[*nLivros].autor,49,stdin);
			fflush(stdin);
		}
		
		//area
		printf("\nDeseja editar a area? (1 = sim | 0 = nao) ");
		scanf("%d", &edit);
		fflush(stdin);
		if(edit == 1){
			//Loop para a confirmação da área.
			while(a==0){
				printf("\nNova Area (numero da area): ");
				scanf("%d", &v[*nLivros].area);
				fflush(stdin);
				
				aux = v[*nLivros].area;
				printf("\n\tArea: %s", k[aux].area);
				printf("\nDeseja confirmar esta area? (0 = nao | 1 = sim) ");
				scanf("%d", &a);
			}
		}
		
		//ano
		printf("\nDeseja editar o ano? (1 = sim | 0 = nao) ");
		scanf("%d", &edit);
		fflush(stdin);
		if(edit == 1){
			printf("\nAno do livro: ");
			scanf("%d", &v[*nLivros].ano);
			fflush(stdin);
		}
		
		//copias
		printf("\nDeseja editar a qtd de copias? (1 = sim | 0 = nao) ");
		scanf("%d", &edit);
		fflush(stdin);
		if(edit == 1){
			printf("\nNova quantidade de Copias: ");
			scanf("%d", &v[*nLivros].qtdc);
			fflush(stdin);
		}
	}
	*nLivros = secure;
	system ("cls");
}

//realizar empréstimo
void realizarEmprestimo (struct Livros v[], int *nLivros){
	int x, i, found=0;
	
	printf("Digite o ISBN do livro para emprestimo: ");
	scanf("%d", &x);
	
	for(i=0; i<*nLivros; i++){
		if(v[i].isbn == x){
			printf("\n--Informacoes do livro--");
			printf("\n\tISBN: %d\n\tTITULO: %s", v[i].isbn, v[i].title);
			printf("\n------------------------------");
			//indicador se encontrou ou não.
			found = 1;
			v[i].qtdc--;
			//incremento do empréstimo
			if(v[i].qtdc>=1){
				v[i].qtdemp++;
				v[i].empac++;
				printf("\nEmprestimo realizado!");
				printf("\n------------------------------\n");
			}
			else{
				v[i].qtdc++;			
				printf("\nEmprestimo indisponivel, minimo de 2 exemplares para realizar um emprestimo");
				printf("\n------------------------------\n");
			}
		}
	}
	if(found==0){
		printf("\nLivro nao encontrado");
	}
}

//realizar devolução
void realizarDev(struct Livros v[], int *nLivros){
	int x, i, found=0;
	
	printf("Digite o ISBN do livro para devolucao: ");
	scanf("%d", &x);
	
	for(i=0; i<*nLivros; i++){
		if(v[i].isbn == x){
			printf("\n--Informacoes do livro--");
			printf("\n\tISBN: %d\n\tTITULO: %s", v[i].isbn, v[i].title);
			printf("\n------------------------------");
			//indicador se encontrou ou não.
			found = 1;
			//incremento do empréstimo
			if(v[i].qtdemp>=1){
				v[i].qtdemp--;
				v[i].qtdc++;
				printf("\nDevolucao realizada!");
				printf("\n------------------------------\n");
			}
			else{			
				printf("\nNao foi realizado emprestimo deste livro");
				printf("\n------------------------------\n");
			}
		}
	}
	if(found==0){
		printf("\nLivro nao encontrado");
	}
}

//relação de livros emprestados
void relLivrosEmp(struct Livros v[], int *nLivros){
	int i, totalemp=0;
	if(*nLivros != 0){
		printf("\tRelacao de livros emprestados:");
		for(i = 0; i < *nLivros; i++){
			if(v[i].qtdemp != 0){
				printf("\n--Informacoes do livro--");
				printf("\n\tISBN: %d\n\tTITULO: %s", v[i].isbn, v[i].title);
				printf("\n\tQTD DE COPIAS: %d\n\tQTD EMPRESTADA: %d", v[i].qtdc, v[i].qtdemp);
				printf("\n------------------------------");
				//contador total de livros emprestados
				totalemp++;
			}
		}
		printf("\nTotal emprestado no momento: %d", totalemp);
		printf("\n------------------------------\n");
	}
}

//relação de livros emprestados de determinada area
void relLivrosEmpArea(struct Livros v[], struct Area k[], int *nLivros){
	int i, totalemp=0, aux, x;
	
	printf("Informe a Area desejada (numero da area): ");
	scanf("%d", &x);
	printf("\nArea informada: %s", k[x].area);
	
	if(*nLivros != 0){
		for(i = 0; i < *nLivros; i++){
			if(v[i].qtdemp != 0){
				if(v[i].area == x){
					printf("\n--Informacoes do livro--");
					printf("\n\tISBN: %d\n\tTITULO: %s", v[i].isbn, v[i].title);
					printf("\n\tQTD DE COPIAS: %d\n\tQTD EMPRESTADA: %d", v[i].qtdc, v[i].qtdemp);
					printf("\n------------------------------");
					//contador total de livros emprestados
					totalemp++;
				}
			}
		}
		printf("\nTotal emprestado no momento: %d", totalemp);
		printf("\n------------------------------\n");
	}
}

//exibir os livros emprestados por área
void relLivrosTAreas(struct Livros v[], struct Area k[], int *nLivros){
	int i, aux, x;
	
	if(*nLivros != 0){
		printf("\t- Livros emprestados por area\n");
		for(x = 0; x < 10; x++){
			for(i = 0; i < *nLivros; i++){
				if(v[i].qtdemp != 0){
					if(v[i].area == x){
						printf("\n--------------Area: %s", k[x].area);
						printf("\n\t--Informacoes do livro--");
						printf("\n\t\tISBN: %d\n\t\tTITULO: %s", v[i].isbn, v[i].title);
						printf("\n\t\tQTD EMPRESTADA: %d", v[i].qtdemp);
						printf("\n------------------------------\n");
					}
				}
			}
		}		
	}
}

//empréstimo acumulado total por área
void empAreaT(struct Livros v[], struct Area k[], int *nLivros){
	int i, totempac[10];
	int x;
	if(*nLivros != 0){
		printf("\nTOTAL DE EMPRESTIMOS ACUMULADO EM CADA AREA:\n");
		//alternar área de soma
		for(x=0; x<10; x++){
			//inicializar o valor inicial do vetor
			totempac[x]=0;
			for(i = 0; i < *nLivros; i++){
				if(v[i].empac != 0){
					if(v[i].area == x){
						//contador total de livros emprestados
						totempac[x] += v[i].empac;
					}
				}
			}
			printf("\n\t- %s\t|- %d Emprestimos Acumulados\n", k[x].area, totempac[x]);
		}
	}
}

//Dados gerais
void dadosGerais (struct Livros v[], int *nLivros){
	int i, totemp = 0, totempac = 0, totqtdc = 0;
	for(i=0; i<*nLivros; i++){
		if(v[i].qtdemp != 0){
			totemp+=v[i].qtdemp;
		}
		if(v[i].empac != 0){
			totempac+= v[i].empac;
		}
		if(v[i].qtdc != 0){
			totqtdc += v[i].qtdc;
		}
	}
	
	printf("Quantidade de livros no acervo: %d", totqtdc);
	printf("\n\nQuantidade de livros atualmente emprestados: %d", totemp);
	printf("\n\nQuantidade total de livros emprestados desde o inicio: %d", totempac);
	printf("\n");
}

//sobre
void sobre(){
	printf("-TRABALHO DE ALGORITMOS e ESTRUTURA DE DADOS\n\tSISTEMA DE BIBLIOTECA\n\tAUTOR: Thiago Silva.\n\tDATA: 25/02/2021");
}

int main(){
	struct Livros acervo[100];
	struct Area v_area[10];
	//Contador de livros cadastrados | op = operador do menu
	int nLivros = 0, op=1;
	//inicializar as areas
	cadArea(v_area);
	
	while (op != 0){
		printf("\n***********************************************************************************************");
		printf("\n0 - SAIR DA APLICACAO\n1 - EXIBIR TODAS AS AREAS\n2 - INSERIR UM LIVRO\n3 - INSERIR VARIOS LIVROS");
		printf("\n4 - EXIBIR RELACAO DE LIVROS\n5 - EXIBIR DADOS DE UM LIVRO POR ISBN\n6 - EXIBIR DADOS DE UM LIVRO POR TITULO");
		printf("\n7 - BUSCAR LIVRO COM AS INICIAIS\n8 - EDITAR UM LIVRO\n9 - REALIZAR UM EMPRESTIMO\n10 - REALIZAR DEVOLUCAO");
		printf("\n11 - EXIBIR OS LIVROS EMPRESTADOS\n12 - EXIBIR OS LIVROS EMPRESTADOS DE DETERMINADA AREA");
		printf("\n13 - EXIBIR OS LIVROS EMPRESTADOS POR AREA\n14 - QUANTIDADE TOTAL DE LIVROS EMPRESTADOS POR AREA");
		printf("\n15 - DADOS GERAIS DA BIBLIOTECA\n\n16 - SOBRE");
		printf ("\n***********************************************************************************************");
	
		printf("\nDIGITE A OPCAO DESEJADA: ");
		scanf ("%d", &op);
		fflush(stdin);
	
		system ("cls");
		
		switch (op) {
			
			case 0 :
				printf("\nEncerrando aplicacao...");
				break;
	
			case 1 :
				exibirArea(v_area);
			    break;
			
			case 2 :
				insLivro(acervo, v_area, &nLivros);
			    break;
			
			case 3 :
				insVLivros(acervo, v_area, &nLivros);
				break;
			
			case 4 :
			    relLivros(acervo, v_area, &nLivros);
				break;
			
			case 5 :
				dataisbn(acervo, v_area, &nLivros);
				break;
			
			case 6 :
				datatitle(acervo, v_area, &nLivros);
				break;
			
			case 7 :
				busctitle(acervo, v_area, &nLivros);
			    break;
			
			case 8 :
				editbook(acervo, v_area, &nLivros);
				break;
			
			case 9 :
				realizarEmprestimo(acervo, &nLivros);
				break;
			
			case 10 :
				realizarDev(acervo, &nLivros);
				break;
				
			case 11 :
				relLivrosEmp(acervo, &nLivros);
				break;
			
			case 12 :
			    relLivrosEmpArea(acervo, v_area, &nLivros);
			    break;
			
			case 13 :
				relLivrosTAreas(acervo, v_area, &nLivros);
				break;
			
			case 14 :
				empAreaT(acervo, v_area, &nLivros);
				break;
			
			case 15 :
				dadosGerais(acervo, &nLivros);
				break;
			
			case 16 :
				sobre();
				break;
				
			default :
				printf("\nComando incorreto!");
				break;
			
			}
		}
	return 0;
}