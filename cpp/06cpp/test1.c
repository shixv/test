void Test(void)
{
	char *str=(char *)malloc(100);
	if(str==NULL)
	{
		return;
	}
	strcpy(str,"hello");
	free(str);
	str=NULL;
}
