#include <iostream>

using namespace std;
const int maxsize=10;
int top=-1;
void clearstack(int x[]);
bool emptystack(int x[]);
bool fullstack(int x[]);
void push(int x[],int l);
void pop(int x[]);
void desplay(int x[],int top);

int main()
{
    int stack1[maxsize]={0},choice;
  while(true){
        cout<<"\n\n----------------------------------------------------------\n";
        cout<<"|          *****Stack operations*****                     | \n";
        cout<<"---------------------------------------------------------- \n";
        cout<<"|1.ClearStack                                             |\n";
        cout<<"|2.DISPLAY                                                |\n";
        cout<<"|3.PUSH                                                   |\n";
        cout<<"|4.POP                                                    |\n";
        cout<<"|5.EXIT                                                   |\n";
        cout<<"----------------------------------------------------------\n";
cout<<"Enter Choice:";
cin>>choice;
switch(choice)
{
    case 1:
    clearstack(stack1);
    break;
    case 2:
    desplay(stack1,top);
    break;
    case 3:{
    int x;
    cout<<"Enter  element to push onto stack: ";
    cin>>x;
    push(stack1,x);}
    break;
    case 4:
    pop(stack1);
    break;

    case 5:
    return 0;
    default:cout<<"Invalid choice...Try again...\n";
}
}
  }



void clearstack(int stack1[]){
    top=-1;

}
bool emptystack(int stack1[]){
  if (top==-1){
    return true;
}else{

return false;
}
}
bool fullstack(int stack1[]){
  if (top==maxsize-1){
    return true;
}else{

return false;
}
}
void push(int stack1[],int element){
if(fullstack(stack1)){
    cout<<"----------------------------------------------------------\n";
    cout<<"|            Stack OverFlow                               |\n";
    cout<<"----------------------------------------------------------\n";
}else{
top++;
stack1[top]=element;
cout<<"----------------------------------------------------------\n";
cout<<"|            Pushed Successfully onto stack....          |\n";
cout<<"----------------------------------------------------------\n";
}

}
void pop(int stack1[]){
if(emptystack(stack1)){
    cout<<"----------------------------------------------------------\n";
    cout<<"|               Stack UnderFlow                          |\n";
    cout<<"----------------------------------------------------------\n";
}else{
int element=stack1[top];
--top;
cout<<"----------------------------------------------------------\n";
cout<<"|element "<<element<<" is poped Successfully from stack         |\n";
cout<<"----------------------------------------------------------\n";
}

}
void desplay(int stack1[],int top){
if(top==-1){
        cout<<"----------------------------\n";
        cout<<"|   Stack Under Flow        |\n";
        cout<<"----------------------------\n";
}else{
    cout<<"  Elements in the Stack are....\n";
for(int i=top;i>-1;i--)
    {
cout<<"     | "<<stack1[i]<<"     |\n";

}
cout<<"     ---------\n";
}
}
