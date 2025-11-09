#include <bits/stdc++.h>
using namespace std;

class SubArray {
public:
    int sum;
    int leftIndex;
    int rightIndex;

    SubArray(int s, int l, int r) : sum(s), leftIndex(l), rightIndex(r) {}
};

SubArray findCrossing(vector<int> arr, int left, int right) {
    int mid = (left + right) / 2;
    if (mid - 1 >= left && mid + 1 <= right) {
        int total = arr[mid - 1] + arr[mid] + arr[mid + 1];
        return SubArray(total, mid - 1, mid + 1);
    }
    return SubArray(INT_MIN, left, right);
}

SubArray max3Day(vector<int> arr, int left, int right) {
    if (right - left + 1 < 3) return SubArray(INT_MIN, left, right);

    if (right - left + 1 == 3) {
        int total = arr[left] + arr[left + 1] + arr[right];
        return SubArray(total, left, right);
    }

    int mid = (left + right) / 2;
    SubArray leftRes = max3Day(arr, left, mid);
    SubArray rightRes = max3Day(arr, mid + 1, right);
    SubArray crossRes = findCrossing(arr, left, right);

    if (leftRes.sum >= rightRes.sum && leftRes.sum >= crossRes.sum)
        return leftRes;
    else if (rightRes.sum >= leftRes.sum && rightRes.sum >= crossRes.sum)
        return rightRes;
    else
        return crossRes;
}

int main() {
    vector<int> temp = {28, 31, 29, 34, 30, 33, 27, 35, 32};
    SubArray result = max3Day(temp, 0, temp.size() - 1);

    cout << "The 3-day subarray with the maximum total temperature is: [";
    for (int i = result.leftIndex; i <= result.rightIndex; i++) {
        cout << temp[i];
        if (i < result.rightIndex) cout << ", ";
    }
    cout << "] (total = " << result.sum << ")" << endl;
}
