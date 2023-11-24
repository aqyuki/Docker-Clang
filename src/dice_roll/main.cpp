#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // initialize random seed
    time_t seed;
    time(&seed);
    srand(seed);

    // initialize the array by 0
    // this array will hold the number of sum of each dice roll
    int sum[11];
    for(int i=0; i<11; i++) sum[i] = 0;

    // roll the dice 500 times
    for(int i=0; i<500; i++){
        // roll the dice
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;

        // sum the dice
        int sum_dice = dice1 + dice2;
        // increment the sum of the dice
        sum[sum_dice-2]++;
    }

    // print the result with star
    for(int i=0; i<11; i++){
        printf("%2d:%2d ", i+2, sum[i]);
        for(int j=0; j<sum[i]; j++) printf("*");
        printf("\n");
    }
}