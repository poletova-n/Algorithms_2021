#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <algorithm>
#include <cmath>

static long long count = 0;

int increment(long inc[], const size_t size);

template <typename T>
void sortShellGaps(T* list, const size_t size)
{
  count = 0;
  for (size_t gap = size / 2; gap >= 1; gap /= 2) {

    for (size_t i = gap; i < size; i++)
    {
      for (size_t j = i; j >= gap; j -= gap)
      {
        count++;
        if (list[j] >= list[j - gap])
        {
          std::swap(list[j], list[j - gap]);
        }
        else
        {
          break;
        }
      }
    }
  }
}

template <typename T>
void sortHibbardGaps(T* list, const size_t size)
{
  count = 0;
  for (size_t gap = pow(2, (int)(log(size) / log(2))) - 1; gap >= 1; gap /= 2)
  {
    for (size_t i = gap; i < size; i++)
    {
      for (size_t j = i; j >= gap; j -= gap)
      {
        count++;
        if (list[j] >= list[j - gap])
        {
          std::swap(list[j], list[j - gap]);
        }
        else
        {
          break;
        }
      }
    }
  }
}


template <typename T>
void sortSedgewickGaps(T* list, const size_t size)
{
  long inc, i, j, seq[40];
  int s;
  count = 0;
  s = increment(seq, size);
  while (s >= 0)
  {
    inc = seq[s--];
    for (i = inc; i < size; ++i)
    {
      for (j = i; j >= inc; j -= inc)
      {
        count++;
        if (list[j] >= list[j - inc])
        {
          std::swap(list[j], list[j - inc]);
        }
        else break;
      }
    }
  }
}



#endif
