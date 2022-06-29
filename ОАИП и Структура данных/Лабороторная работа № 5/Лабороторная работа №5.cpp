#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
//Объединение – это поименованная совокупность данных разных типов, размещаемых в одной и той же области памяти, размер которой достаточен для хранения наибольшего элемента.
//В языке C++ существует средство сжатия размера памяти, выделяемого под объявленные в структуре переменные. Это битовые поля в структурах.
//Битовые поля используются для хранения данных целых типов.При использовании битовых полей в размере типа для них выделяется строго определенное количество бит.
using namespace std;

const unsigned int QUANTITY_OF_CLIENTS = 10;
static unsigned int IP = 0;

void createUILine();
void inputData();
void outputData();
void inputClientsByNumber();
void deleteData();

enum acctype { urgent = 1, preferential = 2 };

struct Date
{
	unsigned short int
		day : 5,
		month : 4,
		jear : 11;
};

union Account
{
	int accnum;
	int accvalue;
};

struct Bank
{
	string
		surname,
		name,
		fname,
		acctype;
	Account
		acc;
	Date
		last_modified;
} bank_client[QUANTITY_OF_CLIENTS];

int main()
{
	setlocale(LC_ALL, "RUS");

	createUILine();
	cout << "Банк" << endl;
	createUILine();

	bool choice_1 = false;

	do
	{
		int SIP = 0;

		cout << "Что Вы желаете сделать?" << endl;
		cout << "1 - Ввести данные в систему" << endl;
		cout << "2 - Вывести данные из системы" << endl;
		cout << "3 - Удалить данные из системы" << endl;
		cout << "4 - Выйти из системы" << endl;
		cout << ">> ";

		cin >> SIP;

		switch (SIP)
		{
		case 1:
			inputData();
			break;
		case 2:
			outputData();
			break;
		case 3:
			deleteData();
			break;
		case 4:
			choice_1 = true;
			break;
		default:
			cout << "Введено некорректное значение. Повторите ввод." << endl;
			break;
		}

	} while (!choice_1);

	cout << "Программа успешно завершила выполнение работы." << endl;

	return 0;
}

void createUILine()
{
	for (int i = 0; i < 10; i++)
		printf("-");
	cout << endl;
}

void inputData()
{
	createUILine();
	cout << "Ввод данных" << endl;
	createUILine();

	bool choice_4 = false;

	do
	{
		cout << "Клиент #" << IP + 1 << endl;

		cout << "Введите фамилию вкладчика:" << endl << ">> ";
		cin >> bank_client[IP].surname;

		cout << "Введите имя вкладчика:" << endl << ">> ";
		cin >> bank_client[IP].name;

		cout << "Введите отчество вкладчика:" << endl << ">> ";
		cin >> bank_client[IP].fname;

		int ip = 0;//Задание с перечислениями

		cout << "Выберите тип счёта:" << endl;
		cout << "1 - Срочный" << endl;
		cout << "2 - Льготный" << endl;
		cout << ">> ";

		switch (ip)
		{
		case 1:
			bank_client[IP].acctype = urgent;
			break;
		case 2:
			bank_client[IP].acctype = preferential;
			break;
		default:
			break;
		}
	
		cout << "Введите номер счёта вкладчика:" << endl << ">> "; //задание с union;
		cin >> bank_client[IP].acc.accnum;

		cout << "Введите cумму на счёте вкладчика:" << endl << ">> ";
		cin >> bank_client[IP].acc.accvalue;
		
		int buffer; //задание с битовым полем

		cout << "Введите сегодняшнюю дату (дату последнего):" << endl;
		cout << "День: >> ";
		cin >> buffer;
		bank_client[IP].last_modified.day = buffer;
		cout << "Месяц: >> ";
		cin >> buffer;
		bank_client[IP].last_modified.month = buffer;
		cout << "Год: >> ";
		cin >> buffer;
		bank_client[IP].last_modified.jear = buffer;

		IP++;

		 int ip_2;

		cout << "Желаете ли Вы ввести ещё одну запись?" << endl;
		cout << "1 - Да" << endl;
		cout << "2 - Нет" << endl;
		cout << ">> ";

		cin >> ip_2;

		switch (ip_2)
		{
		case 1:
			break;
		case 2:
			choice_4 = true;
			break;
		default:
			cout << "Введено неверное значение. Повторите ввод." << endl;
			break;
		}
	} while (!choice_4);
}

