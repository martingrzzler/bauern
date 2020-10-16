cmake_minimum_required(VERSION 3.8)

set(This BauernTests)


set(Sources
  BauernTest.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
  gtest_main
  BauernLib
)

add_test(
  NAME ${This}
  COMMAND ${This}
)

