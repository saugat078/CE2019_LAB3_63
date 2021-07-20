#ifndef BST_h
#define BST_h
class AbstractBST{
		public:
			virtual bool isEmpty()=0;
			virtual void add(int data)=0;
			virtual bool search(int data)=0;
			virtual int max()=0;
};
#endif