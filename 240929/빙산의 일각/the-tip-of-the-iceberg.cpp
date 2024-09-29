#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countClusters(const vector<int>& heights, int waterLevel) {
    int clusters = 0;
    bool inCluster = false;
    for (int height : heights) {
        if (height > waterLevel) {
            if (!inCluster) {
                clusters++;
                inCluster = true;
            }
        } else {
            inCluster = false;
        }
    }
    return clusters;
}

int maxClusters(const vector<int>& heights) {
    int left = 0, right = *max_element(heights.begin(), heights.end());
    int maxCount = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int clusterCount = countClusters(heights, mid);
        
        maxCount = max(maxCount, clusterCount);
        
        int leftCount = countClusters(heights, mid - 1);
        int rightCount = countClusters(heights, mid + 1);
        
        if (leftCount >= rightCount) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return maxCount;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    
    cout << maxClusters(heights) << endl;
    
    return 0;
}