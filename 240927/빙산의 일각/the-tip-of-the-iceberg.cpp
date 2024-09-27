#include <bits/stdc++.h>
using namespace std;
int n;
const int MaxN = 100005;
int arr[MaxN];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    int ans = 0;
    int left = 1;
    int right = 10000000000;
    for(int i = 0; i < n; i++)
        std::cin >> arr[i];
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int cnt = 0;
        bool cur = false;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > mid && !cur)
            {
                cnt++;
                cur = true;
            }
            else if(arr[i] <= mid)
            {
                cur = false;
            }
        }
        if(cnt == ans)
        {
            right = mid-1;
        }
        else if(cnt > ans)
        {
            right = mid;
            ans = cnt;
        }
        else if(cnt < ans)
        {
            left = mid+1;
        }
    }
    std::cout << ans;
    return 0;
}