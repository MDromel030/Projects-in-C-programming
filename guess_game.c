#include <stdio.h>
#include <stdlib.h> //random number generate
#include <time.h>   //seed

int main()
{

    int random, guess;
    int count_guess = 0;

    // seeding function
    srand(time(NULL)); //

    printf("Hey there! Welcome to Guessing Game!!\n");

    random = rand() % 500 + 1; // generating between 0->500//
    do
    {
        printf("\nplease Guess The Number Between [1-500]: ");
        scanf("%d", &guess);
        count_guess++;

        if (guess < random)
        {
            printf("GUESS LARGER THAN THIS ONE!\n");
        }
        else if (guess > random)
        {
            printf("GUESS SMALLER THAN THIS ONE!\n");
        }
        else
        {
            printf("YOO!!CONGRATS$$ YOU HAVE SUCCESFULLY GUESS THE RIGHT ONE IN %d ATTEMPTS!!", count_guess);
        }
    } while (guess != random);

    printf("Thanks for playing");
    printf("Done By (" MDromel030 ")");
}