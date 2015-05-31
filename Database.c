/*
 ============================================================================
 Name        : trial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 ============================================================================
 Name        : Pavan suta H D
 Date        : 13th Oct 2012
 Version     : 1.1
 Description :Database Management
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>



/*
 ============================================================================
 Name:structure
 Description :Structure empdetail contains diffrent data types which includes the psno,age,experience,
 salary,name,psno.
 ============================================================================
 */
struct empdetail
{
	int slno;
	int psno;
	char name[20];
	int age;
	int salary;
	int year;
	int exp;
	struct empdetail *next;


}e1,e,e2,e3;
int PSNO,history_flag=0,check1=0,m,n,count1_2010,count1_2011;;
char NAME,GLOBALNAME[20];
struct empdetail *begg1=NULL,*start1=NULL,*start2=NULL,*start3=NULL,*start4=NULL,*begg2=NULL,*begg3=NULL,*begg4=NULL,*point=NULL;
struct empdetail *create();
time_t currentime;
void display();


/*
 ============================================================================
 Function name:int_cnv()
 Description :The function int_cnv performs ASCII to integer conversion.
 ============================================================================
 */


int int_cnv(char numT1[10])

{
	int i,flag_cnv=0,value,d;
	char ch='\0';

	d=strlen(numT1);
	for( i=0;i<d;i++)
	{
		if(!((numT1[i]<=57)&&(numT1[i]>=48)))
		{
			printf("\n Please enter a valid number \n\t");
			flag_cnv=1;
			break;
		}
		else
		{
			flag_cnv=0;
		}

	}



	if(flag_cnv==0)
	{
		value=atoi(numT1);//ASCII to integer conversion
		return value;

	}
	else
		return ch;

}



/*
 ============================================================================
 Function name:()fetch_name()
 Description :The function pointer fetch_name() performs english letters validation
 for e.g; whether the given input is only an english letter & not any real number.
 ============================================================================
 */

char *fetch_name()
{

	int i;
	int flagname;
	int d;
	do
	{
		fflush(stdin);
		//This statement limits the string length to 20 characters & will not store even a extra
		//character after the limit.The below statement stores the character until it encounters a
		//new line character.

		scanf("%20[^\n]",GLOBALNAME);
		d=strlen(GLOBALNAME);
		for(i=0;i<d;i++)
		{

			//IF condition below checks the range of the string recived in the buffer.

			if(!(((GLOBALNAME[i]<='Z')&&(GLOBALNAME[i]>='A'))||((GLOBALNAME[i]<='z')&&(GLOBALNAME[i]>='a'))||(GLOBALNAME[i]==' ')||(sizeof(GLOBALNAME)<=20)))
			{


				printf("\n\nEnter valid name\n");
				flagname=1;
				break;
			}
			else
			{
				flagname=0;
			}



		}
	} while(flagname);
	return GLOBALNAME;

}


/*
 ============================================================================
 Function name:fetch_number()
 Description :THe function fetch_number checks whether the received number
 is in the range 1 to 8.
 ============================================================================
 */



int fetch_number()
{
	char numT[5];
	int num,flagc;
	do
	{
		fflush(stdin);
		scanf("%5[^\n]",numT);
		if(numT[0]=='0')
		{
			printf("\n Enter a valid number between 1 and 8\n");
			flagc=1;
		}
		else
		{
			num=int_cnv(numT);


			if(((num>=1)&&(num<=8)))
			{
				flagc=0;
			}
			else
			{
				printf("\n Enter a valid number between 1 and 8\n");
				flagc=1;
			}
		}
	}while(flagc);
	return num;
}
/*int fetch_number()
{
	int num;

	int flagc;
	do
	{
		num=int_cnv();
		printf("\n%d\n",num);
		if((num>=1)&&(num<=8))
		{

			flagc=0;

		}
		else
		{
			printf("\n fetch_number Enter a valid number between 1 and 8\n");
			flagc=1;
		}

	}while(flagc);
	return num;

}*/


/*
 ============================================================================
 Function name:fetch1_number()
 Description :THe function fetch1_number checks whether the received number
 is in the range 1 to 5.
 ============================================================================
 */

int fetch1_number()
{
	int num;
	char numc[2];
	int flagc;
	do
	{
		fflush(stdin);
		scanf("%5[^\n]",numc);
		//This statement limits the string length to 5 characters & will not store even a extra
		//character after the limit.The below statement stores the character until it encounters a
		//new line character.
		if(numc[0]=='0')
		{
			printf("\n Enter a valid number between 1 and 5\n");
			flagc=1;
		}
		else
		{
			num=int_cnv(numc);
			if((num>=1)&&(num<=5))
			{

				return num;

			}
			else
			{
				printf("\n Enter a valid number between 1 and 5\n");
				flagc=1;
			}
		}

	}while(flagc);
	return '\0';

}
/*
 ============================================================================
  Function name:fetch2_number()
 Description :THe function fetch2_number checks whether the received number
 is in the range 1 to 2.
 ============================================================================
 */

int fetch2_number()
{
	int num;
	char numM[2];
	int flagc;
	do
	{
		fflush(stdin);
		//This statement limits the string length to 6 characters & will not store even a extra
		//character after the limit.The below statement stores the character until it encounters a
		//new line character.
		scanf("%6[^\n]",numM);
		if(numM[0]=='0')
		{
			printf("\n Enter a valid number between 1 and 2\n");
			flagc=1;
		}
		else
		{
			num=int_cnv(numM);
			if((num>=1)&&(num<=2))
			{

				return num;

			}
			else
			{
				printf("\n Enter a valid number between 1 and 2\n");
				flagc=1;
			}
		}

	}while(flagc);
	return '\0';

}

/*
 ============================================================================
 Function name:fetch3_number()
 Description :THe function fetch3_number checks whether the received number
 is in the range 10000000 to 99999999.
 ============================================================================
 */

int fetch3_number()
{
	int num;
	char numP[15];
	int flagc;
	do
	{
		fflush(stdin);
		//This statement limits the string length to 15 characters & will not store even a extra
		//character after the limit.The below statement stores the character until it encounters a
		//new line character.
		scanf("%15[^\n]",numP);
		if(numP[0]=='0')
		{
			printf("\n Enter a valid 8 digit number\n");
			flagc=1;
		}
		else
		{
			num=int_cnv(numP);
			if((num>=9999999)&&(num<=99999999))
			{

				flagc=0;

			}
			else
			{
				printf("\n Enter a valid 8 digit number\n");
				flagc=1;
			}
		}

	}while(flagc);
	return num;

}
/*
 ============================================================================
 Function name:fetch_salary()
 Description :THe function fetch_salary checks whether the received number
 is in the range 300000 to 50000000.
 ============================================================================
 */
int fetch_salary()
{
	int num;
	char numS[15];

	int flagc;
	do
	{

		fflush(stdin);
		//This statement limits the string length to 15 characters & will not store even a extra
		//character after the limit.The below statement stores the character until it encounters a
		//new line character.
		scanf("%15[^\n]",numS);
		if(numS[0]=='0')
		{
			printf("\n Enter a valid salary between 300000 and 50000000\n");
			flagc=1;
		}
		else
		{
			num=int_cnv(numS);
			if((num>=300000)&(num<=50000000))
			{

				return num;

			}
			else
			{
				printf("\n Enter a valid salary between 300000 and 50000000\n");
				flagc=1;
			}
		}

	}while(flagc);
	return '\0';

}



