#include <vector>
class Solution {
  void floodFillRecursive(std::vector<std::vector<int>>& image, const size_t i,
                          const size_t j, const int oldColor,
                          const int newColor) {
    if (oldColor != image[i][j]) {
      return;
    }
    image[i][j] = newColor;

    if (j + 1 != image.front().size()) {
      floodFillRecursive(image, i, j + 1, oldColor, newColor);
    }
    if (j != 0) {
      floodFillRecursive(image, i, j - 1, oldColor, newColor);
    }
    if (i != 0) {
      floodFillRecursive(image, i - 1, j, oldColor, newColor);
    }
    if (i + 1 != image.size()) {
      floodFillRecursive(image, i + 1, j, oldColor, newColor);
    }
  }

 public:
  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image,
                                          size_t sr, size_t sc, int newColor) {
    if (image[sr][sc] != newColor) {
      floodFillRecursive(image, sr, sc, image[sr][sc], newColor);
    }
    return image;
  }
};
