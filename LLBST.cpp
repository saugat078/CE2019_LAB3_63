#include "LLBST.h"
using namespace std;

bool LinkedBST::isEmpty(){
	if(root==NULL){
		return true;
	}
	else{
		return false;
	}
}

bool LinkedBST::search(int data){
	Node *searchNode;
	searchNode = root;
	while(searchNode!=NULL){
		if(searchNode->key == data){
			return true;
		}
		else if (data<searchNode->key){
			searchNode= searchNode->left;
		}
		else if (data>searchNode->key){
			searchNode= searchNode->right;
		}
	}
	return false;
}

Stack::Stack(){
	stack=NULL;
	top=NULL;
}

Stack::~Stack(){
	
}

bool Stack::isEmpty(){
	if(stack==NULL){
		return true;	
	}
	else{
		return false;
	}
}

void Stack::push(Node *a){
	node* newNode= new node();
	newNode->info=a;
	if(isEmpty()){
		newNode->next=newNode;
		stack=newNode;
	}
	else{
		newNode->next=stack->next;
		stack->next=newNode;
	}
}

Node* Stack::pop(){
	if(isEmpty()){
		std::cout<<"Stack Underflow"<<std::endl;
	}
	else{
		top=stack->next;
		Node* data=top->info;
		stack->next=top->next;
		if(top==stack){
			stack=NULL;
		}
		return data;
	}
}

void LinkedBST::preorder(){
    Stack stack;
	stack.push(root);
	Node* a;
	while (!stack.isEmpty()) {
		a=stack.pop();
		cout << a->key << " ";
		if (a->right != NULL)	stack.push(a->right);
		if (a->left != NULL)	stack.push(a->left);
	}

}

void LinkedBST::inorder(Node* root) 
{ 
    if (root == NULL) 
        return; 
	
	inorder(root->left);  
    std::cout << root->key << " "; 
  	inorder(root->right); 
}
void LinkedBST::inorder(){
	inorder(root);
}

void LinkedBST::remove_node(){
	remove_node(root,6);
}

Node* LinkedBST::remove_node(Node* root, int key){
	if(root==NULL){
		return root;
	}
	if(key<root->key){
		return remove_node(root->left,key);
	}
	else if(key>root->key){
		return remove_node(root->right,key);
	}
	else{
		if(root->left==NULL){
			Node* temp=root->right;
			delete(root);
			return temp;
		}
		else if(root->right==NULL){
			Node *temp=root->left;
			delete(root);
			return temp;
		}
		else{
			Node* current = root->right; 
    		while (current && current->left != NULL) {
    			current = current->left;
			}
			Node* temp=current;
			root->key=temp->key;
			root->right=remove_node(root->right,temp->key);
		}
	}
	return root;
}


void LinkedBST::add(int data){
	Node* newNode = new Node();
	newNode->key = data;
	
	if(isEmpty()){
	root = newNode;
	root->key = data;
	}
	else{
	//Node 1 is travelling node whereas Node 2 is predecessor of Node 1
		Node* Node1 = root;
		Node* Node2 = NULL;
		bool left;
		
		while (Node1 != NULL) {
			Node2 = Node1;
			if (data < Node1->key) {
				Node1 = Node1->left;
				left = true;
			}
			else if (data > Node1->key) {
				Node1 = Node1->right;
				left = false;
			}
		}
		if (left) {
			Node2->left = newNode;
		}
		else {
			Node2->right = newNode;
		}
	
	}
}

int LinkedBST::max(){
	if (isEmpty()){
	cout<<"The linked list is empty."<<endl;
	return 0;
	}
	else{
	Node* Node1= root;
	Node* Node2 = NULL;
	while(Node1!= NULL){
	Node2 = Node1;
	
	Node1 = Node1->right;  
	}
	return Node2->key;
	
	
	}

}

int main(){
	LinkedBST l;
	l.add(2);
	l.add(1);
	l.add(5);
	l.add(6);
	l.add(4);
	l.add(7);
	l.add(8);
	cout<<"Preorder Traversal"<<endl;
	l.preorder();
	cout<<"\n";
	cout<<"The max value is : " <<l.max() <<endl;
	cout<<"Inorder Traversal"<<endl;
	l.inorder();
	cout<<"\n";
	cout<<"removed node 5"<<std::endl;
	Node* p=l.remove_node(l.get_root(),5);
	cout<<"Inorder Traversal after deletion"<<endl;
	l.inorder();
	cout<<"\n";
	
    if(l.search(7)){
        cout<<"exists"<<endl;
    }
    else{
        cout<<"doesnot exists"<<endl;
    }
}