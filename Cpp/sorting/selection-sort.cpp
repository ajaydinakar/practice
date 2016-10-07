//ref c++ Gaddis text book
#include <iostream>
using namespace std;
void acountsort(int[], int);
void showdetail(int [], int);
int main()
{
	
	int array[] = { 3,1,2,11,5,6,8,7,9 ,12};
	const int n = sizeof(array) / 4;
	showdetail(array, n);
	acountsort(array, n);
	showdetail(array, n);
	return 0;
}
void acountsort(int array[], int z)
{

	int scan, minindex, minvalue;
	for (scan = 0; scan < (z - 1); scan++)
	{
		minindex = scan;
		minvalue = array[scan];
		for (int i = scan + 1; i < z; i++)
		{
			if (array[i] < minvalue)
			{
				minvalue = array[i];
				minindex = i;


			}
		}


		array[minindex] = array[scan];
		array[scan] = minvalue;
	}
}
