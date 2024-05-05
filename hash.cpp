#include<iostream>
#include<string.h>
using namespace std;

struct people
{
   string name[20];
   long int tel;
};

class hashdemo
{
public:
   int size;
   string na[20];
   long int t;
   struct people htable[20];

 public:
   hashdemo()
  {
    cout<<"Enter Size :";
    cin>>size;
  }
  
 void get()
 {
    for(int i=0;i<size;i++) 
    {
        htable[i].name="";
        htable[i].tel=0;
    }
 } 

void insert()
{  
   cout<<"Enter name :"<<endl;
   cin>>na;
   cout<<"Enter telephone :"<<endl;
   cin>>t;

   int i=0,sum=0;
   for(int i=0;i<na.length();i++)
   {
       sum=sum+int(na[i]);
       i++;
   }
  int key=sum%size;
 do
{
  int i=key;
  //for(int i=key;i<size;i=i%size)
  
    if(htable[i].name=="")
    {
        htable[i].name=na;
        htable[i].tel=t;        
    }
    i=(i+1)%size;
 }while(i!=key); 
}

};

int main()
{

 hashdemo h1;
 h1.get();
 h1.insert();
 return(0);

}
