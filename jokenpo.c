#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
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

// Global counters
int player1Wins = 0, player2Wins = 0, computerWins = 0;
int player1Losses = 0, player2Losses = 0, computerLosses = 0;
int draws = 0; // Draw counter

int main() {
    int choice;
    srand(time(NULL)); // Initialize random number generator

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
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}

// Function to display the main menu
void showMenu() {
    printf("Main Menu:\n");
    printf("1. Start Game\n");
    printf("2. Game Rules\n");
    printf("3. Win Counter\n");
    printf("4. Loss Counter\n");
    printf("5. Exit Game\n");
    printf("Choose an option: ");
}

// Function to start the game
void startGame() {
    int mode;
    printf("Choose the game mode:\n");
    printf("1. Player VS Computer\n");
    printf("2. Player VS Player\n");
    printf("Choose an option: ");
    scanf("%d", &mode);

    switch (mode) {
        case 1:
            playerVsComputer();
            break;
        case 2:
            playerVsPlayer();
            break;
        default:
            printf("Invalid option. Try again.\n");
    }
}

// Function to display the game rules
void showRules() {
    printf("Game Rules:\n");
    printf("Rock beats Scissors\n");
    printf("Scissors beat Paper\n");
    printf("Paper beats Rock\n");
    printf("Press any key to return to the main menu...\n");
    getchar();
    getchar();
}

// Function to display the win counter
void showWinCounter() {
    int choice;
    showWinCounterOptions();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Player 1 Wins: %d\n", player1Wins);
            printf("Player 2 Wins: %d\n", player2Wins);
            break;
        case 2:
            printf("Player 1 Wins: %d\n", player1Wins);
            printf("Computer Wins: %d\n", computerWins);
            break;
        case 3:
            printf("Player 1 Wins: %d\n", player1Wins);
            printf("Player 2 Wins: %d\n", player2Wins);
            printf("Computer Wins: %d\n", computerWins);
            break;
        case 4:
            resetCounters();
            break;
        case 5:
            return;
        default:
            printf("Invalid option. Try again.\n");
    }
    printf("Press any key to return to the main menu...\n");
    getchar();
    getchar();
}

// Function to display the loss counter
void showLossCounter() {
    int choice;
    showLossCounterOptions();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Player 1 Losses: %d\n", player1Losses);
            printf("Player 2 Losses: %d\n", player2Losses);
            break;
        case 2:
            printf("Player 1 Losses: %d\n", player1Losses);
            printf("Computer Losses: %d\n", computerLosses);
            break;
        case 3:
            printf("Player 1 Losses: %d\n", player1Losses);
            printf("Player 2 Losses: %d\n", player2Losses);
            printf("Computer Losses: %d\n", computerLosses);
            break;
        case 4:
            resetCounters();
            break;
        case 5:
            return;
        default:
            printf("Invalid option. Try again.\n");
    }
    printf("Press any key to return to the main menu...\n");
    getchar();
    getchar();
}

// Function to exit the game
void exitGame() {
    printf("Exiting the game...\n");
    printf("Thank you for playing!\n");
    printf("See you next time!\n");
}

// Function for Player VS Computer mode
void playerVsComputer() {
    int rounds, playerChoice, computerChoice;
    printf("How many rounds do you want to play? ");
    scanf("%d", &rounds);

    for (int i = 0; i < rounds; i++) {
        printf("Choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Choose: ");
        scanf("%d", &playerChoice);

        computerChoice = rand() % 3 + 1;

        if (playerChoice == computerChoice) {
            printf("Draw!\n");
            draws++;
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            printf("You won!\n");
            player1Wins++;
            computerLosses++;
        } else {
            printf("You lost!\n");
            computerWins++;
            player1Losses++;
        }
    }
    playAgain();
}

// Function for Player VS Player mode
void playerVsPlayer() {
    int rounds, player1Choice, player2Choice;
    printf("How many rounds do you want to play? ");
    scanf("%d", &rounds);

    for (int i = 0; i < rounds; i++) {
        printf("Player 1, choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Choose: ");
        scanf("%d", &player1Choice);

        printf("Player 2, choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Choose: ");
        scanf("%d", &player2Choice);

        if (player1Choice == player2Choice) {
            printf("Draw!\n");
            draws++;
        } else if ((player1Choice == 1 && player2Choice == 3) ||
                   (player1Choice == 2 && player2Choice == 1) ||
                   (player1Choice == 3 && player2Choice == 2)) {
            printf("Player 1 won!\n");
            player1Wins++;
            player2Losses++;
        } else {
            printf("Player 2 won!\n");
            player2Wins++;
            player1Losses++;
        }
    }
    playAgain();
}

// Function to display win counter options
void showWinCounterOptions() {
    printf("Win Counter:\n");
    printf("1. Player VS Player win counter\n");
    printf("2. Player VS Computer win counter\n");
    printf("3. Total wins of players and computer\n");
    printf("4. Reset counters\n");
    printf("5. Return to main menu\n");
    printf("Choose an option: ");
}

// Function to display loss counter options
void showLossCounterOptions() {
    printf("Loss Counter:\n");
    printf("1. Player VS Player loss counter\n");
    printf("2. Player VS Computer loss counter\n");
    printf("3. Total losses of players and computer\n");
    printf("4. Reset counters\n");
    printf("5. Return to main menu\n");
    printf("Choose an option: ");
}

// Function to reset counters
void resetCounters() {
    player1Wins = player2Wins = computerWins = 0;
    player1Losses = player2Losses = computerLosses = 0;
    draws = 0; // Reset draw counter
    printf("Counters reset.\n");
}

// Function to ask if the player wants to play again
void playAgain() {
    char choice;
    printf("Do you want to play again? (Y/N): ");
    scanf(" %c", &choice);

// Display final results

    printf("\nFinal Results:\n");
    printf("Player 1 Wins: %d\n", player1Wins);
    printf("Player 1 Looses: %d\n", player1Losses);
    printf("Player 2 Wins: %d\n", player2Wins);
    printf("Computer Wins: %d\n", computerWins);
    printf("Computer Loses: %d\n", computerLosses);
    printf("Draws: %d\n\n", draws);

    if (choice == 'Y' || choice == 'y') {
        startGame();
    } else {
        printf("Returning to main menu...\n");
    }
}