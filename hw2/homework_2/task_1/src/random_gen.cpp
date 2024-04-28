#include "random_gen.hpp"

#include <random>

int RandomNum() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 99);
  int target = dis(gen);
  return target;
}