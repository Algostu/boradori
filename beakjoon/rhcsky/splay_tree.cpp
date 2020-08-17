#include <bits/stdc++.h>
using namespace std;

struct node{
    node* l;
    node* r;
    node* p;
    int key;
}*tree;

void rotate(node* x){ //node x를 x->p로 옮기는 것
    node *p = x->p;
    node *b = nullptr;
    if(!p) return;
    if(x==p->l){
        p->l = b = x->r;
        x->r = p;
    }else{
        p->r = b = x->l;
        x->l = p;
    }

    x->p = p->p;
    p->p = x;
    if(b) b->p = p;
    (x->p ? p==x->p->l ? x->p->l : x->p->r : tree) = x;
}

void splay(node* x){ //루트 노드까지 올리기
    while (x->p)
    {
        node* p = x->p;
        node* g = p->p;
        if(g){
            if((x==p->l)==(p==g->l)) rotate(p);
            else rotate(x);
        }
        rotate(x);
    }
}

void insert(int key){
    node* p = tree;
    node** pp;
    if(!p){
        node* x = new node;
        tree = x;
        x->l = x->r = x->p = nullptr;
        x->key = key;
        return;
    }
    while(true){
        if(key == p->key) return;
        if(key < p->key){
            if(!p->l){
                pp = &p->l;
                break;
            }
            p = p->l;
        }
        else{
            if(!p->r){
                pp = &p->r;
                break;
            }
            p = p->r;
        }
    }

    node* x = new node;
    *pp = x;
    x->l = x->r = nullptr;
    x->p = p, x->key = key;
    splay(x);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}