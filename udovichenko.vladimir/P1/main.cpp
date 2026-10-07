#include <iostream>

const int RETURN_CODE_CANNOT_CALCULATE_ANY_PARAMETER = 2;

int main()
{
  int x = 0;
  int prev = 0;
  int prev_prev = 0;
  int count = 0;
  int max_value = 0;
  int count_local_minimums = 0;
  int count_after_max = 0;

  while (std::cin >> x && x != 0)
  {
    if (prev_prev != 0 && prev < prev_prev && prev < x)
    {
      count_local_minimums++;
    }

    count_after_max++;
    if (count == 0 || x > max_value)
    {
      max_value = x;
      count_after_max = 0;
    }

    prev_prev = prev;
    prev = x;
    count++;
  }

  if (!std::cin)
  {
    std::cerr << "The input isn't a sequence\n";
    return 1;
  }
  if (count == 0)
  {
    std::cerr << "Not enough elements to find local minimum\n";
    return RETURN_CODE_CANNOT_CALCULATE_ANY_PARAMETER;
  }

  std::cout << count_local_minimums << "\n";
  std::cout << count_after_max << "\n";

  return 0;
}