/*
 ============================================================================
 Function name:fetch_agenumber()
 Description :THe function fetch_agenumber checks whether the received number
 is in the range 20 to 70.
 ============================================================================
 */


int fetch_agenumber()
{
	char numAge[6];
	int num;

	int flagc;
	do
	{
		fflush(stdin);
		//This statement limits the string length to 6 characters & will not store even a extra
		//character after the limit.The below statement stores the character until it encounters a
		//new line character.
		scanf("%6[^\n]",numAge);
		if(numAge[0]=='0')
		{
			printf("\n Enter a valid number between 20 and 70\n");
			flagc=1;
		}
		else
		{
			num=int_cnv(numAge);
			if((num>=20)&(num<=70))
			{

				return num;

			}
			else
			{
				printf("\n Enter a valid number between 20 and 70\n");
				flagc=1;
			}
		}

	}while(flagc);
	return '\0';

}


/*
 ============================================================================
 Function name:fetch_yearnum()
 Description :THe function fetch_yearnum checks whether the received number
 is in the range 2000 to 2015.
 ============================================================================
 */

int fetch_yearnum()
{

	char numY[6];
	int num;

	int flagc;
	do
	{
		fflush(stdin);
		//This statement limits the string length to 6 characters & will not store even a extra
		//character after the limit.The below statement stores the character until it encounters a
		//new line character.
		scanf("%6[^\n]",numY);
		if(numY[0]=='0')
		{
			printf("\n Enter a valid year between 2000 and 2015\n");
			flagc=1;
		}
		else
		{

			//numY[5]='\0';
			num=int_cnv(numY);
			if(((num>=2000)&&(num<=2015)))
			{

				return num;

			}
			else
			{
				printf("\n Enter a valid year between 2000 and 2015\n");
				flagc=1;
			}
		}

	}while(flagc);
	return '\0';

}


/*
 ============================================================================
 Function name:fetch_exp()
 Description :The function fetch_exp checks whether the received number
 is in the range 0 to 60.
 ============================================================================
 */
int fetch_exp()
{

	char numE[6];
	int num;

	int flagc;
	do
	{
		fflush(stdin);
		//This statement limits the string length to 6 characters & will not store even a extra
		//character after the limit.The below statement stores the character until it encounters a
		//new line character.
		scanf("%6[^\n]",numE);
		//if(numE[0]=='0')
		//{
			//flagc=1;
			//printf("\n Enter a valid experience between 0 and 60\n");

		//}
		//else
		//{
			//numE[2]='\0';
			num=int_cnv(numE);
			if((num>=0)&(num<=60))
			{

				return num;

			}
			else
			{
				printf("\n Enter a valid experience between 0 and 60\n");
				flagc=1;
			}
		//}
	}while(flagc);
	return '\0';

}


/*
 ============================================================================
 Function name:get1_char()
 Description :The function get1_char() checks whether the received character
  or string is only 'y'/'Y' & it is of unit length.
 ============================================================================
 */

char get1_char()
{
	//char x[20];
	char x[6];

	int flagc,d;
	do
	{
		fflush(stdin);
		//This statement limits the string length to 6 characters & will not store even a extra
		//character after the limit.The below statement stores the character until it encounters a
		//new line character.
		scanf("%6[^\n]",x);

		d=strlen(x);
		if(((x[0]=='y')||(x[0]=='Y')||(x[0]=='n')||(x[0]=='N'))&&(d==1))
		{
			//printf("\n\n correct \n\n");
			return x[0];

		}
		else
		{
			printf("\n\nEnter valid data (y/n)?\n\n");
			flagc=1;
		}

	}while(flagc);
	return '\0';

}

/*
 ============================================================================
  Function name:get_char()
 Description :THe function get_char() checks whether the received string or
 character is only 'A'/'a'/'E'/'e' & it is of unit length.
 ============================================================================
 */


char get_char()
{
	char x[20];

	int flagc,d;
	do
	{
		fflush(stdin);
		//This statement limits the string length to 6 characters & will not store even a extra
		//character after the limit.The below statement stores the character until it encounters a
		//new line character.
		scanf("%6[^\n]",x);
		d=strlen(x);
		if(((x[0]=='a')||(x[0]=='A')||(x[0]=='e')||(x[0]=='E'))&(d==1))
		{
			//printf("\n\n correct \n\n");
			return x[0];

		}
		else
		{
			printf("\n\nEnter valid data(A/E)?\n\n");
			flagc=1;
		}

	}while(flagc);
	return '\0';

}

/*
 ============================================================================
  Function name:get_chardel()
 Description :THe function get_chardel() checks whether the received string or
 character is only 'P'/'p'/'n'/'N' & it is of unit length.
 ============================================================================
 */

char get_chardel()
{
	char x[20];

	int flagc,d;
	do
	{
		fflush(stdin);
		scanf("%6[^\n]",x);
		d=strlen(x);
		if(((x[0]=='p')||(x[0]=='P')||(x[0]=='n')||(x[0]=='N'))&(d==1))
		{
			//printf("\n\n correct \n\n");
			return x[0];

		}
		else
		{
			printf("\n\nEnter valid data(n/p)?\n\n");
			flagc=1;
		}

	}while(flagc);
	return '\0';

}

/*
 ============================================================================
 Function name:fun_slno()
 Description :THe function fun_slno() returns the serial number to be updated
 for the next employee.
 ============================================================================
 */

int fun_slno()

{
	int slno;
	FILE *fp;
	fp=fopen("appamma.txt","r");
	if(fp!=NULL)
	{

		while(!feof(fp))
		{
			fscanf(fp,"%d %d",&e1.slno,&e1.psno);
			fgets(e1.name,20,fp);
			fscanf(fp,"%d %d %d %d ",&e1.age,&e1.salary,&e1.year,&e1.exp);
			slno=e1.slno;
		}

	}
	else
	{


		slno=0;

	}
	fclose(fp);
	return slno;
}

/*
 ============================================================================
  Function name:append()
 Description :The function append(),performs adding details to the employee
 database.
 ============================================================================
 */
void append()
{
	int slno,slno1;
	char name[20],choice;
	int psno;
	int age;
	int salary;
	int year,exp;
	FILE *fp;

	do
	{
		//calling the function fun_slno to update the serial number
		slno1=fun_slno();
		fp=fopen("appamma.txt","a");
		if(fp==NULL)
		{
			printf("\n\n No file exists under such name\n\n");
			//fclose(fp);
		}
		else
		{
		slno=slno1+1;
		printf("\n enter the psno: ");
		//number validaton by calling the function  fetch3_number()
		psno=fetch3_number();

		printf("\n enter the name of the employee: ");
		//copying the validated name

		strcpy(name,fetch_name());

		printf("\nenter the age of the employee: ");
		fflush(stdin);
		//copying the validated age.
		age=fetch_agenumber();
		printf("\nenter the salary of the employee: ");
		//copying the validated salary.
		salary=fetch_salary();
		printf("\nenter the year of joining of the employee: ");
		//copying the validated year.
		year=fetch_yearnum();
		printf("\nenter the experience of the employee: ");
		//copying the validated experience.
		exp=fetch_exp();
		fprintf(fp,"\n%-2d %-10d %-20s %-2d %-10d %-4d %-2d",slno,psno,name,age,salary,year,exp);
		printf("\n**********************************************************************\n");

		printf("\n!!!!!appended succesfully!!!!\n");
		printf("\n**********************************************************************\n");

		printf("\nDo you want to enter the detail of another employee(y/n)?: ");
		fflush(stdin);
		choice=get1_char();
		fclose(fp);
		}
	}while((choice=='y')||(choice=='Y'));
}


