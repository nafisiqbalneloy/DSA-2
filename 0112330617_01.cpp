#include <bits/stdc++.h>
using namespace std;

class SubArray {
public:
    int months;
    int leftIndex;
    int rightIndex;

    SubArray(int m, int l, int r) : months(m), leftIndex(l), rightIndex(r) {}
};

SubArray findCrossing(vector<int> arr, int left, int right) {
    int mid = (left + right) / 2;   
    int leftIndex = mid;
    int rightIndex = mid + 1;

    int leftCount = 0;
    for (int i = mid; i >= left; i--) {  
        if (arr[i] > 0) {
            leftCount++;
            leftIndex = i;
        } 
        else break;
    }

    int rightCount = 0;
    for (int i = mid + 1; i <= right; i++) {
        if (arr[i] > 0) {
            rightCount++;
            rightIndex = i;
        }
         else break;
    }

    return SubArray(leftCount + rightCount, leftIndex, rightIndex);
}

SubArray longestProfit(vector<int> arr, int left, int right) {
    if (left == right) {
        if (arr[left] > 0)
            return SubArray(1, left, right);
        else
            return SubArray(0, left, right);
    }

    int mid = (left + right) / 2;   
    SubArray leftRes = longestProfit(arr, left, mid);       
    SubArray rightRes = longestProfit(arr, mid + 1, right); 
    SubArray crossRes = findCrossing(arr, left, right);

    if (leftRes.months >= rightRes.months && leftRes.months >= crossRes.months)
        return leftRes;
    else if (rightRes.months >= leftRes.months && rightRes.months >= crossRes.months)
        return rightRes;
    else
        return crossRes;
}

int main() {
    vector<int> profit = {3, -1, 9, -2, 4, 3, 1, -5, 3, 2};
    SubArray result = longestProfit(profit, 0, profit.size() - 1);
    cout << "Longest consecutive profit period: "
         << result.months << " months, from month "
         << result.leftIndex + 1 << " to " << result.rightIndex + 1 << endl;
}
