#include <iostream>

using namespace std;

int main() {
    long long n;
    int k;
    cin >> n >> k;
    
    long long st = 1;
    for (int i = 0; i < k; i++) {
        st = st * 2;
    }
    
    long long max_x = n / st;
    
    if (max_x == 0) {
        cout << -1 << endl;
        return 0;
    }

    if (max_x % 2 == 0) {
        max_x = max_x - 1;
    }
    
    long long answer = max_x * st;
    cout << answer << endl;
    
    return 0;
}