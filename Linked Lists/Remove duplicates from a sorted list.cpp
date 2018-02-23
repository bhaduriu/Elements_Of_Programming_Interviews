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
struct node* remove(struct node* head)
{
    struct node* p=head,*q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=p->next;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
    return head;
}
int main()
{
    struct node* head=NULL;
    head=newnode(2);
    append(head,2);
    append(head,2);
    append(head,5);
    append(head,7);
    append(head,11);
    append(head,11);
    print(head);
    head=remove(head);
    print(head);
    return 0;
}

