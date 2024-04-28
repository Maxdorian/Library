#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// 負の数の mod も対応している
template <class T>
inline T mod(T a, T m) {
  return (a % m + m) % m;
}

// extend_gcd
// a*x + b*y = gcd(a, b)を解く
// 返り値 : aとbの最大公約数
template <class T>
T extend_gcd(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
  }
}

// 中国剰余定理
// i = 0, 1, ... , n - 1 について, x = b[i] (mod m[i]) が成り立つ.
// 返り値は (r, m). このとき, x = r (mod m) が成り立つ.
// 解なしのとき, (0, -1) を返す.
template <class T>
pair<T, T> chinese_rem(const vector<T> &b, const vector<T> &m) {
  T r = 0, M = 1;
  for (int i = 0; i < (int)b.size(); i++) {
    T p, q;
    T d = extend_gcd(M, m[i], p, q); // p は m1/d の逆元 (mod m2/d). これは, m1*p + m2*q = d, (m1/d)*p + (m2/d)*q = 1 より, (mod m2/d)をとると (m1/d)*p = 1 (mod m2/d) となるため.
    if ((b[i] - r) % d != 0) {
      return make_pair(0, -1);
    }
    T tmp = (b[i] - r) / d * p % (m[i] / d);
    r += M * tmp;
    M *= m[i] / d;
  }
  return make_pair(mod(r, M), M);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  
  return 0;
}
