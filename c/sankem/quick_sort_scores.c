#include "snake.h"

void quick_sort_scores(int *left, int *right)
{
    int *p = left;
    int *q = right;
    int temp = *left;

    if(left > right)
        return;

    while(p != q) {
        while((*q < temp) && p < q)
            q--;
        if(p < q) {
            *p = *q;
            p++;
        }
        while((*p > temp) && p < q)
            p++;
        if(p < q) {
            *q = *p;
            q--;
        }
    }

    *p = temp;

    quick_sort_scores(left, p - 1);
    quick_sort_scores(p + 1, right);
}
