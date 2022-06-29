#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <algorithm>
//Структура – это пользовательский тип данных, совокупность логически связанных данных различного типа, объединенных под одним идентификатором операция принадлежности. 
using namespace std;

struct Clients
{
	int IdC;
	string Name;
	int Phone;
	string activity;
	string Adress;
};

struct Services
{
	int IdS;
	string service;
	int summa;
	int income;
	string transactionDescription;
	int newsumma;
};

const int Bobik = 2;
const int Oam = 3;
const int Klo = 3;

ofstream lout;
ifstream fin;
int _stateMenu;
int cusdata, numberclients, cusdata2, cusdata3, number, cont, i;
char fims[20], fims2[20];
int CountA[3] = {};

void Menu()
{
	cout << " |-----|----------------------------------------|\n";
	cout << " | 1 | Данные клиентов:                         |\n";
	cout <<" |-----|----------------------------------------|\n";
	cout << " | 2 | Услуги:                                  |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 3 | Допы:                                    |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << "\n";
	cout << "Ваш выбор: ";
	cin >> _stateMenu;
}

void MenuCusData()
{
	cout << " |-----|----------------------------------------|\n";
	cout << " | 1 | Записать информацию о клиентах(консоль): |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 2 | Получить информацию о клиентах(консоль): |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 3 | Удалить информацию о клиентах(консоль):  |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 4 | Записать информацию о клиентах(в файл):  |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 5 | Получить информацию о клиентах(из файл): |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 6 | Удаление файла:                          |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 7 | Удаление содержимого из файла:           |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 8 | Изменение содержимого:                   |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 9 | Фильтрация содержимого:                  |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 10 | Интерполирующий поиск                   |\n";
	cout << " |-----|------------------------------------    |\n";
	cout << " | 11 | Бинарный поиск                          |\n";
	cout << " |-----|------------------------------------    |\n";
	cout << " | 12 | Выполнить сортировку                    |\n";
	cout << " |-----|------------------------------------    |\n";
	cout << "\n";
	cout << "Ваш выбор: ";
	cin >> cusdata;
}

void WriteOfClientsInConsole(Clients* point)
{
	cout << "Запись информации о клиентах: " << endl << endl;
		for (int i = 0; i < Oam; i++)
		{
			cout << "Введите имя " << i + 1 << "-ого клиета: ";
			cin >> point[i].Name;
			cout << endl << "Адресс: ";
			cin >> point[i].Adress;
			cout << endl << "Номер: ";
			cin >> point[i].Phone;
			cout << endl << "Вид деятельности: ";
			cin >> point[i].activity;
			cout << endl;
			point[i].IdC = 1000 + ((i + 1) * 10);
		}
		cout << "Данные введены!" << endl;
		system("pause");
		system("cls");
}

void GetClientsInConsole(Clients* point)
{
	cout << "Получение информации о клиентах: " << endl << endl;
	cout << "Где 1010-данные 1-ого клиента" << endl;
	cout << "Где 1020-данные 2-ого клиента" << endl;
	cout << "Где 1030-данные 3-ого клиента" << endl << endl;
	cout << "Введите номер клиента (10x0): ";
	cin >> number;
	for (int i = 0; i < Oam; i++)
	{
		if (number == point[i].IdC)
		{
			cout << "Название - " << point[i].Name << "\n";
			cout << "Адрес - " << point[i].Adress << "\n";
			cout << "Телефон - " << point[i].Phone << "\n";
			cout << "Вид деятельности - " << point[i].activity << "\n";
		}
	}

	do
	{
		cout << endl << "Хотете продолжть? 1-да; 0-нет "<<endl;
		cin >> cont;
		if (1 == cont)
		{
			cout << endl << "Введите номер клиента (10x0): ";
			cin >> number;
			for (int i = 0; i < Oam; i++)
			{
				if (number == point[i].IdC)
				{
					cout << "Название - " << point[i].Name << "\n";
					cout << "Адрес - " << point[i].Adress << "\n";
					cout << "Телефон - " << point[i].Phone << "\n";
					cout << "Вид деятельности - " << point[i].activity << "\n";
				}
				if (cont == 0)
					break;
			}
		}	
	} while (i > 0);

	do
	{
		cout << endl << "Хотете продолжть? 1-да; 0-нет " << endl;
		cin >> cont;
		if (1 == cont)
		{
			cout << endl << "Введите номер клиента (10x0): ";
			cin >> number;
			for (int i = 0; i < Oam; i++)
			{
				if (number == point[i].IdC)
				{
					cout << "Название - " << point[i].Name << "\n";
					cout << "Адрес - " << point[i].Adress << "\n";
					cout << "Телефон - " << point[i].Phone << "\n";
					cout << "Вид деятельности - " << point[i].activity << "\n";
				}
				if (cont == 0)
					break;
			}
		}
	} while (i > 0);
}

