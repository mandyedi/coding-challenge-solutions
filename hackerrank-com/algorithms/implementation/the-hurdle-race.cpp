int main(){
    int n;
    int k;
    cin >> n >> k;
    int h, max = 0;
    for(int height_i = 0; height_i < n; height_i++){
        cin >> h;
        if(h > max){
            max = h;
        }
    }
    cout << ((max - k) > 0 ? (max - k) : 0);

    return 0;
}