//#include <stdarg.h>
#ifndef _define_h
#define _define_h

//#define Element int
#define TRUE 1
#define FLASE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(n)   (((a)>(0))?(n):(-n))
#define floor(n) (int)n
#define ceil(n)  (int)n+1

//#define MAX(...) MAX(__VA_ARGS__)

//Element MAX(int lim,...);

#endif
