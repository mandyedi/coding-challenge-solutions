#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    map<string, int> m;
    map<string, int>::iterator it;
    int type, value;
    string key;
    
    for(int i=0; i<n; i++){
        cin >> type >> key;
        if(type == 1){
            cin >> value;
            it = m.find(key);
            if(it != m.end()){
                m[key] += value;
            }
            m.insert(make_pair(key,value));
        } else if(type == 2){
            m.erase(key);
        } else if(type == 3){
            it = m.find(key);
            if(it == m.end()){
                cout << 0 << endl;
            } else{
                cout << it->second << endl;
            }
        }
    }
    return 0;
}