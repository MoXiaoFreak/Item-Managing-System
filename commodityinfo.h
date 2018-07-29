#include "head.h"
void AddCommodityInfo()
{
  const char *filename = COMMODITYINFO;
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
        printf("录入成功！\n");
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
	const char *filename = COMMODITYINFO;
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
    const char *filename = COMMODITYINFO;
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
void ModifyCommodityInfo()//没有输出到文件
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
            printf("请输入需要修改的商品的编号:");
        }
    scanf("%d",&mnum);
    for(i=0;i<j;i++)
    {
        if(mnum==comm[i].num)
        {
            tnum=i;
            printf("下面是这个商品的信息:\n");
            printf(NAMEOUT);
            printf(FORMATOUT,DATA);
reinput:printf("请选择需要修改的内容(1.name   2.price   3.count):");
            scanf("%d",&a);
                switch (a)
                {
                    case 1:
                        printf("请输入需要修改成的name:");
                        scanf("%s",comm[i].name);
                        break;
                    case 2:
                        printf("请输入需要修改的price:");
                        scanf("%lf",&comm[i].price);
                        break;
                    case 3:
                        printf("请输入需要修改的cout:");
                        scanf("%lf",&comm[i].counts);
                        break;
                    default:
                        printf("请输入1-3之间的数字.\n");
                        goto reinput;
                }
                printf("继续修改本商品信息？Y/N\n");
               scanf("%c",&aa);
                if(aa=='Y')
                     goto reinput;
                else
                {
                    printf("输入任意键继续....\n");
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
	printf("排序依据:\n");
	printf("1.按序号\n");
	printf("2.按单价\n");
	printf("3.按数量\n");
	printf("4.按总价\n");
	printf("5.返回menu\n");
    while(n)
    {
        printf("请选择排序依据或返回menu,输入数字1-5:");
        scanf("%d",&n);
        if(n==5)
        {
            fclose(fp);
            return Menu();
        }
        printf("请选择排序升降\n6:升序\n7:降序\n");
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
            printf("输入错误\n");
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
            printf("输入错误\n");
            break;
     }
   }
   else{
    printf("输入错误");
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
