#include <stdio.h>

long Factorial(long num) // Cannot receive input values >= 13 since the long type is signed and only goes up to 2 million.
{
	long factorial = 1; // Initialize factorial variable and set it equal to 1 since that will always be the first number to multiply in the operation.
	for (int i = 1; i <= num; i++) // For loop used to go through each number starting from one and ending after iterating through the input value "num."
	{
		factorial = factorial*i; // intial factorial value is multiplied by the iteration and factorial is given that new value. 
	}
	printf("\nThe factorial of %d is %d.\n", num, factorial); 
}

int IsPalindrome(long value) // Function that tests if the input number is a palindrome.
{
	int rev = value; // rev variable used so that it can be modified without affecting the original input.
	int piece; // 
	int initialMultip = 0;
	
	while(rev > 0) // While loop used to reverse the input value.
	{
		piece = rev % 10; // Moves the decimal of the input value over by one place. "piece" variable will hold the value of the digit to the right of the decimal after the move.
		initialMultip = initialMultip*10 + piece; // "InitialMultip" is now used to store the first digit of the reversed number and values of piece will be added to create the reversed number.
		rev /= 10; // rev takes the value of the digits left of the decimal and the loop continues until rev equals zero.
	}
	printf("\n%i is the reversed number of %i.\n", initialMultip, value);
	if(initialMultip == value) // If the reversed number matches the initial input,
	{
		printf("Therefore, %i is a palindrome!\n", value); // the input number is a palindrome.
	}
	else // Else (if the two don't match), 
	{
		printf("Therefore, %i is not a palindrome!\n", value); // the input value is not a palindrome.
	}
} 

int HighestBitSet(int value) // Function that prints the binary number of the decimal value inputted and indicates its most significant bit.
{
	int bit;
	int decimal = value; // "decimal" variable used so we can manipulate the intial input value without losing it.
	int storage[10];
	int i = 1; // Will be used as the size of bits needed for the array.
	int bitCheck;
	int Msb;
	
	while(decimal > 0) // While loop used to convert the decimal value into binary.
	{
		storage[i++] = decimal % 2; // Zeros and ones that are converted into binary are stored into an array.
		decimal = decimal / 2; // decimal then takes on the value of decimal/2 to continue converting the value into binary. Division operation rounds down.
	}
	for(bit = i - 1; bit > 0; bit--) // Prints the values entered in the matrix the way they were entered. First in, first out. 
	{
		printf("%d", storage[bit]); // Prints the corresponding binary value.
	}
	printf(" is the binary value of the decimal %i.\n", value);
	
	for (bitCheck = 0; bitCheck < i; bitCheck++) // For loop used to go through each bit from the right side and moves to the left. Once it finds a 1, that is the most significant bit.
	{
		if((value>>bitCheck) & 1) // If initial input value is moving from the one and comes across a 1,
		{
			Msb = bitCheck; // Most significant bit is assigned that number iteration since that will be the highest bit set.
		}
	}
	printf("The most significant bits is %i.\n", Msb);
}

void ReverseIt(void) // Function reverses order of any 5 numbers inputted by the user.
{
	float guess1;
	float guess2;
	float guess3;
	float guess4; 
	float guess5;
	printf("Please input 5 numbers (with spaces):\n");
	scanf("%f %f %f %f %f", &guess1 , &guess2 , &guess3 , &guess4 , &guess5 ); // Receives the 5 numbers inputted by the user
	float first = guess5; // the following float variables are not needed and are redundant as you can just re-enter the "guess" float variables in reverse order.
	float second = guess4;
	float third = guess3;
	float fourth = guess2;
	float fifth = guess1;
	printf("\nLet's reverse the order!\n%f %f %f %f %f\n", first, second, third, fourth, fifth);
	printf("Ta-da!\nWoah! A wild \"NumberOrderFunction.txt\" appeared in this directory!\n"); 
	
	FILE *pencil; // Used to write a .txt file within the directory.
	pencil = fopen("NumberOrderFunction.txt", "w"); // Opens and essentially "writes" the file titled "NumberOrderFunction.txt"
	if (pencil)
	{
		fprintf(pencil, "Original number order: %f, %f, %f, %f, %f\n", guess1, guess2, guess3, guess4, guess5); // Printing/writing into the .txt file that was created.
		fprintf(pencil, "\nReverse order: %f, %f, %f, %f, %f\n\nNice :D", first, second, third, fourth, fifth);
		fclose(pencil); // Must close file.
	}
	else
	{
		printf("\nError: Unable to open file to write in."); // Error message produced just in case its unable to write.
	}
}

void ReverseItAgain(void) // Function that reads .txt file from previous function and prints the contents of that file.
{
	int glasses; 
	FILE *pencil;
	pencil = fopen("NUmberOrderFunction.txt", "r"); // Opens and reads the following .txt file.
	if(pencil)
	{
		printf("\nHold on, I'm getting my glasses...\n\n");
		while ((glasses = getc(pencil)) != EOF) // While "glasses" variable doesn't reach the end of the file.
		putchar(glasses); // prints contents that were read by the "glasses" function.
		fclose(pencil); // Must close file.
	}
	else
	{
		printf("n\Error: Unable to open file to read."); // Error message produced just in case its unable to read.
	}
}

void Pyramid(int lines) // Creates a pyramid of using asterisks.
{
	int StarAmount;
	FILE *ptrPen; 
	ptrPen = fopen("Pyramid.txt", "w"); // Creates a .txt file to write in. File is located within this directory.
	for (int CurrentLine = 0; CurrentLine < lines; CurrentLine++) // For loop for each line of the pyramid.
	{
		for (int spaces = 0; spaces < lines - CurrentLine+1; spaces++) // For loop for the amount of spaces per line. The amount of spaces per line is equivalent to the total number of lines inputted minus the current line plus one.
		{
			printf(" "); // Prints a space and loops until the amount of spaces surpasses the range of the for loop.
			fprintf(ptrPen, " "); // Same amount of spaces are then written in the .txt file that was opened to write in.
		}
		for (StarAmount = 0; StarAmount < 2*CurrentLine + 1; StarAmount++ )  // Another for loop for the amount of stars to print. Amount of stars per line is equal to 2 times the current line plus one.
		{
			printf("*"); // Prints a star and loops until the amount of stars on the line surpasses the range of the for loop.
			fprintf(ptrPen, "*"); // Same amount of stars are then written in the .txt file that wasopened to write in.
		}
	printf("\n"); // Then goes down a line and reenters the loop to repeat the process until the current line equals the amount of lines inputted by the user.
	fprintf(ptrPen, "\n"); // Goes downa line in the .txt file.
	}
	printf("\nA wild \"Pyramid.txt\" appeared in this directory!\n");
}

int main()
{
	Pyramid(24);
	return 0;
}
