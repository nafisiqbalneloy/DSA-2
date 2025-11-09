#include <bits/stdc++.h>
using namespace std;
class MaxSub
{
public:
    int months;
    int lidx;
    int ridx;
    MaxSub(int s, int l, int r) : months(s), lidx(l), ridx(r) {}
};

MaxSub mcsa(vector<int> arr, int l, int r)
{

    int mid = (l + r) / 2;
    int lidx = mid;
    int ridx = mid + 1;
    int lcount = 0;
    for (int i = mid; i >= l; i--)
    {
        if (arr[i] >= 0)
        {
            lcount++;
            lidx = i;
        }
        else
            break;
    }
    int rcount = 0;

    for (int i = mid + 1; i <= r; i++)
    {
        if (arr[i] >= 0)
        {
            rcount++;
            ridx = i;
        }
        else
            break;
    }

    return MaxSub(lcount + rcount, lidx, ridx);
}
MaxSub longestProfit(vector<int> arr, int l, int r)
{

    if (l == r)
    {

        if (arr[l] > 0)
        {
            return MaxSub(1, l, r);
        }
        else
            return MaxSub(0, l, r);
    }
    int mid = (l + r) / 2;
    MaxSub left = longestProfit(arr, l, mid);
    MaxSub right = longestProfit(arr, mid + 1, r);
    MaxSub cross = mcsa(arr, l, r);
    if (left.months >= right.months && left.months >= cross.months)
        return left;
    else if (right.months >= left.months && right.months >= cross.months)
        return right;
    else
        return cross;
}
int main()
{
    vector<int> a = {3, -1, 9, -2, 4, 3, 1, -5, 3, 2};
    MaxSub res = longestProfit(a, 0, a.size() - 1);
    cout << "Longest consecutive profit period = " << res.months << " months" << endl;
    cout << "Month Range = {";
    for (int i = res.lidx; i <= res.ridx; i++)
    {
        cout << "M" << i + 1;
        if (i == res.ridx)
            cout << "}";
        else
            cout << ", ";
    }

    return 0;
}