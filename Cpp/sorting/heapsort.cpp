#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void buildheap(int arr[], int n);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		// Recursively heapify subtree
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{
	//cal buildheap
	buildheap(arr, n);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}
void buildheap(int arr[],int n)
{
	// Build heap (rearrange array)

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
	for (int i = 0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver program
int main()
{
	int *arr;
	srand((signed int)time(0));
	int n = 8;
	arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand();
		}

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}
