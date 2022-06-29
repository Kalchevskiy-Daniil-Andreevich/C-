#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

// перечисляемый тип данных для удобства использования оператора множественного выбора switch
enum Variants { add_element = 1, delete_element, find_element, show_list, write_in_file, read_from_file, exit_program };

// структура, хранящая в себе сущность "узел", содержащую в себе:
// data - информацию, хранящуюся в узле списка
// next - указатель на следующий узел списка
// конструктор - специальная функция структуры (или класса), которая вызывается автоматически при создании объекта структуры или класса
// т.е. конструктор нужен для того, чтобы автоматически сразу присваивать значение новосозданному узлу и указателю на следующий узел
// это осуществляется при помощи списка инициализаторов членов (оператор : )

struct Node
{
	char data;
	Node* next;
	Node(char _data) : data(_data), next(nullptr) {} // конструктор
};

// структура, хранящая в себе сущность "список", состоящую из:
// first - указатель на первый элемент списка, или голова;
// last - указатель на последний элемент списка, или хвост;
// конструктор, автоматически инициализирующий значения указателей first и last;
// функции, которые позволяют осуществлять операции над списком
// напоминание: структура, как и класс, может хранить в себе не только данные, но и функции, работающие с этими данными

struct list
{
	Node* first;
	Node* last;

	list() : first(nullptr), last(nullptr) {} // конструктор

	bool is_empty() //Это однострочная функция, в которой надо проверить является ли первый узел - пустым
	{
		return first == nullptr;
	}

	void push_back(char _data) // Функция добавления элемента в конец списка
	{
		Node* p = new Node(_data); //  создаем сам узел со значением, которое мы передали в эту функцию.
		if (is_empty()) // если список пустой
		{
			first = p; // Если список пустой, тогда мы присваиваем указателю на первый узел и последний узел указатель на новый узел и выходим из функции.
			last = p;
			return;
		}
		last->next = p; // если же узел не первый, то "пропихиваем" его внутрь списка,надо указать, что новый узел стоит после последнего узла
		last = p; // т.е. делаем его последним
	}

	void print()  // функция, выполняющая печать на экране содержимого списка
	{
		if (is_empty()) // если ничего нет, не печатаем
			return;

		Node* p = first; //Далее создаём указатель p на первый узел и выводим значение узла

		while (p) // пока мы не добрались до конца списка,
		{
			cout << p->data << " "; // вывод информации
			p = p->next; // и переход к следующему узлу
		}
		cout << endl;
	}

	void fprint() // функция, выполняющая печать данных в файл
	{
		if (is_empty()) // если ничего нет, не печатаем
			return;

		char path[] = "test.txt";
		FILE* f;
		fopen_s(&f, path, "w");

		Node* p = first;

		while (p) // пока не достигнут конец списка,
		{
			fprintf_s(f, "%c ", *p); // печать данных
			p = p->next; // и переход к следующему узлу
		}
		cout << "Список записан в файл" << endl;
		fclose(f);
	}

	void push_back() // функция, осуществляющая чтение данных из файла,
	{
		char path[] = "test.txt";

		FILE* f;
		fopen_s(&f, path, "r");

		char _data;

		if (f != NULL)
		{
			for (;;)
			{
				fscanf_s(f, "%c", &_data);
				Node* p = new Node(_data); // выделения места под данные (символ) из файла
				if (is_empty())
				{
					first = p;
					last = p;
				}
				last->next = p; // их "пропихивание" вглубь списка
				last = p;

				if (feof(f))
				{
					remove(_data);
					break;
				}
			}
		}

		fclose(f);
	}

	Node* find(char _data) // функция, осуществляющая поиск заданного значения (символа) в списке
	{
		Node* p = first;
		while (p && p->data != _data) // пока не найден узел с данными, которые мы ввели,
			p = p->next; // переходим к следующему узлу
		return (p && p->data == _data) ? p : nullptr; // если нашли данные, возвращаем их, если нет, возвращаем нулевой указатель (используется тернарный оператор, то же что if...else)
	}

	void remove_first() // функция, удаляющая первый узел из списка
	{
		if (is_empty()) // если список пустой, ничего не делаем
			return;

		Node* p = first; // Далее создаём указатель p на первый узел списка.
		first = p->next; // Меняем значение первого узла на следующий ,

		delete p; //  удаляем узел p;
	}

