#include "head.h"
void AddCommodityInfo()
{
  const char *filename = COMMODITYINFO;
  int count=0;
    char b='1';
    int i=0;
    FILE *fp;
	if((fp=fopen(filename,"r+"))==NULL)			// ���ļ�������fpָ�� �ļ�
	{
		printf("Can not open file\n");
		exit(1);
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm[i].num,comm[i].name,&comm[i].price,&comm[i].counts,&comm[i].total))//��ȡһ�����ݺ�ָ��ָ����һ�����ݣ������ж��Ƿ�ָ�����һ��
	{
		i++;
		count=i;
	}
    while(b=='1')
	{
        printf("�����������Ʒ����Ϣ��\n");
        repeat1:printf("��Ʒ��ţ�");
        scanf("%d",&comm[count+1].num);
        for(i=0;i<count+1;i++)
        {
        	if(comm[i].num==comm[count+1].num)
        	{
        		printf("��Ʒ����Ѵ��ڣ����������롣\n");
        		goto repeat1;
        	}
        }
        fprintf(fp,"%d\t",comm[count+1].num);
        repeat2:printf("��Ʒ���ƣ�");
        scanf("%s",comm[count+1].name);
        for(i=0;i<count+1;i++)
        {
        	if(strcmp(comm[i].name,comm[count+1].name)==0)
        	{
        		printf("��Ʒ�����Ѿ����ڣ����������롣\n");
        		goto repeat2;
        	}
        }
        fprintf(fp,"%s\t",comm[count+1].name);
        printf("��Ʒ�۸�");
        scanf("%lf",&comm[count+1].price);
        fprintf(fp,"%lf\t",comm[count+1].price);
        printf("��Ʒ��棺");
        scanf("%lf",&comm[count+1].counts);
        fprintf(fp,"%lf\t",comm[count+1].counts);
        printf("��Ʒ�ܼۣ�");
        scanf("%lf",&comm[count+1].total);
        fprintf(fp,"%lf\t\n",comm[count+1].total);
        count=count+1;
        printf("¼��ɹ���\n");
        printf("�Ƿ����¼����Ʒ������'1'Ϊ�ǣ�����Ϊ��:\n");
        fflush(stdin);
        scanf("%c",&b);
        if(b!='1')
                break;
    }
 fclose(fp);
 return Menu();
}
void DelCommodityInfo()
{
	const char *filename = COMMODITYINFO;
    int delnum,x,y=0,cho,rdel;
    int count=0;
    int i=0,j;
    FILE *fp;
	if((fp=fopen(filename,"r"))==NULL)			// ���ļ�������fpָ�� �ļ�
	{
		printf("Can not open file\n");
		exit(1);
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm[i].num,comm[i].name,&comm[i].price,&comm[i].counts,&comm[i].total))//��ȡһ�����ݺ�ָ��ָ����һ�����ݣ������ж��Ƿ�ָ�����һ��
	{
		i++;
		count=i;
	}
	printf("����������Ҫɾ������Ʒ��ţ�\n");
