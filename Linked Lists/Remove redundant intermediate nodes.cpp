#include <iostream>
#include <malloc.h>
using namespace std;
struct node{
    int x,y;
    struct node* next;
};
struct node* newnode(int x, int y)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->x=x;temp->y=y;temp->next=NULL;
    return temp;
}
void append(struct node* head, int x, int y)
{
    if(head!=NULL)
    {
        struct node* p = head;
        while(p->next!=NULL)
            p=p->next;
        struct node* temp = newnode(x,y);
        p->next=temp;
    }
}
void print(struct node * head)
{
    struct node *t = head;
    while(t!=NULL)
    {
        cout<<"("<<t->x<<","<<t->y<<")"<<"->";
        t=t->next;
    }
    cout<<"NULL"<<endl;
}
struct node* compute(struct node* head)
{
    struct node* p=head,*q=head,*r=head;
    r=r->next;r=r->next;q=q->next;
    while(r!=NULL)
    {
        if((p->y==q->y)&&(q->y==r->y) || (p->x==q->x)&&(q->x==r->x))
        {
            p->next=r;
            free(q);
            q=r;
            r=r->next;
        }
        else
        {
            r=r->next;
            q=q->next;
            p=p->next;
        }
    }
    return head;
}
int main()
{
    struct node* head=NULL;
    head=newnode(5,6);
    append(head,7,6);
    append(head,7,4);
    append(head,7,3);
    append(head,8,3);
    append(head,8,2);
    append(head,8,1);
    append(head,9,1);
    append(head,10,1);
    append(head,10,0);
    append(head,11,0);
    cout<<"Before Removal of Duplicates: "<<endl;
    print(head);
    cout<<"After Removal of Duplicates: "<<endl;
    head=compute(head);
    print(head);
    return 0;
}


