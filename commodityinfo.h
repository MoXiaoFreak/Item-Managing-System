#include "head.h"
void AddCommodityInfo()
{
    struct commodity comm1[50];
  const char *filename = COMMODITYINFO;
  int count=0;
    char b='1';
    int i=0;
    FILE *fp;
	if((fp=fopen(filename,"r+"))==NULL)			// ���ļ�������fpָ�� �ļ�
	{
	    FILE *fp=fopen(filename,"w+");
		printf("�ļ������ڣ����½����ļ���\n");
		system("pause");
		return Menu();
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm1[i].num,comm1[i].name,&comm1[i].price,&comm1[i].counts,&comm1[i].total))//��ȡһ�����ݺ�ָ��ָ����һ�����ݣ������ж��Ƿ�ָ�����һ��
	{
		i++;
		count=i;
	}
    while(b=='1')
	{
        printf("�����������Ʒ����Ϣ��\n");
        repeat1:printf("��Ʒ��ţ�");
        scanf("%d",&comm1[count+1].num);
        for(i=0;i<count+1;i++)
        {
        	if(comm1[i].num==comm1[count+1].num)
        	{
        		printf("��Ʒ����Ѵ��ڣ����������롣\n");
        		goto repeat1;
        	}
        }
        fprintf(fp,"%d\t",comm1[count+1].num);
        repeat2:printf("��Ʒ���ƣ�");
        scanf("%s",comm1[count+1].name);
        for(i=0;i<count+1;i++)
        {
        	if(strcmp(comm1[i].name,comm1[count+1].name)==0)
        	{
        		printf("��Ʒ�����Ѿ����ڣ����������롣\n");
        		goto repeat2;
        	}
        }
        fprintf(fp,"%s\t",comm1[count+1].name);
        printf("��Ʒ�۸�");
        scanf("%lf",&comm1[count+1].price);
        fprintf(fp,"%lf\t",comm1[count+1].price);
        printf("��Ʒ��棺");
        scanf("%lf",&comm1[count+1].counts);
        fprintf(fp,"%lf\t",comm1[count+1].counts);
        printf("��Ʒ�ܼۣ�");
        scanf("%lf",&comm1[count+1].total);
        fprintf(fp,"%lf\t\n",comm1[count+1].total);
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
     struct commodity comm2[50];
	const char *filename = COMMODITYINFO;
    int delnum,x,y=0,cho,rdel;
    int count=0;
    int i=0,j;
    FILE *fp;
	if((fp=fopen(filename,"r"))==NULL)			// ���ļ�������fpָ�� �ļ�
	{
		printf("�ļ������ڡ�\n");
		system("pause");
		return Menu();
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm2[i].num,comm2[i].name,&comm2[i].price,&comm2[i].counts,&comm2[i].total))//��ȡһ�����ݺ�ָ��ָ����һ�����ݣ������ж��Ƿ�ָ�����һ��
	{
		i++;
		count=i;
	}
	repeat1:printf("����������Ҫɾ������Ʒ��ţ�\n");
        scanf("%d",&delnum);
		for(i=0;i<count;i++)
		{
			if(delnum==comm2[i].num)
				{
					y=1;
					cho=i;
				}
		}
		if(y!=1)
		{
			printf("���������Ʒ��Ų����ڡ�\n");
			goto repeat1;
		}
	printf("����Ҫɾ����Ʒ����Ϣ��\t���\t|����\t|�۸�\t\t|����\t\t|�ܼ�\n");
	printf("                      \t %d \t| %s \t| %lf\t| %lf\t| %lf\n",comm2[cho].num,comm2[cho].name,comm2[cho].price,comm2[cho].counts,comm2[cho].total);
	printf("ȷ��Ҫɾ����(����1Ϊ�ǣ�����Ϊ��)");
	scanf("%d",&x);
	if(x==1)
	{
		for(j=cho;j<count-1;j++)
		{
			comm2[j]=comm2[j+1];
			fclose(fp);
		}
		fp=fopen(filename,"w");
		for(j=0;j<count-1;j++)
		{
			fprintf(fp,"%d\t%s\t%lf\t%lf\t%lf\t\n",comm2[j].num,comm2[j].name,comm2[j].price,comm2[j].counts,comm2[j].total);
		}
		printf("ɾ���ɹ���\n");
		count--;

	}else
		printf("�˳�");
        printf("�Ƿ����ɾ��������1Ϊ�ǣ�����Ϊ��");
		scanf("%d",&rdel);
		if(rdel==1)
        {
            if (count==0)
            {
                printf("����Ʒ��Ϣ,�������˵�\n");
                system("pause");
                return Menu();
            }
            else goto repeat1;
        }
        DelCommodityInfo();
		fclose(fp);
		return Menu();
}
void TotalCommodityInfo()
{
    struct commodity comm3[50];
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
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm3[i].num,comm3[i].name,&comm3[i].price,&comm3[i].counts,&comm3[i].total))//��ȡһ�����ݺ�ָ��ָ����һ�����ݣ������ж��Ƿ�ָ�����һ��
	{
		i++;
		count=i;
	}
	for(j=0;j<count;j++)
    {
        sumnum++;
        sumcounts= sumcounts+comm3[j].counts;
        sumtotal=sumtotal+comm3[j].total;
    }
    system("cls");
    printf("��%d����Ʒ  ������%6.lf��  �ܼ�%6.lfԪ\n\n",sumnum,sumcounts,sumtotal);
    system("pause");
    return Menu();
}
void ModifyCommodityInfo()//û��������ļ�
{
    struct commodity comm4[50];
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
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm4[i].num,comm4[i].name,&comm4[i].price,&comm4[i].counts,&comm4[i].total))
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
        if(mnum==comm4[i].num)
        {
            tnum=i;
            printf("�����������Ʒ����Ϣ:\n");
            printf(NAMEOUT);
            printf(FORMATOUT,comm4[i].num,comm4[i].name,comm4[i].price,comm4[i].counts,comm4[i].total);
reinput:printf("��ѡ����Ҫ�޸ĵ�����(1.name   2.price   3.count):");
            scanf("%d",&a);
                switch (a)
                {
                    case 1:
                        printf("��������Ҫ�޸ĳɵ�name:");
                        scanf("%s",comm4[i].name);
                        break;
                    case 2:
                        printf("��������Ҫ�޸ĵ�price:");
                        scanf("%lf",&comm4[i].price);
                        break;
                    case 3:
                        printf("��������Ҫ�޸ĵ�cout:");
                        scanf("%lf",&comm4[i].counts);
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
    struct commodity comm5[50];
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
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm5[i].num,comm5[i].name,&comm5[i].price,&comm5[i].counts,&comm5[i].total))
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
                            if(comm5[j].num>comm5[j+1].num)
                            {
                                int a=comm5[j+1].num;
                                comm5[j+1].num=comm5[j].num;
                                comm5[j].num=a;
                                double b=comm5[j+1].price;
                                comm5[j+1].price=comm5[j].price;
                                comm5[j].price=b;
                                double c=comm5[j+1].counts;
                                comm5[j+1].counts=comm5[j].counts;
                                comm5[j].counts=c;
                                double d=comm5[j+1].total;
                                comm5[j+1].total=comm5[j].total;
                                comm5[j].total=d;
                                char s[15];
                                strcpy(s, comm5[j+1].name);
                                strcpy(comm5[j+1].name,comm5[j].name);
                                strcpy(comm5[j].name,s);

                            }
                        }
                    }
                    break;
                case 2:
                    for(k=0;k<count-1;k++)
                    {
                        for(j=0;j<count-1-k;j++)
                        {
                            if(comm5[j].price>comm5[j+1].price)
                            {
                                int a=comm5[j+1].num;
                                comm5[j+1].num=comm5[j].num;
                                comm5[j].num=a;
                                double b=comm5[j+1].price;
                                comm5[j+1].price=comm5[j].price;
                                comm5[j].price=b;
                                double c=comm5[j+1].counts;
                                comm5[j+1].counts=comm5[j].counts;
                                comm5[j].counts=c;
                                double d=comm5[j+1].total;
                                comm5[j+1].total=comm5[j].total;
                                comm5[j].total=d;
                                char s[15];
                                strcpy(s, comm5[j+1].name);
                                strcpy(comm5[j+1].name,comm5[j].name);
                                strcpy(comm5[j].name,s);
                            }
                        }
                    }
                    break;
                case 3:
                for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comm5[j].counts>comm5[j+1].counts){
                                 int a=comm5[j+1].num;
                                comm5[j+1].num=comm5[j].num;
                                comm5[j].num=a;
                                double b=comm5[j+1].price;
                                comm5[j+1].price=comm5[j].price;
                                comm5[j].price=b;
                                double c=comm5[j+1].counts;
                                comm5[j+1].counts=comm5[j].counts;
                                comm5[j].counts=c;
                                double d=comm5[j+1].total;
                                comm5[j+1].total=comm5[j].total;
                                comm5[j].total=d;
                                char s[15];
                                strcpy(s, comm5[j+1].name);
                                strcpy(comm5[j+1].name,comm5[j].name);
                                strcpy(comm5[j].name,s);
                    }
                }
            }
            break;
        case 4:
            for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comm5[j].total>comm5[j+1].total){
                                 int a=comm5[j+1].num;
                                comm5[j+1].num=comm5[j].num;
                                comm5[j].num=a;
                                double b=comm5[j+1].price;
                                comm5[j+1].price=comm5[j].price;
                                comm5[j].price=b;
                                double c=comm5[j+1].counts;
                                comm5[j+1].counts=comm5[j].counts;
                                comm5[j].counts=c;
                                double d=comm5[j+1].total;
                                comm5[j+1].total=comm5[j].total;
                                comm5[j].total=d;
                                char s[15];
                                strcpy(s, comm5[j+1].name);
                                strcpy(comm5[j+1].name,comm5[j].name);
                                strcpy(comm5[j].name,s);
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
                    if(comm5[j].num<comm5[j+1].num){
                                 int a=comm5[j+1].num;
                                comm5[j+1].num=comm5[j].num;
                                comm5[j].num=a;
                                double b=comm5[j+1].price;
                                comm5[j+1].price=comm5[j].price;
                                comm5[j].price=b;
                                double c=comm5[j+1].counts;
                                comm5[j+1].counts=comm5[j].counts;
                                comm5[j].counts=c;
                                double d=comm5[j+1].total;
                                comm5[j+1].total=comm5[j].total;
                                comm5[j].total=d;
                                char s[15];
                                strcpy(s, comm5[j+1].name);
                                strcpy(comm5[j+1].name,comm5[j].name);
                                strcpy(comm5[j].name,s);
                    }
                }
            }
            break;
        case 2:
            for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comm5[j].price<comm5[j+1].price){
                         int a=comm5[j+1].num;
                                comm5[j+1].num=comm5[j].num;
                                comm5[j].num=a;
                                double b=comm5[j+1].price;
                                comm5[j+1].price=comm5[j].price;
                                comm5[j].price=b;
                                double c=comm5[j+1].counts;
                                comm5[j+1].counts=comm5[j].counts;
                                comm5[j].counts=c;
                                double d=comm5[j+1].total;
                                comm5[j+1].total=comm5[j].total;
                                comm5[j].total=d;
                                char s[15];
                                strcpy(s, comm5[j+1].name);
                                strcpy(comm5[j+1].name,comm5[j].name);
                                strcpy(comm5[j].name,s);
                    }
                }
            }
            break;
        case 3:
            for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comm5[j].counts<comm5[j+1].counts){
                                int a=comm5[j+1].num;
                                comm5[j+1].num=comm5[j].num;
                                comm5[j].num=a;
                                double b=comm5[j+1].price;
                                comm5[j+1].price=comm5[j].price;
                                comm5[j].price=b;
                                double c=comm5[j+1].counts;
                                comm5[j+1].counts=comm5[j].counts;
                                comm5[j].counts=c;
                                double d=comm5[j+1].total;
                                comm5[j+1].total=comm5[j].total;
                                comm5[j].total=d;
                                char s[15];
                                strcpy(s, comm5[j+1].name);
                                strcpy(comm5[j+1].name,comm5[j].name);
                                strcpy(comm5[j].name,s);
                    }
                }
            }
            break;
        case 4:
            for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comm5[j].total<comm5[j+1].total)
                    {
                               int a=comm5[j+1].num;
                                comm5[j+1].num=comm5[j].num;
                                comm5[j].num=a;
                                double b=comm5[j+1].price;
                                comm5[j+1].price=comm5[j].price;
                                comm5[j].price=b;
                                double c=comm5[j+1].counts;
                                comm5[j+1].counts=comm5[j].counts;
                                comm5[j].counts=c;
                                double d=comm5[j+1].total;
                                comm5[j+1].total=comm5[j].total;
                                comm5[j].total=d;
                                char s[15];
                                strcpy(s, comm5[j+1].name);
                                strcpy(comm5[j+1].name,comm5[j].name);
                                strcpy(comm5[j].name,s);
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
     fprintf(fp,"%d\t",comm5[j].num);
     fprintf(fp,"%s\t",comm5[j].name);
     fprintf(fp,"%lf\t",comm5[j].price);
     fprintf(fp,"%lf\t",comm5[j].counts);
     fprintf(fp,"%lf\t\n",comm5[j].total);

   }

 }
}
void Show()
{
    struct commodity comm7[50];
    FILE *fp;
    int i=0,j=3;
    fp=fopen(COMMODITYINFO,"r+");
    while(~fscanf(fp,"%d%s%lf%lf%lf",&comm7[i].num,comm7[i].name,&comm7[i].price,&comm7[i].counts,&comm7[i].total))
	{
		i++;
	}
	j=i;
	rewind(fp);
	if(i==0)
    {
        printf("There is no record in the file.");
    }else
        {
            printf(NAMEOUT);
            for(i=0;i<j;i++)
                printf(FORMATOUT,comm7[i].num,comm7[i].name,comm7[i].price,comm7[i].counts,comm7[i].total);
        }
    fclose(fp);
}

