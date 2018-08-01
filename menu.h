#include "head.h"
void Menu()
{
    int i=0,j=0,n;
    system("cls");//清屏
    //界面
    SetPosition(getx,gety);
    printf("┌-----------------超市管理系统---------------┐");
    SetPosition(getx,gety+13);
    printf("└");
    SetPosition(getx+45,gety+13);
    printf("┘");
    for(i=1;i<44;i++)
    {
        SetPosition(getx+i,gety+13);
        printf("-");
    }
    for(j=1;j<13;j++)
    {
       SetPosition(getx,gety+j);
        printf("|");
        SetPosition(getx+46,gety+j);
        printf("|");
    }
    SetPosition(getx+16,gety+2);
    printf("1.添加商品信息\n");
    SetPosition(getx+16,gety+3);
    printf("2.删除商品信息\n");
   SetPosition(getx+16,gety+4);
    printf("3.查询商品信息\n");
    SetPosition(getx+16,gety+5);
    printf("4.商品排序\n");
    SetPosition(getx+16,gety+6);
    printf("5.统计商品信息\n");
    SetPosition(getx+16,gety+7);
    printf("6.修改商品信息\n");
    SetPosition(getx+16,gety+8);
    printf("7.插入商品信息\n");
     SetPosition(getx+16,gety+9);
    printf("8.注销\n");
    SetPosition(getx+16,gety+10);
    printf("0.退出\n");
    SetPosition(getx+8,gety+14);
    printf("请输入0-9之间的数字:");
    scanf("%d",&n);
    //界面
    switch(n)
    {
        case 1:AddCommodityInfo();break;
        case 2:DelCommodityInfo();break;
        case 3:Search();break;
        case 4:OrderCommodityInfo();break;
        case 5:TotalCommodityInfo();break;
        case 6:ModifyCommodityInfo();break;
        case 7:InsertCommodityInfo();break;
        case 8:return MenuLogin();break;
        case 0:exit(0);
        default:printf("ERROR");getch();return Menu();
    }
}
