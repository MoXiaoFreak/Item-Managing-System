#include "head.h"

void UserRegister()
{
    FILE *fp;
    char temp[20];        //���������ż���������û���������
a:     printf("\n�û�ע��\n");
        printf("�û���:");
        scanf("%s",user[0].username);

        fp=fopen(user[0].username,"r");
        if(fp!=NULL)
        {
           printf("\n\t���û����Ѵ���");
           fclose(fp);
           printf("\n\t����ע��?(Y/N)");
           if(getch()=='Y')
                return UserRegister();
           else
                return UserLogin();
        }

        printf("\n��  ��:");
        scanf("%s",user[0].password);
        printf("\nȷ������:");
        scanf("%s",temp);
        if(strcmp(user[0].password,temp)!=0)
        printf("\n�������벻һ��,����������");
    if(strcmp(user[0].password,temp)!=0)
        goto a;

    fp=fopen(user[0].username,"w");
    if(fp==NULL)
       {
          printf("\nע��ʧ��\n");
          exit(0);
       }
    else
    {
        system("cls");
        printf("\nע��ɹ�\n");
        judge=0;
        UserLogin();             //������ת����½ģ��
    }


}

void UserLogin()
{

    FILE *fp;
    char u[20],c[20],temp;      //�����������飬��ż���������û���������
    printf("\n�û���¼");
    printf("\n�û���:");
    scanf("%s",u);
    fp=fopen(u,"r+");
    temp='0';
    if(fp==NULL)
    {
        printf("\n�û�������,��ע��");
        printf("\n1.ע��   2.���µ�½");
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
        if(judge==1) fread(&user[0],sizeof(user[0]),1,fp); //��ȡ�û���Ϣ�����û���������
        printf("\n��  ��:");
        scanf("%s",c);
        if(strcmp(user[0].password,c)!=0)                      //�Ա����������Ͷ�ȡ������
        {
            printf("\n�������(1.�˳� 2.��������)");
            temp=getch();
            printf("\n");
            if(temp=='1')
            {
                fclose(fp);
                break;                       //�ر��ļ���ֹ�������
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
        printf("��ǰ����%d��ע���û�",total);
        printf("\n\n�������û�����");
        memset(username,'\0',20);
        scanf("%s",&username);
        printf("\n���������룺");
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
                    printf("\n\n��ӭ %s",username);
                    fflush(stdin);
                    _getche();
                    continue;
                }
            }
        }
        if(f_u==0)
        {
            printf("\n\n�����ڸ��û����� ѡ 1 �������룬ѡ 2 ע�����û�");
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
                printf("ע�����û�");
                printf("\n\n\n�������û�����");
                memset(username,'\0',20);
                scanf("%s",&username);
                printf("\n���������룺");
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
                printf("\n���ٴ��������룺");
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
                    printf("\n\nע��ɹ��������µ�¼");
                    fflush(stdin);
                    _getch();
                    count=0;
                   ReadData();
                    continue;
                }
                else
                {
                    printf("\n\n�������벻һ�£�ע��ʧ��");
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
                printf("\n\n��������3�δ��󣬳����˳�");
                fflush(stdin);
                _getche();
                return ;
            }
            printf("\n\n���������������������");
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
// �������н�password�����*��, ���������Է��Ÿ���
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
// ��д���ļ�ʱ���԰�һ��������ʽ���룬�ɼ����Ժ�Loginʱ��searchʱ��
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
if ((fp=fopen("c:\\data", "rt+")) ==) { // ע�⣬һ��Ҫ�и�����data��û�У��ĺϷ��ļ���C��
printf("---------File is not exist\n");
system("pause");
exit(0);
}
else
fclose(fp);
}
int main(void){
int command;
init(); // ���data�ļ��ڲ���
while (true) {
printf("-----------------------(Login: 1 Register: 2 Exit: 3)\n");
scanf("%d", &command);
printf("-----------------------\n");
// ������Ա�дcommand�ļ�����
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
