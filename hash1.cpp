#include <iostream>
#include <string> 
using namespace std;

struct person {
    string name;
    long int tele;
};

class Htable {
public:

    int size, n,t,it,key;
    struct person h[10];

    Htable() {
        size = 10;
    }

    void initialize() {
        for (int i = 0; i < size; i++) {
            h[i].name = "";
            h[i].tele = 0;
        }}

    void insert() {
        string name; 
        cout << "Enter name & telephone: ";
        cin>>name>>t; 

        int sum=0;
        for (int i=0;i<name.length();i++) { 
            sum+=int(name[i]); 
        }

         key=sum%size;
        int i = key;
        do {
            if (h[i].name == "") { 
                h[i].name = name;
                h[i].tele = t;
                break;
            }
            i = (i+1)%size; 
        } while(i != key); 
    }

void display(){
cout<<"\n";

for (int i =0;i<size;i++) {
            cout<<"\n";
            cout<<h[i].name<< "";
            cout<<h[i].tele;
        }
}
void search(long int t)
{
         bool find;
         int i=key;
         int count;
         count=0;

    do {
            count++;
            if (h[i].tele==t)
            {
                 find = true;
                 cout << "Data Found: " ;
                 cout<<"\n"<< h[i].name << "Telephone: "<< h[i].tele << endl;
                break;
            }
            i = (i + 1) % size;
        } while (i != key);

        if (!find) 
         {
            cout << "Data not found." << endl;
        }
    


      
cout<<"no of comparision required :"<<count;
}
};


int main() {

    Htable ht;
    ht.initialize();
int n;
long int data;
cout<<"Enter no of persons :"<<endl;
cin>>n;
for(int i=0;i<n;i++)

    ht.insert();
   ht.display();

cout<<"\nEnter telephone no to search :";
cin>>data;
ht.search(data);


    return 0;
}
