#include<iostream>
using namespace std;
#include "ArrayBst.h"

arrayBST::arrayBST(){
	for(int i=0;i<MAX_SIZE;i++){
		this->item[i]=0;
	}	
}
bool arrayBST:: isEmpty(){
	for(int i=0;i<MAX_SIZE;i++){ 
    if(item[i] == 0){ 
        return true; 
    } 
    else 
        return false; 
} 

}
arrayBST::~arrayBST(){}

void arrayBST::add(int data){
	if(this->item[1]==0){
		item[1]=data;
	}
	else{
		for(int i=1;i<MAX_SIZE;){
			if(data<this->item[i]){
				i=2*i;
				cout<<"Left :"<<i<<endl;
			}
			else{
				i=2*i+1;
				cout<<"Right :\t"<<i<<endl;
			}
			if(this->item[i]==0){
				this->item[i]=data;
				cout<<"Inserted on "<<i<<endl;
				break;
			}
		}
	}
}
bool arrayBST::search(int data){
	for(int i=1;i<MAX_SIZE;){
		if(this->item[i]==data){
			cout<<"Required data "<<data<<" exists at index "<<i<<" of the tree\n";
			return true;
		}
		else if (data<this->item[i]){
				i=2*i;
			}
		else{
				i=2*i+1;
			}
	}
	cout<<"Required data "<<data<<" doesnot exists in the tree\n";
	return false;
}

void arrayBST::preorder(int x){
	int left=2*x;
	int right=2*x+1;
	
	cout<<(this->item[x])<<" ";
	if(this->item[left]!=0)
	{
		preorder( left);
	}
	
	if(this->item[right]!=0)
	{
		preorder( right);
	}
	
}		
	
int arrayBST::max()
{
	for(int i=1;i<MAX_SIZE;)
	{
		if(this->item[2*i+1]!=0)
		{
			i=2*i+1;
		}
		else
		{
			return item[i];
		}
		
	}
	
}
	
void arrayBST::inorder(int x)
{
	
	int left=2*x;
	int right=2*x+1;
	if(this->item[left]!=0)
	{
		inorder( left);
	}
	cout<<(this->item[x])<<" ";
	
	if(this->item[right]!=0)
	{
		inorder( right);
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
		cout<<a.item[i]<<",";
	}
	cout<<endl;
	a.preorder(1);
	cout<<endl;
	a.search(21);
	a.search(5);
	int temp;
	temp=a.max();
	cout<<"max value : "<<temp<<endl;
	a.inorder(1);
	return 0;
};



