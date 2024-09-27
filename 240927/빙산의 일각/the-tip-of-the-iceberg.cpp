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
    for(int i = 0; i < n; i++)
        std::cin >> arr[i];
    int ans = 0;
    int left = 0;
    int right = 1000000000;
    while(left+1 < right)
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
        if(cnt >= ans)
        {
            right = mid-1;
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