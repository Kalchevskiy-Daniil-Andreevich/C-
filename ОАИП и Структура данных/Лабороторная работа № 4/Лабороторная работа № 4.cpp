#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
//Для доступа к членам структуры 
//Структура – это пользовательский тип данных, совокупность логически связанных данных различного типа, объединенных под одним идентификатором операция принадлежности. 

using namespace std;


struct PersonalLibrary
{
	string BookAuthor;
	string Title;
	string PublishingHouse;
	string LibrarySection;
	string Origin;
	string AvailabilityOfBook;
};

const short N = 20;

void input(PersonalLibrary library[])
{
	int num;

	do
	{
		cout << "Введите количество книг (не более " << N << "): ";
		cin >> num;
	} 

	while (num < 1 || num > N);
	fflush(stdin);

	for (int i = 0; i < num; i++)
	{
		cout << "\tКнига №" << i + 1 << endl;
		cout << "Введите Автора книги:\n";
		cin >> library[i].BookAuthor;
		cout << "Введите Название:\n";
		cin >> library[i].Title;
		cout << "Введите Издательство:\n";
		cin >> library[i].PublishingHouse;
		cout << "Введите Раздел библиотеки:\n";
		cin >> library[i].LibrarySection;
		cout << "Введите Происхождения:\n";
		cin >> library[i].Origin;
		cout << "Наличие книги в данный момент:\n";
		cin >> library[i].AvailabilityOfBook;
		cout << "\n\n";
	}
}


void output(PersonalLibrary library[])
{
	int BookNum;
	cout << "Введите номер книги, которую вы хотите вывести:\n";
	cin >> BookNum;
	int i = BookNum - 1;
	cout << "\tКнига №" << BookNum << '\n';
	cout << "Автора книги: " << library[i].BookAuthor << '\n';
	cout << "Название: " << library[i].Title << '\n';
	cout << "Издательство: " << library[i].PublishingHouse << '\n';
	cout << "Раздел библиотеки: " << library[i].LibrarySection << '\n';
	cout << "Происхождения: " << library[i].Origin << '\n';
	cout << "Наличие книги в данный момент: " << library[i].AvailabilityOfBook << "\n\n\n";
}


void deleteBook(PersonalLibrary library[])
{
	int numCin;
	cout << "Введите порядковый номер книги, информацию о которой Вы хотите удалить:\n";
	cin >> numCin;
	cout << '\n';
	int i = numCin - 1;
	library[i].BookAuthor = ' ';
	library[i].Title = ' ';
	library[i].PublishingHouse = ' ';
	library[i].LibrarySection = ' ';
	library[i].Origin = ' ';
	library[i].AvailabilityOfBook = ' ';
	cout << '\n';
}


void search(PersonalLibrary library[])
{
	string numSearch;
	cout << "Введите книгу автора:\n";
	cin >> numSearch;
	for (int i = 0; i < N; i++)
	{
		if (numSearch == library[i].BookAuthor)
		{
			cout << " Книга № " << i + 1 << ": Автор: " << library[i].BookAuthor << '\n';
		}
	}
	cout << "\n\n";
}


void WriteInFile(PersonalLibrary library[])
{
	string buf;
	int num;

	do
	{
		cout << "Введите количество книг (не более " << N << "): ";
		cin >> num;
	}

	while (num < 1 || num > N);
	fflush(stdin);

	ofstream File1("file.txt");
	
	for (int i = 0; i < num; i++)
	{
		cout << "\tКнига №" << i + 1 << '\n';
		File1 << "\tКнига №" << i + 1 << '\n';
		cout << "Введите Автора книги:\n";
		File1 << "Автора книги: ";
		cin >> library[i].BookAuthor;
		File1 << library[i].BookAuthor;
		cout << "Введите Название:\n";
		File1 << "\nНазвание: ";
		cin >> library[i].Title;
		File1 << library[i].Title;
		cout << "Введите Издательство:\n";
		File1 << "\nИздательство: ";
		cin >> library[i].PublishingHouse;
		File1 << library[i].PublishingHouse;
		cout << "Введите Раздел библиотеки:\n";
		File1 << "\nРаздел библиотеки: ";
		cin >> library[i].LibrarySection;
		File1 << library[i].LibrarySection;
		cout << "Введите Происхождения:\n";
		File1 << "\nПроисхождения: ";
		cin >> library[i].Origin;
		File1 << library[i].Origin;
		cout << "\nНаличие книги в данный момент: ";
		File1 << "\nНаличия: ";
		cin >> library[i].AvailabilityOfBook;
		File1 << library[i].AvailabilityOfBook << "\n\n";
	}
	cout << "\n\n"; 
}


