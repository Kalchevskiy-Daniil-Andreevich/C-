#include <iostream>
#include<stdio.h>
using namespace std;

//1. Компоненты файла fileA – целые отличные от нуля положительные и отрицательные числа. По-лучить файл fileB, состоящий из положительных чисел. 

void CreateFile()
{
	FILE* f;
	fopen_s(&f, "fileA", "w");
	if (f != NULL)
	{
		printf_s("Файл успешно создан\n");
		fputs("1\n2\n3\n-4\n-5\n-6", f);
		cout << "В файл fileA записнаы числа" << endl;
	}
	else
	{
		cout << "Файл открыт неправильно" << endl;
	}
	fclose(f);
}

void CreateFile2()
{
	FILE* f2;
	fopen_s(&f2, "fileB", "w");
	fclose(f2);
}

void func()
{
	FILE* f;
	FILE* f2;

	fopen_s(&f, "fileA", "r");
	fopen_s(&f2, "fileB", "w");

	char buf[5];

	printf_s("В файл fileB были успешно перенесены символы:\n");

	if (f != NULL && f2 != NULL)
	{
		while (!feof(f))
		{
			fgets(buf, 5, f); //Функция fgets() считывает до num-1 символов из файла stream и помещает их в массив символов, на который указывает buf.
							   //В случае удачи fgets() возвращает str, при неудаче возвращается NULL;
								//чтение из файла одной строки текста полностью
			if (buf[0] != '-')
			{
				fputs(buf, f2);
				printf_s("%s", buf);
			}
		}
	}

	fclose(f);
	fclose(f2);
}

//Компоненты файла f – целые двухзначные числа. Получить файл g, образованный из f включением только чисел больших некоторого числа, вводимого с клавиатуры.

void CreateFile_1()
{
	FILE* file;
	fopen_s(&file, "f", "w");
	if (file != NULL)
	{
		printf_s("Файл успешно создан\n");
		fputs("10\n23\n34\n42\n51\n60", file);
		cout << "В файл f записаны двухзначные числа" << endl;
	}
	else
	{
		cout << "Файл открыт неправильно" << endl;
	}
	fclose(file);
}

void CreateFile_2()
{
	FILE* file2;
	fopen_s(&file2, "g", "w");
	fclose(file2);
}

 void func2()
{
	 FILE* file;
	 FILE* file2;
	 fopen_s(&file, "f", "r");
	 fopen_s(&file2, "g", "w");

	 int ch_1; // переменная, которая будет содержать считываемые числа

	 printf_s("Введите целое двузначное число:\n>>");
	 int c;
	 scanf_s("%d", &c);

	 if (file != NULL && file2 != NULL)
	 {
		 while (!feof(file))
		 {
			 fscanf_s(file, "%d", &ch_1); // сканируем число до разделителя
			 printf_s("Из файла %s успешно извлечено число %d\n", " ", ch_1); // выводим его на экран

			 if (ch_1 > c) // если число, считанное из файла, больше числа, введённого пользователем
			 {
				 printf_s("В файл %s успешно записано число %d, подходящее условиям\n", " ", ch_1); // выводим на экран
				 fprintf_s(file2, "%d\n", ch_1);
			 }
		 }
	 }

	 fclose(file);
	 fclose(file2);
}


 int main()
 {
	 setlocale(LC_ALL, "RUS");
	 cout << "Задания 1" << endl << endl;
	 CreateFile();
	 CreateFile2();
	 func();
	 cout << endl << "Задания 2" << endl << endl;
	 CreateFile_1();
	 CreateFile_2();
	 func2();
	 return 0;
 }


 //допы 1-3


 //int dop1() {
	// setlocale(LC_CTYPE, "ru");
	// FILE* F1;
	// FILE* F2;
	// char str[255];
	// errno_t err;
	// err = fopen_s(&F1, "f1_14.txt", "w");
	// for (int i = 0; i < 6; i++)
	// {
	//	 printf("Строка %d: \n", i + 1);
	//	 gets_s(str);
	//	 fputs(str, F1);
	//	 fputs("\n", F1);
	// }
	// fclose(F1);
	// err = fopen_s(&F1, "f1_14.txt", "r");
	// err = fopen_s(&F2, "f2_14.txt", "w");

	// while (fgets(str, 255, F1) != 0)
	// {
	//	 if (str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5'
	//		 || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || str[0] == '0')
	//	 {
	//		 fputs(str, F2);
	//	 }
	// }
	// fclose(F1);
	// fclose(F2);
	// return 0;
 //}


 //int dop2() {
	// FILE* F1;
	// FILE* F2;
	// char str[255];
	// errno_t err;
	// err = fopen_s(&F1, "F1.txt", "w");
	// for (int i = 0; i < 7; i++)
	// {
	//	 printf("Строка %d: \n", i + 1);
	//	 gets_s(str);
	//	 fputs(str, F1);
	//	 fputs("\n", F1);
	// }
	// fclose(F1);
	// err = fopen_s(&F1, "F1.txt", "r");
	// err = fopen_s(&F2, "F2.txt", "w");
	// while (fgets(str, 255, F1) != NULL)
	// {
	//	 if (str[strlen(str) - 2] == 'A' || str[strlen(str) - 2] == 'a')
	//	 {
	//		 fputs(str, F2);
	//	 }
	// }
	// fclose(F1);
	// fclose(F2);
	// return 0;
 //}


 //int dop3() {
	// FILE* F1;
	// FILE* F2;
	// char str[255];
	// errno_t err;
	// err = fopen_s(&F1, "f1_14.txt", "w");
	// for (int i = 0; i < 6; i++)
	// {
	//	 printf("Строка %d: \n", i + 1);
	//	 gets_s(str);
	//	 fputs(str, F1);
	//	 fputs("\n", F1);
	// }
	// fclose(F1);
	// err = fopen_s(&F1, "f1_14.txt", "r");
	// err = fopen_s(&F2, "f2_14.txt", "w");

	// while (fgets(str, 255, F1) != 0)
	// {
	//	 if (str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5'
	//		 || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || str[0] == '0')
	//	 {
	//		 fputs(str, F2);
	//	 }
	// }
	// fclose(F1);
	// fclose(F2);
	// return 0;
 //}














