#include<iostream>
using namespace std;
struct node
{
   int data;
   struct node *next;
};

struct node *adjlist[10];
int n,visit[10];

void bfs(int s)
{
  int q[10];
  int r=0;
  int f=0;
  for(int i=1;i<=n;i++)
  {
      visit[i]=0;
  }
  
 q[r]=s;
 r++;
 cout<<s;
 visit[s]=1;

while(f!=r)
{
  int c=q[f];
  node * temp=adjlist[c];
  while(temp!=NULL)
  {
       if(visit[temp->data]!=1)
       {
          cout<<temp->data;
          visit[temp->data]=1;
          q[r]=temp->data;
          r++;
       }
      temp=temp->next;
         
  }
} 
  
}


int main()
{
   int s;
   int y;
   cout<<"Enter the no nodes :"<<endl;
   cin>>n;

   for(int i=1;i<=n;i++)
  {
      adjlist[i]=NULL;
  }

   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
     {
        cout<<"node between "<< i <<" to "<< j <<":";
        cin>>y;

          if(y==1)
          {
            struct node *n;
            n=new node;
            n->data=j;
            n->next=NULL;
            if(adjlist[i]==NULL)
            {
                adjlist[i]=n;
            }
            else
             {
               struct node *temp;
               temp=adjlist[i];
               while(temp->next!=NULL)
               {
                  temp=temp->next;
               }

                temp->next=n;
             }
            
          }
     }
   }

  cout<<"Enter current node :"<<endl;
  cin>>s;
  
  bfs(s);
return(0);
 
}



