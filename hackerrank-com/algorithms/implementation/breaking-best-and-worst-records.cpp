int main() {
    int n, s, prevMin, prevMax, countMin = 0, countMax = 0;
    cin >> n;

    for(int s_i = 0; s_i < n; s_i++){
       cin >> s;
       if(s_i > 0){
           if(s > prevMax){
               prevMax = s;
               countMax++;
           } else if(s < prevMin){
               prevMin = s;
               countMin++;
           }
       } else {
           prevMax = s;
           prevMin = s;
       }
    }
    
    cout << countMax << " " << countMin;
    return 0;
}