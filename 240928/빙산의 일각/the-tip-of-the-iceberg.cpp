#include <bits/stdc++.h>
using namespace std;

int n;
const int MaxN = 100005;
int arr[MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // 입력 받기
    cin >> n;
    int ans = 0;
    int left = 0;
    int right = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        right = std::max(right, arr[i]);
    }

    // 이분 탐색 시작
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        bool cur = false;

        // 현재 높이(mid)를 기준으로 덩어리 개수 세기
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid && !cur) {
                cnt++;
                cur = true;
            } else if (arr[i] <= mid) {
                cur = false;
            }
        }

        // 덩어리 개수가 더 클 때 최대값 갱신
        if (cnt >= ans) {
            ans = cnt;
            left = mid + 1;  // 더 높은 높이에서 시도
        } else {
            right = mid - 1;  // 더 낮은 높이에서 시도
        }
    }

    cout << ans;
    return 0;
}