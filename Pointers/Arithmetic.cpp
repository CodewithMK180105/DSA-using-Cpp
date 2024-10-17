// #include<iostream>
// using namespace std;
// int main(){
//     int arr[]={4,19};
//     int *ptr=&arr[0];
//     cout<<ptr<<" "<<*ptr<<endl;
//     cout<<*ptr++<<endl;
//     cout<<arr[0]<<" "<<arr[1]<<endl;
//     cout<<ptr<<" "<<*ptr<<endl;
//     return 0;
// }


// #include<iostream>
// using namespace std;
// int main(){
//     int arr[]={4,19};
//     int *ptr=&arr[0];
//     cout<<ptr<<" "<<*ptr<<endl;
//     cout<<(*ptr)++<<endl;
//     cout<<arr[0]<<" "<<arr[1]<<endl;
//     cout<<ptr<<" "<<*ptr<<endl;
//     return 0;
// }


// #include<iostream>
// using namespace std;
// int main(){
//     int arr[]={7,5};
//     int *ptr=&arr[0];
//     cout<<*++ptr<<endl;
//     cout<<arr[0]<<" "<<arr[1]<<endl;
//     return 0;
// }


#include<iostream>
using namespace std;
int main(){
    int arr[]={8,2};
    int *ptr=&arr[0];
    cout<<++*ptr<<endl;
    cout<<arr[0]<<" "<<arr[1]<<endl;
    return 0;
}