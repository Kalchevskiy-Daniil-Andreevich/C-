#include <iostream>

using namespace std;


struct Node                                 
{
    char x;                                   //инфо данные структуры
    Node* Next;                              //Указатель не следующее звено
};



struct List
{
    Node* Head, * Tail;                          //Указатели на начало списка и на конец

    List() : Head(NULL), Tail(NULL) {};            //Инициализация указателей как пустых
    ~List()                                   //Прототип деструктора. Деструктор для освобождения памяти от всего, что будет
    {
        Node* temp = Head;                             //Временный указатель на начало списка

        while (temp != NULL)                         //Пока в списке что-то есть
        {
            temp = Head->Next;                         //Резерв адреса на следующий элемент списка
            delete Head;                               //Освобождение памяти от первой структуры как элемента списка

            Head = temp;                               //Сдвиг начала на следующий адрес, который берем из резерва
        }
    }

    void Add(char x)                          
    {
        Node* temp = new Node;                      //Выделение памяти для нового звена списка
        temp->x = x;                                //Временное запоминание принятого параметра x
        temp->Next = NULL;                          //Указание, что следующее звено новосозданной структуры пока пустое

        if (Head != NULL)                           //Если список не пуст
        {
            Tail->Next = temp;                      //Указание, что следующее звено списка это новосозданная структура
            Tail = temp;
        }
        else Head = Tail = temp;              //Если список не пуст, добавление первого элемента
    }

    void Show()                             
    {
        cout << "-------ОЧЕРЕДЬ----------" << endl;
        Node* temp = Head;                          //Временный указатель на начало списка
        while (temp != NULL)                       //Пока в списке что-то встречается
        {
            cout << temp->x << " ";                //Выводим значения из списка на экран
            temp = temp->Next;                     //Сдвигаем указатель на начало на адрес следующего элемента
        }
        cout << endl << "------------------------" << endl;
    }

    void del()                    
    {
        if (Head != NULL)                   //Если список не пустой
        {
            Node* temp = Head;              //Обращаемся к началу списка с помощью вспомогательного указателя
            cout << "ЭЛЕМЕНТ " << Head->x << " ВЫШЕЛ" << endl;
            Head = Head->Next;              //Сдвиг начала списка
            delete temp;                    //Освобождение памяти от предыдущего звена списка
        }
    }

    int calc() // функция подсчёта числа элементов в очереди
    {
        int size = 0;
        Node* temp = Head;
        while (temp != NULL)                       //Пока в списке что-то встречается
        {
            size++;             //Увеличиваем счётчик на единицу
            temp = temp->Next;                     //Сдвигаем указатель на начало на адрес следующего элемента
        }
        return size;
    }

    void check() // Функция, проверяющая, есть ли случаи совпадения вводимого символа с последним элементом очереди 
    {
        Node* temp_h = Head;
        Node* temp_t = Tail;
        if (calc() > 1 && temp_h->x == temp_t->x)
        {
            cout << "Найдено совпадение! Удаляю..." << endl;
            del();
        }
    }
};

void menu()
{
    cout << "Что Вы желаете сделать?" << endl;
    cout << "1 - Добавить элемент в очередь" << endl;
    cout << "2 - Удалить элемент из очереди" << endl;
    cout << "3 - Посчитать число элементов в очереди" << endl;
    cout << "4 - Выйти из приложения" << endl;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    List lst;

    bool flag = false;
    unsigned short int choice;

    do
    {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Введите символ, который желаете добавить в список:" << endl;
            char ch;
            cin >> ch;
            lst.Add(ch);
            lst.check();
            lst.Show();
            break;
        case 2:
            lst.del();
            lst.check();
            lst.Show();
            break;
        case 3:
            cout << "Всего символов в очереди " << lst.calc() << "." << endl;
            break;
        case 4:
            flag = true;
            break;
        default:
            cout << "Ошибка ввода. Повторите." << endl;
            break;
        }

    } while (!flag);

    cout << "Программа успешно завершила работу" << endl;

    return 0;
}


//допы 1-3

