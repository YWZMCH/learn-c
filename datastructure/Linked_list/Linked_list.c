#include <stdio.h>
#include <stdlib.h>

//需要完善find 需完成赋值函数 复杂节点数据和初始化

/*复杂节点数据
typedef struct Linked_listdata
{
    int val1;
    double val2;
}Ldata;


*/

//链表节点内容
typedef struct Linked_listnode {
    //Ldata data1;结构体嵌套
    int val;               
    struct Linked_listnode *next; 
} Lnode;

/*  简要：链表创建和初始化函数 值全初始化为0
    输入：节点数量
    返回：头节点地址
*/
Lnode *Llist_Init(int n) {
    Lnode *head,*node,*end;
    head = (Lnode *) malloc(sizeof(Lnode));
    head->val=0;
    end=head;
    for(int i=0;i<n-1;i++){
        node=(Lnode *)malloc(sizeof(Lnode));
        node->val=0;
        // node->val=i+1;//调试用
        end->next=node;
        end=node;
    }
    end->next=NULL;
    return head;
}

/*  简要：链表插入节点
    输入：链表的头节点地址  插入位置索引0开始  插入节点的值 
    返回：修改后链表头节点地址
*/
Lnode* Llist_insert(Lnode *list,int index,int value)
{
    Lnode *head=list,*in,*pre;//pre表示插入位置的前一个节点，in表示要加入的节点
    pre=head;
    in=(Lnode *)malloc(sizeof(Lnode));
    in->next=NULL;
    in->val=value;

    if(index==0){//如果加入的位置是头节点
        in->next=head;
        head=in;
    }
    else{
        int i=1;
        while (i<index)//使pre正确指向节点
        {
            pre=pre->next;
            i++;
        }
        if(i==index&&pre!=NULL){
            in->next=pre->next;
            pre->next=in;
        }
        else{//pre没有正确指向节点
            free(in);
            printf("插入位置错误，操作失败\n");
        }
    }

    return head;
}

/*  简要：链表删除节点  
    输入：链表的头节点地址  删除节点的索引0开始
    返回： 修改后链表的头节点地址
*/
Lnode* Llist_delete(Lnode *list,int index)
{
    Lnode *head=list,*de,*pre;//pre表示删除节点的前1个节点，de表示要删除的节点
    pre=head;
    de=pre->next;
    if(index==0){//如果删除的是头节点
        if(de==NULL){
            free(head);
            head=NULL;
            printf("该链表已全部删除\n");
        }
        else{
            de=head;
            head=head->next;
            free(de);
        }
    }
    else{
        int i=1;
        while (i<index && de->next!=NULL)//使de指向正确节点
        {
            pre=pre->next;
            de=pre->next;
            i++;
            // printf("%d ",i);//调试用
        }
        if(i==index&&de!=NULL){//de指向正确节点
            pre->next=de->next;
            free(de);  
        }
        else{//de没有指向正确节点
            printf("删除位置错误，操作失败\n");
        }
    }

    return head;
}

/*  简要：获取链表节点个数
    输入：链表的头节点地址 
    返回：
*/
int Llist_length(Lnode *list)
{
    Lnode* current=list;
    int i=0;
    while (current!=NULL)
    {
        i++;
        current=current->next;
    }
    return i;
}

/*  简要：链表打印函数
    输入：链表的头节点地址
    返回：
*/
void Llist_print(Lnode *list)
{
    Lnode* current=list;
    while (current!=NULL)
    {
        printf("%d ",current->val);
        current=current->next;
    }
    printf("\n");
}

/*  简要：查找链表节点
    输入：链表的头节点地址  要查找的值
    返回：节点索引地址
*/
int Llist_find(Lnode *list,int taget)
{
    int index=0;
    while (list)
    {
        if(list->val==taget)return index;
        list=list->next;
        index++;
    }

    return -1;
}

int main()
{
    Lnode *head;
    head=Llist_Init(3);
    head=Llist_insert(head,0,6);
    Llist_print(head);
    printf("%d \n",Llist_length(head));
    return 0;
}