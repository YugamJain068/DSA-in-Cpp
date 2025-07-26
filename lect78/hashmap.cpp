#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
    //creation of unordered map 
    unordered_map<string,int>m;
    //insertion
    //1st method
    pair<string,int>p1=make_pair("babbar",3);
    m.insert(p1);
    //2nd method
    pair<string,int>p2("love",2);
    m.insert(p2);
    //3rd method
    m["mera"]=1;
    //updation
    m["mera"]=2;
    //search or print
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    //cout<<m.at("unknown")<<endl;
    cout<<m["unknown"]<<endl;
    //now unknown key is mapped to 0 
    cout<<m.at("unknown")<<endl;
    //size
    cout<<m.size()<<endl;
    //key present or not by using count function
    cout<<m.count("hello")<<endl;
    cout<<m.count("mera")<<endl;
    //erase
    m.erase("love");
    cout<<m.size()<<endl;
    //print whole map
    for(auto i:m){
        //i.first---->to print key
        //i.second--->to print value mapped to that key;
        cout<<i.first<<" "<<i.second<<endl;
    }
    //printing by using iterator 
    unordered_map<string,int> :: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}