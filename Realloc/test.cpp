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
//	//Заполнение массива
//	for (int i = 0; i < rows; i++) {
//		mas[i] = counter++;
//	}
//	//Вывод массива
//	for (int i = 0; i < rows; i++) {
//		printf("%d\n", mas[i]);
//		}
//	//Изменение размеров массива
//	printf("\n");
//	int new_size;
//	printf("new_size ");  scanf_s("%d", &new_size);
//	//Вывод массива
//	if (new_size < rows) {
//		mas = (int*)realloc(mas, sizeof(int) * new_size);
//		for (int i = 0; i < new_size; i++) {
//			printf("%d\n", mas[i]);
//		}
//	}
//	if (new_size >= rows) {
//		mas = (int*)realloc(mas, sizeof(int) * new_size);
//		counter = 1;
//		//Заполнение массива
//		for (int i = 0; i < new_size; i++) {
//			mas[i] = counter++;
//		}
//		//Вывод массива
//		for (int i = 0; i < new_size; i++) {
//			printf("%d\n", mas[i]);
//		}
//	}
//	//Добавление K строки
//	int new_row;
//	printf("\nРабота со строкой\n0 - выход\n1 - добавление K строки\n2 - Удаление K строки\n");
//	scanf_s("%d", &new_row);
//	if (new_row == 1) {
//		new_size++;
//		mas = (int*)realloc(mas, sizeof(int) * new_size);
//		//Заполнение новой строки
//		printf("Введите элемент массива\n");
//		scanf_s("%d", &mas[new_size - 1]);
//		printf("Добавляем\n");
//	}
//	if (new_row == 2) {
//		printf("Удаляем\n");
//		new_size--;
//		mas = (int*)realloc(mas, sizeof(int) * new_size);
//	}
//	//Вывод
//	printf("Вывод\n");
//	for (int i = 0; i < new_size; i++) {
//		printf("%d\n", mas[i]);
//	}
//	free(mas);
//}