////dop1
///*1. В приложении 1 приведен проект, в котором 
//реализована очередь на основе односвязного списка
//с приоритетным включением. На основе данного проекта
//разработать функции, которые предлагается создать 
//в данном приложении.*/
//#include<iostream>
//using namespace std;
//struct Item
//{
//	int data;
//	Item* next;
//};
//Item* head, * tail;
//
//bool isNull(void)    //Проверка на пустоту
//{
//	return (head == nullptr);
//}
//void deletFirst()   //Извлечение элемента из начала
//{
//	if (isNull())
//		cout << "Очередь пуста" << endl;
//	else
//	{
//		Item* p = head;
//		head = head->next;
//		delete p;
//	}
//}
//void deletlast()   //Извлечение элемента из начала
//{
//	if (isNull())
//		cout << "Очередь пуста" << endl;
//	else
//	{
//		Item* p;
//		tail->data = NULL;
//
//	}
//}
//void getFromHead()  //Получение элемента из начала
//{
//	if (isNull())
//		cout << "Очередь пуста" << endl;
//	else
//		cout << "Начало = " << head->data << endl;
//}
//void getFromTail()  //Получение элемента из конца
//{
//	if (isNull())
//		cout << "Очередь пуста" << endl;
//	else
//		cout << "Конец = " << tail->data << endl;
//}
//void insertToQueue(int x)  //Добавление элемента в очередь 
//{
//	Item* p = new Item;      //новый указатель 
//	p->data = x;
//	p->next = nullptr;
//	Item* v = new Item;      //указатель для нового числа
//	Item* p1 = new Item;
//	Item* p2 = new Item;
//	int i = 0;               //флажок 
//	if (isNull())
//		head = tail = p;
//	else
//	{
//		p2 = head; p1 = head; // !!!Чтобы реализовать ввод LiFo необходимо чтобы указатель p2 был позади, FiFo наобарот
//		while (p1 != nullptr)  //пока очередь не закончится
//		{
//			if (i == 1) //ТАКЖЕ НЕОБХОДИМЫ ДЛЯ РЕАЛИЗАЦИИ LiFo
//			{
//				if (i == 1)
//				{
//					if (x > p1->data)  //число больше, чем в очереди
//					{
//						v->data = x;
//						v->next = p1;
//						p2->next = v;
//						return;
//					}
//					if (x == p1->data)
//					{
//						v->data = x;
//						v->next = p1->next;
//						p1->next = v;
//						return;
//					}
//					p2 = p2->next;
//				}
//				if (x > p1->data)
//				{
//					v->data = x;
//					v->next = p1;
//					head = v;
//					return;
//				}
//				if (p1->next == nullptr)
//				{
//					v->data = x;
//					v->next = nullptr;
//					tail->next = v;
//					tail = v;
//					return;
//				}
//				i = 1;
//
//				p1 = p1->next;      // следующее число
//			}
//			else // else необходимое для реализации вставки LiFo
//			{
//				if (x >= p1->data)
//				{
//					v->data = x;
//					v->next = p2;
//					head = v;
//					return;
//				}
//			}
//			p1 = p1->next; //ТАКЖЕ НЕОБХОДИМЫ ДЛЯ РЕАЛИЗАЦИИ LiFo
//			i = 1;
//		}
//		if (p1 == NULL) // Выражение ДЛЯ РЕАЛИЗЦИИ LiFo
//		{
//			v->data = x;
//			v->next = tail;
//			p2->next = v;
//		}
//	}
//}
//
//void printQueue()             //Вывод очереди
//{
//	int g;
//	Item* p = new Item;
//	if (isNull())
//		cout << "Очередь пуста" << endl;
//	else
//	{
//		cout << "Очередь = ";
//		p = head;
//		while (!isNull())
//		{
//			if (p != nullptr)
//			{
//				g = p->data;
//				if (g == 0) {
//
//				}
//				else { cout << p->data << " "; cout << "->"; }
//				p = p->next;
//			}
//			else
//			{
//				cout << "NULL" << endl;
//				return;
//			}
//		}
//	}
//}
//
//void clrQueue()           //Очистка очереди
//{
//	while (!isNull()) deletFirst();
//}
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	int i = 1, choice = 1, z; head = nullptr;  tail = nullptr;
//	while (choice != 0)
//	{
//		cout << "1 - добавить элемент" << endl;
//		cout << "2 - получить элемент с начала" << endl;
//		cout << "3 - извлечь элемент с начала" << endl;
//		cout << "4 - вывести элементы" << endl;
//		cout << "5 - очистить очередь" << endl;
//		cout << "6 - получить элемент с конца" << endl;
//		cout << "0 - выход" << endl;
//		cout << "Выберите действие  ";  cin >> choice;
//		switch (choice)
//		{
//		case 1: cout << "Введите элемент:  "; cin >> z;
//			insertToQueue(z); printQueue();  break;
//		case 2: getFromHead(); break;
//		case 3: deletFirst();  break;
//		case 4: printQueue();  break;
//		case 5: clrQueue();    break;
//		case 6: getFromTail(); break;
//		case 7: deletlast(); break;
//		}
//	}
//	return 0;
//}

//dop2
/*2. Создать очередь с вещественными числами, и
заполнить ее с клавиатуры. Выполнить циклический
сдвиг элементов в очереди так, чтобы в ее начале
был расположен наибольший элемент.*/

