#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/* compress
    x を座標圧縮して書き換える
    返り値 : res[i] = x 内で i 番目に小さい値. 
            x[i] = x[i] が元の x の中で何番目に小さいか.
    計算量 : O(NlogN)
*/
template <class T>
vector<T> compress(vector<T> &x) {
  vector<T> res = x;
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  for (int i = 0; i < (int)x.size(); i++) {
    x[i] = lower_bound(res.begin(), res.end(), x[i]) - res.begin();
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  
  return 0;
}
