#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cin >> size;
    
    map<int, int> mp;
    
    for(int i = 0; i < size; i++){
        int c;
        cin >> c;
        mp[c]++;
    }
    
    int n;
    cin >> n;
    
    while(n--){
        int a; 
        cin >> a;
        
        cout << mp[a] << '\n';
    }
}
