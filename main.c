#include <stdio.h>
#include <math.h>

float CalculateTimeToDestination(float distance, float velocity);
void gasStationMenu();
void fourDigitsProgram();
int countNumberOfDigits(int input);
void checkForZeroDigitInNumber(int input);
void checkForPalindromeNumber(int input);
void luachHakefel(int input);
int verifyInput(int input, int limitOfNumber);
int positiveInput(int input);
int checkForPerfectNumber(int input);
void printAllThePerfectNumbers(int input);
void maxMinAndAveNumbers(int input);

int main() {

    //task no 1:
    float journey = 0;
    float speed = 0;
    printf("The time that will take you to reach your destination is: %.1f minutes.\n \n", CalculateTimeToDestination(journey,speed));

    //task no 2:
    gasStationMenu();

    //task no 3:
    fourDigitsProgram();

    //task no 4:
    int input = 0;

    printf("Please enter a positive number with 5 digits with no use the digit 0:\n");
    scanf("%d", &input);

    while (countNumberOfDigits(input) != 5)
    {
        printf("Oops! It seems like you entered an incorrect number of digits. Please make sure to enter exactly 5 digits. Could you please try again?\n");
        scanf("%d", &input);
    }

    checkForZeroDigitInNumber(input);
    checkForPalindromeNumber(input);

    // task no  5:
    luachHakefel(input);

    // task no 6:
    printAllThePerfectNumbers(input);

    // task no 7:
    maxMinAndAveNumbers(input);

    return 0;
}

