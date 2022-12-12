#include <iostream>
#include<stack>
#include<cmath>
using namespace std;

int main()
{
    stack<int> s;
    string ex="",ch="y";
    int op1,op2,re,m=0;
    while(ch=="y"||ch=="Y")//for  evaluate a lot of one expression
    {
        cout<<"Enter Your Expression like :14 5 +44 3 -+3 1 -^="<<endl;
        getline(cin,ex);
        // cout<<ex<<endl; //for test
        int i=0;
        while(ex[i]!='=')
        {
            //cout<<"sa:"<<i<<endl;//for test
            if(ex[i]=='+'||ex[i]=='*'||ex[i]=='-'||ex[i]=='/'||ex[i]=='^')
            {
                if(ex[i]=='+')
                {
                    op2=s.top();
                    // cout << op1 << endl;//for test
                    s.pop();
                    op1=s.top();
                    s.pop();
                    re=op1+op2;
                    //  cout << re<< endl;//for test
                    s.push(re);
                }
                else if(ex[i]=='*')
                {
                    op2=s.top();
                    // cout << op1 << endl;//for test
                    s.pop();
                    op1=s.top();
                    s.pop();
                    re=op1*op2;
                    //cout << re<< endl;//for test
                    s.push(re);
                }
                else if(ex[i]=='-')
                {
                    op2=s.top();
                    // cout << op1 << endl;//for test
                    s.pop();
                    op1=s.top();
                    s.pop();
                    re=op1-op2;
                    //cout << re<< endl;//for test
                    s.push(re);
                }
                else if(ex[i]=='/')
                {
                    op2=s.top();
                    // cout << op1 << endl;//for test
                    s.pop();
                    op1=s.top();
                    s.pop();
                    re=op1/op2;
                    //cout << re<< endl;//for test
                    s.push(re);
                }
               else if(ex[i]=='^')
                {
                    op2=s.top();
                    // cout << op1 << endl;//for test
                    s.pop();
                    op1=s.top();
                    s.pop();
                    re=pow(op1,op2);
                    //  cout << re<< endl;//for test
                    s.push(re);
                }
            }
            else
            {
                //  cout<<"ex "<<ex[i]<<endl;//for test

                if(ex[i]!=' ')
                {
                    m=10*m+(int)ex[i]-48; //because the ASSCII code of 0 is 48
                    // cout<<"m  "<<m<<endl;//for test
                }

                else
                {
                    s.push(m);
                    // cout<<m<<endl;//for test
                    m=0;
                }
            }
            i++;
        }
        i=0;
       /* while(!s.empty())
        {
            re=s.top();
            // cout << "st: "<<re << endl;//for test
            s.pop();
        }*/
          cout<<"*********************************"<<endl;
          cout << "Value of Postfix "<<ex<<" "<<s.top ()<< endl;
          cout<<"*********************************"<<endl;
        ex= "";
        s.pop();
        cout<<"Are you went to evaluate another expression ? yes or no\n ";
        getline(cin,ch);
    }
    return 0;
}
