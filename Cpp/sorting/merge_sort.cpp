//                     Ajay Dinakar Kandavalli
//                             Merge Sort
//        Reference:    Introduction to Algorithms ,Thomas H Carmen
#include<iostream>
using namespace std;
void merge_sort(int [],int,int);
void merge(int [],int,int,int);
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
	merge_sort(arr,0,size-1);
	for (int i = 0; i <= size-1; i++)
	{
		cout<<arr[i]<<",";
	}
}
void merge_sort(int a[] ,int p ,int r)
{
	int q;
	if (p < r)
	{
		q = (p+r)/2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);

	}
}
void merge(int a[],int p,int q,int r )
{
	 int n1 = q - p + 1;
	 int n2 = r - q;
	 int *L, *R;
	L= new int[n1+1];
	R = new int[n2+1];
	 for (int i = 1; i <=n1; i++)
		  L[i] = a[p + i - 1];
	 for (int j = 1; j <= n2; j++)
		  R[j] = a[q+j];
	 L[n1 + 1] = 100000;
	 R[n2 + 1] = 100000;
	 int i = 1, j = 1;
	 for (int k = p; k <= r; k++)
	 {
		 if (L[i] <= R[j])
		 {
			 a[k] = L[i];
			 i = i + 1;
		 }
		 else
		 {
			 a[k] = R[j];
			 j = j + 1;
		 }
	 }

}



