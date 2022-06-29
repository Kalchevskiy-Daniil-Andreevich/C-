//Бинарная куча (binary heap) представляет собой бинарное дерево, для которого выполняется основное свойство кучи: приоритет каждой вершины больше приоритетов её потомков.
//В простейшем случае приоритет можно считать равным значению. Реализация бинарной кучи возможна на основе массива и на основе списка.
#include "Heap.h"
#include <iostream>
#include <fstream>
using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)  // функция сравнения 2х элементов типа ААА
{
#define A1 ((AAA*)a1) 
#define A2 ((AAA*)a2)

	heap::CMP	rc = heap::EQUAL;     // объявляем переменную типа CMP, то есть результат сравнения двух структур (=двух элементов кучи)
	if (A1->x > A2->x) 	          // если значение первого элемента больше значения второго
		rc = heap::GREAT;             // записываем в переменную, что первый элемент больше второго
	else
		if (A2->x > A1->x) 	      // если второй элемент больше первого 
			rc = heap::LESS;		  // записываем в переменную, что первый элемент меньше второго
	return rc;						  //	возвращаем значение переменной
#undef A2	
#undef A1	
}

bool BuildHeap(char* FileName, heap::Heap& h)	// построение кучи из файла, char *FileName - имя файла, heap::Heap& h - куча, на которую берётся указатель
{
	bool rc = true;
	int n;
	ifstream inFile;
	inFile.open(FileName);
	if (!inFile)
	{
		cout << "Невозможно открыть файл" << endl;
		exit(1);
	}
	cout << "    Исходные данные" << endl;
	while (inFile >> n)
	{
		int* a = new int;
		*a = n;	// переписываем прочитанный элемент из буфера в выделенную память 
		h.Insert((void*)a);
		cout << *a << endl;
	}
	inFile.close();
	return rc;
}

void SaveHeap(heap::Heap& h, char* FileName)
{
	ofstream  outFile(FileName);
	if (!outFile)
	{
		std::cout << "Ошибка открытия выходного файла" << std::endl;
		return;
	}
	int* a;
	for (int u = 0; u < h.Size; u++)
	{
		a = (int*)h.Storage[u];
		outFile << *a;
		outFile << endl;
	}
	outFile.close();
}

void main()
{
	setlocale(LC_ALL, "rus");
	char buf[255];
	int k;
	heap::Heap h1 = heap::Create(30, cmpAAA), h2 = heap::Create(30, cmpAAA);

	int choise;
	AAA* a;
	for (;;)
	{
		cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление максимального" << endl;
		cout << "4 - очистить кучу" << endl;
		cout << "5 - сохранить в файл" << endl;
		cout << "6 - загрузить из файла" << endl;
		cout << "7 - извлечение минимального элемента" << endl;
		cout << "8 - удаление i-ого элемента" << endl;
		cout << "9 - объединения двух куч в одну" << endl;
		cout << "0 - выход" << endl;
		cout << "Что надо сделать?" << endl;
		cin >> choise;
		switch (choise)
		{
		case 0:  exit(0);
		case 1:  h1.Scan(0);
			break;
		case 2:
			a = new AAA;
			cout << "Введите элемент " << endl;
			cin >> k;
			a->x = k;
			h1.Insert(a);
			break;
		case 3:
			a = (AAA*)h1.ExtractMax();

			if (a != NULL)
				cout << "Максимальный элемент: " << a->x << endl;
			else cout << "Куча пуста." << endl;
			break;
		case 4:   h1.DeleteHeap();
			break;
		case 5:
			cout << "Введите имя файла" << endl;
			cin >> buf;
			SaveHeap(h1, buf);
			break;
		case 6:
			h1.DeleteHeap();
			cout << "Введите имя файла" << endl;
			cin >> buf;
			BuildHeap(buf, h1);
			break;
		case 7:
			a = (AAA*)h1.ExtractMin();

			if (a != NULL)
				cout << "Минимальный элемент: " << a->x << endl;
			else cout << "Куча пуста." << endl;
			break;
		case 8:
			cout << "Введите номер элемента " << endl;
			cin >> choise;
			a = (AAA*)h1.ExtractI(choise);

			if (a != NULL)
				cout << "Извлечённый элемент: " << a->x << endl;
			else cout << "Куча пуста." << endl;
			break;
		case 9:
			cout << "Введите имя файла" << endl;
			cin >> buf;
			h2.DeleteHeap();
			BuildHeap(buf, h2);
			h1.Union(h2);
			break;
		default:
			cout << endl << "Введена неверная команда!"; cout << endl;
		}
	}
}

//допы 1-3
//
//доп 1

