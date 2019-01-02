#include <stdlib.h>

#include <stdio.h>

#define MAXSIZE 30

#define NUMBER 6

typedef struct {

	char no[10];

	char name[10];

	int score[6];

	int total;

}student;

typedef struct {

	student stu[MAXSIZE];

	int len;

}SeqList;

SeqList List;

SeqList create(SeqList L, int n);

void search(SeqList* L); 

int Partition(int arr[], int low, int high);

void QuickSort(int arr[], int low, int high);

void SelectSort(int arr[]);

void BubbleSort(int arr[]);

void _Printf(SeqList* L);

void sendQuickSort(SeqList* L);

void sendSelectSort(SeqList* L);

void sendBubbleSort(SeqList* L);

void menu();

void chooseMenu();

void repeat();

// 创建学生成绩统计表
SeqList create(SeqList L, int n) {

	int i, j;

	printf("输入学生的学号、姓名、数学、英语、政治、专业课1和专业课2成绩:\n");

	for(i = 0 ; i < n ; i ++) {
	
		scanf("%s",L.stu[i].no);

		scanf("%s",L.stu[i].name);

		L.stu[i].total = 0;

		for(j = 1 ; j < NUMBER ; j ++) {
			
			scanf("%d",&L.stu[i].score[j]);

			L.stu[i].total = L.stu[i].total + L.stu[i].score[j];
		
		}

		printf("%d\n", L.stu[i].total);
		
	}

	return L;

}


// 按照学号查询学生成绩信息
void search(SeqList* L) {

	int i, j;

	char *sno[10];

	printf("输入要查询学生的学号:");

	scanf("%s", sno);

	for(i = 0 ; i < L->len ; i ++) {
	
		if(strcmp(sno, L->stu[i].no) == 0) {
		
			printf("查询结果:\n");

			printf("学生的学号为:%s\n学生的名称为:%s\n", L->stu[i].no, L->stu[i].name);

			printf("学生的数学、英语、政治、专业课1和专业课2成绩分别为:");

			for( j = 1 ; j < NUMBER ; j ++) {
			
				printf("%d ", L->stu[i].score[j]);
			
			}

			printf("\n学生的总成绩为:%d\n ", L->stu[i].total);

			repeat();

			return;
		
		}
	
	}

	if( i = L->len ) {
		
		printf("找不到该学生!\n");	
		
	}

	repeat();

}

// 一趟快速排序
int Partition(int arr[], int low, int high) {

	arr[0] = arr[low];

	while(low < high) {
	
		while (low < high && arr[high] >= arr[0]) {
		
			high --;
		
		}

		arr[low] = arr[high];

		while (low < high && arr[low] <= arr[0]) {
		
			low ++;
		
		}

		arr[high] = arr[low];
	
	}

	arr[low] = arr[0];

	return low;

}

// 通过回调进行多次快速排序
void QuickSort(int arr[], int low, int high) {

	int p;

	if(low < high) {
		
		p = Partition(arr, low, high);

		QuickSort(arr, low, p - 1);

		QuickSort(arr, p + 1, high);
		
	}

}

// 直接选择排序(升序排序)
void SelectSort(int arr[]) {

	int i, j, s, t;

	for(i = 0 ; i < NUMBER - 1 ; i ++) {

		s = i;
	
		// 找出最小元素
		for(j = i+1 ; j < NUMBER ; j ++) {
		
			if(arr[s] > arr[j+1]) {
			
				s = j+1;
			
			}
		
		}

		// 将最小元素和第一个元素进行交换
		if(arr[i] > arr[s]) {
		
			t = arr[i];

			arr[i] = arr[s];

			arr[s] = t;
		
		}
	
	}

}


// 冒泡排序(降序排序)
void BubbleSort(int arr[]) {

	int i, j, t;

	for(i = 1 ; i < NUMBER - 1 ; i ++) {
	
		for(j = 1 ; j < NUMBER - i ; j ++) {
		
			if(arr[j] < arr[j+1]) {
			
				t = arr[j];

				arr[j] = arr[j+1];

				arr[j+1] = t;
			
			}
		
		}

	}
	
}


// 传入学生表
void sendSelectSort(SeqList* L) {

	int i;

	for(i = 0 ; i < L->len ; i ++) {
	
		SelectSort(L->stu[i].score);
	
	}

}


// 传入学生表
void sendQuickSort(SeqList* L) {

	int i;

	for(i = 0 ; i < L->len ; i ++) {

		QuickSort(L->stu[i].score, 1, NUMBER - 1);
	
	}

}

// 传入学生表
void sendBubbleSort(SeqList* L) {

	int i;

	for(i = 0 ; i < L->len ; i ++) {
	
		BubbleSort(L->stu[i].score);
	
	}

}

// 打印输出数组中的值
void _Printf(SeqList* L) {

	int i, j;

	for(i = 0 ; i < L->len ; i ++) {

		printf("输出第%d个学生的成绩:", i + 1);

		for(j = 1 ; j < NUMBER ; j ++) {
		
			printf("%d ",L->stu[i].score[j]);
			
		}

		printf("\n");

	}

	repeat();

	printf("\n");

} 

// 输出菜单信息
void menu() {

	printf("\t\t\t************************\n\n");

	printf("\t\t\t    1. 快速排序\n\n\n");

	printf("\t\t\t    2. 直接选择排序\n\n\n");

	printf("\t\t\t    3. 冒泡排序\n\n\n");

	printf("\t\t\t    4. 查找对应学号学生的成绩:\n\n\n");

	printf("\t\t\t************************\n\n");

}

void chooseMenu(SeqList L) {

	int num;

	printf("请选择:");

	scanf("%d",&num);

	switch(num) {
	
		case 1:sendQuickSort(&L);
			
			_Printf(&L);

			break;

		case 2:sendSelectSort(&L);

			_Printf(&L);

			break;

		case 3:sendBubbleSort(&L);

			_Printf(&L);

			break;

		default:
			search(&L);

			break;
	
	}

}

void repeat() {

	char c;

	printf("是否重新选择(Y/N):");

	getchar();

	scanf("%c", &c);

	if(c == 'Y' || c == 'y') {
	
		system("cls");
		
		menu();

		chooseMenu(List);
	
	}else {
		
		return;
		
	}

}

// 入口函数
void main() {

	printf("输入学生人数:");

	scanf("%d",&List.len);

	List = create(List, List.len);

	system("CLS");

	menu();

	chooseMenu(List);

}
