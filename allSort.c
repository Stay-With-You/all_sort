#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include"allSort.h"

clock_t start, end;
double duration;

void InsertSort(int* a, int n)
{
	for (int i = 1, j; i < n; i++) {
		int tempVal = a[i];  //保存要插入的值
		for (j = i - 1; tempVal < a[j] && j >= 0; --j) { //数据往后移动，给要插入的值腾位
			a[j + 1] = a[j];
		}
		a[j + 1] = tempVal;  //插入数据
	}
}

void QuickSort_Recursion(int* N, int start, int end) {

	int i = start;
	int j = end;
	int temp;
	if (i < j) {
		temp = N[i];
		while (i != j) {
			while (i < j && N[j] >= temp) {
				j--;
			}
			N[i] = N[j];
			while (i < j && N[i] <= temp) {
				i++;
			}
			N[j] = N[i];
		}
		N[i] = temp;  // 当 i == j 时，基准归位到 i 位置

		// 递归快排基准左右的序列 
		QuickSort_Recursion(N, start, i);  // 左边数据的再排序
		QuickSort_Recursion(N, i + 1, end);  // 右边数据的再排序
	}
	return;
}

void MergeArray(int* a, int begin, int mid, int end) {
	int i = 0, lend = end - 1, tmpPos = begin;
	const int numSize = mid - begin + 1; int* temp = NULL;

	while ((begin <= lend) && (end <= mid)) {
		if (a[begin] <= a[end]) {
			temp[tmpPos++] = a[begin++];
		}
		else {
			temp[tmpPos++] = a[end++];
		}
	}

	while (begin <= lend) {
		temp[tmpPos++] = a[begin++];
	}
	while (end <= mid) {
		temp[tmpPos++] = a[end++];
	}
	for (i = 0; i < numSize; i++, mid--) {
		a[mid] = temp[mid];
	}
}

int MIN(int x, int y) {
	return x < y ? x : y;
}
void MergeSort(int* arr, int N) {
	int* a = arr;
	int* b = (int*)malloc(N * sizeof(int));
	int seg, start;
	for (seg = 1; seg < N; seg += seg) {
		for (start = 0; start < N; start += seg * 2) {
			int low = start, mid = MIN(start + seg, N), high = MIN(start + seg * 2, N);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		int* temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		int i;
		for (i = 0; i < N; i++)
			b[i] = a[i];
		b = a;
	}
	free(b);
}

void countSort(int* a, int length) {

	int max = a[0];
	int lastIndex = 0;
	for (int i = 1; i < length; i++) {
		max = a[i] > max ? a[i] : max;
	}
	int* sortArr = (int*)malloc((max + 1) * sizeof(int));
	if (sortArr == NULL)
	{
		printf("排序中，请勿关闭窗口\n");
		return;
	}

	for (int j = 0; j < length; j++) {
		sortArr[a[j]]++;
	}
	for (int k = 0; k < max + 1; k++) {
		while (sortArr[k] > 0) {
			a[lastIndex++] = k;
			sortArr[k]--;
		}
	}
}


// 找到num的从低到高的第pos位的数据
int GetNumInPos(int num, int pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;

	return (num / temp) % 10;
}
void RadixCountSort(int* a, int size) {

	int* radixArrays[10];    // 分别为0~9的序列空间
	for (int i = 0; i < 10; i++)
	{
		radixArrays[i] = (int*)malloc(sizeof(int) * (size + 1));
		radixArrays[i][0] = 0;    // index为0处记录这组数据的个数
	}

	for (int pos = 1; pos <= 10; pos++)    // 从个位开始
	{
		for (int i = 0; i < size; i++)    // 分配过程
		{
			int num = GetNumInPos(a[i], pos);
			int index = ++radixArrays[num][0];
			radixArrays[num][index] = a[i];
		}

		for (int i = 0, j = 0; i < 10; i++)    // 收集
		{
			for (int k = 1; k <= radixArrays[i][0]; k++)
				a[j++] = radixArrays[i][k];
			radixArrays[i][0] = 0;    // 复位
		}
	}
}


void ColorSort(int* a, int size) {

	int count1 = 0, count2 = 0, index = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] == 1)
			count1++;
		else if (a[i] == 2)
			count2++;
	}
	for (int i = 0; i < size - count1 - count2; i++)
		a[index++] = 0;
	for (int i = 0; i < count1; i++)
		a[index++] = 1;
	for (int i = 0; i < count2; i++)
		a[index++] = 2;
}

