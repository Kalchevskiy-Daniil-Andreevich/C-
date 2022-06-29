//Дерево  это структура, имеющая следующие свойства :
//–  существует единственный элемент(узел, вершина), на который не ссылается никакой другой и который называется корнем;
//– начиная с корня и следуя по определенной цепочке указателей, можно осуществить доступ к любому элементу структуры;
//– на каждый элемент, кроме корня, имеется единственная ссылка.
//Бинарное дерево поиска – это упорядоченное дерево, каждая вершина которого имеет не более двух поддеревьев :
//в левом поддереве содержатся ключи, имеющие значения, меньшие, чем значение данного узла, в правом поддереве содержатся ключи, имеющие значения, большие, чем значение данного узла.

#include <iostream>

using namespace std;

int tabs = 0;
int kol_vo = 0;

struct Branch
{
	int Data;
	Branch* LeftBranch;
	Branch* RightBranch;
};

void Add(int aData, Branch*& aBranch)
{
	if (!aBranch)	
	{ 
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else
	{
		if (aBranch->Data > aData)
		{ 
			Add(aData, aBranch->LeftBranch);
		}
		else
		{
			{ 
				Add(aData, aBranch->RightBranch);
			};
		}
	}
}

void print(Branch* aBranch)
{
	if (!aBranch)	//Если ветки не существует - выходим. Выводить нечего
		return; 
	else	//рекурсивно выписываем значения каждого элемента
	{
	tabs += 5; // отступы для красивого вывода
	print(aBranch->LeftBranch); //Выведем ветку и ее подветки слева

	for (int i = 0; i < tabs; i++)
		cout << " "; //Потом отступы
	cout << aBranch->Data << endl; //Данные этой ветки

	print(aBranch->RightBranch);//И ветки, что справа
	tabs -= 5; //После уменьшим кол-во отступов
	return;
	}
}

void is_Empty(Branch*& aBranch)
{
	if (!aBranch)
	{
		cout << "Дерево пустое...";
	}
	else
	{
		cout << "Дерево не пустое...";
	}
}

void pr_obh(Branch*& aBranch)
{
	if (NULL == aBranch)
		return; //Если дерева нет, выходим
	
	cout << aBranch->Data << endl; //Посетили узел
	
	pr_obh(aBranch->LeftBranch); //Обошли левое поддерево
	pr_obh(aBranch->RightBranch); //Обошли правое поддерево
}

void add_elem(int aData, Branch*& aBranch)
{
	if (!aBranch)
	{
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else
	{
		if (aData < aBranch->Data)
		{
			add_elem(aData, aBranch->LeftBranch);
		}
		else if (aData > aBranch->Data)
		{
			add_elem(aData, aBranch->RightBranch);
		}
	}
}

void FreeTree(Branch* aBranch)
{
	if (!aBranch) return;
	FreeTree(aBranch->LeftBranch);
	FreeTree(aBranch->RightBranch);
	delete aBranch;
	return;
}

Branch* del_elem(Branch*& aBranch, int aData)
{
	if (aBranch == NULL)
		return aBranch;
	if (aData == aBranch->Data)
	{
		Branch* tmp;
		if (aBranch->RightBranch == NULL)
			tmp = aBranch->LeftBranch;
		else 
		{
			Branch* ptr = aBranch->RightBranch;
			if (ptr->LeftBranch == NULL)
			{
				ptr->LeftBranch = aBranch->LeftBranch;
				tmp = ptr;
			}
			else 
			{
				Branch* pmin = ptr->LeftBranch;
				while (pmin->LeftBranch != NULL) 
				{
					ptr = pmin;
					pmin = ptr->LeftBranch;
				}
				ptr->LeftBranch = pmin->RightBranch;
				pmin->LeftBranch = aBranch->LeftBranch;
				pmin->RightBranch = aBranch->RightBranch;
				tmp = pmin;
			}
		}
		delete aBranch;
		return tmp;
	}
	else if (aData < aBranch->Data)
		aBranch->LeftBranch = del_elem(aBranch->LeftBranch, aData);
	else
		aBranch->RightBranch = del_elem(aBranch->RightBranch, aData);
	return aBranch;
}


void menu()
{
	cout << "Что Вы желаете сделать?" << '\n';
	cout << "1 - Ввести количество элементов для дерево" << '\n';
	cout << "2 - Проверим дерево на пустоту до его заполнения" << '\n';
	cout << "3 - Вывод бинарного дерева: " << '\n';
	cout << "4 - Прямой обход бинарного дерева: " << '\n';
	cout << "5 - Добавим новый элемент в бинарное дерево: " << '\n';
	cout << "6 - Удалить элемент в дереве: " << '\n';
	cout << "7 - Удаление бинарного дерева: " << '\n';
	cout << ">> ";
}

int main()
{
	setlocale(LC_ALL, "rus");

	Branch* Root = 0;

	int vel;
	int element;
	int k;

	bool flag = false;
	unsigned short int choice;

	do
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите кол-во элементов для будущего дерева: ";
			cin >> vel;
			cout << "Элементы введены" << endl;
			cout << endl;
			for (int i = 0; i < vel; i++)
			{
				Add(rand() % 100, Root);
			}
			break;
		case 2:
			cout << "Проверим дерево на пустоту: " << endl;
			is_Empty(Root);
			cout << endl;
			break;
		case 3:
				cout << "Вывод бинарного дерева: " << endl;
				print(Root);
				cout << endl;
		case 4:
			cout << "Прямой обход бинарного дерева:: " << endl;
			print(Root);
			cout << endl;
		case 5:
			cout << "Добавим новый элемент в бинарное дерево:" << endl;
			cout << "Введите новый элемент: ";
			cin >> element;
			add_elem(element, Root);
		case 6:
			cout << "Удалим элемент из бинарного дерева:" << endl;
				cout << "Введите элемент: ";
				cin >> element;
				del_elem(Root, element);
		case 7:
			FreeTree(Root);
				cout << "Вся динамическая память очищена..." << endl;
		}
	} while (!flag);
	return 0;
}

