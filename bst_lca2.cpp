// Run in Repl.it
// clang++-7 -pthread -std=c++17 -o bst_lca bst_lca.cpp; ./bst_lca < bst_lca1.in
//Run in zeus.cs.txstate.edu:
//g++ -pthread -o bst_lca bst_lca.cpp; ./bst_lca < bst_lca1.in
#include <iostream>
#include <sstream>
#include <vector>

/** QUESTION 6: LOWEST COMMON ANCESTOR **/

// EFFECTS: Returns the value of the lowest common ancestor of nodes l and m.
// 
// PSEUDOCODE:
// algorithm GetLCA
//   Input:
//   Output: 
//   Your pseudocode goes here.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.

int GetLCA(std::vector<int> &bst, int l, int m) {
  // Implement this function.
  //int index = 0;
  //int lindex = (bst.at(l) * 2) + 2;
  //int mindex = (bst.at(m) * 2) + 1 ;

  //std::cout << " index ->" << lindex << " value = " << l << ". ";
  //std::cout << " index ->" << mindex<<" value = " << m << ". ";

  
  if(m < l && l > bst.at(0))
  {
    return bst.at(0);
  }
  else if ( m == bst.at(0) || l == bst.at(0))
  {
    return bst.at(0);
  }
  else if( m < bst.at(0) && l < bst.at(0))
  {
    if( m < bst.at(1) && l < bst.at(1))
    {
      return GetLCA(bst, l, m);
    }
    else  
    {
      return bst.at(1);
    }
  }
  else if(  m > bst.at(0) && l > bst.at(0))
  {
    if( m > bst.at(2) && l > bst.at(2))
    {
      return GetLCA(bst, l, m);
    }
    else  
    {
      return bst.at(2);
    }
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
