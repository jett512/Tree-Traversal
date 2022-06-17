/*
 * autocomplete.cpp
 * 
 * The file where you will implement your autocomplete code for Project 4.
 *
 * INSTRUCTOR NOTE: Do not change any of the existing function signatures in
 * this file, or the testcases will fail. 
 */
#include <iostream>
#include "autocomplete.h"



/** QUESTION 1: FINDNODE **/
/*
EFFECTS: Traverses the Tree based on the charactes in the prefix and 
          returns the TreeNode that we end at. If we cannot find a valid node,
         we return an empty TreeNode. The index variable keeps track of what 
         character we're at in prefix.
 
 PSEUDOCODE:
 algorithm FindNode
   Input:
   Output: 
   
	create vector of treenodes kids = nodes children

	if prefix size = index
		return node
	else
		define match = false
		for loop through kids
			if child at i == prefix at index
			match = true
			break loop
		end loop
		
		if match = false
			return empty node
	
	return FindNode(node, prefix, index + 1)

 COMMENTS:

	Begins by creating a vector of treenodes called kids. The root node is * and we begin at the children of this node.
	This vector is now [a b c], which will be the starting point for the search.

	If statment to check if the size of prefix is equal to index. 
	Since index is character we're at in prefix, when size is equal final character of prefix we're done traversing tree

	Else statments means we are not done traversing tree, so current node is not the target
	Intialize match to keep track of node presence. Begins as false because node search has not yet begun, will be used later.
	Loop through kids nodes as long as i is less than size of kids vector.
	if current child node = current prefix at given index, then node has been found 
	Set match to true, as the node is present in the tree, and break loop because search is over.

	If match is false, then after the loop was finished, the node has not been found and not set to true.
	Then return empty node because node was not found in tree.

	Recursive call increments index, returns the node and prefix back to function to find next node. 

	
*/ 
TreeNode<char> FindNode(TreeNode<char> node, std::string prefix, int index) {
  // Implement this function.
	
	std::vector<TreeNode<char>> kids = node.GetChildren(); //create vector of treenodes
		
	if(prefix.size() == index)//final character of prefix = index
	{
		return node;//done traversing tree
	}

	else//not done traversing tree
	{
		bool match = false;//intialize match to keep track of node presence
		for(int i = 0; i < kids.size(); i++)//loop through kids nodes
		{
			if(kids.at(i).GetValue() == prefix.at(index))//current child node = current prefix at given index
			{
				node = kids.at(i);//set node to current child node
				match = true;//found node
				break;
			}
		}
		if(match == false)//node not found
		{
			return TreeNode<char>();//not in tree
		}       			
	}
	return FindNode(node, prefix, index + 1);//recursive call increments index
}



/** QUESTION 2: COLLECTWORDS **/
/*
 EFFECTS: Collects all the words starting from a given TreeNode. For each word, 
          prepends the word with the prefix and adds it to the results vector.
 
 PSEUDOCODE:
 algorithm CollectWords
   Input:
   Output: 
 
	create vector of treenodes words = nodes children

	for loop through word's node's

		if current node's child's value = $
			if node is empty = true
				break
		else
			push prefix to back of results

		CollectWords(node's children, prefix + node's children, results)	
	end loop

 COMMENTS:
	
	Begins by creating a vector of treenodes called kids. The root node is * and we begin at the children of this node.
	This vector is now [a b c], which will be the starting point for the search.

	Loop through kids nodes as long as i is less than size of kids vector.
	If the current node's child's value equals $, then this may mark the end of the word
	However, there could be more than one child, so nested if checks that node has no other children
	When there is no other children, the loop breaks because the word was found.
	Moving to else statment means one child is $, but another is a character, then push prefix to back of results
	Pushing prefix to the back of results, storing prefix in the results string at the left most position.

	Still inside the for loop, after all comparison statements, recursive call to return node's children, prefix + children of node, and results to function
	Node's children are returned to continue the collection of words based on the current node in the loop.
	Prefix + current child node prepends the prefix to the found characters in the tree, creating the word starting from prefix node(s).
	results is returned unmodified, as it is modified elsewhere.
	

 */ 
void CollectWords(TreeNode<char> node, std::string prefix, std::vector<std::string> &results) {
  // Implement this function.
	
	std::vector<TreeNode<char>> words = node.GetChildren();//create vector of treenodes words = nodes children

	for(int i = 0; i < words.size(); i++)//for loop through word's node's
	{
		if(node.GetChildren()[i].GetValue() == '$')//if current node's child's value = $
		{
			if(node.GetChildren()[i].IsEmpty() == true)//if node has no other children
			{
				break;//only child is $, all characters of word found
			}
			else//one child is $, but another is a character
			{
                results.push_back(prefix);//push prefix to back of results
			}
		}
		CollectWords(node.GetChildren()[i], prefix + node.GetChildren()[i].GetValue(), results);//recursive call to return node, prefix + children of node, and results to function
	}   
}

/** QUESTION 3: GETCANDIDATES **/
/*
EFFECTS: Returns the list of all possible words that can be made starting with
          the letters in prefix, based on traversing the tree with the given root.
 
 PSEUDOCODE:
 algorithm GetCandidates
   Input:
   Output: 
   
	results = empty vector of strings
	Treenode start = FindNode(root, prefix, index = 0)
	CollectWords(start, prefix, results);
	return results

 COMMENTS:
	
	Declare and initialize results, setting eqaul to an empty vector of strings

	Create tree node start, which is equal to find node function impleimented above
	Tree node of root is where find node begins, using prefix, and starting from index 0 (first character)
	This finds the node we want to start from given a prefix

	Collect words called which is a function impleimented above, which collects nodes as characters for the words
	Findnode gave us the start tree node to know where to begin, with prefix, and the empty vector of strings results.
	This node from FindNode function is then used at the starting node for CollectWords.

	These functions are both called to fill in the results string, which is the words created form the tree.
	It is crucial that start is defined as find node becaus ethe function must know where to begin the search, or if prefix is valid.

	return results back to function, which ouputs the words created from the tree nodes.
*/
std::vector<std::string> GetCandidates(TreeNode<char> root, std::string prefix) {
  // Implement this function.
	
	std::vector<std::string> results = std::vector<std::string>(); //Declare and initialize results, setting eqaul to an empty vector of strings

	TreeNode<char> start = FindNode(root, prefix, 0);//equal to find node function impleimented above
	//std::vector<TreeNode<char>> kids = start.GetChildren();

	CollectWords(start, prefix, results);//collects nodes as characters for the words
	
	return results;//output words, if they exist

}