	void remove_last() // функция, удаляющая последний узел из списка
	{
		if (is_empty()) // если нечего удалять, ничего не делаем
			return;

		if (first == last) // если первый узел списка является последним, т.е. в списке один узел,
		{
			remove_first(); // удаляем его
			return;
		}

		Node* p = first; // вспомогательный указатель, равный первому узлу
		while (p->next != last) // пока не достигнут последний узел,
			p = p->next; // проходим по узлам от начала до конца

		p->next = nullptr; // как только достигли последнего узла, обнуляем его, уничтожая данные
		delete last; // удаляем последний узел
		last = p; // последним узлом становится предпоследний
	}

	void remove(char _data) // функция, удаляющая произвольный узел в списке (по значению)
	{
		if (is_empty())  // если нечего удалять, ничего не делаем
			return;

		if (first->data == _data) // если данные содержатся в первом узле,
		{
			remove_first(); // удаляем его
			return;
		}
		else if (last->data == _data) // если данные содержатся в последнем узле,
		{
			remove_last(); // удаляем его
			return;
		}
		// если же данные не содержатся в первом или последнем узле,
		Node* slow = first; // вспомогательный указатель, соответствующий первому узлу
		Node* fast = first->next; // вспомогательный указатель, соответствующий следующему после первого узлу

		while (fast && fast->data != _data)  // пока не дошли до конца списка или не найден узел с нужными данными,
		{
			fast = fast->next; // переходим к следующим узлам
			slow = slow->next;
		}

		if (!fast) // если не найден нужный элемент (дошли до конца списка),
		{
			cout << "Такого элемента не существует" << endl;
			return;
		}

		slow->next = fast->next; // на место удаляемого узла ставим тот, что после него
		delete fast; // удаляем узел
	}
};


void menu() // меню для общения с пользователем
{
	cout << "Что Вы желаете сделать?" << endl;
	cout << "1 - Добавить элемент" << endl;
	cout << "2 - Удалить элемент" << endl;
	cout << "3 - Найти элемент" << endl;
	cout << "4 - Вывести список" << endl;
	cout << "5 - Записать список в файл" << endl;
	cout << "6 - Прочитать список из файла" << endl;
	cout << "7 - Выйти из программы" << endl;
	cout << ">> ";
}

void createFile() // функция, автоматически создающая файл, с которым можно работать
{
	char path[] = "test.txt";
	FILE* f;

	fopen_s(&f, path, "w");

	if (!f)
		cout << "Ошибка создания файла!" << endl;

	fclose(f);
}

int main()
{
	setlocale(LC_ALL, "RUS");

	createFile();

	list l;

	bool flag = false;

	do
	{
		menu();

		char ch;
		unsigned short int choice;
		cin >> choice;

		switch (choice)
		{
		case add_element:
			cout << "Введите символ, который хотите добавить в список:" << endl;
			cin >> ch;
			l.push_back(ch);
			cout << "Ввод символа завершён" << endl;
			break;
		case delete_element:
			cout << "Введите символ, который хотите удалить:" << endl;
			cin >> ch;
			l.remove(ch);
			cout << "Удаление символа завершено" << endl;
			break;
		case find_element:
			cout << "Введите символ, который хотите найти:" << endl;
			cin >> ch;
			cout << "Найден символ '" << ch << "' с адресом " << l.find(ch) << endl;
			break;
		case show_list:
			cout << "Полный список:" << endl;
			l.print();
			cout << "Вывод списка завершён" << endl;
			break;
		case write_in_file:
			l.fprint();
			break;
		case read_from_file:
			l.push_back();
			break;
		case exit_program:
			flag = true;
			break;
		default:
			cout << "Неверное значение. Повторите ввод" << endl;
			break;
		}

	} while (!flag);

	cout << "Программа успешно завершила работу" << endl;

	return 0;
}

//допы 1-3

