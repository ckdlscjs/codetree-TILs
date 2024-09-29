#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100005;
int arr[MaxN];

int countClusters(int n, int height) {
    int cnt = 0;
    bool inCluster = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] > height) {
            if (!inCluster) {
                cnt++;
                inCluster = true;
            }
        } else {
            inCluster = false;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int maxHeight = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxHeight = max(maxHeight, arr[i]);
    }

    int left = 0, right = maxHeight;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int clusters = countClusters(n, mid);
        int clustersLower = countClusters(n, mid - 1);
        
        ans = max(ans, max(clusters, clustersLower));

        if (clustersLower > clusters) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}