void DeleteOfClientsInConsole(Clients* point)
{
	cout << "Удаление информации о клиентах: " << endl << endl;
	cout << "Где 1010-данные 1-ого клиента" << endl;
	cout << "Где 1020-данные 2-ого клиента" << endl;
	cout << "Где 1030-данные 3-ого клиента" << endl << endl;
	cout << "Введите номер клиента (10x0): ";
	cin >> numberclients;
	for (int i = 0; i < Oam; i++)
	{
		if (numberclients == point[i].IdC)
		{
			point[i].Name = ' ';
			point[i].Adress = ' ';
			point[i].Phone = ' ';
			point[i].activity = ' ';
			point[i].IdC = 1000 + ((i + 1) * 10);
		}
	}
	cout << "Данные удалены!" << endl<<endl;

	do
	{
		cout << "Хотете продолжть? 1-да; 0-нет " << endl;
		cin >> cont;
		if (1 == cont)
		{
			cout<< endl << "Введите номер клиента (10x0): ";
			cin >> number;
			for (int i = 0; i < Oam; i++)
			{
				if (number == point[i].IdC)
				{
					cout << "Название - " << point[i].Name << "\n";
					cout << "Адрес - " << point[i].Adress << "\n";
					cout << "Телефон - " << point[i].Phone << "\n";
					cout << "Вид деятельности - " << point[i].activity << "\n";
				}
				if (cont == 0)
					break;
			}
		}
	} while (i > 0);
	cout << "Данные удалены!" << endl;

	do
	{
		cout << endl << "Хотете продолжть? 1-да; 0-нет " << endl;
		cin >> cont;
		if (1 == cont)
		{
			cout << endl << "Введите номер клиента (10x0): ";
			cin >> number;
			for (int i = 0; i < Oam; i++)
			{
				if (number == point[i].IdC)
				{
					cout << "Название - " << point[i].Name << "\n";
					cout << "Адрес - " << point[i].Adress << "\n";
					cout << "Телефон - " << point[i].Phone << "\n";
					cout << "Вид деятельности - " << point[i].activity << "\n";
				}
				if (cont == 0)
					break;
			}
		}
	} while (i > 0);
	cout << "Данные удалены!" << endl;
}

void WriteOfClientsInFile(Clients* point)
{
	system("cls");
	cout << "Введите название файла: " << endl;
	cin >> fims;
	lout.open(fims, ofstream::app);
	if (!lout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		cout << endl << "Запись информации о клиентах: " << endl << endl;
		for (int i = 0; i < Oam; i++)
		{
			cout << "Введите имя " << i + 1 << "-ого клиета: ";
			cin >> point[i].Name;
			lout << point[i].Name << endl;
			cout << endl << "Адресс: ";
			cin >> point[i].Adress;
			lout << point[i].Adress << endl;
			cout << endl << "Номер: ";
			cin >> point[i].Phone;
			CountA[i] = point[i].Phone;
			lout << point[i].Phone << endl;
			cout << endl << "Вид деятельности: ";
			cin >> point[i].activity;
			lout << point[i].activity << endl;
			point[i].IdC = 1000 + ((i + 1) * 10);
		}
		lout.close();
		cout << endl;
		cout << "Данные введены!" << endl;
		system("pause");
		system("cls");
	}
}

void GetClientsInFile(Clients* point)
{
	ifstream fin;
	cout << "Вы записали информацию в " << fims << endl;
	cout << "Введите названия этого файла: " << endl;
	cin >> fims2;
	fin.open(fims2);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		cout << "Наши данные: " << endl << endl;
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
		fin.close();
	}

}

void removeFile()
{
	char fname[80];
	cout << "Введите названия файла, который хотите удалить:" << endl;
	cin >> fname;
	if (remove(fname))
	{
		cout << "Файл не удален!" << endl;
	}
	else
	{
		cout << "Файл удален!" << endl;
	}
}

