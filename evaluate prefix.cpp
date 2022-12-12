#include <iostream>
#include<stack>
#include<cmath>
using namespace std;

int main()
{
    stack<int> op;
    stack<char> opr;
    char opre;
    string ex="",c="y";
    while(c=="y"||c=="Y")
    {
        cout<<"Enter Your Expression like :*+5 6 ^-8 5 2 ="<<endl;
        getline(cin,ex);
        int m=0;
        int i=0,op1,op2,opr1;
        while(ex[i]!='=')
        {
            if(ex[i]=='+'||ex[i]=='*'||ex[i]=='-'||ex[i]=='/'||ex[i]=='^')
            {
                opr.push(ex[i]);
                //cout<<ex[i];
            }
            else if(ex[i]!=' ')
            {
                m=10*m+ex[i]-48;
            }
            else
            {
                opr.push(m);
                m=0;
            }
            i++;
        }
        while(!opr.empty())
        {
            opr1=opr.top();
            opre=opr1;
            //cout<<opre<<endl;
            if(opre=='+')
            {
                op1=op.top();
                //cout<<op1<<endl;
                op.pop();
                op2=op.top();
                //cout<<op2<<endl;
                op.pop();
                op.push(op1+op2);
                opr.pop();
            }
            else if(opre=='-')
            {
                op1=op.top();
                op.pop();
                op2=op.top();
                op.pop();
                op.push(op1-op2);
                opr.pop();
            }
            else if(opre=='/')
            {
                op1=op.top();
                op.pop();
                op2=op.top();
                op.pop();
                op.push(op1/op2);
                opr.pop();
            }
            else if(opre=='*')
            {
                op1=op.top();
                op.pop();
                op2=op.top();
                op.pop();
                op.push(op1*op2);
                opr.pop();
            }
            else if(opre=='^')
            {
                op1=op.top();
                op.pop();
                op2=op.top();
                op.pop();
                op.push(pow(op1,op2));
                opr.pop();
            }
            else
            {
                op.push(opr1);
                // cout<<opr1<<endl;
                opr.pop();

            }

        }
          cout<<"*********************************"<<endl;
          cout << "Value of Prefix "<<ex<<" "<<op.top ()<< endl;
          cout<<"*********************************"<<endl;
         op.pop();
        cout<<"Are you went to evaluate another expression ? yes or no\n ";
        getline(cin,c);
    }
    return 0;
}
