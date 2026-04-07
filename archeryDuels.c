#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void resultadoDisparo(int valorSorteio) {
  srand(time(0));

  int numeroSorteio = (rand() % 6) + 1; //
}
int main() {

  int ptsJogador = 0, ptsComputador = 0;
  int flechasJogador = 3, flechasComputador = 3;
  int turno = 0; // jogador: 0, computador: 1
  while (ptsJogador < 100 || ptsComputador < 100) {
    if (turno == 0) {
      printf("=== Turno do jogador ===");

    } else {
      printf("=== Turno do computador ===");
    }
  }

  return 0;
}
