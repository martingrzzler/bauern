#include "Tree.hpp"
#include "Constants.hpp"
#include <iostream>

void printAllFields(const Node &node, int &count)
{ 
  count++;
  std::cout << node.toString() << std::endl;
  if (node.getChildren().size() != 0) {
    for (int i = 0; i < node.getChildren().size(); i++)
    {
     printAllFields(node.getChildren()[i], count);
    }
  };
}

int main()
{

  Node *root = new Node(Constants::initial);
  Tree *tree = new Tree(*root);
  tree->buildTree(tree->getRoot());
  std::cout << root->getChildren().size();
  int count = 0;
  printAllFields(*root, count);
  std::cout << count << std::endl;

  return 0;
}
