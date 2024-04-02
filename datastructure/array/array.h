#ifndef _ARRAY_H
#define _ARRAY_H

typedef int  Array_type;

int Array_input(Array_type *ptr);
void Array_print(Array_type *ptr,int length);
void Array_insert(Array_type *ptr,int length,int index,Array_type value);
void Array_delete(Array_type *ptr,int length,int index);
int Array_find(Array_type *ptr,int length,Array_type value);
Array_type *Array_extend(Array_type *ptr,int length,int enlarge);


#endif