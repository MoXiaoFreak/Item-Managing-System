#include "head.h"
void MenuLogin()
{
    int i=0,j=0,n;
    system("cls");
    SetPosition(getx,gety);
    printf("┌--------------------登录---------------------┐");
    SetPosition(getx,gety+13);
    printf("└");
    SetPosition(getx+46,gety+13);
    printf("┘");
    for(i=2;i<46;i++)
    {
        SetPosition(getx+i,gety+13);
        printf("-");
    }
    for(j=1;j<13;j++)
    {
       SetPosition(getx,gety+j);
        printf("║");
        SetPosition(getx+46,gety+j);
        printf("║");
    }
    SetPosition(getx+18,gety+5);
    printf("1.新用户注册");
    SetPosition(getx+18,gety+7);
    printf("2.用户登录");
     SetPosition(getx+18,gety+9);
    printf("0.退出程序");
    SetPosition(getx,gety+16);
    printf("please choose:");
    scanf("%d",&n);
    switch(n)//待修改
    {
        case 1:UserRegister();break;
        case 2:UserLogin();break;
        case 0:exit(0);
        default:printf("输入错误");exit(0);
    }
    return Menu();
    // UserRegister()
}
