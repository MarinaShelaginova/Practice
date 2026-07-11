#include <iostream>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    ll fact = 1;
    for (int i = 2; i <= n - 1; i++) {
        fact = (fact * i) % MOD;
    }

    ll num = (MOD + 1) / 2;
    ll ans = (fact * num) % MOD;
    
    cout << ans << '\n';
    
    return 0;
}