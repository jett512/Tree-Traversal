/*
 * tree_node.h
 * 
 * A simple interface for a tree node in a tree data structure. TreeNode is a class
 * template.
 * 
 * INSTRUCTOR NOTE: THIS FILE IS INCLUDED AS PART OF YOUR STARTER CODE. DO NOT
 * MODIFY THIS FILE.
 */

#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__


#include <vector>


template <typename T>
class TreeNode {
  // OVERVIEW: Tree node containing a value and a vector of children 

 public:
  // Operational methods

  // EFFECTS: returns value stored at this node
  T GetValue(); 

  // EFFECTS: returns vector of children of this node
  std::vector< TreeNode<T> > GetChildren();
  
  // EFFECTS: returns true if node is a leaf, or false otherwise
  bool IsLeaf();

  // EFFECTS: returns true if node is empty, or false otherwise
  bool IsEmpty();

  // Maintenance methods

  TreeNode();                                                        // Constructor
  TreeNode(const T value);                                           // Constructor
  TreeNode(const T value, const std::vector< TreeNode<T> > &children); // Constructor
  ~TreeNode();                                                       // Destructor

 private:
  // Private member variables  

  T                             value; // The value stored at this node
  std::vector< TreeNode<T> > children; // Vector containing children of this node
  bool                       is_empty; // Whether this node is empty
};

// Operational methods 

// EFFECTS: returns value stored at this node
template <typename T>
T TreeNode<T>::GetValue() {
  return this->value;
}

// EFFECTS: returns vector of children of this node
template <typename T>
std::vector< TreeNode<T> > TreeNode<T>::GetChildren() {
  return this->children;
}

// EFFECTS: returns true if node is a leaf, or false otherwise
template <typename T>
bool TreeNode<T>::IsLeaf() {
  return this->children.size() == 0;
}

// EFFECTS: returns true if node is empty, or false otherwise
template <typename T>
bool TreeNode<T>::IsEmpty() {
  return this->is_empty;
}

// Maintenance methods

// Constructor with no arguments
template <typename T>
TreeNode<T>::TreeNode() {
  this->is_empty = true;
}

// Constructor with value
template <typename T>
TreeNode<T>::TreeNode(const T value) {
  this->value = value; 
  this->is_empty = false;
}

// Constructor with value and children
template <typename T>
TreeNode<T>::TreeNode(const T value, const std::vector< TreeNode<T> > &children) {
  this->value = value; 
  this->children = children; 
  this->is_empty = false;
}

// Destructor 
template <typename T>
TreeNode<T>::~TreeNode() {}

#endif /* __TREE_NODE_H__ */
