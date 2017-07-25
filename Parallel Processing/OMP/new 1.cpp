#include <iostream>
#include <time.h>
#include <omp.h>
using namespace std;

int x;
double arr[50000];
double arr2[50000];

void main()
{
	
	clock_t tStart = clock();
	
	omp_set_num_threads(4);
	int thread_nu = omp_get_thread_num();
//#pragma omp parallel for schedule(dynamic,100) 
	for (int i = 0; i < 20000; i++){
		arr[i] = i;
		int thread_nu = omp_get_thread_num();
		cout << thread_nu << endl;

		for (int j = 0; j < 20000; j++){
			arr2[j] = j;
		}
	}
	
	/*
#pragma omp parallel
	{
		cout << "hello" << endl;
	}
	*/
	cout << thread_nu << endl;
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	system("pause");
}