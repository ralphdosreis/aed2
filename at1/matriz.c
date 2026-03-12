#include <stdio.h>

#define Alunos 30

int main()
{
    float dados[Alunos][2];
    float somaNotas = 0;
    int aprovados = 0, reprovados = 0;

    for (int i = 0; i < Alunos; i++)
    {
        printf("Aluno %d - Nota: ", i + 1);
        scanf("%f", &dados[i][0]);
        printf("Aluno %d - Frequencia: ", i + 1);
        scanf("%f", &dados[i][1]);

        somaNotas += dados[i][0];
    }

    for (int i = 0; i < Alunos; i++)
    {
        if (dados[i][0] >= 6.0 && dados[i][1] >= 75.0)
        {
            printf("Aluno %d: Aprovado\n", i + 1);
            aprovados++;
        }
        else
        {
            reprovados++;
            if (dados[i][0] < 6.0 && dados[i][1] < 75.0)
            {
                printf("Aluno %d: Reprovado por nota e frequencia\n", i + 1);
            }
            else if (dados[i][0] < 6.0)
            {
                printf("Aluno %d: Reprovado por nota\n", i + 1);
            }
            else
            {
                printf("Aluno %d: Reprovado por frequencia\n", i + 1);
            }
        }
    }

    printf("\nResultados: \n");
    printf("Media da turma: %.2f\n", somaNotas / Alunos);
    printf("Total de aprovados: %d\n", aprovados);
    printf("Total de reprovados: %d\n", reprovados);
}