void ReadFromFile(PersonalLibrary library[])
{
	string strInf;
	ifstream File1("file.txt");
	while (File1)
	{
		cout<< endl << "Из файла считано: " << endl << endl;
		getline(File1, strInf);
		cout << strInf << "endl";
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	short choose;
	PersonalLibrary library[N];
	do
	{
		cout << "Выберите, что сделать:\n1 — ввод элементов структуры с клавиатуры;\n2 — вывод элементов стуктуры в консольное окно;"
			    "\n3 — удаление заданной структурированной переменной; \n4 — поиск информации; \n5 — запись информации в файл; \n6 — чтение данных из файла; \n7 — выход из программы.\n";
		cin >> choose;
		switch (choose)
		{
		case 1: input(library);
			break;
		case 2: output(library);
			break;
		case 3: deleteBook(library);
			break;
		case 4: search(library);
			break;
		case 5: WriteInFile(library);
			break;
		case 6: ReadFromFile(library);
			break;
		}
	}
	while (choose != 7);
}
//Доп 1 
///*Определить структуру для представления информации о сданных студентом экзаменах, содержащую поля: ФИО студента,
//число экзаменов, полученные оценки. Определить функции для обработки отдельного объекта (например, для проверки,
//сданы ли все экзамены на 4 и 5). Написать функцию для обработки массива структур. В результате обработки требуется
//вычислить характеристику успеваемости студентов, то есть отношение числа студентов, сдавших экзамены на 4 и 5, к
//общему числу студентов, в процентах. */
//
//struct Student {
//	string name;
//	int maths;
//	int physics;
//	int english;
//	int oap;
//	int lg;
//};
//
//void exams(Student* students, int SIZE) {
//
//	int numStudents = 0;
//	for (int i = 0; i < SIZE; ++i) {
//
//		if ((students[i].maths == 5 || students[i].maths == 4) &&
//			(students[i].physics == 5 || students[i].physics == 4) &&
//			(students[i].english == 5 || students[i].english == 4) &&
//			(students[i].oap == 5 || students[i].oap == 4) &&
//			(students[i].lg == 5 || students[i].lg == 4))
//		{
//			cout << i << ") Студент: " << students[i].name << " сдал экзамены на 4 или 5" << endl;
//			numStudents++;
//		}
//		else cout << i << ") Студент: " << students[i].name << " не сдал экзамены на 4 или 5" << endl;
//	}
//	cout << "Сотношение студентов, сдавших экзамен на 4 или 5, ко всем студентам " << ((double)numStudents / (double)SIZE) * 100 << " % " << endl;
//}
//
//void displayInfo(Student* students, int SIZE) {
//	for (int i = 0; i < SIZE; ++i) {
//		cout << "Имя студента: " << students[i].name << endl;
//		cout << "Математика: " << students[i].maths << endl;
//		cout << "Физика: " << students[i].physics << endl;
//		cout << "Английский: " << students[i].english << endl;
//		cout << "ОАП: " << students[i].oap << endl;
//		cout << "ЯП: " << students[i].lg << endl;
//		cout << "///////////////////////////////////////" << endl;
//	}
//}
//
//void  ifileStud(Student* students, int SIZE) {
//	ifstream fin("studentsInfo.txt");
//	if (!fin.is_open()) {
//		cout << "Не удаётся открыть файл для чтения " << endl;
//		exit(EXIT_FAILURE);
//	}
//	for (int i = 0; i < SIZE; ++i) {
//		fin >> students[i].maths;
//		fin >> students[i].physics;
//		fin >> students[i].english;
//		fin >> students[i].oap;
//		fin >> students[i].lg;
//		fin >> students[i].name;
//	}
//	cout << "\nВыведена информация из файла studentsInfo.txt\n";
//}
//
//void dop1()
//{
//	setlocale(LC_CTYPE, "ru");
//	const int SIZE = 7;
//	Student students[SIZE];
//	short choose;
//	do {
//		cout << "\nВыберите, что сделать:\n1 — проверить, сколько студентов положительно сдали экзамены;\n2 — вывести в консоль информацию о студенте;\n3 — вывести информацию из файла;\n4 — выход из программы.\n";
//		cin >> choose;
//		switch (choose)
//		{
//		case 1: exams(students, SIZE); break;
//		case 2: displayInfo(students, SIZE); break;
//		case 3: ifileStud(students, SIZE); break;
//		case 4: main(); break;
//		}
//	} while (choose != 4);
//}
//
//
//
//
//
//
//
////Доп 2  
///*Описать структуру с именем TRAIN, содержащую поля: названия пункта назначения,
//номер поезда, время отправления. Написать программу, выполняющую ввод с клавиатуры
//данных в массив, состоящий из восьми элементов типа TRAIN (за-писи должны быть размещены
//в алфавитном порядке по названиям пунктов назначения); вывод на экран информации о поездах,
//отправляющихся после введенного с клавиатуры времени (если таких поездов нет, то вывести сообщение об этом).*/
//
//struct Train {
//	string Place;// место назначения
//	int NumTrain; // номер поезда
//	string time; // время отбытия 
//};
//
//
//bool compTrain(Train lhs, Train rhs)
//{
//	return lhs.Place < rhs.Place;
//}
//
//void displayTrain(Train* trains, int SIZE) {
//	sort(trains, trains + SIZE, compTrain);
//
//	for (int i = 0; i < SIZE; ++i)
//	{
//		cout << "Номер поезда: " << trains[i].NumTrain << "\t";
//		cout << "Место прибытия: " << trains[i].Place << "\t\t";
//		cout << "Время прибытия на вокзал: " << trains[i].time << "\t";
//		cout << "\n///////////////////////////////////////////////////////////////////////////////////" << endl;
//	}
//};
//
//void displayTrainMode(Train* trains, int SIZE, string user_time)
//{
//	sort(trains, trains + SIZE, compTrain);
//
//	if (user_time.size() > 5 || user_time.size() < 2)
//	{
//		cout << "Некорретная дата " << endl;
//		exit(1);
//	}
//
//	istringstream x(user_time, istringstream::in);
//	int time_user1;
//	x >> time_user1;
//	x.clear();
//
//	int hours_user = time_user1 / 100; // часы 
//	int minuts_user = time_user1 % 100;// минуты 
//
//	if (hours_user < -1 || hours_user>60 || minuts_user < -1 || minuts_user >60)
//	{
//		cout << "Некорретная дата " << endl;
//		exit(1);
//	}
//
//
//	cout << "Ваше время : " << hours_user << " часов, " << minuts_user << " минут " << endl;
//	int all_user_time = hours_user * 60 * 60 + minuts_user * 60; //секунды с начатого дня
//
//	vector <int> time_train;
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		istringstream x(trains[i].time, istringstream::in);
//		int train_rail;
//		x >> train_rail;
//		int train_hours = train_rail / 100;
//		int train_minuts = train_rail % 100;
//		time_train.push_back((train_hours * 60 * 60) + (train_minuts * 60));
//	}
//	bool ones = false;
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		if (all_user_time < time_train[i])
//		{
//			cout << "Номер поезда: " << trains[i].NumTrain << "\t";
//			cout << "Место прибытия: " << trains[i].Place << "\t\t";
//			cout << "Время прибытия на вокзал: " << trains[i].time << "\t";
//			cout << "\n////////////////////////////////////////////////////////////////////////////////////////" << endl;
//			ones = true;
//		}
//	}
//	if (ones == false)
//	{
//		cout << "Нет поездов." << endl;
//	}
//}
//;
//
//void ifileTrain(Train* trains, int SIZE)
//{
//	ifstream fin("trainsInfo.txt");
//
//	if (!fin.is_open()) {
//		cout << "Не удаётся открыть файл для чтения " << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	vector<string> fileinfo;
//	string line, word;
//	stringstream x;
//	for (int i = 0; i < SIZE; ++i) {
//
//		fin >> trains[i].NumTrain;//номер поезда 
//
//		getline(fin, line);
//
//		x << line; // деление строки
//		while (x >> word)
//		{
//			fileinfo.push_back(word);
//		}
//
//		for (int k = 0; k < fileinfo.size(); ++k)
//		{
//			if (k == 0) { trains[i].Place = fileinfo[k]; }
//			if (k == 1) { trains[i].time = fileinfo[k]; }
//		}
//
//		x.clear();
//		line.clear();
//		word.clear(); //очистка
//		fileinfo.clear();
//	}
//
//}
//
//void dop2()
//{
//	setlocale(LC_CTYPE, "rus");
//	const int SIZE = 5;
//	Train trains[SIZE];
//	ifileTrain(trains, SIZE);
//	displayTrain(trains, SIZE);
//	cout << "\nВведите дату (формат ЧЧММ): ";
//	string user_time;
//	cin >> user_time;
//	cout << endl;
//	displayTrainMode(trains, SIZE, user_time);
//
//
//
//	short choose;
//	BankClients clients[N];
//	do {
//		cout << "\n1 - выход из программы.\n";
//		cin >> choose;
//		switch (choose)
//		{
//		case 1:  main(); break;
//		}
//	} while (choose != 1);
//
//}
//
//
//
//// Доп 3  
///*Определить структуру для представления информации о наличии санаторных путевок,
//содержащую следующие поля: Название санатория, Место расположения, Лечебный профиль,
//Количество путевок. Представить введенные данные в виде таблицы, сгруппировав их по
//лечебным профилям санаториев. В пределах каждой группы данные отсортировать по названиям
//санаториев. Организовать поиск информации и вывод результатов. */
//struct Camp {
//	string CampName;
//	string CampPlace;
//	string CampType;
//	int voucher;
//};
//
//bool comp1(Camp lhs, Camp rhs)
//{
//	return lhs.CampName < rhs.CampName;
//}
//
//bool comp(Camp lhs, Camp rhs)
//{
//	return lhs.CampType < rhs.CampType;
//}
//
//void showInfo(Camp* lagger, int SIZE) {
//	sort(lagger, lagger + SIZE, comp);
//	int index1 = 0;
//	int index2 = 0;
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		if (lagger[i].CampType == lagger[i + 1].CampType)
//		{
//			index1 = i;
//			break;
//		}
//	}
//
//	for (int i = SIZE; i > 0; i--)
//	{
//		if (lagger[i].CampType == lagger[i - 1].CampType)
//		{
//			index2 = i;
//			break;
//		}
//	}
//
//	sort(lagger + index1, lagger + index2 + 1, comp1);
//
//
//	for (int i = 0; i < SIZE; ++i) {
//		cout << "Название лагеря: " << lagger[i].CampName << "\t";
//		cout << "Место лагеря: " << lagger[i].CampPlace << "\t";
//		cout << "Профиль лечения: " << lagger[i].CampType << "\t\t";
//		cout << "Количество путевок: " << lagger[i].voucher << "\t" << endl;
//		cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
//	}
//
//}
//
//void ifileCamp(Camp* lagger, int SIZE)
//{
//
//	ifstream fin("lagggerInfo.txt");
//
//	if (!fin.is_open()) {
//		cout << "Не удаётся открыть файл для чтения " << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	vector<string> fileinfo;
//	string line, word;
//	stringstream x;
//	for (int i = 0; i < SIZE; ++i) {
//		fin >> lagger[i].voucher;
//		getline(fin, line);
//		x << line;
//		while (x >> word)
//		{
//			fileinfo.push_back(word);
//		}
//		for (int k = 0; k < fileinfo.size(); k++)
//		{
//			if (k == 0) { lagger[i].CampName = fileinfo[k]; }
//			if (k == 1) { lagger[i].CampPlace = fileinfo[k]; }
//			if (k == 2) { lagger[i].CampType = fileinfo[k]; }
//		}
//		x.clear();
//		line.clear();
//		word.clear();
//		fileinfo.clear();
//	}
//	cout << "\nИнформация считана из файла lagggerInfo.txt\n\n";
//}
//
//
//void dop3()
//{
//
//	setlocale(LC_CTYPE, "ru");
//	const int SIZE = 5;
//	Camp lager[SIZE];
//	short choose;
//	do {
//		cout << "Выберите, что сделать:\n1 — вывести информацию из файла;\n2 — вывести в консоль информацию о путёвках;\n3 — выход\n";
//		cin >> choose;
//		switch (choose)
//		{
//		case 1: ifileCamp(lager, SIZE); break;
//		case 2: showInfo(lager, SIZE); break;
//		case 3: exit(0); break;
//		}
//	} while (choose != 3);
//}
//
//// Main 
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	short chooseM;
//	cout << "Введите, какую лабораторную выполнить:\n1 — основа(3 вар);\n2 — доп 1;\n3 — доп 2;\n4 — доп 3;\n5 — завершение работы.\n";
//	cin >> chooseM;
//	switch (chooseM)
//	{
//	case 1: osnova(); break;
//	case 2: dop1(); break;
//	case 3: dop2(); break;
//	case 4: dop3(); break;
//	case 5: cout << "\nДо свидания!\n"; break;
//	}
//}