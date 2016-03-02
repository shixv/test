struct AvlNode{
	Comparable element;
	AvlNode *left;
	AvlNode *right;
	int height;

	AvlNode(const Comparable& theElement,AvlNode *lt,
			AvlNode *rt,int t=0)
		:element(theElement),left(lt),right(rt),height(h)
};
int height(AvlNode *t)const
{
	return t==NULL?-1:t->height;
}
void rotateWithLeftChild(AvlNode*& k2)
{
	AvlNode* k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2->height=max(height(k2->left),height(k2->right))+1;
	k1->height=max(height(k1->left),k2->height)+1;
	k2=k1;
}
void doubleWithLeftChild(AvlNode*& k3)
{
	rotateWithLeftChild(k3->left);
	rotateWithLeftChild(k3);
}
void insert(const Comparable& x,AvlNode*& t)
{
	if(t==NULL)
		t=new AvlNode(x,NULL,NULL);
	else if(x<t->element)
	{
		insert(x,t->left);
		if(height(t->left)-height(t->right)==2)
			if(x<t->left->element)
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
	}
	else if(t->element<x)
	{
		insert(x,t->right);
		if(height(t->right)-height(t->left)==2)
			if(t>right->element<x)
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
	}
	else
		;
	t->height=max(height(t->left),height(t->right))+1;
}