void removeTextInFile(Clients* point)
{
	ofstream fout(fims, ios_base::trunc);
	fout.close();
	cout << endl << "Текст из файла удален!" << endl;
}

void changesFile(Clients* point)
{
	int number_2;
	cout << "Введите номер: \n";
	cin >> number_2;
	cout << "Введите имя клиента: " << endl;
	cin >> point[number_2 - 1].Name;
	cout << endl << "Адресс: ";
	cin >> point[number_2 - 1].Adress;
	cout << endl << "Номер: ";
	cin >> point[number_2 - 1].Phone;
	cout << endl << "Вид деятельности: ";
	cin >> point[number_2 - 1].activity;
}

void Filtration(Clients* point)
{
	string tos;
	cout << "Введите имя для поиска: \n";
	cin >> tos;
	for (int i = 0; i < Oam; i++)
	{
		size_t pos = point[i].Name.find(tos);
		if (pos != string::npos)
		{
			cout << "Найден на позиции " << pos << ", строки " << i + 1 << "\n";
		}
		else
			cout << "Не найдено\n";
	}
}

void search_int()
{
	int x = 0; //Текущая позиция массива, с которым сравнивается искомое
	int a = 0; //Левая граница области, где ведется поиск
	int b = Oam - 1;

	int WhatFind;
	cout << "Введите число для поиска:\n";
	cin >> WhatFind;
	bool found;//Переменка-флаг, принимающая True если искомое найдено

	//Цикл поиска по массиву, пока искомое не найдено или пределы поиска еще существуют

	for (found = false; (CountA[a] < WhatFind) && (CountA[b] > WhatFind) && !found; )
	{
		//Вычисление интерполяцией следующего элемента, который будет сравниваться с искомым
		x = a + ((WhatFind - CountA[a]) * (b - a)) / (CountA[b] - CountA[a]);
		//Получение новых границ области, если искомое не найдено
		if (CountA[x] < WhatFind)
			a = x + 1;
		else if (CountA[x] > WhatFind)
			b = x - 1;
		else
			found = true;
	}
	//Если искомое найдено на границах области поиска, показать на какой границе оно
	if (CountA[a] == WhatFind)
		cout << WhatFind << " элемент найден в позиции " << a + 1 << endl;
	else if (CountA[b] == WhatFind)
		cout << WhatFind << " элемент найден в позиции " << b + 1 << endl;
	else
		cout << "Sorry. Not found" << endl;
}

int binary()
{
	int key;

	sort(CountA, CountA + Oam);

	cout << endl << "Введите ключ:\n";

	cin >> key;

	bool flag = false;
	int l = 0;
	int r = Oam - 1;
	int mid;

	while ((l <= r) && (flag != true))
	{
		mid = (l + r) / 2;

		if (CountA[mid] == key) flag = true;
		if (CountA[mid] > key) r = mid - 1;
		else l = mid + 1;
	}

	if (flag) cout << "Индекс элемента " << key << " в массиве равен: " << mid << "\n";
	else cout << "Извините, но такого элемента в массиве нет\n";
	return 0;
}

void sortOrd(Clients* point)
{
	int smallest_id;

	for (int i = 0; i < Oam; i++)
	{
		smallest_id = i;
		for (int j = i + 1; j < Oam; j++)
		{
			if (CountA[j] < CountA[smallest_id])
				smallest_id = j;
		}
		//меняем местами элементы
		swap(CountA[smallest_id], CountA[i]);
		swap(point[smallest_id], point[i]);
	}
	cout << "Данные отсортированы!\n";
	for (int i = 0; i < Oam; i++)
	{
		cout << CountA[i] << "\n";
	}
}

void MenuCusData2()
{
	cout << " |-----|----------------------------------------|\n";
	cout << " | 1 | Введите услугу(консоль):                 |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 2 | Получить информацию об услуге(консоль):  |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 3 | Удалить информацию об услуге(консоль):   |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 4 | Введите услугу(в файл):                  |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 5 | Получить информацию об услуге(из файла): |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 6 | Удаление файла:                          |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 7 | Удаление содержимого из файла:           |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 8 | Изменение содержимого:                   |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 9 | Записать информацию для сортировки:      |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 10 | Сортировка:                             |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << "\n";
	cout << "Ваш выбор: ";
	cin >> cusdata2;
}

