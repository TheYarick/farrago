#include <iostream>
#include <vector>
 
using namespace std;
 
const int INF = 30000;
 
struct edge {
    int e_start;
    int e_finis;
    int e_mass;
};
 
int main() {
    int V, E;
    cin >> V >> E;
    vector <edge> graph;
    for (int i = 0; i < E; ++i) {
        edge temp;
        cin >> temp.e_start >> temp.e_finis >> temp.e_mass;
        --temp.e_start; --temp.e_finis;
        graph.push_back(temp);
    }
    vector <int> dist(V, INF);
    dist[0] = 0;
	bool change_happened = true;
    for (; change_happened;) {
        change_happened = false;
        for (int j = 0; j < E; ++j)
            if (dist[graph[j].e_start] < INF)
                if (dist[graph[j].e_finis] > dist[graph[j].e_start] + graph[j].e_mass) {
                    dist[graph[j].e_finis] = dist[graph[j].e_start] + graph[j].e_mass;
                    change_happened = true;
                }
    }
    for (int i = 0; i < V; ++i)
        cout << dist[i] << ' ';
    return 0;
}