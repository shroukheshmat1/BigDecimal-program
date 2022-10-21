#include <bits/stdc++.h>
using namespace std;
class BigDecimalInt{
    private: string decStr;
                int decInt;
    public:
    BigDecimalInt(){
        decStr="";
        decInt=0;
    }
    BigDecimalInt (string str){
        decStr=str;
        for (int i=0;i<str.size();i++){
            if ((str[0]=='-'||str[0]=='+')&& isdigit(str[i+1] )){
                continue;
            }
            if(isdigit(str[i])){
                continue;
            }
            else cout<<"invalid input\n";
            break;
        }
    }
    BigDecimalInt(int Int){
        decInt=Int;

    }

    int getDecInt() const {
        return decInt;
    }


    BigDecimalInt operator+(BigDecimalInt s1) {
        BigDecimalInt sum;
        if (decStr.length() > s1.decStr.length())
            swap(decStr, s1.decStr);
         sum.decStr = "";
        int len1 =decStr.length();
        int len2 = s1.decStr.length();
        int digitDiff = len2 - len1;
        int carry = 0;
        int intSum;
        for (int i=len1-1; i>=0; i--) {
            intSum = ((decStr[i]-'0') + (s1.decStr[i+digitDiff]- '0') + carry);
            sum.decStr.push_back(intSum%10 + '0');
            carry = intSum/10;
        }
        for (int i=digitDiff-1; i>=0; i--) {
            intSum = ((s1.decStr[i]-'0')+carry);
            sum.decStr.push_back(intSum%10 + '0');
            carry = intSum/10;
        }
        if (carry)
            sum.decStr.push_back(carry+'0');
        reverse(sum.decStr.begin(), sum.decStr.end());
       // return sum;
        cout<<sum.decStr;
    }
};
int main(){
    BigDecimalInt();
    cout<<"input two numbers \n";
    int isum;
    string num1,num2;
    int inum,inum2;
    cin>>num1>>num2;
    if(num1.size()<9 && num2.size()<9){
        inum=stoi(num1);
        inum2=stoi(num2);
        BigDecimalInt obj(inum) ;
        BigDecimalInt obj2(inum2) ;
        isum=obj.getDecInt()+obj2.getDecInt();
        cout << "small sum = \n";
        cout<<isum<<endl;
    }
    else {
        BigDecimalInt f(num1);
        BigDecimalInt s(num2);
        cout << "sum = \n";
        BigDecimalInt sum = f + s;

    }
}
