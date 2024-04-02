#include <stdio.h>
#include <stdlib.h>
#include "array.h"


int Array_input(Array_type *ptr)
{   
    Array_type num;
    int count=0;
    do {
        if (scanf("%d", &num) == 1) {
            ptr[count]=num;
            count++;
        } 
        else {
            break;
        }
    } while (getchar() != '\n');

    return count;
}


void Array_print(Array_type *ptr,int length)
{
    for(int i=0;i<length;i++){
        printf("%d ",ptr[i]);
        if(i%10==9)printf("\n");
    }
    printf("\n");
}


void Array_insert(Array_type *ptr,int length,int index,Array_type value)
{
    for(int i=length;i>index;i--){
        ptr[i]=ptr[i-1];
    }
    ptr[index]=value;
}


void Array_delete(Array_type *ptr,int length,int index)
{
    for(int i=index;i<length-1;i++){
        ptr[i]=ptr[i+1];
    }
}


int Array_find(Array_type *ptr,int length,Array_type value)
{
    int index=-1;
    for(int i=0;i<length;i++)
    {
        if(ptr[i]==value)index=i;
    }
    return index;
}

Array_type *Array_extend(Array_type *ptr,int length,int enlarge)
{
    Array_type *new=(Array_type *)calloc((length+enlarge),sizeof(Array_type));
    for(int i=0;i<length;i++){
        new[i]=ptr[i];
    }

    return  new;
}