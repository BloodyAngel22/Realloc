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
	//Заполнение массива
	fillArray(mas, rows, cols, counter);
	//Вывод массива
	printArray(mas, rows, cols);
	//Добавление K строки
	int new_row;
	printf("\nРабота со строкой\n0 - выход\n1 - добавление П строки\n2 - Удаление П строки\
	\n3 - сдвиг строк\nП - последней\n");
	scanf_s("%d", &new_row);
	//Новый массив
	if (new_row == 1) {
		//Заполнение новой строки
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
	if (new_row == 3) {
		int** mas_2 = allocateArray(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				mas_2[i][j] = mas[i][j];
			}
		}
		freeArray(mas, rows);
		int** mas = allocateArray(rows, cols);
		printf("Сдвиг\n");
		int displacement;
		scanf_s("%d", &displacement);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				printf("%d ", mas_2[i][j]);
			}
			printf("\n");
		}
		int count=0;
		if (displacement > 0) {
			for (int i = 0; i < rows; i++) {
				int tmp = i;
				while (tmp - displacement < 0) {
					tmp = tmp + rows;
				}
				if (tmp - displacement >= 0) {
					tmp = tmp - displacement;
					//printf("%d ", *mas_2[tmp]);
					*mas[i] = *mas_2[tmp];
					for (int j = 0; j < cols; j++) {
						mas[i][j] = mas_2[tmp][j];
					}
				}
			}
		}
		if (displacement < 0) {
			for (int i = 0; i < rows; i++) {
				int tmp = i;
				tmp = (tmp + abs(displacement)) % rows;
				//printf("%d ", *mas_2[tmp]);
				*mas[i] = *mas_2[tmp];
				for (int j = 0; j < cols; j++) {
					mas[i][j] = mas_2[tmp][j];
				}
			}
		}
		freeArray(mas_2, rows);
		printf("\nВывод сдвинутого массива\n");
		printArray(mas, rows, cols);
		freeArray(mas, rows);
	}

}
