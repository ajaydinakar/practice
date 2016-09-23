#include<iostream>
using namespace std;
void insertion_sort(int []);
int main()
{
	const int size = 8;
	int arr[size] = { 8,4,71,45,63,5,3,7 };
	insertion_sort(arr);
	for (int i = 0; i < size-1; i++)
	{
		cout<<arr[i]<<",";
	}
}
void insertion_sort(int ar[])
{
	int size =sizeof(ar)*2;
	
	for (int j = 1; j < size-1; j++)
	{
		int key = ar[j];
		int i = j - 1;
		while (i >= 0 && ar[i] > key)
		{
			ar[i+1 ] = ar[i];
			i = i - 1;
		}
		ar[i+1] = key;
	}
}
