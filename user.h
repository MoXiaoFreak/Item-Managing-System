#include "head.h"
void UserRegister()
{
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
	printf("��ǰ��%d��ע���û�\n",count);
	userrepeat:printf("������ע���û�����\n");
        scanf("%s",&user[count+1].username);
        for(i=0;i<count+1;i++)
        {
        	if(strcmp(user[i].username,user[count+1].username)==0)
        	{
        		printf("���û����Ѵ��ڣ����������롣\n");
        		goto userrepeat;
        	}
        }
        fprintf(fp,"%s\t",user[count+1].username);
       passrepeat:printf("������ע�����룺\n");
        scanf("%s",&user[count+1].password);
        printf("��ȷ��ע�����룺\n");
        scanf("%s",&pass);
        if(strcmp(user[count+1].password,pass)!=0)
        {
            printf("���벻ƥ�䣬�������趨���룺\n");
            goto passrepeat;
        }
        fprintf(fp,"%s\t\n",user[count+1].password);
        fclose(fp);
        count++;
        printf("ע��ɹ���");
        system("pause");
        return MenuLogin();
}
void UserLogin()
{
    const char *filename =USERINFO;
    int faultcount=0;
    int usercount=0;
     int count=0,i=0,mark=0;
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
	userrepeat2:printf("�������û�����\n");
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
                printf("�޴��û������������룺\n");
                goto userrepeat2;
            }

        }
        printf("���������룺\n");
        passrepeat2:scanf("%s",&pass);
        if(strcmp(user[mark].password,pass)!=0)
        {
            printf("��������������������룺\n");
            goto passrepeat2;
        }
        printf("��¼�ɹ���");
        fclose(fp);
        system("pause");
        return Menu();
}
