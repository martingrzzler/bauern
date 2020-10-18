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

  if (turn == Utils::WHITE) 
  {
    this->moveWhite(node.getData(), node);
  }
  else if(turn == Utils::BLACK) {

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

void Tree::moveWhite(const Utils::MatchField &data, const Node &node) 
{
  auto callback = [&data, &node](int row, int column)
  {
    const Utils::State &current = data[row][column];
    const Utils::State &ahead = data[row + 1][column];
    const Utils::State &leftUpward = column == Constants::NO_LEFT_UPWARD_COLUMN ? Utils::UNDEFINED : data[row + 1][column - 1];
    const Utils::State &rightUpward = column == Constants::NO_RIGHT_UPWARD_COLUMN ? Utils::UNDEFINED : data[row + 1][column + 1];

    if (ahead == Utils::NONE)
    {
      Utils::MatchField copy = Utils::copyMatchField(data);
      copy[row][column + 1] = current;
      copy[row][column] = Utils::NONE;
      Node child = Node(copy);
      node.addChild(child);
    }

  };
  Utils::forEachWhite(data, callback);
}

Node Tree::getRoot()
{
  return this->root;
}
