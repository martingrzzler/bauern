#ifndef UTILS_HPP
#define UTILS_HPP

#include <array>
#include <functional>
#include <map>

namespace Utils
{

  enum State
  {
    NONE,
    WHITE,
    BLACK,
    UNDEFINED = -1
  };

  enum Move
  {
    LEFT_UPWARD,
    AHEAD,
    RIGHT_UPWARD
  };

  enum End
  {
    DRAW,
    WHITE_WIN,
    BLACK_WIN,
    UNSET = -1
  };

  struct Positions
  {
    int row;
    int column;
    Utils::State current;
    Utils::Move move;
  };

  enum Situation
  {
    STUCK, MOVABLE
  };

  struct CurrentStats 
  {
    int row;
    int column;
    int totalBauern;
    int currentBauer;
  };

  typedef std::array<std::array<State, 2>, 8> MatchField;

  /* retrieve the total number of Bauern left from one side */
  int getTotalBauernLeft(const Utils::MatchField &data, const Utils::State& turn);

  /* loops over all elements of the Matchfield and calls the lamda only when the current field is WHITE */
  void forEachWhite(const Utils::MatchField &data, const std::function<void(Utils::CurrentStats)> &lamda);

  /* loops over all elements of the Matchfield in reversed order and calls the lamda only when the current field is BLACK */
  void forEachBlackReverse(const Utils::MatchField &data, const std::function<void(Utils::CurrentStats)> &lamda);

  Utils::MatchField copyMatchField(const Utils::MatchField &from);

}; // namespace Utils

#endif /* UTILS_HPP */