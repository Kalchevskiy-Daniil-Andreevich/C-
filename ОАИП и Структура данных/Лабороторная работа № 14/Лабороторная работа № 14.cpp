//В хеш-таблицах с цепочками (с прямой адресацией) каждая ячейка массива является указателем на связный спи-сок (цепочку) пар ключ-значение, соответствующих одному и тому же хеш-значению ключа.
//Коллизии здесь приводят к тому, что появляются цепочки длиной более одного элемента. 
#include <iostream>
#include <string>
using namespace std;

struct Node 
{
	string data;
	Node* next;
	Node* prev;
};

int Hash(string tmp, int SIZE)
{
	int ASCIIsum = 0;

	for (int i = 0; i < tmp.length(); ++i)
	{
		ASCIIsum += int(tmp[i]);
	}
	return ASCIIsum % SIZE;
}

void addElement(Node*& head, string tmp)
{

	Node* t = head;
	Node* buff;
	for (;;)
	{
		if (!t->next) 
		{
			buff = new Node;
			buff->data = tmp;
			buff->next = NULL;
			t->next = buff;
			buff->prev = t;
			break;
		}
		t = t->next;
	}

}

void showHashTable(Node** mass, int SIZE) 
{
	Node* t;
	for (int i = 0; i < SIZE; ++i) 
	{
		t = mass[i];

		if (!mass[i])
			continue;

		cout << "hashTableRow[" << i << "] ---> ";
		while (t)
		{
			cout << t->data << " | ";
			t = t->next;
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_CTYPE, "rus");

	const int SIZE = 3;
	int key;
	bool flag = false;
	string tmp;

	Node* mass[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		mass[i] = NULL;
	}

	int hashCode = 0;

	for (;;)
	{
		if (flag) 
		{
			cout << "Полученный хеш-код: " << hashCode << endl;
			cout << "========= Хеш-таблица с цепочками ========= " << endl;
			showHashTable(mass, SIZE);
			cout << " ========================================== " << endl;
		}

		cout << "1 - Добавить элемент хеш-таблицу: " << endl;
		cout << "2 - Удалить элемент из хеш-таблицы: " << endl;
		cout << "Выберите, что хотите сделать: " << endl;
		cin >> key;
		switch (key)
		{
		case 1:
			cout << "Введите название Книги: " << endl;
			cin.ignore();
			getline(cin, tmp);
			hashCode = Hash(tmp, SIZE);
			flag = true;

			if (!mass[hashCode]) 
			{

				mass[hashCode] = new Node;
				mass[hashCode]->data = tmp;
				mass[hashCode]->next = NULL;
				mass[hashCode]->prev = NULL;
			}
			else 
			{
				addElement(mass[hashCode], tmp);
			}
			break;

		case 2:
			cout << "Введите название товара(ключ), который хотите удалить из хеш-таблицы: " << endl;
			cin >> tmp;
			Node* t = mass[Hash(tmp, SIZE)]; // получаем список, который содержит нужный элемент
			Node* buff;

			if (t)
			{
				while (t)
				{
					if (t->data == tmp) 
					{
						if (!t->next)
						{ // удаяет последний элемент
							buff = t->next;
							(t->prev)->next = nullptr;
							delete buff;
							break;
						}

						else 
						{
							(t->prev)->next = t->next;
							(t->next)->prev = t->prev;
							delete t;
							break;

						}
					}
					t = t->next;
				}
			}

			else
			{
				cout << "Нет элементов с таким хеш-кодом: " << endl;
			}
			break;
		}
		system("cls");
	}
}

//допы 1-3

//допы 1

//#include "Header.h"
//#include <iostream>
//using namespace std;
//struct AAA
//{
//	int key;
//	char* mas;
//	AAA(int k, char* z)
//	{
//		key = k;  mas = z;
//	} AAA() {}
//};
////-------------------------------
//int key(void* d)
//{
//	AAA* f = (AAA*)d;   return f->key;
//}
////-------------------------------
//void AAA_print(void* d)
//{
//	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
//}
////-------------------------------
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	AAA a1(1, (char*)"one"), a2(2, (char*)"two"), a3(4, (char*)"three"), a4(2, (char*)"fo");
//	int siz = 10, choice, k;
//	cout << "Введите размер хеш-таблицы" << endl; 	cin >> siz;
//	Object H = create(siz, key);
//	for (;;)
//	{
//		cout << "1 - вывод хеш-таблицы" << endl;
//		cout << "2 - добавление элемента" << endl;
//		cout << "3 - удаление элемента" << endl;
//		cout << "4 - поиск элемента" << endl;
//		cout << "0 - выход" << endl;
//		cout << "сделайте выбор" << endl;   cin >> choice;
//		switch (choice)
//		{
//		case 0:  exit(0);
//		case 1: H.scan(AAA_print);  break;
//		case 2: { AAA* a = new AAA;
//			char* str = new char[20];
//			cout << "введите ключ" << endl;	cin >> k;
//			a->key = k;
//			cout << "введите строку" << endl; cin >> str;
//			a->mas = str;
//			if (H.N == H.size)
//				cout << "Таблица заполнена" << endl;
//			else
//				H.insert(a);
//		} break;
//		case 3: {  cout << "введите ключ для удаления" << endl;
//			cin >> k;
//			H.deleteByKey(k);
//		}  break;
//		case 4: {  cout << "введите ключ для поиска" << endl;
//			cin >> k;
//			if (H.search(k) == NULL)
//				cout << "Элемент не найден" << endl;
//			else
//				AAA_print(H.search(k));
//		}  break;
//		}
//	}
//	return 0;
//}

//доп 2

//#include "Header.h"
//#include <iostream>
//using namespace std;
//struct AAA
//{
//	int key;
//	char* mas;
//	AAA(int k, char* z)
//	{
//		key = k;  mas = z;
//	} AAA() {}
//};
////-------------------------------
//int key(void* d)
//{
//	AAA* f = (AAA*)d;   return f->key;
//}
////-------------------------------
//void AAA_print(void* d)
//{
//	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
//}
////-------------------------------
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	AAA a1(1, (char*)"one"), a2(2, (char*)"two"), a3(4, (char*)"three"), a4(2, (char*)"fo");
//	int siz = 10, choice, k;
//	cout << "Введите размер хеш-таблицы" << endl; 	cin >> siz;
//	Object H = create(siz, key);
//	for (;;)
//	{
//		cout << "1 - вывод хеш-таблицы" << endl;
//		cout << "2 - добавление элемента" << endl;
//		cout << "3 - удаление элемента" << endl;
//		cout << "4 - поиск элемента" << endl;
//		cout << "0 - выход" << endl;
//		cout << "сделайте выбор" << endl;   cin >> choice;
//		switch (choice)
//		{
//		case 0:  exit(0);
//		case 1: H.scan(AAA_print);  break;
//		case 2: { AAA* a = new AAA;
//			char* str = new char[20];
//			cout << "введите ключ" << endl;	cin >> k;
//			a->key = k;
//			cout << "введите строку" << endl; cin >> str;
//			a->mas = str;
//			if (H.N == H.size)
//				cout << "Таблица заполнена" << endl;
//			else
//				H.insert(a);
//		} break;
//		case 3: {  cout << "введите ключ для удаления" << endl;
//			cin >> k;
//			H.deleteByKey(k);
//		}  break;
//		case 4: {  cout << "введите ключ для поиска" << endl;
//			cin >> k;
//			if (H.search(k) == NULL)
//				cout << "Элемент не найден" << endl;
//			else
//				AAA_print(H.search(k));
//		}  break;
//		}
//	}
//	return 0;
//}

//доп 3

//#include "Header.h"
//#include <iostream>
//using namespace std;
//struct AAA
//{
//	int key;
//	char* mas;
//	AAA(int k, char* z)
//	{
//		key = k;  mas = z;
//	} AAA() {}
//};
////-------------------------------
//int key(void* d)
//{
//	AAA* f = (AAA*)d;   return f->key;
//}
////-------------------------------
//void AAA_print(void* d)
//{
//	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
//}
////-------------------------------
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	AAA a1(1, (char*)"one"), a2(2, (char*)"two"), a3(4, (char*)"three"), a4(2, (char*)"fo");
//	int siz = 10, choice, k;
//	cout << "Введите размер хеш-таблицы" << endl; 	cin >> siz;
//	Object H = create(siz, key);
//	for (;;)
//	{
//		cout << "1 - вывод хеш-таблицы" << endl;
//		cout << "2 - добавление элемента" << endl;
//		cout << "3 - удаление элемента" << endl;
//		cout << "4 - поиск элемента" << endl;
//		cout << "0 - выход" << endl;
//		cout << "сделайте выбор" << endl;   cin >> choice;
//		switch (choice)
//		{
//		case 0:  exit(0);
//		case 1: H.scan(AAA_print);  break;
//		case 2: { AAA* a = new AAA;
//			char* str = new char[20];
//			cout << "введите ключ" << endl;	cin >> k;
//			a->key = k;
//			cout << "введите строку" << endl; cin >> str;
//			a->mas = str;
//			if (H.N == H.size)
//				cout << "Таблица заполнена" << endl;
//			else
//				H.insert(a);
//		} break;
//		case 3: {  cout << "введите ключ для удаления" << endl;
//			cin >> k;
//			H.deleteByKey(k);
//		}  break;
//		case 4: {  cout << "введите ключ для поиска" << endl;
//			cin >> k;
//			if (H.search(k) == NULL)
//				cout << "Элемент не найден" << endl;
//			else
//				AAA_print(H.search(k));
//		}  break;
//		}
//	}
//	return 0;
//}