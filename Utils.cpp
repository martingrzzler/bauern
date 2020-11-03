#include "Utils.hpp"
#include <iostream>

int Utils::getTotalBauernLeft(const Utils::MatchField &data, const Utils::State &turn)
{
  // first iteration for getting all the bauern left >> CurrentStats::totalBauern
  int totalBauern = 0;
  for (int row = 0; row < data.size(); row++)
  {
    for (int column = 0; column < data[row].size(); column++)
    {
      if (data[row][column] == turn)
      {
        totalBauern++;
      }
    }
  }
  return totalBauern;
}

void Utils::forEachWhite(const Utils::MatchField &data, const std::function<void(Utils::CurrentStats)> &lamda)
{

  int currentBauer = 0;
  for (int row = 0; row < data.size(); row++)
  {
    for (int column = 0; column < data[row].size(); column++)
    {
      if (data[row][column] == Utils::WHITE)
      {
        currentBauer++;
        lamda({row, column, Utils::getTotalBauernLeft(data, Utils::WHITE), currentBauer});
      }
    }
  }
}

void Utils::forEachBlackReverse(const Utils::MatchField &data, const std::function<void(Utils::CurrentStats)> &lamda)
{

  int currentBauer = 0;
  for (int row = data.size() - 1; row > -1; row--)
  {
    for (int column = data[row].size() - 1; column > -1; column--)
    {
      if (data[row][column] == Utils::BLACK)
      {
        currentBauer++;
        lamda({row, column, Utils::getTotalBauernLeft(data, Utils::BLACK), currentBauer});
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
