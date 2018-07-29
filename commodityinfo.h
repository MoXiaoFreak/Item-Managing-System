#include "head.h"
void AddCommodityInfo()
{
  const char *filename = "D:\\commodity.txt";
  int count=0;
    char b='1';
    int i=0;
    FILE *fp;
	if((fp=fopen(filename,"r+"))==NULL)			// 打开文件并且让fp指向 文件
	{
		printf("Can not open file\n");
		exit(1);
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm[i].num,comm[i].name,&comm[i].price,&comm[i].counts,&comm[i].total))//读取一组数据后指针指向下一组数据，并且判断是否指向最后一行
	{
		i++;
		count=i;
	}
    while(b=='1')
	{
        printf("请输入添加商品的信息：\n");
        repeat1:printf("商品编号：");
        scanf("%d",&comm[count+1].num);
        for(i=0;i<count+1;i++)
        {
        	if(comm[i].num==comm[count+1].num)
        	{
        		printf("商品编号已存在，请重新输入。\n");
        		goto repeat1;
        	}
        }
        fprintf(fp,"%d\t",comm[count+1].num);
        repeat2:printf("商品名称：");
        scanf("%s",comm[count+1].name);
        for(i=0;i<count+1;i++)
        {
        	if(strcmp(comm[i].name,comm[count+1].name)==0)
        	{
        		printf("商品名称已经存在，请重新输入。\n");
        		goto repeat2;
        	}
        }
        fprintf(fp,"%s\t",comm[count+1].name);
        printf("商品价格：");
        scanf("%lf",&comm[count+1].price);
        fprintf(fp,"%lf\t",comm[count+1].price);
        printf("商品库存：");
        scanf("%lf",&comm[count+1].counts);
        fprintf(fp,"%lf\t",comm[count+1].counts);
        printf("商品总价：");
        scanf("%lf",&comm[count+1].total);
        fprintf(fp,"%lf\t\n",comm[count+1].total);
        count=count+1;
        printf("是否继续录入商品：输入'1'为是，其他为否:\n");
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
	if((fp=fopen(filename,"r"))==NULL)			// 打开文件并且让fp指向 文件
	{
		printf("Can not open file\n");
		exit(1);
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm[i].num,comm[i].name,&comm[i].price,&comm[i].counts,&comm[i].total))//读取一组数据后指针指向下一组数据，并且判断是否指向最后一行
	{
		i++;
		count=i;
	}
	printf("请输入你想要删除的商品编号：\n");
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
			printf("您输入的商品编号不存在。");
			goto repeat1;
		}
	printf("您所要删除商品的信息：\t编号\t|名称\t|价格\t\t|数量\t\t|总价\n");
	printf("                      \t %d \t| %s \t| %lf\t| %lf\t| %lf\n",comm[cho].num,comm[cho].name,comm[cho].price,comm[cho].counts,comm[cho].total);
	printf("确定要删除吗？(输入1为是，其他为否：)");
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
		printf("删除成功。\n");
		count--;

	}else
		printf("退出");
		printf("是否继续删除？输入1为是，其他为否");
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
	if((fp=fopen(filename,"r"))==NULL)			// 打开文件并且让fp指向 文件
	{
		printf("Can not open file\n");
		exit(1);
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm[i].num,comm[i].name,&comm[i].price,&comm[i].counts,&comm[i].total))//读取一组数据后指针指向下一组数据，并且判断是否指向最后一行
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
    printf("共%d种商品  总数量%6.lf件  总价%6.lf元\n\n",sumnum,sumcounts,sumtotal);
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
