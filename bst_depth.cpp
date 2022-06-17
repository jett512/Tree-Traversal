// Run in Repl.it
// clang++-7 -pthread -std=c++17 -o bst_depth bst_depth.cpp; ./bst_depth < bst_depth1.in
//Run in zeus.cs.txstate.edu:
//g++ -pthread -o bst_depth bst_depth.cpp; ./bst_depth < bst_depth1.in

#include <iostream>
#include <sstream>
#include <vector>

/** QUESTION 5: DEPTH AND PATH **/
/*
 EFFECTS: Returns the depth of the target node. Modifies the path vector
         so that it contains the node values in the path from the root to
          the target node.
 
 PSEUDOCODE:
 algorithm GetDepthAndPath
   Input: 7
   Output: depth = 2 path = 10 5 7
   
	HelperFunction
		if node = target
			put node to path vector
			return path size
		else if  node < target
			put node to path vector
			return recusive call to formula for right side index
		else if  node greater > target
			put node to path vector
			return recusive call to formula for left side index
	end helper

	Function
		index = 0
		if first node = target
			put node to path vector
			return path size 
		else 
			return variables to helper for new variable index
	end Function
	
 COMMENTS:
 
	I make use of a helper function to use a new variable index to use in the left and right index formulas provided.
	
	The helper function begins by checking if node equals target, if so we are done and put node in path vector.
	Then return return path size for depth value, as the size of path is how may levels we traversed.
	Else if node less than target, the target must be on the right side of the tree.
	put node in path vector and make recusive call to the formula for right side index, which will bring us to the right child.
	Else if node greater than target, the target must be on the left side of the tree.
	put node in path vector and make recusive call to the formula for left side index, which will bring us to the left child.
	These compare statments increment index by the respective formula to get to the correct child node for the target.
	
	The depth function begins by checking if node equals target, if so we are done and put node in path vector.
	Then return return path size for depth value, as the size of path is how many levels we traversed.
	Else target node is the not the root, and we must go to the helper function to use variable index.
	Send variables bst, target, path and index to helper for new variable index usage with the index formula
	left = (2 * i) + 1
	right = (2 * i) + 2

 
*/
int GetDepthAndPathHelper(std::vector<int> &bst, int target, int index, std::vector<int> &path) 
{
	if(bst.at(index) == target)//if node is target
	{
		path.push_back(bst.at(index));//put node in path vector
		return path.size() - 1 ;//return path size for depth value
			
	}
	else if(bst.at(index) < target)//if node less than target
	{
		path.push_back(bst.at(index));//put node in path vector
		return GetDepthAndPathHelper(bst, target, (2 * index) + 2, path);//recusive call to formula for right side index
	}
		
		
	else if( bst.at(index) > target )//if  node greater than target
	{
		path.push_back(bst.at(index));//));//put node in path vector
		return GetDepthAndPathHelper(bst, target, (2 * index) + 1, path);//recusive call to formula for left side index
	}	
	return 0;//no node in path
}

int GetDepthAndPath(std::vector<int> &bst, int target, std::vector<int> &path) {
  // Implement this function.
	int index = 0;//set to 0 for use in helper function
	if(bst.at(index) == target)//if first node is target
	{	
		path.push_back(bst.at(index));//put node in path vector
		return path.size() - 1;//return path size for depth value
	}
	else// target not root
	{	 
		return GetDepthAndPathHelper(bst, target, index, path); //send variables to helper for new variable index
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
  int target;
  std::cin >> target;
  
  std::vector<int> path;
  int depth = GetDepthAndPath(bst, target, path);

  std::cout << "depth = " << depth << std::endl;
  std::cout << "path = ";
  for(int i = 0; i < path.size(); i++) {
    std::cout << path[i] ;
    if (i < path.size() - 1) {
      std::cout << " ";
    }
  }
	std::cout << '\n';
  return 0;
}
