#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

void main()
{	
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("chcp 1251"); - либо SetConsole
	FILE * fp = NULL;
	if ((fp = fopen("test.txt", "r")) == NULL)
	{
		printf("Good bye\n");
		printf("Ошибка при открытии\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("File is created\n");

		/*char letter = 'T';
		fputc(letter, fp);*/
		/*for (int i = 100; i < 256; i++)
		{
			fputc(i, fp);
		}*/
		int codeError = getc(fp);
		//while (codeError != EOF)
		while(!feof(fp) == 1) // если не равен 1, т.е. равен 0 т.е. не достиг конца файла будем считывать 
		{
			printf(" - %c\n", codeError);
			codeError = getc(fp); // функция getc() сама делает fp++;
		}
	}

	//putc(int ch, FILE *fp)

	//fclose(fp);
	if (fclose(fp) == 0)
	{
		printf("File was closed successfully\n");
	}
	else
	{
		printf("ERROR\n");
		exit(EXIT_FAILURE);
	}
		
}