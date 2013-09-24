#include <iostream>


#include ".\bintree.h"
//#include ".\templateBinTree.h"

using std::cout;
using std::endl;

void main(void)
{


   binTree testMyTree;
   
   //BinTree<double> wow;
   //BinTree<double> now;

   testMyTree.insert(25);
   testMyTree.insert(64);
   testMyTree.insert(13);
   testMyTree.insert(26);
   testMyTree.insert(17);
   testMyTree.insert(6);
   testMyTree.insert(14);
   testMyTree.insert(25);

   binTree x = testMyTree;
   testMyTree.inOrder();
   cout << endl;
   x.inOrder();
   cout << endl;
   testMyTree.preOrder();
   cout << endl;
   testMyTree.postOrder();

   cout << endl;
   cout << endl;
   cout << endl;

   //wow.insert(25.1);
   //wow.insert(64.1);
   //wow.insert(13.1);
   //wow.insert(26.1);
   //wow.insert(17.1);
   //wow.insert(6.1);
   //wow.insert(14.1);
   //wow.insert(25.1);

   //BinTree<double> ow(wow);
   //wow.inOrder();
   //cout << endl;
   //
  
   //cout << endl;
   //ow.inOrder();
   //cout << endl;
  
  /* now = ow;
   cout << endl;
   cout << endl;
   cout << endl;
   now.inOrder();
   cout << endl;*/
  

}