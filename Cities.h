//
// Created by lnw on 2021/10/11.
//

#ifndef LINKLIST04_CITIES_H
#define LINKLIST04_CITIES_H
#define MAXSIZE 1000
#include <string.h>
#include <math.h>
typedef struct{
    char name[30];
    int x,y;
}cities;
typedef cities ElemType;
typedef struct {
    ElemType data;
    int cur;
}Component,StaticLinkList[MAXSIZE];

int ListLength(StaticLinkList L);
//int PrintString(const char p[]);

void Free_SSL(StaticLinkList space, int k);
int Compare(char *i,char *j){
    return strcmp(i,j);
}

int InitList(StaticLinkList space){//初始化表
    for (int i = 0; i < MAXSIZE-1; i++) {
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0;
    return 1;
}
int Malloc_SSL(StaticLinkList space){//静态链表特性，重写malloc函数
    int i = space[0].cur;
    if(space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}
int ListInsert(StaticLinkList L,int i,ElemType e){//插入节点
    int j,k,l;
    k = MAXSIZE -1;
    if(i<1||i>ListLength(L) + 1)
        return 0;
    j = Malloc_SSL(L);
    if(j){
        L[j].data = e;
        for(l = 1;l<=i-1;l++){
            k  = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return 1;
    }
    return 0;
}
int ListDelete(StaticLinkList L,int i){//删除节点
    int j,k;
    if(i<1 || i> ListLength(L))
        return 0;
    k = MAXSIZE - 1;
    for(j = 1; j<=i-1;j++)
        k = L[k].cur;
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L,j);
    return 1;
}

void Free_SSL(StaticLinkList space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

int ListLength(StaticLinkList L) {
    int j = 0;
    int i = L[MAXSIZE-1].cur;
    while (i){
        i = L[i].cur;
        j++;
    }
    return j;
}
int LinkListSearchByName(StaticLinkList L,char *name){//按名称查找
    int j = 0;
    int i = L[MAXSIZE-1].cur;
    while (i){
        if(Compare(name,L[i].data.name)==0){
            printf("i = %d\n",j);
            return j;
        }
        j++;
        i = L[i].cur;
    }
    return -1;
}
int PutsListById(StaticLinkList L,int index){
    if(index<1){
        puts("要查找的城市不存在");
        return -1;
    }
    printf("城市名字是%s,x轴是%d,y轴是%d\n",L[index].data.name,L[index].data.x,L[index].data.y);
    return 0;
}//根据id输出城市
int ReturnDistanceByInt(int x,int y,int px,int py){//返回距离的平方
    int answer = pow(x-px,2)+pow(y-py,2);
    return answer;
}
int ReturnAllCitiesDistance(StaticLinkList L,int distance,int x,int y,int px,int py){
    int i = L[MAXSIZE-1].cur,flag = -1;//flag是返回状态
    while (i){
        if(ReturnDistanceByInt(x,y,px,py)<= pow(distance,2)){
            printf("城市名字是%s,x轴是%d,y轴是%d\n",L[i].data.name,L[i].data.x,L[i].data.y);
            flag = 1;
        }
        i = L[i].cur;
    }
    return flag;
}//返回所有符合答案的城市名

#endif //LINKLIST04_CITIES_H
