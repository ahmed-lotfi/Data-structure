#include <iostream>
#include<stack>
using namespace std;
int main()
{
    stack<char> s;
    string ex="",r="",c="y";
    while(c=="Y"||c=="y"){// for convert a lot of one  expression
        cout<<"Enter Your Expression : "<<endl;
        getline(cin,ex);
    int i=0,l=ex.size();
    while(i<l)
    {
        if(ex[i]=='+'||ex[i]=='*'||ex[i]=='-'||ex[i]=='/'||ex[i]=='('||ex[i]=='^')
        {
            s.push(ex[i]);
            r=r+" ";
        }
        else
        {
            if(ex[i]==')')
            {
                while(s.top()!='(')
                {
                    r=r+s.top();
                    s.pop();
                }
                s.pop();
            }
            else
            {
                r=r+ex[i];
            }

        }
        i++;
    }
    while(!s.empty())
    {
            r=r+s.top();
            s.pop();
    }
    cout<<"*********************************"<<endl;
    cout <<" Postfix is : "<<r<<endl;
    cout<<"*********************************"<<endl;
    r="";
     cout<<"Are you went to evaluate another expression ? Y or N \n ";
     getline(cin,c);
    }
    return 0;
}
