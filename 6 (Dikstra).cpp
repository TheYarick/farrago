#include <iostream>
#include <vector>
 
using namespace std;
 
const int INF = 1000000000;
 
int main() {
    int n, s, f;
    cin >> n >> s >> f;
    --s; --f;
    vector < vector < pair<int,int> > > graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int m;
            cin >> m;
            if (i != j && m != -1)
                graph[i].push_back(make_pair(j, m));
        }
    }
 
    vector <int> dist(n, INF),  parent(n);
    dist[s] = 0; parent[s] = -1;
    vector <bool> coloured(n);
    for (int i = 0; i < n; ++i) {
        int next_vert = -1;
        for (int j = 0; j < n; ++j)
            if (!coloured[j] && (next_vert == -1 || dist[j] < dist[next_vert]))
                next_vert = j;
        if (dist[next_vert] == INF)
            break;
        coloured[next_vert] = true;
 
        for (size_t j = 0; j < graph[next_vert].size(); ++j) {
            int to = graph[next_vert][j].first,
                len = graph[next_vert][j].second;
            if (dist[next_vert] + len < dist[to]) {
                dist[to] = dist[next_vert] + len;
                parent[to] = next_vert;
            }
        }
    }
    if (dist[f] == INF) {
        cout << -1;
        return 0;
    }
    vector <int> way;
    int curr_node = f;
    while (curr_node != -1) {
        way.push_back(curr_node);
        curr_node = parent[curr_node];
    }
    int waylen = way.size();
    for (int i = waylen - 1; i > -1; --i)
        cout << way[i] + 1 << ' ';
    return 0;
 
}