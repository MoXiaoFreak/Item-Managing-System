#include "head.h"
void Search()
    {
        struct commodity comm6[50];
    printf("��Ʒ�б�:\n");
    Show();
    FILE *fp;
    int i=0,j,find_num,ch,b,m=0;
    int ch1,b1;
    char *find_name[20];
    const char *filename = COMMODITYINFO;
	if((fp=fopen(filename,"r+"))==NULL)
	{
		printf("�ļ�������\n");
		exit(1);
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm6[i].num,comm6[i].name,&comm6[i].price,&comm6[i].counts,&comm6[i].total))
	{
		i++;
	}
	j=i;
	printf("��ѡ����Ҫ������ѡ��(1.��� 2.����):");
	scanf("%d",&ch);
	if(ch==1||ch==2)
    {
            switch(ch)
            {
            case 1:
                printf("�������ѯ����:");
                scanf("%d",&find_num);
                for(i=0;i<j;i++)
                {
                    if(find_num==comm6[i].num)
                    {
                        m=i;
                    }
                }
                i=m;
                if(find_num==comm6[m].num)
                    {
                        printf("����Ʒ��������:\n");
                        printf(NAMEOUT);
                        printf(FORMATOUT,comm6[i].num,comm6[i].name,comm6[i].price,comm6[i].counts,comm6[i].total);
                    }else
                    {
                        printf("δ��ѯ������Ʒ....");
                    }
                break;
            case 2:
                printf("��ѡ���ѯ��ʽ(1.��ȷ����  2.�ؼ��ֲ���):");

                scanf("%d",&ch1);
                while(ch1==1||ch1==2)
                {
                    switch(ch1)
                    {
                    case 1:
                        printf("�������ѯ����:");
                        scanf("%s",find_name);
                        for(i=0;i<j;i++)
                        {
                              if(strcmp(find_name,comm6[i].name)==0)
                            {
                                m=i;
                            }
                        }
                        i=m;
                        if(strcmp(find_name,comm6[i].name)==0)
                            {
                                printf("����Ʒ��������:\n");
                                printf(NAMEOUT);
                                printf(FORMATOUT,comm6[i].num,comm6[i].name,comm6[i].price,comm6[i].counts,comm6[i].total);
                            }else
                            {
                                printf("δ��ѯ������Ʒ....");
                            }
                        break;
                    case 2:
                        printf("�������ѯ����:");
                        scanf("%s",find_name);
                        int q[50];
                        for(i=0;i<j;i++)
                        {
                              if(strstr(comm6[i].name,find_name)!= NULL)
                              {
                                  q[m]=i;
                                  m++;
                              }
                        }
                        if(m==0)
                        {
                            printf("δ��ѯ�������Ʒ...(��������ز�ѯ�˵�)");
                            getch();
                            system("cls");
                            return Search();
                        }else
                        {
                            printf("����Ʒ��������:\n");
                            printf(NAMEOUT);
                            for(j=0;j<m;j++)
                            {
                                i=q[j];
                                printf(FORMATOUT,comm6[i].num,comm6[i].name,comm6[i].price,comm6[i].counts,comm6[i].total);

                            }
                        }
                        break;
                    default:
                        printf("��������ȷ��ѡ��\n");
                        break;

                    }
                    ch1=3;
                    ch=3;
                }
                break;
            default:
                printf("��������ȷ��ѡ��\n");
                break;
            }
            printf("�������������....\n");
            getch();
			printf("�Ƿ������ѯ��Ʒ������'1'Ϊ�ǣ�����Ϊ��:\n");
            scanf("%d",&b);
			if(b==1)
            {
                system("cls");
                return Search();
            }
            else
            {
                ch=3;
                ch1=3;
                system("cls");
                return Menu();
            }
    }
    else
    {
        printf("�������...");
        getch();
        Menu();
    }
}

