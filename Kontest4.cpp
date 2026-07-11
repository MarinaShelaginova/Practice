#include <iostream>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum = (sum + x % MOD + MOD) % MOD;
    }
    
    ll ans = sum;
    for (int i = 0; i < n - 1; i++) {
        ans = (ans * 2) % MOD;
    }
    
    ans = (ans % MOD + MOD) % MOD;
    
    cout << ans << endl;
    
    return 0;
}