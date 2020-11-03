#include "Tree.hpp"
#include "Constants.hpp"
#include <iostream>

void printAllFields(const Node &node, int &count)
{ 
  
  
  if (node.getChildren().size() != 0) {
    for (int i = 0; i < node.getChildren().size(); i++)
    {
     printAllFields(node.getChildren()[i], count);
    }
  } else {
    count++;
    if (node.getEnd() == Utils::UNSET) {
      std::cout << node.toString() << std::endl;
      std::cout << "number of children: " << node.getChildren().size()<< std::endl;
    }
    
  }
}

int main()
{

  Node *root = new Node(Constants::initial);
  Tree *tree = new Tree(*root);
  tree->buildTree(tree->getRoot());
  int count = 0;
  printAllFields(*root, count);
  std::cout << "Leaves count: " << count << std::endl;

  return 0;
}
