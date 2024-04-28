#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/* compress2D
    (x1, y1), (x2, y2)といる二点で表されるもの(長方形や直線など)について、行か列の片方(x1とx2 or y1とy2)を座標圧縮する
    返り値 : res[i] = c1, c2 内で i 番目に小さい値.
            c1[i] = c1[i] が元の c1, c2 の中で何番目に小さいか.
            c2[i] = c2[i] が元の c1, c2 の中で何番目に小さいか.
    計算量 : O(NlogN)
*/
template <class T>
vector<T> compress2D(vector<T> &c1, vector<T> &c2) {
  vector<T> res;
  int n = (int)c1.size();
  for (int i = 0; i < n; i++) {
    for (T d = 0; d <= 1; d++) { // その位置と、一つ隣を確保(隣を確保しないと空白が埋まってしまうことがある)
      T tc1 = c1[i] + d;
      T tc2 = c2[i] + d;
      res.push_back(tc1);
      res.push_back(tc2);
    }
  }
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  for (int i = 0; i < n; i++) {
    c1[i] = lower_bound(res.begin(), res.end(), c1[i]) - res.begin();
    c2[i] = lower_bound(res.begin(), res.end(), c2[i]) - res.begin();
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  
  return 0;
}
