#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>


void formate3();
void formate2();
void formate1();
void formate();
void foodmenu();
void mainmenu();
void ord_veg();
void ord_nonveg();
void ord_egg();
void ord_instruction();
void contactus();
void exit();
void ord_confirm();
void bill();
void user_bill();
void change_details();
void user_updateall_detail();
void user_search();
void user_update_bill();

int a=3,b=16,c=17,q=196,select;
char pack_name[20];
float pack_cost;
float no_pack;


typedef struct details
{
	int id;
	char name[20];
	char ph[20];
	char add[50];
	char date[20];

}det ;

det d;


void user()
{
	clrscr();
	FILE *fp;
	det d;
	fp=fopen("user.txt","w");
		if(fp==NULL)
		{
			printf("File Not Opened");
		}

	formate2();
	printf("\nEnter Your Order ID:");
	scanf("%d",&d.id);
	printf("\nEnter Your Name:");
	scanf("%s",d.name);
	printf("\nEnter Your Mobile Number:");
	scanf("%s",d.ph);
	printf("\nEnter Your Area of Address :");
	scanf("%s",d.add);
	printf("\nEnter Billing Date:");
	scanf("%s",&d.date);

	fwrite(&d,sizeof(det),1,fp);
	fclose(fp);

	change_details();
}



void user_updateall_detail()
{
	clrscr();

	FILE * fp,*new_ptr;
	det d,t;
	int found=0,id;
	fp=fopen("user.txt","r");
		if(fp==NULL)
		{
			printf("\n file not opened\n");
			return;
		}

	new_ptr=fopen("temp.txt","w");
		if(new_ptr==NULL)
		{
			printf("\n file not opened \n");
			return;
		}


	printf("\nEnter Your Order id Number to Change Details:");
	scanf("%d",&id);
		while(1)
		{
			fread(&d,sizeof(det),1,fp);
			if(feof(fp))
			break;
			if(id==d.id)
			{
				found=1;
				printf("\nUser Found!!!!");
				formate2();
				printf("\nEnter your ID:");
				scanf("%d",&t.id);
				printf("\nEnter your Name:");
				scanf("%s",t.name);
				printf("\nEnter your Mobile Number:");
				scanf("%s",t.ph);
				printf("\nEnter your Address:");
				scanf("%s",t.add);
				printf("\nEnter Billing Date:");
				scanf("%s",&t.date);
				fwrite(&t,sizeof(det),1,new_ptr);
			}
				else
				{
				fwrite(&d,sizeof(det),1,new_ptr);
				}
			}

	fclose(fp);
	fclose(new_ptr);

	if(found==0)
	printf("\n record not found\n");
	else
	{
		fp=fopen("user.txt","w");
		if(fp==NULL)
		{
			printf("\n file not opened \n");
			return;
		}
		new_ptr=fopen("temp.txt","r");
		if(new_ptr==NULL)
		{
			printf("\n file not opened \n");
			return;
		}
		while(1)
		{
		if(feof(new_ptr))
		break;
		fread(&d,sizeof(det),1,new_ptr);
		fwrite(&d,sizeof(det),1,fp);
		}
	}
	fclose(fp);
	fclose(new_ptr);

	user_bill();


}



void user_bill()
{
	clrscr();
	textcolor(0);
	textbackground(7);
	FILE *fp;
	det d,t;

	fp=fopen("user.txt","r");

		if(fp==NULL)
		{
			printf("File Opened");
		}
		else
		{
			while(1)
			{

			fread(&d,sizeof(det),1,fp);
			if(feof(fp))
			break;


		formate();
		printf("Id: %d",d.id);

		if(strcmp(d.name,"anjum")==0)
		{
		printf("\nName: %c%s%c",a,d.name,a);
		}
		else
		printf("\nName: %s",d.name);


		printf("\nAddress: %s\n",d.add);

		formate1();
		printf("Billing Date: %s",d.date);
		printf("\n\n\n\n\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  Thank You For Visiting  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q);
		printf("\n\t\t      <<<<< Enter Any Key To Go Back>>>>>");

		}
      }
		fclose(fp);


	getch();
	clrscr();
	mainmenu();
 }

void user_search()
{
	FILE *fp;
	det d;
	char name1[50];
	int flag=0;

	fp=fopen("user.txt","r");

	if(fp==NULL)
		{
		printf("\n file not opened\n");
		return;
		}

	printf("\nEnter Your Name that You want to Search:");
	scanf("%s",name1);
	while(1)
	{
	fread(&d,sizeof(det),1,fp);
	if(feof(fp))
	break;

	if(strcmp(name1,d.name)==0)
		{
		flag=1;
		clrscr();
		printf("\nDetails  Found!!!");
		formate3();
		printf("\n Order Id: %d \n\n Your Name: %s \n\n Your Mobile Number: %s \n\n Your Address: %s \n\n Billing Date: %s",d.id,d.name,d.ph,d.add,d.date);
		return;
		}
	}

	 if(flag==0)
	 printf("\n details not found \n");
	 fclose(fp);

}


void mainmenu()
{

	int select1;
	printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178);
	printf("\t\t\t%c  WELCOME TO BCA CATERING WALA\t%c\n",178,178);
	printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);

	printf("\n\n");


	printf("\n\t\t\t(1) FOOD MENU\n\n");
	printf("\t\t\t(2) Ordering Process/Instruction\n\n");
	printf("\t\t\t(3) Contact Developer\n\n");
	printf("\t\t\t(4) Exit\n\n");

	printf("\n\n\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
	printf("\n\tSelect Option:");
	scanf("%d",&select1);

	if(select1==1)
	{
		clrscr();
		foodmenu();
	}
	else if(select1==2)
	{
		clrscr();
		ord_instruction();
	}
	else if(select1==3)
	{
		clrscr();
		contactus();
	}
	else if(select1==4)
	{
		clrscr();
		exit();
	}
	else
	{
		clrscr();
		mainmenu();
	}

}



