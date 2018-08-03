#include "head.h"
void AddCommodityInfo()
{
    struct commodity comm1[50];
  const char *filename = COMMODITYINFO;
  int count=0;
    int b=1;
    int i,n;
    FILE *fp;
	repeat1:
    while(b==1)
	{
	    if((fp=fopen(filename,"r+"))==NULL)
	{
	    FILE *fp=fopen(filename,"w+");
		printf("文件不存在，已新建该文件。\n");
		getch();
		return Menu();
	}
	 i=0;
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm1[i].num,comm1[i].name,&comm1[i].price,&comm1[i].counts,&comm1[i].total))
	{
		i++;
		count=i;
	}
	   number: system("cls");
	    Show();
        printf("请输入添加商品的信息：\n");
        printf("商品编号：");
        if( n=scanf("%d",&comm1[count+1].num)==0)
            {
        		printf("商品编号不符合要求，请重新输入。\n");
        		fflush(stdin);
        		getch();
				goto number;
			}
        for(i=0;i<count+1;i++)
        {
        	if(comm1[i].num==comm1[count+1].num)
        	{
        	    fclose(fp);
        	    system("cls");
                Show();
        		printf("商品编号已存在，请重新输入。\n");
        		getch();
        		goto repeat1;
        	}
        }
        printf("商品名称：");
        scanf("%s",comm1[count+1].name);
        for(i=0;i<count+1;i++)
        {
        	if(strcmp(comm1[i].name,comm1[count+1].name)==0)
        	{
        	     fclose(fp);
        	    system("cls");
                Show();
        		printf("商品名称已经存在，请重新输入。\n");
        		getch();
        		goto repeat1;
        	}
        }
        fprintf(fp,"%d\t",comm1[count+1].num);
        fprintf(fp,"%s\t",comm1[count+1].name);
        printf("商品价格：");
        scanf("%lf",&comm1[count+1].price);
        fprintf(fp,"%lf\t",comm1[count+1].price);
        printf("商品库存：");
        scanf("%lf",&comm1[count+1].counts);
        fprintf(fp,"%lf\t",comm1[count+1].counts);
        fprintf(fp,"%lf\t\n",comm1[count+1].counts*comm1[count+1].price);
         fclose(fp);
        count=count+1;
        system("cls");
        printf("录入成功！\n");
        getch();
        system("cls");
        Show();
        printf("是否继续录入商品：输入'1'为是，其他为否:\n");
