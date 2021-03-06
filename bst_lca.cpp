// Run in Repl.it
// clang++-7 -pthread -std=c++17 -o bst_lca bst_lca.cpp; ./bst_lca < bst_lca1.in
//Run in zeus.cs.txstate.edu:
//g++ -pthread -o bst_lca bst_lca.cpp; ./bst_lca < bst_lca1.in
#include <iostream>
#include <sstream>
#include <vector>

/** QUESTION 6: LOWEST COMMON ANCESTOR **/
/*
 EFFECTS: Returns the value of the lowest common ancestor of nodes l and m.
 
 PSEUDOCODE:
 algorithm GetLCA
   Input: 7 2
   Output: 5
    
	if m < l and l > root	
		return root
	else if m = root or l = root
		return root
	else if m < root and l < root
		nested if m < small child and l < small child
			return bst, l, m
		nested else
			return small child of root (index 1 in bst)
	else if m > root and l > root
		nested if m > large child and l > large child
			return bst, l, m
		nested else
			return large child of root (index 2 in bst)
	
 COMMENTS:
	If m is less than l, and l is greater than root, we assume that these are the first children of root node.
	Therefore, the root is the lca, when m and l are the direct children.
	
	Else if m is equal to the root, or l is equal to the root, one must be the root node.
	
	Else if checks if m and l are both less than the smaller of the two children from root node.
	Nested if check is both m and l are less than the smaller child.
	When this is the case we need to loop back through function again to check
	else the left child from the root is the lca, so return this to the function.
	
	Else if checks if m and l are both greater than the larger of the two children from root node.
	Nested if check is both m and l are greater than the larger child.
	When this is the case we need to loop back through function again to check
	else the right child from the root is the lca, so return this to the function.
		
	
*/
int GetLCA(std::vector<int> &bst, int l, int m) {
  
	if(m < l && l > bst.at(0))//if m less than l, and l greater than root
	{
		return bst.at(0);//lca is root
	}
	else if ( m == bst.at(0) || l == bst.at(0))//if m or l is root
	{
		return bst.at(0);//root is lca
	}
	else if( m < bst.at(0) && l < bst.at(0))//if m and l on left side of tree
	{
		if( m < bst.at(1) && l < bst.at(1))//if m and l both less than smaller child
		{
			return GetLCA(bst, l, m);//recursive call to run again
		}
		else  
		{
			return bst.at(1);//left child is lca
		}
	}
	else if(  m > bst.at(0) && l > bst.at(0))//if m and l on right side of tree
	{
		if( m > bst.at(2) && l > bst.at(2))//if m and l greater than larger child
		{
			return GetLCA(bst, l, m);////recursive call to run again
		}
		else  
		{
			return bst.at(2);//right child is lca
    }
  
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main() {
  std::vector<int> bst;
  std::string input;
  getline(std::cin, input);
  std::stringstream iss(input);
  int number;
  while (iss >> number) {
    bst.push_back(number);
  }
  int l, m;
  std::cin >> l;
  std::cin >> m;
  
  std::vector<int> path;
  int lca = GetLCA(bst, l, m);

  std::cout << "lca = " << lca;
  return 0;
}
