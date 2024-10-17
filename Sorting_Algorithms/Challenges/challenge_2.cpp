// Give an array of names of the fruits; you are supposed to sort it in lexographic 
// order using the selection sort

#include<iostream>
#include<cstring>
using namespace std;

void lexoGraphicalSort(int n,char fruit[][60]){
    for(int i=0;i<n;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(strcmp(fruit[j],fruit[min_index])<0){
                min_index=j;
            }
        }
        if(min_index!=i) swap(fruit[i],fruit[min_index]);
    }
}

int main(){
    char fruit[] [60]={"papaya","lime","wateremlon","apple","mango","kiwi"};
    int n=sizeof(fruit)/sizeof(fruit[0]);
    lexoGraphicalSort(n,fruit); 
    for(int i=0;i<n;i++) cout<< fruit[i] << " ";
    return 0;
}