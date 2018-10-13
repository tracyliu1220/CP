#include <bits/stdc++.h>
using namespace std;
#define PNN pair<Node*, Node*>
#define MP make_pair
#define F first
#define S second
struct Treap{
    struct Node{
        Node *l, *r;
        int sz, v;
        int minV;
        int tag;
        Node (int _v) : v(_v){
            l = r = NULL;
            sz = 1; 
        }
    }*rt, nodes[MAXN], *idx;
    Treap(){ rt = NULL; idx = nodes; }
    ~Treap(){ clear(rt); }
    void clear(Node *u){
        if (!u) return ;
        clear(u->l); clear(u->r);
        delete u;
    }
    inline int size(Node *u){
        return u ? u->sz : 0;
    }
    inline Node*& pull(Node *&u){		
        u->sz = 1 + size(push(u->l)) + size(push(u->r));
		u->minV = u->v;
		if (u->l) u->minV = min(u->minV, u->l->minV);
	   	if (u->r) u->minV = min(u->minV, u->r->minV); 
        return u;
    }
    inline Node*& push(Node *&u){
        if (!u) return u;
		u->v += tag;
		if (u->l) u->l->tag += tag;
		if (u->r) u->r->tag += tag; 
        tag = 0;
        return u;
    }
    PNN split(Node *T, int x){
        if (!T) return MP((Node*)NULL, (Node*)NULL);
        if (size(push(T)->l) < x){
            PNN tmp = split(T->r, x - size(T->l) - 1);
            T->r = tmp.F;
            return MP(pull(T), tmp.S);
        }else{
            PNN tmp = split(T->l, x);
            T->l = tmp.S;
            return MP(tmp.F, pull(T));
        }
    }
    Node* merge(Node *T1, Node *T2){
        if (!T1 || !T2) return T1 ? T1 : T2;
        if (rand() % (size(T1) + size(T2)) < size(T1)){
            T1->r = merge(push(T1)->r, T2);
            return pull(T1);
        }else{
            T2->l = merge(T1, push(T2)->l);
            return pull(T2);
        }
    }
	void insert(int v) {
		rt = merge(rt, new (idx++) Node(v));
	}
    int rank(int v, Node *u){
        if (!u) return 0;
        return v < u->v ? rank(v, u->l) : size(u->l) + rank(v, u->r) + 1;
    }
};

int main() {

}
