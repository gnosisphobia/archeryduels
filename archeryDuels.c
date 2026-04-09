#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int atirarFlecha() {
    srand(time(NULL));

    int numeroSorteio = rand() % 6 + 1; // 2
    int pontosTiro = 0;

    if (numeroSorteio == 1) {
        pontosTiro = 0;
    } else if (numeroSorteio >= 2 && numeroSorteio <= 5) {
        pontosTiro = numeroSorteio;
    } else {
        pontosTiro = 6;
    }
    return pontosTiro;
}

int rodadaJogador() {
    int escolhaDoJogador;
    int ptsRodada = 0;
    int numFlechas = 3;

    printf("=== Rodada do jogador ===\n");
    printf("Escolha sua acao:\n1. Atirar\n2. Encerrar turno\n");
    scanf("%d", &escolhaDoJogador);

    while (numFlechas > 0) {
        if (escolhaDoJogador == 1) {
            int ptsTiro = atirarFlecha();
        
            if (ptsTiro == 0) {
                ptsRodada = 0;
                return ptsRodada;
            } else if (ptsTiro >= 2 && ptsTiro <= 5){
                ptsRodada += ptsTiro;
                numFlechas --;
            } else {
                ptsRodada += ptsTiro;
                numFlechas ++;
            }

            escolhaDoJogador = 0;
        }
    } return ptsRodada;
} 


int main() {

    int turno = 0; // jogador: 0, comp: 1
    int ptsJogador = 0, ptsComputador = 0;

    while (ptsJogador != 100 || ptsComputador != 100) {
        if (turno == 0) {
            ptsJogador += rodadaJogador();
            turno = 1;
        } else {
            // ptsComputador += rodadaComputador();
            // turno = 0;
        }
    } 

    if (ptsJogador >= 100) {
        printf("Jogador ganhou!");
    } else {
        printf("Computador ganhou!");
    }

    return 0;
}