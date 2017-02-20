#include <stdio.h>
#include <stdlib.h>
//This function returns the number of words in the file to the main
// program to determine how big the array has to be.
int getSizeOfFile()
{
	int count = 0, len, j;
        FILE *file;
        file = fopen("words.txt", "r");
        char word[50];

        while(!feof(file))
        {
		fscanf(file, "%49s", word);	//everytime a word is read 		
		count++;			//increment count
        }
	return count - 1;
        fclose(file);
}
//This function fills the array passed as a parameter with the words in the file,
// each word in the file becomes an entry in the array.
void fillArray(char *array[])
{
	int i = 0;
	FILE *file;
	file = fopen("words.txt", "r");
	char word[50];	

        while(!feof(file))
	{
    		fscanf(file, "%127s", word);
		array[i] = (char*)malloc(sizeof(char) * (strlen(word) + 1));	//allocate the exact space in memory for a word.
		strcpy(array[i], word);						//Copy the word into the respective array slot
    		i++;
  	}

	fclose(file);
}
//This function returns 1 if the file is written in english
// and it returns 2 if the file is written in NATO.
int natoOrEnglish(char *arrayInput[], char *arrayNato[], int size)
{	
	char word[50], word2[50];
        char firstChar;
        int index, lenght;
	
	strcpy(word, arrayInput[0]);
	firstChar = word[0];	//gets the ASCII value of the first letter of the word and subtarcts ASCII value of "A" form it.
	
	if ((firstChar >= 97)&&(firstChar <= 122))       //if first character is lower case.
                return 2; //Words are in english.
	
	index = firstChar - 'A';	//If words are in nato, 0 <= index <= 25.
	strcpy (word2, arrayNato[index]);
	lenght = strlen(word2);
	
	if ((strncmp(word, word2, lenght)) == 0)	//compares the coresponding word in the arrayNato
	{						//with the word in the file.
		return 1; //Words are in Nato.
	}
	else
		return 2; //Words are in english.
	
}
//This function converts english words into NATO words.
void englishToNato(char *arrayEng[], char *arrayNato[], int size)
{
	char word[50], word2[50];
        char currentChar;
        int index, lenght, i, j;
	for (i = 0; i < size; i++)	//Loop iterations are equal to the lenght of the file.
        {
		strcpy(word, arrayEng[i]);
		lenght = strlen(word);
		for (j = 0; j < lenght; j++)	//Loop iterations are equal to the lenght of the word. 
		{
			currentChar = word[j];
			if (((currentChar >= 65)&&(currentChar <= 90))||((currentChar >= 97)&&(currentChar <= 122)))	
			{	//Based on ASCII values, if the given character is a letter, proceed.
                		currentChar = toupper(currentChar);
               		 	index = currentChar - 'A';	//Since currentChar was capitalized, 0 <= index <= 25
                		strcpy(word2, arrayNato[index]);	//Copy coresponding word in arrayNato into word2
				printf("%s", word2);
			}
			else 					//if the given character is not a letter.
			{
				printf("\n-->Error: At this point the file contains other characters that\n are not letters. Please edit the file and run the program again.\n");
				return;
			}
        	}
		printf(" ");
	}
	printf("\n");
}
//This function converts NATO words into English words.
void natoToEnglish(char *arrayInput[], int size)
{
	char firstChar, word[50], word2[50];
        int index, lenght, i, j;
        for (i = 0; i < size; i++)		//Loop iterations are equal to the lenght of the file.
        {
		strcpy(word, arrayInput[i]);
                lenght = strlen(word);
                for (j = 0; j < lenght; j++)	//Loop iterations are equal to the lenght of the word.
                {
			firstChar = word[j];
			if (((firstChar >= 65)&&(firstChar <= 90))||((firstChar >= 97)&&(firstChar <= 122)))
                        {		//Based on ASCII values, if the given character is a letter, proceed.
				if ((word[j] <= 90)&&(word[j] >= 65))	//Based on ASCII values, if the given letter uppercase.
				printf("%c", word[j]);		//Print the letter.
			}
			else				//if the given character is not a letter.
			{
                                printf("\n-->Error: At this point the file contains other characters that\n are not letters. Please edit the file and run the program again.\n");
                                return;
                        }

		}
		printf(" ");
	}
	printf("\n");
}
//This function prints the array passed as a parameter to the screen.
void print(char *array[], int size)
{
	int i;
	for (i = 0; i < size; i++)	//Loop iterations are equal to the lenght of the file.
        {
                
		printf ("%s"" ", array[i]);
        }
	printf ("\n");
	free(array[i]);		//free the memory allocated in the array.
	
	printf("-->Translates to: \n");

}

int main()
{
        int size, flag;
	size = getSizeOfFile();
	if(size == 0)
	{
		printf("-->Error: The file is empty, please edit the file and run the program again.\n");
		return 0;
	}

	char *inputWords[size];	
        char *natoWords[26] = {"Alfa", "Bravo", "Charlie", "Delta", "Echo", 
				"Foxtrot", "Golf", "Hotel", "India", "Juliett", 
				"Kilo", "Lima", "Mike", "November", "Oscar", "Papa", 
				"Quebec", "Romeo", "Sierra", "Tango", "Uniform", 
				"Victor", "Whiskey", "X-ray", "Yankee", "Zulu"};
 
	fillArray(inputWords);
        flag = natoOrEnglish(inputWords, natoWords, size);

	if(flag == 1)
	{
		 print(inputWords, size);
		 natoToEnglish(inputWords, size);
	}

	if(flag == 2)
	{
		 print(inputWords, size);
		 englishToNato(inputWords, natoWords, size);
	}
	return 0;
}
