//#include <stdio.h>
//#include <malloc.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//int main() {
//	system("chcp 1251");
//	int rows, counter = 1;
//	printf("rows "); scanf_s("%d", &rows);
//	int* mas = (int*)malloc(sizeof(int) * rows);
//	//���������� �������
//	for (int i = 0; i < rows; i++) {
//		mas[i] = counter++;
//	}
//	//����� �������
//	for (int i = 0; i < rows; i++) {
//		printf("%d\n", mas[i]);
//		}
//	//��������� �������� �������
//	printf("\n");
//	int new_size;
//	printf("new_size ");  scanf_s("%d", &new_size);
//	//����� �������
//	if (new_size < rows) {
//		mas = (int*)realloc(mas, sizeof(int) * new_size);
//		for (int i = 0; i < new_size; i++) {
//			printf("%d\n", mas[i]);
//		}
//	}
//	if (new_size >= rows) {
//		mas = (int*)realloc(mas, sizeof(int) * new_size);
//		counter = 1;
//		//���������� �������
//		for (int i = 0; i < new_size; i++) {
//			mas[i] = counter++;
//		}
//		//����� �������
//		for (int i = 0; i < new_size; i++) {
//			printf("%d\n", mas[i]);
//		}
//	}
//	//���������� K ������
//	int new_row;
//	printf("\n������ �� �������\n0 - �����\n1 - ���������� K ������\n2 - �������� K ������\n");
//	scanf_s("%d", &new_row);
//	if (new_row == 1) {
//		new_size++;
//		mas = (int*)realloc(mas, sizeof(int) * new_size);
//		//���������� ����� ������
//		printf("������� ������� �������\n");
//		scanf_s("%d", &mas[new_size - 1]);
//		printf("���������\n");
//	}
//	if (new_row == 2) {
//		printf("�������\n");
//		new_size--;
//		mas = (int*)realloc(mas, sizeof(int) * new_size);
//	}
//	//�����
//	printf("�����\n");
//	for (int i = 0; i < new_size; i++) {
//		printf("%d\n", mas[i]);
//	}
//	free(mas);
//}