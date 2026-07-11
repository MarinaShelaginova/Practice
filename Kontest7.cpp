#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    vector<int> parent(n + 1, -1);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    
    pq.push({0, 1});
    
    while (!pq.empty()) {
        ll d = pq.top().first;
        int v = pq.top().second; 
        pq.pop();

        if (d != dist[v]) continue;

        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i].first;
            ll w = g[v][i].second; 
            if (dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                parent[to] = v;
                pq.push({dist[to], to});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << endl;
        return 0;
    }
    
    vector<int> ans;
    int v = n;
    while (v != -1) {
        ans.push_back(v);
        v = parent[v];
    }

    reverse(ans.begin(), ans.end());
    
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}