//dop 1
//#include <iostream>
//#include <string>
//#include<fstream>
//using namespace std;
//struct list
//{
//	int number;
//	list* next;
//};
//
//void insert(list*&, int);
//int del(list*&, int);
//int IsEmpty(list*);
//void printList(list*);
//void menu(void);
//void sum5(list*);
//void toFile(list*& p);
//void fromFile(list*& p);
//void find(list*);
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	list* first = NULL;
//	int choice;
//	int value;
//	menu();
//	cout << " Что дальше? ";
//	cin >> choice;
//	while (choice != 8)
//	{
//		switch (choice)
//		{
//		case 1: cout << "Введите число ";
//			cin >> value;
//			insert(first, value);
//			break;
//		case 2:
//			printList(first);
//			break;
//		case 3: if (!IsEmpty(first))
//		{
//			cout << "Введите удаляемое число ";
//			cin >> value;
//			if (del(first, value))
//			{
//				cout << "Удалено число " << value << endl;
//				printList(first);
//			}
//			else
//				cout << "Число не найдено" << endl;
//		}
//			  else
//			cout << "Список пуст" << endl;
//			break;
//		case 4: sum5(first);
//			break;
//		case 5: toFile(first);
//			break;
//		case 6: fromFile(first);
//			break;
//		case 7: find(first);
//			break;
//		default: cout << "Неправильный выбор" << endl;
//			menu();
//			break;
//		}
//		cout << "Что дальше? ";
//		cin >> choice;
//	}
//	cout << "Конец" << endl;
//	return 0;
//}
//
//void menu(void)
//{
//	cout << "Сделайте выбор:" << endl;
//	cout << " 1 - Ввод числа" << endl;
//	cout << " 2 - Вывод числа" << endl;
//	cout << " 3 - Удаление числа" << endl;
//	cout << " 4 - Вычисление суммы положительных чисел" << endl;
//	cout << " 5 - Запись в файл" << endl;
//	cout << " 6 - Вывод из файла" << endl;
//	cout << " 7 - Поиск элемента" << endl;
//	cout << " 8 - Конец" << endl;
//}
//
//void insert(list*& p, int value)
//{
//	list* newP = new list;
//	if (newP != NULL)
//	{
//		newP->number = value;
//		newP->next = p;
//		p = newP;
//	}
//	else
//		cout << "Операция добавления не выполнена" << endl;
//}
//
//int del(list*& p, int value)
//{
//	list* previous, * current, * temp;
//	if (value == p->number)
//	{
//		temp = p;
//		p = p->next;
//		delete temp;
//		return value;
//	}
//	else
//	{
//		previous = p;
//		current = p->next;
//		while (current != NULL && current->number != value)
//		{
//			previous = current;
//			current = current->next;
//		}
//		if (current != NULL)
//		{
//			temp = current;
//			previous->next = current->next;
//			free(temp);
//			return value;
//		}
//	}
//	return 0;
//}
//
//int IsEmpty(list* p)
//{
//	return p == NULL;
//}
//
//
//
//void printList(list* p)
//{
//	if (p == NULL)
//		cout << "Список пуст" << endl;
//	else
//	{
//		cout << "Список:" << endl;
//		while (p != NULL)
//		{
//			cout << "-->" << p->number;
//			p = p->next;
//		}
//		cout << "-->NULL" << endl;
//	}
//}
//
//void sum5(list* p)
//{
//	int sm = 0;
//	if (p == NULL)
//		cout << "Список пуст" << endl;
//	else
//	{
//		while (p != NULL)
//		{
//			if (p->number >= 0)
//
//				sm = sm + (p->number);
//			p = p->next;
//
//
//		}
//		cout << "Сумма = " << sm << endl;
//	}
//
//}
//void toFile(list*& p)
//{
//	list* temp = p;
//	ofstream file1("mList.txt");
//	if (file1.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	while (temp)
//	{
//		int nn = temp->number;
//		file1 << nn << "\n";
//		temp = temp->next;
//	}
//	file1.close();
//	cout << "Список записан в файл mList.txt\n";
//}
//void fromFile(list*& p)
//{
//
//	char buf[10];
//
//	ifstream file1("mList.txt");
//	if (file1.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	while (!file1.eof())
//	{
//		file1.getline(buf, 10);
//		if (strlen(buf))
//			insert(p, atoi(buf));
//		cout << "-->" << buf;
//	}
//	cout << "-->NULL" << endl;
//	file1.close();
//}
//void find(list* p)
//{
//	bool isFnd = false;
//	int element;
//	cout << "Введите элемент:" << endl;
//	cin >> element;
//	list* fnd = p;
//	while (fnd)
//	{
//		if (fnd->number == element)
//		{
//			isFnd = true;
//			printf("Элемент найден\n");
//			break;
//		}
//		fnd = fnd->next;
//	}
//	if (!isFnd)
//		printf("Элемент не найден\n");
//
//}


