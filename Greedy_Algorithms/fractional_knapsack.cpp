#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    vector<string> item;
    vector<int> profit;
    vector<int> weight;

    cout<<"Enter the Data Respectively: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the name of the item-"<<i+1<<": ";
        string it;
        cin>>it;
        item.push_back(it);

        cout<<"Enter the profit of the item-"<<i+1<<": ";
        int pro;
        cin>>pro;
        profit.push_back(pro);
        
        cout<<"Enter the weight of the item-"<<i+1<<": ";
        int wei;
        cin>>wei;
        weight.push_back(wei);
    }

    vector<float> ratio;

    for(int i=0;i<n;i++){
        ratio.push_back(static_cast<float>(profit[i])/weight[i]);
    }

    cout<<endl;
    cout<<endl;

    cout<<"The data is below: "<<endl;
    cout<<endl;

    cout<<"Item\tProfit\tWeight\tRatio"<<endl;
    for(int i=0;i<n;i++){
        cout<<item[i]<<"\t"<<profit[i]<<"\t"<<weight[i]<<"\t"<<ratio[i]<<endl;
    }

    cout<<"Enter the value of the Knapsack: ";
    int k;
    cin>>k;

    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                flag=false;
                swap(ratio[i],ratio[j]);
                swap(weight[i],weight[j]);
                swap(profit[i],profit[j]);
                swap(item[i], item[j]);
            }
        }
        if(flag) break;
    }

    float p=0;
    int i=0;
    while(k>0 && i<n){
        if(k<weight[i]){
            p+=(float)ratio[i]*k;
            k=0;
        } else {
            p+=(float)profit[i];
            k-=weight[i];
        }
        i++;
    }


    cout<<"The profit is: "<<p;
    return 0;

}