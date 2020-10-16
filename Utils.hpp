#ifndef UTILS_HPP
#define UTILS_HPP

#include <array>

namespace Utils
{

  enum State
  {
    NONE,
    WHITE,
    BLACK
  };

  typedef std::array<std::array<State, 2>, 8> MatchField;

}; // namespace Utils

#endif /* UTILS_HPP */