#include "head.h"
void MenuLogin()
{
    int i=0,j=0,n;
    system("cls");
    SetPosition(getx,gety);
    printf("©°--------------------µÇÂ¼---------------------©´");
    SetPosition(getx,gety+13);
    printf("©¸");
    SetPosition(getx+46,gety+13);
    printf("©¼");
    for(i=2;i<46;i++)
    {
        SetPosition(getx+i,gety+13);
        printf("-");
    }
    for(j=1;j<13;j++)
    {
       SetPosition(getx,gety+j);
        printf("¨U");
        SetPosition(getx+46,gety+j);
        printf("¨U");
    }
    SetPosition(getx+16,gety+5);
    printf("1.Register");
    SetPosition(getx+16,gety+8);
    printf("2.Login");
    SetPosition(getx,gety+16);
    printf("please choose:");
    scanf("%d",&n);
    switch(n)//´ýÐÞ¸Ä
    {
        case 1:UserRegister();break;
        case 2:UserLogin();break;
        default:system("pause");
    }
    return Menu();
    // UserRegister()
}