void outputData()
{
	createUILine();
	cout << "Вывод данных" << endl;
	createUILine();

	bool choice_5 = false;

	do
	{
		cout << "Как Вы желаете вывести данные?" << endl;
		cout << "1 - По номеру счёта" << endl;
		cout << "2 - Назад" << endl;

		int ip_5;
		cin >> ip_5;

		switch (ip_5)
		{
		case 1:
			inputClientsByNumber();
			break;
		case 2:
			choice_5 = true;
			break;
		default:
			cout << "Введено некорректное значение. Повторите ввод." << endl;
			break;
		}
	} while (!choice_5);
}

void inputClientsByNumber()
{
	cout << "Введите номер клиента, которого надо вывести, максимум " << IP << endl;
	cout << ">> ";

	int num;
	cin >> num;
	num--;

	createUILine();
	cout << setw(20) << bank_client[num].surname << setw(20) << bank_client[num].name << setw(20) << bank_client[num].fname << setw(20) << bank_client[num].acc.accnum << setw(20) << bank_client[num].acc.accvalue << setw(20) << setw(6) << bank_client[num].last_modified.day << setw(1) << '.' << bank_client[num].last_modified.month << setw(1) << '.' << bank_client[num].last_modified.jear << endl;
	createUILine();
}

void deleteData()
{
	cout << "Выберите номер записи, которую нужно удалить, максимум " << IP << endl;
	cout << ">> ";

	int ip_7;
	cin >> ip_7;

	ip_7--;

	for (int i = ip_7; i < IP - 1; i++)
	{
		if (ip_7 == IP)
		{
			break;
		}

		bank_client[ip_7].surname = bank_client[ip_7 + 1].surname;
		bank_client[ip_7].name = bank_client[ip_7 + 1].name;
		bank_client[ip_7].fname = bank_client[ip_7 + 1].fname;
		bank_client[ip_7].acctype = bank_client[ip_7 + 1].acctype;
		bank_client[ip_7].acc.accnum = bank_client[ip_7 + 1].acc.accnum;
		bank_client[ip_7].acc.accvalue = bank_client[ip_7 + 1].acc.accvalue;
	}

	IP--;
}

//допы 1-3

//1 доп

