#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "ArraySequence.h"
#include "ListSequence.h"
#include "Sequence.h"
#include "Help_Func.h"
#include "Sorters.h"

template <typename T>
class UserInterface {
private:
	unsigned int mode, seq, flag1, flag2, flag3;
public:
	UserInterface() {};
	void Interface();
	void GoInterface();
};

template <typename T>
void UserInterface<T>::Interface() {
	int mode_, seq_, flag1_, flag2_, flag3_, flag;
	do {
		do {
			cout << "Выберите режим работы: АВТОМАТИЧЕСКИЙ (0) или РУЧНОЙ (1) --> " << endl;
			while (!(cin >> mode_)) {
				cin.clear();
				cout << "ERROR: введите число--> " << endl;
				while (cin.get() != '\n') continue;
			}
			if (mode_ != 0 && mode_ != 1)
				cout << "ERROR: повторите ввод-->";
		} while (mode_ != 0 && mode_ != 1);

		do {
			cout << "Выберите тип последовательности: МАССИВ (0) или СПИСОК (1) --> " << endl;
			while (!(cin >> seq_)) {
				cin.clear();
				cout << "ERROR: введите число--> " << endl;
				while (cin.get() != '\n') continue;
			}
			if (seq_ != 0 && seq_ != 1)
				cout << "ERROR: повторите ввод-->";
		} while (seq_ != 0 && seq_ != 1);

		do {
			cout << "Будем проверять корректность сортировок? (0 - N, 1 - Y)" << endl;
			while (!(cin >> flag1_)) {
				cin.clear();
				cout << "ERROR: введите число--> " << endl;
				while (cin.get() != '\n') continue;
			}
			if (flag1_ != 0 && flag1_ != 1)
				cout << "ERROR: повторите ввод->";
		} while (flag1_ != 0 && flag1_ != 1);

		do {
			cout << "Будем ли сравнивать сортировки? (1 - Y, 0 - N)" << endl;
			while (!(cin >> flag2_)) {
				cin.clear();
				cout << "ERROR: введите число--> " << endl;
				while (cin.get() != '\n') continue;
			}
			if (flag2_ != 0 && flag2_ != 1)
				cout << "ОШИБКА: повторите ввод->";
		} while (flag2_ != 0 && flag2_ != 1);

		do {
			cout << "Булем ли применять сортировки к уже остортированному массиву и отсортированному в обратную сторону массиву? (1 - Y, 0 - N)" << endl;
			while (!(cin >> flag3_)) {
				cin.clear();
				cout << "ERROR: введите число--> " << endl;
				while (cin.get() != '\n') continue;
			}
			if (flag3_ != 0 && flag3_ != 1)
				cout << "ОШИБКА: повторите ввод->";
		} while (flag3_ != 0 && flag3_ != 1);

		this->mode = mode_;
		this->seq = seq_;
		this->flag1 = flag1_;
		this->flag2 = flag2_;
		this->flag3 = flag3_;

		GoInterface();

		do {
			cout << "Завершить работу программы? (1 - ДА, 0 - НЕТ) --> ";
			while (!(cin >> flag)) {
				cin.clear();
				cout << "ERROR: введите число--> " << endl;
				while (cin.get() != '\n') continue;
			}
			if (flag != 0 && flag != 1)
				cout << "ERROR: повторите ввод->";
		} while (flag != 0 && flag != 1);
	} while (flag != 1 && flag == 0);
}

