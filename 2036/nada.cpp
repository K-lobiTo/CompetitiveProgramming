
void solve(){
    int n, m, count=0, len;
    string ans = "1543", act;
    cin>>n>>m;
    vec<char> lay;
    char mat[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>mat[i][j];
    for(int gap = 0; gap<n/2 && gap<m/2; ++gap){
        lay.clear();
        for(int i=gap  ;i<(m-gap);++i)lay.push_back(mat[gap][i]);
        for(int i=gap+1;i<(n-gap-1);++i)lay.push_back(mat[i][m-gap-1]);  //lr left-right
        for(int i=m-gap-1;i>=gap;--i)lay.push_back(mat[n-gap-1][i]);//ud up-down
        for(int i=n-gap-2;i>gap;--i)lay.push_back(mat[i][gap]);
        len = lay.size();
        for(int i = 0; i<len;++i){
            act="";
            act+=lay[i];
            act+=lay[(i+1)%len];
            act+=lay[(i+2)%len];
            act+=lay[(i+3)%len];
            // DEBUG(act);
            count+=(act==ans);
        }
    }
    cout<<count<<'\n';
}