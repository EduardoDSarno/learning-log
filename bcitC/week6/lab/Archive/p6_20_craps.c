// Eduardo Sarno
// Feb 16,2026

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define LOSING_POINT_NUMBER 7
#define GAMES_TO_PLAY 1000
#define MAX_ROLL_ROUND 21
// prototypes
enum Craps{Won,Lost,Continue};
int roll_dice();

struct Game{
    int round;
    int sum;
    enum Craps state;
};
struct Game play_point(struct Game game);
struct Game play(struct Game game);

int main() {
    // add 1 to go from 1-21
    int wins  [MAX_ROLL_ROUND + 1];
    int losses[MAX_ROLL_ROUND + 1];

    // set all counters to zero
    for (int i = 0; i <= MAX_ROLL_ROUND; i++) {
        wins[i] = 0;
        losses[i] = 0;
    }

    int total_wins = 0;
    int total_rolls = 0;

    // seed 
    srand(time(NULL));

    // play gemestoplay times
    for (int i = 0; i < GAMES_TO_PLAY; i++) {
        // start fresh
        struct Game game = {0, 0, Continue};
        game = play(game);

        // fwhich roll does the game is
        int dice_roll = game.round;
        if (dice_roll > MAX_ROLL_ROUND) {
            dice_roll = MAX_ROLL_ROUND;
        }

        // record the result
        if (game.state == Won) {
            wins[dice_roll]++;
            total_wins++;
        } else {
            losses[dice_roll]++;
        }

        total_rolls = total_rolls + game.round;
    }

    // print the report
    printf("Games won or lost after the 21th roll\n");
    printf("are displayed as the 21th roll.\n\n");

    for (int roll = 1; roll <= MAX_ROLL_ROUND; roll++) {
        printf("%3d games won and %3d games lost on roll %d.\n",
               wins[roll], losses[roll], roll);
    }

    /// print % of win
    double win_percent = (100.0 * total_wins) / GAMES_TO_PLAY;
    double avg_length = (double)total_rolls / GAMES_TO_PLAY;

    printf("\nThe chances of winning are %d/%d = %.2f%%\n",
           total_wins, GAMES_TO_PLAY, win_percent);
    printf("The average game length is %.2f rolls.\n", avg_length);

    return 0;
}



/*create game struct to be easier for my visualization*/
struct Game play(struct Game game){
    game.sum = roll_dice();
    game.round = 1;

    switch (game.sum) {
        case 7:
        case 11:
            game.state = Won;
            break;
        case 2:
        case 3:
        case 12:
            game.state = Lost;
            break;
        default:
            game = play_point(game);
            break;
    }

    return game;
}

/* created this to break the process down so hte fucntion is not too big and nested*/
struct Game play_point(struct Game game) 
{
    int point  = game.sum;

    while (game.state == Continue) 
    {
        game.sum = roll_dice();
        game.round++;

        if (game.sum == point) {

            game.state = Won;
            break;
        }
        if (game.sum == LOSING_POINT_NUMBER) {
            // lose
            game.state = Lost;
            break;
        }
    }
    return game;
}

int roll_dice() {
    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6) + 1;

    int result = dice1 + dice2;
    return result;
}
