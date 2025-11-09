#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Drink{
    public:
    string name;
    double volume; //w
    double glucose; //p
    double unit_glucose; //profitPerUnit

    Drink(string n,double v,double g) :name(n),volume(v),glucose(g),unit_glucose(g/v){}

    void display(double takenVolume){
        cout<<"name: "<<name<<" Taken: "<<takenVolume<<"L" <<" Glucose: "<<unit_glucose*takenVolume<<"gm"<<endl;
            
    }
    
};

bool Compare(Drink d1,Drink d2){
    return d1.unit_glucose<d1.unit_glucose;
}

void minimizedGlucose(vector<Drink> drinks,double maxVolume){
    //sort
    sort(drinks.begin(),drinks.end(),Compare);
    cout<<"selected drinks: "<<endl;

    double usedVolume=0;
    double totalGlucose=0;

    for(int i=0;i<drinks.size();i++){
        if(usedVolume>=maxVolume) break;
        
            double canTake = min(drinks[i].volume,maxVolume-usedVolume);
            usedVolume = usedVolume+canTake;
            totalGlucose = totalGlucose+canTake*drinks[i].unit_glucose;
        drinks[i].display(canTake);
    }

    cout<<"minimum glucose consumed: "<<totalGlucose<<endl;
}











// bool Compare(Drink d1,Drink d2){
//     return d1.unit_glucose<d2.unit_glucose; //ascending
// }

// void minimizeGlucose(vector<Drink> drinks,double maxVolume){
//     //sort volume by L
//     sort(drinks.begin(),drinks.end(),Compare);

//     for (int i = 0; i < drinks.size(); i++) {
//     drinks[i].display(drinks[i].volume); 
// }
//       double usedVolume = 0;
//       double totalGlucose = 0;

//       cout<<"selected drinks :"<<endl;

//       for(int i=0;i<drinks.size();i++){
//         if(usedVolume>=maxVolume) break;

//         double canTake = min(drinks[i].volume,maxVolume-usedVolume);
//         usedVolume= usedVolume+canTake;
//         totalGlucose=totalGlucose + canTake*drinks[i].unit_glucose;

//         drinks[i].display(canTake);
        
//       }
//       cout<<"minimum glucose consumed: "<<totalGlucose<<endl;

// }

int main(){
    
    vector<Drink> drinks = {
        Drink("GlaxCose-D",3,75),
        Drink("GlucoMax",4,80),
        Drink("Sting",5,150)
    };

    double maxVolume = 6;
    minimizedGlucose(drinks,maxVolume);
   
}













