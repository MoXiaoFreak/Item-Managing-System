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
		printf("�ļ������ڣ����½����ļ���\n");
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
        printf("�����������Ʒ����Ϣ��\n");
        printf("��Ʒ��ţ�");
        if( n=scanf("%d",&comm1[count+1].num)==0)
            {
        		printf("��Ʒ��Ų�����Ҫ�����������롣\n");
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
        		printf("��Ʒ����Ѵ��ڣ����������롣\n");
        		getch();
        		goto repeat1;
        	}
        }
        printf("��Ʒ���ƣ�");
        scanf("%s",comm1[count+1].name);
        for(i=0;i<count+1;i++)
        {
        	if(strcmp(comm1[i].name,comm1[count+1].name)==0)
        	{
        	     fclose(fp);
        	    system("cls");
                Show();
        		printf("��Ʒ�����Ѿ����ڣ����������롣\n");
        		getch();
        		goto repeat1;
        	}
        }
        fprintf(fp,"%d\t",comm1[count+1].num);
        fprintf(fp,"%s\t",comm1[count+1].name);
        printf("��Ʒ�۸�");
        scanf("%lf",&comm1[count+1].price);
        fprintf(fp,"%lf\t",comm1[count+1].price);
        printf("��Ʒ��棺");
        scanf("%lf",&comm1[count+1].counts);
        fprintf(fp,"%lf\t",comm1[count+1].counts);
        fprintf(fp,"%lf\t\n",comm1[count+1].counts*comm1[count+1].price);
         fclose(fp);
        count=count+1;
        system("cls");
        printf("¼��ɹ���\n");
        getch();
        system("cls");
        Show();
        printf("�Ƿ����¼����Ʒ������'1'Ϊ�ǣ�����Ϊ��:\n");
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
	repeatc: if((fp=fopen(filename,"r+"))==NULL)			// ���ļ�������fpָ�� �ļ�
	{
		printf("�ļ������ڡ�\n");
		getch();
		return Menu();
	}
	i=0;
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comm2[i].num,comm2[i].name,&comm2[i].price,&comm2[i].counts,&comm2[i].total))//��ȡһ�����ݺ�ָ��ָ����һ�����ݣ������ж��Ƿ�ָ�����һ��
	{
		i++;
		count=i;
	}
        fclose(fp);
       repeatdel: system("cls");
        Show();
       printf("����������Ҫɾ������Ʒ��ţ�\n");
        if(n=scanf("%d",&delnum)<1)
        {
            printf("�������");
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
			printf("���������Ʒ��Ų����ڡ�\n");
			goto repeatc;
		}
    system("cls");
    Show();
	printf("����Ҫɾ����Ʒ����Ϣ��\n\t���\t|����\t|�۸�\t\t|����\t\t|�ܼ�\n");
	printf("\t %d \t| %s \t| %lf\t| %lf\t| %lf\n",comm2[cho].num,comm2[cho].name,comm2[cho].price,comm2[cho].counts,comm2[cho].total);
	printf("ȷ��Ҫɾ����(����1Ϊ�ǣ�����Ϊ��)\n");
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
		printf("ɾ���ɹ���\n");
		count--;
	}else
	{
	     printf("�˳�");
	     getch();
	     fclose(fp);
	     return Menu();
	}
        fclose(fp);
        system("cls");
        Show();
        printf("�Ƿ����ɾ��������1Ϊ�ǣ�����Ϊ��");
		scanf("%d",&rdel);
		if(rdel==1)
        {
            if (count==0)
            {
                printf("����Ʒ��Ϣ,�������˵�\n");
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
    printf("��%d����Ʒ  ������%15.lf��  �ܼ�%15.lfԪ\n\n",sumnum,sumcounts,sumtotal);
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
            printf("��������Ҫ�޸ĵ���Ʒ�ı��:");
        }
     if(n=scanf("%d",&mnum)<1)
        {
            printf("�������");
            fflush(stdin);
            getch();
            goto repeatmodify;
        }
    for(i=0;i<j;i++)
    {
        if(mnum==comm8[i].num)
        {
            tnum=i;
            printf("�����������Ʒ����Ϣ:\n");
            printf(NAMEOUT);
            printf(FORMATOUT,comm8[i].num,comm8[i].name,comm8[i].price,comm8[i].counts,comm8[i].total);
            printf("��ѡ����Ҫ�޸ĵ�����(1.name   2.price   3.count):");
            scanf("%d",&a);
            while (a)
            {
                switch (a)
                {
                    case 1:
                        printf("��������Ҫ�޸ĳɵ�name:");
                       name: scanf("%s",comm8[i].name);
                        for(k=0;k<j;k++)
                        {
                            if(i!=k&&strcmp(comm8[i].name,comm8[k].name)==0)
                            {
                                printf("�����ظ�����������:\n");
                                getch();
                                goto name;
                            }
                        }
                        break;
                    case 2:
                        printf("��������Ҫ�޸ĵ�price:");
                        scanf("%lf",&comm8[i].price);
                        break;
                    case 3:
                        printf("��������Ҫ�޸ĵ�count:");
                        scanf("%lf",&comm8[i].counts);
                        break;
                    default:
                        printf("��������ȷ������....\n");
                        printf("��������������޸Ĳ˵�....\n");
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
                printf("�޸ĳɹ�.....\n");
                printf("�������������....\n");
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

	if((fp=fopen(filename,"r+"))==NULL)			// ���ļ�������fpָ�� �ļ�
	{
	    FILE *fp=fopen(filename,"w+");
		printf("�ļ������ڣ����½����ļ���\n");
		fclose(fp);
		getch();
		return Menu();
	}
	while(~fscanf(fp,"%d%s%lf%lf%lf",&comma[i].num,comma[i].name,&comma[i].price,&comma[i].counts,&comma[i].total))//��ȡһ�����ݺ�ָ��ָ����һ�����ݣ������ж��Ƿ�ָ�����һ��
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
    printf("+---------------------��ӭ������빦��--------------------+");

    SetPosition(getx,gety+1);
    printf("�˳�������0�����������\n");
    fflush(stdin);
    scanf("%c",&b);
    if(b=='0'){
    return Menu();
    }
    n=Show();
    if(n==0){
    printf("�ļ�Ϊ�գ��뷵��menu���");
    getch();
    return Menu();
    }
   struct commodity comm9;
   repeat4: printf("�������ڼ�����Ʒ������:");

        n=scanf("%d",&insert_num);
        if(n==0)
            {
        		printf("��Ʒ��Ų�����Ҫ�����������롣\n");
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
			printf("���������Ʒ��Ų����ڡ�");
			goto repeat4;
		}

  repeatx: printf("�������ڸ���Ʒǰ������\n1��ǰ\n2����\n");
    scanf("%d",&qianhou);
    if(qianhou==1){
        for(i=count+1;i>cho;i--){
          comma[i]=comma[i-1];
          comma[i].num=comma[i].num+1;
        }

        comma[cho].num=insert_num;
        repeatz:printf("��Ʒ���ƣ�");
          scanf("%s",comm9.name);
          for(i=0;i<count+1;i++)
          {
        	  if(strcmp(comma[i].name,comm9.name)==0)
        	  {
        		  printf("��Ʒ�����Ѿ����ڣ����������롣\n");
        		  goto repeatz;
        	  }
          }
        strcpy(comma[cho].name,comm9.name);
        repeat5: printf("��Ʒ�۸�");
        fflush(stdin);
        n=scanf("%lf",&comma[cho].price);
        if(n==0)
            {
        		printf("��Ʒ�۸񲻷���Ҫ�����������롣\n");
				goto repeat5;
			}
        repeat6: printf("��Ʒ��棺");
        fflush(stdin);
        n=scanf("%lf",&comma[cho].counts);
        if(n==0)
            {
        		printf("��Ʒ��治����Ҫ�����������롣\n");
				goto repeat6;
			}

        comma[cho].total=comma[cho].price*comma[cho].counts;
        printf("����ɹ���\n");
        count++;
    }
    else if(qianhou==2){
        for(i=count+1;i>cho+1;i--){
          comma[i]=comma[i-1];
          comma[i].num=comma[i].num+1;
        }

        comma[cho+1].num=insert_num+1;
    repeaty:printf("��Ʒ���ƣ�");
          scanf("%s",comm9.name);
          for(i=0;i<count+1;i++)
          {
        	  if(strcmp(comma[i].name,comm9.name)==0)
        	  {
        		  printf("��Ʒ�����Ѿ����ڣ����������롣\n");
        		  goto repeaty;
        	  }
          }
        strcpy(comma[cho+1].name,comm9.name);

        repeat7: printf("��Ʒ�۸�");
        fflush(stdin);
        n=scanf("%lf",&comma[cho+1].price);
        if(n==0)
            {
        		printf("��Ʒ�۸񲻷���Ҫ�����������롣\n");
        		fflush(stdin);
				goto repeat7;
			}

        repeat8: printf("��Ʒ��棺");
        fflush(stdin);
        n=scanf("%lf",&comma[cho+1].counts);
        if(n==0)
            {
        		printf("��Ʒ��治����Ҫ�����������롣\n");
        		fflush(stdin);
        		getch();
				goto repeat8;
			}

        comma[cho+1].total=comma[cho+1].price*comma[cho+1].counts;
        printf("����ɹ���\n");
        count++;
    }
    else{
       printf("���������������\n") ;
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
   printf("�������������롰1��,���������menu:\n");
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
    printf("+---------------------��ӭ����������--------------------+");

    SetPosition(getx,gety+1);
    printf("�˳�������0�����������\n");
    fflush(stdin);
    scanf("%c",&b);
    if(b=='0'){
    return Menu();
    }
    Show();
    printf("��������:\n");
	printf("1.�����\n");
	printf("2.������\n");
	printf("3.������\n");
	printf("4.���ܼ�\n");
	printf("5.����menu\n");
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
   printf("�������������롰1��,���������menu:\n");
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

