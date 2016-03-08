void Print_CircleLinkList(CircleLinkList* clist,PRINLINNODE print){
	if(clist==NULL)
		return ;
	if(print==NULL)
		return;

	CircleLinkList* pCurrent=clist->header.next;
	for(int i=0;i<clist->length*2;i++){
		print(pCurrent);
		pCurrent=pCurrent->next;
		if(pCurrent==&(list->header))
			pCurrent=pCurrent->next;
	}
}
