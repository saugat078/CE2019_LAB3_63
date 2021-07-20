#include <iostream>
#include "BST.h"
using namespace std;

class Node{
	public:
	int key;
	Node *left;
	Node *right;
};

class node{
    public:
        Node* info;
        node* next;
};

class LinkedBST: public AbstractBST{
	private:
	Node *root = NULL;
	public:
	void preorder();
	void inorder();
	void add(int data);
	bool search(int data);
	bool isEmpty();
	int max();
	void inorder(Node* root);
	void remove_node();
	Node* remove_node(Node *root,int key);
	Node* get_root(){
			return root;
		}
};

class Stack{
    public:
    Stack();
    ~Stack();
    
    void push(Node* a);
    Node* pop();
    bool isEmpty();
    bool isFull();
    int peak();
    
    private:
    node* stack;
    node* top;
};