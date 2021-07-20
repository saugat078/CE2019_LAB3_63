#include "BST.h"
#define MAX_SIZE 50

class arrayBST : public AbstractBST
{
    public:
        int item[MAX_SIZE];
        arrayBST();
        ~arrayBST();
        bool isEmpty();
        void preorder(int x);
        void add(int data);
        bool search(int data);
        int max();
        
 		void inorder(int x);
};