void GetTime01(int* a, int N) {

	clock_t start01, start03, start04, end01, end02, end03, end04;
	double duration01, duration03, duration04;

	start01 = clock();
	for (int i = 0; i < 100; i++){
		InsertSort(a, N);
	}
	end01 = clock();
	duration01 = ((double)(end01 - start01)) / CLK_TCK;

	printf("Sorting %d numbers (1000 times) takes up: (by insert sort) %lf\n", N, duration01);
}

void GetTime02(int N) {
	clock_t start02, end02; double duration02;
	srand((unsigned int)time(NULL));
	if (N == 10000) {
		int arr[10000];
		for (int i = 0; i < N; i++) {
			arr[i] = rand() % N;
		}

		start02 = clock();
		QuickSort_Recursion(arr, 0, N - 1);
		end02 = clock();
	}
	if (N == 50000) {
		int arr[50000];
		for (int i = 0; i < N; i++) {
			arr[i] = rand() % N;
		}

		start02 = clock();
		QuickSort_Recursion(arr, 0, N - 1);
		end02 = clock();
	}
	if (N == 100000) {
		int arr[100000];
		for (int i = 0; i < N; i++) {
			arr[i] = rand() % N;
		}

		start02 = clock();
		QuickSort_Recursion(arr, 0, N - 1);
		end02 = clock();
	}

	duration02 = ((double)(end02 - start02)) / CLK_TCK;

	printf("Sorting %d numbers takes up: (by quick sort) %lf\n", N, duration02);
}

void GetTime03(int* a, int N) {
	clock_t start03, end03; double duration03;
	start03 = clock();

	for (int i = 0; i < 100; i++) {
		MergeSort(a, N);
	}
	end03 = clock();
	duration03 = ((double)(end03 - start03)) / CLK_TCK;

	printf("Sorting %d numbers (1000 times) takes up: (by merge sort) %lf\n", N, duration03);
}

void GetTime04(int* a, int N) {
	clock_t start04, end04; double duration04;
	start04 = clock();

	for (int i = 0; i < 1000; i++) {
		countSort(a, N);
	}
	
	end04 = clock();
	duration04 = ((double)(end04 - start04)) / CLK_TCK;

	printf("Sorting %d numbers (1000 times) takes up: (by count sort) %lf\n", N, duration04);
}

int main(void) {

	FILE* fp01 = fopen("E:\\JB_Clion\\sortData01.txt", "r+");
	FILE* fp02 = fopen("E:\\JB_Clion\\sortData02.txt", "r+");
	FILE* fp03 = fopen("E:\\JB_Clion\\sortData03.txt", "r+");
	if (!fp01 || !fp02 || !fp03) {
		return -1;
	}

	// 开辟堆空间
	int* temp01 = (int*)malloc(sizeof(int) * 10000);
	int* temp02 = (int*)malloc(sizeof(int) * 50000);
	int* temp03 = (int*)malloc(sizeof(int) * 100000);

	// 读取
	for (int i = 0; i < 10000; i++) {
		fscanf(fp01, "%d\n", temp01[i]);
	}
	for (int i = 0; i < 50000; i++) {
		fscanf(fp02, "%d\n", temp02[i]);
	}
	for (int i = 0; i < 100000; i++) {
		fscanf(fp03, "%d\n", temp03[i]);
	}

	while (1)
	{
		int ops;
		printf("请输入1-12:\n");
		scanf("%d", &ops);
		switch (ops)
		{
		case 1:
			GetTime01(temp01, 10000);
			system("pause");
			break;
		case 2:
			GetTime01(temp02, 50000);
			system("pause");
			break;
		case 3:
			GetTime01(temp03, 100000);
			system("pause");
			break;
		case 4:
			GetTime02(10000);
			system("pause");
			break;
		case 5:
			GetTime02(50000);
			system("pause");
			break;
		case 6:
			GetTime02(100000);
			system("pause");
			break;
		case 7:
			GetTime03(temp01, 10000);
			system("pause");
			break;
		case 8:
			GetTime03(temp02, 50000);
			system("pause");
			break;
		case 9:
			GetTime03(temp03, 100000);
			system("pause");
			break;
		case 10:
			GetTime04(temp01, 10000);
			system("pause");
			break;
		case 11:
			GetTime04(temp02, 50000);
			system("pause");
			break;
		case 12:
			GetTime04(temp03, 100000);
			system("pause");
			break;
		}
	}
}