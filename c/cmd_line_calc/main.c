#include <stdio.h>

int main() {
    char user_input[100];

    // This gets the users input and stores it in user input
    fgets(user_input, sizeof(user_input), stdin);

    // clean up the new line char
    user_input[strcspn(user_input, "\n")] = '\0';

    // loop through every character and go through the numbers till there is an operator
    // then get the next group till the next operator and if the next operator ranks higher on the list of pemdas then get to the next operator.
    // if its lower then calc before and continue on if not get next again and so on.

    int i = 0;
    while (user_input[i] != '\0') {
    }

    printf("Input: %s", user_input);
    return 0;
}