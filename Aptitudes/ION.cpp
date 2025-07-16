// Problem Statement: Minimum Processing Time
// You are given:

// 1. An integer array requiredMemory where requiredMemory[i] represents the amount of memory required to process the ith program.
// 2. An integer array processType where processType[i] represents the type of the i th program.
// 3. An integer maxMemory representing the maximum memory available at any time.

// You need to determine the minimum time required to process all the programs under the following constraints:

// ✅ At most 2 programs can be processed at the same time.
// ✅ The 2 programs must have the same type in order to process them parallely.
// ✅ The combined memory of the 2 programs must not exceed maxMemory.
// ✅ Processing a single program or two programs together takes exactly 1 unit of time.

// Return the minimum total time required to process all programs.

// A. Test Case 1: Basic Pairing

// Input:
// requiredMemory = [2, 3, 5, 7, 4, 2]
// processType = [1, 2, 2, 1, 3, 1]
// maxMemory = 7

// Output:
// 5

// Explanation:
// Group by types:  
// Type 1: [2, 7, 2] → sorted = [2,2,7]  
// Type 2: [3,5] → sorted = [3,5]  
// Type 3: [4]  

// Process type 1:  
// Pair (2,2) → combined=4 ≤7 → time +=1  
// Process 7 alone → time +=1  

// Process type 2:  
// Process 5 alone → time +=1  
// Process 3 alone → time +=1  

// Process type 3:  
// Process 4 alone → time +=1  

// Total time = 1+1+1+1+1 = 5

// B. Test Case 2: Perfect Pairing

// Input:
// requiredMemory = [1, 1, 1, 1, 1, 1]
// processType = [1, 1, 2, 2, 3, 3]
// maxMemory = 2

// Output:
// 3

// Explanation:
// Each type has 2 programs of memory 1.  
// Since 1+1 ≤ 2, pair them all.  

// Type 1: Pair (1,1) → time +=1  
// Type 2: Pair (1,1) → time +=1  
// Type 3: Pair (1,1) → time +=1  

// Total time = 3

// C. Test Case 3: No Pairing Possible

// Input:
// requiredMemory = [5, 6, 7]
// processType = [1, 2, 3]
// maxMemory = 10

// Output:
// 3

// Explanation:
// Each type has only one program.  
// No pairing possible → process each alone.  

// Time = 1+1+1 = **3**
// Input:
// requiredMemory = [5, 6, 7]
// processType = [1, 2, 3]
// maxMemory = 10

// Output:
// 3

// Explanation:
// Each type has only one program.  
// No pairing possible → process each alone.  

// Time = 1+1+1 = 3

// D. Test Case 4: Large Memory Limit

// Input:
// requiredMemory = [5, 10, 15, 20]
// processType = [1, 1, 1, 1]
// maxMemory = 100

// Output:
// 2

// Explanation:
// All programs are of type 1.  
// Pair (5,20) → memory=25 ≤100 → time +=1  
// Pair (10,15) → memory=25 ≤100 → time +=1  

// Total time = 2

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int minTime(vector<int>& requiredMemory, vector<int>& processType, int maxMemory){
    unordered_map<int, vector<int>> um;
    int n=requiredMemory.size();
    for(int i=0;i<n;i++){
        um[processType[i]].push_back(requiredMemory[i]);
    }

    int res=0;
    for(auto ele: um){
        vector<int> v=ele.second;
        sort(v.begin(), v.end());
        int lo=0, hi=v.size()-1;
        while(lo<=hi){
            if(v[lo]+v[hi]<=maxMemory){
                res++;
                lo++;
                hi--;
            } else {
                res++;
                hi--;
            }
        }
    }
    return res;
}
int main() {
    // Test Case 1
    vector<int> requiredMemory1 = {2, 3, 5, 7, 4, 2};
    vector<int> processType1 = {1, 2, 2, 1, 3, 1};
    int maxMemory1 = 7;
    cout << "Test Case 1 Output: " << minTime(requiredMemory1, processType1, maxMemory1) << endl; // Expected: 5

    // Test Case 2
    vector<int> requiredMemory2 = {1, 1, 1, 1, 1, 1};
    vector<int> processType2 = {1, 1, 2, 2, 3, 3};
    int maxMemory2 = 2;
    cout << "Test Case 2 Output: " << minTime(requiredMemory2, processType2, maxMemory2) << endl; // Expected: 3

    // Test Case 3
    vector<int> requiredMemory3 = {5, 6, 7};
    vector<int> processType3 = {1, 2, 3};
    int maxMemory3 = 10;
    cout << "Test Case 3 Output: " << minTime(requiredMemory3, processType3, maxMemory3) << endl; // Expected: 3

    // Test Case 4
    vector<int> requiredMemory4 = {5, 10, 15, 20};
    vector<int> processType4 = {1, 1, 1, 1};
    int maxMemory4 = 100;
    cout << "Test Case 4 Output: " << minTime(requiredMemory4, processType4, maxMemory4) << endl; // Expected: 2

    return 0;
}
