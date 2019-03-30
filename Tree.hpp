
/**
*
* Tree hpp-here the structure of nodes of the TNode
*beside this here the class Tree signitures
*
*@authers-shai and sela
*
*/




#pragma once
namespace ariel
{

	class TNode {
		int data;
		TNode* left;
		TNode* father;                //fields
		TNode*right;
	public:
		TNode(int num) {
			data = num;
			left = NULL;             //constructor
			father = NULL;
			right = NULL;

		}
		~TNode()                    //destructor
		{
		}
		void setdata(int num1) {
			data = num1;
		}
		int getdata() {
			return data;
		}
		void setleft(TNode* t) {
			left = t;
		}
		TNode* getleft() {                  //setters and getters
			return left;
		}
		void setright(TNode* t) {
			right = t;
		}
		TNode* getright() {
			return right;
		}

		void setfather(TNode* t) {
			father = t;
		}

		TNode* getfather() {
			return father;
		}
	};


	//functions and signitures
	class Tree {

	private:
		TNode* head;
		int TreeSize;
	public:
		Tree();
		~Tree();
		void setHead(TNode* t);
		TNode* gethead();
		void insert(int i);
		int remove(int i);
		int size();
		bool contains(int i);
		int root();
		int parent(int i);
		int left(int i);
		int right(int i);
		void print();

		//add our function:
		TNode* search(int i);
	};
}
