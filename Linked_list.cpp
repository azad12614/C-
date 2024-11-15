#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct Node
{
    ll data;
    Node *link;
};

Node *head,*last;

void push(ll n)
{
    Node *next = new Node;

    next->data = n;
    next->link = NULL;

    if(head == NULL)
    {
        head = next;
        last = next;
    }
    else
    {
        last->link = next;
        last = next;
    }
}

void pushat(ll n, ll l)
{
    Node *next = new Node;

    next->data = n;

    Node *temp = head;

    ll t=1;
    while(t!=l && temp!=NULL)
    {
        temp = temp->link;
        t++;
    }

    if(temp==NULL)
        last = next;

    next->link = temp->link;
    temp->link = next;
}

void pushafter(ll n, ll v)
{
    Node *next = new Node;

    next->data = n;

    Node *temp = head->link;

    ll t = temp->data;
    while(t!=v && temp!=NULL)
    {
        temp = temp->link;
        t = temp->data;
    }
    if(temp!=NULL)
    {
        next->link = temp->link;
        temp->link = next;
    }
    else
    {
        cout << "Value not found!";
    }
}

void pop()
{
    Node *temp = head;
    while(temp->link->link!=NULL)
    {
        temp = temp->link;
    }
    temp->link = NULL;
    last = temp;
}

void popat(ll l)
{
    Node *temp = head;
    Node *temp1 = head;

    ll t=1;
    while(t!=l && temp!=NULL)
    {
        temp1 = temp;
        temp = temp->link;
        t++;
    }
    if(temp!=NULL)
    {
        temp1->link = temp->link;
    }
}

void popit(ll v)
{
    Node *temp = head->link;
    Node *temp1 = head;

    ll t = temp->data;
    while(t!=v && temp!=NULL)
    {
        temp1 = temp;
        temp = temp->link;
        t = temp->data;
    }
    if(temp!=NULL)
    {
        temp1->link = temp->link;
    }
    else
    {
        cout << "Value not found!";
    }
}

void print()
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << ' ';
        temp = temp->link;
    }
    cout << endl;
}

int main()
{
    cout << "..................Manu.................." << endl;
    cout << "1.Insert" << endl;
    cout << "2.Insert at position" << endl;
    cout << "3.Insert after a value" << endl;
    cout << "4.POP()" << endl;
    cout << "5.Delete at position" << endl;
    cout << "6.Delete a value" << endl;
    cout << "7.Print()" << endl;
    cout << "8.Quit" << endl;

    ll ch=0;

    while(ch!=8)
    {
        cout << "make a choice: " << ' ';
        cin >> ch;

        switch(ch)
        {
        case 1:
            ll t;
            cin >> t;
            while(t--)
            {
                ll n; // data
                cin >> n;
                push(n);
            }
            break;
        case 2:
            ll n; //data
            cin >> n;
            ll l; //location
            cin >> l;
            pushat(n,l);
            break;
        case 3:
            cin >> n;//data
            ll v; //value
            cin >> v;
            pushafter(n,v);
            break;
        case 4:
            if(head == last)
            {
                head = NULL;
                last = NULL;
            }
            else
                pop();
            break;
        case 5:
            cin >> l;//location
            popat(l);
            break;
        case 6:
            cin >> v;
            popit(v);
            break;
        case 7:
            print();
            break;
        default:
            break;
        }
    }
    return 0;
}
