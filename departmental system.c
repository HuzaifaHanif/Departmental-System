#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct users
{
	char user_name[30];
	char password[6];

};

struct product
{
  int id,quantity;
  char name[10];
  float price,rprice; 
};

struct customer
{
	char name[10];
	float total;
};

struct sale
{
	char name[10];
	float sum_p,sum_r;
};

struct supplier
{
	char name[20],date[10];
	float price;
	int s_num,p_id,quantity;
};

signup(struct users *a)
{
 	FILE *p;
 	char ch;
 	int i;
 	int z,flag=0;
 	struct users b;
 	
 	p=fopen("login.txt","r");
 	
	if(p==NULL)
	{
	 	printf("\n\n/t/tERROR! file of account not found\n\n");
 		exit(1);
 	}
 	
 	printf("\nEnter Username: ");
 	fflush(stdin);
 	gets(a->user_name);
 	printf("Enter 5 digit Password: ");
 	
 	for (i=0;i<5;i++)
 	{
 		ch=getch();
 		a->password[i]=ch;
 		printf("*");
 		
	}
	
	for ( ;!feof(p); )
 	{
		fscanf(p,"username: %s Password: %s\n",&b.user_name,&b.password);

		if(strcmp(a->user_name,b.user_name)==0)
		{
			flag=1;
			printf("\n\n\t\tPlease change user name!!!! ALREADY PRESENT!!\n\n");
			signup(a);
		}
	}
 	
 	if(flag==0)
	{
 		fclose(p);
 		
 		p=fopen("login.txt","a");
	    fprintf(p,"username: %s Password: %s\n",a->user_name,a->password);
		printf("\n\n\t\tsignup successfull!!!!!\n\n");
	 	fclose(p);
	 	
	 	exit(1);
	}
 }
 
signin( int i )
{
 	struct users b;
 	struct users a;
 	FILE *ptr;
 	char ch;
 	int j;
 	
 	ptr=fopen("login.txt","r");
 	
 	if(ptr==NULL)
	{
	 	printf("\n\n/t/tERROR! file of account not found\n\n");
 		exit(1);
 	}
 	
 	printf("\nEnter Username: ");
 	fflush(stdin);
 	gets(a.user_name);
 	
 	printf("Enter 5 digit Password: ");
 	for (j=0;j<5;j++)
 	{
 		ch=getch();
 		a.password[j]=ch;
 		printf("*");	
	}
 	
 	for ( ;!feof(ptr); )
 	{
	    fscanf(ptr,"username: %s Password: %s\n",b.user_name,b.password);
	    
	    if( strcmp(a.user_name,b.user_name)==0 && strcmp(a.password,b.password)==0 )
	    {
	   		return ;	
	    }
	}
	
	fclose(ptr);
	printf("\n\n\t\t Incorrect Username Or Password!!!\n\n");
	
	if(i==5)
	{
		printf("\nYou have entered wrong password 5 times!!!!! \n\n\n");
		exit(1);
	}
	
	i++;
	signin(i);	 
	 
}
 
single_product(struct product *p)
{
	FILE *file;
	int i,x,flag=0,choice;
	
	file=fopen("project.txt","r");
	if(file==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}

	printf("\nPlease input the product ID : ");
	scanf("%d",&x);
	
	for(;!feof(file);)
	{		
		fscanf(file,"id : %d name : %s price : %f retail price : %f quantity : %d \n",&(p+i)->id,&(p+i)->name,&(p+i)->price,&(p+i)->rprice,&(p+i)->quantity);
		if((p+i)->id==x)
		{
			flag=1;
			printf("\nid : %d \nname : %s \nprice : %f \nretail price : %f \nquantity : %d \n\n",(p+i)->id,(p+i)->name,(p+i)->price,(p+i)->rprice,(p+i)->quantity);
	        break;
		}
    }
	    
	fclose(file);
	
	if(flag==0)
	{
		printf("\n\n\tNO!! product found of this ID!!!!\n\n");
	}
	    	
	printf("\n\nenter 1 to return back: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		system("cls");
	}	
}