//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//struct Node {
//	float Number;
//	Node* next;
//};
//
//struct Queue {
//	int size = 0;
//	Node* head;
//	Node* tail;
//};
//void CreateQueue(Queue* Q) {
//	Q->head = new Node();
//	Q->head->next = NULL;
//	Q->tail = Q->head;
//	Q->size = 0;
//}
//void AddElem(Queue* Q) {
//	float newElem;
//	cout << "Введите элемент:" << endl;
//	cin >> newElem;
//	cout << endl;
//	Q->tail->next = new Node();
//	Q->tail = Q->tail->next;
//	Q->tail->Number = newElem;
//	Q->tail->next = NULL;
//	Q->size++;
//}
//int OutQueue(Queue* Q) {
//	if (Q->head == Q->tail) {
//		cout << "Очередь пуста" << endl;
//		return 0;
//	}
//	else {
//		Node* Temp = Q->head->next;
//		cout << endl;
//		while (Temp) {
//			cout << Temp->Number << endl;
//			Temp = Temp->next;
//		}
//	}
//}
//int Shift(Queue* Q) {
//	if (Q->head == Q->tail) {
//		cout << "Очередь пуста" << endl;
//		return 0;
//	}
//	else {
//		float max = 0;
//		Node* Temp = Q->head->next;
//		while (Temp) {
//			if (Temp->Number > max)
//				max = Temp->Number;
//			Temp = Temp->next;
//		}
//		cout << "Наибольшее значение:" << max << endl;
//		cout << "Очередь со сдвигом:" << endl;
//		Temp = Q->head;
//		Temp->Number = max;
//		cout << Temp->Number << endl;
//		while (Temp) {
//			if (Temp->Number != max) cout << Temp->Number << endl;
//			Temp = Temp->next;
//		}
//		cout << endl << endl;
//	}
//}
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	Queue t;
//	int choice;
//	CreateQueue(&t);
//	for (;;)
//	{
//		cout << "Выберите команду:" << endl;
//		cout << "1 - Добавление элемента в очередь" << endl;
//		cout << "2 - Вывод очереди" << endl;
//		cout << "3 - Циклический сдвиг" << endl;
//		cout << "4 - Выход" << endl;
//		cin >> choice;
//		switch (choice)
//		{
//
//		case 1:
//			AddElem(&t);
//			break;
//		case 2:
//			OutQueue(&t);
//			break;
//		case 3:
//			Shift(&t);
//			break;
//		case 4:
//			return 0;
//			break;
//
//		}
//	}
//}

//dop3
/*3. Содержимое текстового файла f, разделенное на строки,
переписать в текстовый файл g, перенося при этом в конец
каждой строки все входящие в нее цифры (с сохранением
исходного взаимного порядка, как среди цифр, так и среди
остальных литер строки). Использовать очереди.*/

//
//
//#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <string>
//#include <cctype>
//#include <iomanip>
//using namespace std;
//struct Node1 {
//	char Letter;
//	Node1* next;
//};
//
//struct Queue1 {
//	Node1* head;
//	Node1* tail;
//};
//
//struct Node2 {
//	char Number;
//	Node2* next;
//};
//
//struct Queue2 {
//	Node2* head;
//	Node2* tail;
//};
//void CreateQueue1(Queue1* Liter) {
//	Liter->head = new Node1();
//	Liter->head->next = NULL;
//	Liter->tail = Liter->head;
//}
//
//void CreateQueue2(Queue2* Number) {
//	Number->head = new Node2();
//	Number->head->next = NULL;
//	Number->tail = Number->head;
//}
//void symbol(Queue1* Liter, Queue2* Number) {
//	ifstream file("f.txt");
//	string Temp;
//	char Symbol;
//	int TempInt;
//	getline(file, Temp);
//	cout << "исходная строка:" << Temp << endl;
//	for (int i = 0; i < Temp.length(); i++) {
//		Symbol = Temp[i];
//		if ((Symbol >= 97 && Symbol <= 122) || (Symbol >= 65 && Symbol <= 90)) {
//			Liter->tail->next = new Node1;
//			Liter->tail = Liter->tail->next;
//			Liter->tail->Letter = Symbol;
//			Liter->tail->next = NULL;
//		}
//		if (Symbol >= 48 && Symbol <= 57) {
//			Number->tail->next = new Node2();
//			Number->tail = Number->tail->next;
//			Number->tail->Number = Symbol;
//			Number->tail->next = NULL;
//		}
//	}
//	Node1* Temp1 = Liter->head->next;
//	Node2* Temp2 = Number->head->next;
//	cout << "буквы:" << endl;
//	while (Temp1) {
//		cout << Temp1->Letter;
//		Temp1 = Temp1->next;
//	}
//	cout << endl;
//	cout << "цифры:" << endl;
//	while (Temp2) {
//		cout << Temp2->Number;
//		Temp2 = Temp2->next;
//	}
//	cout << endl;
//	file.close();
//
//	ofstream File("g.txt");
//	Temp1 = Liter->head->next;
//	Temp2 = Number->head->next;
//	while (Temp1) {
//		File << Temp1->Letter;
//		Temp1 = Temp1->next;
//	}
//	while (Temp2) {
//		File << Temp2->Number;
//		Temp2 = Temp2->next;
//	}
//	File.close();
//	cout << "строка записана в файл" << endl;
//}
//int main() {
//	setlocale(LC_ALL, "rus");
//	Queue1 Q1;
//	Queue2 Q2;
//	CreateQueue1(&Q1);
//	CreateQueue2(&Q2);
//	symbol(&Q1, &Q2);
//}
//}