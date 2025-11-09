#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Drink{
    public:
    string name;
    double volume;
    double glucose;
    double unit_glucose;

    Drink(string n,double v,double g) :name(n),volume(v),glucose(g),unit_glucose(g/v){}

    void display(double takenVolume){
        cout<<"name: "<<name
        <<", Taken: "<<takenVolume<<"L"
        <<", Glucose: "<<unit_glucose*takenVolume<<"gm"<<endl;
    }
    
};

bool Compare(Drink d1,Drink d2){
    return d1.unit_glucose<d2.unit_glucose; //ascending
}

void minimizeGlucose(vector<Drink> drinks,double maxVolume){
    //sort volume by L
    sort(drinks.begin(),drinks.end(),Compare);
    for (int i = 0; i < drinks.size(); i++) {
    drinks[i].display(drinks[i].volume); 
}
      double usedVolume = 0;
      double totalGlucose = 0;

      cout<<"selected drinks :"<<endl;

      for(int i=0;i<drinks.size();i++){
        if(usedVolume>=maxVolume) break;
        double canTake = min(drinks[i].volume,maxVolume-usedVolume);
        usedVolume= usedVolume+canTake;
        totalGlucose=totalGlucose + canTake*drinks[i].unit_glucose;

        drinks[i].display(canTake);
        
      }
      cout<<"minimum glucose consumed: "<<totalGlucose<<endl;

}

int main(){
    
    vector<Drink> drinks = {
        Drink("GlaxCose-D",3,75),
        Drink("GlucoMax",4,80),
        Drink("Sting",5,150)
    };

    double maxVolume = 6;
    minimizeGlucose(drinks,maxVolume);
   
}

  

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // Drink class: stores info about each drink
// class Drink {
// public:
//     string name;          // Name of the drink
//     double volume;        // Bottle size in liters
//     double glucose;       // Total glucose in the bottle (gm)
//     double unit_glucose;  // Glucose per liter

//     // Constructor: sets values when object is created
//     Drink(string n, double v, double g)
//         : name(n), volume(v), glucose(g), unit_glucose(g / v) {}

//     // Display info about the drink
//     // takenVolume: how much of the bottle we are consuming
//     void display(double takenVolume) {
//         cout << "Name: " << name
//              << ", Taken: " << takenVolume << "L"
//              << ", Glucose: " << unit_glucose * takenVolume << "gm" << endl;
//     }
// };

// // Compare function for sorting drinks by unit_glucose ascending
// bool Compare(Drink d1, Drink d2) {
//     return d1.unit_glucose < d2.unit_glucose; // smaller glucose per liter first
// }

// // Function to select drinks to minimize glucose intake (fractional knapsack)
// void MinimizeGlucose(vector<Drink> drinks, double maxVolume) {
//     // Step 1: Sort drinks by unit glucose (ascending)
//     sort(drinks.begin(), drinks.end(), Compare);

//     // Print all drinks after sorting
//     cout << "Available drinks (sorted by unit glucose):" << endl;
//     for (int i = 0; i < drinks.size(); i++) {
//     drinks[i].display(drinks[i].volume); // display full bottle info
// }
 

//     double usedVolume = 0;   // total liters taken so far
//     double totalGlucose = 0; // total glucose consumed

//     cout << "\nSelected drinks:" << endl;

//     // Step 2: Pick drinks one by one until maxVolume is reached
//     for (Drink d : drinks) {
//         if (usedVolume >= maxVolume) break; // stop if max capacity reached

//         // Step 2a: Decide how much of this drink to take
//         double canTake = min(d.volume, maxVolume - usedVolume); // take full or partial bottle
//         usedVolume += canTake;                                  // update total volume
//         totalGlucose += canTake * d.unit_glucose;              // update total glucose

//         d.display(canTake); // display what we took
//     }

//     // Step 3: Print final result
//     cout << "\nMinimum glucose consumed = " << totalGlucose
//          << " gm (Total volume = " << usedVolume << "L)" << endl;
// }

// int main() {
//     // Step 0: Create drinks
//     vector<Drink> drinks = {
//         Drink("Galxose-D", 3, 75), // 3L, 75gm
//         Drink("GlucoMax", 4, 80),  // 4L, 80gm
//         Drink("Sting", 5, 150)     // 5L, 150gm
//     };

//     double maxVolume = 6; // maximum liters you can drink

//     // Step 4: Call function to pick drinks minimizing glucose
//     MinimizeGlucose(drinks, maxVolume);
// }

















































// #include <bits/stdc++.h>
// using namespace std;

// class SubArray {
// public:
//     int months;
//     int leftIndex;
//     int rightIndex;

//     SubArray(int m, int l, int r) : months(m), leftIndex(l), rightIndex(r) {}
// };

// SubArray findCrossing(vector<int> arr, int left, int right) {
//     int mid = (left + right) / 2;   // ✅ fix
//     int leftIndex = mid;
//     int rightIndex = mid + 1;

//     int leftCount = 0;
//     for (int i = mid; i >= left; i--) {   // ✅ fix (i >= left)
//         if (arr[i] > 0) {
//             leftCount++;
//             leftIndex = i;
//         } else break;
//     }

