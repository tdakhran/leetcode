#include <vector>

class ProductOfNumbers {
  std::vector<int> products{1};
  std::vector<int> zeros{0};

 public:
  ProductOfNumbers() {}

  void add(int num) {
    products.push_back(products.back() ? products.back() * num : num);
    zeros.push_back(zeros.back() + (num == 0));
  }

  int getProduct(int k) {
    size_t index = zeros.size() - static_cast<size_t>(k) - 1;
    if (zeros.back() > zeros[index]) {
      return 0;
    }
    if (products[index] == 0) {
      return products.back();
    }
    return products.back() / products[index];
  }
};
