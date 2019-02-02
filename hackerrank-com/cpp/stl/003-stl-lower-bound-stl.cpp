int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }
    cin >> n;
    int y;
    vector<int>::iterator it;
    for(int i=0; i<n; i++){
        cin >> y;
        //cout << y << endl;
        it = lower_bound(numbers.begin(), numbers.end(), y);
        //cerr << *it << endl;
        if(*it == y){
            cout << "Yes ";
        } else {
            cout << "No ";
        }
        cout << (it - numbers.begin()) + 1 << endl;
    }
    return 0;
}