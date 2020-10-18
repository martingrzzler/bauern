#include "Node.hpp"

Node::Node(const Utils::MatchField &data): data(data) 
{
  this->children = std::vector<Node>();
}

Utils::MatchField Node::getData() const
{
  return this->data;
}

void Node::addChild(const Node &node) const
{
  this->children.push_back(node);
}