void WriteOfService(Services* mourt)
{
	{
		cout << "Запись информации о услугах: " << endl << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "Введите название " << i + 1 << "-ой услуги  " << endl;
			cin >> mourt[i].service;
			cout << endl << "Сумма сделки: ";
			cin >> mourt[i].summa;
			cout << endl << "Доход конторы: ";
			cin >> mourt[i].income;
			cout << endl << "Описание сделки: ";
			cin >> mourt[i].transactionDescription;
			mourt[i].IdS = 2000 + ((i + 1) * 10);
		}
		cout << "Данные введены!" << endl;
		system("pause");
		system("cls");
	}
}

void GetServise(Services* mourt)
{
	cout << "Получение информации о клиентах: " << endl << endl;
	cout << "Где 2010-данные 1-ой услуги" << endl;
	cout << "Где 2020-данные 2-ой услуги" << endl;
	cout << "Где 2030-данные 3-ей услуги" << endl << endl;
	cout << "Введите номер услуги (20x0): ";
	cin >> number;
	for (int i = 0; i < Klo; i++)
	{
		if (number == mourt[i].IdS) {
			cout << "Название - " << mourt[i].service << "\n";
			cout << "Сумма сделки- " << mourt[i].summa << "\n";
			cout << "Доход конторы - " << mourt[i].income << "\n";
			cout << "Описание сделки - " << mourt[i].transactionDescription << "\n";
		}
	}

	do
	{
		cout << endl << "Хотете продолжть? 1-да; 0-нет " << endl;
		cin >> cont;
		if (1 == cont)
		{
			cout << endl << "Введите номер услуги (20x0): ";
			cin >> number;
			for (int i = 0; i < Klo; i++)
			{
				if (number == mourt[i].IdS) {
					cout << "Название - " << mourt[i].service << "\n";
					cout << "Сумма сделки- " << mourt[i].summa << "\n";
					cout << "Доход конторы - " << mourt[i].income << "\n";
					cout << "Описание сделки - " << mourt[i].transactionDescription << "\n";
				}
			}
			if (cont == 0)
				break;
		}
	} while (i > 0);

	do
	{
		cout << endl << "Хотете продолжть? 1-да; 0-нет " << endl;
		cin >> cont;
		if (1 == cont)
		{
			cout << endl << "Введите номер услуги (20x0): ";
			cin >> number;
			for (int i = 0; i < Klo; i++)
			{
				if (number == mourt[i].IdS) {
					cout << "Название - " << mourt[i].service << "\n";
					cout << "Сумма сделки- " << mourt[i].summa << "\n";
					cout << "Доход конторы - " << mourt[i].income << "\n";
					cout << "Описание сделки - " << mourt[i].transactionDescription << "\n";
				}
			}
			if (cont == 0)
				break;
		}
	} while (i > 0);
}

void DeleteOfServise(Services* mourt)
{
	cout << "Удаление информации о клиентах: " << endl << endl;
	cout << "Где 2010-данные 1-ой услуги" << endl;
	cout << "Где 2020-данные 2-ой услуги" << endl;
	cout << "Где 2030-данные 3-ей услуги" << endl << endl;
	cout << "Введите номер услуги (20x0): ";
	cin >> numberclients;
	for (int i = 0; i < Klo; i++)
	{
		if (numberclients == mourt[i].IdS) {
			mourt[i].service = ' ';
			mourt[i].summa = ' ';
			mourt[i].income = ' ';
			mourt[i].transactionDescription = ' ';
			mourt[i].IdS = 2000 + ((i + 1) * 10);
		}
	}
	do
	{
		cout << endl << "Хотете продолжть? 1-да; 0-нет " << endl;
		cin >> cont;
		if (1 == cont)
		{
			cout << endl << "Введите номер услуги (20x0): ";
			cin >> number;
			for (int i = 0; i < Klo; i++)
			{
				if (numberclients == mourt[i].IdS) {
					mourt[i].service = ' ';
					mourt[i].summa = ' ';
					mourt[i].income = ' ';
					mourt[i].transactionDescription = ' ';
					mourt[i].IdS = 2000 + ((i + 1) * 10);
				}
			}
			if (cont == 0)
				break;
		}
	} while (i > 0);

	do
	{
		cout << endl << "Хотете продолжть? 1-да; 0-нет " << endl;
		cin >> cont;
		if (1 == cont)
		{
			cout << endl << "Введите номер услуги (20x0): ";
			cin >> number;
			for (int i = 0; i < Klo; i++)
			{
				if (numberclients == mourt[i].IdS)
				{
					mourt[i].service = ' ';
					mourt[i].summa = ' ';
					mourt[i].income = ' ';
					mourt[i].transactionDescription = ' ';
					mourt[i].IdS = 2000 + ((i + 1) * 10);
				}
			}
			if (cont == 0)
				break;
		}
	} while (i > 0);
}