//     int rightCount = 0;
//     for (int i = mid + 1; i <= right; i++) {
//         if (arr[i] > 0) {
//             rightCount++;
//             rightIndex = i;
//         } else break;
//     }

//     return SubArray(leftCount + rightCount, leftIndex, rightIndex);
// }

// SubArray longestProfit(vector<int> arr, int left, int right) {
//     if (left == right) {
//         if (arr[left] > 0)
//             return SubArray(1, left, right);
//         else
//             return SubArray(0, left, right);
//     }

//     int mid = (left + right) / 2;   // ✅ fix
//     SubArray leftRes = longestProfit(arr, left, mid);       // ✅ fix
//     SubArray rightRes = longestProfit(arr, mid + 1, right); // ✅ fix
//     SubArray crossRes = findCrossing(arr, left, right);

//     if (leftRes.months >= rightRes.months && leftRes.months >= crossRes.months)
//         return leftRes;
//     else if (rightRes.months >= leftRes.months && rightRes.months >= crossRes.months)
//         return rightRes;
//     else
//         return crossRes;
// }

// int main() {
//     vector<int> profit = {3, -1, 9, -2, 4, 3, 1, -5, 3, 2};
//     SubArray result = longestProfit(profit, 0, profit.size() - 1);
//     cout << "Longest consecutive profit period: "
//          << result.months << " months, from month "
//          << result.leftIndex + 1 << " to " << result.rightIndex + 1 << endl;
// }



























// // #include<bits/stdc++.h>
// // using namespace std;
// // class SubArray{
// //     public:
// //     int months;
// //     int leftIndex;
// //     int rightIndex;

// //     SubArray(int m,int l,int r): months(m),leftIndex(l),rightIndex(r){}

// // };

// // SubArray findCrossing(vector<int>arr, int left,int right){
// //     int mid= left+right/2;
// //     int leftIndex= mid;
// //     int rightIndex=mid+1;

// //     int leftCount=0;
// //     for(int i = mid;i>=1;i--){
// //         if(arr[i]>=0){
// //             leftCount++;
// //             leftIndex=i;
// //         }
// //         else{
// //             break;
// //         }

// //     }
// //     int rightCount=0;
// //     for(int i=mid+1;i<=right;i++){
// //         if(arr[i]>=0){
// //             rightCount++;
// //             rightIndex=i;
// //         }
// //         else{
// //             break;
// //         }
// //     }

// //     return SubArray(leftCount+rightCount,leftIndex,rightIndex);

// // }

// //  SubArray longestProfit(vector<int> arr, int left, int right){
// //     if(left==right){

// //         if(arr[left]>0){
// //         return SubArray(1,left,right);
// //         }
// //     else{
// //         return SubArray(0,left,right);
// //     }
// // }
// //    int mid = left+right/2;
// //    SubArray leftRes = longestProfit(arr,mid,left);
// //    SubArray rightRes = longestProfit(arr,mid+1,right);
// //    SubArray crossRes = findCrossing(arr,left,right);

// //     if(leftRes.months>=rightRes.months && leftRes.months>=crossRes.months){
// //         return leftRes;
// //     }
// //     if(rightRes.months>=leftRes.months && rightRes.months>=crossRes.months){
// //         return rightRes;
// //     }
// //     else{
// //         return crossRes;
// //     }


   
// // }

// // int main(){
// //     vector<int> profit = {3, -1, 9, -2, 4, 3, 1, -5, 3, 2};
// //     SubArray result = longestProfit(profit, 0, profit.size() - 1);
// //     cout << "Longest consecutive profit period: " 
// //      << result.months << " months, from month " 
// //      << result.leftIndex + 1 << " to " << result.rightIndex + 1 << endl;

// // }

//3 number 
// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// class Product{
//     public:
//     string name;
//     double weight;
//     double profit;
//     double profitPerKg;

//     Product(string n,double w,double p) : name(n),weight(w),profit(p),profitPerKg(p/w){}

//     void display(double takenWeight){
//         cout<<"Product: "<<name<<" Taken: "<<takenWeight<<"kg"<<" Profit: "<<profitPerKg*takenWeight<<endl;
//     }
// };
// bool Compare(Product p1,Product p2){
//     return p1.profitPerKg>p2.profitPerKg; //desecending
// }
// void maximizeProfit(vector<Product>products,double maxWeight){
//     sort(products.begin(),products.end(),Compare); //sort done

//     double usedWeight = 0;
//     double totalProfit = 0;

//     cout<<"selected products :"<<endl;
    
//     for(int i =0;i<products.size();i++){
//         if(usedWeight>=maxWeight) break;

//         double canTake= min(products[i].weight,maxWeight-usedWeight);
//         usedWeight = usedWeight+canTake;
//         totalProfit = totalProfit+canTake*products[i].profitPerKg;

//         products[i].display(canTake);
//     }

//     cout<<"maximum profit: "<<totalProfit<<endl;

// }
// int main(){
//     vector<Product> products = {
//         Product("Rice",100,1500),
//         Product("Sugar",200,3400),
//         Product("Wheat",350,3500),
//         Product("Onion",250,8000)

//     };
//     double maxWeight = 600;
//     maximizeProfit(products,maxWeight);

// }