#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/* combination
    返り値 : vector<vector<T>>
    組み合わせnCkを計算する
*/
template <class T>
vector<vector<T>> combination(int n, int k) {
  vector<vector<T>> ret(n + 1, vector<T>(k + 1));
  if (n < 0 || k < 0 || n < k) {
    return ret;
  }
  for (int i = 0; i <= n; i++) {
    ret[i][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= min(i, k); j++) {
      ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  
  return 0;
}
