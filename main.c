#include <stdio.h>
#include "Cities.h"


#define MAXSIZE 1000
int main(){
    StaticLinkList space;//题目需要的表
    InitList(space);
    char pname[30] ;
    int citiesnumber,x,y;
    printf("输入要插入城市数");
    scanf("%d",&citiesnumber);
    fflush(stdin);
    for(int i  = 1;i<=citiesnumber;i++){//插入城市
        StaticLinkList list;
        puts("输入城市名");
        scanf("%s",pname);
        printf("输入要插入的坐标");
        stpcpy(list->data.name,pname);
        scanf("%d%d",&x,&y);
        list->data.x = x;
        list->data.y = y;
        ListInsert(space,1,list->data);
    }
    puts("输入要查询的城市");
    scanf("%s",pname);
    fflush(stdin);
    PutsListById(space,LinkListSearchByName(space,pname));
    int px,py,distance;
    puts("依次输入x轴y轴和距离输入坐标的距离以空格分离");
    scanf("%d %d %d",&px,&py,&distance);
    if(ReturnAllCitiesDistance(space,distance,x,y,px,py)==-1){
        puts("没有符合的城市");
    }

    return 0;
}
