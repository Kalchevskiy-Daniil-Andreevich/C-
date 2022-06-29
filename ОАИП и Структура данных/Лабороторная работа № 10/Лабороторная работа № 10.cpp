//смешанной (две или более функций вызывают друг друга попеременно),
//ветвящейся (когда рекурсивный вызов содержится в теле функции более одного раза, либо производится в цикле), вложенной (имеется вызов функции внутри обращения к самой функции). 
#include <iostream>
#include <cmath>

using namespace std;

double numcq(int a, int b)
{
	if (b == 0)
		return 0;
	else
		return floor(a / b) + numcq(b, fmod(a, b));
}

int main()
{
	setlocale(LC_ALL, "RUS");

	double a, b;
	cout << "Введите первую сторону прямоугольника a: " << '\n';
	cout << ">> "; cin >> a;

	cout << "Введите вторую сторону прямоугольника b (b < " << a << "): " << '\n';
	cout << ">> "; cin >> b;

	cout << numcq(a, b) << " квадрата(-ов)" << '\n';

	return 0;
}


//int A(int m, int n)
//{
//	if (m == 0 || n == 0)
//	{
//		return n + 1;
//	}
//	else if (m > 0)
//	{
//		return A(m, 0) + A(m - 1,1);
//	}
//	else if (n > 0)
//	{
//		return A(m, n) + A(m - 1, A(m, n - 1));
//	}
//}
//
//int main()
//{
//	setlocale(LC_ALL, "RUS");
//	int m, n;
//	cout << "Введите m:" << '\n';
//	cout << ">> "; cin >> m;
//	cout << "Введите n:" << '\n';
//	cout << ">> "; cin >> n;
//	cout << "A(m, n) = " << A(m, n) << '\n';
//	return 0;
//}


//допы 1-3

//доп 1

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

//cout << "Введите цифру:";
//cin >> A;
//cout << endl;
//int i;
//for (i = 0; i < A; i++)
//	arr[i] = i + 1;
//ch(0);
//file1.close();
//cout << "Данные записаны в файл." << endl;