#include<stdio.h>

void SizeofVariables(void) // First function: Size of Variables
{
	char c; // defining a character c.
	short s; // defining a short s.
	int i; // defining an integer i.
	unsigned int ui; // defining an unisgned integer ui.
	unsigned long int ul; // defining an unsigned long integer ul.
	float f; // defining a float f.
	double d; // defining a double d.
	long double ld; // defining a long double d.
	void *ptr; //defining a void ptr which has a pointer on it because of the * symbol.
	
	// sizeof(<some_defined_variable>) is a statement that will find the size in bytes of any variable
	printf("Size of char: %i byte\n", sizeof(c)); // prints "Size of char: __ byte", using the sizeof() statement.
	printf("Size of short: %i bytes\n", sizeof(s)); // prints "Size of short: __ bytes", using the sizeof() statement.
	printf("Size of int: %i bytes\n", sizeof(i)); // prints "Size of int: __ bytes", using the sizeof() statement.
	printf("Size of unsigned int: %i bytes\n", sizeof(ui)); // prints "Size of unsigned int: __ bytes", using the sizeof() statement.
	printf("Size of unsigned long int: %i bytes\n", sizeof(ul)); // prints "Size of unsigned long int: __ bytes", using the sizeof() statement.
	printf("Size of float: %i bytes\n", sizeof(f)); // prints "Size of float: __ bytes", using the sizeof() statement.
	printf("Size of double: %i bytes\n", sizeof(d)); // prints "Size of double: __ bytes", using the sizeof() statement.
	printf("Size of long double: %i bytes\n", sizeof(ld)); // prints "Size of long double: __ bytes", using the sizeof() statement.
	printf("Size of void: %i byte\n", sizeof(*ptr) ); // prints "Size of void: __ byte", using the sizeof() statement.
}

int IsLeapYear(int aYear) // Second Function: Leap Year Tester
{	
	if(aYear % 400 == 0) // First condition is if the year "aYear" is divisible by 400 with no remainders.
	{
		printf("%i is a leap year! :)", aYear); // If the first condition is met, it will print "<aYear> is a leap year! :)" and
		return 1; // will return a 1. And if this condition is not met, the program will see if it meets the other conditions.
	}
	else if(aYear % 100 == 0) // Another condition where if the year "aYear" is divisible by 100 with no remainders.
	{
		printf("%i is not a leap year... :(", aYear); // If this condition is met, it will print "<aYear> is not a leap year... :(" and
		return 0; // will return a 0. 
	}
	else if(aYear % 4 == 0) // Another condition where if the year "aYear" is divisible by four with no remainders.
	{
		printf("%i is a leap year! :)", aYear); // If this condition is met, it will preint "<aYear> is a leap year! :)" and 
		return 1; // will return a 1.
	}
	else if(aYear < 1752) // Another condition where if the year "aYear" is less than 1752. 
	{
		printf("%i is not a leap year... :(", aYear); // If this condition is met, it will print "<aYear> is not a leap year... :(" and
		return 0; // will return a 0.
	}
	else // Then if none of the conditions are met,
	{
		printf("%i is not a leap year... :(", aYear); // it will print "<aYear> is not a leap year... :(" and
		return 0; // will return a 0.
	}
}

int IsVowel(char aLetter) // Third Function: Character Identifier
{
	char vowels[] = {"AaEeIiOoUu"}; // Used an array to store all of the vowels using a C string, including their upper and lower case.
	
	if((aLetter >= 'A' && aLetter <= 'Z') || (aLetter >= 'a' && aLetter <= 'z')) // First condition is if the given character is within the range of A-Z inclusive OR (boolean OR)
	{ // within the range of a-z inclusive.
		for(int i = 0; i < 12; i++){ // For loop searches each character of the C string in the array, and
			if (aLetter == vowels[i]) // if aLetter is one of the letters of the array,
			{
				printf("%c is a vowel!", aLetter); // the program will print "<aLetter> is a vowel!" and
				return 1; // will return 1.
				break; // it will then break out of the for loop
			}
			else if(i == 11) // If the letter is not the same as any of the letters in the array,
			{
				printf("%c is a consonant!", aLetter); // the program will print "<aLetter> is a consonant!" and
				return 0; // will return 0.
			}
		}
	}
	else // And if the given aLetter does NOT lie within A-Z (inclusive) or a-z (inclusive) of the ASCII Alphabet,
	{
		printf("Error! Given character is not an ASCII letter."); // program will print an error message, notifying the user that the character is not an ASCII letter.
	}
}

void ReverseNumber(long aNumber) // Fourth Function: Number Reverser
{
	int modifNumber = aNumber; // Created a new variable to preserve the input's original number and sign.
	int remainder; // Created another variable that will be the remainder of each division operation. This number will eventually be the reverse of the original number.
	
	if(aNumber < 0) // If the input number is less than zero,
	{
		modifNumber /= -1; // the program will divide it by -1 to make it a positive number. modifNumber must be positive in order to enter the while loop and reverse its numbers.
		printf("-"); // Will print the negative sign on the print line, since the original number is negative.
	}
	else // Then if the input number is not negative,
	{
		modifNumber *= 1; // multiply that number by one.
	}
	
	while(modifNumber > 0) // Then modifNumber will enter the while loop to reverse its number. It will stop looping the modifNumber reaches zero from the division operations.
	{
		
		remainder = modifNumber % 10; // When dividing a number by 10, it moves the decimal to the left one position. Therefore, the digit to the right of the decimal after
		printf("%i", remainder); // the move is the remainder. This digit will then be printed.
		modifNumber /= 10; // modifNumber is then assigned to all of the numbers to the left of the decimal and this process will loop and continue until modifNumber = 0. 
	} // This ultimately reverses the order of the input number.

}

int main()
{
	ReverseNumber(-12345); 
	
	return 0;
}

