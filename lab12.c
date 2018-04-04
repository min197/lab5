#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
//FILE *fp;
/*void newfile(int n){
    int i;
    fp = fopen("newfileminh.txt", "w+");
    for(i=0;i<=n;i++)
    {
        fprintf(fp, "%s LF %d LF %d", "Du_Van_Minh", "89965095321", "28011997");
        //fclose(fp);
    }
    fclose(fp);
}*/
typedef struct student
{
    char name[50];
    int group;
    int ses[10];
};
struct student student[20];
FILE *bitfile;
FILE *fp;
void newtext(int n)
{
    int i,j;
    fp = fopen("structers.txt", "w+");
    for(i=1;i<=n;i++)
	{
		fprintf(fp,"%s \t %d \t",student[i].name, student[i].group);
        for(j=1;j<=5;j++)
        {
            fprintf (fp,"\t %d",student[i].ses[j]);
        }
        fprintf(fp,"\n");
	}
	fclose(fp);
}
void read(int n)
{
    int i,j;
    //n++;
    bitfile = fopen("structers_2.txt", "w+");
    for(i=1;i<=n;i++)
	{
		fprintf(fp,"%s \t %d \t",student[i].name, student[i].group);
        for(j=1;j<=5;j++)
        {
            fprintf (fp,"\t %d",student[i].ses[j]);
        }
        fprintf(fp,"\n");
	}
	fclose(fp);
    i=1;
    bitfile = fopen("structers_2_bit.txt", "wb");
    //fwrite(&n, sizeof(int),1,bitfile );
    while(i<=n)
    {
          fwrite(&student[i], sizeof(student),1,bitfile );
          i++;
    }

	fclose(bitfile);
}
void ques3(int n)
{
    int i, m, j;
    bitfile = fopen("structers_2.txt", "wb");
    fread(&n, sizeof(int), 1 , bitfile);
    printf("wriite the numbers of clumn : \n");
    scanf("%d",&m);
    if (m==1){
        while (i<=n){
            fread(&studen[i].name, sizeof(char[20]), 1, bitfile);
            fseek(&student[i].name, sizeof(char[20])+2L, SEEK_CUR);
            i++;
        }
        for(i=1; i<=n; i++)
        {
            printf("%s\n", student[i].name);
        }
    }
     if (m==2){
        fseek(bitfile, sizeof(char[20]) + sizeof(int), SEEK_SET);
        while (i<=n){
            fread(&studen[i].group, (long)sizeof(int), 1, bitfile);
            fseek(&student[i].group, (long)(sizeof(char[20]) + sizeof(char[10]) + 2L), SEEK_CUR);
            i++;
        }
        for(i=1; i<=n; i++)
        {
            printf("%s\n", student[i].group);
        }
    }
     if (m==3){
        fseek(bitfile, sizeof(char[20]) + sizeof(int), SEEK_SET);
        while (i<=n){
            fread(&studen[i].ses, sizeof(char[20]), 1, bitfile);
            fseek(&student[i].ses, (long)(sizeof(char[20]) + sizeof(int) + 2L), SEEK_CUR);
            i++;
        }
        for(i=1; i<=n; i++)
        {
            printf("%s\n", student[i].ses);
        }
    }
    if(m!=1 & m!=2 & m!=3) printf("ERROR!!!\n");
    fclose(bitfile);
}
void ques3(int n)
{
    int i, m;
    bitfile = fopen("structers_2.txt", "wb");
    fread(&n, sizeof(int), 1 , bitfile);
    printf("wriite the numbers of clumn : \n");
    scanf("%d",&m);
    if(m<=n){
		fseek(bitfile, (m-1)* sizeof(student)/*(sizeof(char[20]) + sizeof(int)+ sizeof(char[10])+2L)*/, SEEK_CUR);
		fread(student, (long)sizeof(student), 1, bitfile);
		//fread(&array[0].number, (long)sizeof(int), 1, bitfile);
		//fread(&array[0].brand, (long)sizeof(char[10]), 1, bitfile);
		printf("%s\t\t%d\t\t%d\n", student.name, student.group, student.ses);
		exit(1);

	} else printf("Error");

	fclose(bitfile);
}
void write(int n)
{
    int i, m=3,j;
    char s;
    for(i=1; i<=n; i++)
    {
        printf("name student[%d] : \n",i);
        scanf("%s", &student[i].name);

        printf("the number of group : \n");
        scanf("%d",&student[i].group);

        for( j = 1; j<=5; j++)
        {
            printf("the point [%d] : \n",j);
            scanf("%d",&student[i].ses[j]);
        }
    }
}

void show2(int n)
{
	struct student t;
	int i,j,sum=0;
	double tb[20];
	for(i=1;i<=n;i++)
	{
		//sum=0;
		for(j=1;j<=5;j++)
		{
		    //printf("%d\n",student[i].ses[j]);
			sum+=student[i].ses[j];
		}
		printf("sum = %d\n",sum);
		tb[i]=sum/5.0;
        printf("tb = %0.2lf \n",tb[i]);
        sum=0;
	}

	for(i=1;i<=n;i++)
	{
	    /*if(tb[i]<4) printf("the student %s is low\n",student[i].name);
	    else{*/
		for(j=i+1;j<=n;j++)
		{
			if(tb[i]>=tb[j])
			{
                t=student[i];
                student[i]=student[j];
                student[j]=t;
			}
		}
	}
	printf("there are students have the high point: \n");
	printf("name of student \t number of group \n");
	for(i=1;i<=n;i++)
	{
		printf("%10s \t \t \t %d \n",student[i].name, student[i].group);

	}

}

int main()
{
    int n;
    printf("how many student : \n");
    scanf("%d",&n);
    write(n);
    //show1(n);
    show2(n);
    newtext(n);
    read(n);
    return 0;
}
