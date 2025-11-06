unordered_map<int,int> mp;
    
for(auto &x: arr){
    mp[x]++;
}
    
return mp[target];
