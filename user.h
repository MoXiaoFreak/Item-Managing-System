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
	printf("当前共%d个注册用户\n",count);
	userrepeat:printf("请输入注册用户名：\n");
        scanf("%s",&user[count+1].username);
        for(i=0;i<count+1;i++)
        {
        	if(strcmp(user[i].username,user[count+1].username)==0)
        	{
        		printf("该用户名已存在，请重新输入。\n");
        		goto userrepeat;
        	}
        }
        fprintf(fp,"%s\t",user[count+1].username);
       passrepeat:printf("请输入注册密码：\n");
        scanf("%s",&user[count+1].password);
        printf("请确认注册密码：\n");
        scanf("%s",&pass);
        if(strcmp(user[count+1].password,pass)!=0)
        {
            printf("密码不匹配，请重新设定密码：\n");
            goto passrepeat;
        }
        fprintf(fp,"%s\t\n",user[count+1].password);
        fclose(fp);
        count++;
        printf("注册成功！");
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
	  printf("无用户注册记录，跳转到用户注册......\n");
	  return UserRegister();
	}
	while(~fscanf(fp,"%s%s",&user[i].username,&user[i].password))
	{
		i++;
		count=i;
	}
	userrepeat2:printf("请输入用户名：\n");
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
                printf("无此用户，请重新输入：\n");
                goto userrepeat2;
            }

        }
        printf("请输入密码：\n");
        passrepeat2:scanf("%s",&pass);
        if(strcmp(user[mark].password,pass)!=0)
        {
            printf("密码输入错误，请重新输入：\n");
            goto passrepeat2;
        }
        printf("登录成功！");
        fclose(fp);
        system("pause");
        return Menu();
}
