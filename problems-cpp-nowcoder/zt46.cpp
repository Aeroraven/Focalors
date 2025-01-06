#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<vector<int>> ed;
vector<int> vis;
vector<int> blksza = {0};
int blk = 0;
string occp;

void search(int u) {
  if (vis[u])
    return;
  vector<int> q;
  q.push_back(u);
  vis[u] = ++blk;
  int blksz = 1;
  while (!q.empty()) {
    auto f = q.back();
    q.pop_back();
    auto psz = ed[f].size();
    for (int i = 0; i < psz; i++) {
      int v = ed[f][i];
      if (!vis[v] && occp[v] == '1') {
        q.push_back(v);
        vis[v] = vis[u];
        blksz += 1;
      }
    }
  }
  blksza.push_back(blksz);
}

int main() {
  int n, m;
  cin >> n >> m;
  cin >> occp;
  ed.resize(n);
  vis.resize(n);

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    if (occp[i] == '1') {
      search(i);
    }
  }
  long long value = 0, basevalue = 0;
  int tooc = -1;
  for (int i = 0; i < blksza.size(); i++) {
    long long blksz = blksza[i];
    value += blksz * (blksz - 1) / 2;
  }
  basevalue = value;
  for (int i = 0; i < n; i++) {
    if (occp[i] == '0') {
      if (tooc == -1)
        tooc = i;
      unordered_set<int> dr;
      for (auto v : ed[i]) {
        if (occp[v] == '1')
          dr.insert(vis[v]);
      }
      long long aggBlkSz = 0;
      long long curVal = basevalue;
      for (auto &blk : dr) {
        long long blksz = blksza[blk];
        aggBlkSz += blksz;
        curVal -= blksz * (blksz - 1) / 2;
      }
      aggBlkSz++;
      curVal += aggBlkSz * (aggBlkSz - 1) / 2;
      if (curVal > value) {
        value = curVal;
        tooc = i;
      }
    }
  }
  printf("%d %lld", tooc + 1, value);
}
