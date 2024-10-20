// Decode the given encoded text;

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string decodeText(string s){
    string result="";
    for(int i=0;i<s.length();i++){
        if(s[i]!=']'){
            result.push_back(s[i]);
        } else{
            string str="";

            // extract str from result
            while(!result.empty() && result.back()!='['){
                str.push_back(result.back());
                result.pop_back();
            }

            // reverse the str
            reverse(str.begin(), str.end());

            // remove [ from result
            result.pop_back();

            // extract num from result
            string num="";
            while(!result.empty() && result.back()>'0' && result.back()<'9'){
                num.push_back(result.back());
                result.pop_back();
            }

            // reverse the num
            reverse(num.begin(), num.end());

            // convert string to number
            int count = stoi(num);

            while(count){
                result+=str;
                count--;
            }
        }
    }
    return result;  
}
int main(){
    string encodedText = "3[b2[ca]]";
    cout<<decodeText(encodedText)<<endl;
    return 0;
}