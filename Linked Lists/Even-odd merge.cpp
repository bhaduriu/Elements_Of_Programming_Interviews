/*
Get pointer to the last node,
Move all the odd nodes to end,
Delete odd nodes in between,
even->odd
*/

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
struct node* evenodd(struct node* head)
{
    struct node* p=head,*q=head,*m=head;int c=0;
    while(m->next!=NULL)
        m=m->next;
    //O(n)
    struct node* temp=m;
    if(m->data%2)//odd
        c=m->data;
    while(p!=temp)
    {
        if(p->data%2)//odd
        {
            if(p==q)
            {
                p=q->next;
                m->next=newnode(q->data);
                m=m->next;
                free(q);
                q=p;
                head=q;
            }
            else
            {
                q->next=p->next;
                m->next=newnode(p->data);
                m=m->next;
                free(p);
                p=q->next;
            }
        }
        else
        {
            q=p;p=p->next;
        }
    }
    //O(n)
    struct node* mm=head;
    if(c!=0)
    {
        m->next=newnode(p->data);
        while((mm->next)!=temp)
            mm=mm->next;
        //O(n)
        mm->next=temp->next;
    }
    free(p);free(q);free(m);
    free(mm);free(temp);
    return head;
}
int main()
{
    struct node* head=NULL;
    head=newnode(17);
    append(head,15);
    append(head,8);
    append(head,12);
    append(head,10);
    append(head,5);
    append(head,4);
    append(head,1);
    append(head,7);
    append(head,6);
    print(head);
    head=evenodd(head);
    print(head);
    return 0;
}


/*
Append even elements to one list,
Odd elements to the second list,
even->odd 
*/

#include <iostream>
#include <malloc.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node* newnode(int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=x;t->next=NULL;
    return t;
}
void append(struct node* head, int x)
{
    if(head!=NULL)
    {
        struct node* p = head;
        while(p->next!=NULL)
            p=p->next;
        p->next=newnode(x);
    }
}
struct node* evenodd(struct node* head)
{
    struct node* even=NULL,*odd=NULL,*temp=NULL;
    struct node* e=even,*o=odd;struct node* p= head;
    while(p!=NULL)
    {
        temp = newnode(p->data);
        if(p->data%2)//odd
        {
            if(odd==NULL)
                odd=temp;
            else
                o->next=temp;
            o=temp;
        }
        else
        {
            if(even==NULL)
                even=temp;
            else
                e->next=temp;
            e=temp;
        }
        p=p->next;
    }
    e->next=odd;
    o->next=NULL;
    return even;
}
void print(struct node* head)
{
    struct node* p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
    struct node* head=NULL;
    head=newnode(105);
    append(head,15);
    append(head,8);
    append(head,12);
    append(head,10);
    append(head,5);
    append(head,4);
    append(head,1);
    append(head,7);
    append(head,6);
    head=evenodd(head);
    print(head);
}

