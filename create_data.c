#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>


int main(void) {

	srand((unsigned int)time(NULL));
	FILE* fp01 = fopen("E:\\JB_Clion\\sortData01.txt", "w");
	FILE* fp02 = fopen("E:\\JB_Clion\\sortData02.txt", "w");
	FILE* fp03 = fopen("E:\\JB_Clion\\sortData03.txt", "w");
	if (!fp01 || !fp02 || !fp03) {
		return -1;
	}

	for (int i = 0; i < 10000; i++) {
		fprintf(fp01, "%d\n", rand() % 10000 + 1);
	}
	for (int i = 0; i < 50000; i++) {
		fprintf(fp02, "%d\n", rand() % 50000 + 1);
	}
	for (int i = 0; i < 100000; i++) {
		fprintf(fp03, "%d\n", rand() % 100000 + 1);
	}
	fclose(fp01);
	fclose(fp02);
	fclose(fp03);

	printf("数据写入成功！");
	system("pause");

}