//#include <iostream>
//#include<fstream>
//#include <iomanip>
//using namespace std;
//# define str_len 256
//# define size 100
//using namespace std;
//void enter_new();
//void out();
//void search();
//union fornotebook
//{
//	char str[40];
//	int limb;
//};
//struct notebook
//{
//	fornotebook name;
//	fornotebook surname;
//	fornotebook middleName;
//	fornotebook date;
//	fornotebook addres;
//	fornotebook phone;
//	fornotebook place_of_work;
//	fornotebook position;
//};
//notebook people_in_notebook[size];
//int current_size = 0; int choice;
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	cout << "Введите:" << endl;
//	cout << "1-для ввода записи" << endl;
//	cout << "2-для вывода записи" << endl;
//	cout << "3-для поиска информации" << endl;
//	cout << "4-для выхода" << endl;
//	cin >> choice;
//	do
//	{
//		switch (choice)
//		{
//		case 1: enter_new(); break;
//		case 2: out(); break;
//		case 3: search(); break;
//		}
//	} while (choice != 4);
//}
//void enter_new()
//{
//	cout << "Ввод информации" << endl;
//	if (current_size < size)
//	{
//		cout << "Строка номер ";
//		cout << current_size + 1;
//		cout << endl << "Фамилия" << endl;
//		cin >> people_in_notebook[current_size].surname.str;
//		cout << "Имя" << endl;
//		cin >> people_in_notebook[current_size].name.str;
//		cout << "Отчество" << endl;
//		cin >> people_in_notebook[current_size].middleName.str;
//		cout << "Дата рождения: " << endl;
//		cin >> people_in_notebook[current_size].date.str;
//		cout << "Адрес:" << endl;
//		cin >> people_in_notebook[current_size].addres.str;
//		cout << "Номер телефона:" << endl;
//		cin >> people_in_notebook[current_size].phone.limb;
//		cout << "Место работы:" << endl;
//		cin >> people_in_notebook[current_size].place_of_work.str;
//		cout << "Должность:" << endl;
//		cin >> people_in_notebook[current_size].position.str;
//		current_size++;
//
//
//	}
//	else
//		cout << "Введено максимальное кол-во строк";
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void out()
//{
//	int sw, n;
//	cout << "1-вывод 1 строки" << endl;
//	cout << "2-вывод всех строк" << endl;
//	cin >> sw;
//	if (sw == 1)
//	{
//		cout << "Номер выводимой строки: " << endl;
//		cin >> n;
//		cout << endl;
//		cout << "Фамилия" << endl;
//		cout << people_in_notebook[n - 1].surname.str;
//		cout << endl;
//		cout << "Имя" << endl;
//		cout << people_in_notebook[n - 1].name.str;
//		cout << endl;
//		cout << "Отчество" << endl;
//		cout << people_in_notebook[n - 1].middleName.str;
//		cout << endl;
//		cout << "Дата рождения: " << endl;
//		cout << people_in_notebook[n - 1].date.str;
//		cout << "Адрес:" << endl;
//		cout << people_in_notebook[n - 1].addres.str;
//		cout << endl;
//		cout << "Номер телефона:" << endl;
//		cout << people_in_notebook[n - 1].phone.limb;
//		cout << endl;
//		cout << "Место работы:" << endl;
//		cout << people_in_notebook[n - 1].place_of_work.str;
//		cout << endl;
//		cout << "Должность:" << endl;
//		cout << people_in_notebook[n - 1].position.str;
//		cout << endl;
//
//	}
//	if (sw == 2)
//	{
//		for (int i = 0; i < current_size; i++)
//		{
//			cout << "Фамилия" << endl;
//			cout << people_in_notebook[i].surname.str;
//			cout << endl;
//			cout << "Имя" << endl;
//			cout << people_in_notebook[i].name.str;
//			cout << endl;
//			cout << "Отчество" << endl;
//			cout << people_in_notebook[i].middleName.str;
//			cout << endl;
//			cout << "Дата рождения: " << endl;
//			cout << people_in_notebook[i].date.str;
//			cout << "Адрес:" << endl;
//			cout << people_in_notebook[i].addres.str;
//			cout << endl;
//			cout << "Номер телефона:" << endl;
//			cout << people_in_notebook[i].phone.limb;
//			cout << endl;
//			cout << "Место работы:" << endl;
//			cout << people_in_notebook[i].place_of_work.str;
//			cout << endl;
//			cout << "Должность:" << endl;
//			cout << people_in_notebook[i].position.str;
//			cout << endl;
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void search()
//{
//	char name[16];
//	cout << "Введите фамилию:" << "\n";
//	cin >> name;
//	for (int z = 0; z < current_size; z++)
//	{
//		if (strcmp(name, people_in_notebook[z].surname.str) == 0)
//		{
//			cout << "Фамилия" << endl;
//			cout << people_in_notebook[z].surname.str;
//			cout << endl;
//			cout << "Имя" << endl;
//			cout << people_in_notebook[z].name.str;
//			cout << endl;
//			cout << "Отчество" << endl;
//			cout << people_in_notebook[z].middleName.str;
//			cout << endl;
//			cout << "Дата рождения: " << endl;
//			cout << people_in_notebook[z].date.str;
//			cout << "Адрес:" << endl;
//			cout << people_in_notebook[z].addres.str;
//			cout << endl;
//			cout << "Номер телефона:" << endl;
//			cout << people_in_notebook[z].phone.limb;
//			cout << endl;
//			cout << "Место работы:" << endl;
//			cout << people_in_notebook[z].place_of_work.str;
//			cout << endl;
//			cout << "Должность:" << endl;
//			cout << people_in_notebook[z].position.str;
//			cout << endl;
//
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}

