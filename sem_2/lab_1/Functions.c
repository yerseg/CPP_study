#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "Header.h"
#define TRUE 1
#define FALSE 0

//�������� �������
void* array_alloc() {		
	return(void*)malloc(sizeof(Array));
}	//��������� ������ �� Array

void* array_set(Array *p, int count) {
	p->elements_count = count;
	p->memory_ptr = (void**)malloc(count*(sizeof(void*)));
	return p;
} //������� ���������� �������� Array � ��������� ������ ��� ������ ���������� 

void* lect_alloc() {
	return(void*)malloc(sizeof(Lecturer));
} //��������� ������ ��� �������������

void* stud_alloc() {
	return(void*)malloc(sizeof(Student));
} //��������� ������ ��� ��������

void get_lect(Array* Lect_Arr) {  //���������� ������� �������� � ����������� ��� � Array
	Lecturer* lect;
	for (int i = 0; i < Lect_Arr->elements_count; i++) {
		lect = (Lecturer*)lect_alloc();
		int k = 0, l = 0, s = 0;
		char c;

		//���������� �����

		lect->firstName = (char*)malloc(100 * sizeof(char));
		lect->middleName = (char*)malloc(100 * sizeof(char));
		lect->lastName = (char*)malloc(100 * sizeof(char));
		printf("������� ��� ������������� � ��������� �� ����� 100 �������� � ������� Enter->\n");
		c = getchar();
		while (((c = getchar()) != ' ') && (k != 100)) {
			lect->lastName[l] = c;
			k = k + 1;
			l = l + 1;
		} 
		lect->lastName = (char*)realloc(lect->lastName, (k+1)*sizeof(char)); 
		lect->lastName[l] = '\0'; 
		k = 0; l = 0;
		
		while (((c = getchar()) != ' ') && (k != 100)) {
			lect->firstName[l] = c;
			k = k + 1;
			l = l + 1;
		} 
		lect->firstName = (char*)realloc(lect->firstName, (k+1)*sizeof(char)); 
		lect->firstName[l] = '\0'; 
		l = 0; k = 0;

		while (((c = getchar()) != '\n') && (k != 100)) {
			lect->middleName[l] = c;
			k = k + 1;
			l = l + 1;
		} 
		lect->middleName = (char*)realloc(lect->middleName, (k+1)*sizeof(char)); 
		lect->middleName[l] = '\0';

		printf("������� ����� �������� � ������� XXXX->\n");
		do {
			scanf_s("%d", &s);
			if (s <= 1000 || s >= 9999)
				printf("������ 005: ��������� ����->");
		} while (s <= 1000 || s >= 9999);
		lect->id.series = s;

		printf("������� ����� �������� � ������� XXXXXX->\n");
		do {
			scanf_s("%d", &s);
			if (s <= 100000 || s >= 999999)
				printf("������ 005: ��������� ����->");
		} while (s <= 100000 || s >= 999999);
		lect->id.number = s;

		printf("������� ��� �������� �������������->\n");
		do {
			scanf_s("%d", &s);
			if (s <= 1900 || s >= 2018)
				printf("������ 005: ��������� ����->");
		} while (s <= 1900 || s >= 2018);
		lect->yearofBirth = s;

		printf("������� ������ ������: 0 - ���������, 1 - ������, 2 - ���������->\n");
		do {
			scanf_s("%d", &s);
			if (s != 0 && s != 1 && s != 2)
				printf("������ 005: ��������� ����->");
		} while (s != 0 && s != 2 && s != 1);
		lect->grade = s;

		Lect_Arr->memory_ptr[i] = (void*)lect; //��������� � ������ ����������
	}
}

void get_stud(Array* Stud_Arr) { //�� �� ����� ��� ���������
	Student *stud;
	for (int i = 0; i < Stud_Arr->elements_count; i++) {
		stud = (Student*)stud_alloc();
		int l = 0, k = 0, s = 0;
		char c;

		//���������� �����
		stud->firstName = (char*)malloc(100 * sizeof(char));
		stud->middleName = (char*)malloc(100 * sizeof(char));
		stud->lastName = (char*)malloc(100 * sizeof(char));
		printf("������� ��� �������� c ��������� �� ����� 100 �������� � ������� Enter->\n");
		c = getchar();
		while (((c = getchar()) != ' ') && (k != 100)) {
			*((stud->lastName) + l) = c;
			k = k + 1;
			l = l + 1;
		} 
		stud->lastName = realloc(stud->lastName, (k+1)*sizeof(char)); 
		stud->lastName[l] = '\0'; 
		k = 0; l = 0;

		while (((c = getchar()) != ' ') && (k != 100)) {
			stud->firstName[l] = c;
			k = k + 1;
			l = l + 1;
		} 
		stud->firstName = (char*)realloc(stud->firstName, (k+1)*sizeof(char)); 
		stud->firstName[l] = '\0'; 
		l = 0; k = 0;

		while (((c = getchar()) != '\n') && (k != 100)) {
			*((stud->middleName) + l) = c;
			k = k + 1;
			l = l + 1;
		} 
		stud->middleName = (char*)realloc(stud->middleName, (k+1)*sizeof(char)); 
		stud->middleName[l] = '\0';

		printf("������� ����� �������� � ������� XXXX->\n");
		do {
			scanf_s("%d", &s);
			if (s <= 1000 || s >= 9999)
				printf("������ 005: ��������� ����->");
		} while (s <= 1900 && s >= 2018);
		stud->id.series = s;
		printf("������� ����� �������� � ������� XXXXXX->\n");
		do {
			scanf_s("%d", &s);
			if (s <= 100000 || s >= 999999)
				printf("������ 005: ��������� ����->");
		} while (s <= 100000 || s >= 999999);
		stud->id.number = s;

		printf("������� ��� �������� ��������->\n");
		do {
			scanf_s("%d", &s);
			if (s <= 1900 || s >= 2018)
				printf("������ 005: ��������� ����->");
		} while (s <= 1900 || s >= 2018);
		stud->yearofBirth = s;

		printf("������� ������ �������� �� �������� ����������� �� 1 �� 10 ->\n");
		do {
			scanf_s("%d", &s);
			if (s < 1 || s > 10)
				printf("������ 005: ��������� ����->");
		} while (s < 1 || s > 10);
		stud->rate = s;

		Stud_Arr->memory_ptr[i] = (void*)stud;
	}
}

