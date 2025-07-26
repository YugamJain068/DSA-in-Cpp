#include<iostream>
#include<queue>
using namespace std;
class heap{
    public:
        int arr[100];
        int size;
    //consructor
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        //insert at end of array
        size++;
        int index=size;
        arr[index]=val;
        //inserting it at correct position
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void deletefromheap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        //putting last element into first index
        arr[1]=arr[size];
        //deleting last element
        size--;
        //propogating root node to its correct position
        int i=1;
        while(i<size){
            int leftindex=2*i;
            int rightindex=2*i+1;
            if(leftindex < size && arr[leftindex] > arr[i]){
                swap(arr[leftindex],arr[i]);
                i=leftindex;
            }
            else if(rightindex < size && arr[rightindex] > arr[i]){
                swap(arr[rightindex],arr[i]);
                i=rightindex;
            }
            else{
                return ;
            }
        }
    }
    //printing the heap
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
void heapify(int arr[],int size, int index){
    int largest=index;
    int leftindex=2*index;
    int rightindex=2*index+1;
    if(leftindex <= size && arr[leftindex] > arr[largest]){
        //update largest
        largest=leftindex;
    }
    if(rightindex <= size && arr[rightindex] > arr[largest]){
        //update largest
        largest=rightindex;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
}
void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        //step1 - swap
        swap(arr[1],arr[size]);
        size--;
        //step2 - root node correct position
        heapify(arr,size,1);
    }
}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    cout<<"creation of heap from inserting: "<<endl;
    h.print();
    h.deletefromheap();
    cout<<"heap after deletion: "<<endl;
    h.print();
    //heap creation
    cout<<"creation of heap from heapify algo: "<<endl;
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    //calling heapify function
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    //printing heap
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"sorted heap: "<<endl;
    //heapsort
    heapsort(arr,n);
     //printing heap after sorting
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"using priority queue: "<<endl;
    //max heap
    priority_queue<int>pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout<<"element at top: "<<pq.top()<<endl;
    pq.pop();
    //largest element is deleted i.e the element at 1st index
    cout<<"element at top after pop: "<<pq.top()<<endl;
    cout<<"size of heap is: "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"heap is empty"<<endl;
    }
    else{
        cout<<"heap is not empty"<<endl;
    }
    cout<<"\n\n"<<endl;
    //min heap
    priority_queue<int , vector<int> , greater<int>>mp;
    mp.push(4);
    mp.push(2);
    mp.push(5);
    mp.push(3);
    cout<<"element at top: "<<mp.top()<<endl;
    mp.pop();
    //largest element is deleted i.e the element at 1st index
    cout<<"element at top after pop: "<<mp.top()<<endl;
    cout<<"size of heap is: "<<mp.size()<<endl;
    if(mp.empty()){
        cout<<"heap is empty"<<endl;
    }
    else{
        cout<<"heap is not empty"<<endl;
    }
    return 0;
}