//dop 2
//#include <iostream>
//#include <string>
//#include<fstream>
//using namespace std;
//struct list
//{
//	int number;
//	list* next;
//};
//
//void insert(list*&, int);
//int del(list*&, int);
//int IsEmpty(list*);
//void printList(list*);
//void menu(void);
//void sum5(list*);
//void toFile(list*& p);
//void fromFile(list*& p);
//void find(list*);
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	list* first = NULL;
//	int choice;
//	int value;
//	menu();
//	cout << " Что дальше? ";
//	cin >> choice;
//	while (choice != 8)
//	{
//		switch (choice)
//		{
//		case 1: cout << "Введите число ";
//			cin >> value;
//			insert(first, value);
//			break;
//		case 2:
//			printList(first);
//			break;
//		case 3: if (!IsEmpty(first))
//		{
//			cout << "Введите удаляемое число ";
//			cin >> value;
//			if (del(first, value))
//			{
//				cout << "Удалено число " << value << endl;
//				printList(first);
//			}
//			else
//				cout << "Число не найдено" << endl;
//		}
//			  else
//			cout << "Список пуст" << endl;
//			break;
//		case 4: sum5(first);
//			break;
//		case 5: toFile(first);
//			break;
//		case 6: fromFile(first);
//			break;
//		case 7: find(first);
//			break;
//		default: cout << "Неправильный выбор" << endl;
//			menu();
//			break;
//		}
//		cout << "Что дальше? ";
//		cin >> choice;
//	}
//	cout << "Конец" << endl;
//	return 0;
//}
//
//void menu(void)
//{
//	cout << "Сделайте выбор:" << endl;
//	cout << " 1 - Ввод числа" << endl;
//	cout << " 2 - Вывод числа" << endl;
//	cout << " 3 - Удаление числа" << endl;
//	cout << " 4 - Вычисление суммы положительных двузначных чисел" << endl;
//	cout << " 5 - Запись в файл" << endl;
//	cout << " 6 - Вывод из файла" << endl;
//	cout << " 7 - Поиск элемента" << endl;
//	cout << " 8 - Конец" << endl;
//}
//
//void insert(list*& p, int value)
//{
//	list* newP = new list;
//	if (newP != NULL)
//	{
//		newP->number = value;
//		newP->next = p;
//		p = newP;
//	}
//	else
//		cout << "Операция добавления не выполнена" << endl;
//}
//
//int del(list*& p, int value)
//{
//	list* previous, * current, * temp;
//	if (value == p->number)
//	{
//		temp = p;
//		p = p->next;
//		delete temp;
//		return value;
//	}
//	else
//	{
//		previous = p;
//		current = p->next;
//		while (current != NULL && current->number != value)
//		{
//			previous = current;
//			current = current->next;
//		}
//		if (current != NULL)
//		{
//			temp = current;
//			previous->next = current->next;
//			free(temp);
//			return value;
//		}
//	}
//	return 0;
//}
//
//int IsEmpty(list* p)
//{
//	return p == NULL;
//}
//
//
//
//void printList(list* p)
//{
//	if (p == NULL)
//		cout << "Список пуст" << endl;
//	else
//	{
//		cout << "Список:" << endl;
//		while (p != NULL)
//		{
//			cout << "-->" << p->number;
//			p = p->next;
//		}
//		cout << "-->NULL" << endl;
//	}
//}
//
//void sum5(list* p)
//{
//	int sm = 0;
//	if (p == NULL)
//		cout << "Список пуст" << endl;
//	else
//	{
//		while (p != NULL)
//		{
//			if (p->number > 0 && p->number > 9 && p->number < 100)
//
//				sm = sm + (p->number);
//			p = p->next;
//
//
//		}
//		cout << "Сумма = " << sm << endl;
//	}
//
//}
//void toFile(list*& p)
//{
//	list* temp = p;
//	ofstream file1("mList.txt");
//	if (file1.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	while (temp)
//	{
//		int nn = temp->number;
//		file1 << nn << "\n";
//		temp = temp->next;
//	}
//	file1.close();
//	cout << "Список записан в файл mList.txt\n";
//}
//void fromFile(list*& p)
//{
//
//	char buf[10];
//
//	ifstream file1("mList.txt");
//	if (file1.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	while (!file1.eof())
//	{
//		file1.getline(buf, 10);
//		if (strlen(buf))
//			insert(p, atoi(buf));
//		cout << "-->" << buf;
//	}
//	cout << "-->NULL" << endl;
//	file1.close();
//}
//void find(list* p)
//{
//	bool isFnd = false;
//	int element;
//	cout << "Введите элемент:" << endl;
//	cin >> element;
//	list* fnd = p;
//	while (fnd)
//	{
//		if (fnd->number == element)
//		{
//			isFnd = true;
//			printf("Элемент найден\n");
//			break;
//		}
//		fnd = fnd->next;
//	}
//	if (!isFnd)
//		printf("Элемент не найден\n");
//
//}


