#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//1. Скопировать из файла FILE1 в файл FILE2 все строки, которые не содержат цифры. Подсчитать количе-ство строк, которые начинаются на букву «А» в файле FILE2.

void createNewFile(string path, string filename) 
{
	path += filename;

	ofstream NewFile(path);
	
	NewFile.open(filename);

	if (!NewFile.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		cout << "Файл " << path << " открыт" << endl;
	}

	NewFile.close();
}

void writeInFile(string path, string filename, string s_in_file)
{
	path += filename;

	ofstream NewFile1(path, ios_base::app);

	if (!NewFile1.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		cout << "Выполняется запись: "<< endl << s_in_file << endl;
		NewFile1 << s_in_file << endl;
	}

	NewFile1.close();
}

void readFromFile(string path, string filename)
{
	path += filename;

	string fstring;
	int counter = 0;

	ifstream rFile(path);

	while (getline(rFile, fstring))
	{
		bool flag = false;

		for (int i = 0; i < fstring.size(); i++)
		{
			if (isdigit(fstring[i]))
			{
				cout << "Нельзя записать: " << fstring << endl;
				flag = true;
				break;
			}
		}

		if (flag == false)
		{

			if (fstring[0] == 'A' || fstring[0] == 'a')
			{
				counter++;
			}

			writeInFile("", "FILE2.txt", fstring);
		}
	}

	cout << "Количество строк с первой буквой А в FILE2.txt равно " << counter << endl;

	rFile.close();
}


//2. Ввести с клавиатуры строку, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл. Прочитать из файла данные, подсчитать количество символов в самом длинном слове и вывести его.

void createNewFile_2(string path, string filename)
{
	path += filename;

	ofstream NewFile(path);

	if (!NewFile.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		cout << "Файл " << path << " открыт" << endl;
	}

	NewFile.close();
}

void writeInFile_2(string path, string filename)
{
	path += filename;

	ofstream NewFile1(path, ios_base::app);

	if (!NewFile1.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		char str[256];

		cout << "Введите строку:" << endl;
		gets_s(str);

		char ch;

		NewFile1 << str << endl;

		cout << "Cтрока введена в файл" << endl;
	}

	NewFile1.close();
}

void readFromFile_2(string path, string filename)
{
	path += filename;

	// getline() способен считывать слова до определённого ограничения, например, пробела
	// Так можно считать все слова, кроме последнего, поскольку там стоит '\n'
	// Найти количество символов в последнем слове можно по формуле:
	// Количество_символов_в_последнем_слове = кол-во_всех_символов_в_строке - кол-во_символов_во_всех_предыдущих_словах - кол-во_пробелов

	// Объявляем и инициализируем переменные:

	int max_word_counter = 0; // количество символов в самом большом слове
	int word_counter = 0; // количество символов в наибольшем слове, кроме последнего
	int all_string_counter = 0; // количество символов во всей строке
	int words_counter = 0; // количество символов во всех словах, кроме последнего
	int spaces_counter = 0; // количество пробелов в строке
	int buf_counter; // переменная, отвечающая за то, чтобы считать все слова из строки, кроме последнего
	int last_word_counter = 0; // количество символов в последнем слове

	string fstring;

	ifstream rFile(path);

	while (getline(rFile, fstring)) // находим число символов во всей строке
	{
		all_string_counter = fstring.length();
		cout << "Строка содержит " << all_string_counter << " символов." << endl;
	}

	rFile.close();

	ifstream rFile2(path);

	while (getline(rFile2, fstring)) // находим число всех пробелов в строке
	{
		for (int i = 0; i < fstring.length(); i++)
		{
			if (fstring[i] == ' ')
				spaces_counter++;
		}
		cout << "Строка содержит " << spaces_counter << " пробелов." << endl;
	}

	rFile2.close();

	buf_counter = spaces_counter; // присваиваем значение вспомогательной переменной, чтобы считать все слова, кроме последнего

	ifstream rFile3(path);

	while (getline(rFile3, fstring, ' ') && buf_counter-- != 0) // ищем количество символов в самом длинном слове, кроме последнего (если бы мы не установили buf_counter, считывалось бы и последнее слово, что нам не нужно))
	{
		cout << "Считано: " << fstring << endl;
		if (word_counter < fstring.length())
		{
			word_counter = fstring.length();
		}

		words_counter += fstring.length(); // находим общее число символов в словах, кроме последнего (без учёта пробелов)
	}

	cout << "Все слова, кроме последнего, в сумме дают " << words_counter << " символов." << endl;
	cout << "Самое длинное слово, кроме последнего, содержит " << word_counter << " символов." << endl;

	last_word_counter = all_string_counter - words_counter - spaces_counter; // считаем число символов в последнем слове

	cout << "Последнее слово содержит " << last_word_counter << " символов." << endl;

	// Далее используется тернарный оператор (ещё один оператор условия)
	// Он имеет синтаксис (условие) ? (сделать_если_истина) : (сделать_если_ложь)
	// Его используют редко, потому что грамоздкий и, по сути, ничем не отличается от if-else, но иногда он более удобный

	(word_counter < last_word_counter) ? (max_word_counter = last_word_counter) : (max_word_counter = word_counter);

	rFile3.close();

	cout << "Количество символов в самом длинном слове: " << max_word_counter << endl;
}



