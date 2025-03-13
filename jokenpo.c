#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showMenu();
void startGame();
void showRules();
void showWinCounter();
void showLossCounter();
void exitGame();
void playerVsComputer();
void playerVsPlayer();
void showWinCounterOptions();
void showLossCounterOptions();
void resetCounters();
void playAgain();

int player1Wins = 0, player2Wins = 0, computerWins = 0;
int player1Losses = 0, player2Losses = 0, computerLosses = 0;

int main() {
    int choice;
    srand(time(NULL));

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                showRules();
                break;
            case 3:
                showWinCounter();
                break;
            case 4:
                showLossCounter();
                break;
            case 5:
                exitGame();
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}

void showMenu() {
    printf("Menu Principal:\n");
    printf("1. Iniciando o jogo\n");
    printf("2. Regras do jogo\n");
    printf("3. Contador de Vitórias\n");
    printf("4. Contador de Derrotas\n");
    printf("5. Saindo do jogo\n");
    printf("Escolha uma opção: ");
}

void startGame() {
    int mode;
    printf("Escolha o modo de jogo:\n");
    printf("1. Jogador VS Computador\n");
    printf("2. Jogador VS Jogador\n");
    printf("Escolha uma opção: ");
    scanf("%d", &mode);

    switch (mode) {
        case 1:
            playerVsComputer();
            break;
        case 2:
            playerVsPlayer();
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }
}

void showRules() {
    printf("Regras do jogo:\n");
    printf("Pedra ganha de Tesoura\n");
    printf("Tesoura ganha de Papel\n");
    printf("Papel ganha de Pedra\n");
    printf("Pressione qualquer tecla para voltar ao menu principal...\n");
    getchar();
    getchar();
}

void showWinCounter() {
    int choice;
    showWinCounterOptions();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Vitórias do Jogador 1: %d\n", player1Wins);
            printf("Vitórias do Jogador 2: %d\n", player2Wins);
            break;
        case 2:
            printf("Vitórias do Jogador 1: %d\n", player1Wins);
            printf("Vitórias do Computador: %d\n", computerWins);
            break;
        case 3:
            printf("Vitórias do Jogador 1: %d\n", player1Wins);
            printf("Vitórias do Jogador 2: %d\n", player2Wins);
            printf("Vitórias do Computador: %d\n", computerWins);
            break;
        case 4:
            resetCounters();
            break;
        case 5:
            return;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }
    printf("Pressione qualquer tecla para voltar ao menu principal...\n");
    getchar();
    getchar();
}

void showLossCounter() {
    int choice;
    showLossCounterOptions();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Derrotas do Jogador 1: %d\n", player1Losses);
            printf("Derrotas do Jogador 2: %d\n", player2Losses);
            break;
        case 2:
            printf("Derrotas do Jogador 1: %d\n", player1Losses);
            printf("Derrotas do Computador: %d\n", computerLosses);
            break;
        case 3:
            printf("Derrotas do Jogador 1: %d\n", player1Losses);
            printf("Derrotas do Jogador 2: %d\n", player2Losses);
            printf("Derrotas do Computador: %d\n", computerLosses);
            break;
        case 4:
            resetCounters();
            break;
        case 5:
            return;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }
    printf("Pressione qualquer tecla para voltar ao menu principal...\n");
    getchar();
    getchar();
}

void exitGame() {
    printf("Encerrando o jogo...\n");
    printf("Obrigado por jogar!\n");
    printf("Até a próxima!\n");
}

void playerVsComputer() {
    int rounds, playerChoice, computerChoice;
    printf("Quantas rodadas você quer jogar? ");
    scanf("%d", &rounds);

    for (int i = 0; i < rounds; i++) {
        printf("Escolha uma opção:\n");
        printf("1. Pedra\n");
        printf("2. Papel\n");
        printf("3. Tesoura\n");
        printf("Escolha: ");
        scanf("%d", &playerChoice);

        computerChoice = rand() % 3 + 1;

        if (playerChoice == computerChoice) {
            printf("Empate!\n");
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            printf("Você ganhou!\n");
            player1Wins++;
            computerLosses++;
        } else {
            printf("Você perdeu!\n");
            computerWins++;
            player1Losses++;
        }
    }
    playAgain();
}

void playerVsPlayer() {
    int rounds, player1Choice, player2Choice;
    printf("Quantas rodadas você quer jogar? ");
    scanf("%d", &rounds);

    for (int i = 0; i < rounds; i++) {
        printf("Jogador 1, escolha uma opção:\n");
        printf("1. Pedra\n");
        printf("2. Papel\n");
        printf("3. Tesoura\n");
        printf("Escolha: ");
        scanf("%d", &player1Choice);

        printf("Jogador 2, escolha uma opção:\n");
        printf("1. Pedra\n");
        printf("2. Papel\n");
        printf("3. Tesoura\n");
        printf("Escolha: ");
        scanf("%d", &player2Choice);

        if (player1Choice == player2Choice) {
            printf("Empate!\n");
        } else if ((player1Choice == 1 && player2Choice == 3) ||
                   (player1Choice == 2 && player2Choice == 1) ||
                   (player1Choice == 3 && player2Choice == 2)) {
            printf("Jogador 1 ganhou!\n");
            player1Wins++;
            player2Losses++;
        } else {
            printf("Jogador 2 ganhou!\n");
            player2Wins++;
            player1Losses++;
        }
    }
    playAgain();
}

void showWinCounterOptions() {
    printf("Contador de Vitórias:\n");
    printf("1. Contador de vitórias do jogador VS jogador\n");
    printf("2. Contador de vitórias do jogador VS Computador\n");
    printf("3. Contador de vitórias totais dos jogadores e computador\n");
    printf("4. Reiniciar os contadores\n");
    printf("5. Retornar ao menu principal\n");
    printf("Escolha uma opção: ");
}

void showLossCounterOptions() {
    printf("Contador de Derrotas:\n");
    printf("1. Contador de derrotas do jogador VS jogador\n");
    printf("2. Contador de derrotas do jogador VS Computador\n");
    printf("3. Contador de derrotas totais dos jogadores e computador\n");
    printf("4. Reiniciar os contadores\n");
    printf("5. Retornar ao menu principal\n");
    printf("Escolha uma opção: ");
}

void resetCounters() {
    player1Wins = player2Wins = computerWins = 0;
    player1Losses = player2Losses = computerLosses = 0;
    printf("Contadores reiniciados.\n");
}

void playAgain() {
    char choice;
    printf("Deseja jogar novamente? (S/N): ");
    scanf(" %c", &choice);

    if (choice == 'S' || choice == 's') {
        startGame();
    } else {
        printf("Voltando ao menu principal...\n");
    }
}