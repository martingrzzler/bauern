#include "Utils.hpp"

void Utils::forEachWhite(const Utils::MatchField &data, const std::function<void(int, int)> &lamda)
{
  for (int row = 0; row < data.size(); row++)
  {
    for (int column = 0; column < data[row].size(); column++)
    {
      if (data[row][column] == Utils::WHITE) {
        lamda(row, column);
      }
      
    }
  }
}

Utils::MatchField Utils::copyMatchField(const Utils::MatchField &from) 
{
  Utils::MatchField to = MatchField();

  for (int i = 0; i < from.size(); i++) 
  {
    for (int j = 0; j < from[i].size(); j++) 
    {
      to[i][j] = from[i][j];
    }
  }

  return to;
}