template <typename T>
void UserInterface<T>::GoInterface() {
	Sorter<T> sort;
	int N, flag;
	if (this->mode == 0) {
		cout << "АВТОМАТИЧЕСКИЙ РЕЖИМ" << endl << endl;
		if (this->seq == 0) {
			cout << "ПОСЛЕДОВАТЕЛЬНОСТЬ --> МАССИВ" << endl << endl;
			ArraySequence<T> arr_2;
			if (this->flag1 == 1) {
				cout << "ПРОВЕРКА СОРТИРОВОК" << endl;
				ArraySequence<T> arr_1;
				do {
					cout << "Введите количество элементов в массиве: " << endl;
					while (!(cin >> N)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (N < 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (N < 1);
				Rand_Seq_Gen(&arr_1, N);

				ArraySequence<T> arr_1_ = arr_1;

				sort.InsectionSort(&arr_1);
				cout << "Сортировка вставками: ";
				if (Test_After_Sort(&arr_1))
					cout << "TRUE" << endl;
				else
					cout << "FALSE" << endl;
				sort.QuickSort(&arr_1_);
				cout << "Быстрая сортировка: ";
				if (Test_After_Sort(&arr_1_))
					cout << "TRUE" << endl;
				else
					cout << "FALSE" << endl;
			}

			if (this->flag2 == 1) {
				cout << "СРАВНЕНИЕ СОРТИРОВОК ПО ВРЕМЕНИ" << endl;
				do {
					cout << "Введите количество элементов в массиве: " << endl;
					while (!(cin >> N)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (N < 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (N < 1);
				Rand_Seq_Gen(&arr_2, N);
				do {
					cout << "Вывести ли массив на экран? (0 - N, 1 - Y)" << endl;
					while (!(cin >> flag)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (flag != 0 && flag != 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (flag != 0 && flag != 1);
				if (flag == 1)
					arr_2.printAll();

				ArraySequence<T> arr_2_ = arr_2;

				Sorts_Compare(&arr_2, &arr_2_, sort);
				do {
					cout << "Вывести ли массив на экран? (0 - N, 1 - Y)" << endl;
					while (!(cin >> flag)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (flag != 0 && flag != 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (flag != 0 && flag != 1);
				if (flag == 1)
					arr_2.printAll();

				if (this->flag3 == 1) {
					cout << "СРАВНЕНИЕ СОРТИРОВОК В случае отсортированной и неотсортированной последовательности" << endl;
					cout << "Случай ОТСОРТИРОВАННОЙ последовательности: " << endl;
					Sorts_Compare(&arr_2, &arr_2_, sort);
					Invert_Seq(&arr_2);
					ArraySequence<T> arr_3 = arr_2;
					cout << "Случай ОТСОРТИРОВАННОЙ по убыванию последовательности: " << endl;
					Sorts_Compare(&arr_2, &arr_3, sort);
				}
			}
		}
		if (this->seq == 1) {
			ListSequence<T> list_2;
			cout << "ПОСЛЕДОВАТЕЛЬНОСТЬ --> СПИСОК" << endl << endl;
			if (this->flag1 == 1) {
				cout << "ПРОВЕРКА СОРТИРОВОК" << endl;
				ListSequence<T> list_1;
				do {
					cout << "Введите количество элементов в массиве: " << endl;
					while (!(cin >> N)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (N < 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (N < 1);
				Rand_Seq_Gen(&list_1, N);

				ListSequence<T> list_1_ = list_1;

				sort.InsectionSort(&list_1);
				cout << "Сортировка вставками: ";
				if (Test_After_Sort(&list_1))
					cout << "TRUE" << endl;
				else
					cout << "FALSE" << endl;
				sort.QuickSort(&list_1_);
				cout << "Быстрая сортировка: ";
				if (Test_After_Sort(&list_1_))
					cout << "TRUE" << endl;
				else
					cout << "FALSE" << endl;
			}

			if (this->flag2 == 1) {
				cout << "СРАВНЕНИЕ СОРТИРОВОК ПО ВРЕМЕНИ" << endl;
				do {
					cout << "Введите количество элементов в массиве: " << endl;
					while (!(cin >> N)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (N < 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (N < 1);
				Rand_Seq_Gen(&list_2, N);
				ListSequence<T> list_2_ = list_2;
				do {
					cout << "Вывести ли массив на экран? (0 - N, 1 - Y)" << endl;
					while (!(cin >> flag)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (flag != 0 && flag != 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (flag != 0 && flag != 1);
				if (flag == 1)
					list_2.printAll();
				Sorts_Compare(&list_2, &list_2_, sort);
				do {
					cout << "Вывести ли массив на экран? (0 - N, 1 - Y)" << endl;
					while (!(cin >> flag)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (flag != 0 && flag != 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (flag != 0 && flag != 1);
				if (flag == 1)
					list_2.printAll();

				if (this->flag3 == 1) {
					cout << "СРАВНЕНИЕ СОРТИРОВОК В случае отсортированной и неотсортированной последовательности" << endl;
					cout << "Случай ОТСОРТИРОВАННОЙ последовательности: " << endl;
					Sorts_Compare(&list_2, &list_2_, sort);
					Invert_Seq(&list_2);
					ListSequence<T> list_3 = list_2;
					cout << "Случай ОТСОРТИРОВАННОЙ по убыванию последовательности: " << endl;
					Sorts_Compare(&list_2, &list_3, sort);
				}
			}
		}
	}
	if (this->mode == 1) {
		cout << "РУЧНОЙ РЕЖИМ" << endl << endl;
		if (this->seq == 0) {
			cout << "ПОСЛЕДОВАТЕЛЬНОСТЬ --> МАССИВ" << endl << endl;
			ArraySequence<T> arr2;

			if (this->flag1 == 1) {
				cout << "ПРОВЕРКА СОРТИРОВОК" << endl;
				ArraySequence<T> arr1;
				int N;
				do {
					cout << "Введите количество элементов в массиве: " << endl;
					while (!(cin >> N)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (N < 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (N < 1);
				for (int i = 0; i < N; i++) {
					T k;
					cout << "Введите " << i << "-ый элемент: ";
					while (!(cin >> k)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					arr1.Append(k);
				}
				sort.InsectionSort(&arr1);
				cout << "Сортировка вставками: ";
				if (Test_After_Sort(&arr1))
					cout << "TRUE" << endl;
				else
					cout << "FALSE" << endl;
				ArraySequence<T> arr1_ = arr1;
				sort.QuickSort(&arr1_);
				cout << "Быстрая сортировка: ";
				if (Test_After_Sort(&arr1_))
					cout << "TRUE" << endl;
				else
					cout << "FALSE" << endl;
			}

			if (this->flag2 == 1) {
				cout << "СРАВНЕНИЕ СОРТИРОВОК ПО ВРЕМЕНИ" << endl;
				do {
					cout << "Введите количество элементов в массиве: " << endl;
					while (!(cin >> N)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (N < 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (N < 1);
				for (int i = 0; i < N; i++) {
					T k;
					cout << "Введите " << i << "-ый элемент: ";
					while (!(cin >> k)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					arr2.Append(k);
				}
				do {
					cout << "Вывести ли массив на экран? (0 - N, 1 - Y)" << endl;
					while (!(cin >> flag)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (flag != 0 && flag != 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (flag != 0 && flag != 1);
				if (flag == 1)
					arr2.printAll();
				ArraySequence<T> arr2_ = arr2;
				Sorts_Compare(&arr2, &arr2_, sort);
				do {
					cout << "Вывести ли массив на экран? (0 - N, 1 - Y)" << endl;
					while (!(cin >> flag)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (flag != 0 && flag != 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (flag != 0 && flag != 1);
				if (flag == 1)
					arr2.printAll();

				if (this->flag3 == 1) {
					cout << "СРАВНЕНИЕ СОРТИРОВОК В случае отсортированной и неотсортированной последовательности" << endl;
					cout << "Случай ОТСОРТИРОВАННОЙ последовательности: " << endl;
					Sorts_Compare(&arr2, &arr2_, sort);
					Invert_Seq(&arr2);
					ArraySequence<T> arr3 = arr2;
					cout << "Случай ОТСОРТИРОВАННОЙ по убыванию последовательности: " << endl;
					Sorts_Compare(&arr2, &arr3, sort);
				}
			}
		}
		if (this->seq == 1) {
			ListSequence<T> list2;
			cout << "ПОСЛЕДОВАТЕЛЬНОСТЬ --> СПИСОК" << endl << endl;
			if (this->flag1 == 1) {
				cout << "ПРОВЕРКА СОРТИРОВОК" << endl;
				ListSequence<T> list1;
				do {
					cout << "Введите количество элементов в массиве: " << endl;
					while (!(cin >> N)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (N < 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (N < 1);
				for (int i = 0; i < N; i++) {
					T k;
					cout << "Введите " << i << "-ый элемент: ";
					while (!(cin >> k)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					list1.Append(k);
				}
				sort.InsectionSort(&list1);
				cout << "Сортировка вставками: ";
				if (Test_After_Sort(&list1))
					cout << "TRUE" << endl;
				else
					cout << "FALSE" << endl;
				ListSequence<T> list1_ = list1;
				sort.QuickSort(&list1_);
				cout << "Быстрая сортировка: ";
				if (Test_After_Sort(&list1_))
					cout << "TRUE" << endl;
				else
					cout << "FALSE" << endl;
			}

			if (this->flag2 == 1) {
				cout << "СРАВНЕНИЕ СОРТИРОВОК ПО ВРЕМЕНИ" << endl;
				do {
					cout << "Введите количество элементов в массиве: " << endl;
					while (!(cin >> N)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (N < 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (N < 1);
				for (int i = 0; i < N; i++) {
					T k;
					cout << "Введите " << i << "-ый элемент: ";
					while (!(cin >> k)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					list2.Append(k);
				}
				do {
					cout << "Вывести ли массив на экран? (0 - N, 1 - Y)" << endl;
					while (!(cin >> flag)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (flag != 0 && flag != 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (flag != 0 && flag != 1);
				if (flag == 1)
					list2.printAll();
				ListSequence<T> list2_ = list2;
				Sorts_Compare(&list2, &list2_, sort);
				do {
					cout << "Вывести ли массив на экран? (0 - N, 1 - Y)" << endl;
					while (!(cin >> flag)) {
						cin.clear();
						cout << "ERROR: введите число--> " << endl;
						while (cin.get() != '\n') continue;
					}
					if (flag != 0 && flag != 1)
						cout << "ОШИБКА: повторите ввод->";
				} while (flag != 0 && flag != 1);
				if (flag == 1)
					list2.printAll();

				if (this->flag3 == 1) {
					cout << "СРАВНЕНИЕ СОРТИРОВОК В случае отсортированной и неотсортированной последовательности" << endl;
					cout << "Случай ОТСОРТИРОВАННОЙ последовательности: " << endl;
					Sorts_Compare(&list2, &list2_, sort);
					Invert_Seq(&list2);
					ListSequence<T> list3 = list2;
					cout << "Случай ОТСОРТИРОВАННОЙ по убыванию последовательности: " << endl;
					Sorts_Compare(&list2, &list3, sort);
				}
			}
		}
	}
}

#endif /* USER_INTERFACE_H */