void out(Array* Lect_Arr, Array* Stud_Arr) {
	int l;
	char d;
	printf("\n�������������\n\n");
		for (int i = 0; i < Lect_Arr->elements_count; i++) {
			Lecturer* lecturer = (Lecturer*)Lect_Arr->memory_ptr[i];
			printf("\n");
			printf("�������: ");
			for (l = 0; (lecturer->lastName[l]) != '\0'; l++) {
				d = lecturer->lastName[l];
				putchar(d);
			} putchar('\n');
			printf("���: ");
			for (l = 0; (lecturer->firstName[l]) != '\0'; l++) {
				d = lecturer->firstName[l];
				putchar(d);
			} putchar('\n');
			printf("��������: ");
			for (l = 0; (lecturer->middleName[l]) != '\0'; l++) {
				d = lecturer->middleName[l];
				putchar(d);
			} putchar('\n');
			printf("����� ��������: ");
			int q = lecturer->id.series;
			printf("%d\n", q);
			printf("����� ��������: ");
			q = lecturer->id.number;
			printf("%d\n", q);
			printf("��� ��������: ");
			q = lecturer->yearofBirth;
			printf("%d\n", q);
			printf("������: ");
			q = lecturer->grade;
			if (q == 0)
				printf("���������\n");
			if (q == 1)
				printf("������\n");
			if (q == 2)
				printf("���������\n");
			//free(lecturer);
		}

	printf("\n��������\n\n");
		for (int i = 0; i < Stud_Arr->elements_count; i++) {
			Student* student = Stud_Arr->memory_ptr[i];
			printf("\n");
			printf("�������: ");
			for (l = 0; (student->lastName[l]) != '\0'; l++) {
				d = student->lastName[l];
				putchar(d);
			} putchar('\n');
			printf("���: ");
			for (l = 0; (student->firstName[l]) != '\0'; l++) {
				d = student->firstName[l];
				putchar(d);
			} putchar('\n');
			printf("��������: ");
			for (l = 0; (student->middleName[l]) != '\0'; l++) {
				d = student->middleName[l];
				putchar(d);
			} putchar('\n');
			printf("����� ��������: ");
			int q = student->id.series;
			printf("%d\n", q);
			printf("����� ��������: ");
			q = student->id.number;
			printf("%d\n", q);
			printf("��� ��������: ");
			q = student->yearofBirth;
			printf("%d\n", q);
			printf("������ �� �����������: ");
			q = student->rate;
			printf("%d\n", q);
		}
}

