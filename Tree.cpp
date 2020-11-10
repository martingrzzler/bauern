#include "Tree.hpp"
#include "Constants.hpp"
#include <iostream>

Tree::Tree(const Node &node) : root(node)
{
}

void Tree::buildTree(const Node &node)
{
  if (this->hasEnded(node))
  {
    return;
  }

  if (node.getTurn() == Utils::WHITE)
  {
    this->moveWhite(node);
  }
  else if (node.getTurn() == Utils::BLACK)
  {
    this->moveBlack(node);
  }
}

bool Tree::hasEnded(const Node &node) const
{
  bool hasEnded = true;
  for (int i = 0; i < node.getData().size(); i++)
  {
    for (int j = 0; j < node.getData()[i].size(); j++)
    {
      Utils::State bauer = node.getData()[i][j];
      if (bauer == Utils::WHITE || bauer == Utils::BLACK)
      {
        if (node.getTurn() == bauer)
        {
          hasEnded = false;
        }

        if (bauer == Utils::WHITE && i == Constants::END_LINE_WHITE) {
          node.setEnd(Utils::WHITE_WIN);
          return true;
        }

        else if (bauer == Utils::BLACK && i == Constants::END_LINE_BLACK) 
        {
          node.setEnd(Utils::BLACK_WIN);
          return true;
        }
      }
    }
  }
  if (hasEnded && node.getTurn() == Utils::BLACK) node.setEnd(Utils::WHITE_WIN);
  else if (hasEnded && node.getTurn() == Utils::WHITE) node.setEnd(Utils::BLACK_WIN);
  return hasEnded;
}

void Tree::moveBlack(const Node &node)
{
  int stucks = 0;

  auto callback = [this, &node, &stucks]( Utils::CurrentStats stats) {
    const Utils::State &current = node.getData()[stats.row][stats.column];
    const Utils::State &ahead = node.getData()[stats.row - 1][stats.column];
    const Utils::State &leftUpward = stats.column == Constants::NO_LEFT_UPWARD_COLUMN ? Utils::UNDEFINED : node.getData()[stats.row - 1][stats.column - 1];
    const Utils::State &rightUpward = stats.column == Constants::NO_RIGHT_UPWARD_COLUMN ? Utils::UNDEFINED : node.getData()[stats.row - 1][stats.column + 1];

    if (ahead == Utils::NONE)
    {
      this->addNode(node, { stats.row, stats.column, current, Utils::AHEAD });
    }

    if (leftUpward == Utils::WHITE)
    {
      this->addNode(node, { stats.row, stats.column, current, Utils::LEFT_UPWARD });
    }

    if (rightUpward == Utils::WHITE)
    {
      this->addNode(node, { stats.row, stats.column, current, Utils::RIGHT_UPWARD });
    }

    // can't move
    if (ahead == Utils::WHITE && leftUpward != Utils::WHITE && rightUpward != Utils::WHITE) 
    {
      stucks++;
      // no left bauer can move hence => DRAW
      if (stucks == stats.totalBauern) node.setEnd(Utils::DRAW);
    }
  };

  Utils::forEachBlackReverse(node.getData(), callback);
}

void Tree::moveWhite(const Node &node)
{
  int stucks = 0;

  auto callback = [&node, this, &stucks](Utils::CurrentStats stats) {
    const Utils::State &current = node.getData()[stats.row][stats.column];
    const Utils::State &ahead = node.getData()[stats.row + 1][stats.column];
    const Utils::State &leftUpward = stats.column == Constants::NO_LEFT_UPWARD_COLUMN ? Utils::UNDEFINED : node.getData()[stats.row + 1][stats.column - 1];
    const Utils::State &rightUpward = stats.column == Constants::NO_RIGHT_UPWARD_COLUMN ? Utils::UNDEFINED : node.getData()[stats.row + 1][stats.column + 1];
    if (ahead == Utils::NONE)
    {
      this->addNode(node, { stats.row, stats.column, current, Utils::AHEAD });
    }
    if (leftUpward == Utils::BLACK)
    {
      this->addNode(node, { stats.row, stats.column, current, Utils::LEFT_UPWARD });
    }
    if (rightUpward == Utils::BLACK)
    {
      this->addNode(node, { stats.row, stats.column, current, Utils::RIGHT_UPWARD });
    }
    // can't move
    if (ahead == Utils::BLACK && leftUpward != Utils::BLACK && rightUpward != Utils::BLACK)
    {
      stucks++;
      if (stucks == stats.totalBauern) node.setEnd(Utils::DRAW);
    }
  };
  Utils::forEachWhite(node.getData(), callback);
}

void Tree::addNode(const Node &node, const Utils::Positions &positions)
{
  Utils::MatchField copy = Utils::copyMatchField(node.getData());
  switch (positions.move)
  {
  case Utils::AHEAD:
    if (node.getTurn() == Utils::WHITE) copy[positions.row + 1][positions.column] = positions.current;
    else copy[positions.row - 1][positions.column] = positions.current;
    break;
  case Utils::LEFT_UPWARD:
    if (node.getTurn() == Utils::WHITE) copy[positions.row + 1][positions.column - 1] = positions.current;
    else copy[positions.row - 1][positions.column - 1] = positions.current;
    break;
  case Utils::RIGHT_UPWARD:
    if(node.getTurn() == Utils::WHITE) copy[positions.row + 1][positions.column + 1] = positions.current;
    else copy[positions.row - 1][positions.column + 1] = positions.current;
    break;
  default:
    std::cout << "Should not happen with Move: " << positions.move << std::endl;
    break;
  }

  copy[positions.row][positions.column] = Utils::NONE;
  const Node *child = new Node(copy, node.getTurn() == Utils::WHITE ? Utils::BLACK : Utils::WHITE);
  node.addChild(*child);
  this->buildTree(*child);
}

void Tree::postOrderTraverseDF(const Node* node ,const std::function<void(const Node&)> &lamda) 
{
  if (node == NULL) 
  {
    return;
  }

  for (int i = 0; i < node->getChildren().size(); i++) 
  {
    this->postOrderTraverseDF(&node->getChildren()[i], lamda);
  }

  lamda(*node);
}

void Tree::analyze() 
{
  auto callback = [](const Node& node)
  {
    if(node.getEnd() == Utils::DRAW) std::cout << node.toString();
  };

  this->postOrderTraverseDF(&this->root, callback);
}

Node &Tree::getRoot()
{
  return this->root;
}
