#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef struct{
    float profit;
    float weight;
    float ratio;
}Item;

void input(Item items[],int sizeofItems){
    for(int i=0;i<sizeofItems;i++){
        cout << "Enter item " << i+1 << " profit:";
        cin >> items[i].profit; 
        cout << "Enter item " << i+1 << " weight:";
        cin >> items[i].weight;
        cout << endl;
    }
}

bool compare(Item item1,Item item2){
    return (item1.ratio>item2.ratio);
}


float knapsack(Item item[],int itemSize,int mw){
    
    for(int i=0;i<itemSize;i++){
        item[i].ratio=item[i].profit/item[i].weight;
    }
    
    sort(item,item+itemSize,compare);
    
    
    double tprofit=0,tweight=0;
    for(int i=0;i<itemSize;i++){
        if(tweight+item[i].weight<=mw){
            tweight += item[i].weight;
            tprofit += item[i].profit;
        }
        else{
            double wt = mw-tweight;
            tprofit += (item[i].ratio*wt);
            tweight += wt;
            break;
        }
    }
    return tprofit;
}

int main(){
    int mw;
    int numItems;
    cout << "Enter number of items to be entered: ";
    cin >> numItems;
    Item items[numItems];
    input(items,numItems);
    cout << "Enter maximum weight: ";
    cin >> mw;
    double maxProfit = knapsack(items,numItems,mw);
    cout << "\nMax value for " << mw << " weight is " << maxProfit << endl;    
    return 0;
}
