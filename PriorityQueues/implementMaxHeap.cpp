// Using the array Data Structure, implement the Max heap

#include<iostream>
#include<queue>
using namespace std;
class MaxHeap{
    public:
        int arr[20];
        int idx;
        MaxHeap(){
            idx=1;
        }

        int top(){
            return arr[1];
        }
        void push(int val){
            arr[idx]=val;
            int pos=idx;
            while(pos!=1 && arr[pos/2]<arr[pos]){
                swap(arr[pos/2], arr[pos]);
                pos=pos/2;
            }
            idx++;
        }

        int size(){
            return idx-1;
        }

        void pop(){
            if(idx==1){
                cout<<"Heap is empty"<<endl;
                return;
            }
            arr[1]=arr[idx-1];
            idx--;

            int i=1;
            while(true){
                if(idx>2*i+1){
                    if(arr[2*i]>arr[2*i+1] && arr[i]<arr[2*i]){
                        swap(arr[i], arr[2*i]);
                        i=2*i;
                    }
                    else if(arr[i]<arr[2*i+1]){
                        swap(arr[i], arr[2*i+1]);
                        i=2*i+1;
                    }
                } else if(idx>2*i && arr[i]<arr[2*i]){
                    swap(arr[i], arr[2*i]);
                    i=2*i;
                } else {
                    break;
                }
            }
        }

};
int main() {
    MaxHeap pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(2);
    pq.push(15);

    pq.pop(); // Should remove 20
    while (pq.size() > 0) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}