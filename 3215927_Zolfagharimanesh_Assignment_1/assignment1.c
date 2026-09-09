/*
 * Program: EECS 348 Assignment 1
 * Description: This program asks the user to guess a fixed secret number
 *              between 1 and 10. The user gets up to 3 valid attempts.
 * Input: The integeers the user guesses
 * Output: Tells the user if the guess is too high, too low, or correct,
 *         and prints a final win or lose message.
 * Collaborators: None
 * Sources: Claude, ChatGPT (I used chatgpt to generate an input validation code for this program and I added it to the final code)
 * Author: Ryka Zolfaghari
 * Creation Date: September 8, 2026
 * Revision Date: September 8, 2026
 * Revisions: Added comments and input validation.
 */

#include <stdio.h> // access to printf() and scanf()

int main(void) { // main function where the program starts

    int secret = 7; // store the fixed secret number
    int guess; // store the user's guess
    int attempts = 3; // store the maximum number of valid attempts
    int won = 0; // keep track of whether the user guessed correctly

    // explaining the user what to do
    printf("Guess the number between 1 and 10. You have %d attempts.\n", attempts);

    // allowing the user up to 3 valid guesses
    for (int i = 1; i <= attempts; i++) { // loop through each attempt

        printf("Attempt %d/%d: ", i, attempts); // ask the user for a guess

        // check if the user entered a valid integer
        if (scanf("%d", &guess) != 1) { // check if scanf successfully read an integer or not
            printf("Invalid input. Please enter a number.\n"); // tell the user the input was invalid if it wasn't

            while (getchar() != '\n'); // clear the invalid input from the input buffer

            i--; // do not count invalid input as an attempt
            continue; //go back to the start of the loop
        }

        // check if the guess is inside the allowed range (1-10)
        if (guess < 1 || guess > 10) { // check if the number is outside 1 through 10
            printf("Please enter a number between 1 and 10.\n"); // tell the user the valid range (1-10)

            i--; // do not count an out-of-range guess as an attempt
            continue; // go back to the start of the loop
        }

        // check if the guess is correct, too high, or too low
        if (guess == secret) { // check if the guess matches the secret number
            won = 1; // record that the user won
            break; // stop the loop immediately
        } else if (guess > secret) { // check if the guess is too high
            printf("Too high!\n"); // tell the user the guess is too high
        } else { // none of the above so it means the guess is lower than the secret number
            printf("Too low!\n"); // tell the user the guess is too low
        }
    }

    // print the final result
    if (won) { // check if the user won
        printf("Correct! You guessed the number.\n"); // print the win message
    } else { // the user did not win so
        printf("You lose! The number was %d.\n", secret); // print the lose message
    }

    return 0; // end the program successfully
}
