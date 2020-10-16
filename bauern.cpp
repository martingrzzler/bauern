#include "Tree.hpp"
#include "Constants.hpp"

int main()
{

  Node root = Node(Constants::initial);
  Tree tree = Tree(root);
  tree.buildTree(tree.getRoot());

  return 0;
}
