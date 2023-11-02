#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

enum class Shape {
  kRock,
  kPaper,
  kScissors,
};

enum class Outcome {
  kWin,
  kLose,
  kDraw,
};

/// Determines which shape you should play to get the desired outcome
Shape shape_to_get_outcome(Shape opponent_shape, Outcome desired_outcome)
{
  switch (opponent_shape) {
    case Shape::kRock:
      switch (desired_outcome) {
        case Outcome::kWin: return Shape::kPaper;
        case Outcome::kLose: return Shape::kScissors;
        case Outcome::kDraw: return Shape::kRock;
        default: throw std::runtime_error("Unknown outcome");
      }
    case Shape::kPaper:
      switch (desired_outcome) {
        case Outcome::kWin: return Shape::kScissors;
        case Outcome::kLose: return Shape::kRock;
        case Outcome::kDraw: return Shape::kPaper;
        default: throw std::runtime_error("Unknown outcome");
      }
    case Shape::kScissors:
      switch (desired_outcome) {
        case Outcome::kWin: return Shape::kRock;
        case Outcome::kLose: return Shape::kPaper;
        case Outcome::kDraw: return Shape::kScissors;
        default: throw std::runtime_error("Unknown outcome");
      }
    default: throw std::runtime_error("Unknown shape");
  }
}

/// Gets the score obtained for playing the given shape
int score_for_shape(Shape shape)
{
  switch (shape) {
    case Shape::kRock: return 1;
    case Shape::kPaper: return 2;
    case Shape::kScissors: return 3;
    default: throw std::runtime_error("Unknown shape");
  }
}

/// Gets the score obtained for achieving the given outcome
int score_for_outcome(Outcome outcome)
{
  switch (outcome) {
    case Outcome::kWin: return 6;
    case Outcome::kLose: return 0;
    case Outcome::kDraw: return 3;
    default: throw std::runtime_error("Unknown outcome");
  }
}

int main()
{
  // Maps for decoding opponent moves and my moves
  std::map<char, Shape> opponent_encoding = {
    {'A', Shape::kRock},
    {'B', Shape::kPaper},
    {'C', Shape::kScissors}
  };
  std::map<char, Outcome> outcome_encoding = {
    {'X', Outcome::kLose},
    {'Y', Outcome::kDraw},
    {'Z', Outcome::kWin}
  };

  std::string line;
  std::ifstream input_file("resources/input.txt");
  int total_score = 0;
  while (getline(input_file, line)) {
    Shape opponent_shape = opponent_encoding[line[0]];
    Outcome desired_outcome = outcome_encoding[line[2]];
    Shape my_shape = shape_to_get_outcome(opponent_shape, desired_outcome);
    int round_score =
      score_for_shape(my_shape) + score_for_outcome(desired_outcome); 
    total_score += round_score;
  }

  std::cout << "Total score: " << total_score << std::endl;
  return 0;
}
