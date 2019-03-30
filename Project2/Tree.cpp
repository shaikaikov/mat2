


/**
*
* here we built the Tree we use the help of file that was in data structure module of ariel site
*
*
*
*@authers-shai and sela
*
*/


#include <iostream>
#include<string>
#include "Tree.hpp"
using namespace std;
using namespace ariel;

Tree::Tree()
{
	head = NULL;
	TreeSize = 0;
}


///delete the Tree by destructor
void recursive_Delete_TRee(TNode* head) {

	TNode* current = head;
	if (current != NULL)
	{
		if (current->getleft() != NULL)
			recursive_Delete_TRee(current->getleft());
		if (current->getright() != NULL)
			recursive_Delete_TRee(current->getright());
		delete current;
	}
}

///destructor
Tree::~Tree()
{
	recursive_Delete_TRee(head);
}

void Tree::setHead(TNode* t) {
	head = t;
}

TNode* Tree::gethead() {
	return head;
}


/// insert-if the number little than the node that he meet go to the left untill null.
///else if he bigger the node go to right untill null.
void Tree::insert(int i) {

	if (contains(i))                                                    ///contains cheak if the data is alredidy exist if exist throw exception.
	{
		throw string(to_string(i) + " is allready in the tree!");      
		return;
	}
	TreeSize++;
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
///cheak of the data is alredy exist if yes return true else continue to search untill find or in the end return false
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

///function we add that like contain exactly just return address of TNode
TNode* Tree::search(int i) {
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


///remove the bst tree.
int Tree::remove(int i) {

	if (!contains(i))
	{
		throw string(to_string(i) + " is not in the tree!");
		return 2147483647;
	}
	TreeSize--;
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

	// case 3: two children
	else
	{
		TNode* replace = current->getleft();
		while (replace->getright() != NULL)
			replace = replace->getright();
		int number = replace->getdata();
		remove(replace->getdata());
		current->setdata(number);
		return i;
	}
	delete current;
	return i;
}


///return the size

int Tree::size() {
	return TreeSize;
}
///return the data of the head.if null so is exception.
int Tree::root() {
	if (head == NULL)
	{
		throw string("root is null!");
	}
	return head->getdata();
}

///use the function of search if the node null or his father null -exception.ifthe father exsit return the data

int Tree::parent(int i) {
	TNode* temp = search(i);
	if (temp == NULL)
		throw string(to_string(i) + " is not in the tree");
	if (temp->getfather() == NULL)
		throw string(to_string(i) + " does not have a parent");
	return temp->getfather()->getdata();
}
///like the parent just in left.
int Tree::left(int i) {
	TNode* temp = search(i);
	if (temp == NULL)
		throw string(to_string(i) + " is not in the tree");
	if (temp->getleft() == NULL)
		throw string(to_string(i) + " does not have a left child");
	return temp->getleft()->getdata();
}
///like the parent just in right
int Tree::right(int i) {
	TNode* temp = search(i);
	if (temp == NULL)
		throw string(to_string(i) + " is not in the tree");
	if (temp->getright() == NULL)
		throw string(to_string(i) + " does not have a right child");
	return temp->getright()->getdata();
}


///print the Tree-inorder order.
void functionvisit(TNode* node) {

	if (node->getleft() != NULL) {
		functionvisit(node->getleft());
	}
	cout << " ";
	cout << node->getdata();

	if (node->getright() != NULL) {
		functionvisit(node->getright());
	}

}

///go to the print function
void Tree::print() {


	functionvisit(head);

}