/*
 ============================================================================
 Function name:create()
 Description :The function pointer create() of type empdetail allocates memory for
 structure empdetail,& updates the each node created.
 ============================================================================
 */
struct empdetail * create()
{
	struct empdetail *New;
	//Dynamic memory allocation of size struct empdetail
	New=malloc(sizeof(struct empdetail));
	//The 'NEW' pointer for e.g;here is pointing to the Slno of the newly created node & stores the slno.
	//It works similarly to psno,name.age,salary,year &exp where the struct detail of each employee
	//is stored in each newley created node.
	New->slno=e1.slno;
	New->psno=e1.psno;
	strcpy(New->name,e1.name);
	New->age=e1.age;
	New->salary=e1.salary;
	New->year=e1.year;
	New->exp=e1.exp;
	New->next=NULL;
	return New;
}


/*
 ============================================================================
 Function name:sotrting_name()
 Description :The function sorting_name sorts the empoyee name,based on ASCII
 value of the english alphabets.
 ============================================================================
 */
void sorting_name(int count,struct empdetail *ptr)
{
	int i,j,comp;
	int temp_slno,temp_psno,temp_age,temp_salary,temp_year,temp_exp;
	char temp_name[20];
	struct empdetail *temp_ptr,*begin;

	begin=ptr;

	for(i=0;i<count;i++)
	{
		for(j=0;j<(count-1);j++)
		{
			temp_ptr=ptr->next;
			comp=strcmp(ptr->name,temp_ptr->name);
			if(ptr!=NULL)
			{
				if(comp>0)
				{
					//Exchange or swaping of data between diifferent nodes is done here
					//based on english alphabetical order.
					temp_slno=ptr->slno;
					temp_psno=ptr->psno;
					strcpy(temp_name,ptr->name);
					temp_age=ptr->age;
					temp_salary=ptr->salary;
					temp_year=ptr->year;
					temp_exp=ptr->exp;

					ptr->slno=temp_ptr->slno;
					ptr->psno=temp_ptr->psno;
					strcpy(ptr->name,temp_ptr->name);
					ptr->age=temp_ptr->age;
					ptr->salary=temp_ptr->salary;
					ptr->year=temp_ptr->year;
					ptr->exp=temp_ptr->exp;

					temp_ptr->slno=temp_slno;
					temp_ptr->psno=temp_psno;
					strcpy(temp_ptr->name,temp_name);
					temp_ptr->age=temp_age;
					temp_ptr->salary=temp_salary;
					temp_ptr->year=temp_year;
					temp_ptr->exp=temp_exp;
					//printf("\n%-8d %-20s %-2d %-4d %-8d %-2d\n",ptr->PSNO,ptr->EMP_NAME,ptr->AGE,ptr->YEAR,ptr->SALARY,ptr->EXP);

				}
				ptr=ptr->next;
			}
		}
		ptr=begin;
	}
}

/*
 ============================================================================
 Name:yearwisenode()
 Description :The function yearwisenode() creates linke list for 2010.2011,2012
 & otheryears separatley.

 ============================================================================
 */

void yearwisenode()
{
	FILE *fp;
	int count_2010=0,count_2011=0,count_2012=0,count_otheryear=0;
	struct empdetail *New;
	begg1=NULL;
	start1=NULL;
	begg2=NULL;
	start2=NULL;
	begg3=NULL;
	start3=NULL;
	begg4=NULL;
	start4=NULL;

	fp=fopen("appamma.txt","r");
	if(fp==NULL)
	{
		printf("\nSorry no data exists");
	}
	else
	{
		while(!feof(fp))
		{
			fscanf(fp,"%d %d",&e1.slno,&e1.psno);
			fgets(e1.name,20,fp);
			fscanf(fp,"%d %d %d %d ",&e1.age,&e1.salary,&e1.year,&e1.exp);

			if(e1.year==2010)
			{
				New=create();
				if(start1==NULL)
				{
					//Storing the first node address of year 2010 in begg pointer.
					start1=New;
					begg1=New;
				}
				else
				{
					//Linking to next node address to the present node.
					//Now literally  the next node becomes the new node.
					start1->next=New;
					start1=New;
				}
				count_2010=count_2010+1;
			}
			else if(e1.year==2011)
			{
				New=create();
				if(start2==NULL)
				{
					//Storing the first node address of year 2011 in begg pointer.
					start2=New;
					begg2=New;
				}
				else
				{
					//Linking to next node address to the present node.
					//Now literally  the next node becomes the new node.
					start2->next=New;
					start2=New;
				}
				count_2011=count_2011+1;
			}
			else if(e1.year==2012)
			{
				New=create();
				if(start3==NULL)
				{
					//Storing the first node address of year 2012 in begg pointer.
					start3=New;
					begg3=New;
				}
				else
				{
					//Linking to next node address to the present node.
					//Now literally  the next node becomes the new node.
					start3->next=New;
					start3=New;
				}
				count_2012=count_2012+1;
			}


			else
			{
				New=create();
				if(start4==NULL)
				{
					//Storing the first node address of other year in begg pointer.
					start4=New;
					begg4=New;
				}
				else
				{
					//Linking to next node address to the present node.
					//Now literally  the next node becomes the new node.
					start4->next=New;
					start4=New;
				}
				count_otheryear=count_otheryear+1;
			}
		}
	}
	fclose(fp);

	sorting_name(count_2010,begg1);
	sorting_name(count_2011,begg2);
	sorting_name(count_2012,begg3);
	sorting_name(count_otheryear,begg4);



}


/*
 ============================================================================
 Name:delete_fun()
 Description :The function delete_fun() performs deleting the employee data from
 the database of the company.

 ============================================================================
 */
