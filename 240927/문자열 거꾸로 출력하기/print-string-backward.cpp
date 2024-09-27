#include <bits/stdc++.h>
using namespace std;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::string str;
    while(std::cin >> str && str != "END")
    {
        std::reverse(str.begin(), str.end());
        std::cout << str <<'\n';
    }
    return 0;
}