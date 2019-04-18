#include <iostream>
#include <assert.h>
#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Sorters.h"
#include "Binary_Search.h"
#include "BTree.h"
#include "Exceptions.h"
#include "Student.h"
#include "IDictionary.h"
#include "Test.h"
#include "Help_Func.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	Test_Binary_Search(); Test_Dictionary(); Test_BTree();

	srand(static_cast<unsigned int>(time(0)));

	while (1) {
		int section;

		do {
			cout << "�������� ������:" << endl;
			cout << "1 - �������� �����\n2 - ���-�������\n3 - B/�+-������\n4 - ��������� ������\n�����:   ";
			while (!(cin >> section)) {
				cin.clear();
				cout << "ERROR: ������� �����--> " << endl;
				while (cin.get() != '\n') continue;
			}
			if (section < 1 or section > 4)
				cout << "������: ��������� ����->";
		} while (section != 1 && section != 2 && section != 3 && section != 4);

		if (section == 1) {
			int vvod;

			do {
				cout << "�������� ����� ������:\n1 - ������ ����\n2 - �������������� ����\n�����:    ";
				while (!(cin >> vvod)) {
					cin.clear();
					cout << "ERROR: ������� �����--> " << endl;
					while (cin.get() != '\n') continue;
				}
				if (vvod != 1 && vvod != 2)
					cout << "������: ��������� ����->";
			} while (vvod != 1 && vvod != 2);
			
			if (vvod == 1) {
				ArraySequence<Student> ArraySeq;
				int amount_of_el;
				do {
					cout << "������� ���������� ��������� � ������������������: ";
					while (!(cin >> amount_of_el)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (amount_of_el < 1)
						cout << "������: ��������� ����->";
				} while (amount_of_el < 1);

				cout << "������� ������� � ���� ��������" << endl;
				for (int i = 0; i < amount_of_el; i++) {
					cout << "C������ " << i << ":" << endl;
					cout << "���:  ";
					string name; cin >> name;
					cout << "���� �������� (����� ������):\n";
					int d; int m; int g;
					do {
						cout << "������� ����: ";
						while (!(cin >> d)) {
							cin.clear();
							cout << "ERROR: ������� �����--> " << endl;
							while (cin.get() != '\n') continue;
						}
						if (d > 31 || d < 1)
							cout << "������: ��������� ����->";
					} while (d > 31 || d < 1);
					do {
						cout << "������� �����: ";
						while (!(cin >> m)) {
							cin.clear();
							cout << "ERROR: ������� �����--> " << endl;
							while (cin.get() != '\n') continue;
						}
						if (m > 12 || m < 1)
							cout << "������: ��������� ����->";
					} while (m > 12 || m < 1);
					do {
						cout << "������� ���: ";
						while (!(cin >> g)) {
							cin.clear();
							cout << "ERROR: ������� �����--> " << endl;
							while (cin.get() != '\n') continue;
						}
						if (g > 2018 || g < 1900)
							cout << "������: ��������� ����->";
					} while (g > 2018 || g < 1900);
					
					Student stud = Student(name, d, m, g);
					ArraySeq.Append(stud);
				}

				Sorter<Student> sort;
				ArraySequence<Student> arr1;
				arr1 = ArraySeq;
				sort.QuickSort(&arr1);
				ArraySeq.printAll();
				arr1.printAll();

				cout << "������� �������, ������� ������ �����:\n";
				cout << "C������: " << endl;
				cout << "���:  ";
				string name; cin >> name;
				cout << "���� ��������:\n";
				int d; int m; int g;
				do {
					cout << "������� ����: ";
					while (!(cin >> d)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (d > 31 || d < 1)
						cout << "������: ��������� ����->";
				} while (d > 31 || d < 1);
				do {
					cout << "������� �����: ";
					while (!(cin >> m)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (m > 12 || m < 1)
						cout << "������: ��������� ����->";
				} while (m > 12 || m < 1);
				do {
					cout << "������� ���: ";
					while (!(cin >> g)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (g > 2018 || g < 1900)
						cout << "������: ��������� ����->";
				} while (g > 2018 || g < 1900);

				int fib_n;
				do {
					cout << "��� ��������� ������ � �������� ������ ��������� ������� ����� ����� ���������: ";
					while (!(cin >> fib_n)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (fib_n < 2 || fib_n > 15)
						cout << "������: ��������� ����->";
				} while (fib_n < 2 || fib_n > 15);

				int prop1; int prop2;
				cout << "��� ��������� ������ � �������� �������� ������� ��������� � ������� X:Y\n";
				do {
					cout << "������� X: ";
					while (!(cin >> prop1)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (prop1 < 1)
						cout << "������: ��������� ����->";
				} while (prop1 < 1);
				do {
					cout << "������� Y: ";
					while (!(cin >> prop2)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (prop2 < 1)
						cout << "������: ��������� ����->";
				} while (prop2 < 1);
				
				int atr;
				do {
					cout << "�������� ������� ������:\n1 - ���, 2 - ���� ��������, 3 - ��� �������� ";
					while (!(cin >> atr)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (atr != 1 && atr != 2 && atr != 3 && atr != 4)
						cout << "������: ��������� ����->";
				} while (atr != 1 && atr != 2 && atr != 3 && atr != 4);
				
				Student stud_ = Student(name, d, m, g);

				if (atr == 1) {
					for (int i = 0; i < amount_of_el; i++) {
						ArraySeq.GetPointer(i)->set_flag(1);
					}
					stud_.set_flag(1);
				}
				else if (atr == 2) {
					for (int i = 0; i < amount_of_el; i++) {
						ArraySeq.GetPointer(i)->set_flag(2);
					}
					stud_.set_flag(2);
				}
				else if (atr == 3) {
					for (int i = 0; i < amount_of_el; i++) {
						ArraySeq.GetPointer(i)->set_flag(0);
					}
					stud_.set_flag(0);
				}
				else
					;

				try {
					int index = Search_Binary_Base(&ArraySeq, stud_);
					cout << "������ �������� �������� � ��������������� ������������������: " << index << endl;
					Student res_stud = ArraySeq.Get(index);
					cout << "������� �������: " << res_stud << endl;
				}
				catch (ElementNotFoundException<Student> ex1) {
					ex1.what();
				}
				catch (EmptySequenceException ex2) {
					ex2.what();
				}
				catch (NoMeaningFibException ex3) {
					ex3.what();
				}
				try {
					cout << "����� ��� �������� ��������� ������: " << Time_For_Search_Binary_Base(&ArraySeq, stud_)[1] << " ��" << endl;
				}
				catch (ElementNotFoundException<Student> ex1) {
					ex1.what();
				}
				catch (EmptySequenceException ex2) {
					ex2.what();
				}
				catch (NoMeaningFibException ex3) {
					ex3.what();
				}
				try {
					cout << "����� ��� ��������� ������ � �������� ������� ��������: " << Time_For_Search_Binary_Golden_Ratio(&ArraySeq, stud_)[1] << " ��" << endl;
				}
				catch (ElementNotFoundException<Student> ex1) {
					ex1.what();
				}
				catch (EmptySequenceException ex2) {
					ex2.what();
				}
				catch (NoMeaningFibException ex3) {
					ex3.what();
				}
				try {
					cout << "����� ��� ��������� ������ � �������� ������ ���������: " << Time_For_Search_Binary_Fibonacci(&ArraySeq, stud_, fib_n)[1] << " ��" << endl;
				}
				catch (ElementNotFoundException<Student> ex1) {
					ex1.what();
				}
				catch (EmptySequenceException ex2) {
					ex2.what();
				}
				catch (NoMeaningFibException ex3) {
					ex3.what();
				}
				try {
					cout << "����� ��� ��������� ������ � �������� ��������: " << Time_For_Search_Binary_Own_Pair(&ArraySeq, stud_, prop1, prop2)[1] << " ��" << endl;
				}
				catch (ElementNotFoundException<Student> ex1) {
					ex1.what();
				}
				catch (EmptySequenceException ex2) {
					ex2.what();
				}
				catch (NoMeaningFibException ex3) {
					ex3.what();
				}
			}
			else if (vvod == 2) {
				ArraySequence<Student> ArraySeq;
				int amount_of_el;
				do {
					cout << "������� ���������� ��������� � ������������������: ";
					while (!(cin >> amount_of_el)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (amount_of_el < 1)
						cout << "������: ��������� ����->";
				} while (amount_of_el < 1);

				Rand_Stud_Seq_Gen(&ArraySeq, amount_of_el);

				ArraySeq.printAll();

				cout << "������� �������, ������� ������ �����:\n";
				cout << "C������: " << endl;
				cout << "���: ";
				string name; cin >> name;
				cout << "���� �������� (����� ������):\n";
				int d; int m; int g;
				do {
					cout << "������� ����: ";
					while (!(cin >> d)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (d > 31 || d < 1)
						cout << "������: ��������� ����->";
				} while (d > 31 || d < 1);
				do {
					cout << "������� �����: ";
					while (!(cin >> m)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (m > 12 || m < 1)
						cout << "������: ��������� ����->";
				} while (m > 12 || m < 1);
				do {
					cout << "������� ���: ";
					while (!(cin >> g)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (g > 2018 || g < 1900)
						cout << "������: ��������� ����->";
				} while (g > 2018 || g < 1900);

				int fib_n;
				do {
					cout << "��� ��������� ������ � �������� ������ ��������� ������� ����� ����� ���������: ";
					while (!(cin >> fib_n)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (fib_n < 2 || fib_n > 15)
						cout << "������: ��������� ����->";
				} while (fib_n < 2 || fib_n > 15);

				int prop1; int prop2;
				cout << "��� ��������� ������ � �������� �������� ������� ��������� � ������� X:Y\n";
				do {
					cout << "������� X: ";
					while (!(cin >> prop1)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (prop1 < 1)
						cout << "������: ��������� ����->";
				} while (prop1 < 1);
				do {
					cout << "������� Y: ";
					while (!(cin >> prop2)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (prop2 < 1)
						cout << "������: ��������� ����->";
				} while (prop2 < 1);

				Student stud_ = Student(name, d, m, g);

				int atr;
				do {
					cout << "�������� ������� ������:\n1 - ���, 2 - ���� ��������, 3 - ��� �������� ";
					while (!(cin >> atr)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (atr != 1 && atr != 2 && atr != 3 && atr != 4)
						cout << "������: ��������� ����->";
				} while (atr != 1 && atr != 2 && atr != 3 && atr != 4);

				if (atr == 1) {
					for (int i = 0; i < amount_of_el; i++) {
						ArraySeq.GetPointer(i)->set_flag(1);
					}
					stud_.set_flag(1);
				}
				else if (atr == 2) {
					for (int i = 0; i < amount_of_el; i++) {
						ArraySeq.GetPointer(i)->set_flag(2);
					}
					stud_.set_flag(2);
				}
				else if (atr == 3) {
					for (int i = 0; i < amount_of_el; i++) {
						ArraySeq.GetPointer(i)->set_flag(0);
					}
					stud_.set_flag(0);
				}
				else
					;

				try {
					int index = Search_Binary_Base(&ArraySeq, stud_);
					cout << "������ �������� �������� � ��������������� ������������������: " << index << endl;
					Student res_stud = ArraySeq.Get(index);
					cout << "������� �������: " << res_stud << endl;
				}
				catch (ElementNotFoundException<Student> ex1) {
					ex1.what();
				}
				catch (EmptySequenceException ex2) {
					ex2.what();
				}
				catch (NoMeaningFibException ex3) {
					ex3.what();
				}
				try {
					cout << "����� ��� �������� ��������� ������: " << Time_For_Search_Binary_Base(&ArraySeq, stud_)[1] << " ��" << endl;
				}
				catch (ElementNotFoundException<Student> ex1) {
					ex1.what();
				}
				catch (EmptySequenceException ex2) {
					ex2.what();
				}
				catch (NoMeaningFibException ex3) {
					ex3.what();
				}
				try {
					cout << "����� ��� ��������� ������ � �������� ������� ��������: " << Time_For_Search_Binary_Golden_Ratio(&ArraySeq, stud_)[1] << " ��" << endl;
				}
				catch (ElementNotFoundException<Student> ex1) {
					ex1.what();
				}
				catch (EmptySequenceException ex2) {
					ex2.what();
				}
				catch (NoMeaningFibException ex3) {
					ex3.what();
				}
				try {
					cout << "����� ��� ��������� ������ � �������� ������ ���������: " << Time_For_Search_Binary_Fibonacci(&ArraySeq, stud_, fib_n)[1] << " ��" << endl;
				}
				catch (ElementNotFoundException<Student> ex1) {
					ex1.what();
				}
				catch (EmptySequenceException ex2) {
					ex2.what();
				}
				catch (NoMeaningFibException ex3) {
					ex3.what();
				}
				try {
					cout << "����� ��� ��������� ������ � �������� ��������: " << Time_For_Search_Binary_Own_Pair(&ArraySeq, stud_, prop1, prop2)[1] << " ��" << endl;
				}
				catch (ElementNotFoundException<Student> ex1) {
					ex1.what();
				}
				catch (EmptySequenceException ex2) {
					ex2.what();
				}
				catch (NoMeaningFibException ex3) {
					ex3.what();
				}
			}
		}
		else if (section == 2) {
			IDictionary<string, Student> dict;
			int f = 1;
			while(f == 1) {
				int act;
				do {
					cout << "�������� ��������:  \n1 - �������� �������\n2 - ������� �������\n3 - ��������� �������� �� �����\n4 - ��������, ��� � ������� ��� ���� ������� � �������� ������\n5 - �����\n�����: ";
					while (!(cin >> act)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (act != 1 && act != 2 && act != 3 && act != 4 && act != 5)
						cout << "������: ������� ���������� ��������(�� 1 �� 5):  ";
				} while (act != 1 && act != 2 && act != 3 && act != 4 && act != 5);
				
				if (act == 1) {
					
					int act1;
					do {
						cout << "�������� ��������:  \n1 - ��������� ���������� ����������\n2 - ������ �������\n�����:  ";
						while (!(cin >> act1)) {
							cin.clear();
							cout << "ERROR: ������� �����--> " << endl;
							while (cin.get() != '\n') continue;
						}
						if (act1 != 1 && act1 != 2 && act1 != 3 && act1 != 4 && act1 != 5)
							cout << "������: ������� ���������� ��������:  ";
					} while (act1 != 1 && act1 != 2 && act1 != 3 && act1 != 4 && act1 != 5);

					if (act1 == 1) {
						int amount_of_elem;
						do {
							cout << "������� ���������� ��������� � ������������������: ";
							while (!(cin >> amount_of_elem)) {
								cin.clear();
								cout << "ERROR: ������� �����--> " << endl;
								while (cin.get() != '\n') continue;
							}
							if (amount_of_elem < 1)
								cout << "������: ��������� ����->";
						} while (amount_of_elem < 1);

						ArraySequence<Student> Stud_Arr;
						Rand_Stud_Seq_Gen(&Stud_Arr, amount_of_elem);
						for (int i = 0; i < amount_of_elem; i++)
							dict.Add(Stud_Arr.Get(i).GetName(), Stud_Arr.Get(i));
						cout << "������������ ���-�������:" << endl;
						dict.printAll();
						cout << "Capacity: " << dict.GetCapacity() << endl;
						cout << "Count: " << dict.GetCount() << endl;
					}

					else if (act1 == 2) {
						int amount_of_elem;
						do {
							cout << "������� ���������� ��������� � ������������������: ";
							while (!(cin >> amount_of_elem)) {
								cin.clear();
								cout << "ERROR: ������� �����--> " << endl;
								while (cin.get() != '\n') continue;
							}
							if (amount_of_elem < 1)
								cout << "������: ��������� ����->";
						} while (amount_of_elem < 1);
						while (amount_of_elem < 1) {
							cout << "������� ���������� ��������:  ";
							cin >> amount_of_elem;
						}
						string name;
						int d, m, g;
						cout << "������� ������� � ���� ��������" << endl;
						for (int i = 0; i < amount_of_elem; i++) {
							cout << "C������ " << i << ":" << endl;
							cout << "���:  ";
							string name; cin >> name;
							cout << "���� �������� (����� ������):\n";
							int d; int m; int g;
							do {
								cout << "������� ����: ";
								while (!(cin >> d)) {
									cin.clear();
									cout << "ERROR: ������� �����--> " << endl;
									while (cin.get() != '\n') continue;
								}
								if (d > 31 || d < 1)
									cout << "������: ��������� ����->";
							} while (d > 31 || d < 1);
							do {
								cout << "������� �����: ";
								while (!(cin >> m)) {
									cin.clear();
									cout << "ERROR: ������� �����--> " << endl;
									while (cin.get() != '\n') continue;
								}
								if (m > 12 || m < 1)
									cout << "������: ��������� ����->";
							} while (m > 12 || m < 1);
							do {
								cout << "������� ���: ";
								while (!(cin >> g)) {
									cin.clear();
									cout << "ERROR: ������� �����--> " << endl;
									while (cin.get() != '\n') continue;
								}
								if (g > 2018 || g < 1900)
									cout << "������: ��������� ����->";
							} while (g > 2018 || g < 1900);

							Student stud = Student(name, d, m, g);
							dict.Add(stud.GetName(), stud);
						}
						dict.printAll();
						cout << "Capacity: " << dict.GetCapacity() << endl;
						cout << "Count: " << dict.GetCount() << endl;
					}
				}

				else if (act == 2) {
					if (dict.GetCount() == 0) {
						cout << "������� �������� ������� � ������������������\n";
						act = 1;
					}
					else {
						cout << "������� ���� ��������, ������� ������ �������:  ";
						string k;
						cin >> k;

						try {
							dict.Remove(k);
						}
						catch (KeyIsNotExistException<string> ex1) {
							ex1.what();
						}
						cout << "������������ ���-�������:" << endl;
						dict.printAll();
						cout << "Capacity: " << dict.GetCapacity() << endl;
						cout << "Count: " << dict.GetCount() << endl;
					}
					
				}
				else if (act == 3) {
					if (dict.GetCount() == 0) {
						cout << "������� �������� ������� � ������������������\n";
						act = 1;
					}
					else {
						cout << "������� ���� ��� ��������� �������� ";
						string key;
						cin >> key;

						Student stud;
						try {
							stud = dict.Get(key);
						}
						catch (ElementNotFoundException<Student> ex1) {
							ex1.what();
						}
						cout << endl << stud;
					}
				}
				else if (act == 4) {
					if (dict.GetCount() == 0) {
						cout << "������� �������� ������� � ������������������\n";
						act = 1;
					}
					else {
						cout << "������� ���� ��� ������ �������� ";
						string key;
						cin >> key;

						bool flag = false;
						try {
							flag = dict.ContainsKey(key);
						}
						catch (ElementNotFoundException<Student> ex1) {
							ex1.what();
						}
	
						if (flag)
							cout << endl << "True";
						else if (!flag)
							cout << endl << "False";
					}
				}
				else if (act == 5) {
					f = -1;
				}
			}
		}

		else if (section == 3) {
			ArraySequence<Student> Stud_Arr;
			int t, f = 1;

			do {
				cout << "������� t - ����������� ������� B-������: ";
				while (!(cin >> t)) {
					cin.clear();
					cout << "ERROR: ������� �����--> " << endl;
					while (cin.get() != '\n') continue;
				}
				if (t > 10 || t < 1)
					cout << "������: ��������� ����->";
			} while (t > 10 || t < 1);
			
			BTreeBuilder<Student> builder = BTreeBuilder<Student>(t);

			int atr;
			do {
				cout << "�������� ������� ������:\n1 - ���, 2 - ���� ��������, 3 - ��� �������� ";
				while (!(cin >> atr)) {
					cin.clear();
					cout << "ERROR: ������� �����--> " << endl;
					while (cin.get() != '\n') continue;
				}
				if (atr != 1 && atr != 2 && atr != 3 && atr != 4)
					cout << "������: ��������� ����->";
			} while (atr != 1 && atr != 2 && atr != 3 && atr != 4);

			cout << "�������� �������� ��� ���������� ���������� B-������" << endl;

			int vvod;
			do {
				cout << "�������� ����� ������:\n1 - ������ ����\n2 - �������������� ����\n�����:    ";
				while (!(cin >> vvod)) {
					cin.clear();
					cout << "ERROR: ������� �����--> " << endl;
					while (cin.get() != '\n') continue;
				}
				if (vvod != 1 && vvod != 2)
					cout << "������: ������� ���������� ��������(1 ��� 2): ";
			} while (vvod != 1 && vvod != 2);

			if (vvod == 1) {

				int amount_of_el;
				do {
					cout << "������� ���������� ��������� � ������������������: ";
					while (!(cin >> amount_of_el)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (amount_of_el < 1)
						cout << "������: ��������� ����->";
				} while (amount_of_el < 1);

				cout << "������� ������� � ���� ��������" << endl;
				for (int i = 0; i < amount_of_el; i++) {
					cout << "C������ " << i << ":" << endl;
					cout << "���:  ";
					string name; cin >> name;
					cout << "���� �������� (����� ������):\n";
					int d; int m; int g;
					do {
						cout << "������� ����: ";
						while (!(cin >> d)) {
							cin.clear();
							cout << "ERROR: ������� �����--> " << endl;
							while (cin.get() != '\n') continue;
						}
						if (d > 31 || d < 1)
							cout << "������: ��������� ����->";
					} while (d > 31 || d < 1);
					do {
						cout << "������� �����: ";
						while (!(cin >> m)) {
							cin.clear();
							cout << "ERROR: ������� �����--> " << endl;
							while (cin.get() != '\n') continue;
						}
						if (m > 12 || m < 1)
							cout << "������: ��������� ����->";
					} while (m > 12 || m < 1);
					do {
						cout << "������� ���: ";
						while (!(cin >> g)) {
							cin.clear();
							cout << "ERROR: ������� �����--> " << endl;
							while (cin.get() != '\n') continue;
						}
						if (g > 2018 || g < 1900)
							cout << "������: ��������� ����->";
					} while (g > 2018 || g < 1900);

					Student stud = Student(name, d, m, g);
					Stud_Arr.Append(stud);
				}
			}

			else if (vvod == 2) {
				int amount_of_el;
				do {
					cout << "������� ���������� ��������� � ������������������: ";
					while (!(cin >> amount_of_el)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (amount_of_el < 1)
						cout << "������: ��������� ����->";
				} while (amount_of_el < 1);
				Rand_Stud_Seq_Gen(&Stud_Arr, amount_of_el);
			}

			for (int k = 0; k < Stud_Arr.GetLength(); k++) {
				if (atr == 1)
					Stud_Arr.Get(k).set_flag(1);
				else if (atr == 2)
					Stud_Arr.Get(k).set_flag(2);
				else if (atr == 3)
					Stud_Arr.Get(k).set_flag(0);
			}
			
			BTree<Student> btree = builder.build(&Stud_Arr, Stud_Arr.GetLength());

			cout << "������������ B-������\n";
			btree.traverse();

			while (f == 1) {
				ArraySequence<Student> Stud_Arr1;

				int act;
				do {
					cout << "�������� ��������:  \n1 - �������� �������\n2 - ����� ��������\n3 - �����\n�����: ";
					while (!(cin >> act)) {
						cin.clear();
						cout << "ERROR: ������� �����--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (act != 1 && act != 2 && act != 3)
						cout << "������: ������� ���������� ��������(�� 1 �� 5):  ";
				} while (act != 1 && act != 2 && act != 3);

				if (act == 1) {
					int vvod;
					do {
						cout << "�������� ����� ������:\n1 - ������ ����\n2 - �������������� ����\n�����:    ";
						while (!(cin >> vvod)) {
							cin.clear();
							cout << "ERROR: ������� �����--> " << endl;
							while (cin.get() != '\n') continue;
						}
						if (vvod != 1 && vvod != 2)
							cout << "������: ��������� ����->";
					} while (vvod != 1 && vvod != 2);

					if (vvod == 1) {

						int amount_of_el;
						do {
							cout << "������� ���������� ��������� � ������������������: ";
							while (!(cin >> amount_of_el)) {
								cin.clear();
								cout << "ERROR: ������� �����--> " << endl;
								while (cin.get() != '\n') continue;
							}
							if (amount_of_el < 1)
								cout << "������: ��������� ����->";
						} while (amount_of_el < 1);

						cout << "������� ������� � ���� ��������" << endl;
						for (int i = 0; i < amount_of_el; i++) {
							cout << "C������ " << i << ":" << endl;
							cout << "���:  ";
							string name; cin >> name;
							cout << "���� �������� (����� ������):\n";
							int d; int m; int g;
							do {
								cout << "������� ����: ";
								while (!(cin >> d)) {
									cin.clear();
									cout << "ERROR: ������� �����--> " << endl;
									while (cin.get() != '\n') continue;
								}
								if (d > 31 || d < 1)
									cout << "������: ��������� ����->";
							} while (d > 31 || d < 1);
							do {
								cout << "������� �����: ";
								while (!(cin >> m)) {
									cin.clear();
									cout << "ERROR: ������� �����--> " << endl;
									while (cin.get() != '\n') continue;
								}
								if (m > 12 || m < 1)
									cout << "������: ��������� ����->";
							} while (m > 12 || m < 1);
							do {
								cout << "������� ���: ";
								while (!(cin >> g)) {
									cin.clear();
									cout << "ERROR: ������� �����--> " << endl;
									while (cin.get() != '\n') continue;
								}
								if (g > 2018 || g < 1900)
									cout << "������: ��������� ����->";
							} while (g > 2018 || g < 1900);

							Student stud = Student(name, d, m, g);
							Stud_Arr1.Append(stud);
						}
					}

					else if (vvod == 2) {
						int amount_of_el;
						do {
							cout << "������� ���������� ��������� � ������������������: ";
							while (!(cin >> amount_of_el)) {
								cin.clear();
								cout << "ERROR: ������� �����--> " << endl;
								while (cin.get() != '\n') continue;
							}
							if (amount_of_el < 1)
								cout << "������: ��������� ����->";
						} while (amount_of_el < 1);
						Rand_Stud_Seq_Gen(&Stud_Arr1, amount_of_el);
					}

					for (int k = 0; k < Stud_Arr1.GetLength(); k++) {
						if (atr == 1)
							Stud_Arr1.Get(k).set_flag(1);
						else if (atr == 2)
							Stud_Arr1.Get(k).set_flag(2);
						else if (atr == 3)
							Stud_Arr1.Get(k).set_flag(0);
					}

					for (int j = 0; j < Stud_Arr1.GetLength(); j++)
						btree.insert(Stud_Arr1.Get(j));

					cout << "������������ B-������\n";
					btree.traverse();
				}
				else if (act == 2) {
					cout << "\n������� �������� ��� ������ � B-������ " << endl;
					cout << "C������: " << endl;
					cout << "���:  ";
					string name; cin >> name;
					cout << "���� �������� (����� ������):\n";
					int d; int m; int g;
					do {
						cout << "������� ����: ";
						while (!(cin >> d)) {
							cin.clear();
							cout << "ERROR: ������� �����--> " << endl;
							while (cin.get() != '\n') continue;
						}
						if (d > 31 || d < 1)
							cout << "������: ��������� ����->";
					} while (d > 31 || d < 1);
					do {
						cout << "������� �����: ";
						while (!(cin >> m)) {
							cin.clear();
							cout << "ERROR: ������� �����--> " << endl;
							while (cin.get() != '\n') continue;
						}
						if (m > 12 || m < 1)
							cout << "������: ��������� ����->";
					} while (m > 12 || m < 1);
					do {
						cout << "������� ���: ";
						while (!(cin >> g)) {
							cin.clear();
							cout << "ERROR: ������� �����--> " << endl;
							while (cin.get() != '\n') continue;
						}
						if (g > 2018 || g < 1900)
							cout << "������: ��������� ����->";
					} while (g > 2018 || g < 1900);

					Student stud = Student(name, d, m, g);
					if (atr == 1)
						stud.set_flag(1);
					else if (atr == 2)
						stud.set_flag(2);
					else if (atr == 3)
						stud.set_flag(0);

					auto begin = chrono::high_resolution_clock::now();
					try {
						cout << "���������: " << btree.search(stud).index;
					}
					catch (ElementNotFoundException<Student> ex) {
						ex.what();
					}
					auto end = chrono::high_resolution_clock::now();
					auto res = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
					cout << " �����: " << res << " ��" << endl;
				}
				else if (act == 3)
					f = -1;
			}
		}
		else if (section == 4) 
			return -1;

		system("pause");
	}
}
