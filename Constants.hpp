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


  const int END_LINE_WHITE = initial.size() - 1;
  const int END_LINE_BLACK = 0;

} // namespace Constants

#endif /* CONSTANTS_HPP */