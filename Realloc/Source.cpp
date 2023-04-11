#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <Windows.h>

int** allocateArray(int rows, int cols) {
	int** mas = (int**)malloc(sizeof(int*) * rows);
	for (int i = 0; i < rows; i++) {
		mas[i] = (int*)malloc(sizeof(int) * cols);
	}
	return mas;
}

void fillArray(int** mas, int rows, int cols, int counter) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mas[i][j] = counter++;
		}
	}
}

void printArray(int** mas, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}
}

void freeArray(int** mas, int rows) {
	for (int i = 0; i < rows; i++) {
		free(mas[i]);
	}free(mas);
}

int main() {
	system("chcp 1251");
	int rows, cols, counter = 1;
	printf("rows "); scanf_s("%d", &rows);
	printf("cols "); scanf_s("%d", &cols);
	int** mas = allocateArray(rows,cols);
	//���������� �������
	fillArray(mas, rows, cols, counter);
	//����� �������
	printArray(mas, rows, cols);
	//���������� K ������
	int new_row;
	printf("\n������ �� �������\n0 - �����\n1 - ���������� � ������\n2 - �������� � ������\
	\n� - ���������\n");
	scanf_s("%d", &new_row);
	//����� ������
	if (new_row == 1) {
		//���������� ����� ������
		int new_rows = rows+1;
		int** mas_2 = allocateArray(new_rows, cols);
		counter = 1;
		fillArray(mas_2, new_rows, cols, counter);
		printArray(mas_2, new_rows, cols);
		freeArray(mas_2, new_rows);
	}
	if (new_row == 2) {
		int new_rows = rows - 1;
		int** mas_2 = allocateArray(new_rows, cols);
		counter = 1;
		fillArray(mas_2, new_rows, cols, counter);
		printArray(mas_2, new_rows, cols);
		freeArray(mas_2, new_rows);
	}
	
	freeArray(mas, rows);

}