#include <stdlib.h>
#include <stdio.h>

void printM(int **M, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int **scroll90(int **M, int N, int Q, int S){
//  Rotaciona a matriz M uma quantidade Q de vezes em 90º no sentido S

    int **A = (int**) malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++)
        A[i] = (int*) malloc(sizeof(int) * N);

    for(int q = 0; q < Q; q++){
        // rotaciona M e armazena em A
        for(int i = 0; i < N; i++){
            for(int j = 0, k = (N - 1); j < N; j++){
                switch(S){
                    case 0: // horário
                        A[i][j] = M[k][i];

                        break;

                    case 1: // anti-horário
                        A[j][i] = M[i][k];

                        break;
                }

                k--;
            }
        }

        // atualiza M
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                M[i][j] = A[i][j];
            }
        }
    }

    for(int i = 0; i < N; i++)
        free(A[i]);
    free(A);

    return M;
}

int copyM(int **A, int **B, int N){
// copia a matriz A em B

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            A[i][j] = B[i][j];
        }
    }
}

int main(void){
    int N;
    int **M, **A;

    printf("Insira o tamanho da matriz: ");
    scanf("%d", &N);

    M = (int**) malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++)
        M[i] = (int*) malloc(sizeof(int) * N);
    A = (int**) malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++)
        A[i] = (int*) malloc(sizeof(int) * N);

    printf("Insira os valores da matriz...\n");

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &M[i][j]);
        }
    }

    printf("É a matriz:\n");
    printM(M, N);

    copyM(A, M, N);
    A = scroll90(A, N, 1, 0);
    printf("É a matriz rotacionada 90º no sentido horário:\n");
    printM(A, N);

    copyM(A, M, N);
    A = scroll90(A, N, 1, 1);
    printf("É a matriz rotacionada 90º no sentido anti-horário:\n");
    printM(A, N);

    return 0;
}