#include <iostream>
#include <fstream>
using namespace std;

enum Variants { _ADD = 1, _DELETE, _SEARCH, _PRINT, _WRITE, _READ, _EXIT };


struct Node { // Структура, олицетворяющая элемент стека 
	int Data; // данные, хранящиеся в этом элементе
	Node* next; // указатель на следующий элемент
};

void s_push(Node** top, int D);
void s_pop(Node** top);
void s_print(Node* top);
void s_read(Node** top);
void s_write(Node* top);
void menu();

void s_push(Node** top, int D) //функция типа void(ничего не возвращает), которая принимает указатель на вершину стека и переменную, которая будет записываться в ячейку
{
	Node* q; //Создаем новый указатель q. По сути это и есть наш новый элемент
	q = new Node(); //выделяем память для нового элемента
	q->Data = D; //Записываем необходимую сущность в Data элемента

	if (top == NULL)  //Если вершины нет, то есть стек пустой
	{
		*top = q; //вершиной стека будет новый элемент
	}
	else //если стек не пустой,
	{
		q->next = *top; //Проводим связь от нового элемента, к вершине
		*top = q; //Обозначаем, что вершиной теперь является новый элемент
	}
}

void s_pop(Node** top) // функция, которая принимает вершину top и сущность, которую нужно удалить
{
	Node* q = *top; //создаем указатель типа Node и приравниваем/ставим его на вершину стека
	Node* prev = NULL; //создаем указатель на предыдуший элемент, сначала он будет пустым

	while (q != NULL) //пока указатель q не пустой, мы будем выполнять код в цикле, если он все же пустой цикл заканчивается
	{
		if (q == *top) //если такой указатель равен вершине, то есть элемент, который нам нужно удалить - вершина
		{
			*top = q->next; //передвигаем вершину на следующий элемент
			free(q); //очищаем ячейку
			q->Data = NULL; //Далее во избежание ошибок мы обнуляем переменные в удаленной ячейке, так как в некоторых компиляторах удаленная ячейка имеет переменные не NULL значения, 
			q->next = NULL; // а дословно "Чтение памяти невозможно" или числа  "-2738568384" или другие, в зависимости от компилятора.
		}
		else //если элемент последний или находится между двумя другими элементами
		{
			prev->next = q->next;//Проводим связь от предыдущего элемента к следующему
			free(q); //очищаем ячейку 
			q->Data = NULL; //обнуляем переменные
			q->next = NULL;
		}
		// если Data элемента НЕ равна сущности, которую нам нужно удалить
		prev = q; //запоминаем текущую ячейку как предыдущую
		q = q->next;//перемещаем указатель q на следующий элемент
	}
}

void s_print(Node* top)  // Функция вывода на экран. Принимает указатель на вершину стека
{
	Node* q = top; //устанавливаем q на вершину
	while (q) //пока q не пустой (while(q) эквивалентно while(q != NULL))
	{
		cout << q->Data << '\n'; //выводим на экран данные ячейки стека
		q = q->next; //после того, как вывели, передвигаем q на следующий элемент (ячейку)
	}
}

void s_write(Node* top)
{
	FILE* f;
	fopen_s(&f, "test.txt", "w");

	if (!f)
		cout << "Ошибка чтения файла!" << '\n';

	Node* q = top;
	while (q)
	{
		fprintf_s(f, "%d ", q->Data);
		q = q->next;
	}

	fclose(f);
}

void s_read(Node** top)
{
	FILE* f;
	fopen_s(&f, "test.txt", "r");

	if (!f)
		cout << "Ошибка чтения файла!" << '\n';

	for (;;)
	{
		Node* q;
		q = new Node();
		fscanf_s(f, "%d", &q->Data);

		if (top == NULL)
		{
			*top = q;
		}
		else
		{
			q->next = *top;
			*top = q;
		}

		if (feof(f))
		{
			break;
		}
	}

	fclose(f);
}

void s_find(Node* top)
{
	Node* q = top;
	Node* nxt = top->next;
	while (q && nxt)
	{
		if(top->Data == nxt->Data)
		{
			cout << "Нужны элемент найден, Значение: " << top->Data << endl;
		}
		q = q->next;
		nxt = nxt->next;
	}
}

void menu()
{
	cout << "-----------------------" << '\n';
	cout << "Что Вы желаете сделать?" << '\n';
	cout << "1 - Добавить элемент" << '\n';
	cout << "2 - Удалить элемент" << '\n';
	cout << "3 - Определить, есть ли в стеке хотя бы один элемент, который равен следующему за ним элементу" << '\n';
	cout << "4 - Вывести стек" << '\n';
	cout << "5 - Записать стек в файл" << '\n';
	cout << "6 - Прочитать стек из файла" << '\n';
	cout << "7 - Выйти из программы" << '\n';
	cout << ">> ";
}



