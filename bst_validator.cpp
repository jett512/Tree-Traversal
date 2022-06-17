// Run in Repl.it 
// clang++-7 -pthread -std=c++17 -o bst_validator bst_validator.cpp; ./bst_validator < bst_validator1.in
//Run in zeus.cs.txstate.edu:
//g++ -pthread -o bst_validator bst_validator.cpp; ./bst_validator < bst_validator1.in

#include <iostream>
#include <sstream>
#include <vector>

/** QUESTION 4: BST VALIDATOR **/
/*
 EFFECTS: Returns true if the tree is a valid BST, or false otherwise.

 PSEUDOCODE:
 algorithm IsBST
   Input: 10 5 15 2 7 11 25 1
   Output:true
   Your pseudocode goes here.
	
	IsBSTHelper function( Bintree, isleft, index, nodeVal)

		left node index = (2*index) + 1
		right node index = (2*index) + 2

		if left, & BinTree at index > nodeVal
			return false
		else if !left, & BinTree at index < nodeVal
			return false

		else if LNI < Bintree size - 1 & RNI < Bintree size - 1
			if BinTree LNI > index
				return false
			else if BinTree RNI < index
				return false
			else
				return BSTHelper( Bintree, isleft, LNI, Bintree at (0)) 
				& BSTHelper( Bintree, isleft, RNI, Bintree at (2))
		else if LNI < Bintree size - 1
			if BinTree at LNI > BinTree at index
				return false
			else
				return IsBSTHelper Bintree, isleft, LNI, BinTree at (0)
		else 
			return true
		end IsBSTHelper function


	IsBST function (Bintree)
		if Bintree empty
			return true
		else if Bintree size = 1
			return true
		else if Bintree at (0) > Bintree at (1) & Bintree at (0) < Bintree at (2)
			return IsBSTHelper function Bintree, true, 1, Bintree at (0) 
			& IsBSTHelper function Bintree, false, 2, Bintree at (0)
		else
			return false


 COMMENTS:
	There are two functions implimented here, IsBST and IsBSTHelper
	While they have been implimented helper then original, I will explain them in reverse order to clarify meaning.

	IsBST has only the binary tree in the function declaration, but we can establish the base cases here.
	Base case 1: If the tree is empty, no rules of binary search tree can be violated, so true is returned
	Base case 2: If the tree has 1 element, no rules of binary search tree can be violated, so true is returned
	else if left child less than root, & right child greater than root, these ar ethe rules of Binary search tree.
	Then we return the left and right child to the helper function to be further examined with rules for binary search trees.
	else right child less than root or left child greater than root, thereofre not a binary search tree

	IsBSTHelper function has 3 extra variables, bool to check if left located, index to keep track of stack, and the value of root node.
	Define left node index as the given formula for ease of use later. Same is done for right node index
	If left child and greater than root value, then this is not a binary tree
	Else if right child and less than root, then this is not a binary tree
	else if left and right children less than tree size, this could be a tree
		nested if left child greater than value at index, not a binary tree
		nested else if right child less than value at index, not a binary tree
		else both children in left subtree, so recursive call to return both children in left subtree
		the else statment occures when this could possibly be a binary search tree, but needs more examination.
	else left child's index less than tree size, this could be a binary search tree
		nested if left child greater than value at index, not a binary search tree
		else left child less than value at index, then recursive call to return left child to further examine
	else no rules for binary trees broken, therefore this must be a binary search tree.


*/

bool IsBSTHelper(std::vector<int> &binary_tree, bool isleft, int index, int nodeVal){
	int LNI = (2*index) + 1;//formula for left node index
	int RNI = (2*index) + 2;//formula for right node index

	if(isleft == true && binary_tree.at(index) > nodeVal)//left child and greater than root value
	{
		return false;
	}
	else if( isleft == false && binary_tree.at(index) < nodeVal) // right child and less than root value
	{
		return false;
	}

	else if(LNI < binary_tree.size() - 1 && RNI < binary_tree.size() - 1)//left and right children less than tree size
	{
		if( binary_tree.at(LNI) > binary_tree.at(index))//left child greater than value at index
		{
			return false;
		}
		else if (binary_tree.at(RNI) < binary_tree.at(index))//right child less than value at index
		{
			return false;	
		}
		else//both children in left subtree
		{
			//recursive call to return both children in left subtree
			 return IsBSTHelper(binary_tree, isleft, LNI, binary_tree.at(0)) && IsBSTHelper(binary_tree, isleft, RNI, binary_tree.at(0));
		}
	}
	else if( LNI < binary_tree.size() - 1)//left child's index less than tree size
	{
		if(binary_tree.at(LNI) > binary_tree.at(index))//left child greater than value at index
		{
			return false;
		}
		else//left child less than value at index
		{
			//recursive call to return left child 
			return IsBSTHelper(binary_tree, isleft, LNI, binary_tree.at(0));
		}
	}
	else//no rules for binary trees broken
	{
		return true;//is binary tree
	}
}
bool IsBST(std::vector<int> &binary_tree) {
  // Implement this function.
	
	if(binary_tree.empty())//base case 1
	{
		return true;
	}
	else if(binary_tree.size() == 1)//base case 2
	{
		return true;
	}

	//left child less than root, & right child greater than root
	else if(binary_tree.at(0) > binary_tree.at(1) && binary_tree.at(0) < binary_tree.at(2))
	{
		//send left and right children to helper function, with their index
		return IsBSTHelper(binary_tree, true, 1, binary_tree.at(0)) && IsBSTHelper(binary_tree, false, 2, binary_tree.at(0));
	}
	else //right child less than root or left child greater than root
	{
		return false;
	}

}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main() {
  std::vector<int> binary_tree;
  std::string input;
  getline(std::cin, input);
  std::stringstream iss(input);
  int number;
  while (iss >> number) {
    binary_tree.push_back(number);
  }
  if (IsBST(binary_tree)) {
    std::cout << "True";
  } else {
    std::cout << "False";
  }
  return 0;
}
