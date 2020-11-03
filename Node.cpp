#include "Node.hpp"
#include <sstream>

Node::Node(const Utils::MatchField &data): data(data) 
{
  this->children = new std::vector<Node>();
  this->end = new Utils::End();
  *this->end = Utils::UNSET;
}

Utils::MatchField Node::getData() const
{
  return this->data;
}

void Node::addChild(const Node &node) const
{
  this->children->push_back(node);
}

void Node::setEnd(const Utils::End &end) const
{
  *this->end = end;
}

Utils::End& Node::getEnd() const
{
  return *this->end;
}

std::vector<Node>& Node::getChildren() const
{
  return *this->children;
}

std::string Node::toString() const
{
  std::stringstream ss;
  ss << "Node(end: " << *this->end << "): {\n";
  for (int i = 0; i < this->data.size(); i++)
  {
    ss << "\tRow " << i << ": {";
    for (int j = 0; j < this->data[i].size(); j++)
    {
      ss << this->data[i][j] << ", ";
    }
    ss << "},\n";
    
  }
  ss << "}\n";

  return ss.str();
}

