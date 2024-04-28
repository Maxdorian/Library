#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename type = unsigned int, int B = 32>
struct binary_trie {
 private:
  struct node {
    int cnt;
    node* child[2];
    node() : cnt(0), child{nullptr, nullptr} {}
  };

  int get_size(Node *t) const {return t ? t -> cnt : 0;}

  node* add(node* t, type val, int b = B - 1) {
    if (!t) t = new node;
    t -> cnt++;
    if (b < 0) return t;
    int bin = (val >> (type)b) & (type)1;
    t -> child[bin] = add(t -> child[bin], val, b - 1);
    return t;
  }

  node* sub(node* t, type val, int b = B - 1) {
    assert(t);
    t -> cnt--;
    if (t -> cnt == 0) return nullptr;
    if (b < 0) return t;
    int bin = (val >> (type)b) & (type)1;
    t -> child[bin] = sub(t -> child[bin], val, b - 1);
    return t;
  }

  // 全体を val で xor 取ったときの最小値
  type get_min(node* t, type val, int b = B - 1) const {
    assert(t);
    if (b < 0) return 0;
    int bin = (val >> (type)b) & (type)1;
    bin ^= (!t -> child[bin]);
    return get_min(t -> child[bin], val, b - 1) | ((type)bin << (type)b);
  }

  // 全体を val で xor 取ったときに k 番目 (1-indexed) に小さい値
  type get_kth(node* t, type val, int k, int b = B - 1) const {
    assert(t);
    if (b < 0) return 0;
    int bin = (val >> (type)b) & (type)1;
    if (get_size(t -> child[bin]) < k) {
      k -= get_size(t -> child[bin]);
      bin ^= 1;
    }
    return get_kth(t -> child[bin], val, k, b - 1) | ((type)bin << (type)b);
  }

  node* root;

 public:
  binary_trie() : root(nullptr) {}
  int size() const {
    return get_size(root);
  }
  bool empty() const {
    return !root;
  }
  void insert(type val) {
    root = add(root, val);
  }
  void erase(type val) {
    root = sub(root, val);
  }

  // xor 取った後の値ではなく、集合内にある値がそのまま返る
  type max_element(type XOR = 0) const {
    return get_min(root, ~XOR);
  }
  type min_element(type XOR = 0) const {
    return get_min(root, XOR);
  }

  // 0-indexed
  type get_kth(int k, type XOR = 0) const {
    assert(0 <= k and k < size());
    return get_kth(root, XOR, k + 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  
  return 0;
}
