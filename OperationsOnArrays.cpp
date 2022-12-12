#include <iostream>

using namespace std;
void createarray(int x[],int size);
void deletarray(int x[]);
void insertarray(int x[]);
void desplayarray( int x[]);
void searcharray(int x[],int item);
int n,x,pos,loc,l,op,item;
const int asize=10;
int main()
{
int a[asize]={0};

   while(true){
   cout<<"----------------------------------------------------------\n";
   cout<<"|**choose of operation from the following :               |";
   cout<<"\n|1. create array                                          |";
   cout<<"\n|2. Desplay array                                         | ";
   cout<<"\n|3. delete element of array :                             |";
   cout<<"\n|4. insert element to array:                              |";
   cout<<"\n|5. Search about element in array                         |";
   cout<<"\n|6. Exit                                                  |";
   cout<<"\n----------------------------------------------------------\n";
   cout<<"Enter choice :";
    cin>>op;
    if(op==1){
        cout << "Enter Size of array : " ;
          cin>>n;
    createarray(a,n);
    }
    if(op==2){
             desplayarray(a);
     }




  if(op==3){

         deletarray(a);

}
if(op==4){
        insertarray(a);

}
if(op==5){
    cout<<"enter element that you need to search it : ";
    cin>>item;
    searcharray(a,item);
}
if(op==6){return 0;}
if(op>6||op<1)
    cout<<" invalid choice ..... tray again \n";   }
}


void createarray(int a[],int n){


  //  int a[n];
    cout<<"\nEnter Element of array : \n";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
}
void desplayarray(int a[]){
    cout<<" ---------------------------------------\n";
 cout<< "|     Element of an array              |\n";
    cout<<"| [";
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"]                        \n";
    cout<<"|--------------------------------------|\n";
}
void deletarray(int a[]){
cout<<"-------------------------------\n";
     cout << "Enter position of Element that you need to delete from array : " ;
     cin>> pos;
     if( pos>n  ||pos<=0){
            cout<<" --------------\n"<<"|Out of Bounded |\n --------------\n";}
     else{
         x=a[pos-1];
        for (int i=pos-1;i<n;i++){
        a[i]=a[i+1];
    }

    n--;

    cout<<"---------------------------\narray after delete \n";
    cout<<"[ ";     // because delete one element from array so that size =size -1
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
     cout<<"] \n----------------------------\n"<<"Element that delete is : "<<x<<" from position "<<pos;
 cout<<"] \n----------------------------\n";
        }
        }
void insertarray(int a[]){
    cout<<"\n-------------------------------\n";
     cout << "Enter location of Element that you need to insert to array : " ;
     cin>> loc;
     n++;
     cout<<"\nEnter Element that you need to insert to array : ";
     cin>>l;
     for (int i=n;i>loc-1;i--){
        a[i]=a[i-1];
     }
     a[loc-1]=l;
     cout<<"\n----------------------------\n insert successful   \n";

}
void searcharray(int a[],int x){
    bool found=false;
    int lo;
for(int i=0;i<n;i++){
    if(a[i]==x){
        found=true;
        lo=i+1;
    }
    }
    if(found){
             cout<<"\n------------------------------------------------\n";
        cout<<"element " <<x<<" is found in position "<<lo<<endl;
     cout<<"\n------------------------------------------------\n";
    }
    else{
             cout<<"\n------------------------------------------------\n";
        cout<<"element "<<x<<" is not found in array \n";
     cout<<"\n------------------------------------------------\n";
    }
}


