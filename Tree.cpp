#include "Tree.hpp"
#include "Constants.hpp"
#include <iostream>

Tree::Tree(const Node &node) : root(node)
{
}

void Tree::buildTree(const Node &node, const Utils::State &turn)
{
  Node *root_p = &this->root;
  if (&node == root_p)
  {
    std::cout << "called with root node" << std::endl;
  }
  if (this->hasEnded(turn, node.getData()))
  {
    return;
  }

  if (turn == Utils::WHITE)
  {
    this->moveWhite(node.getData(), node);
  }
  else if (turn == Utils::BLACK)
  {
    this->moveBlack(node.getData(), node);
  }
}

bool Tree::hasEnded(const Utils::State &turn, const Utils::MatchField &data) const
{
  bool hasEnded = true;
  for (int i = 0; i < data.size(); i++)
  {
    for (int j = 0; j < data[i].size(); j++)
    {
      Utils::State bauer = data[i][j];
      if (bauer == Utils::WHITE || bauer == Utils::BLACK)
      {
        if (turn == bauer)
        {
          hasEnded = false;
        }

        if (bauer == Utils::WHITE && i == Constants::END_LINE_WHITE)
          return true;
        else if (bauer == Utils::BLACK && i == Constants::END_LINE_BLACK)
          return true;
      }
    }
  }
  return hasEnded;
}

void Tree::moveBlack(const Utils::MatchField &data, const Node &node)
{
  auto callback = [&data, this, &node](int row, int column) {
    const Utils::State &current = data[row][column];
    const Utils::State &ahead = data[row - 1][column];
    const Utils::State &leftUpward = column == Constants::NO_LEFT_UPWARD_COLUMN ? Utils::UNDEFINED : data[row + 1][column - 1];
    const Utils::State &rightUpward = column == Constants::NO_RIGHT_UPWARD_COLUMN ? Utils::UNDEFINED : data[row + 1][column + 1];

    if (ahead == Utils::NONE)
    {
      Utils::MatchField copy = Utils::copyMatchField(data);
      copy[row - 1][column] = current;
      copy[row][column] = Utils::NONE;
      const Node child = Node(copy);
      node.addChild(child);
      this->buildTree(child, Utils::WHITE);
    }

    if (leftUpward == Utils::WHITE)
    {
      Utils::MatchField copy = Utils::copyMatchField(data);
      copy[row - 1][column - 1] = current;
      copy[row][column] = Utils::NONE;
      const Node child = Node(copy);
      node.addChild(child);
      this->buildTree(child, Utils::WHITE);
    }

    if (rightUpward == Utils::WHITE)
    {
      Utils::MatchField copy = Utils::copyMatchField(data);
      copy[row - 1][column + 1] = current;
      copy[row][column] = Utils::NONE;
      const Node child = Node(copy);
      node.addChild(child);
      this->buildTree(child, Utils::WHITE);
    }
  };

  Utils::forEachBlackReverse(data, callback);
}

void Tree::moveWhite(const Utils::MatchField &data, const Node &node)
{
  Node *root_p = &this->root;
  if (&node == root_p)
  {
    std::cout << "called with root node in moveWhite" << std::endl;
  }
  auto callback = [&data, &node, this](int row, int column) {
    const Utils::State &current = data[row][column];
    const Utils::State &ahead = data[row + 1][column];
    const Utils::State &leftUpward = column == Constants::NO_LEFT_UPWARD_COLUMN ? Utils::UNDEFINED : data[row + 1][column - 1];
    const Utils::State &rightUpward = column == Constants::NO_RIGHT_UPWARD_COLUMN ? Utils::UNDEFINED : data[row + 1][column + 1];

    if (ahead == Utils::NONE)
    {
      Node *root_p = &this->root;
      if (&node == root_p)
      {
        std::cout << "called with root node in lamda" << std::endl;
      }
      Utils::MatchField copy = Utils::copyMatchField(data);
      copy[row + 1][column] = current;
      copy[row][column] = Utils::NONE;
      const Node child = Node(copy);
      node.addChild(child);
      this->buildTree(child, Utils::BLACK);
    }
    if (leftUpward == Utils::BLACK)
    {
      Utils::MatchField copy = Utils::copyMatchField(data);
      copy[row + 1][column - 1] = current;
      copy[row][column] = Utils::NONE;
      const Node child = Node(copy);
      node.addChild(child);
      this->buildTree(child, Utils::BLACK);
    }
    if (rightUpward == Utils::BLACK)
    {
      Utils::MatchField copy = Utils::copyMatchField(data);
      copy[row + 1][column + 1] = current;
      copy[row][column] = Utils::NONE;
      const Node child = Node(copy);
      node.addChild(child);
      this->buildTree(child, Utils::BLACK);
    }
  };
  Utils::forEachWhite(data, callback);
}

Node &Tree::getRoot()
{
  return this->root;
}
