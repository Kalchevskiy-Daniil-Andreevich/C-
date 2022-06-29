#include<iostream>
#include<forward_list>
#include<vector>
#include <ctime>
#include<list>
#include <deque>
#include <string>

using namespace std;

enum condition 
{
    on, off, sleep_mode
};

void zadanie_1()
{

	setlocale(LC_CTYPE, "Russian");

	int pc_condition;

	bool exit = true;

	while (exit)
	{
		cout << "Выберите состояние PC: Где 0-это включенный PC, 1-Выключенный PC, 2-PC в состоянии покоя;" << endl;
		cin >> pc_condition;

		switch (pc_condition)
		{
		case on:
			cout << "PC включен; " << endl;
			break;

		case  off:
			cout << "PC выключен; " << endl;
			break;

		case sleep_mode:
			cout << "PC находится в спящем режиме;"<< endl;
			break;

		default:
			cout << "Выберите действия от 0-2: " << endl;
		}
		    cout << "Хотите продолжить выбор? Если да=1, нет-0" << endl;
			cin >> exit;
	}
}

//это динамический массив, способный увеличиваться по мере необходимости для содержания всех своих элементов. 

void zadanie_7()
{
	setlocale(LC_CTYPE, "Russian");

	vector<int> vect;
	int max = 0;

	for (int i = 0; i < 5; i++)
		vect.push_back(10 - i); // добавляем числа в конец массива

	for (int i = 0; i < vect.size(); i++) {
		if (max < vect[i]) 
		{
			max = vect[i];
		}
	}
	cout << max << ' ';
	cout << endl;
}


void zadanie_8()
{

        std::deque<int> deq;
        for (int count = 0; count < 4; ++count)
        {
            deq.push_back(count); // вставляем числа в конец массива
            deq.push_front(10 - count); // вставляем числа в начало массива
        }

        int min = 100;

        for (int index = 0; index < deq.size(); ++index) {
            if (min > deq[index])
                min = deq[index];
        }
        deq.push_front(min);
    
        for (int index = 0; index < deq.size(); index++) {

            cout << deq[index] << ' ';
        }
        cout << '\n';
}


void zadanie_9() {
    int arr[] = { 5, 34, 5, 3, 12, 21, 25 };
    int max = 0, min = 100;
    for (int i = 0; i < 7; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    int sum = max + min;
    cout << sum;
}

//двусвязный список

void zadanie_11()
{
    int x;
    setlocale(LC_ALL, "rus");

    list<int> newlist = { 6, 2, 8, 4, 5 };
    cout << "Изначальный список:\n";
    for (int n : newlist)
    {
        cout << n << "\t";
    }
    cout << "\n:\n";
    cin >> x;
    newlist.remove(x);
    newlist.push_front(x);
    for (int n : newlist)
    {
        cout << n << "\t";
    }
}


void zadanie_13()
{
    int value;
    forward_list<int> newlist = { 6, 2, 8, 4, 5 };
    cout << "Изначальный список:\n";
    for (int n : newlist)
    {
        cout << n << "\t";
    }
    newlist.clear();
    cout << "\nДобавляем:\n";
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        newlist.push_front(value);
    }
    for (int n : newlist)
    {
        cout << n << "\t";
    }
}


int main()
{
	setlocale(LC_CTYPE, "Russian");

	cout << "Задания 1:" << endl << endl;
	zadanie_1();

    cout << endl << endl << "Задания 7:" << endl << endl;
    zadanie_7();

	cout << endl << "Задания 8:" << endl << endl;
	zadanie_8();

	cout << endl << "Задания 9:" << endl<<endl;
    zadanie_9();

	cout << endl << "Задания 11:" << endl << endl;
	zadanie_11();

	cout <<endl << endl << "Задания 13:" << endl << endl;
	zadanie_13();
}