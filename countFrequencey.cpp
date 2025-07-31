#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    vector<int>arr = {5,1,21,6,5,16,21,5,1};
    map<int,int> numbers;

    for(int x:arr){
        numbers[x]++;
    }

    cout<<"Frequency of each elements:"<<endl;
    for(auto i: numbers){ //for(pair<int, int> i : numbers) insetad we use auto

        cout<<i.first<<"-->"<<i.second<<endl;
    }
    return 0;
}