#include <bits/stdc++.h>
using namespace std;

int n;
const int MaxN = 100005;
int arr[MaxN];

int countClusters(int height) {
    int cnt = 0;
    bool cur = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] > height && !cur) {
            cnt++;
            cur = true;
        } else if (arr[i] <= height) {
            cur = false;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    int maxHeight = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxHeight = max(maxHeight, arr[i]);
    }

    int left = 0, right = maxHeight, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int clusters = countClusters(mid);
        
        if (clusters >= ans) {
            ans = clusters;
            left = mid + 1;  // 더 높은 높이에서 시도
        } else {
            right = mid - 1;  // 더 낮은 높이에서 시도
        }
    }

    cout << ans << "\n";
    return 0;
}