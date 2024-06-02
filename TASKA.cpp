#include <iostream>

bool BinarySearch(const long long* begin, const long long* end,
                  long long target) {
  size_t r = size_t(end - begin), l = 0;
  while (r > l + 1) {
    auto mid = (l + r) / 2;
    if (*(begin + mid) <= target) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return (*(begin + l)) == target;
}

int main() {
  size_t n, q;
  std::cin >> n;
  long long* arr = new long long[n];
  for (size_t i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  std::cin >> q;
  bool* ans = new bool[q];
  for (size_t i = 0; i < q; ++i) {
    size_t i1, j1;
    long long t;
    std::cin >> i1 >> j1 >> t;
    ans[i] = BinarySearch(arr + i1, arr + j1, t);
  }
  for (size_t i = 0; i < q; ++i) {
    std::cout << (ans[i] ? "YES" : "NO") << '\n';
  }
  delete[] arr;
  delete[] ans;
  return 0;
}
