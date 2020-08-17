#include <bits/stdc++.h>

using namespace std;

struct node{
	node * parent;
	vector<node *> childs;
};

void solve(){
	int N, from, to, root_index=0;
	long double dig=0, jit=0;
	vector<node*> tree;
	vector<node*> cur_stack;

	node * n, * root;

	cin >> N;

	for(int i=0; i<1000; i++){
		tree.push_back(new node);
		tree[i]->parent = NULL;
	}

	for(int i=0; i<N-1; i++){
		scanf("%d %d", &from, &to);
		tree[from-1]->childs.push_back(tree[to-1]);
		tree[to-1]->parent = tree[from-1];
	}

	for(int i=0; i<N; i++){
		if(tree[i]->parent == NULL){
			root = tree[i];
			cur_stack.push_back(root);
			break;
		}
	}

	assert(!cur_stack.empty());

	while(!cur_stack.empty()){
		n = cur_stack.back(); cur_stack.pop_back();

		// jit
		double nchild = n->childs.size();

		if(n->parent != NULL){
			nchild++;
		}

		if(nchild >= 3){
			jit += nchild * (nchild-1) * (nchild-2) / 6;		}

		// dig
		double sum=0;
		for(int i=0; i<n->childs.size(); i++){
			sum += n->childs[i]->childs.size();
		}
		if(n->parent != NULL)
			dig += sum * n->childs.size();
		else
			dig += sum * (n->childs.size() - 1);


		cur_stack.insert(cur_stack.end(), n->childs.begin(), n->childs.end());
		//printf("node : %d\n", n->key);
		//printf("%lld %lld \n", dig, jit);
	}

	if(dig > jit * 3){
		printf("D\n");
	} else if (dig == jit * 3){
		printf("DUDUDUNGA\n");
	} else {
		printf("G\n");
	}

}

int main(void){
	solve();
	return 0;
}
