// https://leetcode.com/problems/count-and-say/

// base problem solution:
#include<bits/stdc++.h>
using namespace std;

int main() {

    string str = "3322251"; // 23321511
    string ans = "";
    int n = str.length();
    int count = 1;
    for(char ch=1; ch<n; ch++) {
        if(str[ch]!=str[ch-1]){
            ans+= to_string(count);
            ans+= str[ch-1];
            if(ch==n-1) {
                ans+= "1";
                ans+= str[ch];
            }
            count = 1;
        }
        else if(str[ch] == str[ch-1]){
            count++;
        }
    }

    cout<<"Answer: "<<ans<<endl;

    return 0;
}

// main solution: 
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str = countAndSay(n-1);
        // str = 3322251 -> 233321511
        string ztr = "";
        int freq = 1;
        char ch = str[0];
        for(int i=1; i<str.length(); i++){
            char dh = str[i];
            if(ch==dh){
                freq++;
            } else {
                ztr+=(to_string(freq)+ch);
                freq = 1;
                ch = dh;
            }
        }
        ztr+=(to_string(freq)+ch);
        return ztr;
    }
};