int main(void)
{
	setlocale(LC_ALL, "RUS");

	Node* top = NULL; // В начале выполнения программы у нас нет стека, соответственно, вершины нет, даем ей значение NULL
	//Дальше начинаем добавлять цифры от 1 до 5 в наш стек
	// почему в функцию мы передавали указатель на указатель вершины? Дело в том, что если бы мы ввели в функцию только указатель на вершину, 
	// то «Стек» создавался и изменялся только внутри функции, в главной функции вершина бы как была, так и оставалась NULL. 
	// Передавая указатель на указатель мы изменяем вершину *top в главной функции. 
	// Получается если функция изменяет стек, нужно передавать в нее вершину указателем на указатель, 
	// так у нас было в функциях push и delete. В функции print «Стек» не должен изменяться, поэтому мы передаем просто указатель на вершину.
	bool flag = false;

	do
	{
		menu();

		unsigned short int choice;
		cin >> choice;

		int D;

		switch (choice)
		{
		case _ADD:
			cout << "Ввод данных в стек" << '\n';
			cout << "------------------" << '\n';
			cout << "Введите элемент (число), который хотите ввести в стек:" << '\n' << ">> ";
			cin >> D;

			s_push(&top, D);
			break;
		case _DELETE:
			cout << "Удаление данных из стека" << '\n';
			cout << "------------------------" << '\n';

			s_pop(&top);
			break;
		case _SEARCH:
			cout << "Определение, есть ли в стеке хотя бы один элемент, который равен следующему за ним элементу" << '\n';
			cout << "-------------------------------------------------------------------------------------------" << '\n';

			s_find(top);
			break;
		case _PRINT:
			cout << "Вывод стека на экран" << '\n';
			cout << "--------------------" << '\n';

			s_print(top);
			break;
		case _WRITE:
			cout << "Запись стека в файл" << '\n';
			cout << "--------------------" << '\n';

			s_write(top);
			break;
		case _READ:
			cout << "Чтение стека из файла" << '\n';
			cout << "--------------------" << '\n';

			s_read(&top);
			break;
		case _EXIT:
			flag = true;
			cout << "Программа успешно завершила работу." << '\n';
			break;
		default:
			cout << "Неверный ввод. Повторите!" << '\n';
			break;
		}
	} while (!flag);

	return 0;
}

//допы 1-3
//#include <iostream>
//#include "stack.h"
//using namespace std;
//
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	char str[20];
//	int dl;
//	Stack* myStk = new Stack; //выделение памяти для стека
//	myStk->head = NULL;       //инициализация первого элемента 
//	while (strlen(str) % 2 != 0) {
//		cout << "Строка с четным количеством символов" << endl;
//		cin >> str;
//	}
//	dl = strlen(str);
//	for (int i = (dl / 2); i < dl; i++) {
//		push(str[i], myStk);
//	}
//	for (int i = 0; i < (dl / 2); i++) {
//		push(str[i], myStk);
//	}
//	show(myStk);
//}

//#include <iostream>
//#include <cmath>
//#include <string>
//#include <fstream>
//
//using namespace std;
//struct stack
//{
//	int ind;
//	stack* next;
//};
//void length(stack** el, int n)
//{
//	stack* i = new stack;
//	i->ind = n;
//	i->next = *el;
//	*el = i;
//}
//void out(stack* el)
//{
//	stack* i = el;
//	if (el == NULL)
//	{
//		cout << "Список пуст";
//		return;
//	}
//	while (i != NULL)
//	{
//		cout << i->ind << endl;
//		i = i->next;
//	}
//}
//int main()
//{
//	int min = 256, j = 0;
//	setlocale(LC_CTYPE, "Russian");
//	stack* el = NULL;
//	ifstream file1("1.txt");
//	char str[255];
//	int n;
//	while (!file1.eof())
//	{
//		file1.getline(str, 255);
//		n = strlen(str);
//		length(&el, n);
//		if (n < min)
//		{
//			min = n;
//			j++;
//		}
//	}
//	file1.close();
//	out(el);
//	cout << endl;
//	cout << "Длина самой маленькой строки:" << min << endl;
//	cout << "Её номер:" << j << endl;
//	return 0;
//}
//
//#include <iostream>
//#include "stack.h"
//using namespace std;
//void push(char x, Stack* myStk)   //Добавление элемента х в стек 
//{
//	Stack* e = new Stack;    //выделение памяти для нового элемента
//	e->data = x;             //запись элемента x в поле v 
//	e->next = myStk->head;   //перенос вершины на следующий элемент 
//	myStk->head = e;         //сдвиг вершины на позицию вперед
//}
//int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
//{
//	if (myStk->head == NULL)
//	{
//		cout << "Стек пуст!" << endl;
//		return -1;               //если стек пуст - возврат -1 
//	}
//	else
//	{
//		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
//		char a = myStk->head->data;   //запись числа из поля data в переменную a 
//		myStk->head = myStk->head->next; //перенос вершины
//		delete e;                        //удаление временной переменной
//		return a;                        //возврат значения удаляемого элемента
//	}
//}
//void show(Stack* myStk)    //Вывод стека
//{
//	Stack* e = myStk->head;    //объявляется указатель на вершину стека
//	char a;
//	if (e == NULL)
//		cout << "Стек пуст!" << endl;
//	while (e != NULL)
//	{
//		a = e->data;          //запись значения в переменную a 
//		cout << a << " ";
//		e = e->next;
//	}
//	cout << endl;
//}
