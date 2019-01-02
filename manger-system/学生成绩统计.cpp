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

// ����ѧ���ɼ�ͳ�Ʊ�
SeqList create(SeqList L, int n) {

	int i, j;

	printf("����ѧ����ѧ�š���������ѧ��Ӣ����Ρ�רҵ��1��רҵ��2�ɼ�:\n");

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


// ����ѧ�Ų�ѯѧ���ɼ���Ϣ
void search(SeqList* L) {

	int i, j;

	char *sno[10];

	printf("����Ҫ��ѯѧ����ѧ��:");

	scanf("%s", sno);

	for(i = 0 ; i < L->len ; i ++) {
	
		if(strcmp(sno, L->stu[i].no) == 0) {
		
			printf("��ѯ���:\n");

			printf("ѧ����ѧ��Ϊ:%s\nѧ��������Ϊ:%s\n", L->stu[i].no, L->stu[i].name);

			printf("ѧ������ѧ��Ӣ����Ρ�רҵ��1��רҵ��2�ɼ��ֱ�Ϊ:");

			for( j = 1 ; j < NUMBER ; j ++) {
			
				printf("%d ", L->stu[i].score[j]);
			
			}

			printf("\nѧ�����ܳɼ�Ϊ:%d\n ", L->stu[i].total);

			repeat();

			return;
		
		}
	
	}

	if( i = L->len ) {
		
		printf("�Ҳ�����ѧ��!\n");	
		
	}

	repeat();

}

// һ�˿�������
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

// ͨ���ص����ж�ο�������
void QuickSort(int arr[], int low, int high) {

	int p;

	if(low < high) {
		
		p = Partition(arr, low, high);

		QuickSort(arr, low, p - 1);

		QuickSort(arr, p + 1, high);
		
	}

}

// ֱ��ѡ������(��������)
void SelectSort(int arr[]) {

	int i, j, s, t;

	for(i = 0 ; i < NUMBER - 1 ; i ++) {

		s = i;
	
		// �ҳ���СԪ��
		for(j = i+1 ; j < NUMBER ; j ++) {
		
			if(arr[s] > arr[j+1]) {
			
				s = j+1;
			
			}
		
		}

		// ����СԪ�غ͵�һ��Ԫ�ؽ��н���
		if(arr[i] > arr[s]) {
		
			t = arr[i];

			arr[i] = arr[s];

			arr[s] = t;
		
		}
	
	}

}


// ð������(��������)
void BubbleSort(int arr[]) {

	int i, j, t;

	for(i = 0 ; i < NUMBER - 1 ; i ++) {
	
		for(j = 0 ; j < NUMBER - i ; j ++) {
		
			if(arr[j] > arr[j+1]) {
			
				t = arr[j];

				arr[j] = arr[j+1];

				arr[j+1] = t;
			
			}
		
		}

	}
	
}


// ����ѧ����
void sendSelectSort(SeqList* L) {

	int i;

	for(i = 0 ; i < L->len ; i ++) {
	
		SelectSort(L->stu[i].score);
	
	}

}


// ����ѧ����
void sendQuickSort(SeqList* L) {

	int i;

	for(i = 0 ; i < L->len ; i ++) {

		QuickSort(L->stu[i].score, 1, NUMBER - 1);
	
	}

}

// ����ѧ����
void sendBubbleSort(SeqList* L) {

	int i;

	for(i = 0 ; i < L->len ; i ++) {
	
		BubbleSort(L->stu[i].score);
	
	}

}

// ��ӡ��������е�ֵ
void _Printf(SeqList* L) {

	int i, j;

	for(i = 0 ; i < L->len ; i ++) {

		printf("�����%d��ѧ���ĳɼ�:", i + 1);

		for(j = 1 ; j < NUMBER ; j ++) {
		
			printf("%d ",L->stu[i].score[j]);
			
		}

		printf("\n");

	}

	repeat();

	printf("\n");

} 

// ����˵���Ϣ
void menu() {

	printf("\t\t\t************************\n\n");

	printf("\t\t\t    1. ��������\n\n\n");

	printf("\t\t\t    2. ֱ��ѡ������\n\n\n");

	printf("\t\t\t    3. ð������\n\n\n");

	printf("\t\t\t    4. ���Ҷ�Ӧѧ��ѧ���ĳɼ�:\n\n\n");

	printf("\t\t\t************************\n\n");

}

void chooseMenu(SeqList L) {

	int num;

	printf("��ѡ��:");

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

	printf("�Ƿ�����ѡ��(Y/N):");

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

// ��ں���
void main() {

	printf("����ѧ������:");

	scanf("%d",&List.len);

	List = create(List, List.len);

	system("CLS");

	menu();

	chooseMenu(List);

}
