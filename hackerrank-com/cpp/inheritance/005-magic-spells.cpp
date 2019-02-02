if(Fireball *f = dynamic_cast<Fireball*>(spell)){
    f->revealFirepower();
} else if(Frostbite *f = dynamic_cast<Frostbite*>(spell)){
    f->revealFrostpower();
} else if(Thunderstorm *t = dynamic_cast<Thunderstorm*>(spell)){
    t->revealThunderpower();
} else if(Waterbolt *w = dynamic_cast<Waterbolt*>(spell)){
    w->revealWaterpower();
} else {
    string X = spell->revealScrollName();
    string Y = SpellJournal::journal;
    
    int m = X.size();
    int n = Y.size();
    int L[m+1][n+1];
    int i, j;

    for (i=0; i<=m; i++) {
        for (j=0; j<=n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            }
            else if (X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            }
            else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    cout << L[m][n] << endl;
}