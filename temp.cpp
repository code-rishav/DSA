#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string convertToTitle(int columnNumber) {
        string s="";
        int n=0;
        while(columnNumber>pow(26,n)){n++;}
        n = n-1;
        int check = columnNumber;
        int dum = n;
        cout<<n<<endl;
        while(dum>0){
            check = check - pow(26,dum);
            dum--;
        }
        if(check<0)
            n = n-1;

        while(columnNumber!=0){
            int temp = 64+ (int)(columnNumber/(pow(26,n)));
            cout<<temp<<endl;
            s+= char(temp);
            columnNumber = columnNumber % (int)(pow(26,n));
            n--;                               
        }
        return s;
    }
int main(){
    string s1 = convertToTitle(701);
    cout<<s1<<endl;
}