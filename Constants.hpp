#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "Utils.hpp"
#include <array>

namespace Constants
{

  const Utils::MatchField initial =
      {{
        {Utils::NONE, Utils::NONE},
        {Utils::WHITE, Utils::WHITE},
        {Utils::NONE, Utils::NONE},
        {Utils::NONE, Utils::NONE},
        {Utils::NONE, Utils::NONE},
        {Utils::NONE, Utils::NONE},
        {Utils::BLACK, Utils::BLACK},
        {Utils::NONE, Utils::NONE}
      }};

  const int MAX_PLAYERS = initial[0].size();
  const int END_LINE_WHITE = initial.size() - 1;
  const int END_LINE_BLACK = 0;
  const int NO_LEFT_UPWARD_COLUMN = 0;
  const int NO_RIGHT_UPWARD_COLUMN = initial[0].size() - 1;

} // namespace Constants

#endif /* CONSTANTS_HPP */