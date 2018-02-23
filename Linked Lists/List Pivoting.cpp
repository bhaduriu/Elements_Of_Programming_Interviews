#include <iostream>
#include <malloc.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node* newnode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;temp->next=NULL;
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
    struct node *t = head;
    while(t!=NULL)
    {
        cout<<t->data<<"->";
        t=t->next;
    }
    cout<<"NULL"<<endl;
}
struct node* dutch(struct node* head, int x)
{
    struct node* p = head, *less = NULL, *equal = NULL, *high = NULL;
    struct node* l=less,*e=equal,*h=high;
    while(p!=NULL)
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=p->data;temp->next=NULL;
        if(p->data<x)
        {
            if(less==NULL)
                less=temp;
            else
                l->next=temp;
            l=temp;
        }
        else if(p->data==x)
        {
            if(equal==NULL)
                equal=temp;
            else
                e->next=temp;
            e=temp;
        }
        else
        {
            if(high==NULL)
                high=temp;
            else
                h->next=temp;
            h=temp;
        }
        p=p->next;
    }
    e->next=high;
    l->next=equal;
    free(l);free(e);free(h);
    free(equal);free(high);
    free(p);
    return less;
}
int main()
{
    struct node* head=NULL;
    head=newnode(3);
    append(head,2);
    append(head,2);
    append(head,11);
    append(head,7);
    append(head,5);
    append(head,11);
    print(head);
    head=dutch(head,7);
    print(head);
    return 0;
}