void WriteOfService_2(Services* mourt)
{
	system("cls");
	cout << "Введите название этого файла: " << endl;
	cin >> fims;
	lout.open(fims, ofstream::app);
	if (!lout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		for (int i = 0; i < Klo; i++)
		{
			cout << "Введите название " << i + 1 << "-ой услуги  " << endl;
			cin >> mourt[i].service;
			lout << mourt[i].service << endl;
			cout << endl << "Сумма сделки: ";
			cin >> mourt[i].summa;
			lout << mourt[i].service << endl;
			cout << endl << "Доход конторы: ";
			cin >> mourt[i].income;
			lout << mourt[i].income << endl;
			cout << endl << "Описание сделки: ";
			cin >> mourt[i].transactionDescription;
			lout << mourt[i].transactionDescription << endl;
			mourt[i].IdS = 2000 + ((i + 1) * 10);
		}
		lout.close();
		cout << endl;
		cout << "Данные введены!" << endl;
		system("pause");
		system("cls");
	}
}

void GetServise_2(Services* mourt)
{
	ifstream fin;
	cout << "Вы записали информацию в " << fims << endl;
	cout << "Введите названия этого файла: " << endl;
	cin >> fims2;
	fin.open(fims2);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		cout << "Наши данные: " << endl << endl;
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
		fin.close();
	}
}

void removeTextInFile(Services* mourt)
{
	ofstream fout(fims, ios_base::trunc);
	fout.close();
	cout << endl << "Текст из файла удален!" << endl;
}

void changesFile(Services* mourt)
{
	int number_2;
	cout << "Введите номер: \n";
	cin >> number_2;
	cout << "Введите новую информацию услуги: " << endl;
	cin >> mourt[number_2 - 1].service;
	cout << endl << "Сумма сделки: ";
	cin >> mourt[number_2 - 1].summa;
	cout << endl << "Доход конторы: ";
	cin >> mourt[number_2 - 1].income;
	cout << endl << "Описание сделки: ";
	cin >> mourt[number_2 - 1].transactionDescription;
}

void writeService_2(Services* xmen)
{
	{
		cout << "Запись информации о услугах: " << endl << endl;
		for (int q = 0; q < Bobik; q++)
		{
			cout << "Введите название " << q + 1 << "-ой услуги  " << endl;
			cin >> xmen[q].service;
			cout << endl << "Старая сумма сделки: ";
			cin >> xmen[q].summa;
			cout << endl << "Новая сумма сделки: ";
			cin >> xmen[q].newsumma;
		}
		cout << "Данные введены!" << endl;
		system("pause");
		system("cls");
	}
}

void sorting(Services* xmen)
{
	int sortChoising;
	cout << "По какому методу будем сортировать: " << endl;
	cout << "1) Старая сумма сделки: " << endl;
	cout << "2) Новая сумма сделки: " << endl;
	cin >> sortChoising;

	if (sortChoising == 1)
	{
		for (int q = 0; q < Bobik; q++)
		{
			for (int j = q + 1; j < Bobik; j++)
			{
				if (xmen[q].summa > xmen[j].summa)
				{
					swap(xmen[q], xmen[j]);
				}
			}
		}
	}
	else
	{
		for (int q = 0; q < Bobik; q++)
		{
			for (int j = q + 1; j < Bobik; j++)
			{
				if (xmen[q].newsumma > xmen[j].newsumma)
				{
					swap(xmen[q], xmen[j]);
				}
			}
		}
	}
	for (int x = 0; x < Bobik; x++)
	{
		cout << xmen[x].service << endl;
		cout << xmen[x].summa << endl;
		cout << xmen[x].service << endl;
		cout << xmen[x].newsumma << endl;
	}
}


