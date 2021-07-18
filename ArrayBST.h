#include "BST.h"
#define MAX_SIZE 40

class arrayBST : public BST
{

    public:
        int elements[MAX_SIZE];
        arrayBST();
        ~arrayBST();
        void preorder(int x);
        void add(int data);
        bool search(int data);
        int max();
 		void inorder(int x);
};
