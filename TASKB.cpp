#include <iostream>

const int inf = 10004321;

int pivot(int* ch, int nach, int kon) {
  int mid = (nach + kon) / 2;
  std::swap(ch[mid], ch[nach + 1]);
  if (ch[kon] < ch[nach]) {
    std::swap(ch[kon], ch[nach]);
  }
  if (ch[kon] < ch[nach + 1]) {
    std::swap(ch[kon], ch[nach + 1]);
  }
  if (ch[nach + 1] < ch[nach]) {
    std::swap(ch[nach + 1], ch[nach]);
  }
  int l = nach + 1, r = kon, piv = ch[nach + 1];
  while (true) {
    while (ch[++l] < piv)
      ;
    while (ch[--r] > piv)
      ;
    if (l > r) break;
    std::swap(ch[l], ch[r]);
  }
  ch[nach + 1] = ch[r];
  ch[r] = piv;
  return r;
}

int cth(int* ch, int len, int k) {
  int l = 1, r = len;
  while (r > l + 1) {
    int temp = pivot(ch, l, r);
    if (temp == k) {
      return ch[temp];
    }
    if (temp >= k) {
      r = temp - 1;
    }
    if (temp <= k) {
      l = temp;
    }
  }
  if (r == l + 1 && ch[r] < ch[l]) std::swap(ch[l], ch[r]);
  return ch[k];
}

int main() {
  int n, k, a0, a1;
  std::cin >> n >> k >> a0 >> a1;
  int* arr = new int[size_t(n + 1)];
  arr[0] = 0;
  arr[1] = a0;
  arr[2] = a1;
  for (int i = 3; i <= n; ++i) {
    arr[i] = (arr[i - 1] * 123 + arr[i - 2] * 45) % inf;
  }

  std::cout << cth(arr, n, k);
  delete[] arr;
  return 0;
}