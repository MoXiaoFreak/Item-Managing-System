#include "head.h"
void MenuLogin()
{
    int i=0,j=0,n;
    system("cls");
    SetPosition(getx,gety);
    printf("��--------------------��¼---------------------��");
    SetPosition(getx,gety+13);
    printf("��");
    SetPosition(getx+46,gety+13);
    printf("��");
    for(i=2;i<46;i++)
    {
        SetPosition(getx+i,gety+13);
        printf("-");
    }
    for(j=1;j<13;j++)
    {
       SetPosition(getx,gety+j);
        printf("�U");
        SetPosition(getx+46,gety+j);
        printf("�U");
    }
    SetPosition(getx+18,gety+5);
    printf("1.���û�ע��");
    SetPosition(getx+18,gety+7);
    printf("2.�û���¼");
     SetPosition(getx+18,gety+9);
    printf("0.�˳�����");
    SetPosition(getx,gety+16);
    printf("please choose:");
    scanf("%d",&n);
    switch(n)//���޸�
    {
        case 1:UserRegister();break;
        case 2:UserLogin();break;
        case 0:exit(0);
        default:printf("�������");exit(0);
    }
    return Menu();
    // UserRegister()
}
