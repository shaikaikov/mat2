#include <iostream>
#include "Tree.hpp"
using namespace std;


Tree::Tree()
{
	head = NULL;
	TreeSize = 0;
}

Tree::~Tree()
{
	if (head->getleft() != NULL)
		delete head->getleft();
	if (head->getright() != NULL)
		delete head->getright();
	delete head;
}

void Tree::setHead(TNode* t) {
	head = t;
}

TNode* Tree::gethead() {
	return head;
}

void Tree::insert(int i) {

	TNode* temp = new TNode(i);
	

	if (head == NULL) {

		head = temp;
	}

	else {
		TNode* current = head;
		bool exit = false;
		while (!exit) {
			if (i < current->getdata()) {
				if (current->getleft() == NULL) {
					current->setleft(temp);
					temp->setfather(current);
					exit = true;
				}

				else {
					current = current->getleft();
				}
			}
			else {
				if (current->getright() == NULL) {
					current->setright(temp);
					temp->setfather(current);
					exit = true;
				}
				else {
					current = current->getright();
				}
			}
		}

	}

}

bool Tree::contains(int i) {
	TNode* current = head;
	while (current != NULL) {
		if (current->getdata() == i) {
			return true;
		}
		else if (i < current->getdata()) {
			current = current->getleft();
		}
		else {
			current = current->getright();
		}
	}
	return false;
}


TNode* Tree:: search(int i) {
	TNode* current = head;
	while (current != NULL) {
		if (current->getdata() == i) {
			return current;
		}
		else if (i < current->getdata()) {
			current = current->getleft();
		}
		else {
			current = current->getright();
		}
	}
	return NULL;
	
}

int Tree::remove(int i) {
	//if(contains(i)==false)

	TNode* current = head;
	while (current->getdata() != i)
	{
		if (i < current->getdata())
			current = current->getleft();
		else {
			current = current->getright();
		}

	}


	TNode* father = current->getfather();

	//case 1:leaf

	if (current->getleft() == NULL && current->getright() == NULL) {
		if (father == NULL) {
			delete head;
			head = NULL;

		}

		else if (i < father->getdata()) {
			father->setleft(NULL);

		}
		else {
			father->setright(NULL);

		}

	}
		//case 2:current has only child
	else if (current->getleft() == NULL) {
		if (father == NULL) {
			head = current->getright();
			head->setfather(NULL);
		}
		else if (i < father->getdata()) {
			father->setleft(current->getright());
			current->getright()->setfather(father);
		}
		else {
			father->setright(current->getright());
			current->getright()->setfather(father);
		}
	}
	else if (current->getright() == NULL) {
		if (father == NULL) {
			head = current->getleft();
			head->setfather(NULL);
		
		}
		else if (i < father->getdata()) {
			father->setleft(current->getleft());
			current->getleft()->setfather(father);
		}
		else {
			father->setright(current->getleft());
			current->getleft()->setfather(father);
		}
	}

	// case 2: two children
	else
	{
		TNode* replace = current->getleft();
		while (replace->getright() != NULL)
			replace = replace->getright();
		remove(replace->getdata());
		current->setdata(replace->getdata());
	}
	return i;
}



int main()
{
	Tree t;
	t.insert(5);
	t.insert(6);
	t.remove(5);

}
