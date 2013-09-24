#include ".\bintree.h"
#include <iostream>
#include <cstdlib>

using std::cout;

// treeNode definitions
treeNode::treeNode(int stuff): data(stuff), left(NULL), right(NULL)
{
}

treeNode::treeNode(const treeNode& from): data(from.data), left(from.left),right(from.right)
{

}

treeNode::~treeNode()
{
    // should we be freeing up children here?
}




// binTree definitions
binTree::binTree(void):root(NULL), size(0)
{
}

binTree::binTree( const binTree& from )
{
   copyTree( &(this->root) , from.root );
}
binTree::~binTree(void)
{

}

void binTree::cleanTree(treeNode **subTree)
{
    if ( NULL != *subTree )
    {
        cleanTree( &((*subTree)->right) );
        cleanTree( &((*subTree)->left)  );
        delete (*subTree );
    }
}

////////////////////////////////////////////////
// using a private helper method makes a cleaner
// interface to the insert.
////////////////////////////////////////////////
void binTree::insert(int data)
{
   insert(&root, data);
}

void binTree::insert(treeNode **hook, int stuff)
{
   if ( NULL == *hook) 
   {
      *hook = new treeNode(stuff);
   }
   else if ( stuff < (*hook)->data )
   {
      insert(&((*hook)->left), stuff);
   }
   else if ( stuff > (*hook)->data )
   {
      insert(&((*hook)->right), stuff);
   }
   else
   {
      cout << "dupppppp!!!!!!!\n";
   }
 
}


void binTree::copyTree( treeNode **hook, treeNode* source )
{
    if ( NULL != source ) 
   {
      *hook = new treeNode( source->data );
      copyTree( &((*hook)->left) , source->left );
      copyTree( &((*hook)->right) , source->right );
   }
}

////////////////////////////////////////////
// use the same help trick for all of the 
// traversal functions
////////////////////////////////////////////

// inorder traversal using output for the visit step.
void binTree::inOrder()
{
   inOrder( &root);
}


void binTree::inOrder(treeNode ** hook)
{
   if( NULL != *hook )
   {
      inOrder(& ((*hook)->left));   // LEFT
      cout << (*hook)->data << " "; // VISIT 
      inOrder(& ((*hook)->right));  // RIGHT
   }
}

// preorder traversal using output for the visit step.
void binTree::preOrder()
{
   preOrder( &root);
}


void binTree::preOrder(treeNode ** hook)
{
   if( NULL != *hook )
   {
      cout << (*hook)->data << " "; // VISIT 
      preOrder(& ((*hook)->left));   // LEFT
      preOrder(& ((*hook)->right));  // RIGHT
   }
}


// postorder traversal using output for the visit step.
void binTree::postOrder()
{
   postOrder( &root);
}


void binTree::postOrder(treeNode ** hook)
{
   if( NULL != *hook )
   {
      postOrder(& ((*hook)->left));   // LEFT
      postOrder(& ((*hook)->right));  // RIGHT
      cout << (*hook)->data << " "; // VISIT 
   }
}

