//допы 1-3

//доп 1

// struct node {
	//	int info;
	//	node* l, * r;
	//};
	//
	//node* tree1 = NULL;
	//
	//void push(int a, node** t) {
	//	if ((*t) == NULL) {
	//		(*t) = new node;
	//		(*t)->info = a;
	//		(*t)->l = (*t)->r = NULL;
	//		return;
	//	}
	//
	//	if (a > (*t)->info)
	//		push(a, &(*t)->r);
	//	else
	//		push(a, &(*t)->l);
	//}
	//
	//void print(node* t, int u) {
	//	if (t == NULL) return;
	//	else
	//	{
	//		print(t->r, ++u);
	//		for (int i = 0; i < u; ++i)
	//			cout << "|";
	//		cout << t->info << endl;
	//		u--;
	//	}
	//	print(t->l, ++u);
	//
	//
	//}
	//void check_left(node* t)
	//{
	//	int col = 0;
	//	if (t->l != NULL)
	//	{
	//		check_left(t->l);
	//		col++;
	//	}
	//	if (t->r != NULL)
	//		check_left(t->r);
	//	cout << col << ' ';
	//}
	//void del(node** t)
	//{
	//	if (t != nullptr)
	//	{
	//		if ((*t)->l)del(&(*t)->l);
	//		if ((*t)->r)del(&(*t)->r);
	//		delete* t;
	//		*t = nullptr;
	//	}
	//}
	//void check(node* t)
	//{
	//	if (t == NULL)
	//	{
	//		cout << "äåðåâà íåò" << endl;
	//	}
	//	else
	//	{
	//		return;
	//	}
	//}
	//int main() {
	//	setlocale(0, "");
	//	int amount, newnumber, ans = 0;
	//	cout << "ââåäèòå êîëè÷åñòâî ýëåìåíòîâ:\t";
	//	cin >> amount;
	//	cout << "\nââîäèòå ÷èñëà:\n";
	//	for (int i = 0; i < amount; ++i) {
	//		cin >> newnumber;
	//		push(newnumber, &tree1);
	//	}
	//	cout << "\näåðåâî:\n";
	//	print(tree1, 0);
	//	cout << endl;
	//	cout << "êîëè÷åñòâî ëåâûõ äî÷åðíèõ âåðøèí äåðåâà:";
	//	check_left(tree1);
	//	del(&tree1);
	//	cout << endl;
	//	check(tree1);
	//}

