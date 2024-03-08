#ifndef TEST
#define TEST
#include<random>
#include<time.h>
#include<chrono>
#include<ctime>
#include"GroupOne.h"
#include"GroupTwo.h"
#include"GroupThree.h"
#define MAX_ELEMENT_IN_ARRAY 1e9+1

int* generate_random_array(int n);
int* generate_sorted_array(int n);
int* generate_sorted_reverse_array(int n);
int* generate_near_sorted_array(int n);

int* copyArray(int a[], int n);
void print(int *a, int n);
bool checkifSorted(int *a, int n);

void test_sorting_runtimes_Group1(int size,int type);
void test_sorting_runtimes_Group2_3(int size,int type);

int* generate_random_array_for_countingsort(int n);
int* generate_sorted_array_for_countingsort(int n);
int* generate_sorted_reverse_array_for_countingsort(int n);
int* generate_near_sorted_array_for_countingsort(int n);

int* generate_random_array(int n)
{
	int *a = new int[n];
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<unsigned long long> dis(0, MAX_ELEMENT_IN_ARRAY);

	for (int i = 0; i < n; i++)
		a[i] = dis(gen);
	return a;
}
int* generate_sorted_array(int n)
{
	int *a = new int[n];
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<unsigned long long> dis(0, MAX_ELEMENT_IN_ARRAY);

	for (int i = 0; i < n; i++)
		a[i] = dis(gen);
	sort(a, a + n);
	return a;
}
int* generate_sorted_reverse_array(int n)
{
	int *a = new int[n];
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<unsigned long long> dis(0, MAX_ELEMENT_IN_ARRAY);

	for (int i = 0; i < n; i++)
		a[i] = dis(gen);
	sort(a, a + n);
	reverse(a, a + n);
	return a;
}
int* generate_near_sorted_array(int n) {
	int *a = new int[n];
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<unsigned long long> dis(0, MAX_ELEMENT_IN_ARRAY);

	for (int i = 0; i < n; i++)
		a[i] = dis(gen);
	sort(a, a + n);
	for (int i = 0; i < n; i += 1000) {
		a[i] = 271199;
	}
	return a;
}
int* copyArray(int a[], int n)
{
	int *arr = new int[n];
	int i;
	for (i = 0; i < n; ++i)
		arr[i] = a[i];
	return arr;
}

void print(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void test_sorting_runtimes_Group2_3(int size,int type)
{
	int n = size;

	double HeapSortTime = 0, MergeSortTime = 0;
	double QuickSortTime = 0, qSortTime = 0;
	double CountTime = 0, RadixTime = 0, Flashtime = 0;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	int *a;
	if (type == 1)
		a = generate_random_array(n);
	else if (type==2) 
		a = generate_sorted_array(n);
	else if (type == 3) 
		a = generate_sorted_reverse_array(n);
	else 
		a = generate_near_sorted_array(n);

	//print(a, n);
	std::chrono::duration<double> elapsed_seconds;

	int *b = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	heapSort(b, n);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(b, n)) return;
	elapsed_seconds = end - start;
	HeapSortTime += elapsed_seconds.count();
	free(b);

	int *c = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	merge_sort(c, 0, n - 1);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(c, n)) return;
	elapsed_seconds = end - start;
	MergeSortTime += elapsed_seconds.count();
	free(c);

	int *d = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	quickSort(d, 0, n - 1);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(d, n)) return;
	elapsed_seconds = end - start;
	QuickSortTime += elapsed_seconds.count();
	free(d);

	int *e = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	QSort(e, n);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(e, n)) return;
	elapsed_seconds = end - start;
	qSortTime += elapsed_seconds.count();
	free(e);

	int *f;
	if (type == 1)
		f = generate_random_array_for_countingsort(n);
	else if (type == 2)
		f = generate_sorted_array_for_countingsort(n);
	else if (type == 3)
		f = generate_sorted_reverse_array_for_countingsort(n);
	else
		f = generate_near_sorted_array_for_countingsort(n);
	start = std::chrono::system_clock::now();
	
	countingSort(f, n);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(f, n)) return;
	elapsed_seconds = end - start;
	CountTime += elapsed_seconds.count();
	free(f);

	int *g = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	RadixSort(g, n);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(g, n)) return;
	elapsed_seconds = end - start;
	RadixTime += elapsed_seconds.count();
	free(g);

	int *h = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	FlashSort(h, n);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(h, n)) return;
	elapsed_seconds = end - start;
	Flashtime += elapsed_seconds.count();
	free(h);

	free(a);

	//Output
	printf("\nTime taken to sort Group 2 and Group 3 Algorithms :\n\n");
	printf("%-35s %f(s)\n\n", "1. HeapSort Time: ", HeapSortTime);
	printf("%-35s %f(s)\n\n", "2. MergeSort Time: ", MergeSortTime);
	printf("%-35s %f(s)\n\n", "3. QuickSort Time: ", QuickSortTime);
	printf("%-35s %f(s)\n\n", "4. qSort Time: ", qSortTime);
	printf("%-35s %f(s)\n\n", "5. CountingSort Time: ", CountTime);
	printf("%-35s %f(s)\n\n", "6. RadixSort Time: ", RadixTime);
	printf("%-35s %f(s)\n\n", "7. FLASHSort Time: ", Flashtime);
}

