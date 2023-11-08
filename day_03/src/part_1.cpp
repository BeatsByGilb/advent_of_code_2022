#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

/// Finds which character shows up at least once in both str_1 and str_2.
/// Assumption: str_1 and str_2 have exactly one character in common.
char find_common_element(std::string str_1, std::string str_2)
{
  std::unordered_set<char> elements_in_1;
  for (char c1 : str_1) {
    elements_in_1.insert(c1);
  }

  for (char c2 : str_2) {
    if (elements_in_1.find(c2) != elements_in_1.end()) {
      return c2;
    }
  }

  return '\0';
}

/// Gets the priority of the item represented by the given character
int get_item_priority(char item)
{
  if (item >= 'a') {
    return item - 'a' + 1;
  } else {
    return item - 'A' + 27;
  }
}

int main()
{
  std::string line;
  std::ifstream input_file("resources/input.txt");
  int priority_sum = 0;
  while (getline(input_file, line)) {
    size_t items_per_compartment = line.length() / 2;
    std::string compartment_1 = line.substr(0, items_per_compartment);
    std::string compartment_2 = line.substr(
      items_per_compartment, items_per_compartment);
    char duplicate_item = find_common_element(compartment_1, compartment_2);
    priority_sum += get_item_priority(duplicate_item);
  }

  std::cout << "Sum of priorities of repeated items: " << priority_sum <<
    std::endl;
  return 0;
}
