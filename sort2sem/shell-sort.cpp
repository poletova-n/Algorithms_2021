#include "shell-sort.hpp"

int increment(long inc[], const size_t size)
{
  int p1, p2, p3, s;
  p1 = p2 = p3 = 1;
  s = -1;
  do
  {
    if (++s % 2)
    {
      inc[s] = 8 * p1 - 6 * p2 + 1;
    }
    else
    {
      inc[s] = 9 * p1 - 9 * p3 + 1;
      p2 *= 2;
      p3 *= 2;
    }
    p1 *= 2;
  } while (3 * inc[s] < size);
  return s > 0 ? --s : 0;
}