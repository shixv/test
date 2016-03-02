void printTree(ostream& out=cout)const
{
	if(isEmpty())
		out<<"Empty tree"<<endl;
	else
		printTree(root,out);
}
void printTree(BinaryNode *t,ostream& out)const
{
	if(t!=NULL)
	{
		printTree(t->left,out);
		out<<t->element<<endl;
		printTree(t->right,out);
	}
}
int height(BinaryNode* t)
{
	if(t==NULL)
		return -1;
	else
		return 1+max(height(t->left),height(t->right));
}
