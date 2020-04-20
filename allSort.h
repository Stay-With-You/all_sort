
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#define SIZE 10

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void InsertSort(int* a, int n);


/**
 *  @name        : void MergeArray(int *a,  int begin, int end);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int begin, int mid, int end);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp);
/**
 *  @name        : void MergerSort(int* arr, int N);
 *  @description : 归并排序
 *  @param       : 数组指针arr，元素个数N
 */
void MergerSort(int* arr, int N);


/**
 *  @name        : void QuickSort(int* N, int start, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点start，数组终点end
 */
void QuickSort_Recursion(int* N, int start, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int length)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度length
 */
void countSort(int* a, int length);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size);


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int search(int* a, int K);

#endif // QUEUE_H_INCLUDED
