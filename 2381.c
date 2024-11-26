#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno_estrutura {
	char nome[21];
	struct Aluno_estrutura* proximo;
} Aluno;

Aluno* novoAluno(char *nome) {
	Aluno *novoAluno = (Aluno*)malloc(sizeof(Aluno));
	strcpy(novoAluno->nome, nome);

	novoAluno->proximo = NULL;
	return novoAluno;
}

void inserirOrdenado(Aluno **lista, char *nome) {
	Aluno* novoAluno = novoAluno(nome);

	if (*lista == NULL || strcmp((*lista)->nome, nome) > 0) {
		novoAluno->proximo = *lista;
		*lista = novoAluno;
	} else {
		Aluno *atual = *lista;
		while (atual->proximo != NULL && strcmp(atual->proximo->nome, nome) < 0) {
			atual = atual->proximo;
		}
		novoAluno->proximo = atual->proximo;
		atual->proximo = novoAluno;
	}
}

char *obterNomeK(Aluno *lista, int k) {
	int i;

	for (int i = 1; i < k && lista != NULL; i++) {
		lista = lista->proximo;
	}

	return lista->nome;
}

void liberarLista(Aluno *lista) {
	Aluno *temp;
	
	while (lista != NULL) {
		temp = lista;
		lista = lista->proximo;
		free(temp);
	}
}

int main() {
	int totalAlunos, posicaoSorteada, i;

	scanf("%d %d", &totalAlunos, &posicaoSorteada);

	Aluno *listaOrdenada = NULL;
	char nomeAluno[21];

	for (i = 0; i < totalAlunos; i++) {
		scanf("%s", nomeAluno);
		inserirOrdenado(&listaOrdenada, nomeAluno);
	}

	printf("%s\n", obterNomeK(listaOrdenada, posicaoSorteada));

	liberarLista(listaOrdenada);
}
