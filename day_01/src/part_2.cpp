#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
  std::string line;
  std::ifstream input_file("resources/input.txt");
  std::vector<int> elves;
  int current_elf = 0;
  while (getline(input_file, line)) {
    // Blank line means end of elf's calories list
    if (line == "") {
      elves.push_back(current_elf);
      current_elf = 0;
      continue;
    }

    int calories;
    std::stringstream ss(line);
    ss >> calories;
    current_elf += calories; 
  }

  // Sort from most to least calories
  std::sort(elves.begin(), elves.end(), std::greater<int>());

  int top_three_total = elves[0] + elves[1] + elves[2];

  std::cout << "Top three elves: " << elves[0] << ", " << elves[1] << ", " <<
    elves[2] << " calories" << std::endl;
  std::cout << "The top three elves are carrying a total of " <<
    top_three_total << " calories" << std::endl;
  return 0;
}