all_products(struct product *p)
{
 	FILE *file;
	int i,x,a;
	
	file=fopen("project.txt","r");
	if(file==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}
	
	for(;!feof(file);)
	{		
		fscanf(file,"id : %d name : %s price : %f retail price : %f quantity : %d \n",&(p+i)->id,&(p+i)->name,&(p+i)->price,&(p+i)->rprice,&(p+i)->quantity);
		printf("\nid : %d \nname : %s \nprice : %f \nretail price : %f \nquantity : %d \n",(p+i)->id,(p+i)->name,(p+i)->price,(p+i)->rprice,(p+i)->quantity);
    }
	fclose(file);	
	
	printf("\n\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    }
 }
 
disp(struct product *p)
{

 	FILE *file;
	int i,x,a;
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n");
	file=fopen("project.txt","r");
	if(file==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}
	printf("\t\t\t\t|PRODUCTS|\n");
	for(;!feof(file);)
	{		
		fscanf(file,"id : %d name : %s price : %f retail price : %f quantity : %d \n",&(p+i)->id,&(p+i)->name,&(p+i)->price,&(p+i)->rprice,&(p+i)->quantity);
		printf("\n\tid : %d\tname : %s\tprice : %f",(p+i)->id,(p+i)->name,(p+i)->price);
    }
    printf("\n");
	fclose(file);	
	    
 }
 
new_product(struct product *p)
{
 	FILE *file;
	int i,x,a;
	
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n");
	
	file=fopen("project.txt","a");
	if(file==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}
 	printf("how many products do you want to input: ");
 	scanf("%d",&x);
 	printf("\n\n");
 	
 	for(i=0;i<x;i++)
	{	
		printf("ID : ");
		scanf("%d",&p[i].id);
		printf("name : ");
		scanf("%s",&p[i].name);
		printf("price : ");
		scanf("%f",&p[i].price);
		printf("retail price : ");
		scanf("%f",&p[i].rprice);
		printf("quantity : ");
		scanf("%d",&p[i].quantity);
		printf("\n\n\tProduct added successfully !\n\n");
		
		fprintf(file,"id : %d name : %s price : %f retail price : %f quantity : %d \n",p[i].id,p[i].name,p[i].price,p[i].rprice,p[i].quantity);
    }
    
 	fclose(file);
 	    
	printf("\n\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    }
 }
 
all_sales(struct sale *s)
{
	FILE *file1;
	struct customer c;
	int i,a;
	
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n");
	
	file1=fopen("sales.txt","r");
	if(file1==NULL)
	{
		printf("ERROR file of sales not found");
		exit(1);
	}
 	for(i=0;!feof(file1);i++)
	{
		fscanf(file1,"customer name :%s\nsale is %f \nand sum of retail price is %f\n",&c.name,&(s+i)->sum_p,&(s+i)->sum_r); 
 	    printf("customer name :%s\nsale is %f \nand sum of retail price is %f\n\n",c.name,(s+i)->sum_p,(s+i)->sum_r); 
 	}
 	
	fclose(file1);	 
	
	printf("\n\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    }   
 }
 
profit_loss(struct sale *s)
{
 	FILE *file1;
	struct customer c;
	int i,a;
	float total,total_1;
	
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n");
		
	file1=fopen("sales.txt","r");
	if(file1==NULL)
	{
		printf("ERROR file of sales not found");
		exit(1);
	}
	for(i=0;!feof(file1);i++)
	{
		fscanf(file1,"customer name :%s\nsale is %f \nand sum of retail price is %f\n",&c.name,&(s+i)->sum_p,&(s+i)->sum_r); 
		total=total+(s+i)->sum_p;
		total_1=total_1+(s+i)->sum_r;
	}
 	
 	if(total>total_1)
 	{
 		printf("\n\n\tCONGRATULATIONS! YOU ARE IN < PROFIT >\n\n");
 		printf("Total amount of all sales :%f\n",total);
 		printf("Total amount of retail price of all sales :%f\n\n",total_1);
	}
	
	else
	{
		printf("\n\n\tSORRY! YOU ARE IN < LOSS >\n\n");
 		printf("Total amount of all sales :%f\n",total);
 		printf("Total amount of retail price of all sales :%f\n\n",total_1);
	}
	
	printf("\n\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    }  
 }
 
marketing(struct product *p)
{
 	FILE *file;
 	FILE *file1;
 	FILE *file2;
	int i,x,choice,q,a,flag;
	float sum_p=0,sum_r=0;
	char name[10];
	
	struct customer c;
	struct sale s;
	
	file=fopen("project.txt","r");
	if(file==NULL)
	{
		printf("ERROR file of products not found");
		exit(1);
	}
	
    printf("\nEnter customer name :");
    scanf("%s",&c.name);
	    
	for(i=0;;i++)
	{		flag=0;
		printf("\nPlease input the product ID : ");
	    scanf("%d",&x);	
		fseek(file,0,SEEK_SET);
		
		for(i=0;!feof(file);i++)
		{	
		    fscanf(file,"id : %d name : %s price : %f retail price : %f quantity : %d \n",&(p+i)->id,&(p+i)->name,&(p+i)->price,&(p+i)->rprice,&(p+i)->quantity);
		    
			if((p+i)->id==x)
		    {
		    	flag=01;
				file1=fopen("sales.txt","a");
				if(file1==NULL)
				{
					printf("ERROR file of sales not found");
					exit(1);
				}
		        file2=fopen("customer.txt","a");
				if(file2==NULL)
				{
					printf("ERROR file of customer not found");
					exit(1);
				}
		        printf("how much quantity :");
		        scanf("%d",&q);
		        
				s.sum_p=s.sum_p+((p+i)->price*q);
		        s.sum_r=s.sum_r+((p+i)->rprice*q);   
				c.total=s.sum_p; 
		
			     break;
		    }
		    
		}
		if(flag==0)
		{
			printf("\nProduct not found\n");
		}
		printf("\n\nEnter 1 to exit :");
		scanf("%d",&choice);		  
		if(choice==1)
	    {
	    	break;
		}  
	}
    if(s.sum_p<4000)
    {
    	printf("\n\n\t\tTHE BILL IS\n\n");
    	printf("name :%s\n",c.name);
    	printf("total amount :%f",c.total);
    	printf("\n-------------------------------------------\n");
	}
    
    if( s.sum_p>=4000 && s.sum_p<8000 )
    {
    	printf("\n\n\t( We offer him 10 PERCENT discount ) \n\n");
    	s.sum_p=s.sum_p*0.9;
    	c.total=s.sum_p; 
    	printf("\n\t\tTHE BILL IS\n\n");
    	printf("name :%s\n",c.name);
    	printf("total amount :%f",c.total);
    	printf("\n-------------------------------------------\n");
    	
	}
	if( s.sum_p>=8000 && s.sum_p<10000)
	{
		printf("\n\n\t( We offer him 20 PERCENT discount )\n\n");
    	s.sum_p=s.sum_p*0.8;
    	c.total=s.sum_p; 
    	printf("\n\t\tTHE BILL IS\n\n");
    	printf("name :%s",c.name);
    	printf("total amount :%f",c.total);
    	printf("\n-------------------------------------------\n");
	}
	if( s.sum_p>=10000)
	{
		printf("\n\n\t( We offer him 30 PERCENT discount )\n\n");
    	s.sum_p=s.sum_p*0.7;
    	c.total=s.sum_p; 
    	printf("\n\t\tTHE BILL IS\n\n");
    	printf("name :%s\n",c.name);
    	printf("total amount :%f",c.total);
    	printf("\n-------------------------------------------\n");
	}
    fprintf(file1,"customer name :%s\nsale is %f \nand sum of retail price is %f\n",c.name,s.sum_p,s.sum_r); 
    fprintf(file2,"customer name :%s Total price is %f\n",c.name,c.total);
    
	fclose(file);
	fclose(file1);
	fclose(file2);
	
	printf("\n\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    }  
 	
 }
 
single_cus()
{
	FILE *ptr;
	char ch[20];
	int i,a;
	struct customer c;
	
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n");
	
	ptr=fopen("customer.txt","r");
    if(ptr==NULL)
    {
    	printf("\nError\n");
    	exit(1);
	}
	printf("Input Customer Name : ");
	scanf("%s",&ch);
	printf("\n\n");
	for(i=0;!feof(ptr);i++)
	{
	fscanf(ptr,"customer name :%s Total price is %f\n",&c.name,&c.total);
	if(strcmp(c.name,ch)==0)
	{
		printf("customer name :%s\nTotal price is %f\n\n",c.name,c.total);
	}
    
	}
	fclose(ptr);
	
	printf("\n\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    }  
}

all_cus()
{
	FILE *ptr;
	int i,a;
	struct customer c;
	
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n");
	
	ptr=fopen("customer.txt","r");
    if(ptr==NULL)
    {
    	printf("\nError\n");
    	exit(1);
	}
	printf("\n\n");
	for(i=0;!feof(ptr);i++)
	{
	fscanf(ptr,"customer name :%s Total price is %f\n",&c.name,&c.total);
	printf("customer name :%s\nTotal price is %f\n\n",c.name,c.total);
	}
	fclose(ptr);
	
	printf("\n\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    }  
}
 
delete_product(struct product *p)
{
	FILE *file;
	FILE *file1;
	int i,x,a,product;
	
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n");
	
	file=fopen("project.txt","r");
	if(file==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}
 	file1=fopen("new.txt","w");
 	if(file1==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}
	
	printf("how many products do you want to delete: ");
 	scanf("%d",&x);
	
 	for(i=0;i<x;i++)
	{
		printf("\nEnter the product ID you want to delete: ");
		scanf("%d",&product);
		
		for(;!feof(file);)
	    {		
			fscanf(file,"id : %d name : %s price : %f retail price : %f quantity : %d \n",&(p+i)->id,&(p+i)->name,&(p+i)->price,&(p+i)->rprice,&(p+i)->quantity);
			if((p+i)->id!=product)
			{
				fprintf(file1,"id : %d name : %s price : %f retail price : %f quantity : %d \n",(p+i)->id,(p+i)->name,(p+i)->price,(p+i)->rprice,(p+i)->quantity);	
			}
        }
		
	}
	fclose(file);
	fclose(file1);
	
	remove("project.txt");
	rename("new.txt","project.txt");	
	
	printf("\n\n\tPRODUCT DELETED SUCCESSFULLY!\n\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    }  
}

int edit_product(struct product *p)
{
	FILE *file;
	FILE *file1;
		
	int i,x,a,choice;
	int quan;
	float price,r_price;
	char name[10];
	
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n");
	
	printf("\nPlease input the product ID : ");
	scanf("%d",&x);
	
	file=fopen("project.txt","r");
	if(file==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}
	file1=fopen("new.txt","w");
 	if(file1==NULL)
	{
		printf("ERROR file to edit product not found");
		exit(1);
	}
	
	for(i=0;!feof(file);i++)
	{		
		fscanf(file,"id : %d name : %s price : %f retail price : %f quantity : %d \n",&(p+i)->id,&(p+i)->name,&(p+i)->price,&(p+i)->rprice,&(p+i)->quantity);
		if((p+i)->id==x)
		{
			printf("\n\n\tPress 1 for NAME\n\tPress 2 for PRICE\n\tPress 3 for RETAIL PRICE\n\tPress 4 for QUANTITY\n\n");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:
				printf("\nEnter new name: ");
				scanf("%s",&name);
				fprintf(file1,"id : %d name : %s price : %f retail price : %f quantity : %d \n",(p+i)->id,name,(p+i)->price,(p+i)->rprice,(p+i)->quantity);
				printf("\n\n\tNAME EDITED SUCCESSFULLY\n\n");
				break;
				
				case 2:
				printf("\nEnter new price: ");
				scanf("%f",&price);
				fprintf(file1,"id : %d name : %s price : %f retail price : %f quantity : %d \n",(p+i)->id,(p+i)->name,price,(p+i)->rprice,(p+i)->quantity);
				printf("\n\n\tPRICE EDITED SUCCESSFULLY\n\n");
				break;
				
				case 3:
				printf("\nEnter new retail price: ");
				scanf("%f",&r_price);
				fprintf(file1,"id : %d name : %s price : %f retail price : %f quantity : %d \n",(p+i)->id,(p+i)->name,(p+i)->price,r_price,(p+i)->quantity);
				printf("\n\n\tRETAIL PRICE EDITED SUCCESSFULLY\n\n");
				break;
				
				case 4:
				printf("\nEnter new quantity: ");
				scanf("%d",&quan);
				fprintf(file1,"id : %d name : %s price : %f retail price : %f quantity : %d \n",(p+i)->id,(p+i)->name,(p+i)->price,(p+i)->rprice,quan);	
				printf("\n\n\tQUANTITY EDITED SUCCESSFULLY\n\n");
				break;		
				
			}
		}
		
		else
		{
			fprintf(file1,"id : %d name : %s price : %f retail price : %f quantity : %d \n",(p+i)->id,(p+i)->name,(p+i)->price,(p+i)->rprice,(p+i)->quantity);
		}
	}
		
	fclose(file);
	fclose(file1);
	
	remove("project.txt");
	rename("new.txt","project.txt");
	
	printf("\n\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    }  
	
}

single_sup()
{
	struct supplier z;
	FILE *ptr;
	int i,j,flag=0;
	
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n");
		
	ptr=fopen("supplier.txt","r");
	if(ptr==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}
	printf("Input the Supplier number you want to search : ");
	scanf("%d",&j);
	for (i=0;!feof(ptr);i++)
	{
		fscanf(ptr,"s_num : %d name : %s p_id : %d price : %f quantity : %d date : %s\n",&z.s_num,&z.name,&z.p_id,&z.price,&z.quantity,&z.date);
	    if(z.s_num==j)
	    {
	    	flag=1;
		    printf("\n\nsupplier number : %d\nname : %s\nproduct id : %d\nprice : %f\nquantity : %d\ndate : %s\n",z.s_num,z.name,z.p_id,z.price,z.quantity,z.date);
			break;
		}
	}
	if(flag==0)
	{
		printf("\n\tNo such supplier found!!!\n");
	}
	
	int a;
	printf("\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    }  
}

all_sup()
{
	struct supplier z;
	FILE *ptr;
	int i;
	
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n");
		
	ptr=fopen("supplier.txt","r");
	if(ptr==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}
	for (i=0;!feof(ptr);i++)
	{
	fscanf(ptr,"s_num : %d name : %s p_id : %d price : %f quantity : %d date : %s\n",&z.s_num,&z.name,&z.p_id,&z.price,&z.quantity,&z.date);
    printf("\n\nsupplier number : %d\nname : %s\nproduct id : %d\nprice : %f\nquantity : %d\ndate : %s\n\n",z.s_num,z.name,z.p_id,z.price,z.quantity,z.date);
    }
    
    int a;
	printf("\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    } 
}	

add_sup(struct product *p)
{
	struct supplier z;
	FILE *ptr;
	FILE *ptr1;
	FILE *ptr2;
	int f;
	int i,j,count=0;
	char a[3];
	char b[3]="YES";
	char c[3]="yes";
	
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n");
		
	ptr=fopen("supplier.txt","a");
	ptr1=fopen("project.txt","r");
	ptr2=fopen("p.txt","w");
			
	if(ptr==NULL)
	{
		printf("ERROR file of supplier not found");
		exit(1);
	}
	
	if(ptr1==NULL)
	{
		printf("ERROR file of product not found");
		exit(1);
	}
	
	if(ptr2==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}
	
 	printf("supplier id : ");
    scanf("%d",&z.s_num);
	printf("Supplier Name : ");
	scanf("%s",&z.name);
	printf("Date (DD/MM/YYYY) : ");
	scanf("%s",&z.date);
	
	printf("\n\nEnter product details you want to supply :\n\n");
	printf("enter product ID: ");
	scanf("%d",&z.p_id);
	printf("enter product price: ");
	scanf("%f",&z.price);
	printf("Enter quantity: ");
	scanf("%d",&z.quantity);
	
	for(j=0;!feof(ptr1);j++)
	{
		fscanf(ptr1,"id : %d name : %s price : %f retail price : %f quantity : %d \n",&(p+j)->id,&(p+j)->name,&(p+j)->price,&(p+j)->rprice,&(p+j)->quantity);

		if ((p+j)->id==z.p_id)
		{
			count=1;
			
			if((p+j)->price!=z.price)
			{
				printf("\n\nPrice doesnot match:\n\n\tEnter < YES > to update new price\n\n");
				scanf("%s",&a);
				
				if( strcmp(a,b)==0 || strcmp(a,c)==0 )
				{
					(p+j)->price=z.price;
					
					fprintf(ptr2,"id : %d name : %s price : %f retail price : %f quantity : %d \n",(p+j)->id,(p+j)->name,(p+j)->price,(p+j)->rprice,(p+j)->quantity);
					printf("\n\n\tPRICE UPDATED SUCCESSFULLY!!!\n\n");
					continue;
				}	
			
			}
		}
		
		fprintf(ptr2,"id : %d name : %s price : %f retail price : %f quantity : %d \n",(p+j)->id,(p+j)->name,(p+j)->price,(p+j)->rprice,(p+j)->quantity);
	
	}
		
	fprintf(ptr,"s_num : %d name : %s p_id : %d price : %f quantity : %d date : %s\n",z.s_num,z.name,z.p_id,z.price,z.quantity,z.date);
	
	fclose(ptr1);
	fclose(ptr2);
	fclose(ptr);
		
	remove("project.txt");
	rename("p.txt","project.txt");

	if(count==0)
	{
		printf("\n\nProduct doesnot found in store:\n\n\tEnter < YES > to add new product\n\tEnter < NO > to return\n");
		scanf("%s",&a);
		
		if( strcmp(a,b)==0 || strcmp(a,c)==0 )
		{
			ptr1=fopen("project.txt","a");
			
			printf("\n\nplease enter new product: \n\n");
			printf("ID : ");
			scanf("%d",&p->id);
			printf("name : ");
			scanf("%s",&p->name);
			printf("price : ");
			scanf("%f",&p->price);
			printf("retail price : ");
			scanf("%f",&p->rprice);
			printf("quantity : ");
			scanf("%d",&p->quantity);
			printf("\n\n\tProduct added successfully !\n\n");
			
			fprintf(ptr1,"id : %d name : %s price : %f retail price : %f quantity : %d \n",p->id,p->name,p->price,p->rprice,p->quantity);
		}
		
		else
		{
			printf("\nenter 1 to return back: ");
			scanf("%d",&f);
			
			if(f==1)
			{
				system("cls");
				return;
			}
		}
	
	}
	
	fclose(ptr1);
	printf("\nenter 1 to return back: ");
    scanf("%d",&f);
    
    if(f==1)
    {
    	system("cls");
    }

}

del_sup()
{
	struct supplier z;
	FILE *ptr;
	FILE *ptr1;
	int i,j,flag=0;
	
	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n");
		
	ptr=fopen("supplier.txt","r");
	if(ptr==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}
	ptr1=fopen("new1.txt","w");
	if(ptr1==NULL)
	{
		printf("ERROR file not found");
		exit(1);
	}
	printf("Input the Supplier id you want to delete : ");
	scanf("%d",&j);
	for (i=0;!feof(ptr);i++)
	{
	fscanf(ptr,"s_num : %d name : %s p_id : %d price : %f quantity : %d date : %s\n",&z.s_num,&z.name,&z.p_id,&z.price,&z.quantity,&z.date);
    if(z.s_num!=j)
    {
    fprintf(ptr1,"s_num : %d name : %s p_id : %d price : %f quantity : %d date : %s\n",z.s_num,z.name,z.p_id,z.price,z.quantity,z.date);
	}
	else 
	{
		flag=1;
	}
	}
	if(flag==1)
	{
		printf("\n\tSuccessfully Deleted!\n\n");
	}
	
	if(flag==0)
	{
		printf("\n\tproduct ID not found!!!\n\n");
	}
	
	fclose(ptr);
	fclose(ptr1);
	
	remove("supplier.txt");
	rename("new1.txt","supplier.txt");
	
	int a;
	printf("\nenter 1 to return back: ");
    scanf("%d",&a);
    
    if(a==1)
    {
    	system("cls");
    } 
}
 
main()
{
   struct product p[5];
   struct customer c;
   struct sale s;
   
   int choice;
   
    for(;;)
	{
	   printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n\tPress 1 for ADMIN\n\tPress 2 for CASHIER\n\tPress 3 for SUPPLIER\n\tPress 4 for EXIT\n\n");
	   scanf("%d",&choice);
	   
	    if(choice==4)
	    {
	   	    exit(1);
	    }
	   
	    struct users user ;
	   
	    if(choice==1)
	    { 
			int y;
		    printf("\npress ( 1 ) for signup and press ( 2 ) for signin\n\n");
		    scanf("%d",&y);
		    struct users a;
		    if (y==1)
		    {
		    	signup(&a);
		    	system("cls");
			}
			else 
			{
				signin(1);
				system("cls");
				
			    for(;;)
		   	 	{
		   		    printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n\nADMIN :\n\n\tPress 1 for availability of products :\n\tPress 2 for add new products :\n\t");
					printf("Press 3 all sales  :\n\tpress 4 for profit and loss :\n\tPress 5 to edit a product :\n\tPress 6 to delete a product :\n\tPress 7 to EXIT the ADMIN program\n\n");
		   	 	    scanf("%d",&choice);
		   	 	    system("cls");
		   	 	    
		   	 	    int x;
		   	 	    
		   	 	    if(choice==7)
		   	 	    {
		   	 	    	break;
					}
		   	 	    switch(choice)
		   	 	    {
					    case 1:
				    	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n\n\tpress 1 for a single product: \n\tpress 2 for all products: \n\n ");
   	 		            scanf("%d",&choice);
   	 		            
   	 		            switch (choice)
   	 		            {
							case 1:
							single_product(&p[0]);
							break;	
										
		   	 		        case 2: 						
							all_products(&p[0]);
							break;
   	 	                }
   	 	            
   	 	                break;
   	 	                
   	 	                case 2:
   	 	                new_product(&p[0]);	
   	 	                break;
 	                
   	 	                case 3:
   	 	                all_sales(&s);	
   	 	                break;
	   	 	            
	   	 		        case 4:
	   	 		        profit_loss(&s);	
   	 		        	break;	 
							
						case 5:
	   	 		        edit_product(&p[0]);	
   	 		        	break;  
						
						case 6:
						delete_product(&p[0]);	
						break;	 
		   	 		}	
		   	 	}
		   	}
		}
	   	
	   	if(choice==2)
	   	{
		   	int y;
		    printf("\npress ( 1 ) for signup and press ( 2 ) for signin\n\n");
		    scanf("%d",&y);
		    
		    struct users a;
		    
		    if (y==1)
		    {
		    	signup(&a);
		    	system("cls");
			}
			
			else 
			{
				signin(1);
				system("cls");
		
		   		for(;;)
			   	{
			   		int ace;
			   		printf("\n\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n\nCASHIER :\n\n\tPress 1 for MARKETING :\n\tPress 2 for SEARCHING a customer :\n\tPress 3 to EXIT : \n");
			   		scanf("%d",&ace);
			   		system("cls");
			   		
				   	if(ace==3)
				    {
				   	    break;
				    }
				    
				    switch(ace)
				    {
				    	case 1:
				    	disp(&p[0]);
				    	marketing(&p[0]);	
				    	break;
				    	
				    	case 2:
				    	printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n\n\tpress 1 for a single Customer : \n\tpress 2 for all Customers: \n\n ");
	 		            scanf("%d",&choice);
	 		            system("cls");
	 		            
	 		            switch(choice)
	 		            {
	 		            	case 1:
	 		            	single_cus();
	 		            	break;
	 		            	
	 		            	case 2:
							all_cus();
							break;
						}
				        break;		
					}  
				}
			}
	    }
	    
	    if(choice==3)
	    {
	    	int y;
		    printf("\npress ( 1 ) for signup and press ( 2 ) for signin\n\n");
		    scanf("%d",&y);
		    struct users a;
		    if (y==1)
		    {
		    	signup(&a);
		    	system("cls");
			}
			else 
			{
				signin(1);
				system("cls");
				for(;;)
			   	{
			   		printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n\nSUPPLIER :\n\n\tPress 1 for EDITING a product :\n\tPress 2 for SEARCHING a supplier :\n\tPress 3 for DELETE a supplier :\n\tPress 4 to ADD a supplier\n\tPress 5 to EXIT : \n\n");
			   		scanf("%d",&choice);
			   		system("cls");
			   		
			   		if(choice==5)
				    {
				   	    break;
				    }
				    switch(choice)
				    {
						
						case 1:
					    edit_product(&p[0]);
					    break;
					    
						case 2:
						printf("\t\t\tPROGRAM OF DEPARTMENTAL SYSTEM\n\n\n\tpress 1 for a single supplier: \n\tpress 2 for all supplier: \n\n ");
	 		            scanf("%d",&choice);
	 		            system("cls");
	 		            
	 		            switch (choice)
	 		            {
							case 1:
							single_sup();
							break;	
										
		   	 		        case 2: 						
							all_sup();
							break;
	 	                }
	 	                break;
	   	 	                
						case 3:
						del_sup();
						break; 
						
						case 4:
						add_sup(&p[0]);
						break;  	 	
					}	
			   	}
			}	
		}
	}
}
