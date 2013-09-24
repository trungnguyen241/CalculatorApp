#pragma once

class binTree;   // forward declaration


class treeNode
{
friend class binTree;
public:
   explicit treeNode(int);
   treeNode(const treeNode& from);
   ~treeNode();
   treeNode& operator=(const treeNode& rightHandSide);

private:
   int data;
   treeNode* left;
   treeNode* right;
};


class binTree
{
public:
   binTree(void);
   binTree(const binTree& from);
   ~binTree(void);
   binTree& operator=(const binTree& rightHandSide);


   void insert(int);
   void remove(int);

   bool isEmpty();

   void inOrder();
   void preOrder();
   void postOrder();
   unsigned getSize();

private:
   void insert(treeNode **next, int stuff);
   void remove(treeNode **next, int stuff);
   void inOrder(treeNode **next);
   void preOrder(treeNode **next);
   void postOrder(treeNode **next);
   void copyTree(treeNode **next, treeNode* source);
   void cleanTree(treeNode **subTree);



   treeNode* root;
   unsigned size;



};
