#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include "Utils.hpp"

class Node
{
private:
  Utils::MatchField data;
  mutable std::vector<Node> *children;
  mutable Utils::End *end = NULL;
public:
  Node(const Utils::MatchField &data);
  Utils::MatchField getData() const;
  void addChild(const Node &node) const;
  void setEnd(const Utils::End &end);
  std::vector<Node>& getChildren() const;
  std::string toString() const;
};


#endif /* NODE_HPP */