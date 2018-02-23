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
}
struct node* kth(struct node* head, int k)
{
    struct node* f=head,*s=head,*p=head;int l=k;
    while(k--)
        f=f->next;
    if(f->next==NULL)
    {
        cout<<head->data<<endl;
        struct node* temp=head;
        temp=head->next;
        free(head);
        return temp;
    }
    while(f->next!=NULL)
    {
        p=s;
        s=s->next;f=f->next;
    }
    if(f->next==NULL)
    {
        cout<<s->data<<endl;
        p->next=s->next;
        free(s);
    }
    return head;
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
    append(head,7);
    cout<<"Enter the kth last node to remove: ";
    int k;cin>>k;
    head=kth(head,k-1);
    cout<<"Entire list after removal:"<<endl;
    print(head);
    return 0;
}