void MenuCusData3()
{
	cout << " |-----|----------------------------------------|\n";
	cout << " | 1 | 1 Доп 8 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 2 | 2 Доп 8 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 3 | 3 Доп 8 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 4 | 1 Доп 3 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 5 | 2 Доп 3 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 6 | 3 Доп 3 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 7 | 1 Доп 5 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 8 | 2 Доп 5 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 9 | 3 Доп 5 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 10 | 1 Доп 7 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 11 | 2 Доп 7 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 12 | 3 Доп 7 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 13 | 1 Доп 4 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 14 | 2 Доп 4 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << " | 15 | 3 Доп 4 лаба:                            |\n";
	cout << " |-----|----------------------------------------|\n";
	cout << "\n";
	cout << "Ваш выбор: ";
	cin >> cusdata3;
}
//Это метод, которым садовый гном сортирует линию цветочных горшков. По существу он смотрит на следующий и предыдущий садовые горшки: если они в правильном порядке, он шагает 
//на один горшок вперёд, иначе он меняет их местами и шагает на один горшок назад. Граничные условия: если нет предыдущего горшка, он шагает вперёд; если нет следующего горшка, он закончил."

void gnomesort(Clients* point)//5
{
	int i = 0;

	while (i < Oam)
	{
		if (i == 0)
		{
			i = 1;
		}
		if (point[i - 1].Phone <= point[i].Phone)
		{
			i++;
		}
		else 
		{
			swap(point[i], point[i - 1]);
			i--;
		}
	}
	for (int i = 0; i < Oam; i++)
	{
		cout << point[i].Phone << "\n";
	}
}

//При сортировке вставками массив постепенно перебирается слева направо.При этом каждый последующий элемент размещается так, чтобы он оказался между ближайшими элементами
//с минимальным и максимальным значением.

void InsertionSort(Clients* point)//5
{
	for (int i = 1; i < Oam; ++i)
	{
		int x = point[i].Phone;
		int j = i;
		while (j > 0 && point[j - 1].Phone > x)
		{
			point[j].Phone = point[j - 1].Phone;
			--j;
		}
		point[j].Phone = x;
	}
	for (int i = 0; i < Oam; i++)
	{
		cout << point[i].Phone << "\n";
	}
}

//Шейкерная сортировка отличается от пузырьковой тем, что она двунаправленная : алгоритм перемещается не строго слева направо, а сначала слева направо, затем справа налево.

void ShakerSort(Clients* point)//5
{
	int left = 0;
	int right = Oam - 1;
	while (left <= right)
	{
		for (int i = right; i > left; --i)
		{
			if (point[i - 1].Phone > point[i].Phone)
			{
				swap(point[i - 1], point[i]);
			}
		}
		++left;
		for (int i = left; i < right; ++i)
		{
			if (point[i].Phone > point[i + 1].Phone)
			{
				swap(point[i], point[i + 1]);
			}
		}
		--right;
	}
	for (int i = 0; i < Oam; i++)
	{
		cout << point[i].Phone << "\n";
	}
}

void dop7_1(Services* mourt)//пузырек
{
	for (int i = 0; i + 1 < Klo; i++)
	{
		for (int j = 0; j + 1 < Klo - i; j++)
		{
			if (mourt[j + 1].summa < mourt[j].summa)
			{
				swap(mourt[j], mourt[j + 1]);
			}
		}
	}
	for (int k = 0; k < Klo; k++)
	{
		mourt[k].summa;
	}
}

void dop7_2(Services* mourt)//вставка
{
	int key = 0;
	int i = 0;
	for (int j = 1; j < Klo; j++)
	{
		key = mourt[j].summa;
		i = j - 1;
		while (i >= 0 && mourt[i].summa > key)
		{
			mourt[i + 1] = mourt[i];
			i = i - 1;
			mourt[i + 1].summa = key;
		}
	}
	for (int k = 0; k < Klo; k++)
	{
		mourt[k].summa;
	}
}

void dop7_3(Services* mourt)//выбор
{
	int smallest_id;

	for (int i = 0; i < Klo; i++)
	{
		smallest_id = i;
		for (int j = i + 1; j < Klo; j++) {
			if (mourt[j].summa < mourt[smallest_id].summa)
				smallest_id = j;
		}
		//меняем местами элементы
		swap(mourt[smallest_id], mourt[i]);
	}
}

