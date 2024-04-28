#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <class T>
struct bellman_ford {
 public:
  int n;
  const T INF = numeric_limits<T>::max();
  vector<tuple<int, int, T>> e;
  vector<T> dist;
  vector<bool> negative;

  bellman_ford() {}
  bellman_ford(int n) {
    init(n);
  }

  void init(int n) {
    this->n = n;
    dist.assign(n, INF);
    negative.assign(n, false);
  }

  // 頂点 u から v に辺を張る
  void add_edge(int u, int v, T cost) {
    e.emplace_back(u, v, cost);
  }

  // 頂点 s からの最短経路を求める
  void work(int s) {
    dist[s] = 0;
    // 最短経路更新
    for (int itr = 0; itr < n - 1; itr++) {
      for (auto [u, v, cost] : e) {
        if (dist[u] != INF) {
          if (dist[v] > dist[u] + cost) {
            dist[v] = dist[u] + cost;
          }
        }
      }
    }

    // 負閉路判定
    for (int itr = 0; itr < n; itr++) {
      for (auto [u, v, cost] : e) {
        if (dist[u] != INF) {
          if (dist[v] > dist[u] + cost) {
            negative[v] = true;
          }
        }
        // 負閉路が存在
        if (negative[u]) {
          negative[v] = true;
        }
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  
  return 0;
}
