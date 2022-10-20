#include <iostream>
#include <string>
using namespace std;
class BigDecimalInt
{
private:
   string num1;
   int size();
   int sign();
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