void dop8_1(Clients* point)
{
	string tos;
	cout << "Введите Адресс для поиска: \n";
	cin >> tos;
	for (int i = 0; i < Oam; i++)
	{
		size_t pos = point[i].Adress.find(tos);
		if (pos != string::npos)
		{
			cout << "Найден на позиции " << pos << ", строки " << i + 1 << "\n";
		}
		else
			cout << "Не найдено\n";
	}
}

void dop8_2(Clients* point)
{
	string tos;
	cout << "Введите вид деятельности для поиска: \n";
	cin >> tos;
	for (int i = 0; i < Oam; i++)
	{
		size_t pos = point[i].activity.find(tos);
		if (pos != string::npos)
		{
			cout << "Найден на позиции " << pos << ", строки " << i + 1 << "\n";
		}
		else
			cout << "Не найдено\n";
	}
}

void dop8_3(Clients* point)
{
	string tos;
	cout << "Введите Имя для поиска: \n";
	cin >> tos;
	for (int i = 0; i < Oam; i++)
	{
		size_t pos = point[i].Name.find(tos);
		if (pos != string::npos)
		{
			cout << "Найден на позиции " << pos << ", строки " << i + 1 << "\n";
		}
		else
			cout << "Не найдено\n";
	}
}

void dop3_1()
{
	string str;
	ofstream ffout("f1.txt");
	ofstream sfout("f2.txt");
	ffout << "Work with files C++" << "\n";
	ffout << "Work with files C++" << "\n";
	ffout << "Not work with files C++" << "\n";
	ffout.close();
	ifstream ffin("f1.txt");
	ifstream sfin("f2.txt");
	if (!ffin.is_open())
		cout << "Ошибка открытия файла!\n";
	else
	{
		while (getline(ffin, str))
		{
			if (str[0] == 'W' && str[1] == 'o' && str[2] == 'r' && str[3] == 'k')
			{
				sfout << str << "\n";
			}
		}
		cout << "Данные успешено скопированы!";
		ffin.close();
		sfin.close();
		ffout.close();
		sfout.close();
	}
}

void dop3_2() 
{
	int k, num = 0, counter = 0;
	string TTTR;
	ifstream file1("file2_1_1.txt");
	ofstream file2("file2_1_2.txt");
	while (getline(file1, TTTR))
	{
		if (TTTR[0] == 'a' || TTTR[0] == 'A')
		{
			file2 << TTTR << '\n';
		}
	}
}

void dop3_3()
{
	int n, k, num = 0, counter = 0;
	cout << "Введите, с какой строки копировать:\n";
	cin >> n;
	cout << "Введите, до какой строки копировать:\n";
	cin >> k;
	string str1;
	ifstream file11("file6_1_1.txt");
	ofstream file21("file6_1_2.txt");
	k--;
	n--;
	while (getline(file11, str1))
	{
		if (num >= n && num <= k)
		{
			file21 << str1 << '\n';
			for (int j = 0; j < 8; j++)
			{
				if (str1[j] == 'q' || str1[j] == 'w' || str1[j] == 'r' || str1[j] == 't' || str1[j] == 'p' || str1[j] == 's' || str1[j] == 'd' || str1[j] == 'f' ||
					str1[j] == 'g' || str1[j] == 'h' || str1[j] == 'j' || str1[j] == 'k' || str1[j] == 'l' || str1[j] == 'z' || str1[j] == 'x' || str1[j] == 'c' ||
					str1[j] == 'v' || str1[j] == 'b' || str1[j] == 'n' || str1[j] == 'm')
					counter++;
			}
		}
		num++;
	}
	cout << counter << " согласных букв.\n";
}

void dop4_1(Services* xmen)
{
	string doc;
	cout << "Введите данные услуги : \n";
	cin >> doc;
	for (int q = 0; q < Klo; q++)
	{
		if ((doc == xmen[q].service))
		{
			cout << endl << "Старая сумма сделки:"<< xmen[q].summa<<endl;
			cout << endl << "Новая сумма сделки: "<< xmen[q].newsumma<<endl;
		}
	}
}

void dop4_2(Services* xmen)
{
	int doc;
	cout << "Введите старую сумму сделки : \n";
	cin >> doc;
	for (int q = 0; q < Klo; q++)
	{
		if ((doc == xmen[q].summa))
		{
			cout << endl << "Данные услуги:" << xmen[q].service << endl;
			cout << endl << "Новая сумма сделки: " << xmen[q].newsumma << endl;
		}
	}
}

