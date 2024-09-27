#include <bits/stdc++.h>
using namespace std;

int n;
const int MaxN = 100005;
bool under[MaxN];
std::pair<int, int> arr[MaxN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> arr[i].second;
        arr[i].first = i;
    }
    std::stable_sort(arr+1, arr+n+1, [](const std::pair<int, int>& a, const std::pair<int, int>& b)
    {
        return a.second < b.second;
    });
    under[0] = under[n+1] = true;
    int ans = 1;
    int cur = 1;
    for(int i = 1; i <= n; i++)
    {
        int idx = arr[i].first;
        under[idx] = true;
        if(!under[idx-1] && !under[idx+1])
            cur++;
        else if(under[idx-1] && under[idx+1])
            cur--;
        if(i == n || arr[i+1].second > arr[i].second)
        {
            ans = std::max(ans, cur);
        }
    }
    std::cout << ans;
    return 0;
}