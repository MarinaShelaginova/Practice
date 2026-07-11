#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<long long> dp(N + 1);
    dp[1] = 0;
    
    for (int i = 2; i <= N; i++) {
        dp[i] = i + dp[i - 1];
        
        if (i % 2 == 0) {
            dp[i] = min(dp[i], (long long)i + dp[i / 2]);
        }

        if (i % 3 == 0) {
            dp[i] = min(dp[i], (long long)i + dp[i / 3]);
        }
    }
    
    cout << dp[N] << endl;
    
    return 0;
}