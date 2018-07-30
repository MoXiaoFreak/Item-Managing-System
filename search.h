#include "head.h"
void Search()
    {
        struct commodity comm6[50];
    printf("商品列表:\n");
    Show();
    FILE *fp;
    int i=0,j,find_num,ch,b,m=0;
    int ch1,b1;
    char *find_name[20];
    const char *filename = COMMODITYINFO;
	if((fp=fopen(filename,"r+"))==NULL)
	{
		printf("文件不存在\n");
		exit(1);
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm6[i].num,comm6[i].name,&comm6[i].price,&comm6[i].counts,&comm6[i].total))
	{
		i++;
	}
	j=i;
	printf("请选择需要搜索的选项(1.编号 2.名称):");
	scanf("%d",&ch);
	if(ch==1||ch==2)
    {
            switch(ch)
            {
            case 1:
                printf("请输入查询数据:");
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
                        printf("该商品数据如下:\n");
                        printf(NAMEOUT);
                        printf(FORMATOUT,comm6[i].num,comm6[i].name,comm6[i].price,comm6[i].counts,comm6[i].total);
                    }else
                    {
                        printf("未查询到该商品....");
                    }
                break;
            case 2:
                printf("请选择查询方式(1.精确查找  2.关键字查找):");

                scanf("%d",&ch1);
                while(ch1==1||ch1==2)
                {
                    switch(ch1)
                    {
                    case 1:
                        printf("请输入查询数据:");
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
                                printf("该商品数据如下:\n");
                                printf(NAMEOUT);
                                printf(FORMATOUT,comm6[i].num,comm6[i].name,comm6[i].price,comm6[i].counts,comm6[i].total);
                            }else
                            {
                                printf("未查询到该商品....");
                            }
                        break;
                    case 2:
                        printf("请输入查询数据:");
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
                            printf("未查询到相关商品...(任意键返回查询菜单)");
                            getch();
                            system("cls");
                            return Search();
                        }else
                        {
                            printf("该商品数据如下:\n");
                            printf(NAMEOUT);
                            for(j=0;j<m;j++)
                            {
                                i=q[j];
                                printf(FORMATOUT,comm6[i].num,comm6[i].name,comm6[i].price,comm6[i].counts,comm6[i].total);

                            }
                        }
                        break;
                    default:
                        printf("请输入正确的选项\n");
                        break;

                    }
                    ch1=3;
                    ch=3;
                }
                break;
            default:
                printf("请输入正确的选项\n");
                break;
            }
            printf("输入任意键继续....\n");
            getch();
			printf("是否继续查询商品：输入'1'为是，其他为否:\n");
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
        printf("输入错误...");
        getch();
        Menu();
    }
}