int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Задания 1" << endl << endl;
	createNewFile("", "FILE1.txt");
	createNewFile("", "FILE2.txt");
	writeInFile("", "FILE1.txt", "My name is Danik\nI'm 17\nI live in Minsk\nI like C++\nI am using visual studio 2019\nAn ordinary boy");
	readFromFile("", "FILE1.txt");
	cout <<endl<< "Задания 2" << endl << endl;
	createNewFile_2("", "File.txt");
	writeInFile_2("","File.txt");
	readFromFile_2("", "file.txt");
	return 0;
}


//допы 1-3

//Доп 1

// int main()
//{ 
// setlocale(LC_ALL, "ru"); 
// int n1, n2, num = 0, counter = 0; 
// string str; 
// cout << "Введите, с какой строки копировать:\n"; 
// cin >> n1; 
// cout << "Введите, до какой строки копировать:\n"; 
// cin >> n2; 
// ifstream file1("file15_1_1.txt"); 
// ofstream file2("file15_1_2.txt"); 
// n1--; 
// n2--; 
// while (getline(file1, str)) 
// { 
//  if (num >= n1 && num <= n2) 
//  { 
//   if (str[0] == 'C' || str[0] == 'c') 
//   { 
//    file2 << str << '\n'; 
//    for (int i = 0; i < str.length(); i++) 
//    { 
//     if (str[i] == ' ') 
//     { 
//      counter++; 
//     } 
//    } 
//   } 
//  } 
//  num++; 
// } 
// cout << "В первой строке второго файла " << ++counter << " слова.\n"; 
//} 

//Доп 2

//int main() 
//{ 
// setlocale(LC_ALL, "ru"); 
// int k, num = 0, counter = 0; 
// string str; 
// ifstream file1("file2_1_1.txt"); 
// ofstream file2("file2_1_2.txt"); 
// while (getline(file1, str)) 
// { 
//  if(str[0] == 'a' || str[0] == 'A') 
//  { 
//   file2 << str << '\n'; 
//  } 
// } 
//} 

//Доп 3

//string fileOut(string* pStrOut)
//{
//	ofstream file1("file15_2_1.txt");
//	file1 << *pStrOut;
//	file1.close();
//	return *pStrOut;
//}
//
//string fileIn(string* pStrIn)
//{
//	string StrIn, min = "0000000";
//	short counter = 1, SequenceNum;
//	ifstream file2("file15_2_1.txt");
//	while (file2)
//	{
//		file2 >> StrIn;
//		if (StrIn.length() < min.length())
//		{
//			min = StrIn;
//			SequenceNum = counter;
//		}
//		counter++;
//	}
//	cout << "Порядковый номер самого короткого слова: " << SequenceNum << '\n';
//	file2.close();
//	return StrIn;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	string strOut, strIn;
//	string* pStrOut = &strOut, * pStrIn = &strIn;
//	cout << "Введите группы цифр, разделенные пробелом:\n";
//	getline(cin, strOut);
//	fileOut(pStrOut);
//	fileIn(pStrIn);
//}