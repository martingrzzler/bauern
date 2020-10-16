#include "Tree.hpp"
#include "Constants.hpp"
#include <iostream>

Tree::Tree(const Node &node) : root(node)
{
}

void Tree::buildTree(const Node &node, const Utils::State &turn)
{
  if (this->hasEnded(turn, node.getData()))
  {
    return;
  }
}

bool Tree::hasEnded(const Utils::State &turn, const Utils::MatchField &data) const
{
  bool hasEnded = true;
  for (int i = 0; i < data.size(); i++)
  {
    for (int j = 0; j < data[i].size(); j++)
    {
      if (data[i][j] == turn)
      {
        hasEnded = false;
        if (turn == Utils::WHITE && i == Constants::END_LINE_WHITE)
          hasEnded = true;
        else if (turn == Utils::BLACK && i == Constants::END_LINE_BLACK)
          hasEnded = true;
      }
    }
  }
  return hasEnded;
}

Node Tree::getRoot() const
{
  return this->root;
}
