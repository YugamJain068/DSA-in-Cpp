#include<iostream>
#include<array>
using namespace std;
main()
{
    array<int,4> a={1,2,3,4};
    int size=a.size();
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"number at 2 position = "<<a.at(2)<<endl;
    cout<<"empty or not = "<<a.empty()<<endl;
    cout<<"first number = "<<a.front()<<endl;
    cout<<"last number = "<<a.back()<<endl;
}