repeat1:scanf("%d",&delnum);
		for(i=0;i<count;i++)
		{
			if(delnum==comm[i].num)
				{
					y=1;
					cho=i;
				}
		}
		if(y!=1)
		{
			printf("���������Ʒ��Ų����ڡ�");
			goto repeat1;
		}
	printf("����Ҫɾ����Ʒ����Ϣ��\t���\t|����\t|�۸�\t\t|����\t\t|�ܼ�\n");
	printf("                      \t %d \t| %s \t| %lf\t| %lf\t| %lf\n",comm[cho].num,comm[cho].name,comm[cho].price,comm[cho].counts,comm[cho].total);
	printf("ȷ��Ҫɾ����(����1Ϊ�ǣ�����Ϊ��)");
	scanf("%d",&x);
	if(x==1)
	{
		for(j=cho;j<count-1;j++)
		{
			comm[j]=comm[j+1];
			fclose(fp);
		}
		fp=fopen(filename,"w");
		for(j=0;j<count-1;j++)
		{
			fprintf(fp,"%d\t%s\t%lf\t%lf\t%lf\t\n",comm[j].num,comm[j].name,comm[j].price,comm[j].counts,comm[j].total);
		}
		printf("ɾ���ɹ���\n");
		count--;

	}else
		printf("�˳�");
		printf("�Ƿ����ɾ��������1Ϊ�ǣ�����Ϊ��");
		scanf("%d",&rdel);
		if(rdel==1)
			DelCommodityInfo();
		fclose(fp);
		return Menu();
}
void TotalCommodityInfo()
{
    const char *filename = COMMODITYINFO;
    int count=0;
    int i=0,j;
    int sumnum=0;
    double sumcounts=0,sumtotal=0;
    FILE *fp;
	if((fp=fopen(filename,"r"))==NULL)			// ���ļ�������fpָ�� �ļ�
	{
		printf("Can not open file\n");
		exit(1);
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm[i].num,comm[i].name,&comm[i].price,&comm[i].counts,&comm[i].total))//��ȡһ�����ݺ�ָ��ָ����һ�����ݣ������ж��Ƿ�ָ�����һ��
	{
		i++;
		count=i;
	}
	for(j=0;j<count;j++)
    {
        sumnum++;
        sumcounts= sumcounts+comm[j].counts;
        sumtotal=sumtotal+comm[j].total;
    }
    system("cls");
    printf("��%d����Ʒ  ������%6.lf��  �ܼ�%6.lfԪ\n\n",sumnum,sumcounts,sumtotal);
    system("pause");
    return Menu();
}
void ModifyCommodityInfo()//û��������ļ�
{
    FILE *fp;
    int i=0,j,mnum,a,tnum;
    char get[20];
    char aa;
    const char *filename = COMMODITYINFO;
	if((fp=fopen(filename,"r+"))==NULL)
	{
		printf("Can not open file\n");
		exit(1);
	}

	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm[i].num,comm[i].name,&comm[i].price,&comm[i].counts,&comm[i].total))
	{
		i++;
	}

	j=i;
	if(i==0)
    {
        printf("There is no record in the file.");
    }else
        {
            printf("Original data:\n");

            Show();
            printf("��������Ҫ�޸ĵ���Ʒ�ı��:");
        }
    scanf("%d",&mnum);
    for(i=0;i<j;i++)
    {
        if(mnum==comm[i].num)
        {
            tnum=i;
            printf("�����������Ʒ����Ϣ:\n");
            printf(NAMEOUT);
            printf(FORMATOUT,DATA);
reinput:printf("��ѡ����Ҫ�޸ĵ�����(1.name   2.price   3.count):");
            scanf("%d",&a);
                switch (a)
                {
                    case 1:
                        printf("��������Ҫ�޸ĳɵ�name:");
                        scanf("%s",comm[i].name);
                        break;
                    case 2:
                        printf("��������Ҫ�޸ĵ�price:");
                        scanf("%lf",&comm[i].price);
                        break;
                    case 3:
                        printf("��������Ҫ�޸ĵ�cout:");
                        scanf("%lf",&comm[i].counts);
                        break;
                    default:
                        printf("������1-3֮�������.\n");
                        goto reinput;
                }
                printf("�����޸ı���Ʒ��Ϣ��Y/N\n");
               scanf("%c",&aa);
                if(aa=='Y')
                     goto reinput;
                else
                {
                    printf("�������������....\n");
                    system("pause");
                    return Menu();
                }
        }
    }
}
void InsertCommodityInfo()
{

}
void OrderCommodityInfo()
{
    system("cls");
    const char *filename = COMMODITYINFO;
    int i=0,j=0,n=1,m=0,k=0;
    int count=0;
    FILE *fp;
	if((fp=fopen(filename,"r+"))==NULL)
	{
		printf("Can not open file\n");
		exit(1);
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm[i].num,comm[i].name,&comm[i].price,&comm[i].counts,&comm[i].total))
	{
		i++;
		count=i;
	}
	printf("��������:\n");
	printf("1.�����\n");
	printf("2.������\n");
	printf("3.������\n");
	printf("4.���ܼ�\n");
	printf("5.����menu\n");
    while(n)
    {
        printf("��ѡ���������ݻ򷵻�menu,��������1-5:");
        scanf("%d",&n);
        if(n==5)
        {
            fclose(fp);
            return Menu();
        }
        printf("��ѡ����������\n6:����\n7:����\n");
        scanf("%d",&m);
        if(m==6)
        {
            switch(n)
            {
                case 1:
                    for(k=0;k<count-1;k++)
                    {
                        for(j=0;j<count-1-k;j++)
                        {
                            if(comm[j].num>comm[j+1].num)
                            {
                                int a=comm[j+1].num;
                                comm[j+1].num=comm[j].num;
                                comm[j].num=a;
                                double b=comm[j+1].price;
                                comm[j+1].price=comm[j].price;
                                comm[j].price=b;
                                double c=comm[j+1].counts;
                                comm[j+1].counts=comm[j].counts;
                                comm[j].counts=c;
                                double d=comm[j+1].total;
                                comm[j+1].total=comm[j].total;
                                comm[j].total=d;
                                char s[15];
                                strcpy(s, comm[j+1].name);
                                strcpy(comm[j+1].name,comm[j].name);
                                strcpy(comm[j].name,s);

                            }
                        }
                    }
                    break;
                case 2:
                    for(k=0;k<count-1;k++)
                    {
                        for(j=0;j<count-1-k;j++)
                        {
                            if(comm[j].price>comm[j+1].price)
                            {
                                int a=comm[j+1].num;
                                comm[j+1].num=comm[j].num;
                                comm[j].num=a;
                                double b=comm[j+1].price;
                                comm[j+1].price=comm[j].price;
                                comm[j].price=b;
                                double c=comm[j+1].counts;
                                comm[j+1].counts=comm[j].counts;
                                comm[j].counts=c;
                                double d=comm[j+1].total;
                                comm[j+1].total=comm[j].total;
                                comm[j].total=d;
                                 char s[15];
                                strcpy(s, comm[j+1].name);
                                strcpy(comm[j+1].name,comm[j].name);
                                strcpy(comm[j].name,s);
                            }
                        }
                    }
                    break;
                case 3:
                for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comm[j].counts>comm[j+1].counts){
                                int a=comm[j+1].num;
                                comm[j+1].num=comm[j].num;
                                comm[j].num=a;
                                double b=comm[j+1].price;
                                comm[j+1].price=comm[j].price;
                                comm[j].price=b;
                                double c=comm[j+1].counts;
                                comm[j+1].counts=comm[j].counts;
                                comm[j].counts=c;
                                double d=comm[j+1].total;
                                comm[j+1].total=comm[j].total;
                                comm[j].total=d;
                                 char s[15];
                                strcpy(s, comm[j+1].name);
                                strcpy(comm[j+1].name,comm[j].name);
                                strcpy(comm[j].name,s);
                    }
                }
            }
            break;
        case 4:
            for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comm[j].total>comm[j+1].total){
                                int a=comm[j+1].num;
                                comm[j+1].num=comm[j].num;
                                comm[j].num=a;
                                double b=comm[j+1].price;
                                comm[j+1].price=comm[j].price;
                                comm[j].price=b;
                                double c=comm[j+1].counts;
                                comm[j+1].counts=comm[j].counts;
                                comm[j].counts=c;
                                double d=comm[j+1].total;
                                comm[j+1].total=comm[j].total;
                                comm[j].total=d;
                                 char s[15];
                                strcpy(s, comm[j+1].name);
                                strcpy(comm[j+1].name,comm[j].name);
                                strcpy(comm[j].name,s);
                    }
                }
            }
            break;
        default:
            printf("�������\n");
            break;
     }
    }
    else if(m==7){
     switch(n)
     {
        case 1:
            for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comm[j].num<comm[j+1].num){
                        int a=comm[j+1].num;
                                comm[j+1].num=comm[j].num;
                                comm[j].num=a;
                                double b=comm[j+1].price;
                                comm[j+1].price=comm[j].price;
                                comm[j].price=b;
                                double c=comm[j+1].counts;
                                comm[j+1].counts=comm[j].counts;
                                comm[j].counts=c;
                                double d=comm[j+1].total;
                                comm[j+1].total=comm[j].total;
                                comm[j].total=d;
                                char s[15];
                                strcpy(s, comm[j+1].name);
                                strcpy(comm[j+1].name,comm[j].name);
                                strcpy(comm[j].name,s);
                    }
                }
            }
            break;
        case 2:
            for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comm[j].price<comm[j+1].price){
                         int a=comm[j+1].num;
                                comm[j+1].num=comm[j].num;
                                comm[j].num=a;
                                double b=comm[j+1].price;
                                comm[j+1].price=comm[j].price;
                                comm[j].price=b;
                                double c=comm[j+1].counts;
                                comm[j+1].counts=comm[j].counts;
                                comm[j].counts=c;
                                double d=comm[j+1].total;
                                comm[j+1].total=comm[j].total;
                                comm[j].total=d;
                                char s[15];
                                strcpy(s, comm[j+1].name);
                                strcpy(comm[j+1].name,comm[j].name);
                                strcpy(comm[j].name,s);
                    }
                }
            }
            break;
        case 3:
            for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comm[j].counts<comm[j+1].counts){
                                int a=comm[j+1].num;
                                comm[j+1].num=comm[j].num;
                                comm[j].num=a;
                                double b=comm[j+1].price;
                                comm[j+1].price=comm[j].price;
                                comm[j].price=b;
                                double c=comm[j+1].counts;
                                comm[j+1].counts=comm[j].counts;
                                comm[j].counts=c;
                                double d=comm[j+1].total;
                                comm[j+1].total=comm[j].total;
                                comm[j].total=d;
                                char s[15];
                                strcpy(s, comm[j+1].name);
                                strcpy(comm[j+1].name,comm[j].name);
                                strcpy(comm[j].name,s);
                    }
                }
            }
            break;
        case 4:
            for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comm[j].total<comm[j+1].total)
                    {
                                int a=comm[j+1].num;
                                comm[j+1].num=comm[j].num;
                                comm[j].num=a;
                                double b=comm[j+1].price;
                                comm[j+1].price=comm[j].price;
                                comm[j].price=b;
                                double c=comm[j+1].counts;
                                comm[j+1].counts=comm[j].counts;
                                comm[j].counts=c;
                                double d=comm[j+1].total;
                                comm[j+1].total=comm[j].total;
                                comm[j].total=d;
                                char s[15];
                                strcpy(s, comm[j+1].name);
                                strcpy(comm[j+1].name,comm[j].name);
                                strcpy(comm[j].name,s);
                    }
                }
            }
            break;
        default:
            printf("�������\n");
            break;
     }
   }
   else{
    printf("�������");
   }
   fp=fopen(filename,"w+");
   for(j=0;j<count;j++){
     fprintf(fp,"%d\t",comm[j].num);
     fprintf(fp,"%s\t",comm[j].name);
     fprintf(fp,"%lf\t",comm[j].price);
     fprintf(fp,"%lf\t",comm[j].counts);
     fprintf(fp,"%lf\t\n",comm[j].total);

   }

 }
}
void Show()
{

}