float CalculateTimeToDestination(float distance, float velocity)
{
    printf("Please enter the distance (in km) between your current location to your destination...\n");
    scanf("%f",&distance);
    while(distance < 0)
    {
        printf("Error! Please enter a valid distance:\n");
        scanf("%f", &distance);
    }
    printf("Please enter the average of your velocity (in km/h) during your drive...\n");
    scanf("%f",&velocity);
    while(velocity < 0)
    {
        printf("Error! Please enter a valid velocity:\n");
        scanf("%f", &velocity);
    }

    float time = (distance / velocity) * 60;

    return time;
}
void gasStationMenu() {
    char fuelSelection = 0;
    double numberOfLiters = 0;
    double bill = 0;

    printf("Hi and welcome to our gas station! Please choose your fuel...\n");
    printf("For a 98 octane please press: 'S'\n");
    printf("For a 95 octane please press: 'R'\n");
    printf("For Diesel please press: 'D'\n");
    printf("For canceling the fueling please press: 'X'\n");

    do {
        scanf(" %c", &fuelSelection);

        switch (fuelSelection)
        {
            case 'S':
            case 's':
                printf("Thank you! Now please enter the number of liters that you're interested in:\n");
                scanf("%lf", &numberOfLiters);
                bill = numberOfLiters * 7.5;
                printf("Your bill is %.2lf\n", bill);
                break;

            case 'R':
            case 'r':
                printf("Thank you! Now please enter the number of liters that you're interested in:\n");
                scanf("%lf", &numberOfLiters);
                bill = numberOfLiters * 5.85;
                printf("Your bill is %.2lf\n", bill);
                break;

            case 'D':
            case 'd':
                printf("Thank you! Now please enter the number of liters that you're interested in:\n");
                scanf("%lf", &numberOfLiters);
                bill = numberOfLiters * 5.95;
                printf("Your bill is %.2lf\n", bill);
                break;

            case 'X':
            case 'x':
                printf("We sorry to see you leaving. Hope we'll see you next time!\n");
                break;

            default:
                printf("Invalid option. Please try again:\n");
                break;
        }
    } while (!(fuelSelection == 's' || fuelSelection == 'S' || fuelSelection == 'r' || fuelSelection == 'R' ||
               fuelSelection == 'd' || fuelSelection == 'D' || fuelSelection == 'x' || fuelSelection == 'X'));

    if (bill > 150)
    {
        printf("Bravo! You've won a free newspaper! Have a good one :)\n \n");
    }
    else
    {
        printf("Have a good one :)\n \n");
    }
}
void fourDigitsProgram()
{
    int input = 0;
    int choice = 0;
    int digitsNumber = 0;
    int inputSquare = 0;

    printf("Hi! Please enter a number with 1 to 4 digits:\n");
    scanf("%d", &input);
    while(input > 9999 || input < -9999)
    {
        printf("Error! Please enter a number with 1 to 4 digits:\n");
        scanf("%d", &input);
    }
    int evenCheck = input % 2;

    printf("Thanks! Please select one of the following options:\n\n");

    printf("For finding the number of digits in your number, select: 1\n");
    printf("For determine if your number is odd or even, select: 2\n");
    printf("For square your number, select: 3\n");

    scanf("%d", &choice);


    switch (choice)
    {

        case 1:

            digitsNumber = countNumberOfDigits(input);

            printf("Your number has %d digits.\n\n", digitsNumber);
            break;

        case 2:

            if (evenCheck != 0)
            {

                printf("You have chose an odd number.\n\n");
            }

            else
            {
                printf("You have chosen an even number.\n\n");
            }
            break;

        case 3:

            inputSquare = input * input;

            printf("Your square number is: %d.\n\n", inputSquare);

            break;

        default:
            printf("Invalid choice.\n");
            break;
    }
}
int countNumberOfDigits(int input)
{
    if (input < 0)
    {
        input = -input;
    }
    else if (input == 0)
    {
        input = input + 2;
    }
    int digitsNumber = log10(input) + 1;

    return digitsNumber;
}
void checkForZeroDigitInNumber(int input)
{
    int tempInput = input;

    for (int i = 0; i < 5; i++)
    {
        int digit = tempInput % 10;
        if (digit == 0)
        {
            printf("You used the digit zero. It's not what i was asking for... \n\n");
            break;
        }
        else
        {
            tempInput = tempInput / 10;
        }
    }
}
void checkForPalindromeNumber(int input)
{
    int firstDigit = input / 10000;
    int secondDigit = (input / 1000) % 10;
    int fourthDigit = (input % 100) / 10;
    int fifthDigit = input % 10;

    if (firstDigit == fifthDigit && secondDigit == fourthDigit)
    {
        printf("Congratulations! You've written a palindrome number.\n\n");
    }
    else
    {
        printf("Bummer! You haven't written a palindrome number.\n\n");
    }
}
void luachHakefel(int input)
{
    int i = 0;
    int j = 0;
    printf("Please enter the number of the size of your Luach Hakefel.\n");
    scanf("%d", &input);

    input = verifyInput(input, 100);

    for (i = 1; i <= input; ++i) {
        for (j = 1; j <= input; ++j) {
            printf("%d * %d = %d \n", i, j, i * j);
        }
        printf("\n");
    }
}
int verifyInput(int input, int limitOfNumber)
{
    while (input < 1 || input > limitOfNumber)
    {
        printf("Your number is wrong! Please enter a number between 1 to 100\n");
        scanf("%d",&input);
    }
    return input;
}
int positiveInput(int input) {
    while (input <= 0) {
        printf("Your number is wrong! Please enter a positive number\n");
        scanf("%d", &input);
    }
    return input;
}
int checkForPerfectNumber(int input)
{
    input = positiveInput(input);
    int sum = 0;
    for (int i = 1; i < input; ++i) {
        if(input % i == 0)
        {
            sum = sum + i;
        }
    }
    if(sum == input)
    {
        return sum;
    }
    return 0;
}
void printAllThePerfectNumbers(int input)
{
    printf("Please enter a positive number\n");
    scanf("%d", &input);
    int perfectNumber = 0;
    if(checkForPerfectNumber(input) != 0)
    {
        printf("Bravo! Your number is a perfect number.\nJust to know, a perfect number is a positive integer that's equal to the sum of its positive factors. The number 6 is perfect. Its factors are 1, 2, and 3. Adding these factors (1 + 2 + 3) gives you 6. The perfect numbers under 10000 are: \n\n");
    }
    else
    {
        printf("Unfortunately, your number is not a perfect number.\nJust to know, a perfect number is a positive integer that's equal to the sum of its positive factors. The number 6 is perfect. Its factors are 1, 2, and 3. Adding these factors (1 + 2 + 3) gives you 6. The perfect numbers under 10000 are: \n\n");
    }

    for (int i = 1; i < 10000; ++i)
    {
        if(checkForPerfectNumber(i) != 0)
        {
            perfectNumber = checkForPerfectNumber(i);
            printf("%d\n", perfectNumber);
        }
    }
}
void maxMinAndAveNumbers(int input)
{
    int max = 0;
    int min = 0;
    float avg = 0;
    printf("Please enter 20 integer numbers. Start with the first:\n");
    scanf("%d",&input);
    max = input;
    min = input;
    avg = input;

    for (int i = 1; i < 20; ++i)
    {
        printf("Please enter a %dth integer number\n", i + 1);
        scanf("%d",&input);
        if (max < input) max = input;
        if(min > input) min = input;
        avg += input;
    }
    avg = avg/20;
    printf("Your max num is : %d\n", max);
    printf("Your min num is : %d\n", min);
    printf("The average number of your numbers is: %.2f\n", avg);
}