void delete_fun()
{
	FILE *fp,*fptr;
	int psno1,i;
	char ch,name1[20],del;
	struct empdetail e;
	do
	{
		check1=0;
		printf("\n\n Enter the name or psno of the employee to be deleted\n\n");
		printf("Press N for name & P for psno: ");
		fflush(stdin);
		ch=get_chardel();
		if((ch=='n')||(ch=='N'))
		{
			printf("\nenter the name to be deleted: ");
			strcpy(name1,fetch_name());

			fp=fopen("appamma.txt","r");
			//fptr=fopen("temp.txt","a");


			if(fp==NULL)

			{
				printf("no file exists by such name");
				//fclose(fp);
				//fclose(fptr);
				//remove("appamma.txt");
				//rename("temp.txt","appamma.txt");
			}

			else
			{
				fptr=fopen("temp.txt","a");
				while(!feof(fp))
				{
					//Scanning each employee data at a time from the database
					fscanf(fp,"%d %d ",&e.slno,&e.psno);
					fgets(e.name,20,fp);
					fscanf(fp,"%d %d %d %d ",&e.age,&e.salary,&e.year,&e.exp);

					for(i=0;i<19;i++)
					{
						if((e.name[i]==' ')&&(e.name[i+1]==' ')&&(e.name[i+2]==' '))
						{ //Inserting NULL character at the end of the name
							e.name[i]='\0';
							break;
						}
					}
					if((strcmp(e.name,name1))!=0)
					{  //If the comparison is not true,the employee data is written to new file.
						//i.e; the detail which should not be omitted is written in temp file.
						fprintf(fptr,"\n%-2d %-10d %-20s %-2d %-10d %-4d %-2d ",e.slno,e.psno,e.name,e.age,e.salary,e.year,e.exp);
					}
					else
					{
						check1=1;
						printf("\n**********************************************************************\n");

						printf("\n!!!! Deleted successfully!!!!\n");
						printf("\n**********************************************************************\n");

					}
				}
				fclose(fp);
				fclose(fptr);
				remove("appamma.txt");
				rename("temp.txt","appamma.txt");

			}

			//fclose(fp);
			//fclose(fptr);
			//remove("appamma.txt");
			//rename("temp.txt","appamma.txt");

		}


		else if((ch=='p')||(ch='P'))
		{
			printf("\nenter the PSNO to be deleted: ");
			psno1=fetch3_number();



			fp=fopen("appamma.txt","r");
			//fptr=fopen("temp.txt","a");

			if(fp==NULL)
			{
				printf("\n no file exists by such name\n");
				//fclose(fp);
				//fclose(fptr);
				//remove("appamma.txt");
		       //rename("temp.txt","appamma.txt");

			}
			else
			{
				fptr=fopen("temp.txt","a");
				while(!feof(fp))
				{

					fscanf(fp,"%d %d ",&e.slno,&e.psno);
					fgets(e.name,20,fp);
					fscanf(fp,"%d %d %d %d ",&e.age,&e.salary,&e.year,&e.exp);

					if(psno1!=e.psno)
					{
						fprintf(fptr,"\n%-2d %-10d %-20s %-2d %-10d %-4d %-2d ",e.slno,e.psno,e.name,e.age,e.salary,e.year,e.exp);
					}
					else
					{
						check1=1;
						printf("\n**********************************************************************\n");

						printf("\n!!!! Deleted successfully!!!!\n");
						printf("\n**********************************************************************\n");

					}
				}
				fclose(fp);
				fclose(fptr);
				remove("appamma.txt");
				rename("temp.txt","appamma.txt");

			}

			//fclose(fp);
			//fclose(fptr);
			//remove("appamma.txt");
			//rename("tempfile.txt","appamma.txt");

		}

		if(check1!=1)
		{
			printf("\n\n The details of this employee not found .");
		}
		printf("\n\nDo you want to delete another detail(y/n)?: ");
		fflush(stdin);
		del=get1_char();
	}while(((del=='y')||(del=='Y'))==1);



}

void clear()
{
while(begg1)
		{
			point=begg1->next;
			free(begg1);
			begg1=point;
		}

		while(begg2)
		{
			point=begg2->next;
			free(begg2);
			begg2=point;
		}

		while(begg3)
		{
			point=begg3->next;
			free(begg3);
			begg3=point;
		}

		while(begg4)
		{
			point=begg4->next;
			free(begg4);
			begg4=point;
		}
}

/*
 ============================================================================
 Name:display()
 Description :The function display()displays the details of an employee
 from the database.

 ============================================================================
 */
void display()
{
	int flag_display=0;
	int slno1=0,slno2=0,slno3=0,slno4=0;
	struct empdetail *disp1,*disp2,*disp3,*disp4;
	disp1=begg1;
	disp2=begg2;
	disp3=begg3;
	disp4=begg4;

	printf("\nSL  PSNO           NAME            AGE SALARY    YEAR EXP\n");
	printf(".........................................................................");
	while(disp1)
	{   //counting the number of employee in 2010
		slno1++;
		//printf("\n.................................................");
		//printf("\SLNO PSNO  NAME       AGE   SALARY  YEAR   EXPERIENCE");
		printf("\n%-2d %-10d %20s %-2d %-10d %-4d %-2d",slno1,disp1->psno,disp1->name,disp1->age,disp1->salary,disp1->year,disp1->exp);
		disp1=disp1->next;
	}
	printf("\n\n**********************************************************************************************\n\n");
	while(disp2)
		//counting the number of employee in 2011
	{     slno2++;
	//printf("\n.................................................");
	printf("\n%-2d %-10d %20s %-2d %-10d %-4d %-2d",slno2,disp2->psno,disp2->name,disp2->age,disp2->salary,disp2->year,disp2->exp);
	disp2=disp2->next;
	}
	printf("\n\n**********************************************************************************************\n\n");
	while(disp3)
		//counting the number of employee in 2012
	{     slno3++;
	//printf("\n.................................................");
	printf("\n%-2d %-10d %20s %-2d %-10d %-4d %-2d",slno3,disp3->psno,disp3->name,disp3->age,disp3->salary,disp3->year,disp3->exp);
	disp3=disp3->next;
	}
	printf("\n\n**********************************************************************************************\n\n");
	while(disp4)
	{   //counting the number of employee in other years other than 2010,2011 & 2012
		slno4++;
		if(flag_display==0)
		{
			printf("\n\n........................................................................\n\n");
			printf("\n\n..........Database of employee other than 2010/2011/2012.......................\n\n");
			printf("\nSL  PSNO           NAME            AGE SALARY    YEAR EXP\n");
			flag_display=1;
		}
		//printf("\n.................................................");
		printf("\n%-2d %-10d %20s %-2d %-10d %-4d %-2d",slno4,disp4->psno,disp4->name,disp4->age,disp4->salary,disp4->year,disp4->exp);
		disp4=disp4->next;
	}
	clear();
}

/*
 ============================================================================
 Name:name_modify()
 Description :The function name_modify() helps in modifying the detail of an
 employee in the database based on his name.
 ============================================================================
 */
void name_modify()
{

	int i=0,flag_nm=0;
	char nameM[20];
	FILE *fp,*fptr;
	printf("\nenter the name of the employee to be modified: ");
	fflush(stdin);
	strcpy(nameM,fetch_name());
	fp=fopen("appamma.txt","r");
	fptr=fopen("temp.txt","a");
	if(fp==NULL)
	{
		printf("file does not exists");
		//break;
	}
	else
	{
	while(!feof(fp))
	{


		fscanf(fp,"%d %d ",&e.slno,&e.psno);
		fgets(e.name,20,fp);
		fscanf(fp,"%d %d %d %d ",&e.age,&e.salary,&e.year,&e.exp);
		for(i=0;i<19;i++)
		{   //Making the last character of name as NULL in the string
			if((e.name[i]==' ')&&(e.name[i+1]==' ')&&(e.name[i+2]==' '))
			{
				e.name[i]='\0';
			}
		}
		if(strcmp(e.name,nameM)==0)

		{
			flag_nm=1;
			printf("\n**********************************************************************\n");

			printf("\n\nPSNO           NAME             AGE SALARY    YEAR EXP\n\n");

			printf("\n%-10d %-20s %-2d %-10d %-4d %-2d",e.psno,e.name,e.age,e.salary,e.year,e.exp);

			printf("\n**********************************************************************\n");


			printf("\nenter the new psno: ");
			e.psno=fetch3_number();
			printf("\nenter the new name: ");
			strcpy(e.name,fetch_name());

			printf("\nenter the present age: ");
			e.age=fetch_agenumber();
			printf("\nenter the revised salary: ");
			e.salary=fetch_salary();
			printf("\nenter the current year: ");
			e.year=fetch_yearnum();
			printf("\nenter the present experience: ");
			e.exp=fetch_exp();
			printf("\n!!!!!modified successfully!!!!\n");
			//Writing the modified name into the temporary file.
			fprintf(fptr,"\n%-2d %-10d %-20s %-2d %-10d %-4d %-2d",e.slno,e.psno,e.name,e.age,e.salary,e.year,e.exp);

		}
		else
		{
			//Writing the unmodified name into the temporary file.
			fprintf(fptr,"\n%-2d %-10d %-20s %-2d %-10d %-4d %-2d",e.slno,e.psno,e.name,e.age,e.salary,e.year,e.exp);
		}

	}
	}
	fclose(fp);
	fclose(fptr);
	remove("appamma.txt");
	rename("temp.txt","appamma.txt");
	if(flag_nm==0)
	{
		printf("\n**********************************************************************\n");

		printf("\n\nNo employee with this detail found\n\n");
		printf("\n**********************************************************************\n");

	}
}
/*
 ============================================================================
 Name:psno_modify()
 Description :The function name_modify() helps in modifying the detail of an
 employee in the database based on his psno.
 ============================================================================
 */
