#include "head.h"
void Menu()
{
    int i=0,j=0,n;
    system("cls");//����
    //����
    SetPosition(getx,gety);
    printf("��-----------------���й���ϵͳ---------------��");
    SetPosition(getx,gety+13);
    printf("��");
    SetPosition(getx+45,gety+13);
    printf("��");
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
    printf("1.�����Ʒ��Ϣ\n");
    SetPosition(getx+16,gety+3);
    printf("2.ɾ����Ʒ��Ϣ\n");
   SetPosition(getx+16,gety+4);
    printf("3.��ѯ��Ʒ��Ϣ\n");
    SetPosition(getx+16,gety+5);
    printf("4.��Ʒ����\n");
    SetPosition(getx+16,gety+6);
    printf("5.ͳ����Ʒ��Ϣ\n");
    SetPosition(getx+16,gety+7);
    printf("6.�޸���Ʒ��Ϣ\n");
    SetPosition(getx+16,gety+8);
    printf("7.������Ʒ��Ϣ\n");
     SetPosition(getx+16,gety+9);
    printf("8.ע��\n");
    SetPosition(getx+16,gety+10);
    printf("0.�˳�\n");
    SetPosition(getx+8,gety+14);
    printf("������0-9֮�������:");
    scanf("%d",&n);
    //����
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
