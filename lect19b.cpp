#include<iostream>
#include<vector>
using namespace std;
main()
{
    vector<int>a;
    vector<int>b(5,1);
    vector<int>last(b);
    for(int i:b)
    {
        cout<<i<<" ";
    }
    cout<<"\n\n";
    for(int i:last)
    {
        cout<<i<<" ";
    }
    cout<<"\n\n"; 
    cout<<a.capacity()<<endl;
    a.push_back(1);
    cout<<a.capacity()<<endl;
    a.push_back(34);
    cout<<a.capacity()<<endl;
    a.push_back(3);
    cout<<a.capacity()<<endl;
    a.push_back(23);
    cout<<a.capacity()<<endl;
    a.push_back(5);
    cout<<a.capacity()<<endl;
    cout<<a.size()<<endl;
    cout<<"value at 2 = "<<a.at(2)<<endl;
    cout<<a.at(3)<<endl;
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;
    cout<<"\nbefore pop\n";
    for(int i:a)
    {
        cout<<i<<" ";
    }
    a.pop_back();
    cout<<"\nafter pop\n";
     for(int i:a)
    {
        cout<<i<<" ";
    }
    a.erase(a.begin());
    cout<<"\nafter erase"<<endl;
    for(int i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\nafter erasing first 2 values"<<endl;
    a.erase(a.begin(),a.begin()+2);
    for(int i:a)
    {
        cout<<i<<" ";
    }
}   