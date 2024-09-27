#include <bits/stdc++.h>
using namespace std;

int n;
const int MaxN = 100005;
int arr[MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int ans = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        right = std::max(right, arr[i]);
    }
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        bool cur = false;
        for (int i = 0; i < n; i++) 
        {
            if (arr[i] > mid && !cur) 
            {
                cnt++;
                cur = true;
            } 
            else if (arr[i] <= mid) 
            {
                cur = false;
            }
        }

        if (cnt >= ans) 
        {
            ans = cnt;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans;
    return 0;
}