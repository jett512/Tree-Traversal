// Run in Repl.it
// clang++-7 -pthread -std=c++17 -o auto_test1 autocomplete.cpp auto_test1.cpp; ./auto_test1
//Run in zeus.cs.txstate.edu:
//g++ -pthread -o auto_test1 autocomplete.cpp auto_test1.cpp; ./auto_test1
/*
 * auto_test1.cpp
 * 
 * Simple test cases for verifying the functionality of your code in
 * autocomplete.cpp.
 *
 * INSTRUCTOR NOTE: This main function contains some test cases from the project 
 * instructions in order to help you get started with testing your code. You can
 * update or add test cases below to help you verify that your code is functional. 
 * Please test and debug your code!
 * 
 * 
 * It is expected that the main function will result in a segfault if you have not
 * yet implemented the functions in autocomplete.cpp. If you want to test only part
 * of the main function, you can comment out the rest.
 */

#include <iostream>
#include <vector>

#include "autocomplete.h"
#include "tree_node.h"

TreeNode<char> MakeExample() {
  return (
    TreeNode<char>('*', std::vector< TreeNode<char> > { 
      TreeNode<char>('a', std::vector< TreeNode<char> > { 
        TreeNode<char>('c', std::vector< TreeNode<char> > { 
          TreeNode<char>('e', std::vector< TreeNode<char> > { 
            TreeNode<char>('$')
          }),
          TreeNode<char>('n', std::vector< TreeNode<char> > { 
            TreeNode<char>('e', std::vector< TreeNode<char> > { 
              TreeNode<char>('$')
            })
          })
        }),
        TreeNode<char>('n', std::vector< TreeNode<char> > { 
          TreeNode<char>('d', std::vector< TreeNode<char> > { 
            TreeNode<char>('$'),
            TreeNode<char>('r', std::vector< TreeNode<char> > { 
              TreeNode<char>('e', std::vector< TreeNode<char> > { 
                TreeNode<char>('w', std::vector< TreeNode<char> > { 
                  TreeNode<char>('$')
                })
              })
            })
          })
        }),
      }),
      TreeNode<char>('b', std::vector< TreeNode<char> > {
        TreeNode<char>('e', std::vector< TreeNode<char> > {
          TreeNode<char>('a', std::vector< TreeNode<char> > {
            TreeNode<char>('m', std::vector< TreeNode<char> > {
              TreeNode<char>('$')
            })
          }),
          TreeNode<char>('e', std::vector< TreeNode<char> > {
            TreeNode<char>('f', std::vector< TreeNode<char> > {
              TreeNode<char>('$')
            }),
            TreeNode<char>('s', std::vector< TreeNode<char> > {
              TreeNode<char>('$')
            })
          })
        })
      }),
      TreeNode<char>('c', std::vector< TreeNode<char> > {
        TreeNode<char>('a', std::vector< TreeNode<char> > {
          TreeNode<char>('t', std::vector< TreeNode<char> > {
            TreeNode<char>('$')
          })
        }),
        TreeNode<char>('o', std::vector< TreeNode<char> > {
          TreeNode<char>('w', std::vector< TreeNode<char> > {
            TreeNode<char>('$')
          })
        }),
        TreeNode<char>('u', std::vector< TreeNode<char> > {
          TreeNode<char>('t', std::vector< TreeNode<char> > {
            TreeNode<char>('$')
          })
        })
      })
    })
  );
}

template <typename T>
void PrintVector(const std::vector<T> &vec) {
  std::cout << "[ ";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << "\"" << vec[i] << "\" ";
  }
  std::cout << "]" << std::endl;
}

int main() {
  TreeNode<char> example = MakeExample();

  // Q1 Examples
  TreeNode<char> end_node = FindNode(example, "acn", 0);
  std::cout << end_node.GetValue() << std::endl; // Should output 'n'
  std::cout << end_node.GetChildren()[0].GetValue() << std::endl; // Should output 'e'

  end_node = FindNode(example, "notInTree", 0);
  std::cout << (end_node.IsEmpty() ? "true" : "false") << std::endl; // Should output true

  // Q2 Examples
  std::vector<std::string> example_list = std::vector<std::string>();
  CollectWords(example.GetChildren()[1], "", example_list);
  PrintVector(example_list); // Should output ["eam" "eef" "ees"]

  example_list.clear();
  CollectWords(example.GetChildren()[1], "b", example_list);
  PrintVector(example_list); // Should output ["beam" "beef" "bees"]

  example_list.clear();
  CollectWords(example.GetChildren()[1], "mm", example_list);
  PrintVector(example_list); // Should output ["mmeam" "mmeef" "mmees"]

  // Q3 Examples
  PrintVector(GetCandidates(example, "c")); // Should output ["cat" "cow" "cut"]
  PrintVector(GetCandidates(example, "ca")); // Should output ["cat"]
  PrintVector(GetCandidates(example, "an")); // Should output ["and" "andrew"]

  // Should output ["ace" "acne" "and" "andrew" "beam" "beef" "bees" "cat" "cow" "cut"]
  PrintVector(GetCandidates(example, ""));
  PrintVector(GetCandidates(example, "deer")); // Should output []
  PrintVector(GetCandidates(example, "bean")); // Should output []
  
  return 0;
}
