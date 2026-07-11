#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    priority_queue<int> pq_max;
    
    priority_queue<int, vector<int>, greater<int>> pq_min;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if (pq_max.empty() || x <= pq_max.top()) {
            pq_max.push(x);
        } 
        else {
            pq_min.push(x);
        }

        if (pq_max.size() > pq_min.size() + 1) {
            pq_min.push(pq_max.top());
            pq_max.pop();
        }
        if (pq_min.size() > pq_max.size()) {
            pq_max.push(pq_min.top());
            pq_min.pop();
        }

        cout << pq_max.top() << "\n";
    }
    
    return 0;
}