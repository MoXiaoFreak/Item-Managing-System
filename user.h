#include "head.h"

void UserRegister()
{
    FILE *fp;
    char temp[20];        //定义数组存放键盘输入的用户名和密码
a:     printf("\n用户注册\n");
        printf("用户名:");
        scanf("%s",user[0].username);

        fp=fopen(user[0].username,"r");
        if(fp!=NULL)
        {
           printf("\n\t该用户名已存在");
           fclose(fp);
           printf("\n\t继续注册?(Y/N)");
           if(getch()=='Y')
                return UserRegister();
           else
                return UserLogin();
        }

        printf("\n密  码:");
        scanf("%s",user[0].password);
        printf("\n确认密码:");
        scanf("%s",temp);
        if(strcmp(user[0].password,temp)!=0)
        printf("\n两次密码不一致,请重新输入");
    if(strcmp(user[0].password,temp)!=0)
        goto a;

    fp=fopen(user[0].username,"w");
    if(fp==NULL)
       {
          printf("\n注册失败\n");
          exit(0);
       }
    else
    {
        system("cls");
        printf("\n注册成功\n");
        judge=0;
        UserLogin();             //这里跳转到登陆模块
    }


}

void UserLogin()
{

    FILE *fp;
    char u[20],c[20],temp;      //定义两个数组，存放键盘输入的用户名和密码
    printf("\n用户登录");
    printf("\n用户名:");
    scanf("%s",u);
    fp=fopen(u,"r+");
    temp='0';
    if(fp==NULL)
    {
        printf("\n用户不存在,请注册");
        printf("\n1.注册   2.重新登陆");
        temp=getch();
        if(temp=='1')
        {
            system("cls");
            UserRegister();
        }
        else return UserLogin();
    }
    do
    {
        if(judge==1) fread(&user[0],sizeof(user[0]),1,fp); //读取用户信息，即用户名和密码
        printf("\n密  码:");
        scanf("%s",c);
        if(strcmp(user[0].password,c)!=0)                      //对比输入的密码和读取的密码
        {
            printf("\n密码错误(1.退出 2.重新输入)");
            temp=getch();
            printf("\n");
            if(temp=='1')
            {
                fclose(fp);
                break;                       //关闭文件防止错误操作
            }
        }
    }while(temp=='2');
    return Menu();
}
/*
void ReadData()
{
    int total=GetPrivateProfileInt("INFO","count",0,"e:\\Info.dat");
    int i;
    char t[5]={"\0"};
    for(i=0;i<total;i++)
    {
        sprintf(t,"%d",i+1);
        GetPrivateProfileString(t,"USERNAME","",user[i].username,20,"e:\\Info.dat");
        GetPrivateProfileString(t,"PASSWORD","",user[i].password,20,"e:\\Info.dat");
    }
}

void UserLogin()
{
    int p,i=0,count=0,f_u=0,f_p=0,total=0;
    char username[20]={"\0"};
    char password[20]={"\0"};
    while(1)
    {
        f_u=0;
        f_p=0;
        system("cls");
        printf("当前共有%d个注册用户",total);
        printf("\n\n请输入用户名：");
        memset(username,'\0',20);
        scanf("%s",&username);
        printf("\n请输入密码：");
        memset(password,'\0',20);
        i=0;
        while(1)
        {
            p=_getch();
            if(p==10 || p==13)
            {
                break;
            }
            password[i++]=p;
            printf("*");
        }
        for(i=0;i<total;i++)
        {
            if(strcmp(user[i].username,username)==0)
            {
                f_u=1;
                if(strcmp(user[i].password,password)==0)
                {
                    f_p=1;
                    printf("\n\n欢迎 %s",username);
                    fflush(stdin);
                    _getche();
                    continue;
                }
            }
        }
        if(f_u==0)
        {
            printf("\n\n不存在该用户名！ 选 1 重新输入，选 2 注册新用户");
            int c=0;
            fflush(stdin);
            c=_getche();
            if(c=='1')
            {
                continue;
            }
            else if(c=='2')
            {
                system("cls");
                printf("注册新用户");
                printf("\n\n\n请输入用户名：");
                memset(username,'\0',20);
                scanf("%s",&username);
                printf("\n请输入密码：");
                char temp[20]={"\0"} ;
                i=0;
                while(1)
                {
                    p=_getch();
                    if(p==10 || p==13)
                    {
                        break;
                    }
                    i++;
                    temp[i]=p;
                    printf("*");
                }
                printf("\n请再次输入密码：");
                i=0;
                memset(password,'\0',20);
                while(1)
                {
                    p=_getch();
                    if(p==10 || p==13)
                    {
                        break;
                    }
                    i++;
                    password[i]=p;
                    printf("*");
                }
                if(strcmp(temp,password)==0)
                {
                    total++;
                    char t[5]={"\0"};
                    sprintf(t,"%d",total);
                    WritePrivateProfileString("INFO","count",t,"e:\\Info.dat");
                    WritePrivateProfileString(t,"USERNAME",username,"e:\\Info.dat");
                    WritePrivateProfileString(t,"PASSWORD",password,"e:\\Info.dat");
                    printf("\n\n注册成功，请重新登录");
                    fflush(stdin);
                    _getch();
                    count=0;
                   ReadData();
                    continue;
                }
                else
                {
                    printf("\n\n两次密码不一致，注册失败");
                    fflush(stdin);
                    _getch();
                    count=0;
                    continue;
                }
            }
        }
        else if(f_p==0)
        {
            count++;
            if(count>=3)
            {
                printf("\n\n连续输入3次错误，程序将退出");
                fflush(stdin);
                _getche();
                return ;
            }
            printf("\n\n密码输入错误，请重新输入");
            fflush(stdin);
            _getche();
        }
    }
    return ;
}
*/
/*
bool search(char id[], char pass[])
{
    *fp;
    char tid[10], tpass[10];
    fp = fopen("c:\\data", "rt+");
    while (!feof(fp))
    {
        fscanf(fp, "%s%s", tid, tpass);
        if ((tid, id)==0 &&(tpass, pass)==0)
        {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return false;
}
bool login() {
char id[10], pass[10];
printf("Login\nPress the id: ");
scanf("%s", id);
printf("Press the password: ");
// 可以自行将password处理成*号, 如果不会可以发信给我
scanf("%s", pass);
printf("-----------------------");
if (search(id, pass))
return true;
else
return false;
}
void _add(char id[], char pass[]) {
*fp;
fp=fopen("c:\\data", "a");
// 在写入文件时可以按一定的排序方式插入，可减少以后Login时的search时间
fprintf(fp, "%s %s\n", id, pass);
fclose(fp);
}
void regis() {
char id[10], pass[10], tpass[10];
printf("Register\nPress the id: ");
scanf("%s", id);
while (true) {
printf("Press the password: ");
scanf("%s", pass);
printf("Press the password again: ");
scanf("%s", tpass);
if (
(pass, tpass) != 0)
printf("The passwords you pressed are not the same!\n");
else
break;
}
_add(id, pass);
printf("-----------------------Register successfully!\n");
}
void init() {
*fp;
if ((fp=fopen("c:\\data", "rt+")) ==) { // 注意，一定要有个名叫data（没有）的合法文件在C盘
printf("---------File is not exist\n");
system("pause");
exit(0);
}
else
fclose(fp);
}
int main(void){
int command;
init(); // 检查data文件在不在
while (true) {
printf("-----------------------(Login: 1 Register: 2 Exit: 3)\n");
scanf("%d", &command);
printf("-----------------------\n");
// 这里可以编写command的检测语句
if (command == 3)
break;
else if (command == 1) {
if (!login())
printf("ID is not exist or password is wrong!\n");
else
printf("Login successfully!\n");
}
else
regis();
}
return 0;
}
*/