void psno_modify()


{


	FILE *fp,*fptr;
	int psno1;
	//char sel;
	int flag_np=0;
	//do
	//{
	printf("\n\nenter the psno of the employee to be modified: ");

	psno1=fetch3_number();
	fp=fopen("appamma.txt","r");
	fptr=fopen("temp.txt","a");
	if(fp==NULL)
	{
		printf("file does not exists");
		//break;

	}
	else
	{
		while(!feof(fp))
		{
			fscanf(fp,"%d %d ",&e.slno,&e.psno);
			fgets(e.name,20,fp);
			fscanf(fp,"%d %d %d %d ",&e.age,&e.salary,&e.year,&e.exp);

			if(psno1==e.psno)

			{

				printf("\n**************************************************************************\n");

				printf("\n\nPSNO           NAME             AGE SALARY    YEAR EXP\n\n");
				printf("\n%-10d %-20s %-2d %-10d %-4d %-2d",e.psno,e.name,e.age,e.salary,e.year,e.exp);
				printf("\n**************************************************************************\n");



				printf("\nenter the new psno: ");
				e.psno=fetch3_number();
				printf("\nenter the new name: ");
				fflush(stdin);
				strcpy(e.name,fetch_name());
				printf("\nenter the present age: ");
				e.age=fetch_agenumber();;
				printf("\nenter the revised salary: ");
				e.salary=fetch_salary();
				printf("\nenter the current year: ");
				e.year=fetch_yearnum();
				printf("\nenter the present experience: ");
				e.exp=fetch_exp();
				fprintf(fptr,"\n%-2d %-10d %-20s %-2d %-10d %-4d %-2d",e.slno,e.psno,e.name,e.age,e.salary,e.year,e.exp);

				printf("\n**********************************************************************\n");

				printf("\n!!!!!modified successfully!!!!\n");
				printf("\n**********************************************************************\n");

				flag_np=1;
			}
			else
			{
				fprintf(fptr,"\n%-2d %-10d %-20s %-2d %-10d %-4d %-2d",e.slno,e.psno,e.name,e.age,e.salary,e.year,e.exp);
			}
		}
	}
	fclose(fp);
	fclose(fptr);
	remove("appamma.txt");
	rename("temp.txt","appamma.txt");
	if(flag_np==0)
	{
		printf("\n\nNo employee with this detail found\n\n");
	}
}



/*
 ============================================================================
 Name:modify_fun()
 Description :The function name_modify() uses swith case to swith between
 name_modify() & psno_modify functions.

 ============================================================================
 */

void modify_fun()
{
	int choice;
	char select;

	printf("\nDo you want to modify the data based on  1.)Name    2.)Psno\n");
	printf("\npress 1 to modify based on employee name: \n");
	printf("\npress 2 to modify based on employee psno: \n");
	choice=fetch2_number();
	do
	{
		switch(choice)
		{
		case 1:
			name_modify();

			break;
		case 2:
			psno_modify();
			break;
		default:printf("Invalid choice");


		}
		printf("\n\ndo you want to modify another employee detail(y/n): ");
		fflush(stdin);
		select=get1_char();

	} while(select=='y'||select=='Y');
}

/*
 ============================================================================
 Name:searchemployee_data()
 Description :The function searchemployee_data() helps in searching an employee
 detail based on his psno,name,age,year & salary.

 ============================================================================
 */
void searchemployee_data()

