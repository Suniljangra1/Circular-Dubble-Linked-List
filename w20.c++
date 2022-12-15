// implement curculor Double link list ✌✌
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int value;
    Node *pre;
    Node  *next;
     Node()
     {
        value= 0;
        pre=NULL;
        next = NULL;
     }
};
class CDL
{
    Node *head;
    public:
    CDL()
    {
        head = NULL;
    }
    void insert(int v)
    {
        Node *temp = new Node();
        temp->value = v;
        if(head ==  NULL )
        {
            head = temp ;
            temp->pre=temp;
            temp->next=temp;
        }
        else{
           Node *s = head->pre;
           s->next=temp;
           temp->pre=s;
           temp->pre=head->pre;
           head->pre= temp;       
        } 
    }
    void insert_Begin(int v)
    {
        Node *temp = new Node();
        temp->value=v;
        if(head == NULL)
        {
            head = temp;
            temp->next=temp;
            temp->pre = temp;
        }
        else {
            Node *s = head->pre;
            temp->next=head;
            head->pre=temp;
            s->next=temp->pre;
            temp->pre=s;
            head = temp;
        }
    }
    void insert_end(int v)
    {
        Node *temp = new Node();
        temp->value = v;
        if(head == NULL)
        {
            head = temp;
            temp->next = temp;
            temp->pre = temp;
        }
        else {
            Node *s = head->pre;
            s->next = temp;
            temp->pre = s;
            head ->pre = temp->next;
            head->pre= temp;
        }
    }
    void insert_Middle(int v,int n)
    {
        Node *temp = new Node();
        temp->value = v;
        if ( n == 1)
        {
            this->insert_Begin(v);
        }
       
        else {
            Node *s = head ;
            while(n-1)
            {
                n--;
                if(s->next!=head)
                {
                    cout<<"Index Not Valid \n";
                    return;
                }
                s = s->next;
            }
            temp->next = s->next;
            s->next = temp;
            temp ->pre = s;
            temp->next->pre = temp;  
        } 
    }
    void Delete_first()
    {
        if(head == NULL)
        {
            cout<<"value Unvailable ";
        }
        else {
            Node *s = head;
            head=s->next;
            head ->pre->next= s->next;
            s->next= head;
          
        }
    }
    void Delete_Middle(int n)
    {
        if(n==1)
        {
            this->Delete_first();
        }
        else 
        {
            Node *s = head;
            while(n-2)
            {
                n--;
                 if(s->next!=head)
                {
                    cout<<"Index Not Valid ";
                    return;
                }
                s = s->next;
            }
            s=s->next;
            s->pre->next = s->next;
            s->next=s->pre->next;
            delete s;
        }
    }
    void Print_()
    {
        Node *temp = head;
        while(temp->next!=head)
        {
            cout<<temp->value<<" <=> ";
            temp=temp->next;
        }
    }
    void Search_(int v)
    {
        int r=0;
        if(head==NULL)
        cout<<"value not exit ";
        else { Node *s= head;
            while(s!=head)
            {
               if(s->value == v){
                cout<<"Value founded on  index \n";
                return;
               }
               s=s->next;
            }
             cout<<"Value Not founded\n";
        }
       
    }
};
int main()
{
    CDL c;
   

     while(1)
    {
        cout<<"\n....................................................................\n";
        cout<<"1 For Insert Element \n";
        cout<<"2 For Insert Element in Begin \n";
        cout<<"3 For Insert Element in End \n";
        cout<<"4 For Insert Element in Any Position \n";
        cout<<"5 For Delete First Element \n";
        cout<<"6 For Delete Any Element \n";
        cout<<"7 For Search Any Value \n";
        cout<<"8 For Print All Value \n";
        cout<<"9 For Exit \n";
        cout<<"\nEnter Your Choice \n";

        int choice,r,s;
        cin>>choice;
        switch(choice )
        {
            case 1: 
                 cout<<"Enter value ";
                 cin>>r;
                 c.insert(r);
            break;
            case 2:
                 cout<<"Enter value ";
                 cin>>r;
                 c.insert_Begin(r);
            break;
            case 3: 
                 cout<<"Enter value ";
                 cin>>r;
                 c.insert_end(r);
            break;
            case 4:
                 cout<<"Enter value \n";
                 cin>>r;
                 cout<<"Ok then Enter index ";
                 cin>>s;
                 c.insert_Middle(r,s);
            break;
            case 5:
                 c.Delete_first();
            break;
            case 6:
                 cout<<"Enter value ";
                 cin>>r;
                 c.Delete_Middle(r);
            break;
            case 7:
                 cout<<"Enter value ";
                 cin>>r;
                 c.Search_(r);
            break;
            case 8:
                 c.Print_();
            break;
            case 9:
                 exit(0);
            break;
            default:
                 cout<<"Please Enter a Valid Choice ";
            break;
        }

    }
}