#include <iostream>
#include <math.h>
#include <string>
#include "Template.h"
#include "Testing.h"
#define TRUE 1
#define FALSE 0

using namespace std;

int func1(int n) {
	return n * n;
}

int func2(int n) {
	if (n == 0 || n == 1)
		return 1;
	return n * func2(n - 1);
}

int func3(int n) {
	return n + 1;
}

int func4(int n) {
	return 2 * n;
}

int func5(int n) {
	if (n >= 0)
		return TRUE;
	if (n < 0)
		return FALSE;
	else
		return FALSE;
}

int func6(int n) {
	return n - n + 33;
}

void GoInterface(int type, int function) {
	if (type == 2) {
		cout << "������\n" << endl;
		if (function == 1) {
			cout << "MAP ����������� ������ ������ ������ � �������� ������\n";
			Tree<string> *string_tree = new Tree<string>;
			string_tree->SetTree();
			cout << "������� ������������� ������: " << endl;
			string for_map; cin >> for_map;
			string_tree->map(for_map);
			string_tree->PrintByLevels();
			string_tree->RCLrootPrint();
			delete string_tree;
		}
		if (function == 2) {
			cout << "WHERE ����� ������, ��������� ������ �� �����, ���������� �������� � ������� < 7\n\n";
			Tree<string> *string_tree = new Tree<string>;
			Tree<string> *res_string_tree = new Tree<string>;
			string_tree->SetTree();
			string_tree->where(res_string_tree);
			if (res_string_tree->GetRoot() == nullptr) cout << "ERROR 404: not found" << endl;
			else {
				res_string_tree->RCLrootPrint();
				res_string_tree->PrintByLevels();
			}
			delete string_tree;
			delete res_string_tree;
		}
		if (function == 3) {
			cout << "������ ������ ��� �������:" << endl;
			Tree<string> *first_string_tree = new Tree<string>;
			first_string_tree->SetTree();
			cout << "������ ������ ��� �������:" << endl;
			Tree<string> *second_string_tree = new Tree<string>;
			second_string_tree->SetTree();
			second_string_tree->MergeTrees(first_string_tree);
			cout << "���������: " << endl;
			first_string_tree->RCLrootPrint();
			first_string_tree->PrintByLevels();
			delete first_string_tree;
			delete second_string_tree;
		}
		if (function == 4) {
			Tree<string> *string_tree = new Tree<string>;
			Tree<string> *res_string_tree = new Tree<string>;
			string_tree->SetTree();
			cout << "������� ������: ";
			string str; cin >> str;
			string_tree->SubtreeExtraction(str, res_string_tree);
			cout << "��������� ���������� ��������� �� ��������� ��������: " << endl;
			if (res_string_tree->GetRoot() == nullptr) cout << "ERROR 404" << endl;
			else {
				res_string_tree->RCLrootPrint();
				res_string_tree->PrintByLevels();
			}
			delete string_tree;
		}

		if (function == 5) {
			Tree<string> *string_tree = new Tree<string>;
			cout << "������� ������ " << endl;
			string_tree->SetTree();
			Tree<string> *string_subtree = new Tree<string>;
			cout << "������� ��������� " << endl;
			string_subtree->SetTree();
			if (string_tree->IfTreeContain(string_subtree)) cout << "�������" << endl;
			else cout << "ERROR 404: not found" << endl;
			delete string_tree;
			delete string_subtree;
		}

		if (function == 6) {
			Tree<string> *string_tree = new Tree<string>;
			string_tree->SetTree();
			cout << "������� ������, ��� ������� ���� ���������, ���������� �� ��� � ������: ";
			string str; cin >> str;
			if (string_tree->IfElementContain(str)) cout << "����������" << endl;
			else cout << "ERROR 404: not found" << endl;
			delete string_tree;
		}
		else
			;
	}

	if (type == 1) {
		cout << "�������" << endl;
		void *ptr[] = { (void*)func1, (void*)func2, (void*)func3, (void*)func4, (void*)func5 };
			if (function == 1) {
				cout << "MAP ����������� ������ ������� ������ � ��������\n\n";
				Tree<void*> *func_tree = new Tree<void*>;
				func_tree->SetFunctionTree(ptr);
				cout << "������� ������������� �������: " << endl;
				int func_number;

				do {
					cin >> func_number;
				} while (func_number != 1 && func_number != 2 && func_number != 3 && func_number != 4 && func_number != 5);
				void *for_map = ptr[func_number - 1];
				func_tree->map(for_map);
				func_tree->PrintByLevels();
				func_tree->PrintValueFunction();
				delete func_tree;
			}
			if (function == 2) {
				cout << "WHERE ����� ������, ��������� ������ �� �������, f(5)<10\n";
				Tree<void*> *func_tree = new Tree<void*>;
				Tree<void*> *res_func_tree = new Tree<void*>;
				func_tree->SetFunctionTree(ptr);
				func_tree->where(res_func_tree);
				if (res_func_tree->GetRoot() == nullptr) cout << "ERROR 404: not found" << endl;
				else {
					res_func_tree->PrintByLevels();
					res_func_tree->PrintValueFunction();
				}
				delete func_tree;
				delete res_func_tree;
			}
			if (function == 3) {
				cout << "������ ������ ��� �������:" << endl;
				Tree<void*> *first_functional_tree = new Tree<void*>;
				first_functional_tree->SetFunctionTree(ptr);
				cout << "������ ������ ��� �������:" << endl;
				Tree<void*> *second_functional_tree = new Tree<void*>;
				second_functional_tree->SetFunctionTree(ptr);
				second_functional_tree->MergeTrees(first_functional_tree);
				cout << "���������: " << endl;
				first_functional_tree->PrintByLevels();
				first_functional_tree->RCLrootPrint();
				first_functional_tree->PrintValueFunction();
				delete first_functional_tree;
				delete second_functional_tree;
			}
			if (function == 4) {
				Tree<void*> *functional_tree = new Tree<void*>;
				Tree<void*> *res_functional_tree = new Tree<void*>;
				functional_tree->SetFunctionTree(ptr);
				cout << "�������� ������� ��� ����������: " << endl;
				int func_number;
				do {
					cin >> func_number;
				} while (func_number != 1 && func_number != 2 && func_number != 3 && func_number != 4 && func_number != 5);
				void *func = ptr[func_number - 1];
				functional_tree->SubtreeExtraction(func, res_functional_tree);
				if (functional_tree->GetRoot() == nullptr) cout << "ERROR 404: not found" << endl;
				res_functional_tree->PrintByLevels();
				res_functional_tree->PrintValueFunction();
				delete functional_tree;
			}
			if (function == 5) {
				Tree<void*> *func_tree = new Tree<void*>;
				cout << "������� ������ " << endl;
				func_tree->SetFunctionTree(ptr);
				Tree<void*> *func_subtree = new Tree<void*>;
				cout << "������� ��������� " << endl;
				func_subtree->SetFunctionTree(ptr);
				if (func_tree->IfTreeContain(func_subtree)) cout << "����������" << endl;
				else cout << "ERROR 404: not found" << endl;
				delete func_tree;
				delete func_subtree;
			}
			if (function == 6) {
				Tree<void*> *func_tree = new Tree<void*>;
				func_tree->SetFunctionTree(ptr);
				cout << "�������� �������, ��� ������� ���� ���������, ���������� �� ��� � ������: ";
				int func_number;
				do {
					cin >> func_number;
				} while (func_number != 1 && func_number != 2 && func_number != 3 && func_number != 4 && func_number != 5);
				void *func = ptr[func_number - 1];
				if (func_tree->IfElementContain(func)) cout << "����������" << endl;
				else cout << "ERROR 404: not found" << endl;
				delete func_tree;
			}
			else
				;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	int track2, stop, track1, stop1 = 0, con1 = FALSE, con2 = FALSE, flag1 = 0, flag = 0;
	cout << "����� �� ����������� ������� 0 - NO/1 - YES -->";
	do {
		scanf_s("%d", &stop);
		rewind(stdin);
		if (stop != 0 && stop != 1)
			printf("������: ��������� ����->");
	} while (stop != 0 && stop != 1);
	if (stop == TRUE)
		Testing();

	do {
		cout  << "�������� � ����� ����� ������ ��������: 1 - �������, 2 - ������->\n";
		do {
			scanf_s("%d", &track1);
			rewind(stdin);
			if (track1 != 1 && track1 != 2)
				printf("������: ��������� ����->");
		} while (track1 != 1 && track1 != 2);
		cout << "\n�������� �������:\n 1 - map\n 2 - where\n 3 - �������\n 4 - ���������� ��������� �� ��������� ��������\n 5 - ����� �� ��������� ���������\n 6 - ����� �������� �� ��������� -->\n";
		do {
			scanf_s("%d", &track2);
			rewind(stdin);
			if (track2 != 1 && track2 != 2 && track2 != 3 && track2 != 4 && track2 != 5 && track2 != 6)
				printf("������: ��������� ����->");
		} while (track2 != 1 && track2 != 2 && track2 != 3 && track2 != 4 && track2 != 5 && track2 != 6);

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
