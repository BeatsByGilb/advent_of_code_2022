#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
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

/// Gets the outcome of a single round
Outcome play_round(Shape opponent_shape, Shape my_shape)
{
  switch (opponent_shape) {
    case Shape::kRock:
      switch (my_shape) {
        case Shape::kRock: return Outcome::kDraw;
        case Shape::kPaper: return Outcome::kWin;
        case Shape::kScissors: return Outcome::kLose;
        default: throw std::runtime_error("Unknown shape");
      }
    case Shape::kPaper:
      switch (my_shape) {
        case Shape::kRock: return Outcome::kLose;
        case Shape::kPaper: return Outcome::kDraw;
        case Shape::kScissors: return Outcome::kWin;
        default: throw std::runtime_error("Unknown shape");
      }
    case Shape::kScissors:
      switch (my_shape) {
        case Shape::kRock: return Outcome::kWin;
        case Shape::kPaper: return Outcome::kLose;
        case Shape::kScissors: return Outcome::kDraw;
        default: throw std::runtime_error("Unknown shape");
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
  std::map<char, Shape> my_encoding = {
    {'X', Shape::kRock},
    {'Y', Shape::kPaper},
    {'Z', Shape::kScissors}
  };

  std::string line;
  std::ifstream input_file("resources/input.txt");
  int total_score = 0;
  while (getline(input_file, line)) {
    Shape opponent_shape = opponent_encoding[line[0]];
    Shape my_shape = my_encoding[line[2]];
    Outcome outcome = play_round(opponent_shape, my_shape);
    int round_score = score_for_shape(my_shape) + score_for_outcome(outcome); 
    total_score += round_score;
  }

  std::cout << "Total score: " << total_score << std::endl;
  return 0;
}
