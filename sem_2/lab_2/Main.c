#include <malloc.h>
#include <stdio.h>
#include <locale.h>
#include "Header.h"
#define TRUE 1
#define FALSE 0

int main() {
	setlocale(LC_ALL, "Rus");
	int track2, stop, track1, stop1 = 0, con1 = FALSE, con2 = FALSE, flag1 = 0, flag = 0;

	printf("Áóäåì ëè òåñòèðîâàòü ôóíêöèè 0 - NO/1 - YES -->");
	do {
	scanf_s("%d", &stop);
	rewind(stdin);
	if (stop != 0 && stop != 1)
	printf("ÎØÈÁÊÀ: ïîâòîðèòå ââîä->");
	} while (stop != 0 && stop != 1);
	if (stop == TRUE)
	Testing();

	do {
		printf("Âûáåðèòå ñ êàêèì òèïîì äàííûõ ðàáîòàåì: 1 - ÔÓÍÊÖÈÈ, 2 - ÑÒÐÎÊÈ->\n");
		do {
			scanf_s("%d", &track1);
			rewind(stdin);
			if (track1 != 1 && track1 != 2)
				printf("ÎØÈÁÊÀ: ïîâòîðèòå ââîä->");
		} while (track1 != 1 && track1 != 2);
		printf("\nÂûáåðèòå ôóíêöèþ concat(1), extract(2), search(3)-->\n");
		do {
			scanf_s("%d", &track2);
			rewind(stdin);
			if (track2 != 1 && track2 != 2 && track2 != 3)
				printf("ÎØÈÁÊÀ: ïîâòîðèòå ââîä->");
		} while (track2 != 1 && track2 != 2 && track2 != 3);

		GoInterface(track1, track2);
		
		printf("\nÐÀÁÎÒÀ ÇÀÂÅÐØÅÍÀ\n\nÏÐÎÄÎËÆÈÒÜ ðàáîòó ïðîãðàììû? (1 - äà, 0 - íåò)-->");
		do {
			scanf_s("%d", &stop);
			rewind(stdin);
			if (stop != TRUE && stop != FALSE)
				printf("ÎØÈÁÊÀ: ïîâòîðèòå ââîä->");
		} while (stop != TRUE && stop != FALSE);
	} while (stop == TRUE);

	system("PAUSE");
	return 0;
}
