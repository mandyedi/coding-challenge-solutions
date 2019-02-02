int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    
    int result = 0;
    vector<int>::iterator it = ar.begin(), it2;
    while(it != ar.end()){
        int current = *it;
        it2 = ar.erase(it);
        while(it2 != ar.end()){
            if(current == *it2){
                result++;
                it2 = ar.erase(it2);
                break;
            } else {
                ++it2;
            }
        }
    }

    cout << result << endl;
    return 0;
}