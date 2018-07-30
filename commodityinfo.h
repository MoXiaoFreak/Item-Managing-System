#include "head.h"
void AddCommodityInfo()
{
    struct commodity comm1[50];
  const char *filename = COMMODITYINFO;
  int count=0;
    char b='1';
    int i=0;
    FILE *fp;
	if((fp=fopen(filename,"r+"))==NULL)			// 打开文件并且让fp指向 文件
	{
	    FILE *fp=fopen(filename,"w+");
		printf("文件不存在，已新建该文件。\n");
		system("pause");
		return Menu();
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm1[i].num,comm1[i].name,&comm1[i].price,&comm1[i].counts,&comm1[i].total))//读取一组数据后指针指向下一组数据，并且判断是否指向最后一行
	{
		i++;
		count=i;
	}
    while(b=='1')
	{
        printf("请输入添加商品的信息：\n");
        repeat1:printf("商品编号：");
        scanf("%d",&comm1[count+1].num);
        for(i=0;i<count+1;i++)
        {
        	if(comm1[i].num==comm1[count+1].num)
        	{
        		printf("商品编号已存在，请重新输入。\n");
        		goto repeat1;
        	}
        }
        fprintf(fp,"%d\t",comm1[count+1].num);
        repeat2:printf("商品名称：");
        scanf("%s",comm1[count+1].name);
        for(i=0;i<count+1;i++)
        {
        	if(strcmp(comm1[i].name,comm1[count+1].name)==0)
        	{
        		printf("商品名称已经存在，请重新输入。\n");
        		goto repeat2;
        	}
        }
        fprintf(fp,"%s\t",comm1[count+1].name);
        printf("商品价格：");
        scanf("%lf",&comm1[count+1].price);
        fprintf(fp,"%lf\t",comm1[count+1].price);
        printf("商品库存：");
        scanf("%lf",&comm1[count+1].counts);
        fprintf(fp,"%lf\t",comm1[count+1].counts);
        printf("商品总价：");
        scanf("%lf",&comm1[count+1].total);
        fprintf(fp,"%lf\t\n",comm1[count+1].total);
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
     struct commodity comm2[50];
	const char *filename = COMMODITYINFO;
    int delnum,x,y=0,cho,rdel;
    int count=0;
    int i=0,j;
    FILE *fp;
	if((fp=fopen(filename,"r"))==NULL)			// 打开文件并且让fp指向 文件
	{
		printf("文件不存在。\n");
		system("pause");
		return Menu();
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm2[i].num,comm2[i].name,&comm2[i].price,&comm2[i].counts,&comm2[i].total))//读取一组数据后指针指向下一组数据，并且判断是否指向最后一行
	{
		i++;
		count=i;
	}
	repeat1:printf("请输入你想要删除的商品编号：\n");
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
			printf("您输入的商品编号不存在。\n");
			goto repeat1;
		}
	printf("您所要删除商品的信息：\t编号\t|名称\t|价格\t\t|数量\t\t|总价\n");
	printf("                      \t %d \t| %s \t| %lf\t| %lf\t| %lf\n",comm2[cho].num,comm2[cho].name,comm2[cho].price,comm2[cho].counts,comm2[cho].total);
	printf("确定要删除吗？(输入1为是，其他为否：)");
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
		printf("删除成功。\n");
		count--;

	}else
		printf("退出");
        printf("是否继续删除？输入1为是，其他为否");
		scanf("%d",&rdel);
		if(rdel==1)
        {
            if (count==0)
            {
                printf("无商品信息,返回主菜单\n");
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
	if((fp=fopen(filename,"r"))==NULL)			// 打开文件并且让fp指向 文件
	{
		printf("Can not open file\n");
		exit(1);
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm3[i].num,comm3[i].name,&comm3[i].price,&comm3[i].counts,&comm3[i].total))//读取一组数据后指针指向下一组数据，并且判断是否指向最后一行
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
    printf("共%d种商品  总数量%6.lf件  总价%6.lf元\n\n",sumnum,sumcounts,sumtotal);
    system("pause");
    return Menu();
}
void ModifyCommodityInfo()//没有输出到文件
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
            printf("请输入需要修改的商品的编号:");
        }
    scanf("%d",&mnum);
    for(i=0;i<j;i++)
    {
        if(mnum==comm4[i].num)
        {
            tnum=i;
            printf("下面是这个商品的信息:\n");
            printf(NAMEOUT);
            printf(FORMATOUT,comm4[i].num,comm4[i].name,comm4[i].price,comm4[i].counts,comm4[i].total);
reinput:printf("请选择需要修改的内容(1.name   2.price   3.count):");
            scanf("%d",&a);
                switch (a)
                {
                    case 1:
                        printf("请输入需要修改成的name:");
                        scanf("%s",comm4[i].name);
                        break;
                    case 2:
                        printf("请输入需要修改的price:");
                        scanf("%lf",&comm4[i].price);
                        break;
                    case 3:
                        printf("请输入需要修改的cout:");
                        scanf("%lf",&comm4[i].counts);
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
            printf("输入错误\n");
            break;
     }
   }
   else{
    printf("输入错误");
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

