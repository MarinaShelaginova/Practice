#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m, k;
    cin >> n >> m >> k;
    --k;
    
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    ll s = k;
    vector<ll> d(n, -1);
    d[s] = 0;
    queue<ll> q;
    q.push(s);
    
    while (q.size()) {
        ll u = q.front();
        q.pop();
        for (ll v : g[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    
    for (ll i = 0; i < n; ++i) {
        cout << d[i] << " ";
    }
    cout << '\n';
    
    return 0;
}