//        fflush(stdin);
        scanf("%d",&b);
        if(b!=1)
                break;
    }
 return Menu();
}
void DelCommodityInfo()
{
     struct commodity comm2[50];
	const char *filename = COMMODITYINFO;
    int delnum,x,y=0,cho,rdel;
    int count=0;
    int i,j,n;
    FILE *fp;
	repeatc: if((fp=fopen(filename,"r+"))==NULL)			// 打开文件并且让fp指向 文件
	{
		printf("文件不存在。\n");
		getch();
		return Menu();
	}
	i=0;
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm2[i].num,comm2[i].name,&comm2[i].price,&comm2[i].counts,&comm2[i].total))//读取一组数据后指针指向下一组数据，并且判断是否指向最后一行
	{
		i++;
		count=i;
	}
        fclose(fp);
       repeatdel: system("cls");
        Show();
       printf("请输入你想要删除的商品编号：\n");
        if(n=scanf("%d",&delnum)<1)
        {
            printf("输入错误");
            fflush(stdin);
            getch();
            goto repeatdel;
        }
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
			goto repeatc;
		}
    system("cls");
    Show();
	printf("您所要删除商品的信息：\n\t编号\t|名称\t|价格\t\t|数量\t\t|总价\n");
	printf("\t %d \t| %s \t| %lf\t| %lf\t| %lf\n",comm2[cho].num,comm2[cho].name,comm2[cho].price,comm2[cho].counts,comm2[cho].total);
	printf("确定要删除吗？(输入1为是，其他为否：)\n");
	scanf("%d",&x);
	if(x==1)
	{
		for(j=cho;j<count-1;j++)
		{
			comm2[j]=comm2[j+1];
			fclose(fp);
		}
		fp=fopen(filename,"w+");
		for(j=0;j<count-1;j++)
		{
			fprintf(fp,"%d\t%s\t%lf\t%lf\t%lf\t\n",comm2[j].num,comm2[j].name,comm2[j].price,comm2[j].counts,comm2[j].total);
		}
		printf("删除成功。\n");
		count--;
	}else
	{
	     printf("退出");
	     getch();
	     fclose(fp);
	     return Menu();
	}
        fclose(fp);
        system("cls");
        Show();
        printf("是否继续删除？输入1为是，其他为否");
		scanf("%d",&rdel);
		if(rdel==1)
        {
            if (count==0)
            {
                printf("无商品信息,返回主菜单\n");
                getch();
                return Menu();
            }
            else goto repeatc;
        }
        else
        {
            fclose(fp);
            return Menu();
        }
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
    printf("共%d种商品  总数量%15.lf件  总价%15.lf元\n\n",sumnum,sumcounts,sumtotal);
    system("pause");
    return Menu();
}
void ModifyCommodityInfo()
{
    struct commodity comm8[50];
    FILE *fp;
    FILE *fp1;
    int i=0,j,mnum,a,tnum,m,k,n;
    const char *filename = COMMODITYINFO;
	if((fp=fopen(filename,"r+"))==NULL)
	{
		printf("Can not open file\n");
		exit(1);
	}

	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm8[i].num,comm8[i].name,&comm8[i].price,&comm8[i].counts,&comm8[i].total))
	{
		i++;
	}
    close(fp);
	j=i;
	if(i==0)
    {
        printf("There is no record in the file.");
    }else
        {
      repeatmodify:       system("cls");
            Show();
            fclose(fp);
            printf("请输入需要修改的商品的编号:");
        }
     if(n=scanf("%d",&mnum)<1)
        {
            printf("输入错误");
            fflush(stdin);
            getch();
            goto repeatmodify;
        }
    for(i=0;i<j;i++)
    {
        if(mnum==comm8[i].num)
        {
            tnum=i;
            printf("下面是这个商品的信息:\n");
            printf(NAMEOUT);
            printf(FORMATOUT,comm8[i].num,comm8[i].name,comm8[i].price,comm8[i].counts,comm8[i].total);
            printf("请选择需要修改的内容(1.name   2.price   3.count):");
            scanf("%d",&a);
            while (a)
            {
                switch (a)
                {
                    case 1:
                        printf("请输入需要修改成的name:");
                       name: scanf("%s",comm8[i].name);
                        for(k=0;k<j;k++)
                        {
                            if(i!=k&&strcmp(comm8[i].name,comm8[k].name)==0)
                            {
                                printf("名称重复！重新输入:\n");
                                getch();
                                goto name;
                            }
                        }
                        break;
                    case 2:
                        printf("请输入需要修改的price:");
                        scanf("%lf",&comm8[i].price);
                        break;
                    case 3:
                        printf("请输入需要修改的count:");
                        scanf("%lf",&comm8[i].counts);
                        break;
                    default:
                        printf("请输入正确的数字....\n");
                        printf("输入任意键返回修改菜单....\n");
                        getch();
                        return ModifyCommodityInfo();
                }
                fp1=fopen(COMMODITYINFO,"r+");
                for(m=0;m<j;m++)
                {
                    comm8[m].total=comm8[m].price*comm8[m].counts;
                    fprintf(fp1,"%d\t%s\t%lf\t%lf\t%lf\t\n",comm8[m].num,comm8[m].name,comm8[m].price,comm8[m].counts,comm8[m].total);
                }
                fclose(fp1);
                system("cls");
                Show();
                printf("修改成功.....\n");
                printf("输入任意键继续....\n");
                getch();
                return Menu();
            }
        }
      }
}
void InsertCommodityInfo()
{

    struct commodity comm9;
    struct commodity comma[50];
    const char *filename = COMMODITYINFO;
    int count=0;
    char a='1',b;
    int i=0,y=0,cho=0,k,j,n;
    int insert_num=0,qianhou=0;
    FILE *fp;

	if((fp=fopen(filename,"r+"))==NULL)			// 打开文件并且让fp指向 文件
	{
	    FILE *fp=fopen(filename,"w+");
		printf("文件不存在，已新建该文件。\n");
		fclose(fp);
		getch();
		return Menu();
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comma[i].num,comma[i].name,&comma[i].price,&comma[i].counts,&comma[i].total))//读取一组数据后指针指向下一组数据，并且判断是否指向最后一行
	{
		i++;
		count=i;
	}
    for(k=0;k<count-1;k++){
                for(j=0;j<count-1-k;j++){
                    if(comma[j].num>comma[j+1].num){
                                int a=comma[j+1].num;
                                comma[j+1].num=comma[j].num;
                                comma[j].num=a;
                                double b=comma[j+1].price;
                                comma[j+1].price=comma[j].price;
                                comma[j].price=b;
                                double c=comma[j+1].counts;
                                comma[j+1].counts=comma[j].counts;
                                comma[j].counts=c;
                                double d=comma[j+1].total;
                                comma[j+1].total=comma[j].total;
                                comma[j].total=d;
                                char s[15];
                                strcpy(s, comma[j+1].name);
                                strcpy(comma[j+1].name,comma[j].name);
                                strcpy(comma[j].name,s);
                    }
                }
            }
   fp=fopen(filename,"w+");
   for(j=0;j<count;j++){
     fprintf(fp,"%d\t",comma[j].num);
     fprintf(fp,"%s\t",comma[j].name);
     fprintf(fp,"%lf\t",comma[j].price);
     fprintf(fp,"%lf\t",comma[j].counts);
     fprintf(fp,"%lf\t\n",comma[j].total);
   }
   fclose(fp);
   while(a=='1'){

    system("cls");

    SetPosition(getx,gety);
    printf("+---------------------欢迎进入插入功能--------------------+");

    SetPosition(getx,gety+1);
    printf("退出请输入0，任意键继续\n");
    fflush(stdin);
    scanf("%c",&b);
    if(b=='0'){
    return Menu();
    }
    n=Show();
    if(n==0){
    printf("文件为空，请返回menu添加");
    getch();
    return Menu();
    }
   struct commodity comm9;
   repeat4: printf("请输入在几号商品处插入:");

        n=scanf("%d",&insert_num);
        if(n==0)
            {
        		printf("商品编号不符合要求，请重新输入。\n");
				goto repeat4;
			}
		for(i=0;i<count;i++)
		{
			if(insert_num==comma[i].num)
				{
					y=1;
					cho=i;
				}
		}
		if(y!=1)
		{
			printf("您输入的商品编号不存在。");
			goto repeat4;
		}

  repeatx: printf("请输入在该商品前或后插入\n1：前\n2：后\n");
    scanf("%d",&qianhou);
    if(qianhou==1){
        for(i=count+1;i>cho;i--){
          comma[i]=comma[i-1];
          comma[i].num=comma[i].num+1;
        }

        comma[cho].num=insert_num;
        repeatz:printf("商品名称：");
          scanf("%s",comm9.name);
          for(i=0;i<count+1;i++)
          {
        	  if(strcmp(comma[i].name,comm9.name)==0)
        	  {
        		  printf("商品名称已经存在，请重新输入。\n");
        		  goto repeatz;
        	  }
          }
        strcpy(comma[cho].name,comm9.name);
        repeat5: printf("商品价格：");
        fflush(stdin);
        n=scanf("%lf",&comma[cho].price);
        if(n==0)
            {
        		printf("商品价格不符合要求，请重新输入。\n");
				goto repeat5;
			}
        repeat6: printf("商品库存：");
        fflush(stdin);
        n=scanf("%lf",&comma[cho].counts);
        if(n==0)
            {
        		printf("商品库存不符合要求，请重新输入。\n");
				goto repeat6;
			}

        comma[cho].total=comma[cho].price*comma[cho].counts;
        printf("插入成功！\n");
        count++;
    }
    else if(qianhou==2){
        for(i=count+1;i>cho+1;i--){
          comma[i]=comma[i-1];
          comma[i].num=comma[i].num+1;
        }

        comma[cho+1].num=insert_num+1;
    repeaty:printf("商品名称：");
          scanf("%s",comm9.name);
          for(i=0;i<count+1;i++)
          {
        	  if(strcmp(comma[i].name,comm9.name)==0)
        	  {
        		  printf("商品名称已经存在，请重新输入。\n");
        		  goto repeaty;
        	  }
          }
        strcpy(comma[cho+1].name,comm9.name);

        repeat7: printf("商品价格：");
        fflush(stdin);
        n=scanf("%lf",&comma[cho+1].price);
        if(n==0)
            {
        		printf("商品价格不符合要求，请重新输入。\n");
        		fflush(stdin);
				goto repeat7;
			}

        repeat8: printf("商品库存：");
        fflush(stdin);
        n=scanf("%lf",&comma[cho+1].counts);
        if(n==0)
            {
        		printf("商品库存不符合要求，请重新输入。\n");
        		fflush(stdin);
        		getch();
				goto repeat8;
			}

        comma[cho+1].total=comma[cho+1].price*comma[cho+1].counts;
        printf("插入成功！\n");
        count++;
    }
    else{
       printf("输入错误，重新输入\n") ;
       goto repeatx;
    }
   fp=fopen(filename,"w+");
   for(j=0;j<count;j++){
     fprintf(fp,"%d\t",comma[j].num);
     fprintf(fp,"%s\t",comma[j].name);
     fprintf(fp,"%lf\t",comma[j].price);
     fprintf(fp,"%lf\t",comma[j].counts);
     fprintf(fp,"%lf\t\n",comma[j].total);
   }
   fclose(fp);
   system("cls");
   Show();
   fflush(stdin);
   printf("继续插入请输入“1”,任意键返回menu:\n");
   scanf("%c",&a);
 }
 return Menu();
}

