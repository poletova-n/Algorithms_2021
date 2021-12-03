#include <iostream>
using namespace std;
int main()
{
	
	int arr[5]={1, 2, 5, 8, 9};
	for (int i = 0; i < 5; i++)
	{
	
		if (arr[i] % 2 == 0)
		{
			cout << arr[i] << endl;
		}
		
	}
	for (int j = 0; j < 5; j++)
	{
		
		if (arr[j] % 2 == 1)
		{
			cout << arr[j] << endl;
		}

	}
}

