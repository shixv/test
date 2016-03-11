#include <iostream>

template <typename Comparable>
class BinarySearchTree
{
	public:
		BinarySearchTree():root(NULL){std::cout<<"BinarySearchTree construct.."<<std::endl;}
		BinarySearchTree(const BinarySearchTree& rhs){std::cout<<"BinarySearchTree construct.."<<std::endl;}
		~BinarySearchTree(){
			makeEmpty();
			std::cout<<"BinarySearchTree destroy.."<<std::endl;
		}
		const Comparable& findMin()const{
			findMin(root);
		}
		const Comparable& findMax()const{
			findMax(root);
		}
		bool contains(const Comparable& x)const{
			return contains(x,root);
		}
		bool isEmpty()const{
			return root==NULL;
		}
		int depth()const{
			return depth(root);
		}
		void printTree()const{
			printTree(root);
			std::cout<<std::endl;
		}
		void makeEmpty(){
			makeEmpty(root);
		}
		void insert(const Comparable& x){
			insert(x,root);
		}
		void remove(const Comparable& x){
			remove(x,root);
		}

		const BinarySearchTree& operator=(const BinarySearchTree& rhs){
			if(this!=&rhs){
				makeEmpty();
				root=clone(rhs.root);
			}
			return *this;
		}
	private:
		struct BinaryNode
		{
			Comparable element;
			BinaryNode* left;
			BinaryNode* right;

			BinaryNode(const Comparable& theElement=0,BinaryNode* lt=NULL,BinaryNode* rt=NULL)
				:element(theElement),left(lt),right(rt){/*std::cout<<"BinaryNode construct.."<<std::endl;*/}
		};
		BinaryNode* root;
		int depth(BinaryNode* t)const{
			if(t==NULL)
				return 0;
			int depthl=depth(t->left);
			int depthr=depth(t->right);
			return 1+(depthl>depthr?depthl:depthr);
		}
		void insert(const Comparable& x,BinaryNode*& t)const{
			if(t==NULL)
				t=new BinaryNode(x,NULL,NULL);
			else if(x<t->element)
				insert(x,t->left);
			else if(x>t->element)
				insert(x,t->right);
			else
				return;
		}
		void insert(const Comparable& x,BinaryNode*& t,int)const{
			auto v=t;
			while(v!=NULL&&v->element!=x){
				if(x<v->element){
					if(v->left!=NULL){
						v=v->left;
					}else{
						v->left=new BinaryNode(x,NULL,NULL);
						v=NULL;
					}
				}else{
					if(v->right!=NULL){
						v=v->right;
					}else{
						v->right=new BinaryNode(x,NULL,NULL);
						v=NULL;
					}
				}
			}
			if(t==NULL){
				t=new BinaryNode(x,NULL,NULL);
			}
		}
		void remove(const Comparable& x,BinaryNode*& t)const{
			if(t==NULL)
				return;
			if(x<t->element)
				remove(x,t->left);
			else if(x>t->element)
				remove(x,t->right);
			else if(t->left!=NULL&&t->right!=NULL){
				t->element=findMin(t->right)->element;
				remove(t->element,t->right);
			}
			else{
				BinaryNode* oldnode=t;
				t=(t->left!=NULL)?t->left:t->right;
				delete oldnode;
			}
		}
		BinaryNode* findMin(BinaryNode* t)const{
			while(t!=NULL)
				while(t->left!=NULL)
					t=t->left;
			return t;
		}
		BinaryNode* findMax(BinaryNode* t)const{
			while(t!=NULL)
				while(t->right!=NULL)
					t=t->right;
			return t;
		}
		bool contains(const Comparable& x,BinaryNode* t)const{
			if(t==NULL)
				return false;
			else if(x<t->element)
				return contains(x,t->left);
			else if(x>t->element)
				return contains(x,t->right);
			else
				return true;
		}
		void makeEmpty(BinaryNode*& t){
			if(t!=NULL){
				makeEmpty(t->left);
				makeEmpty(t->right);
				delete t;
			}
			t=NULL;
		}
		void printTree(BinaryNode* t)const{
			if(t==NULL)
				return;
			printTree(t->left);
			std::cout<<t->element<<"->";
			printTree(t->right);
		}
		BinaryNode* clone(BinaryNode* t)const{
			if(t==NULL)
				return NULL;
			return new BinaryNode(t->element,clone(t->left),clone(t->right));
		}
};
