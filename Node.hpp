#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include "Utils.hpp"

class Node
{
private:
  Utils::MatchField data;
  mutable std::vector<Node> children;
public:
  Node(const Utils::MatchField &data);
  Utils::MatchField getData() const;
  void addChild(const Node &node) const;
  std::vector<Node>& getChildren() const;
  std::string toString() const;
};


#endif /* NODE_HPP */