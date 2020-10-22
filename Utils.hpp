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

  /* loops over all elements of the Matchfield and calls the lamda only when the current field is WHITE */
  void forEachWhite(const Utils::MatchField &data, const std::function<void(int, int)> &lamda);
  
 /* loops over all elements of the Matchfield in reversed order and calls the lamda only when the current field is BLACK */
  void forEachBlackReverse(const Utils::MatchField &data, const std::function<void(int, int)> &lamda);

  Utils::MatchField copyMatchField(const Utils::MatchField &from);

}; // namespace Utils

#endif /* UTILS_HPP */