void test_sorting_runtimes_Group1(int size,int type)
{
	int n = size;

	double SelectionTime = 0, InsertionTime = 0;
	double BinaryInsertionTime = 0, BubbleTime = 0;
	double ShakerTime = 0, ShellTime = 0;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	int *a;
	if (type == 1)
		a = generate_random_array(n);
	else if (type == 2)
		a = generate_sorted_array(n);
	else if (type == 3)
		a = generate_sorted_reverse_array(n);
	else
		a = generate_near_sorted_array(n);

	std::chrono::duration<double> elapsed_seconds;

	int *b = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	selection_Sort(b, n);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(b, n)) return;
	elapsed_seconds = end - start;
	SelectionTime += elapsed_seconds.count();
	free(b);

	int *c = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	InsertionSort(c, n);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(c, n)) return;
	elapsed_seconds = end - start;
	InsertionTime += elapsed_seconds.count();
	free(c);

	int *d = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	binaryInsertionSort(d, n);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(d, n)) return;
	elapsed_seconds = end - start;
	BinaryInsertionTime += elapsed_seconds.count();
	free(d);

	int *e = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	bubbleSort(e, n);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(e, n)) return;
	elapsed_seconds = end - start;
	BubbleTime += elapsed_seconds.count();
	free(e);

	int *f = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	shakerSort(f, n);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(f, n)) return;
	elapsed_seconds = end - start;
	ShakerTime += elapsed_seconds.count();
	free(f);

	int *g = copyArray(a, n);
	start = std::chrono::system_clock::now();
	
	shellSort(g, n);
	
	end = std::chrono::system_clock::now();
	//if (!checkifSorted(g, n)) return;
	elapsed_seconds = end - start;
	ShellTime += elapsed_seconds.count();
	free(g);

	free(a);

	//Output
	printf("\nTime taken to sort Group 1 Algorithms :\n\n");
	printf("%-35s %f(s)\n\n", "1. Selection sort: ", SelectionTime);
	printf("%-35s %f(s)\n\n", "2. Insertion sort: ", InsertionTime);
	printf("%-35s %f(s)\n\n", "3. BinaryInsertionSort Time ", BinaryInsertionTime);
	printf("%-35s %f(s)\n\n", "4. BubbleSort Time ", BubbleTime);
	printf("%-35s %f(s)\n\n", "5. ShakerSort Time ", ShakerTime);
	printf("%-35s %f(s)\n\n", "6. ShellSort Time ", ShellTime);
}

bool checkifSorted(int *a, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] < a[i]) return false;
	}
	return true;
}

//FOR COUNGTING SORT
int* generate_random_array_for_countingsort(int n)
{
	srand(time(NULL));
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
		a[i] = rand() % MAX_FOR_COUNTING;
	return a;
}
int* generate_sorted_array_for_countingsort(int n)
{
	srand(time(NULL));
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
		a[i] = rand() % MAX_FOR_COUNTING;
	sort(a, a + n);
	return a;
}
int* generate_sorted_reverse_array_for_countingsort(int n)
{
	srand(time(NULL));
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
		a[i] = rand() % MAX_FOR_COUNTING;
	sort(a, a + n);
	reverse(a, a + n);
	return a;
}
int* generate_near_sorted_array_for_countingsort(int n)
{
	srand(time(NULL));
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
		a[i] = rand() % MAX_FOR_COUNTING;
	sort(a, a + n);
	for (int i = 0; i < n; i+=1000) {
		a[i] = 2711;
	}
	return a;
}

