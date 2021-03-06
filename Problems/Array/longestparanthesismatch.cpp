#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(string s){
    stack<char> s1;
    for(char c:s){
        if(c == '('){
            s1.push('(');
        }
        else if(c == ')' && !s1.empty()){
            s1.pop();
        }
        else{
            return false;
        }
    }
    return s1.empty();
}
int getMax(string s){
    map<string,int> m;
    int max = 0;
    if(check(s)){
        return s.length();
    }
    for(int i=0;i<s.length()-1;i++){
        for(int j = 1 ;j<=s.length()-i;j++){
            string s2 = s.substr(i,j);
            if(m.find(s2) != m.end()){
                cout<<s2<<endl;
                if(m[s2] > max){
                        max = m[s2];
                    }
                    continue;
            }
            else{
                if(s2.length() >= 2){
                    // cout<<s2<<endl;
                    if(check(s2)){
                        int c = s.substr(i,j).length();
                        m[s2] = c; 
                        if(c > max){
                            max = c;
                        }
                    }
                }
            }
            
        }
    }
    for(auto const &val:m){
        cout<<val.first<<"->"<<val.second<<endl;
    }
    return max;
}
int main(){
    string s ="((())())(()))(()()(()(()))(()((((()))))))((()())()))()()(()(((((()()()())))()())(()()))((((((())))((()))()()))))(()))())))()))()())((()()))))(()(((((())))))()((()(()(())((((())(())((()()(()())))())(()(())()()))())(()()()))()(((()())(((()()())))(((()()()))(()()))()))()))))))())()()((()(())(()))()((()()()((())))()(((()())(()))())())))(((()))))())))()(())))()())))())()((()))((()))()))(((())((()()()(()((()((())))((()()))())(()()(()))))())((())))(()))()))))))()(()))())(()())))))(()))((())(()((())(((((()()()(()()())))(()())()((()(()()))(()(())((()((()))))))))(()(())()())()(()(()(()))()()()(()()())))(())(()((((()()))())))(())((()(())())))))())()()))(((())))())((()(()))(()()))((())(())))))(()(()((()((()()))))))(()()()(()()()(()(())()))()))(((()(())()())(()))())))(((()))())(()((()))(()((()()()(())()(()())()(())(()(()((((())()))(((()()(((()())(()()()(())()())())(()(()()((()))))()(()))))(((())))()()))(()))((()))))()()))))((((()(())()()()((()))((()))())())(()((()()())))))))()))(((()))))))(()())))(((()))((()))())))(((()(((())))())(()))))(((()(((((((((((((())(((()))((((())())()))())((((())(((())))())(((()))))()())()(())())(()))))()))()()()))(((((())()()((()))())(()))()()(()()))(())(()()))()))))(((())))))((()()(()()()()((())((((())())))))((((((()((()((())())(()((()))(()())())())(()(())(())(()((())((())))(())())))(()()())((((()))))((()(())(()(()())))))))))((()())()()))((()(((()((()))(((((()()()()()(()(()((()(()))(()(()((()()))))()(()()((((((()((()())()))((())()()(((((()(()))))()()((()())((()())()(())((()))()()(()))";
    cout<<getMax(s)<<endl;
}