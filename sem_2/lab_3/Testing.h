#ifndef __TESTING__H__
#define __TESTING__H__
#include "Template.h"
#include <iostream>
#include <math.h>

Tree<string> *test_tree() {
	Tree <string> *mytree = new Tree<string>;
	mytree->insert("aa");
	mytree->insert("bb");
	mytree->insert("ccc");
	mytree->insert("ddd");
	mytree->insert("fff");
	mytree->insert("eee");
	return mytree;
}

void map_test() {
	Tree<string> *mytree = new Tree<string>;
	mytree = test_tree();
	mytree->map("KZ");
	Tree<string> *after = new Tree<string>;
	after->insert("KZ");
	after->insert("KZ");
	after->insert("KZ");
	after->insert("KZ");
	bool *check = new bool;
	*check = 1;
	mytree->CompareTrees(mytree->GetRoot(), after->GetRoot(), check);
	if (*check) cout << "���� map: �����" << endl;
	else cout << "���� map: �� �����" << endl;
	delete mytree;
}

void where_test() {
	Tree<string> *mytree = new Tree<string>;
	mytree = test_tree();
	Tree<string> *after = new Tree<string>;
	mytree->where(after);
	Tree<string> *truetree = new Tree<string>;
	truetree->insert("aa");
	truetree->insert("bb");
	bool *check = new bool;
	*check = 1;
	mytree->CompareTrees(after->GetRoot(), truetree->GetRoot(), check);
	if (*check) cout << "���� where: �����" << endl;
	else cout << "���� where: �� �����" << endl;
	delete mytree;
	delete after;
	delete truetree;
}

void merge_test() {
	Tree<string> *mytree = new Tree<string>;
	mytree = test_tree();
	Tree<string> *mytree2 = new Tree<string>;
	mytree2 = test_tree();
	mytree->MergeTrees(mytree2);
	if (mytree2->GetKids() == 11) cout << "�������: �����" << endl;
	else cout << "�������: �� �����" << endl;
	delete mytree;
	delete mytree2;
}

void subtree_test() {
	Tree<string> *mytree = new Tree<string>;
	mytree = test_tree();
	Tree<string> *smalltree = new Tree<string>;
	mytree->SubtreeExtraction("bb", smalltree);
	if (smalltree->GetKids() == 2) cout << "���������� ���������: �����" << endl;
	else cout << "���������� ���������: �� �����" << endl;
	delete mytree;
}

void el_contain_test() {
	Tree<string> *mytree = new Tree<string>;
	mytree = test_tree();
	if (mytree->IfElementContain("aa")) cout << "�������� �������� �� ���������: �����" << endl;
	else cout << "�������� �������� �� ���������: �� �����" << endl;
	delete mytree;
}

void if_tree_contain_test() {
	Tree<string> *mytree = new Tree<string>;
	mytree = test_tree();
	Tree<string> *smalltree = new Tree<string>;
	smalltree->insert("aa");
	smalltree->insert("bb");
	if (mytree->IfTreeContain(smalltree)) cout << "�������� ��������� �� ���������: �����" << endl;
	else cout << "�������� ��������� �� ���������: �� �����" << endl;
	delete mytree;
	delete smalltree;
}

void Testing() {
	map_test();
	where_test();
	merge_test();
	subtree_test();
	el_contain_test();
	if_tree_contain_test();
}

#endif /* __TESTING__H__ */

