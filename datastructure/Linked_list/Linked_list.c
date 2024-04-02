#include <stdio.h>
#include <stdlib.h>

//��Ҫ����find ����ɸ�ֵ���� ���ӽڵ����ݺͳ�ʼ��

/*���ӽڵ�����
typedef struct Linked_listdata
{
    int val1;
    double val2;
}Ldata;


*/

//����ڵ�����
typedef struct Linked_listnode {
    //Ldata data1;�ṹ��Ƕ��
    int val;               
    struct Linked_listnode *next; 
} Lnode;

/*  ��Ҫ���������ͳ�ʼ������ ֵȫ��ʼ��Ϊ0
    ���룺�ڵ�����
    ���أ�ͷ�ڵ��ַ
*/
Lnode *Llist_Init(int n) {
    Lnode *head,*node,*end;
    head = (Lnode *) malloc(sizeof(Lnode));
    head->val=0;
    end=head;
    for(int i=0;i<n-1;i++){
        node=(Lnode *)malloc(sizeof(Lnode));
        node->val=0;
        // node->val=i+1;//������
        end->next=node;
        end=node;
    }
    end->next=NULL;
    return head;
}

/*  ��Ҫ���������ڵ�
    ���룺�����ͷ�ڵ��ַ  ����λ������0��ʼ  ����ڵ��ֵ 
    ���أ��޸ĺ�����ͷ�ڵ��ַ
*/
Lnode* Llist_insert(Lnode *list,int index,int value)
{
    Lnode *head=list,*in,*pre;//pre��ʾ����λ�õ�ǰһ���ڵ㣬in��ʾҪ����Ľڵ�
    pre=head;
    in=(Lnode *)malloc(sizeof(Lnode));
    in->next=NULL;
    in->val=value;

    if(index==0){//��������λ����ͷ�ڵ�
        in->next=head;
        head=in;
    }
    else{
        int i=1;
        while (i<index)//ʹpre��ȷָ��ڵ�
        {
            pre=pre->next;
            i++;
        }
        if(i==index&&pre!=NULL){
            in->next=pre->next;
            pre->next=in;
        }
        else{//preû����ȷָ��ڵ�
            free(in);
            printf("����λ�ô��󣬲���ʧ��\n");
        }
    }

    return head;
}

/*  ��Ҫ������ɾ���ڵ�  
    ���룺�����ͷ�ڵ��ַ  ɾ���ڵ������0��ʼ
    ���أ� �޸ĺ������ͷ�ڵ��ַ
*/
Lnode* Llist_delete(Lnode *list,int index)
{
    Lnode *head=list,*de,*pre;//pre��ʾɾ���ڵ��ǰ1���ڵ㣬de��ʾҪɾ���Ľڵ�
    pre=head;
    de=pre->next;
    if(index==0){//���ɾ������ͷ�ڵ�
        if(de==NULL){
            free(head);
            head=NULL;
            printf("��������ȫ��ɾ��\n");
        }
        else{
            de=head;
            head=head->next;
            free(de);
        }
    }
    else{
        int i=1;
        while (i<index && de->next!=NULL)//ʹdeָ����ȷ�ڵ�
        {
            pre=pre->next;
            de=pre->next;
            i++;
            // printf("%d ",i);//������
        }
        if(i==index&&de!=NULL){//deָ����ȷ�ڵ�
            pre->next=de->next;
            free(de);  
        }
        else{//deû��ָ����ȷ�ڵ�
            printf("ɾ��λ�ô��󣬲���ʧ��\n");
        }
    }

    return head;
}

/*  ��Ҫ����ȡ����ڵ����
    ���룺�����ͷ�ڵ��ַ 
    ���أ�
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

/*  ��Ҫ�������ӡ����
    ���룺�����ͷ�ڵ��ַ
    ���أ�
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

/*  ��Ҫ����������ڵ�
    ���룺�����ͷ�ڵ��ַ  Ҫ���ҵ�ֵ
    ���أ��ڵ�������ַ
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