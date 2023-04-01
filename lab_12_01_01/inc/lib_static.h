#ifndef __LIB_STATIC_H__
#define __LIB_STATIC_H__
#include <stdio.h>

int mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif
