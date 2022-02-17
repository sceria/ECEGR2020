#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------------------------------------------------------------------

void ReverseArray(void)
{
	int theArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	{
		int N = 10;
		for (int* navigator = &theArray[N -1] ; *navigator > 0; navigator--)
			printf("%d, ", *navigator);
	}
}

//--------------------------------------------------------------------------

void students()
{
	printf("How many keikis are in the class?\n"); // keiki is "child" in hawaiian btw
	int keikis;
	scanf("%d", &keikis);
	
	typedef struct
	{
		int ID;
		char firstName[30];
		char lastName[30];
		float GPA;
	}Student;
	
	Student **BANNclass = (Student **)malloc(keikis*sizeof(Student*)); //** is an array of pointers
 
	// Remember that when defining pointers, it must match variable type of what it's pointing at.
	
	
	for (int i = 0; i < keikis; ++i)
	{
		Student* student = (Student*)malloc(sizeof(Student));
		char firstName[30];
		char lastName[30];
		printf("What's the student ID number of this keiki #%d?\n", i+1);
		scanf("%d", &(student->ID));
		printf("First name of keiki #%d?\n", i+1);
		scanf("%s", &firstName);
		printf("Last name of keiki #%d?\n", i+1);
		scanf("%s", &lastName);
		printf("What's this keiki's GPA?\n");
		scanf("%f", &(student -> GPA));
		
		strcpy(student -> firstName, firstName);
		strcpy(student -> lastName, lastName);
		
		BANNclass[i] = student;
	}
	
	
	
	// loop to organize the students by GPA
	for (int i = 0; i < keikis; i++){
		for (int j = 0; j < keikis; j++){
			if (BANNclass[i] -> GPA > BANNclass[j] -> GPA){
				Student* tempor = BANNclass[i];
				BANNclass[i] = BANNclass[j];
				BANNclass[j] = tempor;
			}
		}
	}
	
	// write file
	FILE *pencil = fopen("ClassOfKeikis.txt", "w");
	fprintf(pencil, "Number of Keikis in the class: %d\n", keikis);
	fprintf(pencil, "\n");
	for (int i = 0; i < keikis; i++) {
		fprintf(pencil, "ID Number: %d\n", BANNclass[i] -> ID);
		fprintf(pencil, "First Name: %s\n", BANNclass[i] -> firstName);
		fprintf(pencil, "Last Name: %s\n", BANNclass[i] -> lastName);
		fprintf(pencil, "GPA: %f\n", BANNclass[i] -> GPA);
		fprintf(pencil, "\n");
	}
	fclose(pencil);
}

//--------------------------------------------------------------------------
// reads file created
void reads()
{
	int s;
	FILE *glasses;
	glasses = fopen("ClassOfKeikis.txt", "r");
	printf("Hold on. Im getting my glasses...");
	printf("\n");
	while ((s = getc(glasses)) != EOF){
		putchar(s);
	}
	fclose(glasses);
	printf("\n");
}
//--------------------------------------------------------------------------
void VowelCount(char userinput4vowels[100]) // Menu Option A
{
	int TotalCountVowels = 0;
	for(int magnGlass = 0; magnGlass < strlen(userinput4vowels); magnGlass++) {
		if ((userinput4vowels[magnGlass] == 'a') || (userinput4vowels[magnGlass] == 'A') || (userinput4vowels[magnGlass] == 'e') || (userinput4vowels[magnGlass] == 'E') ||
		(userinput4vowels[magnGlass] == 'i') || (userinput4vowels[magnGlass] == 'I') || (userinput4vowels[magnGlass] == 'o') || (userinput4vowels[magnGlass] == 'O') ||
		(userinput4vowels[magnGlass] == 'u') || (userinput4vowels[magnGlass] == 'U') )
		{
			TotalCountVowels += 1;
		}
	}
	printf("Total number of vowels: %d\n\n", TotalCountVowels);
}

void ConsonantCount(char userinput4cons[100]) // Menu Option B
{
	int TotalCountCons = 0;
	for (int magnGlass = 0; magnGlass < strlen(userinput4cons); magnGlass++) {
		if ( (userinput4cons[magnGlass] == 'a') || (userinput4cons[magnGlass] == 'A') || (userinput4cons[magnGlass] == 'e') || (userinput4cons[magnGlass] == 'E') ||
		(userinput4cons[magnGlass] == 'i') || (userinput4cons[magnGlass] == 'I') || (userinput4cons[magnGlass] == 'o') || (userinput4cons[magnGlass] == 'O') ||
		(userinput4cons[magnGlass] == 'u') || (userinput4cons[magnGlass] == 'U') || (userinput4cons[magnGlass] == ' ') )
		{
			continue;
		}
		else 
		{
			TotalCountCons += 1;
		}
	}
	printf("Total number of consonants: %d\n\n", TotalCountCons);
}

void UpperCase(char UpperConv[100]) // Menu Option C
{
	for (int MarioMushroom; MarioMushroom < strlen(UpperConv); MarioMushroom++) {
		if ( ((UpperConv[MarioMushroom] >= 'A') && (UpperConv[MarioMushroom] <= 'Z')) || (UpperConv[MarioMushroom] == ' '))
		{
			continue;
		}
		else
		{
			UpperConv[MarioMushroom] -= 32;
		}
	}
	printf("\nUppercase Conversion Complete!\n");
}

void LowerCase(char LowerConv[100]) // Menu Option D
{
	for (int Goomba; Goomba < strlen(LowerConv); Goomba++) {
		if ( ((LowerConv[Goomba] >= 'a') && (LowerConv[Goomba] <= 'z')) || (LowerConv[Goomba] == ' '))
		{
			continue;
		}
		else
		{
			LowerConv[Goomba] += 32;
		}
	}
	printf("\nLowercase Conversion Complete!\n");
}

void StrDisp (char CurrStr[100]) // Menu Option E
{
	printf("This is your current String: %s\n", CurrStr);
}

void reverse(char rev[100], int i, int j) // Menu Option R
{
	char tempVal;
    while(i < j)
	{
		tempVal = rev[i];
		rev[i] = rev[j];
		rev[j] = tempVal;
		i++;
		j--;
	}
}


int main()
{
	// Part A
	//ReverseArray();
	
	// Part B
	//students();
	
	// Part C
	reads();
	
	/*
	char Sentence[100];
	printf("Please enter a string:\n");
	scanf("%[^\n]", &Sentence);
	printf("\nThis is your string: %s\n", Sentence);
	printf("\n");
	
	
	printf("A) Count the number of vowels in the string\nB) Count the number of consonants in the string\n");
	printf("C) Convert the string to uppercase\nD) Convert the string to lowercase\n");
	printf("E) Display the current string\nF) Enter another string\n");
	printf("M) Display this menu\nR) Reverse words in string\nX) Exit the program");
	
		
	while(1)
	{
		printf("\nPlease select an option: ");
		char MenuSelection;
		scanf("\n%c", &MenuSelection);
		if (MenuSelection == 'a' || MenuSelection == 'A')
		{
			VowelCount(Sentence);
		}
		else if (MenuSelection == 'b' || MenuSelection == 'B')
		{
			ConsonantCount(Sentence);
		}
		else if (MenuSelection == 'c' || MenuSelection == 'C')
		{
			UpperCase(Sentence);
		}
		else if (MenuSelection == 'd' || MenuSelection == 'D')
		{
			LowerCase(Sentence);
		}
		else if (MenuSelection == 'e' || MenuSelection == 'E')
		{
			StrDisp(Sentence);
		}
		else if (MenuSelection == 'f' || MenuSelection == 'F')
		{
			char garbo;
			printf("Please enter a new string:\n");
			scanf("%d", &garbo);
			scanf("%[^\n]", &Sentence);
		}
		else if (MenuSelection == 'm' || MenuSelection == 'M')
		{
			printf("A) Count the number of vowels in the string\nB) Count the number of consonants in the string\n");
			printf("C) Convert the string to uppercase\nD) Convert the string to lowercase\n");
			printf("E) Display the current string\nF) Enter another string\n");
			printf("M) Display this menu\nR) Reverse words in string\nX) Exit the program");
		}
		else if (MenuSelection == 'r' || MenuSelection == 'R')
		{
			int i, j;
			j=0;
			i=0;
			while(Sentence[j])
			{
				for(j = i; Sentence[j] && Sentence[j] != ' '; j++);
				reverse(Sentence, i, j - 1);
				i = j + 1;
			}
			printf("%s\n",Sentence);
		}
		else if (MenuSelection == 'x' || MenuSelection == 'X')
		{
			break;
		}
		else
		{
			printf("This is an invalid input :(\n");
		}
	}
	printf("\nClosing the program... Goodbye! :)\n");
	 */
	return 0;
}