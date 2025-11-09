#include <iostream>
#include <climits>
using namespace std;

void RodCutting(int price[], int n){
    int R[n+1]; 
    int b[n+1]; 
    R[0] = 0;
    b[0] = 0;

   
    for(int j = 1; j <= n; j++){
        R[j] = INT_MIN;
        for(int i = 1; i <= j; i++){
            if(price[i-1] + R[j-i] > R[j]){
                R[j] = price[i-1] + R[j-i];
                b[j] = i;
            }
        }
    }

    
    cout << "Maximum Revenue for rod length " << n << " = " << R[n] << endl;

    
    cout << "Pieces lengths: ";
    int length = n;
    while(length > 0){
        cout << b[length] << " ";
        length -= b[length];
    }
    cout << endl;
}

int main(){
    
    int price[] = {2, 2, 8, 9, 10, 20, 22}; 
    int n; 

    cout << "Enter rod length: ";
    cin >> n;

    RodCutting(price, n);

    return 0;
}
