int dp_SO(string& s, string& t) {
    int n = s.size(), m = t.size();
    
    vector<int> prev(m+1, 0), curr(m+1, 0);
    prev[0] = 1;  // Base case
    
    for(int r = 1; r <= n; r++){
        curr[0] = 1;  // Reset base case for each row
        for(int c = 1; c <= m; c++){
            if (s[r-1] == t[c-1]) 
                curr[c] = (long long)prev[c-1] + prev[c];
            else 
                curr[c] = prev[c];
        }
        prev.swap(curr);
    }
    
    return prev[m];
}
