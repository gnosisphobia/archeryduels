#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rodada() {
  srand(time(0));

  int numeroSorteio = (rand() % 6) + 1;
}
int main() {

  int ptsJogador = 0, ptsComputador = 0;
  int flechasJogador = 3, flechasComputador = 3;
  int turno = 0; // jogador: 0, computador: 1
  int escolhaDoJogador;
  int numeroLoopJogador = 0;

  while (ptsJogador < 100 || ptsComputador < 100) {
    while (turno == 0 || numeroLoopJogador != 3) {
      printf("=== Turno do jogador ===\n");
      printf("Escolha sua ação:\n1. Atirar\n2. Encerrar rodada");
      scanf("%d", &escolhaDoJogador);

      if (escolhaDoJogador == 1) {
        rodada();
        numeroLoopJogador++;
      } else {
        numeroLoopJogador++;
      }
    }

    return 0;
  }
}
