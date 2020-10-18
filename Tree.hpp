#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"

class Tree
{
private:
  Node root;

public:
  Tree(const Node &node);
  void buildTree(const Node &node, const Utils::State &turn = Utils::WHITE);
  bool hasEnded(const Utils::State &turn, const Utils::MatchField &data) const;
  void moveBlack(const Utils::MatchField &data);
  void moveWhite(const Utils::MatchField &data);
  Node getRoot() const;
};

#endif /* TREE_HPP */