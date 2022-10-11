#include <iostream>
#include <string>
using namespace std;
string convert(string a,string b){
        int len1,len2,sum,carry=0,minm,maxm;
        string s,s1,s2;
        char c1,c2,ch;
        len1 = a.length();
        len2 = b.length();
        if(len1>len2){
            maxm = len1-1;
            minm = len2-1;
            s1 = a;
            s2 = b;
        }
        else{
            maxm = len2-1;
            minm = len1-1;
            s1 = b;
            s2 = a;
        }
        int r = maxm - minm;
       
        for(int i=minm;i>=0;i--){
            c1 = s1[i+r];
            c2 = s2[i];

            if(c1=='0'&&c2 =='1'||c2=='0'&&c1 =='1'){
                if(carry){
                    s =  '0'+s;
                    carry = 1;
                }
                else
                    s ='1'+s;
            }
            else if(c1=='1'&& c2=='1'||c2=='1'&& c1=='1'){
                if(carry){
                    s = '1'+s;
                    carry = 1;
                }
                else{
                    s = '0'+s;
                    carry = 1;
                }
            }
            else{
                if(carry)
                    s = '1'+s;
                else
                    s = '0'+s;
                carry = 0;
                
            }
        
            
        }
        cout<<s<<endl;
        cout<<carry<<endl;
        for(int i=r-1;i>=0;i--){
            ch = s1[i];
            if(ch=='1'){
                if(carry){
                    s = '0'+s;
                    carry = 1;
                }
                else{
                    s = '1'+s;
                }
            }
            else{
                if(carry){
                    s = '1'+s;
                    carry = 0;
                }
                else{
                    s = '0'+s;
                }
            }
        }
        if(carry)
            s = '1'+s;
        return s;
}
int main(){
    string s1 = convert("1101110111","1101");
    cout<<s1<<endl;
}