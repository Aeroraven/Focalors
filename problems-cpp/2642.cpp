#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Target {
    int v, w;
    bool operator <(const Target& t) const{
        return w > t.w;
    }
};

class Graph {
public:
    std::vector<std::vector<int>> dist;
    std::vector <std::vector<std::pair<int, int>>> ed;
    static constexpr const int MAXV = 200000000;
    int n = 0;

    Graph(int n, vector<vector<int>>& edges) {
        dist.reserve(n);
        dist.resize(n);
        ed.reserve(n);
        ed.resize(n);
        for (const auto& e : edges) {
            ed[e[0]].push_back({ e[1],e[2] });
        }
        for (int i = 0; i < n; i++) {
            dist[i].reserve(n);
            dist[i].resize(n);
            for (int j = 0; j < n; j++) {
                dist[i][j] = MAXV;
            }
            dist[i][i] = 0;
        }
        this->n = n;
    }
    void update(int s) {
        for (int j = 0; j < n; j++) {
            dist[s][j] = MAXV;
        }
        dist[s][s] = 0;
        vector<int> vis(n);
        priority_queue<Target> q;
        q.push({ s,0 });
        while (!q.empty()) {
            auto tp = q.top();
            q.pop();
            if (vis[tp.v])continue;
            vis[tp.v] = 1;
            for (const auto& e : ed[tp.v]) {
                if (dist[s][tp.v] + e.second < dist[s][e.first]) {
                    dist[s][e.first] = e.second + dist[s][tp.v];
                    q.push({ e.first,dist[s][e.first] });
                }
            }
        }
    }

    void addEdge(vector<int> edge) {
        ed[edge[0]].push_back({ edge[1],edge[2] });
    }

    int shortestPath(int node1, int node2) {
        update(node1);
        if (dist[node1][node2] >= MAXV)return -1;
        return dist[node1][node2];
    }
};

int main() {
    vector<vector<int>> v = { {0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
    Graph s(4, v);
    cout << s.shortestPath(3, 2) << endl;
    cout << s.shortestPath(0, 3) << endl;
    s.addEdge({ 1, 3, 4 });
    cout << s.shortestPath(0, 3) << endl;
    return 0;
}