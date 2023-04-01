#ifndef _LIB_DYNAMIC_L_H_
#define _LIB_DYNAMIC_L_H_

#ifdef LIB_DYN_EXPORTS
#define LIB_DLL __declspec(dllexport)
#else
#define LIB_DLL __declspec(dllimport)
#endif

#define LIB_DECL __cdecl

#include <stdio.h>

LIB_DLL int LIB_DECL mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
LIB_DLL int LIB_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
LIB_DLL int LIB_DECL correct_file_input(char *f_name);
LIB_DLL int LIB_DECL compare(const void *i, const void *j);
LIB_DLL int LIB_DECL create_array(char *f_name, int **arr, int **arr_end);
LIB_DLL void LIB_DECL print_array(char *filename, int *begin, int *end);

#endif
