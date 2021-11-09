#include <array>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> findNumOfValidWords(std::vector<std::string> &words,
                                       std::vector<std::string> &puzzles) {
    // cluster words into bucket, bucket[i] has words that contain ('a' + i)
    std::array<std::vector<unsigned>, 26> letter_to_word_signature;
    for (const auto &word : words) {
      unsigned word_signature = 0;
      for (auto letter : word) {
        word_signature |= (1 << (letter - 'a'));
      }
      for (size_t pos = 0; pos < letter_to_word_signature.size(); ++pos) {
        if (word_signature & (1 << pos)) {  // <-- check if contains ('a' + i)
          letter_to_word_signature[pos].push_back(word_signature);
        }
      }
    }

    std::vector<int> result(puzzles.size());
    for (size_t pos = 0; pos < puzzles.size(); ++pos) {
      unsigned puzzle_signature = 0;
      for (auto letter : puzzles[pos]) {
        puzzle_signature |= (1 << (letter - 'a'));
      }
      for (auto word_signature : letter_to_word_signature[static_cast<size_t>(
               puzzles[pos][0] - 'a')]) {
        if (word_signature & (~puzzle_signature)) {
          continue;
        }
        ++result[pos];
      }
    }

    return result;
  }
};
