
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#define SIZE 10

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void InsertSort(int* a, int n);


/**
 *  @name        : void MergeArray(int *a,  int begin, int end);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int* a, int begin, int mid, int end);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int* a, int begin, int end, int* temp);
/**
 *  @name        : void MergerSort(int* arr, int N);
 *  @description : �鲢����
 *  @param       : ����ָ��arr��Ԫ�ظ���N
 */
void MergerSort(int* arr, int N);


/**
 *  @name        : void QuickSort(int* N, int start, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������start�������յ�end
 */
void QuickSort_Recursion(int* N, int start, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int* a, int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int* a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int length)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��length
 */
void countSort(int* a, int length);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int* a, int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int* a, int size);


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
int search(int* a, int K);

#endif // QUEUE_H_INCLUDED