void dop4_3(Services* xmen)
{
	int doc;
	cout << "Введите новую сумму сделки : \n";
	cin >> doc;
	for (int q = 0; q < Klo; q++)
	{
		if ((doc ==xmen[q].newsumma ))
		{
			cout << endl << "Старая сумма сделки:" << xmen[q].summa << endl;
			cout << endl << "Данные услуги:" << xmen[q].service << endl;
		}
	}
}

int main()
{
	setlocale(LC_CTYPE, "RU");
	Clients* point = new Clients[3];
	Services* mourt = new Services[3];
	Services* xmen = new Services[2];
	Menu();
	system("cls");
	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 1:
			MenuCusData();
			system("cls");
			switch (cusdata)
			{
			case 1:
				system("cls");
				WriteOfClientsInConsole(point);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				GetClientsInConsole(point);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				DeleteOfClientsInConsole(point);
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				WriteOfClientsInFile(point);
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				GetClientsInFile(point);
				system("pause");
				system("cls");
				break;
			case 6:
				system("cls");
				removeFile();
				system("pause");
				system("cls");
				break;
			case 7:
				system("cls");
				removeTextInFile(point);
				system("pause");
				system("cls");
				break;
			case 8:
				system("cls");
				changesFile(point);
				system("pause");
				system("cls");
				break;
			case 9:
				system("cls");
				Filtration(point);
				system("pause");
				system("cls");
				break;
			case 10:
				system("cls");
				search_int();
				system("pause");
				system("cls");
				break;
			case 11:
				system("cls");
				binary();
				system("pause");
				system("cls");
				break;
			case 12:
				system("cls");
				sortOrd(point);
				system("pause");
				system("cls");
				break;
			default:
				Menu();
				system("cls");
				break;
			}
			system("cls");
			Menu();
			break;

		case 2:
			MenuCusData2();
			system("cls");
			switch (cusdata2)
			{
			case 1:
				system("cls");
				WriteOfService(mourt);	
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				GetServise(mourt);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				DeleteOfServise(mourt);
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				WriteOfService_2(mourt);
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				GetServise_2(mourt);
				system("pause");
				system("cls");
				break;
			case 6:
				system("cls");
				removeFile();
				system("pause");
				system("cls");
				break;
			case 7:
				system("cls");
				removeTextInFile(mourt);
				system("pause");
				system("cls");
				break;
			case 8:
				system("cls");
				changesFile(mourt);
				system("pause");
				system("cls");
				break;
			case 9:
				system("cls");
				writeService_2(xmen);
				system("pause");
				system("cls");
				break;
			case 10:
				system("cls");
				sorting(xmen);
				system("pause");
				system("cls");
				break;
			default:
				Menu();
				system("cls");
				break;
			}
			system("cls");
			Menu();
			break;
		case 3:
			MenuCusData3();
			system("cls");
			switch (cusdata3)
			{
			case 1:
				system("cls");
				dop8_1(point);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				dop8_2(point);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				dop8_3(point);
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				dop3_1();
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				dop3_2();
				system("pause");
				system("cls");
				break;
			case 6:
				system("cls");
				dop3_3();
				system("pause");
				system("cls");
				break;
			case 7:
				system("cls");
				gnomesort(point);
				system("pause");
				system("cls");
				break;
			case 8:
				system("cls");
				InsertionSort(point);
				system("pause");
				system("cls");
				break;
			case 9:
				system("cls");
				ShakerSort(point);
				system("pause");
				system("cls");
				break;
			case 10:
				system("cls");
				dop7_1(mourt);
				system("pause");
				system("cls");
				break;
			case 11:
				system("cls");
				dop7_2(mourt);
				system("pause");
				system("cls");
				break;
			case 12:
				system("cls");
				dop7_3(mourt);;
				system("pause");
				system("cls");
				break;
			case 13:
				system("cls");
				dop4_1(xmen);;
				system("pause");
				system("cls");
				break;
			case 14:
				system("cls");
				dop4_2(xmen);;
				system("pause");
				system("cls");
				break;
			case 15:
				system("cls");
				dop4_3(xmen);;
				system("pause");
				system("cls");
				break;
			}
		}
	}
}