//2 доп 

//#include <iostream>
//#include<fstream>
//# define str_len 256
//# define size 100
//using namespace std;
//void enter_new();
//void out();
//void del();
//void search();
//struct notebook
//{
//	char name[str_len];
//	char surname[str_len];
//	char middleName[str_len];
//	unsigned day : 4;
//	unsigned month : 4;
//	unsigned year : 4;
//	char addres[str_len];
//	int phone;
//	char place_of_work[str_len];
//	char position[str_len];
//};
//struct notebook people_in_notebook[size];
//int current_size = 0; int choice;
//notebook all;
//notebook b;
//int l, z, x;
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	cout << "Введите:" << endl;
//	cout << "1-для ввода записи" << endl;
//	cout << "2-для вывода записи" << endl;
//	cout << "3-для удаления" << endl;
//	cout << "4-для поиска информации" << endl;
//	cout << "5-для выхода" << endl;
//	cin >> choice;
//	do
//	{
//		switch (choice)
//		{
//		case 1: enter_new(); break;
//		case 2: out(); break;
//		case 3: del(); break;
//		case 4: search(); break;
//
//
//		}
//	} while (choice != 5);
//}
//void enter_new()
//{
//	cout << "Ввод информации" << endl;
//	if (current_size < size)
//	{
//		cout << "Строка номер ";
//		cout << current_size + 1;
//		cout << endl << "Фамилия" << endl;
//		cin >> people_in_notebook[current_size].surname;
//		cout << "Имя" << endl;
//		cin >> people_in_notebook[current_size].name;
//		cout << "Отчество" << endl;
//		cin >> people_in_notebook[current_size].middleName;
//		cout << "Дата рождения: " << endl;
//		cout << "День:";
//		cin >> l; b.day = l;
//		cout << endl;
//		cout << "Месяц:";
//		cin >> z; b.month = z;
//		cout << endl;
//		cout << "Год:";
//		cin >> x; b.year = x;
//		cout << endl;
//		cout << "Адрес:" << endl;
//		cin >> people_in_notebook[current_size].addres;
//		cout << "Номер телефона:" << endl;
//		cin >> people_in_notebook[current_size].phone;
//		cout << "Место работы:" << endl;
//		cin >> people_in_notebook[current_size].place_of_work;
//		cout << "Должность:" << endl;
//		cin >> people_in_notebook[current_size].position;
//		current_size++;
//
//	}
//	else
//		cout << "Введено максимальное кол-во строк";
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void out()
//{
//	int sw, n;
//	cout << "1-вывод 1 строки" << endl;
//	cout << "2-вывод всех строк" << endl;
//	cin >> sw;
//	if (sw == 1)
//	{
//		cout << "Номер выводимой строки: " << endl; cin >> n; cout << endl;
//		cout << "Фамилия" << endl;
//		cout << people_in_notebook[n - 1].surname;
//		cout << endl;
//		cout << "Имя" << endl;
//		cout << people_in_notebook[n - 1].name;
//		cout << endl;
//		cout << "Отчество" << endl;
//		cout << people_in_notebook[n - 1].middleName;
//		cout << endl;
//		cout << "Дата рождения: " << endl;
//		cout << "День:";
//		cout << l;
//		cout << endl;
//		cout << "Месяц:";
//		cout << z;
//		cout << endl;
//		cout << "Год:";
//		cout << x;
//		cout << endl;
//		cout << "Адрес:" << endl;
//		cout << people_in_notebook[n - 1].addres;
//		cout << endl;
//		cout << "Номер телефона:" << endl;
//		cout << people_in_notebook[n - 1].phone;
//		cout << endl;
//		cout << "Место работы:" << endl;
//		cout << people_in_notebook[n - 1].place_of_work;
//		cout << endl;
//		cout << "Должность:" << endl;
//		cout << people_in_notebook[n - 1].position;
//		cout << endl;
//
//
//	}
//	if (sw == 2)
//	{
//		for (int i = 0; i < current_size; i++)
//		{
//			cout << "Фамилия" << endl;
//			cout << people_in_notebook[i].surname;
//			cout << endl;
//			cout << "Имя" << endl;
//			cout << people_in_notebook[i].name;
//			cout << endl;
//			cout << "Отчество" << endl;
//			cout << people_in_notebook[i].middleName;
//			cout << endl;
//			cout << "Дата рождения: " << endl;
//			cout << "День:";
//			cout << l;
//			cout << endl;
//			cout << "Месяц:";
//			cout << z;
//			cout << endl;
//			cout << "Год:";
//			cout << x;
//			cout << endl;
//			cout << "Адрес:" << endl;
//			cout << people_in_notebook[i].addres;
//			cout << endl;
//			cout << "Номер телефона:" << endl;
//			cout << people_in_notebook[i].phone;
//			cout << endl;
//			cout << "Место работы:" << endl;
//			cout << people_in_notebook[i].place_of_work;
//			cout << endl;
//			cout << "Должность:" << endl;
//			cout << people_in_notebook[i].position;
//			cout << endl;
//
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void del()
//{
//	int d;
//	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
//	cin >> d;
//	if (d != 99)
//	{
//		for (int de1 = (d - 1); de1 < current_size; de1++)
//			people_in_notebook[de1] = people_in_notebook[de1 + 1];
//		current_size = current_size - 1;
//	}
//	if (d == 99)
//		for (int i = 0; i < size; i++)
//			people_in_notebook[i] = all;
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void search()
//{
//	char surname[16];
//	cout << "Фамилия:" << "\n";
//	cin >> surname;
//	for (int q = 0; q < current_size; q++)
//	{
//		if (strcmp(surname, people_in_notebook[q].surname) == 0)
//		{
//			cout << "Фамилия" << endl;
//			cout << people_in_notebook[q].surname;
//			cout << endl;
//			cout << "Имя" << endl;
//			cout << people_in_notebook[q].name;
//			cout << endl;
//			cout << "Отчество" << endl;
//			cout << people_in_notebook[q].middleName;
//			cout << endl;
//			cout << "Дата рождения: " << endl;
//			cout << "День:";
//			cout << l;
//			cout << endl;
//			cout << "Месяц:";
//			cout << z;
//			cout << endl;
//			cout << "Год:";
//			cout << x;
//			cout << endl;
//			cout << "Адрес:" << endl;
//			cout << people_in_notebook[q].addres;
//			cout << endl;
//			cout << "Номер телефона:" << endl;
//			cout << people_in_notebook[q].phone;
//			cout << endl;
//			cout << "Место работы:" << endl;
//			cout << people_in_notebook[q].place_of_work;
//			cout << endl;
//			cout << "Должность:" << endl;
//			cout << people_in_notebook[q].position;
//			cout << endl;
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}

