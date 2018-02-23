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
    struct node * t = head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}
struct node* cyclic(struct node* head, int k)
{
    struct node *p=head,*q=head,*m=head;
    int n=0,c;
    while(p!=NULL)
    {
        n++;p=p->next;
    }
    c=k%n;p=head;c--;
    while(p->next!=NULL)
        p=p->next;
    while(c--)
        q=q->next;
    while(m!=q)
    {
        p->next=newnode(m->data);
        p=p->next;
        struct node* temp=m;
        m=m->next;
        free(temp);
    }
    return m;
}
int main()
{
    struct node* head=NULL;
    head=newnode(10);
    append(head,20);
    append(head,30);
    append(head,40);
    append(head,50);
    append(head,60);
    print(head);
    head=cyclic(head, 5);
    print(head);
    return 0;
}

