#include <iostream>
#include <cstring>
using namespace std;

main()
{
	char command[256];
	cerr << "echo >";

	while(1)
	{
		cin >> command;
		if(strcmp(command,"quit")==0)
			break;
		cout << command << " !!" << endl;
	}
}













		








