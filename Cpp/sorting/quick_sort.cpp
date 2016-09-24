//**********************************            Quick sort program            *********************************** *
//***************                 Ref:Introduction to algorithms by Thomas H Cormen****************************
#include<iostream>
using namespace std;
void quick_sort(int [],int,int);
int partition(int [],int,int);
int main()
{
	const int size = 8;
	int arr[size] = { 8,4,71,45,63,5,3,7 };
	cout << "unsorted array is";
	for (int i = 0; i <= size - 1; i++)
	{
		cout << arr[i] << ",";
	}
	cout << endl;
	cout << "sorted array is";
	quick_sort(arr,0,size-1);
	for (int i = 0; i <= size-1; i++)
	{
		cout<<arr[i]<<",";
	}
}
void quick_sort(int a[] ,int p ,int r)
{
	int q;
	if (p < r)
	{
		q = partition(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);

	}
}
int partition(int a[], int p, int r)
{
	int temp;
	int x = a[r];
	int i = p - 1;
	for (int j = p; j <= r -1; j++)
	{
		if (a[j] <= x)
		{
			i = i + 1;
				temp = a[i];
			a[i] = a[j];
			a[j] = temp;

		}
	}
	temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	return i + 1;

}


