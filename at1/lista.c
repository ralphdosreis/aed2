#include <stdio.h>
#include <stdlib.h>

#define ALUNOS 3

typedef struct Aluno
{
  float nota;
  float frequencia;
  struct Aluno *proximo;
} Aluno;

int main()
{
  Aluno *inicio = NULL, *atual, *novo;
  float somaNotas = 0;
  int aprovados = 0, reprovados = 0;

  for (int i = 0; i < ALUNOS; i++)
  {
    novo = (Aluno *)malloc(sizeof(Aluno));
    printf("Aluno %d - Nota: ", i + 1);
    scanf("%f", &novo->nota);
    printf("Aluno %d - Frequencia: ", i + 1);
    scanf("%f", &novo->frequencia);
    novo->proximo = NULL;

    if (inicio == NULL)
    {
      inicio = novo;
    }
    else
    {
      atual = inicio;
      while (atual->proximo != NULL)
        atual = atual->proximo;
      atual->proximo = novo;
    }
  }

  atual = inicio;
  int cont = 1;
  printf("RESULTADOS:\n");
  while (atual != NULL)
  {
    somaNotas += atual->nota;
    printf("Aluno %d: ", cont++);

    if (atual->nota >= 6.0 && atual->frequencia >= 75.0)
    {
      aprovados++;
      printf("Aprovado\n");
    }
    else
    {
      reprovados++;
      if (atual->nota < 6.0 && atual->frequencia < 75.0)
        printf("Reprovado por Nota e Frequencia\n");
      else if (atual->nota < 6.0)
        printf("Reprovado por Nota\n");
      else
        printf("Reprovado por Frequencia\n");
    }
    atual = atual->proximo;
  }

  printf("Media da turma: %.2f", somaNotas / ALUNOS);
  printf("\nAprovados: %d", aprovados);
  printf("\nReprovados: %d", reprovados);

  while (inicio != NULL)
  {
    atual = inicio;
    inicio = inicio->proximo;
    free(atual);
  }

  return 0;
}