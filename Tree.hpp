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
  bool hasEnded(const Utils::State &turn, const Node &node) const;
  void moveBlack(const Node &node);
  void moveWhite(const Node &node);
  void addNode(const Node &node, const Utils::State &turn, const Utils::Positions &positions);
  void postOrderTraverseDF(const Node*, const std::function<void(const Node&)> &lamda);
  void analyze();
  Node& getRoot();
};

#endif /* TREE_HPP */