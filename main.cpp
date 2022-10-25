#include <iostream>
#include <string>
using namespace std;
class BigDecimalInt
{
private:
   string num1;
   int size();
   int sign();
   string nineComplement(string s, int LoopLength){
        string result = "";
        int diff = LoopLength - s.size();
        for (int i = LoopLength - 1; i >= 0; i--){
            if (i >= diff){
                result += char(9 - (s[i - diff] - '0') + '0');
            }
            else {
                result += char(9 + '0');
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
public:
   BigDecimalInt (string firstnum)
   {
       num1=firstnum;
   }

//    BigDecimalInt operator- (BigDecimalInt anotherDec);
//    {
//        if (num1[0]!='-' && anotherDec.num1[0]!='-')
//        {
//            if (num1[0]!='-' && anotherDec.num1[0]!='-')
//            {
//// number 0 task 2
//#include <bits/stdc++.h>
//using namespace std;
//int main(){
    string str;
    getline(cin,str);
    for (int i=str.size()-1;i>0;i--){
        if (str[i]==' ' and str[i]==str[i-1] ){
            //deletes character at position i
            str.erase(str.begin() + i );
        }
    }
    for (int i=0;i<str.size();i++){
        str[i]= tolower(str[i]);
    }
    str[0]= toupper(str[0]);
    if (str[str.size()-1]=='.'){
        cout<<str;
    }
    else
       cout<<str<<".";
}
//                if (num1.size()==anotherDec.size())
//                {
//                    if (num1>anotherDec.num1)
//                    {
//
//                    }
//                }
//            }
//        }
//    }
   
       BigDecimalInt operator-(BigDecimalInt s2){
        BigDecimalInt result;
        BigDecimalInt help(decStr);
        int loopLength;
        int len1 = decStr.length();
        int len2 = s2.decStr.length();
        //int num1, num2;
//        if (len1 < 9 && len2 < 9){
//            num1 = int(decStr);
//            decInt = num1;
//            //decInt = stoi(decStr);
//            num2 = int(s2.decStr);
//            s2.decInt = num2;
//            //s2.decInt = stoi (s2.decStr);
//            result.decInt = decInt - s2.decInt;
//        }
        //else {
        if (s2.decStr[0] == '-') {
            s2.decStr.erase(0, 1);
            len2 -= 1;
            //s2.decStr[0] = '0';
            if (decStr[0] == '-') { // - (-num) = + num
                decStr.erase(0, 1);
                len1 -= 1;
                //decStr[0] = '0';
                if (len1 >= len2) {
                    loopLength = len1;
                }
                else{
                    loopLength = len2;
                }
                help.decStr = nineComplement(decStr, loopLength);
                //result.decStr = s2.decStr + decStr;
                result = s2 + help;

                if (result.decStr.length() > loopLength){ // There is a Carry
                    string carry = "";
                    carry.push_back(result.decStr[0]);
                    BigDecimalInt carr (carry);
                    result.decStr.erase(0, 1); // Removes the Carry From the result
                    //result.decStr = result.decStr + carry;
                    result = result + carr;
                }
                else if (result.decStr.length() == loopLength){
                    result.decStr = nineComplement(result.decStr, loopLength);
                    reverse(result.decStr.begin(), result.decStr.end());
                    result.decStr.push_back('-');
                    reverse(result.decStr.begin(), result.decStr.end());
                }
            }
            else if (decStr[0] == '+'){
                decStr.erase(0, 1);
                result = help + s2;
                //result.decStr = decStr + s2.decStr;
            }
            else if (isdigit(decStr[0])){
                //BigDecimalInt help(decStr);
                result = help + s2;
                //result.decStr = decStr + s2.decStr;
            }
        }
        else if (s2.decStr[0] == '+' || isdigit(s2.decStr[0])){
            if (s2.decStr[0] == '+'){
                s2.decStr.erase(0, 1);
                len2 -= 1;
            }
            if (decStr[0] == '-'){
                decStr.erase(0, 1);
                result = help + s2; // The two numbers has the same sign (-ve)
                result.decStr = decStr + s2.decStr;
                reverse(result.decStr.begin(), result.decStr.end());
                result.decStr.push_back('-');
                reverse(result.decStr.begin(), result.decStr.end());
            }
            else if(decStr[0] == '+' || isdigit(decStr[0])){
                if (decStr[0] == '+'){
                 decStr.erase(0, 1);
                 len1 -= 1;
                }
                if (len1 >= len2){
                    loopLength = len1;
                }
                else{
                    loopLength = len2;
                }
                s2.decStr = nineComplement(s2.decStr, loopLength);
                //result.decStr = decStr + s2.decStr;
                result = help + s2;
                if (result.decStr.length() > loopLength){ // There is a Carry, the result is positive
                    //char carry = result.decStr[0];
                    string carry = "";
                    carry.push_back(result.decStr[0]);
                    BigDecimalInt carr (carry);
                    result.decStr.erase(0, 1); // Removes the Carry From the result
                    //result.decStr = result.decStr + carry;
                    //cout << "before: " << result.decStr << endl;
                    result = result + carr;
                    //cout << "After : " << result.decStr << endl;
                }
                else if (result.decStr.length() == loopLength){ //There is no carry, the result is negative
                    result.decStr = nineComplement(result.decStr, loopLength);
                    reverse(result.decStr.begin(), result.decStr.end());
                    result.decStr.push_back('-');
                    reverse(result.decStr.begin(), result.decStr.end());
                }
            }
        }
        //}
        //cout << "decInt= " << result.decInt << endl;
        cout << "decStr= " << result.decStr << endl;
        return result;
    }

   bool operator< (BigDecimalInt anotherDec)
   {
       if (num1[0]!='-' && anotherDec.num1[0]!='-')
       {
           if (num1.size()==anotherDec.num1.size())
           {
               for (int i=0;i<num1.size();i++)
               {
                   if (int(num1[i])<int(anotherDec.num1[i]))
                   {
                       return true;
                   }
                   else if (int(num1[i])>int(anotherDec.num1[i]))
                   {
                       return false;
                   }
               }
           }
           else if (num1.size()>anotherDec.num1.size())
           {
               return false;
           }
           else if (num1.size()<anotherDec.num1.size())
           {
               return true;
           }
       }
       else if (num1[0]!='-' && anotherDec.num1[0]=='-')
       {
           return false;
       }
       else if (num1[0]=='-' && anotherDec.num1[0]!='-')
       {
           return true;
       }
       else if (num1[0]=='-' && anotherDec.num1[0]=='-')
       {
           if (num1.size()==anotherDec.num1.size())
           {
               for (int i=0;i<num1.size();i++)
               {
                   if (int(num1[i])>int(anotherDec.num1[i]))
                   {
                       return true;
                   }
                   else if (int(num1[i])<int(anotherDec.num1[i]))
                   {
                       return false;
                   }
               }
           }
           else if (num1.size()>anotherDec.num1.size())
           {
               return true;
           }
           else if (num1.size()<anotherDec.num1.size())
           {
               return false;
           }
       }
   };




   bool operator> (BigDecimalInt anotherDec)
   {
       if (num1[0]!='-' && anotherDec.num1[0]!='-')
       {
           if (num1.size()==anotherDec.num1.size())
           {
               for (int i=0;i<num1.size();i++)
               {
                   if (int(num1[i])>int(anotherDec.num1[i]))
                   {
                       return true;
                   }
                   else if (int(num1[i])<int(anotherDec.num1[i]))
                   {
                       return false;
                   }
               }
           }
           else if (num1.size()>anotherDec.num1.size())
           {
               return true;
           }
           else if (num1.size()<anotherDec.num1.size())
           {
               return false;
           }
       }
       else if (num1[0]!='-' && anotherDec.num1[0]=='-')
       {
           return true;
       }
       else if (num1[0]=='-' && anotherDec.num1[0]!='-')
       {
           return false;
       }
       else if (num1[0]=='-' && anotherDec.num1[0]=='-')
       {
           if (num1.size()==anotherDec.num1.size())
           {
               for (int i=0;i<num1.size();i++)
               {
                   if (int(num1[i])>int(anotherDec.num1[i]))
                   {
                       return false;
                   }
                   else if (int(num1[i])<int(anotherDec.num1[i]))
                   {
                       return true;
                   }
               }
           }
           else if (num1.size()>anotherDec.num1.size())
           {
               return false;
           }
           else if (num1.size()<anotherDec.num1.size())
           {
               return true;
           }
       }
   };



   bool operator==(BigDecimalInt anotherDec)
   {
       if (num1.size()==anotherDec.num1.size())
       {
           for (int i=0;i<num1.size();i++)
           {
               if (int(num1[i])!=int(anotherDec.num1[i]))
               {
                   return false;
               }
               else if (int(num1[i])==int(anotherDec.num1[i]))
               {
                   if (i==num1.size()-1)
                       return true;
               }
           }
       }
       else
           return false;
   };


   BigDecimalInt& operator= (const BigDecimalInt& anotherDec)
   {
       num1=anotherDec.num1;
       return *this;
   };
   int SZ()
   {
       if (num1[0]=='-')
           return num1.size()-1;
       else
           return num1.size();
   };
   int SIGN()
   {
       if (int(num1[0])=='-')
           return 0;
       else
           return 1;

   };
   friend ostream& operator << (ostream& out, BigDecimalInt b);
};
ostream& operator << (ostream& out, BigDecimalInt b)
{
   out<<b.num1<<endl;
   return out;
};


int main()
{
   string no1,no2,my_signed_num,size_number,no11,no22;

   cout<<"please enter the 2 numbers you want operate on them the less than operation"<<endl;
   cin>>no11>>no22;
   BigDecimalInt number11(no1);
   BigDecimalInt mynumm(no2);
   bool anss = number11<mynumm;
   if (anss==1)
       cout<<no1<<" is less than "<<no2<<endl;
   else if (anss==0)
       cout<<no2<<" is less than "<<no1<<endl;


   cout<<"please enter the 2 numbers you want operate on them the greater than operation"<<endl;
   cin>>no1>>no2;
   BigDecimalInt number1(no1);
   BigDecimalInt mynum(no2);
   bool ans = number1>mynum;
   if (ans==1)
       cout<<no1<<" is greater than "<<no2<<endl;
   else if (ans==0)
       cout<<no2<<" is greater than "<<no1<<endl;


   bool equality= no1==no2;
   if (ans==1)
       cout<<no1<<" is equal to "<<no2<<endl;
   else if (ans==0)
       cout<<no1<<" isn't equal to "<<no2<<endl;


   cout<<"please enter the number you want to know its size"<<endl;
   cin>>size_number;
   int mysz=number1.SZ();
   cout<<mysz;

   cout<<"please enter the number you want to know its sign"<<endl;
   cin>>my_signed_num;
   int mysign=number1.SIGN();
   if (mysign==1)
       cout<<'+'<<endl;
   else
       cout<<'-'<<endl;

}
