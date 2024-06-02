#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

const int inf = 10004321;

struct MinQueue {
  MinQueue() : stacks(new std::stack<std::pair<int, int>>[2]) {}

  MinQueue(const MinQueue& tmp) : MinQueue() {
    stacks[0] = tmp.stacks[0];
    stacks[1] = tmp.stacks[1];
  }

  MinQueue& operator=(const MinQueue& tmp) {
    stacks[0] = tmp.stacks[0];
    stacks[1] = tmp.stacks[1];
    return *this;
  }

  size_t size() { return stacks[0].size() + stacks[1].size(); }

  void add(int x, int num = 1) {
    if (num == 1 && stacks[0].empty()) {
      stacks[0].push({x, x});
      return;
    }

    if (stacks[num].empty() || x < stacks[num].top().second) {
      stacks[num].push({x, x});
    } else {
      stacks[num].push({x, stacks[num].top().second});
    }
  }

  int del() {
    if (size() == 0) {
      return -1;
    }
    int tmp1 = stacks[0].top().first;
    stacks[0].pop();
    if (stacks[0].empty()) {
      while (!stacks[1].empty()) {
        auto tmp = stacks[1].top();
        add(tmp.first, 0);
        stacks[1].pop();
      }
    }
    return tmp1;
  }

  int front() { return (stacks[0].empty() ? -1 : stacks[0].top().first); }

  void clear() {
    while (!stacks[0].empty()) {
      stacks[0].pop();
    }
    while (!stacks[1].empty()) {
      stacks[1].pop();
    }
  }

  int min() {
    if (size() == 0) return -1;
    if (stacks[1].empty() || stacks[1].top().second > stacks[0].top().second) {
      return stacks[0].top().second;
    } else {
      return stacks[1].top().second;
    }
  }

  ~MinQueue() { delete[] stacks; }

 private:
  std::stack<std::pair<int, int>>* stacks;
};

int main() {
  int n;
  std::cin >> n;
  MinQueue mq;

  for (int i = 0; i < n; ++i) {
    std::string cmd;
    std::cin >> cmd;
    if (cmd == "enqueue") {
      int x;
      std::cin >> x;
      mq.add(x);
      std::cout << "ok\n";
    } else if (cmd == "dequeue") {
      auto kk = mq.del();
      if (kk == -1) {
        std::cout << "error\n";
      } else {
        std::cout << kk << '\n';
      }
    } else if (cmd == "front") {
      if (mq.front() == -1) {
        std::cout << "error\n";
      } else
        std::cout << mq.front() << '\n';
    } else if (cmd == "size") {
      std::cout << mq.size() << '\n';
    } else if (cmd == "clear") {
      mq.clear();
      std::cout << "ok\n";
    } else if (cmd == "min") {
      if (mq.size() == 0) {
        std::cout << "error\n";
      } else
        std::cout << mq.min() << '\n';
    } else {
      std::cout << "error\n";
    }
  }

  return 0;
}