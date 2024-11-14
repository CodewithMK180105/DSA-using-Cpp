// #include<iostream>
// #include<string>
// #include<sstream>
// using namespace std;

// int main(){
//     string str="raghav  is a   maths    teacher";
//     stringstream ss(str);
//     string temp;

//     while(ss>>temp){
//         cout<<temp<<endl;
//     }
//     return 0;
// }


#include <iostream>
#include <sstream>
#include<string>
using namespace std;

int countWords(string str)
{
    // Breaking input into word 
    // using string stream
  
    // Used for breaking words
    stringstream s(str); 
  
    // To store individual words
    string word; 

    int count = 0;
    while (s >> word)
        count++;
    return count;
}

// Driver code
int main()
{
    string s = "geeks for geeks geeks \n    ""contribution placements"" raf gnh";
    cout<<s<<endl;
    cout << " Number of words are: " << countWords(s);
    return 0;
}