#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "prabhunaman";
    
    map<char, int> mp;
    
    for(int i = 0; i < s.size(); i++){
        mp[s[i]]++;
    }
    
    // pair<char, int> p;
    // vector<p> v;
    
    // for(auto it : mp){
    //     p.first = it.first;
    //     p.second = it.second;
    //     v.push_back(p);
    // }
    
    vector<pair<char, int>> v;
    
    for(auto it : mp){
        v.push_back({it.first, it.second});
    }
    
    for(int i = 0; i < v.size(); i++)
    cout << v[i].first << " " << v[i].second << '\n';
}
