#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Graph.h"
#include "Test.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	srand(static_cast<unsigned int>(time(0)));

	Test_Find_Shortest_Path();

	while (1) {
		int section;

		do {
			cout << "�������� ��������:" << endl;
			cout << "1 - ����� ����������� ����\n2 - �����\n�����:   ";
			while (!(cin >> section)) {
				cin.clear();
				cout << "ERROR: ������� �����--> " << endl;
				while (cin.get() != '\n') continue;
			}
			if (section != 1 && section != 2 && section != 3)
				cout << "������: ��������� ����->";
		} while (section != 1 && section != 2 && section != 3);

		if (section == 1) {
			int number, u, v;
			do {
				cout << "������� ���������� ������ ������������������ �����: " << endl;
				while (!(cin >> number)) {
					cin.clear();
					cout << "ERROR: ������� �����--> " << endl;
					while (cin.get() != '\n') continue;
				}
				if (number < 1)
					cout << "������: ��������� ����->";
			} while (number < 1);

			Graph<int> G = Graph<int>(number);

			vector<vector<int> *> vect = G.FindShortestPath();

			G.printMatrix();

			cout << "���������� ���������� ����� ����� ��������� ����� G ������������ � �������:\n " << endl;

			for (int i = 0; i < number; i++) {
				cout << " ";
				for (int j = 0; j < number; j++) {
					cout << "    " << vect[0][i][j] << "    ";
				}
				cout << endl;
			}

			bool f = 1;

			do {
				cout << "������� ��� ������� ����� ����� �������� ���������� ������������ ���������� ����: " << endl;
				do {
					cout << "������� 1 �������: " << endl;
					while (!(cin >> u)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (u < 0)
						cout << "������: ��������� ����->";
				} while (u < 0);

				do {
					cout << "������� 2 �������: " << endl;
					while (!(cin >> v)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (v < 0)
						cout << "������: ��������� ����->";
				} while (v < 0);

				cout << "���������� ����: \n";
				try {
					G.ConstructPath(vect[1], u, v);
				}
				catch (BadIndex ex1) {
					ex1.what();
				}

				do {
					cout << "����������?\n 1 - ��\n 0 - ���\n �����: ";
					while (!(cin >> f)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (f != 0 && f != 1)
						cout << "������: ��������� ����->";
				} while (f != 0 && f != 1);

			} while (f == 1);
		}

		else if (section == 2)
			return -1;

		system("pause");
	
	}
}

