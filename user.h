#include "head.h"
void UserRegister()
{
    system("cls");
    const char *filename =USERINFO;
     int count=0,i=0;
     char pass[20];
     FILE *fp;
	a:if((fp=fopen(filename,"r+"))==NULL)
	{
	    FILE *fp=fopen(filename,"w+");
	    fclose(fp);
		goto a;
	}
	while(~fscanf(fp,"%s%s",&user[i].username,&user[i].password))
	{
		i++;
		count=i;
	}
	SetPosition(getx+15,gety+3);
	printf("��ǰ��%d��ע���û�\n",count);
	userrepeat:
	    DrawRegist();
	    SetPosition(getx+15,gety+4);
	    printf("������ע���û�����\n");
	    SetPosition(getx+15,gety+5);
        scanf("%s",&user[count+1].username);
        for(i=0;i<count+1;i++)
        {
        	if(strcmp(user[i].username,user[count+1].username)==0)
        	{
        	    SetPosition(getx+15,gety+6);
        		printf("���û����Ѵ��ڣ����������롣\n");
        		SetPosition(getx+15,gety+7);
                printf("�������������....");
                getch();
                system("cls");
        		goto userrepeat;
        	}
        }
        fprintf(fp,"%s\t",user[count+1].username);
       passrepeat:
           SetPosition(getx+15,gety+7);
           printf("������ע�����룺\n");
           SetPosition(getx+15,gety+8);
        scanf("%s",&user[count+1].password);
        SetPosition(getx+15,gety+9);
        printf("��ȷ��ע�����룺\n");
        SetPosition(getx+15,gety+10);
        scanf("%s",&pass);
        if(strcmp(user[count+1].password,pass)!=0)
        {
            SetPosition(getx+15,gety+11);
            printf("���벻ƥ��,������ע��.\n");
            SetPosition(getx+15,gety+12);
            printf("�������������....");
            getch();
            system("cls");
            goto userrepeat;
        }
        fprintf(fp,"%s\t\n",user[count+1].password);
        fclose(fp);
        count++;
        SetPosition(getx+15,gety+12);
        printf("ע��ɹ���");
        getch();
        return MenuLogin();
}
void UserLogin()
{
    const char *filename =USERINFO;
    system("cls");
    int faultcount=0;
        int usercount=0;
     int count=0,mark=0,i=0;
     char usern[20];
     char pass[20];
     FILE *fp;
	if((fp=fopen(filename,"r+"))==NULL)
	{
        printf("���û�ע���¼����ת���û�ע��......\n");
	  return UserRegister();
	}
	while(~fscanf(fp,"%s%s",&user[i].username,&user[i].password))
	{
		i++;
		count=i;
	}
	userrepeat2:
	    DrawLogin();
	    SetPosition(getx+15,gety+3);
	    printf("�û���:\n");
	    SetPosition(getx+15,gety+5);
	    printf("����:\n");
	    SetPosition(getx+23,gety+3);
        scanf("%s",&usern);
        for(i=0;i<count;i++)
        {
        	if(strcmp(user[i].username,usern)==0)
        	{
        		mark=i;
        		break;
        	}
        	else
            {
                usercount++;
            }
            if(usercount==count)
            {
                SetPosition(getx+15,gety+15);
                printf("�޴��û�,���������������...\n");
                getch();
                system("cls");
                DrawLogin();
                goto userrepeat2;
            }

        }
        passrepeat2:

            SetPosition(getx+21,gety+5);
            scanf("%s",&pass);
        if(strcmp(user[mark].password,pass)!=0)
        {
            SetPosition(getx+15,gety+15);
            printf("�����������,���������������...\n");
            faultcount++;
            getch();
            usercount=0;

//            if(faultcount==3)
//            {
//                SetPosition(getx+15,gety+14);
//                printf("��¼ʧ��");
//                getch();
//                return MenuLogin();
//            }
            system("cls");
            goto userrepeat2;
        }
        SetPosition(getx+14,gety+7);
        printf("��¼�ɹ�...�������������...");
        fclose(fp);
        getch();
        return Menu();
}
//void get_verifying_code() {
//	char str[STR_LEN + 1] = { 0 };
//	int i;
//	srand(time(NULL));
//	for (i = 0; i < STR_LEN; i++)
//	{
//		str[i] = rand() % (CHAR_MAX - CHAR_MIN + 1) + CHAR_MIN;
//	}
//	for (int i = 0; i < STR_LEN; i++)
//		verifyting_code[i] = str[i];
//	printf(str);
//}//��֤��
void DrawLogin()
{
    int i=0,j=0;
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
}
void DrawRegist()
{
    int i=0,j=0;
    SetPosition(getx,gety);
    printf("��--------------------ע��---------------------��");
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
}
