#define Max(a,b) ((a)>(b)?(a):(b))
#define FREE(p) \
	do{\
		free(p);\
		p=NULL;\
	}while(0)