//#include <iostream>
//using namespace std;
//struct Tree
//{
// int key;
// char number[20];
// char surname[20];
// char tarif[20];
// Tree* Left, * Right;
//};
//
//Tree* makeTree(Tree* Root);
//Tree* list(int i, char* s, char* number, char* t);
//Tree* insertElem(Tree* Root, int key, char* s, char* number, char* t);
//void view(Tree* t, int level);
//void search(Tree* n, char* number);
//string popularTarif(Tree* n);
//void delAll(Tree* t);
//
//
//int c = 0;
//int t1 = 0, t2 = 0, t3 = 0;
//Tree* Root = NULL;
//void main()
//{
// setlocale(0, "Russian");
// int key, choice, n;
// Tree* rc; char s[20], t[20], number[20];
// string ans;
// for (;;)
// {
//  cout << "1 -создание дерева\n";
//  cout << "2 -добавление элемента\n";
//  cout << "3 -вывод дерева\n";
//  cout << "4 -поиск по номеру \n";
//  cout << "5 -попул¤рный тариф \n";
//  cout << "6 -удаление дерева \n";
//  cout << "7 -выход\n";
//  cout << "ваш выбор?\n";
//  cin >> choice;
//  cout << "\n";
//  switch (choice)
//  {
//  case 1: Root = makeTree(Root); break;
//  case 2: cout << "\nвведите ключ: "; cin >> key;
//   cout << "введите фамилию: "; cin >> s;
//   cout << "введите номер: "; cin >> number;
//   cout << "введите тариф: "; cin >> t;
//   insertElem(Root, key, s, number, t); break;
//  case 3: if (Root->key >= 0)
//  {
//   cout << "дерево :" << endl;
//   view(Root, 0);
//  }
//     else cout << "дерево пустое\n"; break;
//
//  case 4: cout << "\nвведите номер: ";
//   cin >> number;
//   cout << "јбонент:";
//   search(Root, number);
//   break;
//
//  case 5:
//   cout << "ѕопул¤рный тариф:";
//   ans = popularTarif(Root);
//   cout << ans << endl;
//   break;
//  case 6: delAll(Root); break;
//
//  case 7: exit(0);
//  }
// }
//}
//
//Tree* makeTree(Tree* Root)
//{
// int key; char s[20], t[20], number[20];
// cout << " онец ввода 0 ключ\n\n";
// if (Root == NULL)
// {
//  cout << "введите ключ корн¤: "; cin >> key;
//  cout << "введите фамилию абонента: "; cin >> s;
//  cout << "введите номер абонента: "; cin >> number;
//  cout << "введите тариф абонента: "; cin >> t;
//  Root = list(key, s, number, t);
// }
// while (1)
// {
//  cout << "\nвведите ключ: "; cin >> key;
//  if (key == 0) break;
//  cout << "введите фамилию абонента: "; cin >> s;
//  cout << "введите номер абонента: "; cin >> number;
//  cout << "введите тариф абонента: "; cin >> t;
//  insertElem(Root, key, s, number, t);
// }
// return Root;
//}
//
//Tree* list(int i, char* s, char* number, char* t)
//{
// Tree* tmp = new Tree[sizeof(Tree)];
// tmp->key = i;
// for (i = 0; i < 20; i++)
// {
//  *((tmp->surname) + i) = *(s + i);
//
//
//  *((tmp->number) + i) = *(number + i);
//
//
//  *((tmp->tarif) + i) = *(t + i);
// }
//
// tmp->Left = tmp->Right = NULL;
// return tmp;
//}
//
//Tree* insertElem(Tree* tmp, int key, char* s, char* number, char* t)
//{
// Tree* Prev = tmp;
// int find = 0;
// while (tmp && !find)
// {
//  Prev = tmp;
//  if (key == tmp->key)
//   find = 1;
//  else
//   if (key < tmp->key) tmp = tmp->Left;
//   else tmp = tmp->Right;
// }
// if (!find)
// {
//  tmp = list(key, s, number, t);
//  if (key < Prev->key)
//   Prev->Left = tmp;
//  else
//   Prev->Right = tmp;
// }
// return tmp;
//}
//
//
//
//void view(Tree* t, int level)
//{
// if (t)
// {
//  view(t->Right, level + 1);
//  for (int i = 0; i < level; i++)
//   cout << " |";
//  int tm = t->key;
//  cout << tm << ' ';
//  cout << t->surname << endl;
//  cout << t->number << endl;
//  cout << t->tarif << endl;
//  view(t->Left, level + 1);
// }
//}
//
//void search(Tree* n, char* number)
//{
// if (n != NULL)
// {
//  if (strcmp(number, n->number) == 0)
//  {
//   cout << n->key << endl;
//   cout << n->surname << endl;
//   cout << n->number << endl;
//   cout << n->tarif << endl;
//  }
//  else
//   search(n->Left, number);
//  search(n->Right, number);
// }
//
//}
//string popularTarif(Tree* n)
//{
// if (!n)return"

//доп 2

//доп 2

//const int n = 5;
//int a[n];
//
//void perem(int k)
//{
//    int i, j, t, p;
//    for (i = 0; i < n - k; i++)
//    {
//        if (k < n - 2)
//            perem(k + 1); // рекурсивный вызов
//        else // печать готовой перестановки
//        {
//            for (p = 0; p < n; p++)
//                cout << " " << a[p];
//            cout << endl;
//        }
//        // циклический сдвиг
//        t = a[k];
//        for (j = k + 1; j < n; j++)
//            a[j - 1] = a[j];
//        a[j - 1] = t;
//    }
//}
//
//int main(void)
//{
//    int i;
//    // заполнение
//    for (i = 0; i < n; i++)
//        a[i] = i + 1;
//    perem(0);
//    return 0;
//}

//доп 3 

//int i, c, b = 0;
//
//int func(int smth, int max, int* array)
//{
//    if (!b)
//    {
//        while (i < max)
//        {
//            i++;
//            b++;
//        }
//    }
//    if (i <= smth)
//    {
//        array[c] = i;
//        ++i;
//        c++;
//        func(smth, max, array);
//    }
//    else
//    {
//        return c;
//    }
//}
//
//int main(int argc, char* argv[])
//{
//    int a;
//    cout << "Enter the number: " << '\n';
//    cin >> a;
//
//    int* arr = new int[a];
//
//    int counter = 1;
//
//    while (counter < a)
//    {
//        counter = counter * 10;
//        cout << "We count to " << counter << endl;
//    }
//    counter = counter / 10;
//    cout << "We count from " << counter << endl;
//    int count = func(a, counter, arr);
//
//    for (int i = 0; i < count; i++)
//    {
//        cout << arr[i] << endl;
//    }
//
//    return 0;
//}