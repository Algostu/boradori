#include <iostream>

struct node{
  node *l, *r, *p;
  int key;
  int cnt;
  int sum, value;
} * tree;

void Rotate(node * x){
  node * p = x -> p;
  node * b;
  if(p->l == x){
    p->l = b = x->r;
    x->r = p;
  } else {
    p->r = b = x->l;
    x->l = p;
  }
  x->p = p->p;
  p->p = x;
  if(b) b->p = p;
  (x->p ? (x->p->l == p ? x->p->l : x->p->r) : tree) = x;
  Update(p);
  Update(x);
}

void Splay(node *x, node * end = NULL){
  while(x->p!=end){
    node * p = x->p;
    node * gp = p->p;
    if(gp!=end) Rotate((x==p->l) == (p==g->l) ? p : x);
    Rotate(x);
  }
}

void Insert(int key) {
    node *p = tree, **pp;
    if (!p) {
        node *x = new node;
        tree = x;
        x->l = x->r = x->p = NULL;
        x->key = key;
        return;
    }
    while (1) {
        if (key == p->key) return;
        if (key < p->key) {
            if (!p->l) {
                pp = &p->l;
                break;
            }
            p = p->l;
        } else {
            if (!p->r) {
                pp = &p->r;
                break;
            }
            p = p->r;
        }
    }
    node *x = new node;
    *pp = x;
    x->l = x->r = NULL;
    x->p = p;
    x->key = key;
    Splay(x);
}

bool Find(int key) {
    node *p = tree;
    if (!p) return false;
    while (p) {
        if (key == p->key) break;
        if (key < p->key) {
            if (!p->l) break;
            p = p->l;
        } else {
            if (!p->r) break;
            p = p->r;
        }
    }
    Splay(p);
    return key == p->key;
}

void Delete(int key) {
    if (!Find(key)) return;
    node *p = tree;
    if (p->l) {
        if (p->r) {
            tree = p->l;
            tree->p = NULL;
            node *x = tree;
            while (x->r) x = x->r;
            x->r = p->r;
            p->r->p = x;
            Splay(x);
            delete p;
            return;
        }
        tree = p->l;
        tree->p = NULL;
        delete p;
        return;
    }
    if (p->r) {
        tree = p->r;
        tree->p = NULL;
        delete p;
        return;
    }
    delete p;
    tree = NULL;
}

void Update(node * x){
  x->cnt = 1;
  x->sum = x->value;
  if(x->l) {
    x->cnt += x->l->cnt;
    x->sum += x->l->sum;
  }
  if(x->r) {
    x->cnt += x->r->cnt;
    x->sum += x->r->sum;
  }
}

void Find_Kth(int k){
  node * x = tree;
  while(1){
    while(x->l && x->l->cnt > k) x = x->l;
    if(x->l) k -= x->l->cnt;
    if(!k--) break;
    x = x->r;
  }
  Splay(x);
}

void Add(int i, int z) {
    Find_Kth(i);
    tree->sum += z;
    tree->value += z;
}

void Initialize(int n) {
    node *x;
    int i;
    tree = x = new node;
    x->l = x->r = x->p = NULL;
    x->cnt = n;
    x->sum = x->value = 0;
    for (i = 1; i < n; i++) {
        x->r = new node;
        x->r->p = x;
        x = x->r;
        x->l = x->r = NULL;
        x->cnt = n - i;
        x->sum = x->value = 0;
    }
}

void Interval(int l, int r) {
    Find_Kth(l - 1);
    node *x = tree;
    tree = x->r;
    tree->p = NULL;
    Find_Kth(r - l + 1);
    x->r = tree;
    tree->p = x;
    tree = x;
}

int Sum(int l, int r) {
    Interval(l, r);
    return tree->r->l->sum;
}

int main(void){
  Initialize(5);
}
