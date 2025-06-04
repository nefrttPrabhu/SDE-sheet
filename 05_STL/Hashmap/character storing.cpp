#include<bits/stdc++.h>
using namespace std;

int main(){
    cout << "string input: ";
    string s;
    cin >> s;
    
    int h[26] = {0};
    
    int a;
    cin >> a;
    
    for(int i = 0; i < s.size(); i++){
        h[s[i] - 'a']++;
    }
    
    while(a--){
        char c;
        cin >> c;
        
        cout << h[c - 'a'] << '\n';
    }
}