void foodmenu()
{
	int b=16,c=17,select;

	printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178);
	printf("\t\t\t%c  WELCOME TO BCA CATERING WALA\t%c\n",178,178);
	printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178);
	printf("\n\n");
	printf("\t\t     %c%c%c%c%c%c%c%c%c%c OUR SPECIAL COMBO %c%c%c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c,c,b,b,b,b,b,b,b,b,b,b);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);

	printf("\t\tPackage Name\t\t\t\tPrice\n");
	printf("\n\t\t(1) Classic Veg Meal\t\t\t899 Rs\n\n");
	printf("\t\t(2) Hot Non-Veg Meal\t\t\t1599 Rs\n\n");
	printf("\t\t(3) Spicy Egg Meal\t\t\t499 Rs\n\n");
	printf("\t\t(4) Go Back\t\t\t\t\n\n");

	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);

	printf("\n\n\tSelect Option:");
	scanf("%d",&select);

	clrscr();


	if(select==1)
	{
		clrscr();
		ord_veg();

	}
	else if(select==2)
	{
		clrscr();
		ord_nonveg();

	}
	else if(select==3)
	{
		clrscr();
		ord_egg();

	}
	else if(select==4)
	{
		clrscr();
		mainmenu();
	}
	else
	{
		foodmenu();
	}

}



void ord_veg()
{
	int quantity;
	char sure[5];
	printf("\n\t\t\t    %c Classic Veg Meal %c\n",1,1,c,c,c,c,b,b,b,b);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);

	printf("\tItems\t\t\t\t\t\tQuantity\n");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);


	printf("\t%c Biryani\t\t\t\t\t1%c kg\n\n",175,171);
	printf("\t%c Hungry Paneer\t\t\t\t\t970 gm\n\n",175);
	printf("\t%c dal makhan\t\t\t\t\t1%c kg\n\n",175,172);
	printf("\t%c Gulab jamun\t\t\t\t\t12 pcs\n\n",175);
	printf("\t%c Aam rass\t\t\t\t\t1 liter\n\n",175);
	printf("\t%c papad\t\t\t\t\t\t12 pcs\n",175);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	ord_confirm();

}


void ord_nonveg()
{
	printf("\n\t\t\t    %c Hot Non-Veg Meal %c\n",1,1,c,c,c,c,b,b,b,b);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	printf("\t\tItems\t\t\t\t\t\tQuantity\n");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	printf("\t%c  chicken Biryani\t\t\t\t\t1%c kg\n\n",175,171);
	printf("\t%c  chicken muradabadi\t\t\t\t\t950 gm\n\n",175);
	printf("\t%c  chicken salamati\t\t\t\t\t%c kg\n\n",175,171);
	printf("\t%c  chicken 65 DRY\t\t\t\t\t1 kg\n\n",175);
	printf("\t%c  sikh\t\t\t\t\t\t\t10 pcs\n\n",175);
	printf("\t%c  jeeru drink with water bottle\t\t\t4 liter\n\n",175);

	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	ord_confirm();


}

