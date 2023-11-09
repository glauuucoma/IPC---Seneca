/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Davyd Kuleba
Student ID#: 147894224
Email      : dkuleba@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM_MOVES 26
#define MIN_NUM_MOVES 3
#define MINIMUM_PATH 10
#define MAXIMUM_PATH 70
#define MAX_NUM_LIVES 10
#define MIN_NUM_LIVES 1


#include <stdio.h>
struct PlayerInfo {
    int numOfLives;
    char playerSymbol;
    int treasureCount;
    int positions[MAXIMUM_PATH];
    
    
};

struct GameInfo {
    int max_num_move;
    int path_length;
    int bombs[MAXIMUM_PATH];
    int treasure[MAXIMUM_PATH];
};

int main(void)
{
    // Initialize structs
    struct PlayerInfo player;
    struct GameInfo game;
    
    // Initialize variables and constants
    
    
    // Template output
    printf("================================\n         Treasure Hunt!\n================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    
    // User input receiver
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.playerSymbol);
    
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.numOfLives);
        if(player.numOfLives < MIN_NUM_LIVES || player.numOfLives > MAX_NUM_LIVES){
            printf("     Must be between 1 and 10!\n");
        }
    } while (player.numOfLives < MIN_NUM_LIVES || player.numOfLives > MAX_NUM_LIVES); //!!!!!!!!!!!!
    printf("Player configuration set-up is complete\n\n");
    
    
    // Game configuration
    printf("GAME Configuration\n");
    printf("------------------\n");
    
    // User input path length
    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.path_length);
        if(game.path_length < MINIMUM_PATH || game.path_length > MAXIMUM_PATH || game.path_length % 5 != 0){
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (game.path_length < MINIMUM_PATH || game.path_length > MAXIMUM_PATH || game.path_length % 5 != 0);
   
    // User input moves allowed
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.max_num_move);
        if(game.max_num_move < player.numOfLives || game.max_num_move > .75 * game.path_length){
            printf("    Value must be between %d and %d\n", MIN_NUM_MOVES, MAX_NUM_MOVES);
        }
    } while (game.max_num_move < player.numOfLives || game.max_num_move > .75 * game.path_length);
    
    //BOMB placement
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    int i;
    for (i = 0; i < game.path_length; i += 5) {
        printf("   Positions [%2d-%2d]: ", i+1, i+5);
        int j;
        for (j = i; j < i + 5; j++) {
            scanf("%d", &game.bombs[j]);
        }
    }
    printf("BOMB placement set\n");
    
    // Treasure placement
    printf("\nTREASURE Placement");
    printf("\n------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    
    for (i = 0; i < game.path_length; i += 5) {
        printf("   Positions [%2d-%2d]: ", i+1, i+5);
        int j;
        for (j = i; j < i + 5; j++) {
            scanf("%d", &game.treasure[j]);
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.playerSymbol);
    printf("   Lives      : %d\n", player.numOfLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    
    printf("\nGame:\n");
    printf("   Path Length: %d\n", game.path_length);
    printf("   Bombs      : ");
    for (i=0; i<game.path_length; i++) {
        printf("%d", game.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i=0; i<game.path_length; i++) {
        printf("%d", game.treasure[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    return 0;
}
