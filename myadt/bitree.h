template<class ElemType>
class Binode
{
	private:
		ElemType *data;
		Binode *lchild,*rchild;
	public:
		Binode();
		~Binode();
};
template<class ElemType>
class Bitree
{
	private:
		Binode *root;
		Binode *cur;
	public:
		Bitree();
		~Bitree();
		bool preorder(bool(*visit)(ElemType &e));
		bool inorder(bool(*visit)(ElemType &e));
		bool postorder(bool(*visit)(ElemType &e));
		bool levelorder(bool(*visit)(ElemType &e));
};
