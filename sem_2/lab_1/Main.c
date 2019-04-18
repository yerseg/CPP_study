#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "Header.h"
#define TRUE 1
#define FALSE 0

int main() {
	int q, p, stop, track, con = FALSE;
	int stud_count = 0, lect_count = 0; //���������� ��������� � ��������������
	setlocale(LC_ALL, "Rus");

	printf("����� �� ����������� ������� 0 - NO/1 - YES -->");
	do {
		scanf_s("%d", &stop);
		if (stop != 0 && stop != 1)
			printf("������ 002: ��������� ����->");
	} while (stop != 0 && stop != 1);
	if (stop == TRUE)
		Testing();

	Array* Lect_Arr = array_alloc(); //�������� ������ ��� ��������� Array
	Array* Stud_Arr = array_alloc();


	while (stud_count == 0 && lect_count == 0) {
		printf("������� ���������� ���������->\n");
		scanf_s("%d", &stud_count);
		printf("������� ���������� ��������������->\n");
		scanf_s("%d", &lect_count);
		if (stud_count == 0 && lect_count == 0) {
			printf("������ 001: ���������� �������������� �/��� ���������� ��������� ������ ���� ������ 0\n");
		}
	}

	(Array*)array_set(Lect_Arr, lect_count);
	(Array*)array_set(Stud_Arr, stud_count);

	get_lect(Lect_Arr);
	get_stud(Stud_Arr);
	Array* new_arr = array_alloc();

	printf("����� �� ��������� ������� 0 - ���/1 - �� -->");
	do {
		scanf_s("%d", &stop);
		if (stop != 0 && stop != 1)
			printf("������ 002: ��������� ����->");
	} while (stop != 0 && stop != 1); 
	
	
	while (stop != FALSE && con != TRUE) {
		printf("�������� � ��� ������ ��������: �������������(1), ��������(2)->\n");
		do {
			scanf_s("%d", &track);
			if (track != 1 && track != 2)
				printf("������ 003: ��������� ����->");
		} while (track != 1 && track != 2);

			if (track == 1) {
				printf("�������� ������� map(1), where(2), concat(3)->");
				do {
					scanf_s("%d", &q);
					if (q != 1 && q != 2 && q != 3)
						printf("������ 003: ��������� ����->");
				} while (q != 1 && q != 2 && q != 3);

				if (q == 1) {
					printf("�������� �������� �������: �������� �������������(1)->\n");
					do {
						scanf_s("%d", &p);
						if (p != 1)
							printf("������ 003: ��������� ����->");
					} while (p != 1);

					if (p == 1)
						map(Lect_Arr, grade_change);
				}
				if (q == 2) {
					printf("�������� �������� �������: ������ �����������(1)->\n");
					do {
						scanf_s("%d", &p);
						if (p != 1)
							printf("������ 003: ��������� ����->");
					} while (p != 1);

					if (p == 1)
					where(Lect_Arr, grade_sort);
				}
				if (q == 3) {
					new_arr = concat(Lect_Arr, Stud_Arr);
					con = TRUE;
				}
			}
			if (track == 2) {
				printf("�������� ������� map(1), where(2), concat(3)->");
				do {
					scanf_s("%d", &q);
					if (q != 1 && q != 2 && q != 3)
						printf("������ 003: ��������� ����->");
				} while (q != 1 && q != 2 && q != 3);

				if (q == 1) {
					printf("�������� �������� �������: �������� ��� ��������(1)->\n");
					scanf_s("%d", &p);
					if (p == 1)
						map(Stud_Arr, No_Birthday_Stud);
				}
				if (q == 2) {
					printf("�������� �������� �������: ������ �� �������� �� 21(1)->\n");
					do {
						scanf_s("%d", &p);
						if (p != 1)
							printf("������ 003: ��������� ����->");
					} while (p != 1);

					if (p == 1)
					where(Stud_Arr, age_sort_stud);
				}
				if (q == 3) {
					new_arr = concat(Lect_Arr, Stud_Arr);
					con = TRUE;
				}
			}
			if (con == FALSE) {
				printf("����� �� ��������� ������� 0/1->");
				do {
					scanf_s("%d", &stop);
					if (stop != 0 && stop != 1)
						printf("������ 002: ��������� ����->");
				} while (stop != 0 && stop != 1);
			}
			else
				;
	}
	
	if (con == FALSE) {
		out(Lect_Arr, Stud_Arr);
	}
	if (con == TRUE) {
		printf("\n\n�� ������������\n\n");
		out(Lect_Arr, Stud_Arr);
		printf("\n\n����� ������������\n\n");
		lect_count = Lect_Arr->elements_count;
		stud_count = Stud_Arr->elements_count;
		out_concate(new_arr, lect_count, stud_count);
	}

	if (con == FALSE) {
		free_Lecturer(Lect_Arr);
		free_Student(Stud_Arr);
		free(new_arr);
	}
	if (con == TRUE) {
		free_concate(new_arr, lect_count, stud_count);
		free(Lect_Arr);
		free(Stud_Arr);
	} 
	
	system("PAUSE");
	return 0;
}