#include<iostream>
using namespace std;
#include "ArrayBst.h"

arrayBST::arrayBST(){
	for(int i=0;i<MAX_SIZE;i++){
		this->elements[i]=0;
	}	
}
arrayBST::~arrayBST(){}
void arrayBST::add(int data){
	if(this->elements[1]==0){
		elements[1]=data;
	}
	else{
		for(int i=1;i<MAX_SIZE;){
			if(data<this->elements[i]){
				i=2*i;
				cout<<"Left :"<<i<<endl;
			}
			else{
				i=2*i+1;
				cout<<"Right :\t"<<i<<endl;
			}
			if(this->elements[i]==0){
				this->elements[i]=data;
				cout<<"Inserted on "<<i<<endl;
				break;
			}
		}
	}
}
bool arrayBST::search(int data){
	for(int i=1;i<MAX_SIZE;){
		if(this->elements[i]==data){
			cout<<"Required data "<<data<<" is found in index "<<i<<" of the tree\n";
			return true;
		}
		else if (data<this->elements[i]){
				i=2*i;
			}
		else{
				i=2*i+1;
			}
	}
	cout<<"Required number "<<data<<"  is not found in the tree\n";
	return false;
}
void arrayBST::preorder(int x){
	int l=2*x;
	int r=2*x+1;
	
	cout<<(this->elements[x])<<" ";
	if(this->elements[l]!=0)
	{
		preorder( l);
	}
	
	if(this->elements[r]!=0)
	{
		preorder( r);
	}
	
}		
	
int arrayBST::max()
{
	for(int i=1;i<MAX_SIZE;)
	{
		if(this->elements[2*i+1]!=0)
		{
			i=2*i+1;
		}
		else
		{
			return elements[i];
		}
		
	}
	
}
	
void arrayBST::inorder(int x)
{
	
	int l=2*x;
	int r=2*x+1;
	if(this->elements[l]!=0)
	{
		inorder( l);
	}
	cout<<(this->elements[x])<<" ";
	
	if(this->elements[r]!=0)
	{
		inorder( r);
	}
	
		
}
int main(){
	arrayBST a;
	a.add(15);
	a.add(10);
	a.add(11);
	a.add(14);
	a.add(13);
	a.add(4);
	a.add(1);
	a.add(5);
	a.add(16);
	a.add(18);
	a.add(17);
	a.add(20);
	for(int i=0;i<MAX_SIZE;i++){
		cout<<a.elements[i]<<",";
	}
	cout<<endl;
	a.preorder(1);
	cout<<endl;
	a.search(21);
	a.search(29);
	int temp;
	temp=a.max();
	cout<<"max value : "<<temp<<endl;
	a.inorder(1);
	return 0;
};