//dop 3
//#include <iostream>
//#include <string>
//#include<fstream>
//using namespace std;
//struct list
//{
//	int number;
//	list* next;
//};
//
//void insert(list*&, int);
//int del(list*&, int);
//int IsEmpty(list*);
//void printList(list*);
//void menu(void);
//void sum5(list*);
//void toFile(list*& p);
//void fromFile(list*& p);
//void find(list*);
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	list* first = NULL;
//	int choice;
//	int value;
//	menu();
//	cout << " Что дальше? ";
//	cin >> choice;
//	while (choice != 8)
//	{
//		switch (choice)
//		{
//		case 1: cout << "Введите число ";
//			cin >> value;
//			insert(first, value);
//			break;
//		case 2:
//			printList(first);
//			break;
//		case 3: if (!IsEmpty(first))
//		{
//			cout << "Введите удаляемое число ";
//			cin >> value;
//			if (del(first, value))
//			{
//				cout << "Удалено число " << value << endl;
//				printList(first);
//			}
//			else
//				cout << "Число не найдено" << endl;
//		}
//			  else
//			cout << "Список пуст" << endl;
//			break;
//		case 4: sum5(first);
//			break;
//		case 5: toFile(first);
//			break;
//		case 6: fromFile(first);
//			break;
//		case 7: find(first);
//			break;
//		default: cout << "Неправильный выбор" << endl;
//			menu();
//			break;
//		}
//		cout << "Что дальше? ";
//		cin >> choice;
//	}
//	cout << "Конец" << endl;
//	return 0;
//}
//
//void menu(void)
//{
//	cout << "Сделайте выбор:" << endl;
//	cout << " 1 - Ввод числа" << endl;
//	cout << " 2 - Вывод числа" << endl;
//	cout << " 3 - Удаление числа" << endl;
//	cout << " 4 - Вычисление суммы отрицательных чисел, кратных 5" << endl;
//	cout << " 5 - Запись в файл" << endl;
//	cout << " 6 - Вывод из файла" << endl;
//	cout << " 7 - Поиск элемента" << endl;
//	cout << " 8 - Конец" << endl;
//}
//
//void insert(list*& p, int value)
//{
//	list* newP = new list;
//	if (newP != NULL)
//	{
//		newP->number = value;
//		newP->next = p;
//		p = newP;
//	}
//	else
//		cout << "Операция добавления не выполнена" << endl;
//}
//
//int del(list*& p, int value)
//{
//	list* previous, * current, * temp;
//	if (value == p->number)
//	{
//		temp = p;
//		p = p->next;
//		delete temp;
//		return value;
//	}
//	else
//	{
//		previous = p;
//		current = p->next;
//		while (current != NULL && current->number != value)
//		{
//			previous = current;
//			current = current->next;
//		}
//		if (current != NULL)
//		{
//			temp = current;
//			previous->next = current->next;
//			free(temp);
//			return value;
//		}
//	}
//	return 0;
//}
//
//int IsEmpty(list* p)
//{
//	return p == NULL;
//}
//
//
//
//void printList(list* p)
//{
//	if (p == NULL)
//		cout << "Список пуст" << endl;
//	else
//	{
//		cout << "Список:" << endl;
//		while (p != NULL)
//		{
//			cout << "-->" << p->number;
//			p = p->next;
//		}
//		cout << "-->NULL" << endl;
//	}
//}
//
//void sum5(list* p)
//{
//	int sm = 0;
//	if (p == NULL)
//		cout << "Список пуст" << endl;
//	else
//	{
//		while (p != NULL)
//		{
//			if (p->number < 0 && p->number % 5 == 0)
//
//				sm = sm + (p->number);
//			p = p->next;
//
//
//		}
//		cout << "Сумма = " << sm << endl;
//	}
//
//}
//void toFile(list*& p)
//{
//	list* temp = p;
//	ofstream file1("mList.txt");
//	if (file1.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	while (temp)
//	{
//		int nn = temp->number;
//		file1 << nn << "\n";
//		temp = temp->next;
//	}
//	file1.close();
//	cout << "Список записан в файл mList.txt\n";
//}
//void fromFile(list*& p)
//{
//
//	char buf[10];
//
//	ifstream file1("mList.txt");
//	if (file1.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	while (!file1.eof())
//	{
//		file1.getline(buf, 10);
//		if (strlen(buf))
//			insert(p, atoi(buf));
//		cout << "-->" << buf;
//	}
//	cout << "-->NULL" << endl;
//	file1.close();
//}
//void find(list* p)
//{
//	bool isFnd = false;
//	int element;
//	cout << "Введите элемент" << endl;
//	cin >> element;
//	list* fnd = p;
//	while (fnd)
//	{
//		if (fnd->number == element)
//		{
//			isFnd = true;
//			printf("Элемент найден\n");
//			break;
//		}
//		fnd = fnd->next;
//	}
//	if (!isFnd)
//		printf("Элемент не найден\n");
//
//}