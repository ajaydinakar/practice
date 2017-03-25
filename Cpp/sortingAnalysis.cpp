//***********************************************************************************//
//  Name    :Ajay Dinakar Kandavalli, Project -2    
//  course  :  CMPS 5243-Section 201,Algorithm analysis,spring 2017,Dr.Tina Johnson
//  Purpose :Program to demonstrate emperical analysis of O(N^2) sorting algorithims Bubble
//           sort and selection sort, NlogN sorting algorithms merge sort and heap sort
//           by computing number of comparisions made by each sorting
//           algorithm and  time taken by each sorting algorithm 
//           
// --->>> Reference:Introduction to algorithms by Thomas H Cormen    <<<---
//Comparision  Data collected for 10 loops in increments  of 1000
//***********************************************************************************//
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
//function declerations
int merge_sort(int[], int, int);
int merge(int[], int, int, int);
int selection_sort(int[], int);
int buildheap(int arr[], int n);
int heapify(int arr[], int n, int i);
int heapSort(int arr[], int n);
int BubbleSort(int[], int);
//main function
int main()
{
	int arr_size, iterations = 10;
	ofstream output1,output2;//declaring output files
	output1.open("AjayP2comparisions.csv");//opening outputfile1
	output2.open("AjayP2time.csv");//opening outputfile2
	srand((signed int)time(0));//this causes rand() to generate different random numbers
	                           //every time when it runs
	output1 <<"n"<<","<< " Bubble sort" << "," << " selection sort"<<"," << " Merge sort"<< "," << "Heap sort"<<endl;
	output2 << "n" << "," << " Inserton sort" << "," << " selection sort" << "," << " Merge sort" << "," << "Heap sort" << endl;
	for (arr_size = 1000; arr_size <= 10000; arr_size += 1000)//running 10 loops in increments of 1000
	{
		int *A, *B,*C,*D;//declaring pointers for dynamic array allocation
		int BublCt = 0, MegCt =0, SelCt = 0,HeapCt=0;//variabes that store comprision counts
		double mergesort_time = 0,  heapsort_time = 0, Bubblesort_time=0, selectionsort_time=0;
		//declaring  start and stop time variables 
		clock_t I_start, I_stop, M_start, M_stop, S_stop, S_start, H_start, H_stop;
		//defining dynamic arrays
		A = new int[arr_size];
		B = new int[arr_size];
		C = new int[arr_size];
		D = new int[arr_size];
		for (int avg = 0; avg < iterations; avg++)//loop for ten times for taking average count
		{
			for (int i =0; i<=arr_size-1 ; i++)//
			{
				A[i] = rand();//initializing array with random numbers
				
			}
			for (int i = 0; i <= arr_size - 1; i++)//
			{
				B[i]=C[i]=D[i]= A[i];//initializing the arrays B,C,D with same elements as of A
			}
		    I_start = clock();//capture starttime of insertion sort
			BublCt += BubbleSort(A, arr_size);//call insertion sort function
			                     //comparisions count is stored inInsCt
		 	I_stop = clock();//capture endtime of insertion sort
		    M_start = clock();//capture starttime of merge sort
			MegCt += merge_sort(B, 0, arr_size - 1);//call merge sort function
                            //comparisions count is stored in MegCt
		    M_stop = clock();//captureing endtime of merge sort 
		    S_start = clock();//captureing starttime of selection sort
			SelCt += selection_sort(C, arr_size);
			//comparisions count is stored in SelCt
		    S_stop = clock();//captureing endtime of selection sort
		    H_start = clock();//captureing starttime of heap sort
			HeapCt += heapSort(D, arr_size);//calling Heap sort function
			             //comparisions count is stored in HeapCt
		    H_stop = clock();//captureing endtime of heap sort
							 //computinging time taken by each sort
			 mergesort_time += (double)(M_stop - M_start) / CLK_TCK;
			 heapsort_time += (double)(H_stop - H_start) / CLK_TCK;
			 Bubblesort_time += (double)(I_stop - I_start) / CLK_TCK;
			 selectionsort_time += (double)(S_stop - S_start) / CLK_TCK;
		}
		
		output1 <<arr_size<<","<<  BublCt / iterations << ","   <<SelCt/iterations<< ","<< MegCt / iterations<< "," << HeapCt / iterations<<endl;//average count
		output2 << arr_size << "," << Bubblesort_time / iterations << "," << selectionsort_time / iterations << ",";
		output2<< mergesort_time / iterations << "," << heapsort_time / iterations << endl;
		cout << A[20] << B[20] << C[20] << D[20]<<endl;
		delete[] A;//de allocating memory for dynamic arrays A,B,C,D
		delete[] B;
		delete[] C;
		delete[] D;
	}
	output1.close();//closing the files
	output2.close();
}
//Insertion sort function definition
int insertion_sort(int arr[], int size)
{
	
	int count = 0;//initializing the count
	for (int j = 1;++count && j < size; j++)
	{
		int key = arr[j];
		int i = j - 1;
		while (  i >= 0 && ++count && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
	
	return count;//return insertion sort comparision count to main
}
//Merge sort function definitions
int merge_sort(int arr[], int p, int r)
{
	int q;
	 int count=0;//c is count
	if (++count && p < r)
	{
		q = (p + r) / 2;//finding middle index
		count +=merge_sort(arr, p, q);
		count +=merge_sort(arr, q + 1, r);
		count = count + merge(arr, p, q, r);
	}
	return count;//return merge sort comparision count to main
}
//merge
int merge(int arr[], int p, int q, int r)
{
	int count=0;
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L, *R;
	L = new int[n1 + 1];
	R = new int[n2 + 1];
	for (int i = 1;++count && i <= n1; i++)
		L[i] = arr[p + i - 1];
	for (int j = 1;++count && j <= n2; j++)
		R[j] = arr[q + j];
	L[n1 + 1] = 100000;
	R[n2 + 1] = 100000;
	int i = 1, j = 1;
	for (int k = p;++count && k <= r; k++)
	{
		if (++count && L[i] <= R[j])
		{
			arr[k] = L[i];
			i = i + 1;
		}
		else
		{
			arr[k] = R[j];
			j = j + 1;
			count++;
		}
	}
	return count;//return merge sort comparision count to merge_sort function
}
int selection_sort(int array[], int z)
{
	int count=0;
	int scan, minindex, minvalue;
	for ( scan = 0; ++count && scan < (z - 1); scan++)
	{
		minindex = scan;
		minvalue = array[scan];
		//finding the minimum value from scan+1 to z
		//and replacing array[scan] with that minimum value
		for ( int i = scan + 1; ++count && i < z; i++)
		{
			if (++count && array[i] < minvalue)
			{
				minvalue = array[i];
				minindex = i;
			}
		}
		array[minindex] = array[scan];
		array[scan] = minvalue;
	}
	return count;
}
int heapify(int arr[], int n, int i)
{
	int count = 0;
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2
	// If left child is larger than root
	if (++count && l < n && arr[l] > arr[largest])
		largest = l;
	// If right child is larger than largest so far
	if (++count && r < n && arr[r] > arr[largest])
		largest = r;
	// If largest is not root
	if (++count && largest != i)
	{
		swap(arr[i], arr[largest]);
		// Recursively heapify subtree
		count += heapify(arr, n, largest);
	}
	return count;
}
int heapSort(int arr[], int n)
{
	int count;
	//call buildheap
	count = buildheap(arr, n);
	// One by one extract an element from heap
	for (int i = n - 1; ++count && i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);
		// call max heapify on the reduced heap
		count += heapify(arr, i, 0);
	}
	return count;
}
int buildheap(int arr[], int n)
{
	int count = 0;
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; ++count && i >= 0; i--)
		count += heapify(arr, n, i);
	return count;
}

int BubbleSort(int array[], int size)
{
	int count = 0;

	int  temp;
	bool swap;

	do
	{
		swap = false;
		for (int index = 0; index < (size - 1); index++)
		{
			if (++count && array[index] > array[index + 1])
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				swap = true;
			}
		}
	} while (++count &&swap);
	return count;
}