void out_concate(Array* new_arr, int lect_count, int stud_count) {
	int l, i;
	char d;
	printf("\n�������������\n\n");
	for (i = 0; i < lect_count; i++) {
		Lecturer* lecturer = (Lecturer*)new_arr->memory_ptr[i];
		printf("\n");
		printf("�������: ");
		for (l = 0; (lecturer->lastName[l]) != '\0'; l++) {
			d = lecturer->lastName[l];
			putchar(d);
		} putchar('\n');
		printf("���: ");
		for (l = 0; (lecturer->firstName[l]) != '\0'; l++) {
			d = lecturer->firstName[l];
			putchar(d);
		} putchar('\n');
		printf("��������: ");
		for (l = 0; (lecturer->middleName[l]) != '\0'; l++) {
			d = lecturer->middleName[l];
			putchar(d);
		} putchar('\n');
		printf("����� ��������: ");
		int q = lecturer->id.series;
		printf("%d\n", q);
		printf("����� ��������: ");
		q = lecturer->id.number;
		printf("%d\n", q);
		printf("��� ��������: ");
		q = lecturer->yearofBirth;
		printf("%d\n", q);
		printf("������: ");
		q = lecturer->grade;
		if (q == 0)
			printf("���������\n");
		if (q == 1)
			printf("������\n");
		if (q == 2)
			printf("���������\n");
	}

	printf("\n��������\n\n");
	while(i < lect_count + stud_count && stud_count != 0) {
		Student* student = new_arr->memory_ptr[i];
		printf("\n");
		printf("�������: ");
		for (l = 0; (student->lastName[l]) != '\0'; l++) {
			d = student->lastName[l];
			putchar(d);
		} putchar('\n');
		printf("���: ");
		for (l = 0; (student->firstName[l]) != '\0'; l++) {
			d = student->firstName[l];
			putchar(d);
		} putchar('\n');
		printf("��������: ");
		for (l = 0; (student->middleName[l]) != '\0'; l++) {
			d = student->middleName[l];
			putchar(d);
		} putchar('\n');
		printf("����� ��������: ");
		int q = student->id.series;
		printf("%d\n", q);
		printf("����� ��������: ");
		q = student->id.number;
		printf("%d\n", q);
		printf("��� ��������: ");
		q = student->yearofBirth;
		printf("%d\n", q);
		printf("������ �� �����������: ");
		q = student->rate;
		printf("%d\n", q);
		i++;
	}
}

void free_Lecturer(Array* Lect_Arr) {
	for (int i = 0; i < Lect_Arr->elements_count; i++) {
		Lecturer* lect = (Lecturer*)Lect_Arr->memory_ptr[i];
		char* name = lect->firstName;
		free(name);
		name = lect->lastName;
		free(name);
		name = lect->middleName;
		free(name);
		free(lect);
	}

	if (Lect_Arr->elements_count != 0) {
		void** A = Lect_Arr->memory_ptr;
		free(A);
	}

	Array* arr = Lect_Arr;
	free(arr);
}

void free_Student(Array* Stud_Arr) {
	for (int i = 0; i < Stud_Arr->elements_count; i++) {
		Student* stud = (Student*)Stud_Arr->memory_ptr[i];
		char* name = stud->firstName;
		free(name);
		name = stud->lastName;
		free(name);
		name = stud->middleName;
		free(name);
		free(stud);
	}

	if (Stud_Arr->elements_count != 0) {
		void** B = Stud_Arr->memory_ptr;
		free(B);
	}

	Array* arr = Stud_Arr;
	free(arr);
}

void free_concate(Array* new_arr, int lect_count, int stud_count) {
	for (int i = 0; i < lect_count; i++) {
		Lecturer* lect = (Lecturer*)new_arr->memory_ptr[i];
		char* name = lect->firstName;
		free(name);
		name = lect->lastName;
		free(name);
		name = lect->middleName;
		free(name);
		free(lect);
	}
	for (int i = 0; i < stud_count; i++) {
		Student* stud = (Student*)new_arr->memory_ptr[i + lect_count];
		char* name = stud->firstName;
		free(name);
		name = stud->lastName;
		free(name);
		name = stud->middleName;
		free(name);
		free(stud);
	}

	void** A = new_arr->memory_ptr;
	free(A);

	Array* arr = new_arr;
	free(arr);
}
	
//�������� �������

void map(Array* arr, void* function(void*)) {
	int i;

	for (i = 0; i < arr->elements_count; i++) {
		void* struct_ptr = arr->memory_ptr[i];
		function(struct_ptr);
	}
}

void where(Array* arr, int function(void*)) {
	int i, k = 0;
	for (i = 0; i < arr->elements_count; i++) {
		void* struct_ptr = arr->memory_ptr[i];
		if ((function(struct_ptr)) == TRUE) {
			arr->memory_ptr[k] = struct_ptr;
			k = k + 1;
		}
		if ((function(struct_ptr)) == FALSE) {
		}
	}
	arr->elements_count = k;
	arr->memory_ptr = (void**)realloc(arr->memory_ptr, arr->elements_count * sizeof(void*));
}

void* concat(Array* arr1, Array* arr2) {
	int i, new_count = arr1->elements_count + arr2->elements_count;
	Array* new_arr = array_alloc();
	array_set(new_arr, new_count);
	for (i = 0; i < arr1->elements_count; i++) 
			new_arr->memory_ptr[i] = arr1->memory_ptr[i];
	for (i = 0; i < arr2->elements_count; i++)
		new_arr->memory_ptr[i + arr1->elements_count] = arr2->memory_ptr[i];
	
	return(new_arr);
}

//������� ��� ��������
void* grade_change(Lecturer* struct_ptr) {
	struct_ptr->grade = 2;
	return (struct_ptr);
}

void* No_Birthday_Stud(Student* struct_ptr) {
	struct_ptr->yearofBirth = 0000;
	return(struct_ptr);
}

int age_sort_stud(Student* struct_ptr) {
	if ((2018 - struct_ptr->yearofBirth) <= 21)
		return TRUE;
	else
		return FALSE;
}

int grade_sort(Lecturer* struct_ptr) {
	if (struct_ptr->grade == 2)
		return TRUE;
	else
		return FALSE;
}