{
	int psno,flag=0,i=0,Age,Year,range;
	char nameS[20],ch;
	FILE *fp;
	int choice;
	do
	{

		printf("select the below choice number  based on which you want to search the employee data\n");
		printf("Choice 1: psno\n");
		printf("Choice 2: name\n");
		printf("Choice 3: age\n");
		printf("Choice 4: year\n");
		printf("Choice 5: salary\n");
		fflush(stdin);
		choice=fetch1_number();
		if(choice==1)
		{
			flag=0;

			printf("\nenter the psno of the employee to be searched: ");
			psno=fetch3_number();
			fp=fopen("appamma.txt","r");
			if(fp==NULL)


			{
				printf("no file exists under such name");
			}
			else
			{

				while(!feof(fp))
				{

					fscanf(fp,"%d %d ",&e.slno,&e.psno);
					fgets(e.name,20,fp);
					fscanf(fp,"%d %d %d %d ",&e.age,&e.salary,&e.year,&e.exp);
					if(e.psno==psno)
					{
						printf("\n**********************************************************************\n");

						printf("\nthe employee with psno:%d is\n",e.psno);
						printf("\n**********************************************************************\n");

						printf("\n\nPSNO           NAME             AGE SALARY    YEAR EXP\n\n");
						printf("\n%-10d %-20s %-2d %-10d %-4d %-2d",e.psno,e.name,e.age,e.salary,e.year,e.exp);
						flag=1;
					}


				}
				fclose(fp);
			}
			if(flag==0)
			{
				printf("\nNo employee with this PSNO found");
			}
			//fclose(fp);


		}
		else if(choice==2)
		{
			flag=0;
			printf("\nenter the name of the employee to be searched: ");
			strcpy(nameS,fetch_name());

			fp=fopen("appamma.txt","r");
			if(fp==NULL)
			{
				printf("no file exists under such name");
			}
			else
			{
			while(!feof(fp))
			{


				fscanf(fp,"%d %d ",&e.slno,&e.psno);
				fgets(e.name,20,fp);
				fscanf(fp,"%d %d %d %d ",&e.age,&e.salary,&e.year,&e.exp);
				for(i=0;i<19;i++)
				{
					if((e.name[i]==' ')&&(e.name[i+1]==' ')&&(e.name[i+2]==' '))
					{
						e.name[i]='\0';
					}

				}


				if(strcmp(e.name,nameS)==0)
				{
					printf("\n**********************************************************************\n");

					printf("\nthe employee with name:%s is",e.name);
					printf("\n**********************************************************************\n");

					printf("\n\nPSNO           NAME             AGE SALARY    YEAR EXP\n\n");
					printf("\n%-10d %-20s %-2d %-10d %-4d %-2d",e.psno,e.name,e.age,e.salary,e.year,e.exp);
					flag=1;
				}

			}
			fclose(fp);
			}
			if(flag==0)
			{
				printf("\nNo employee with this name found\n");
			}
			//fclose(fp);



		}
		else if(choice==3)
		{
			flag=0;
			printf("\nenter the age of the employee to be searched: ");
			Age=fetch_agenumber();
			fp=fopen("appamma.txt","r");
			if(fp==NULL)


			{
				printf("\nno file exists under such name\n");
			}

			else
			{

			while(!feof(fp))
			{

				fscanf(fp,"%d %d ",&e.slno,&e.psno);
				fgets(e.name,20,fp);
				fscanf(fp,"%d %d %d %d ",&e.age,&e.salary,&e.year,&e.exp);
				if(e.age==Age)
				{
					printf("\n**********************************************************************\n");

					printf("\nthe employee with age:%d is",e.age);
					printf("\n**********************************************************************\n");

					printf("\n\nPSNO           NAME             AGE SALARY    YEAR EXP\n\n");
					printf("\n%-10d %-20s %-2d %-10d %-4d %-2d",e.psno,e.name,e.age,e.salary,e.year,e.exp);
					flag=1;
				}

			}
			fclose(fp);
			}
			if(flag==0)
			{
				printf("No employee with this age found");
			}
			//fclose(fp);



		}
		else if(choice==4)
		{
			flag=0;
			printf("\n enter the joining year of the employee to be searched: ");
			Year=fetch_yearnum();
			fp=fopen("appamma.txt","r");
			if(fp==NULL)
			{
				printf("\nno file exists under such name\n");
			}

			else
			{
			while(!feof(fp))
			{

				fscanf(fp,"%d %d ",&e.slno,&e.psno);
				fgets(e.name,20,fp);
				fscanf(fp,"%d %d %d %d ",&e.age,&e.salary,&e.year,&e.exp);
				if(e.year==Year)
				{
					printf("\n**********************************************************************\n");

					printf("\n the employee with the joining year:%d is",e.year);
					printf("\n**********************************************************************\n");

					printf("\n\nPSNO           NAME             AGE SALARY    YEAR EXP\n\n");
					printf("\n %-10d %-20s %-2d %-10d %-4d %-2d",e.psno,e.name,e.age,e.salary,e.year,e.exp);
					flag=1;
				}

			}
			fclose(fp);

			}
			if(flag==0)
			{
				printf("\nNo employee with this joining year found\n");
			}
			//fclose(fp);



		}





		else if(choice==5)
		{


			printf("select the below range number  based on which you want to search the employee data\n");
			printf("range 1: above 3 lakh but less than 4 lakh\n");
			printf("range 2: above 4 lakh but less than 5 lakh\n");
			printf("range 3: above 5 lakh but less than 8 lakh\n");
			printf("range 4: above 8 lakh but less than 10 lakh\n");
			printf("range 5: above 10 lakh \n");
			fflush(stdin);
			printf("enter the range value");
			range=fetch1_number();
			fp=fopen("appamma.txt","r");
			if(fp==NULL)
			{
				printf("\n no file exists under such name");
			}
			flag=0;


			printf("\n**********************************************************************\n");

			printf("\nthe employee with the salary  is");
			printf("\n**********************************************************************\n");
			printf("\nPSNO       NAME                 AGE SALARY    YEAR EXP\n");

			while(!feof(fp))
			{
				fscanf(fp,"%d %d ",&e.slno,&e.psno);
				fgets(e.name,20,fp);
				fscanf(fp,"%d %d %d %d ",&e.age,&e.salary,&e.year,&e.exp);

				if(range==1)
				{
					if((e.salary<400000)&&(e.salary>=300000))
					{
						printf("\n**********************************************************************\n");

						//printf("\nPSNO       NAME                 AGE SALARY    YEAR EXP\n");
						printf("\n%-10d %-20s %-2d %-10d %-4d %-2d",e.psno,e.name,e.age,e.salary,e.year,e.exp);
						printf("\n**********************************************************************\n");

						flag=1;

					}
				}


				if(range==2)
				{
					if((e.salary<=500000)&&(e.salary>=400000))
					{
						printf("\n**********************************************************************\n");

						//printf("\nPSNO       NAME                AGE SALARY    YEAR EXP\n");
						printf("\n%-10d %-20s %-2d %-10d %-4d %-2d",e.psno,e.name,e.age,e.salary,e.year,e.exp);
						printf("\n**********************************************************************\n");

						flag=1;

					}
				}



				if(range==3)
				{
					if((e.salary<=800000)&&(e.salary>=500001))
					{ 	printf("\n**********************************************************************\n");

					//printf("\n\nPSNO        NAME                AGE SALARY    YEAR EXP\n\n");
					printf("\n%-10d %-20s %-2d %-10d %-4d %-2d",e.psno,e.name,e.age,e.salary,e.year,e.exp);
					printf("\n**********************************************************************\n");

					flag=1;

					}

				}

				if(range==4)
				{
					if((e.salary<=1000000)&&(e.salary>=800001))
					{
						printf("\n**********************************************************************\n");

						//printf("\nPSNO      NAME                  AGE SALARY    YEAR EXP\n");
						printf("\n%-10d %-20s %-2d %-10d %-4d %-2d",e.psno,e.name,e.age,e.salary,e.year,e.exp);
						printf("\n**********************************************************************\n");

						flag=1;

					}


				}

				if(range==5)
				{
					if((e.salary>=1000001))
					{
						printf("\n**********************************************************************\n");

						//printf("\nPSNO       NAME                AGE SALARY    YEAR EXP\n");
						printf("\n%-10d %-20s %-2d %-10d %-4d %-2d",e.psno,e.name,e.age,e.salary,e.year,e.exp);
						printf("\n**********************************************************************\n");

						flag=1;

					}


				}

			}

			if(flag==0)
			{
				printf("\nNo salary of an employee is found in this range\n");
			}

			fclose(fp);


		}




		else
			printf("invalid entry");
		printf("\n\n Do you want to continue searching(y/n): ");
		fflush(stdin);
		ch=get1_char();
	} while(ch=='y'||ch=='Y');


}

/*
 ============================================================================
 Name:percentage_hike()
 Description :The function percentage_hike() calculates the hike or reduce in
 the salary of an employee between any two consecutive years.


 ============================================================================
 */
void percentage_hike()

{

	int psno3,yprevious,y,salary_present,salary_previous,flag=0,flag2=0;
	float result,result1;
	FILE *fp;
	char choic;

	do
	{
		flag=0;
		flag2=0;
		printf("\n enter the psno of the employee to find the percentage hike in salary: ");
		psno3=fetch3_number();
		printf("\n Enter the year: ");
		y=fetch_yearnum();
		fp=fopen("appamma.txt","r");
		if(fp==NULL)
		{
			printf("The intended file does not exists");
		}
		else
		{
			while(!feof(fp))
			{

				fscanf(fp,"%d %d",&e3.slno,&e3.psno);
				fgets(e3.name,20,fp);
				fscanf(fp,"%d %d %d %d ",&e3.age,&e3.salary,&e3.year,&e3.exp);
				if(((psno3==e3.psno)&&(y==e3.year)))
				{
					salary_present=e3.salary;
					yprevious=y-1;
					flag=1;
					break;

				}
			}
			fclose(fp);
			fp=fopen("appamma.txt","r");
			if(flag==1)
			{
				while(!feof(fp))
				{

					fscanf(fp,"%d %d",&e3.slno,&e3.psno);
					fgets(e3.name,20,fp);
					fscanf(fp,"%d %d %d %d ",&e3.age,&e3.salary,&e3.year,&e3.exp);
					if(((psno3==e3.psno)&&(yprevious==e3.year)))
					{
						salary_previous=e3.salary;
						flag2=1;
						break;


					}
				}
				fclose(fp);
				if((flag==1)&&(flag2==1))
				{
					result=(salary_present-salary_previous);
					result1=((result)/(salary_previous))*100;

					printf("\n**********************************************************************\n");

					printf("\n%s percentage hike or reduce  is %f percent:",e3.name,result1);
					printf("\n**********************************************************************\n");

				}
			}

			if((flag==0)||(flag2==0))
			{
				printf("\nThe result not found for this employee\n");

			}


		}
		printf("\nDo you want to continue to calculate the  hike(y/n)?: ");
		fflush(stdin);
		choic=get1_char();
	}  while((choic=='y')||(choic=='Y'));
}


