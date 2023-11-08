#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

/// Finds which character shows up at least once in all three strings.
/// Assumption: There is exactly one character that exists in all three strings.
char find_common_element(
  std::string str_1, std::string str_2, std::string str_3)
{
  std::unordered_set<char> elements_in_1;
  for (char c1 : str_1) {
    elements_in_1.insert(c1);
  }

  std::unordered_set<char> elements_in_2;
  for (char c2 : str_2) {
    elements_in_2.insert(c2);
  }

  for (char c3 : str_3) {
    bool in_1 = elements_in_1.find(c3) != elements_in_1.end();
    bool in_2 = elements_in_2.find(c3) != elements_in_2.end();
    if (in_1 && in_2) {
      return c3;
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
  std::string line_1, line_2, line_3;
  std::ifstream input_file("resources/input.txt");
  int badge_priority_sum = 0;
  while (
    getline(input_file, line_1) &&
    getline(input_file, line_2) &&
    getline(input_file, line_3))
  {
    char duplicate_item = find_common_element(line_1, line_2, line_3);
    badge_priority_sum += get_item_priority(duplicate_item);
  }

  std::cout << "Sum of priorities of badges: " << badge_priority_sum <<
    std::endl;
  return 0;
}