void OrderCommodityInfo()
{
    struct commodity comm5[50];
    system("cls");
    const char *filename = COMMODITYINFO;
    char a='1';
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
	 fclose(fp);
    while(a=='1')
    {
    system("cls");
    char b;
    SetPosition(getx,gety);
    printf("+---------------------欢迎进入排序功能--------------------+");

    SetPosition(getx,gety+1);
    printf("退出请输入0，任意键继续\n");
    fflush(stdin);
    scanf("%c",&b);
    if(b=='0'){
    return Menu();
    }
    Show();
    printf("排序依据:\n");
	printf("1.按序号\n");
	printf("2.按单价\n");
	printf("3.按数量\n");
	printf("4.按总价\n");
	printf("5.返回menu\n");
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
   for(j=0;j<count;j++)
    {
     fprintf(fp,"%d\t",comm5[j].num);
     fprintf(fp,"%s\t",comm5[j].name);
     fprintf(fp,"%lf\t",comm5[j].price);
     fprintf(fp,"%lf\t",comm5[j].counts);
     fprintf(fp,"%lf\t\n",comm5[j].total);
   }
   fclose(fp);
   Show();
   fflush(stdin);
   printf("继续排序请输入“1”,任意键返回menu:\n");
   scanf("%c",&a);
 }
 return Menu();
}
int Show()
{
system("cls");
            SetPosition(5,3);
              struct commodity comm7[50];
            FILE *fp;
            int i=0,j=3;
            fp=fopen(COMMODITYINFO,"r+");
            while(~fscanf(fp,"%d%s%lf%lf%lf",&comm7[i].num,comm7[i].name,&comm7[i].price,&comm7[i].counts,&comm7[i].total))
            {
                i++;
            }
            j=i;
            DrawTable(j,5);
            rewind(fp);

            if(i==0)
            {
                SetPosition(10,15);
                printf("There is no record in the file.");
                return 0;
            }else
                {
                    SetPosition(7,3);
                    printf(NAMEOUT);

                    for(i=0;i<j;i++)
                    {
                        printf("\n");
                        SetPosition(7,2*i+5);
                        printf(FORMATOUT,comm7[i].num,comm7[i].name,comm7[i].price,comm7[i].counts,comm7[i].total);
                    }
                }
            fclose(fp);
            printf("\n\n");
            return 1;
}