/*
 ============================================================================
 Name:display1()
 Description :The function display1()displays the details of an employee
 from the database.

 ============================================================================
 */

void display1()
{
	int flag_display=0;
	int slno1=0,slno2=0,slno3=0,slno4=0;
	struct empdetail *disp1,*disp2,*disp3,*disp4;
	disp1=begg1;
	disp2=begg2;
	disp3=begg3;
	disp4=begg4;

	printf("\nSL  PSNO           NAME            AGE SALARY    YEAR EXP\n\n");
	printf("\n\n**********************************************************************************************\n\n");
	while(disp1)
	{
		slno1++;
		//printf("\n.................................................");
		//printf("\SLNO PSNO  NAME       AGE   SALARY  YEAR   EXPERIENCE");
		printf("\n%-2d %-10d %20s %-2d %-10d %-4d %-2d",slno1,disp1->psno,disp1->name,disp1->age,disp1->salary,disp1->year,disp1->exp);
		disp1=disp1->next;
	}

	printf("\n\n**********************************************************************************************\n\n");
	while(disp2)
	{     slno2++;
	//printf("\n.................................................");
	printf("\n%-2d %-10d %20s %-2d %-10d %-4d %-2d",slno2,disp2->psno,disp2->name,disp2->age,disp2->salary,disp2->year,disp2->exp);
	disp2=disp2->next;
	}
	printf("\n\n**********************************************************************************************\n\n");
	while(disp3)

	{     slno3++;
	//printf("\n.................................................");
	printf("\n%-2d %-10d %20s %-2d %-10d %-4d %-2d",slno3,disp3->psno,disp3->name,disp3->age,disp3->salary,disp3->year,disp3->exp);
	disp3=disp3->next;
	}
	printf("\n\n**********************************************************************************************\n\n");
	while(disp4)
	{
		slno4++;
		if(flag_display==0)
		{
			printf("\n\n........................................................................\n\n");
			printf("\n\n..........Database of employee other than 2010/2011/2012.......................\n\n");
			printf("\n**********************************************************************\n");

			printf("\nSL  PSNO           NAME            AGE SALARY    YEAR EXP\n");
			flag_display=1;
		}
		//printf("\n.................................................");
		printf("\n%-2d %-10d %20s %-2d %-10d %-4d %-2d",slno4,disp4->psno,disp4->name,disp4->age,disp4->salary,disp4->year,disp4->exp);
		disp4=disp4->next;
	}
}

/*
 ============================================================================
 Name:escapeto_new()
 Description :The function escapeto_new interchanges the record between two
 years 2010 & 2012.


 ============================================================================
 */

void swap_new()
{


	struct empdetail *temprec1,*temprec2;
	int temp_slno,temp_psno,temp_age,temp_salary,temp_year,temp_exp;
	temprec1=begg1;
	temprec2=begg2;
	printf("%d %d",m,n);

	if(m==n)
	{
		while(temprec1)
		{
			temp_slno=temprec1->slno;
			temp_psno=temprec1->psno;
			temp_age=temprec1->age;
			temp_salary=temprec1->salary;
			temp_year=temprec1->year;
			temp_exp=temprec1->exp;

			temprec1->slno=temprec2->slno;
			temprec1->psno=temprec2->psno;
			temprec1->age=temprec2->age;
			temprec1->salary=temprec2->salary;
			temprec1->year=temprec2->year;
			temprec1->exp=temprec2->exp;

			temprec2->slno=temp_slno;
			temprec2->psno=temp_psno;
			temprec2->age=temp_age;
			temprec2->salary=temp_salary;
			temprec2->year=temp_year;
			temprec2->exp=temp_exp;

			temprec1=temprec1->next;
			temprec2=temprec2->next;

		}

		display1();
	}

	else
	{
		printf("\n\n Cannot swap as the counts are not same in 2010 & 2011\n\n");
	}

}

/*
 ============================================================================
 Name:interchange_record()
 Description :The function interchange_record() creates links for years
 2010 & 2012 separately.



 ============================================================================
 */


void interchange_record()
{

	FILE *fp;
	int count1_2010=0,count1_2011=0;
	struct empdetail *New;
	begg1=NULL;
	start1=NULL;
	begg2=NULL;
	start2=NULL;


	fp=fopen("appamma.txt","r");
	if(fp==NULL)
	{
		printf("\nSorry no data exists");
	}
	else
	{
		while(!feof(fp))
		{
			fscanf(fp,"%d %d",&e1.slno,&e1.psno);
			fgets(e1.name,20,fp);
			fscanf(fp,"%d %d %d %d ",&e1.age,&e1.salary,&e1.year,&e1.exp);

			if(e1.year==2010)
			{
				New=create();
				if(start1==NULL)
				{
					start1=New;
					begg1=New;
				}
				else
				{
					start1->next=New;
					start1=New;
				}
				count1_2010=count1_2010+1;
			}
			else if(e1.year==2011)
			{
				New=create();
				if(start2==NULL)
				{
					start2=New;
					begg2=New;
				}
				else
				{
					start2->next=New;
					start2=New;
				}
				count1_2011=count1_2011+1;
			}
		}




	}
	fclose(fp);
	m=count1_2010;
	n=count1_2011;
	sorting_name(count1_2010,begg1);
	sorting_name(count1_2011,begg2);
	swap_new();
	//getch();

}


/*
 ============================================================================
 Name:Access_history()
 Description :The function access_history()  creates a log-file for the entry
 into the database.




 ============================================================================
 */

