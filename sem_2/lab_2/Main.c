#include <malloc.h>
#include <stdio.h>
#include <locale.h>
#include "Header.h"
#define TRUE 1
#define FALSE 0

int main() {
	setlocale(LC_ALL, "Rus");
	int track2, stop, track1, stop1 = 0, con1 = FALSE, con2 = FALSE, flag1 = 0, flag = 0;

	printf("����� �� ����������� ������� 0 - NO/1 - YES -->");
	do {
	scanf_s("%d", &stop);
	rewind(stdin);
	if (stop != 0 && stop != 1)
	printf("������: ��������� ����->");
	} while (stop != 0 && stop != 1);
	if (stop == TRUE)
	Testing();

	do {
		printf("�������� � ����� ����� ������ ��������: 1 - �������, 2 - ������->\n");
		do {
			scanf_s("%d", &track1);
			rewind(stdin);
			if (track1 != 1 && track1 != 2)
				printf("������: ��������� ����->");
		} while (track1 != 1 && track1 != 2);
		printf("\n�������� ������� concat(1), extract(2), search(3)-->\n");
		do {
			scanf_s("%d", &track2);
			rewind(stdin);
			if (track2 != 1 && track2 != 2 && track2 != 3)
				printf("������: ��������� ����->");
		} while (track2 != 1 && track2 != 2 && track2 != 3);

		GoInterface(track1, track2);
		
		printf("\n������ ���������\n\n���������� ������ ���������? (1 - ��, 0 - ���)-->");
		do {
			scanf_s("%d", &stop);
			rewind(stdin);
			if (stop != TRUE && stop != FALSE)
				printf("������: ��������� ����->");
		} while (stop != TRUE && stop != FALSE);
	} while (stop == TRUE);

	system("PAUSE");
	return 0;
}