void ord_egg()
{

	printf("\n\t\t\t\t  %c Spicy Egg Meal %c\n",1,1,c,c,c,c,b,b,b,b);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	printf("\t\tItems\t\t\t\t\tQuantity\n");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);

	printf("\t%c  Egg biryani\t\t\t\t\t2.5 kg\n\n",175);
	printf("\t%c  Egg curry \t\t\t\t\t950 gm\n\n",175);
	printf("\t%c  Egg Frankie\t\t\t\t\t12 roll\n\n",175);
	printf("\t%c  Special Masala Egg\t\t\t\t10 plates\n\n",175);
	printf("\t%c  Soft Drink with pure Water\t\t\t2ltr\n\n",175);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	ord_confirm();

}

void exit()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t  THANKS FOR VISITING OUR PAGE");
}


void ord_instruction()
{
	printf("\t\t\t\tInstruction\n\n\n");
	printf("-> Hey,i'm explaining how to order our special and delicious packages from us: \n\n\n");
	printf("STEP 1: If you want to order a food you've to press 1 to select FOOD MENU:\n\n\n");
	printf("STEP 2: Then after our page opens a page named OUR SPECIAL COMBO In this options");
	printf("there are 3 types of Menus you've to select as your wish.\n\n\n");
	printf("STEP 3: Then after seeing our all of packages you want order whatever package you like and you'nt be also go the menu with the help of go back\n\n\n");
	printf("STEP 4: then you are finalized about your order then you've to enter your information for billing process and at the case of wrong credential you'll be update your information with the help of update function.\n\n\n\n");
	printf("\t\t\t\tThank you");
	getch();
	clrscr();
	mainmenu();

}

void contactus()
{
	printf("\t\t\t\t-> CATERING MANAGEMENT.\n ");
	printf("-------------------------------------------------------------------------------");
	printf("\t\t\t\t1) NAVED MEMON\n\n");
	printf("\t\t\t\t2) IRBAZ LOKHANDWALA\n\n");
	printf("\t\t\t\t3) FARMAN ANSARI\n\n\n");
	printf("--------------------------------------------------------------------------------");
	printf("\t\t\tAny query related project then contact \n\n\n");
	printf("\t\t\t\tRoll no:33\n\n");
	printf("\t\t\t\tRoll no:26\n\n");
	printf("\t\t\t\tROll no: 4\n\n\n");

	printf("\t\t\t\tThank you") ;
	getch();
	clrscr();
	mainmenu();

}

void ord_confirm()
{
	int select2;

	printf("(1) Order this\n");
	printf("(2) Back\n\n");


	printf("Select Option:");
	scanf("%d",&select2);

	if(select2==1)
	{

		printf("Enter your package name:");
		scanf("%[^.]%s",pack_name);
		printf("Enter your Package Cost:");
		scanf("%f",&pack_cost);
		printf("Number of packages:");
		scanf("%f",&no_pack);
		clrscr();
		user();

	}
	else if(select2==2)
	{
		clrscr();
		foodmenu();
	}
	else
	{
		ord_confirm();
	}

}

void change_details()
{
	clrscr();
	char change5[10];
	int select3;
	printf("\nDo you want to change your details(yes/no):");
	scanf("%s",change5);
	if(strcmp(change5,"yes")==0)
	{
		clrscr();
		printf("\n[1] Update All Details");
		printf("\n[2] Search Your Details");
		printf("\n[3] Print Bill");
		printf("\n\n\n\nSelect option:");
		scanf("%d",&select3);
		if(select3==1)
		{
			user_updateall_detail();

		}
		else if(select3==2)
		{
			user_search();
		}
		else if(select3==3)
		{
			user_bill();
		}
		else
		{
			change_details();
		}

	}
	else if(strcmp(change5,"no")==0)
	{
		clrscr();
		user_bill();
	}
	else
	{
		clrscr();
		change_details();
	}

}

void formate()
{
	printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178);
	printf("\t\t\t%c  WELCOME TO BCA CATERING WALA\t%c\n",178,178);
	printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);

	printf("\t\t\t\t  %c BILL Receipt %c\n\n",1,1);


}
void formate1()
{

	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);

	printf("Items\t\t\t\tQuantity\t\t\tPrice\n");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q);
	printf("%s\t\t%.2f\t\t\t\t%.2f\n",pack_name,no_pack,pack_cost);
      //	printf("\t\t%.2f\t\t\t\t%.2f\n",no_pack,pack_cost);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q);

      printf("Total Amount :-\t\t\t\t\t\t\t%.3f\n",no_pack*pack_cost);

 }

void formate2()
{
	  printf("\n\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  Enter Your Personal Details  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q);

}

void formate3()
{
	  printf("\n\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  Your Personal Details  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q,q);

}

void main()
{

	clrscr();
	mainmenu();
	getch();



}


