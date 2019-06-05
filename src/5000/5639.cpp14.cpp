#include <cstdio>

struct BST
{
	struct Node
	{
		int key;
		Node *left, *right;

		Node()
		{
			left=right=NULL;
		}

		void post()
		{
			if(left!=NULL)
				left->post();

			if(right!=NULL)
				right->post();

			printf("%d\n", key);
		}
	};

	Node *root;
	BST()
	{
		root=NULL;
	}

	void insert(int num)
	{
		if(root==NULL)
		{
			root=new Node();
			root->key=num;
			return;
		}

		Node *p=root, *parent=root;
		while(p)
		{
			parent=p;
			if(num<p->key)
				p=p->left;

			else
				p=p->right;
		}

		p=new Node();
		p->key=num;
		if(num<parent->key)
			parent->left=p;

		else
			parent->right=p;
	}

	void post()
	{
		if(root!=NULL)
			root->post();
	}
};

int main()
{
	int num;
	BST bst;
	while(~scanf("%d", &num))
		bst.insert(num);

	bst.post();
}
