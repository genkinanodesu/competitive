struct UnionFind {
  vector<long long> data;
  UnionFind(long long size) : data(size, -1) { }
  bool unionSet(long long x, long long y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(long long x, long long y) {
    return root(x) == root(y);
  }
  long long root(long long x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  long long size(long long x) {
    return -data[root(x)];
  }
};
