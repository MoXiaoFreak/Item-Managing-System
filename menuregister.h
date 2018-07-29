#include "head.h"
void MenuRegister()
{
    int i=0,j=0,n;
    system("cls");
    SetPosition(getx,gety);
    printf("X--------------------µÇÂ¼-------------------X");
    SetPosition(getx,gety+13);
    printf("X");
    SetPosition(getx+46,gety+13);
    printf("X");
    for(i=2;i<46;i++)
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
    SetPosition(getx+16,gety+5);
    printf("1.User Login");
    SetPosition(getx+16,gety+8);
    printf("0.exit");
    SetPosition(getx,gety+16);
    printf("please choose:");
    scanf("%d",&n);
    switch(n)
    {
    case 1:UserLogin();break;
    case 0:printf("\n sdafaf");break;
    default:system("pause");
    }

    // UserRegister()
}
