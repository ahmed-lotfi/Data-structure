#include <iostream>

using namespace std;

int main()
{
    int que[5],frent=-1,rear=-1,num=0,x,y,ch;
    bool f=false,e=false;

    while(1)
{
cout<<"\n*****Menu for QUEUE operations*****\n\n";
cout<<"1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n";
cout<<"Enter Choice:";
cin>>ch;

if (frent==-1||frent>rear){
         frent=rear=-1;
        e=true;
    }
    else{
        e=false;
    }
    if (rear>=4){

        f=true;
    }
    else{
        f=false;
    }
    if(ch==1){

       if(f){
        cout<<"Queue is Over flow \n";
    }
    else if(frent>rear){
            frent=rear=-1;
    }
    else{
            if(frent==-1){
              frent=0;
            }

        rear++;
        cout<<"Enter element to add to Queue :\n";
        cin>>x;
        que[rear]=x;
        cout<<"insert successful \n";
    }

    }
if(ch==2){
    if(e){
        cout<<"Queue is Under flow \n";
    }
    else{
         y=que[frent];
         frent++;
        cout<<"delete successful  :: element delete from queue is  "<<y;
    }
}

    if(ch==3){

        if(e){
        cout<<"Queue is Under flow \n";
    }
    else{
         for(int i=frent;i<=rear;i++){
            cout<<que[i]<<" ";
         }
    }
    }

   if(ch==4){
    return 0;
   }

}
}