//доп 3

//#include <iostream>
//#include<fstream>
//# define str_len 256
//# define size 100
//using namespace std;
//void enter_new();
//void out();
//void del();
//void search();
//struct teachers
//{
//	char surname_of_teacher[str_len];
//	char exam[str_len];
//	unsigned day : 4;
//	unsigned month : 4;
//	unsigned year : 4;
//
//};
//teachers allTeachers[size];
//teachers all;
//teachers b;
//int choice; int current_size = 0;
//int l, z, q;
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	cout << "Введите:" << endl;
//	cout << "1-для ввода записи" << endl;
//	cout << "2-для вывода записи" << endl;
//	cout << "3-для удаления" << endl;
//	cout << "4-для поиска информации" << endl;
//	cout << "5-для выхода" << endl;
//	cin >> choice;
//	do
//	{
//		switch (choice)
//		{
//		case 1: enter_new(); break;
//		case 2: out(); break;
//		case 3: del(); break;
//		case 4: search(); break;
//
//
//		}
//	} while (choice != 5);
//}
//void enter_new()
//{
//	cout << "Ввод информации" << endl;
//	if (current_size < size)
//	{
//		cout << "Строка номер ";
//		cout << current_size + 1;
//		cout << endl << "Фамилия преподователя" << endl;
//		cin >> allTeachers[current_size].surname_of_teacher;
//		cout << "Экзамен" << endl;
//		cin >> allTeachers[current_size].exam;
//		cout << "Дата" << endl;
//		cout << "День";
//		cin >> l; b.day = l;
//		cout << endl;
//		cout << "Месяц";
//		cin >> z; b.month = l;
//		cout << endl;
//		cout << "Год";
//		cin >> q; b.year = l;
//		current_size++;
//	}
//	else
//		cout << "Введено максимальное кол-во строк";
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void out()
//{
//	int sw, n;
//	cout << "1-вывод 1 строки" << endl;
//	cout << "2-вывод всех строк" << endl;
//	cin >> sw;
//	if (sw == 1)
//	{
//		cout << "Номер выводимой строки: " << endl; cin >> n; cout << endl;
//		cout << "Фамилия преподователя:";
//		cout << allTeachers[n - 1].surname_of_teacher;
//		cout << endl;
//		cout << "Экзамен:";
//		cout << allTeachers[n - 1].exam;
//		cout << endl;
//		cout << "Дата" << endl;
//		cout << "День:";
//		cout << l;
//		cout << endl;
//		cout << "Месяц:";
//		cout << z;
//		cout << endl;
//		cout << "Год:";
//		cout << q;
//		cout << endl;
//
//
//	}
//	if (sw == 2)
//	{
//		for (int i = 0; i < current_size; i++)
//		{
//
//			cout << "Фамилия преподователя:";
//			cout << allTeachers[i].surname_of_teacher;
//			cout << endl;
//			cout << "Экзамен:";
//			cout << allTeachers[i].exam;
//			cout << endl;
//			cout << "Дата" << endl;
//			cout << "День:";
//			cout << l;
//			cout << endl;
//			cout << "Месяц:";
//			cout << z;
//			cout << endl;
//			cout << "Год:";
//			cout << q;
//			cout << endl;
//
//
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void del()
//{
//	int d;
//	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
//	cin >> d;
//	if (d != 99)
//	{
//		for (int de1 = (d - 1); de1 < current_size; de1++)
//			allTeachers[de1] = allTeachers[de1 + 1];
//		current_size = current_size - 1;
//	}
//	if (d == 99)
//		for (int i = 0; i < size; i++)
//			allTeachers[i] = all;
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void search()
//{
//	int day, month, year;
//	cout << "Введите дату" << endl;
//	cout << "День:";
//	cin >> day;
//	cout << endl;
//	cout << "Месяц:";
//	cin >> month;
//	cout << endl;
//	cout << "Год:";
//	cin >> year;
//	cout << endl;
//	for (int f = 0; f < current_size; f++)
//	{
//		if (day == l && month == z && year == q)
//		{
//			cout << "Фамилия преподователя:";
//			cout << allTeachers[f].surname_of_teacher;
//			cout << endl;
//			cout << "Экзамен";
//			cout << allTeachers[f].exam;
//			cout << endl;
//			cout << "Дата" << endl;
//			cout << "День:";
//			cout << l;
//			cout << endl;
//			cout << "Месяц:";
//			cout << z;
//			cout << endl;
//			cout << "Год:";
//			cout << q;
//			cout << endl;
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}