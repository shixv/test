#include "define.h"

Element MAX(int lim, ...)
{
	va_list ap;
	Element max=0;
	va_start(ap,lim);
	for(int i=0;i<lim;i++)
		max=_MAX(max,va_arg(ap,Element));
	return max;
}
