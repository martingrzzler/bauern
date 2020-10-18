#ifndef UTILS_HPP
#define UTILS_HPP

#include <array>
#include <functional>

namespace Utils
{

  enum State
  {
    NONE,
    WHITE,
    BLACK,
    UNDEFINED = -1
  };

  typedef std::array<std::array<State, 2>, 8> MatchField;

  /* loops over all elements in the Matchfield and calls the lamda only when the current Field is WHITE */
  void forEachWhite(const Utils::MatchField &data, const std::function<void(int, int)> &lamda);

  Utils::MatchField copyMatchField(const Utils::MatchField &from);

}; // namespace Utils

#endif /* UTILS_HPP */