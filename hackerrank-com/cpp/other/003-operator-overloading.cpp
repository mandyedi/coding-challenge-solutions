class Matrix{
public:
    vector<vector<int> > a;
    
    Matrix operator + (Matrix &x){
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a[i].size(); j++){
                a[i][j] = a[i][j] + x.a[i][j];
            }
        }
        return *this;
    }
};