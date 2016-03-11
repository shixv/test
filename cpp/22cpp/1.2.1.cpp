#include <iostream>
using namespace std;
struct BSTreeNode
{
	int m_nValue;
	BSTreeNode* m_pLeft;
	BSTreeNode* m_pRight;
};
void addBSTreeNode(BSTreeNode*& pCurrent,int value);
void inOrderBSTree(BSTreeNode* pBSTree);
void convertToDoubleList(BSTreeNode* pCurrent);
BSTreeNode* pHead=NULL;
BSTreeNode* pIndex=NULL;
int main(void)
{
	BSTreeNode* pRoot=NULL;
	addBSTreeNode(pRoot,10);
	addBSTreeNode(pRoot,6);
	addBSTreeNode(pRoot,14);
	addBSTreeNode(pRoot,4);
	addBSTreeNode(pRoot,8);
	addBSTreeNode(pRoot,12);
	addBSTreeNode(pRoot,16);
	inOrderBSTree(pRoot);
	return 0;
}
void addBSTreeNode(BSTreeNode*& pCurrent,int value)
{
	if(pCurrent==NULL)
	{
		BSTreeNode* pBSTree=new BSTreeNode;
		pBSTree->m_nValue=value;
		pBSTree->m_pLeft=NULL;
		pBSTree->m_pRight=NULL;
		pCurrent=pBSTree;
	}
	else if(pCurrent->m_nValue<value){
		addBSTreeNode(pCurrent->m_pRight,value);
	}
	else if(pCurrent->m_nValue>value){
		addBSTreeNode(pCurrent->m_pLeft,value);
	}
	else{
		cout<<"Node repeat."<<endl;
	}
}
void inOrderBSTree(BSTreeNode* pBSTree)
{
	if(NULL==pBSTree){
		return;
	}
	if(NULL!=pBSTree->m_pLeft){
		inOrderBSTree(pBSTree->m_pLeft);
	}
	if(NULL!=pBSTree){
//		cout<<pBSTree->m_nValue<<" ";
	convertToDoubleList(pBSTree);
	}
	if(NULL!=pBSTree->m_pRight){
		inOrderBSTree(pBSTree->m_pRight);
	}
}
void convertToDoubleList(BSTreeNode* pCurrent)
{
	pCurrent->m_pLeft=pIndex;
	if(NULL==pIndex){
		pHead=pCurrent;
	}
	else{
		pIndex->m_pRight=pCurrent;
	}
	pIndex=pCurrent;
	cout<<pCurrent->m_nValue<<" ";
}
