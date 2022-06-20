# Tree-Traversal

Part 1 - FindNode
Our first function in autocomplete.cpp, FindNode, traverses the Tree based on the
characters in prefix and outputs the TreeNode that we end at. If we cannot find a
valid node, we return null. The index variable helps us remember which character
we're at in prefix.
For example, if our prefix was "acn", we should output the node with 'n' in it after
traversing TreeNode('a') and TreeNode('c').

Part 2 - CollectWords
Our next function in autocomplete.cpp actually collects all the words from a given
TreeNode. It also ensures that each word is prepended with prefix. 

Part 3 - Get Candidates
Our final function in autocomplete.cpp uses the functions from P1 and P2 together to
return the actual answer.
