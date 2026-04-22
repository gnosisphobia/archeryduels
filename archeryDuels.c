#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int atirarFlecha() {

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

void pausar() {
  printf("\nPressione ENTER para continuar...");
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ; // limpa tudo
  getchar();
}

int rodadaJogador() {
  int escolhaDoJogador;
  int ptsRodada = 0;
  int numFlechas = 3;

  printf("\033[H\033[J"); // limpa cmd
  printf("====== RODADA DO JOGADOR ======\n");

  while (numFlechas > 0) {
    printf("Escolha sua acao:\n1. Atirar\n2. Encerrar turno\n");

    // validando num inteiro
    if (scanf("%d", &escolhaDoJogador) != 1) { // ou seja, caso seja falso
      printf("Entrada invalida!\n");
      while (getchar() != '\n')
        ;       // limpa o buffer
      continue; // volta para o início do while
    }

    // validando se eh 1 ou 2
    if (escolhaDoJogador != 1 && escolhaDoJogador != 2) {
      printf("Opção invalida!\n");
      continue;
    }

    if (escolhaDoJogador == 1) {
      int ptsTiro = atirarFlecha();

      if (ptsTiro == 0) {
        ptsRodada = 0;
        printf("Voce errou!\n");
        printf("Pontuacao total da rodada: %d\n", ptsRodada);
        pausar();
        return ptsRodada;
      } else if (ptsTiro >= 2 && ptsTiro <= 5) {
        ptsRodada += ptsTiro;
        numFlechas--;
        printf("Voce ganhou %d pontos!\n", ptsTiro);
        printf("Numero de flechas atual: %d\n", numFlechas);
        printf("Pontuacao total da rodada: %d\n", ptsRodada);
      } else {
        ptsRodada += ptsTiro;
        printf("Acerto critico! Você ganhou 6 pontos!\n");
        printf("Numero de flechas atual: %d\n", numFlechas);
        printf("Pontuacao total da rodada: %d\n", ptsRodada);
      }

    } else if (escolhaDoJogador == 2) {
      pausar();
      return ptsRodada;
    }
  }

  pausar();

  return ptsRodada;
}

int rodadaComputador(
    int ptsComputador) { // busca ptsComputador para aplicar regra 1
  int ptsRodada = 0;
  int numFlechas = 3;

  printf("\033[H\033[J"); // limpa cmd
  printf("====== RODADA DO COMPUTADOR ======\n");

  while (numFlechas > 0) {
    int ptsTiro = atirarFlecha();

    if (ptsTiro == 0) {
      printf("Computador errou!\n");
      pausar();
      return 0; // retorna 0 pq ja vai zerar direto
    }

    ptsRodada += ptsTiro;

    printf("Computador fez %d pontos!\n", ptsTiro);
    printf("Pontuacao total da rodada: %d\n", ptsRodada);

    // regra 1: caso ele já tenha ganho, para de jogar, evitando tirar 0
    if (ptsComputador + ptsRodada >= 100) {
      printf("Computador encerrou o turno para vencer!\n");
      pausar();
      return ptsRodada;
    }

    // regra 2: alto risco
    if (ptsRodada >= 15) { // REVISAR VALOR
      printf("Computador encerrou o turno! (alto risco)\n");
      pausar();
      return ptsRodada;
    }

    // controle de flechas
    if (ptsTiro != 6) {
      numFlechas--;
    }

    printf("Numero de flechas atual: %d\n", numFlechas);
  }

  pausar();

  return ptsRodada;
}

int main() {

  srand(time(NULL));

  int turno = 0; // jogador: 0, comp: 1
  int ptsJogador = 0, ptsComputador = 0;

  while (ptsJogador < 100 && ptsComputador < 100) {
    if (turno == 0) {
      ptsJogador += rodadaJogador();
      printf("====== FIM DA RODADA ======\n");
      printf("Pontuacao total do jogador: %d\n", ptsJogador);
      pausar();
      turno = 1;
    } else {
      ptsComputador += rodadaComputador(ptsComputador);
      printf("====== FIM DA RODADA ======\n");
      printf("Pontuacao total do computador: %d\n", ptsComputador);
      pausar();
      turno = 0;
    }
  }

  printf("\033[H\033[J"); // limpa cmd
  printf("====== FIM DE JOGO ======\n");
  printf("====== PLACAR ======\nJogador: %d\nComputador: %d\n\n", ptsJogador,
         ptsComputador);

  if (ptsJogador >= 100) {
    printf("JOGADOR GANHOU!\n");
  } else {
    printf("COMPUTADOR GANHOU!\n");
  }

  // confirmacao antes de sair do programa
  printf("\nPressione ENTER para sair...");
  while (getchar() != '\n')
    ;        // limpa buffer
  getchar(); // espera receber o ENTER

  return 0;
}
