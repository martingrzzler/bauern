#include "Tree.hpp"
#include "Constants.hpp"
#include <iostream>

Tree::Tree(const Node &node) : root(node)
{
}

void Tree::buildTree(const Node &node, const Utils::State &turn)
{
  if (this->hasEnded(turn, node))
  {
    return;
  }

  if (turn == Utils::WHITE)
  {
    this->moveWhite(node);
  }
  else if (turn == Utils::BLACK)
  {
    this->moveBlack(node);
  }
}

bool Tree::hasEnded(const Utils::State &turn, const Node &node) const
{
  bool hasEnded = true;
  for (int i = 0; i < node.getData().size(); i++)
  {
    for (int j = 0; j < node.getData()[i].size(); j++)
    {
      Utils::State bauer = node.getData()[i][j];
      if (bauer == Utils::WHITE || bauer == Utils::BLACK)
      {
        if (turn == bauer)
        {
          hasEnded = false;
        }

        if (bauer == Utils::WHITE && i == Constants::END_LINE_WHITE) {
          node.setEnd(Utils::WHITE_WIN);
          return true;
        }

          
        else if (bauer == Utils::BLACK && i == Constants::END_LINE_BLACK) {
          node.setEnd(Utils::BLACK_WIN);
          return true;
        }
      }
    }
  }
  if (hasEnded && turn == Utils::BLACK) node.setEnd(Utils::WHITE_WIN);
  else if (hasEnded && turn == Utils::BLACK) node.setEnd(Utils::BLACK_WIN);
  return hasEnded;
}

void Tree::moveBlack(const Node &node)
{
  auto callback = [this, &node](int row, int column) {
    const Utils::State &current = node.getData()[row][column];
    const Utils::State &ahead = node.getData()[row - 1][column];
    const Utils::State &leftUpward = column == Constants::NO_LEFT_UPWARD_COLUMN ? Utils::UNDEFINED : node.getData()[row - 1][column - 1];
    const Utils::State &rightUpward = column == Constants::NO_RIGHT_UPWARD_COLUMN ? Utils::UNDEFINED : node.getData()[row - 1][column + 1];

    if (ahead == Utils::NONE)
    {
      this->addNode(node, Utils::BLACK, { row, column, current, Utils::AHEAD });
    }

    if (leftUpward == Utils::WHITE)
    {
      this->addNode(node, Utils::BLACK, { row, column, current, Utils::LEFT_UPWARD });
    }

    if (rightUpward == Utils::WHITE)
    {
      this->addNode(node, Utils::BLACK, { row, column, current, Utils::RIGHT_UPWARD });
    }

    else {
      node.setEnd(Utils::DRAW);
    }
  };

  Utils::forEachBlackReverse(node.getData(), callback);
}

void Tree::moveWhite(const Node &node)
{
  auto callback = [&node, this](int row, int column) {
    const Utils::State &current = node.getData()[row][column];
    const Utils::State &ahead = node.getData()[row + 1][column];
    const Utils::State &leftUpward = column == Constants::NO_LEFT_UPWARD_COLUMN ? Utils::UNDEFINED : node.getData()[row + 1][column - 1];
    const Utils::State &rightUpward = column == Constants::NO_RIGHT_UPWARD_COLUMN ? Utils::UNDEFINED : node.getData()[row + 1][column + 1];

    if (ahead == Utils::NONE)
    {
      this->addNode(node, Utils::WHITE, { row, column, current, Utils::AHEAD });
    }
    if (leftUpward == Utils::BLACK)
    {
      this->addNode(node, Utils::WHITE, { row, column, current, Utils::LEFT_UPWARD });
    }
    if (rightUpward == Utils::BLACK)
    {
      this->addNode(node, Utils::WHITE, { row, column, current, Utils::RIGHT_UPWARD });
    }

    else 
    {
      node.setEnd(Utils::DRAW);
    }
  };
  Utils::forEachWhite(node.getData(), callback);
}

void Tree::addNode(const Node &node, const Utils::State &turn, const Utils::Positions &positions)
{
  Utils::MatchField copy = Utils::copyMatchField(node.getData());
  switch (positions.move)
  {
  case Utils::AHEAD:
    if (turn == Utils::WHITE) copy[positions.row + 1][positions.column] = positions.current;
    else copy[positions.row - 1][positions.column] = positions.current;
    break;
  case Utils::LEFT_UPWARD:
    if (turn == Utils::WHITE) copy[positions.row + 1][positions.column - 1] = positions.current;
    else copy[positions.row - 1][positions.column - 1] = positions.current;
    break;
  case Utils::RIGHT_UPWARD:
    if(turn == Utils::WHITE) copy[positions.row + 1][positions.column + 1] = positions.current;
    else copy[positions.row - 1][positions.column + 1] = positions.current;
    break;
  default:
    std::cout << "Should not happen with Move: " << positions.move << std::endl;
    break;
  }

  copy[positions.row][positions.column] = Utils::NONE;
  const Node *child = new Node(copy);
  node.addChild(*child);
  this->buildTree(*child, turn == Utils::WHITE ? Utils::BLACK : Utils::WHITE);
}

Node &Tree::getRoot()
{
  return this->root;
}
