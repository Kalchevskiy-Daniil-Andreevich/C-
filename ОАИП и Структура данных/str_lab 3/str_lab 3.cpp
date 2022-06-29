#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;


void createNewFileAndWriteNewFile(string path, string filename)
{
	path += filename;

	cout << "Введите названия файла" << endl;
	getline(cin, filename, '\n');

	ofstream NewFile(path);

	if (!NewFile.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		string input;
		cout << "Введите, что вы хотите ввести в файл:\n";
		getline(cin, input, '\n');

		NewFile << input;

		cout << "Данные записаны в файл" << endl;
	}

	NewFile.close();
}


void readFromFile(string path, string filename)
{
	path += filename;

	ifstream rFile(path);


	if (!rFile.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}

	else
	{
		cout << "Из файла считано: " << endl;
		char ch;
		while (rFile.get(ch))
		{
			cout << ch;
		}
	}
	rFile.close();
}

 
void deleteText()
{
	ofstream fout("", ios_base::trunc);//удалить содержимое файла, если он существует
	fout.close();
	cout <<endl << "Текст из файла неудален!" << endl;
}


void deleteFiles()
{
	if( remove( "" ) != 0 )
	{
		cout << "Ошибка удаления файла";
	}
	else
	{
		cout << "Файл успешно удалён";
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	createNewFileAndWriteNewFile(" ", "file.txt_2");
	readFromFile(" ", "file.txt_2");
	deleteText();
	deleteFiles();
	return 0;
}