void Access_history(int a)
{

	FILE *fp;
	time (&currentime);

	if (history_flag==0)
	{
		if(a==1)

		{
			fp=fopen("India.txt","a");
			fprintf(fp,"The employee database was viewed by system administrator @:  ");
			fprintf(fp,"%s",ctime(&currentime));
			fprintf(fp,"___________________________________________________________________\n");
			fclose(fp);
		}

		else if(a==2)
		{

			fp=fopen("India.txt","a");
			fprintf(fp,"The employee database was searched by system administrator @:  ");
			fprintf(fp,"%s",ctime(&currentime));
			fprintf(fp,"___________________________________________________________________\n");
			fclose(fp);


		}
		else if(a==3)
		{
			fp=fopen("India.txt","a");
			fprintf(fp,"The employee database was modified by system administrator @:  ") ;
			fprintf(fp,"%s",ctime(&currentime));
			fprintf(fp,"___________________________________________________________________\n");
			fclose(fp);

		}

		else if(a==4)
		{

			fp=fopen("India.txt","a");
			fprintf(fp,"The employee database was deleted by system administrator @:  ") ;
			fprintf(fp,"%s",ctime(&currentime));
			fprintf(fp,"___________________________________________________________________\n");
			fclose(fp);

		}

		else if(a==5)
		{

			fp=fopen("India.txt","a");
			fprintf(fp,"The employee database was appended by system administrator @:  ") ;
			fprintf(fp,"%s",ctime(&currentime));
			fprintf(fp,"___________________________________________________________________\n");
			fclose(fp);

		}

		else if(a==6)
		{

			fp=fopen("India.txt","a");
			fprintf(fp,"The percentage hike in salary of an employee was done by system administrator @:  ") ;
			fprintf(fp,"%s",ctime(&currentime));
			fprintf(fp,"___________________________________________________________________\n");
			fclose(fp);

		}


	}
	else if(history_flag==1)
	{

		if(a==1)

		{

			fp=fopen("India.txt","a");
			fprintf(fp,"The database was viewed by %s with PSNO %d\n ",e2.name,e2.psno);
			fprintf(fp,"The database was  viewed @:  ") ;
			fprintf(fp,"%s",ctime(&currentime));
			fprintf(fp,"_____________________________________________________________________\n");
			fclose(fp);
		}

		if(a==2)

		{

			fp=fopen("India.txt","a");
			fprintf(fp,"The database was searched by %s with PSNO %d\n ",e2.name,e2.psno);
			fprintf(fp,"The database was searched @:  ") ;
			fprintf(fp,"%s",ctime(&currentime));
			fprintf(fp,"_____________________________________________________________________\n");
			fclose(fp);
		}

		if(a==3)

		{

			fp=fopen("India.txt","a");
			fprintf(fp,"The database was modified by %s with PSNO %d\n ",e2.name,e2.psno);
			fprintf(fp,"The database was  modified @:  ") ;
			fprintf(fp,"%s",ctime(&currentime));
			fprintf(fp,"_____________________________________________________________________\n");
			fclose(fp);
		}

		if(a==4)

		{

			fp=fopen("India.txt","a");
			fprintf(fp,"The database was deleted by %s with PSNO %d\n ",e2.name,e2.psno);
			fprintf(fp,"The database was deleted @:  ") ;
			fprintf(fp,"%s",ctime (&currentime));
			fprintf(fp,"_____________________________________________________________________\n");
			fclose(fp);
		}

		if(a==5)

		{

			fp=fopen("India.txt","a");
			fprintf(fp,"The database was appended  by %s with PSNO %d\n ",e2.name,e2.psno);
			fprintf(fp,"The database was appended @:  ") ;
			fprintf(fp,"%s",ctime (&currentime));
			fprintf(fp,"_____________________________________________________________________\n");
			fclose(fp);
		}

		if(a==6)

		{

			fp=fopen("India.txt","a");
			fprintf(fp,"The hike in salary of an employee was searched by %s with PSNO %d\n ",e2.name,e2.psno);
			fprintf(fp,"The database was  viewed @:  ") ;
			fprintf(fp,"%s",ctime (&currentime));
			fprintf(fp,"_____________________________________________________________________\n");
			fclose(fp);
		}









	}

}

/*
 ============================================================================
 Name:exit_function)
 Description :The function exit_function() helps an database user to exit
 from the database page.




 ============================================================================
 */
void exit_function()
{

	printf("\nTHANK YOU\n");
	printf("\n**********************************************************************\n");
	getch();
	exit(0);
}



void menu()
{
	int choice;
	char ch;
	do
	{
		printf("\n\n********************MENU************************************************\n\n");
		printf("\n Enter your choice to:- \n");
		printf("\n**********************************************************************\n");

		printf("\n1:Display the database of the employee & also see the database in sorted order\n");
		printf("\n2:Search the record in the database\n");
		printf("\n3:Modify the record in the database\n");
		printf("\n4:Delete the record in the database\n");
		printf("\n5:Append a record in the database\n");
		printf("\n6:Calculate the percentage increase in salary\n");
		printf("\n7:To interchange the record for 2011 & 2012\n");
		printf("\n8:To exit from the database\n");
		printf("\n**********************************************************************\n");


		choice=fetch_number();
		if(choice==1)
		{

			yearwisenode();
			printf("\n\n**********************************************************************\n\n");
			display();



			printf("\n\n**********************************************************************\n\n");
			Access_history(1);
		}
		else if(choice==2)
		{
			printf("\n\n**********************************************************************\n\n");
			searchemployee_data();
			printf("\n\n**********************************************************************\n\n");
			Access_history(2);

		}
		else if(choice==3)
		{
			printf("\n\n**********************************************************************\n\n");
			modify_fun();
			printf("\n\n***********************************************************************n\n");
			Access_history(3);

		}
		else if(choice==4)
		{
			printf("\n\n**********************************************************************\n\n");
			delete_fun();
			printf("\n\n**********************************************************************\n\n");
			Access_history(4);

		}
		else if(choice==5)
		{
			printf("\n\n*********************************************************************\n\n");
			append();
			printf("\n\n*********************************************************************\n\n");
			Access_history(5);

		}
		else if(choice==6)
		{
			printf("\n\n**********************************************************************\n\n");
			percentage_hike();
			printf("\n\n*********************************************************************8\n\n");
			Access_history(6);

		}

		else if(choice==7)
		{
			printf("\n\n**********************************************************************\n\n");
			interchange_record();

			printf("\n\n*********************************************************************8\n\n");
			Access_history(6);

		}
		else if(choice==8)
		{
			printf("\n\n**********************************************************************\n\n");
			exit_function();
			printf("\n\n**********************************************************************\n\n");


		}
		else
		{
			printf("\n\n WRONG INPUT please enter correct choice\n\n");
		}

		printf("\n\n Do you want to continue to access the database (y/n)?: ");
		fflush(stdin);
		ch=get1_char();

	}while((ch=='y')||(ch=='Y'));

}

/*
 ============================================================================
 Name:firewall()
 Description :The function firewall() checks whether the user is an system
 administrator or an employee & allows for successful access of database based
 on correct password,otherwise rejected & finally blocked.

 ============================================================================
 */


void firewall()
{
	char choice;
	int security_m=123456;
	int security=0;
	char sel;
	int count1=4,flag1=0;

	FILE *fp;
	do
	{
		printf("\n Do you want to enter as an system administrator or as an employee ...?\n");
		printf("\n**********************************************************************\n");

		printf(" \nselect A for system administrator access & E for employee access:   ");
		printf("\n**********************************************************************\n");

		fflush(stdin);
		choice=get_char();
		if((choice=='a')||(choice=='A'))
		{


			printf("\nEnter the system administrator password:  ");
			scanf("%d",&security);
			if(security==security_m)
			{
				printf("\n\n!!!!!! login successful as system administrator!!!!!!\n\n");
				history_flag=0;
				menu();
				exit(0);
			}
			count1--;
		}

		else if((choice=='e')||(choice=='E'))
		{

			printf("\n enter the employee psno: ");
			scanf("%d",&PSNO);

			fp=fopen("appamma.txt","r");
			if(fp==NULL)
			{

				printf("\nNo file exists\n");
			}
			else
			{
				while(!feof(fp))
				{

					fscanf(fp,"%d %d",&e2.slno,&e2.psno);
					fgets(e2.name,20,fp);
					fscanf(fp,"%d %d %d %d ",&e2.age,&e2.salary,&e2.year,&e2.exp);

					if(e2.psno==PSNO)

					{
						printf("\n\n!!!!!!login successful as an employee!!!!!!!\n\n");
						flag1=1;
						break;

					}


				}
				count1--;
			}
			fclose(fp);


		}
		if(flag1==1)
		{
			history_flag=1;
			menu();
			exit(0);
		}
		else
		{
			printf("\nYou entered wrong password you have %d chance left\n",count1);
		}
		printf("Do you want to continue?(Y/N)?: ");
		fflush(stdin);
		sel=get1_char();
		if(count1==0)
		{
			printf("\n**********************************************************************\n");

			printf("\nYou exceeded the limit you are blocked now\n");
			printf("\n**********************************************************************\n");

			break;
		}


	}while((sel=='y')||(sel=='Y'));
}









int main()
{
	printf("\n**********************************************************************\n");

	printf("\n\nWelcome to Database Management\n\n");
	printf("\n**********************************************************************\n");

	firewall();






	//getch();
	return 0;

}
