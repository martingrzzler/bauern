#include "Tree.hpp"
#include "Constants.hpp"
#include <iostream>

int main()
{

  Node root = Node(Constants::initial);
  Tree tree = Tree(root);
  tree.buildTree(tree.getRoot());
  std::cout << root.getChildren().size();
  for (int i = 0; i < root.getChildren().size(); i++)
  {
    Node &node = root.getChildren()[i];
    std::cout << node.toString();
  }
  
  return 0;
}
