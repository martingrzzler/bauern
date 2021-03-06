#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include "Utils.hpp"

class Node
{
private:
  Utils::MatchField data;
  mutable std::vector<Node> *children;
  mutable Utils::End *end;
  Utils::State turn;
public:
  Node(const Utils::MatchField &data, Utils::State turn);
  Utils::MatchField getData() const;
  void addChild(const Node &node) const;
  void setEnd(const Utils::End &end) const;
  Utils::End& getEnd() const;
  std::vector<Node>& getChildren() const;
  std::string toString() const;
  Utils::State getTurn() const;
};


#endif /* NODE_HPP */