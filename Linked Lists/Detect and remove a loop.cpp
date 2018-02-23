#include <iostream>
#include <malloc.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
    int count;
};
struct node* newnode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->count=0;
    temp->next=NULL;
    return temp;
}
void append(struct node* head, int data)
{
    if(head!=NULL)
    {
        struct node* p = head;
        while(p->next!=NULL)
            p=p->next;
        struct node* temp = newnode(data);
        p->next=temp;
    }
}
void print(struct node * head)
{
    struct node * t = head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
}
void detectloop(struct node* head)
{
    struct node* p = head,*q;
    while(p!=NULL)
    {
        if(p->count==2)
            break;
        (p->count)++;
        p=p->next;
    }
    cout<<"Loop detected at "<<p->data<<endl;
    q=p;q=q->next;
    while(q->next!=p)
    {
        q=q->next;
    }
    q->next=NULL;
    cout<<"Loop removed."<<endl;
}
int main()
{
    struct node* head=NULL;
    head=newnode(1);
    append(head,2);
    append(head,3);
    append(head,4);
    append(head,5);
    append(head,6);
    struct node* p = head, *q = head;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    while(p!=NULL)
    {
        if(p->data==5)
        {
            break;
        }
        p=p->next;
    }
    q->next=p;
    detectloop(head);
    print(head);
    return 0;
}

