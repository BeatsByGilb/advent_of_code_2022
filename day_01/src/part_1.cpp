#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
  std::string line;
  std::ifstream input_file("resources/input.txt");
  int max_elf_calories = 0;
  int current_elf_calories = 0;
  while (getline(input_file, line)) {
    // Blank line means end of elf's calories list
    if (line == "") {
      if (current_elf_calories > max_elf_calories) {
        max_elf_calories = current_elf_calories;
        std::cout << "New max: " << current_elf_calories << " calories"
          << std::endl;
      }
      current_elf_calories = 0;
      continue;
    }

    int calories;
    std::stringstream ss(line);
    ss >> calories;
    current_elf_calories += calories;
  }

  std::cout << "Maximum calories carried by one elf: " << max_elf_calories
    << " calories" << std::endl;
  return 0;
}