//доп 2


//struct node {
//	int info;
//	node* l, * r;
//};
//
//node* tree1 = NULL;
//
//void push(int a, node** t) {
//	if ((*t) == NULL) {
//		(*t) = new node;
//		(*t)->info = a;
//		(*t)->l = (*t)->r = NULL;
//		return;
//	}
//
//	if (a > (*t)->info)
//		push(a, &(*t)->r);
//	else
//		push(a, &(*t)->l);
//}
//
//void print(node* t, int u) {
//	if (t == NULL) return;
//	else
//	{
//		print(t->r, ++u);
//		for (int i = 0; i < u; ++i)
//			cout << "|";
//		cout << t->info << endl;
//		u--;
//	}
//	print(t->l, ++u);
//
//
//}
//void printLeaf(node* t)
//{
//
//
//	if ((t->l == nullptr) && (t->r == nullptr))
//	{
//		cout << t->info << " ";
//	}
//	else
//	{
//		if (t->l) printLeaf(t->l);
//		if (t->r) printLeaf(t->r);
//	}
//}
//void del(node** t)
//{
//	if (t != nullptr)
//	{
//		if ((*t)->l)del(&(*t)->l);
//		if ((*t)->r)del(&(*t)->r);
//		delete* t;
//		*t = nullptr;
//	}
//}
//void check(node* t)
//{
//	if (t == NULL)
//	{
//		cout << "Äåðåâà íåò" << endl;
//	}
//	else
//	{
//		return;
//	}
//}
//
//int main() {
//	setlocale(0, "");
//	int Amount, newNumber;
//	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ:\t";
//	cin >> Amount;
//	cout << "\nÂâîäèòå ×èñëà:\n";
//	for (int i = 0; i < Amount; ++i) {
//		cin >> newNumber;
//		push(newNumber, &tree1);
//	}
//	cout << "\nÄåðåâî:\n";
//	print(tree1, 0);
//	cout << endl;
//	cout << "Ëèñòüÿ:";
//	printLeaf(tree1);
//	del(&tree1);
//	cout << endl;
//	check(tree1);
//}

//доп 3

//struct node {
//	int info;
//	node* l, * r;
//};
//
//node* tree1 = NULL;
//
//void push(int a, node** t) {
//	if ((*t) == NULL) {
//		(*t) = new node;
//		(*t)->info = a;
//		(*t)->l = (*t)->r = NULL;
//		return;
//	}
//
//	if (a > (*t)->info)
//		push(a, &(*t)->r);
//	else
//		push(a, &(*t)->l);
//}
//
//void print(node* t, int u) {
//	if (t == NULL) return;
//	else
//	{
//		print(t->r, ++u);
//		for (int i = 0; i < u; ++i)
//			cout << "|";
//		cout << t->info << endl;
//		u--;
//	}
//	print(t->l, ++u);
//
//
//}
//int traverse(node* t)
//{
//	int n = 0;
//	if (t != NULL) {
//		n += traverse(t->l);
//		n += t->info;
//		n += traverse(t->r);
//	}
//	return n;
//}
//void del(node** t)
//{
//	if (t != nullptr)
//	{
//		if ((*t)->l)del(&(*t)->l);
//		if ((*t)->r)del(&(*t)->r);
//		delete* t;
//		*t = nullptr;
//	}
//}
//void check(node* t)
//{
//	if (t == NULL)
//	{
//		cout << "Äåðåâà íåò" << endl;
//	}
//	else
//	{
//		return;
//	}
//}
//int main() {
//	setlocale(0, "");
//	int Amount, newNumber, ans;
//	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ:\t";
//	cin >> Amount;
//	cout << "\nÂâîäèòå ×èñëà:\n";
//	for (int i = 0; i < Amount; ++i) {
//		cin >> newNumber;
//		push(newNumber, &tree1);
//	}
//	cout << "\nÄåðåâî:\n";
//	print(tree1, 0);
//	cout << endl;
//	ans = traverse(tree1);
//	cout << "Ñóììà âñåõ âåðøèí ðàâíà=" << ans << endl;
//	del(&tree1);
//	cout << endl;
//	check(tree1);
//}