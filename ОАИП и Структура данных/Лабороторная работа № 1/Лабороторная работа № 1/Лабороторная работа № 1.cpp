#include <iostream>
using namespace std;


//1 задания

float frank(float a, float b, float(*f)(float)) {
  float x, e = 0.001;
    do{
      x = (a + b) / 2;
      if (f(x) * f(a) <= 0)
        b = x;
      else a = x;
    } while (abs(a - b) > 2 * e);
    cout << x << endl;
    return x;
  }


float fun1(float x)
{
  return pow(x,3) + x - 3;
}


float fun2(float x)
{
  return exp(x) - 2;
}


int main()
{
  setlocale(LC_CTYPE, "Russian");
  float a1, b1;
  cout << "Значения 1-ого корня: " << endl;
  cin >> a1;
  cout << "Значения 2-ого корня: " << endl;
  cin >> b1;
  float *a = &a1;
  float *b = &b1;
  frank(*a, *b, fun1);
  frank(*a, *b, fun2); 
}


//2 задания

int fmax(int a, ...) 
{ 
 int* p = &a; 
 int min=1; 
 for (int i = 0; i < a; i++) 
 { 
  if (*(++p) < min) 
   min = *p; 
 } 
 cout << min; 
 return min; 
} 
 
int main() 
{ 
 fmax(8, 5, 12, 89, -42, 45, -13, 98); 
 return 0;
} 


//1 dop

//int mn(int a, ...)
//{
//    int* p = &a;
//    int max = 1;
//    for (int i = 0; i < a; i++)
//    {
//        if (*(++p) > max)
//            max = *p;
//    }
//    cout << max;
//    return max;
//}
//
//int main()
//{
//    mn(3, 10, -13, 98);
//    return 0;
//}


//2 dop

//float MinMatr(int aa, ...) 
//{ 
// int *a = &aa; 
// int min = 100; 
// for (int i = 0; i < 9; i++) 
// { 
//  if (*(a++) < min) 
//   min = *a; 
// } 
// cout << min; 
// return min; 
//} 
// 
//int main() 
//{ 
// MinMatr(8, 12, 54, -12, -45, 0, 34, 23, 75); 
// return 0;
//} 


//3 dop

//void StrSym() 
//{ 
// char* Size = new char[256]; 
// cout << "Введите предложение, заканчивающееся точкой:\n"; 
// cin.getline(Size, 256, '.'); 
// short i = 0, Probel = 0, LastP = 0, Length = strlen(Size), Max = 0; 
// while (i != Length) 
// { 
//  if (*(Size + i) == ' ') 
//  { 
//   Probel = i; 
//   short Word = Probel - LastP - 1; 
//   if (Word > Max) 
//   { 
//    Max = Word; 
//   } 
//   LastP = Probel; 
//  } 
//  if ((i + 1) == Length) 
//  { 
//   short Word = Length - LastP - 1; 
//   if (Word > Max) 
//   { 
//    Max = Word; 
//   } 
//  } 
//  i++; 
// } 
// cout << "Максимальное количество букв в слове: " << Max; 
//} 
//
//int main() 
//{ 
// setlocale(LC_CTYPE, "Russian"); 
// StrSym(); 
//}