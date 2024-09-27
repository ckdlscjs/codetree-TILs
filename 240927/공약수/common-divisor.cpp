#include <bits/stdc++.h>
using namespace std;
const int MaxN = 3;
int arr[MaxN];
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    int large;
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        large = std::max(large, arr[i]);
    }
        
    for(int i = 1; i <= large; i++)
    {
        if([=]()->bool{
            for(int j = 0; j < n; j++)
            {
                if(arr[j] % i)
                    return false;
            }
            return true;
        }())
        std::cout << i <<'\n';
    }

    return 0;
}