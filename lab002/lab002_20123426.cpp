// Lab 002
// Name : Jinsung Choi
// ID : 20123426

#include <iostream>
using namespace std;

int Fib(int n);

int main()
{
	int n;

	while(1)
	{
		cerr << "Enter the number n :" << endl;
		cin >> n;
		
		if(n == -1)
			break;

		cout << "Fib (" << n << ") = " << Fib(n) << endl;
	}
}

int Fib(int n)
{
	if(n <= 1)
		return n;
	else
		return Fib(n-2)+Fib(n-1);
}

 

 



