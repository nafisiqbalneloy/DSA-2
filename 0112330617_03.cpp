// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// class Product {
// public:
//     string name;
//     double weight;
//     double wholesalePrice;
//     double retailPricePerKg;
//     double profitPerKg;

//     Product(string n, double w, double wholesale, double retailPerKg) 
//         : name(n), weight(w), wholesalePrice(wholesale), retailPricePerKg(retailPerKg) {
//         double wholesalePerKg = wholesalePrice / weight;
//         profitPerKg = retailPricePerKg - wholesalePerKg;
//     }

//     void display(double takenWeight) {
//         cout << "Product: " << name 
//              << " Taken: " << takenWeight << "kg"
//              << " Profit: " << profitPerKg * takenWeight << endl;
//     }
// };

// bool Compare(Product p1, Product p2) {
//     return p1.profitPerKg > p2.profitPerKg; // sort by profit/kg descending
// }

// void maximizeProfit(vector<Product> products, double maxWeight) {
//     sort(products.begin(), products.end(), Compare);

//     double usedWeight = 0;
//     double totalProfit = 0;

//     cout << "Selected products:\n";
    
//     for (int i = 0; i < products.size(); i++) {
//         if (usedWeight >= maxWeight) break;

//         double canTake = min(products[i].weight, maxWeight - usedWeight);
//         usedWeight =  usedWeight + canTake;
//         totalProfit = totalProfit + canTake * products[i].profitPerKg;

//         products[i].display(canTake);
//     }

//     cout << "Maximum Profit: " << totalProfit << endl;
// }

// int main() {
//     vector<Product> products = {
//         Product("Rice", 100, 4000, 55),
//         Product("Sugar", 200, 9000, 62),
//         Product("Wheat", 350, 7000, 30),
//         Product("Onion", 250, 12000, 80)
//     };

//     double maxWeight = 600;
//     maximizeProfit(products, maxWeight);

//     return 0;
// }

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Product{
    public:
    string name;
    double weight;
    double wholesalePrice;
    double retailPricePerKg;
    double profitPerKg;

    Product(string n,double w, double wholesale,double retail) : name(n), weight(w), wholesalePrice(wholesale),
                    retailPricePerKg(retail){
                        double wholesalePricePerKg = wholesalePrice/weight;
                        profitPerKg = retailPricePerKg - wholesalePricePerKg;
                    }
            
        void display(double takenWeight){
            cout<<"Product: "<<name;
            cout<<" Taken: "<<takenWeight<<"kg";
            cout<<" Profit: "<<takenWeight*profitPerKg<<endl;
        }
};

bool Compare(Product p1, Product p2){
    return p1.profitPerKg>p2.profitPerKg;
}

void maximizeProfit(vector<Product> products, double maxWeight){
    sort(products.begin(),products.end(),Compare);

    double usedWeight = 0;
    double totalProfit = 0;

    cout<<"selected product: "<<endl;
    for(int i=0;i<products.size();i++){
        if(usedWeight>=maxWeight) break;

        double canTake = min(products[i].weight,maxWeight-usedWeight);
        usedWeight = usedWeight + canTake;
        totalProfit = totalProfit + canTake*products[i].profitPerKg;

        products[i].display(canTake);
    }
    cout<<"maximum profit: "<<totalProfit<<endl;


}

int main(){
    vector <Product> products = {
        
        Product("Rice", 100, 4000, 55),
        Product("Sugar", 200, 9000, 62),
        Product("Wheat", 350, 7000, 30),
        Product("Onion", 250, 12000, 80)

    };

    double maxWeight = 600;
    maximizeProfit(products,maxWeight);

    return 0;

}