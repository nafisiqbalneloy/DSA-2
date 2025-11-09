#include<bits/stdc++.h>
using namespace std;
class subArray{
    public:
    int sum;
    int leftIndex;
    int rightIndex;

    subArray(int s,int l,int r) : sum(s),leftIndex(l),rightIndex(r) {}
};

subArray findCrossing(vector<int> arr,int left,int right){
    int mid = (left+right)/2;

    //left half sum
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft = mid; //index er hishab

    for(int i=mid;i>=left;i--){
        sum = sum+arr[i];
        if(sum>leftSum){
            leftSum = sum;
            maxLeft = i;

        }
    }

    //right half sum
    int rightSum = INT_MIN;
     sum = 0;
    int maxRight = mid+1;

    for(int i = mid+1;i<=right;i++){
        sum = sum+arr[i];
        if(sum>rightSum){
            rightSum = sum;
            maxRight = i;
        }
    }

    return subArray(leftSum+rightSum,maxLeft,maxRight);
}

subArray longestProfit(vector<int>arr,int left,int right){
    if(left==right){
        return subArray(arr[left],left,right);
    }

    int mid=(left+right)/2;

    subArray leftRes = longestProfit(arr, left, mid);
    subArray rightRes = longestProfit(arr, mid + 1, right);
    subArray crossRes = findCrossing(arr, left, right);

    if (leftRes.sum >= rightRes.sum && leftRes.sum >= crossRes.sum)
        return leftRes;
    else if (rightRes.sum >= leftRes.sum && rightRes.sum >= crossRes.sum)
        return rightRes;
    else
        return crossRes;
}

int main(){
    vector<int> profit = {3, -1, 9, -2, 4, 3, 1, -5, 3, 2};
    subArray result = longestProfit(profit, 0, profit.size() - 1);
    cout<<result.sum<<endl;
    cout<<"index: "<<result.leftIndex+1<<" to "<<result.rightIndex+1<<endl;

    // cout << "Maximum sum subarray: " << result.sum 
    //      << " from index " << result.leftIndex + 1 
    //      << " to " << result.rightIndex + 1 << endl;

}