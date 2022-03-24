#include<iostream>
using namespace std;
int Multiplicacion(int num1, int num2)
{
   if(num1<num2)
    return Multiplication(num2, num1);

   else if(num2!=0)
   return (num1+Multiplication(num1, num2-1));

   else
    return 0;
}
int main()
{
    int num1, num2;
    cout<<"Numeros a multiplicar"<<endl;
    cout<<"Numero 1: ";
    cin>>num1;
    cout<<"Numero 2: ";
	cin>>num2;
    cout<<"Multiplicacion por Recursion => "<<Multiplication(num1,num2);
}
