#include "head.h"
void AddCommodityInfo()
{
  const char *filename = "D:\\commodity.txt";
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
	const char *filename = "D:\\commodity.txt";
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
    const char *filename = "D:\\commodity.txt";
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
void ModifyCommodityInfo()
{

}
void InsertCommodityInfo()
{

}
void OrderCommodityInfo()
{

}
void Show()
{

}
