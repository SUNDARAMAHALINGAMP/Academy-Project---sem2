
#include<stdio.h>
#include<string.h>
typedef struct family_details
{
	char father_name[20];
	char f_phone[20];
	char mother_name[20];
	char m_phone[20]; 
	char wife_name[20];
}f;
struct record
{
	char id[30];
	char name[30];
	char age[10];
	char sex[10];
	char height[10];
	char weight[10];
	char crime[100];
	char conviction[100];
	char date[10];
	char p_duration[30];
	f fam;  
	
};
struct record v;
void view()
{
system("cls");
FILE *fp;
char p_name[30];
printf("\n\n\t\t***************************\n"); 
printf("\t\t * LIST OF PRISONERS *"); 
printf("\n\t\t***************************\n\n"); 
fp=fopen("prision.txt","rb"); 
rewind(fp); 
while((fread(&v,sizeof(v),1,fp))==1) 
{ 
   printf("\nYOUR OLD RECORD WAS AS:"); 
   printf("\nPRISIONER'S ID:",v.id);
   printf("\nPRISONER'S NAME: %s",v.name); 
   printf("\nPRISONER'S AGE: %s",v.age); 
   printf("\nPRISONER'S GENDER: %s",v.sex);
   printf("\nPRISONER'S HEIGHT: %s",v.height);  
   printf("\nPRISONER'S WEIGHT: %s",v.weight); 
   printf("\nPRISONER'S CRIME: %s",v.crime); 
   printf("\nPRISONER'S CONVICTION: %s",v.conviction); 
   printf("\nPRISONER'S PRISONED DATE:%s",v.date);
   printf("\nPRISONERS PUNISHMENT DURATION:%s",v.p_duration);
   printf("\nPRISONER'S FATHER NAME:%s",v.fam.father_name);
   printf("\nPRISONER'S FATHER'S PHONE NUMBER:%s",v.fam.f_phone);
   printf("\nPRISONER'S MOTHER NAME:%s",v.fam.mother_name);
   printf("\nPRISONER'S MOTHER'S PHONE NUMBER:%s",v.fam.m_phone);
   printf("\nPRISONER'S WIFE NAME:%s",v.fam.wife_name); 
 
 getch(); 
 printf("\n\n"); 
} 
fclose(fp); 
getch();
}

void add()
{
	
	FILE *fp;
	char anthr='Y';
	char id[30];
	char p_name[30];
	int options;
	printf("\n\tENTER THE NAME OF PRISONER:\t");
	fflush(stdin);
	gets(p_name);
	fp=fopen("prision.txt","ab+");
	if(fp==NULL)
	{
		fp=fopen("prision.txt","wb+");
		if(fp==NULL)
		{
		 printf("SYSTEM ERROR");
	    }
	}
	while(anthr=='Y'|| anthr=='y')
	{
		options=0;fflush(stdin);
		printf("\n\tENTER THE PRSONER ID:");
		gets(id);
		rewind(fp);
		while(fread(&v,sizeof(v),1,fp)==1)
		{
			if(strcmp(v.id,id)==0)
			{
				printf("\n\t RECORD ALREADY EXIST");
				options=1;
			}
		}
		if(options==0)
		{
			strcpy(v.id,id);
			printf("\n\tENTER THE NAME:");
			fflush(stdin);
			gets(v.name);
			printf("\n\tENTER THE AGE:");
			fflush(stdin);
			gets(v.age);
			
			printf("\n\tENTER THE SEX:");
			fflush(stdin);
			gets(v.sex);
			
			printf("\n\tENTER THE HEGHT:");
			fflush(stdin);
			gets(v.height);
			
			printf("\n\tENTER THE WIEGHT:");
			fflush(stdin);
			gets(v.weight);
			
			printf("\n\tENTER THE CRIME:");
			fflush(stdin);
			gets(v.crime);
			
			printf("\n\tENETER THE CONVICTION:");
			fflush(stdin);
			gets(v.conviction);
			
			printf("\n\tENTER THE ARRIVING DATE:");
			fflush(stdin);
			gets(v.date);
			
			printf("\n\tENTER THE PUNISHMENT DURATION:");
			fflush(stdin);
		    gets(v.p_duration);
		    printf("\n\tENTER THE FAMILY DEATAILS:");
		    printf("\n\tENTER THE FATHER NAME:");
		    fflush(stdin);
		    gets(v.fam.father_name);
		    printf("\n\tENTER THE FATHER PHONE NUMBER:");
		    fflush(stdin);
		    scanf("%s",v.fam.f_phone);
		    printf("\n\tENTER THE MOTHER NAME:");
		    fflush(stdin);
		    gets(v.fam.mother_name);
		    printf("\n\tENTER THE MOTHER PHONE NUMBER:");
		    fflush(stdin);
		    scanf("%s",v.fam.m_phone);
		    printf("\n\tENTER THE WIFE NAME:");
		    fflush(stdin);
		    scanf("%s",v.fam.wife_name);
		    
            fwrite(&v,sizeof(v),1,fp);
		    printf("\n\tYOUR RECORD IS ADDED...\n");
		    
			
		}
		printf("\n\tADD ANOTHER RECORD....(Y/N\t)");
		fflush(stdin);
		anthr=getch();
		
		
	}
	fclose(fp);
	printf("\n\tPRESS ANY KEY TO EXIT");
	getch();
	
}
void edit()
{
 system("cls");
 FILE *fp ; 
 char id[10],options,p_name[14]; 
 int nmber,counting=0; 
 printf("\n\n\t\t*******************************\n"); 
 printf("\t\t* WELCOME TO THE EDITING MENU *"); 
 printf("\n\t\t*******************************\n\n"); 
 do 
 { 
 printf("\n\tENTER THE PRISONER NAME TO BE EDITED:"); 
 fflush(stdin); 
 gets(p_name); 
 printf("\n\tENTER ID:"); 
 gets(id);
 fp = fopen("prision.txt","rb+"); 
 while ((fread(&v,sizeof(v),1, fp )== 1 )) 
 {
  if(strcmp(v.id,id)==0) 
  { 
   printf("\nYOUR OLD RECORD WAS AS:");
   printf("\nPRISONER'S NAME: %s",v.name); 
   printf("\nPRISONER'S AGE: %s",v.age); 
   printf("\nPRISONER'S GENDER: %s",v.sex);
   printf("\nPRISONER'S HEIGHT: %s",v.height);  
   printf("\nPRISONER'S WEIGHT: %s",v.weight); 
   printf("\nPRISONER'S CRIME: %s",v.crime); 
   printf("\nPRISONER'S CONVICTION: %s",v.conviction); 
   printf("\nPRISONER'S PRISONED DATE:%s",v.date);
   printf("\nPRISONERS PUNISHMENT DURATION:%s",v.p_duration);
   printf("\nPRISONER'S FATHER NAME:%s",v.fam.father_name);
   printf("\nPRISONER'S FATHER'S PHONE NUMBER:%s",v.fam.f_phone);
   printf("\nPRISONER'S MOTHER NAME:%s",v.fam.mother_name);
   printf("\nPRISONER'S MOTHER'S PHONE NUMBER:%s",v.fam.m_phone);
   printf("\nPRISONER'S WIFE NAME:%s",v.fam.wife_name);
   printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT.."); 
   printf("\n1.NAME."); 
   printf("\n2.AGE.");
   printf("\n3.GENDER.");  
   printf("\n4.HEIGHT.");
   printf("\n5.WEIGHT.");
   printf("\n6.CRIME.");
   printf("\n7.CONVICTION");
   printf("\n8.PRISONED DATE.");
   printf("\n9.PUNISHMENT DURATION.");
   printf("\n10.FATHER NAME.");
   printf("\n11.FATHER'S PHONE NUMBER.");
   printf("\n12.MOTHER NAME.");
   printf("\n13.MOTHER PHONE NUMBER.");
   printf("\n14.WIFE NAME."); 
   printf("\n15.WHOLE RECORD."); 
   printf("\n16.GO BACK TO MAIN MENU."); 
  do 
  { 
   printf("\n\tENTER YOUR CHOICE:"); 
   fflush(stdin); 
   scanf("%d",&nmber); 
   fflush(stdin); 
   switch(nmber) 
   { 
    case 1: printf("\nENTER THE NEW DATA:"); 
            printf("\nNAME:"); 
		    gets(v.name); 
		    break; 
    case 2: printf("\nENTER THE NEW DATA:"); 
            printf("\nAGE:"); 
		    scanf("%s",v.age); 
		    break; 
    case 3: printf("\nENTER THE NEW DATA:"); 
            printf("\nSEX:"); 
		    gets(v.sex); 
		    break; 
    case 4: printf("\nENTER THE NEW DATA:"); 
            printf("\nHEIGHT:"); 
		    scanf("%s",v.height); 
		    break; 
    case 5: printf("\nENTER THE NEW DATA:"); 
            printf("\nWEIGHT:"); 
		    scanf("%s",v.weight); 
		    break; 
	case 6: printf("\nENTER THE NEW DATA:"); 
            printf("\nCRIME::"); 
		    gets(v.crime); 
		    break; 
    case 7: printf("ENTER THE NEW DATA:"); 
            printf("\nCONVICTION:"); 
	   	    gets(v.conviction); 
		    break; 
    case 8: printf("ENTER THE NEW DATA:"); 
            printf("\nPRISIONED DATE:"); 
		    gets(v.date); 
		    break; 
    case 9: printf("ENTER THE NEW DATA:"); 
            printf("\nPUNISHMENT DURATION:"); 
	        gets(v.p_duration); 
		    break; 
    case 10: printf("ENTER THE NEW DATA:"); 
             printf("\nFATHER NAME:"); 
	         gets(v.fam.father_name); 
		     break; 
    case 11: printf("ENTER THE NEW DATA:"); 
             printf("FATHER'S PHONE NUMBER:"); 
		     scanf("%s",v.fam.f_phone); 
		     break; 
    case 12: printf("ENTER THE NEW DATA:"); 
             printf("\nMOTHERNAME"); 
	    	 gets(v.fam.mother_name); 
		     break; 
    case 13: printf("ENTER THE NEW DATA:"); 
             printf("\nMOTHER PHONE NUMBER:"); 
		     scanf("%s",v.fam.m_phone); 
		     break; 
    case 14: printf("ENTER THE NEW DATA:"); 
             printf("\nWIFE NAME:"); 
		     gets(v.fam.wife_name); 
		     break; 
  
		    
    case 16: printf("ENTER THE NEW DATA:"); 
             printf("\tPRISONER NAME:"); 
		     gets(v.name); 
		     printf("\tAGE:"); 
		     scanf("%s",v.age); 
		     printf("\tSEX:"); 
		     gets(v.sex); 
		     printf("\tHEIGHT:"); 
		     scanf("%s",v.height); 
		     printf("\tWEIGHT:"); 
		     scanf("%s",v.weight); 
	         printf("\tCRIME:"); 
		     gets(v.crime);
		     printf("\tENTER THE CONVITION:"); 
		     gets(v.conviction); 
		     printf("\tENTER THE PRISIONED DATE:"); 
		     gets(v.date); 
		     printf("\tPUNISHMENT DURATION:"); 
		     scanf("%s",v.p_duration); 
		     printf("\tFATHER NAME:"); 
		     scanf("%s",v.fam.father_name); 
		     printf("\tFATHER PHONE NUMBER:"); 
		     scanf("%s",v.fam.f_phone); 
		     printf("\tMOTHER NAME:"); 
		     gets(v.fam.mother_name); 
		     printf("\tMOTHER PHONE NUMBER:"); 
		     scanf("%s",v.fam.m_phone); 
		     printf("\tWIFE NAME:"); 
		     gets(v.fam.wife_name);
     case 17: printf("\nPRESS ANY KEY TO GO BACK...\n"); 
              getch(); 
			  return ; 
			  break; 
     default: printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n"); 
              break; 
			
   } 
  }while(nmber<1||nmber>20); 
  fseek(fp,sizeof(v),SEEK_CUR);
  fwrite(&v,sizeof(v),1,fp); 
  fseek(fp,sizeof(v),SEEK_CUR); 
  fread(&v,sizeof(v),1,fp); 
  options=5; 
  break;
  }
}
  if(options==5) 
  { 
   system("cls"); 
   printf("\n\t\tEDITING COMPLETED...\n"); printf("--------------------\n"); 
   printf("THE NEW RECORD IS:\n"); printf("--------------------\n");
   printf("\nPRISONER'S NAME: %s",v.name); 
   printf("\nPRISONER'S AGE: %s",v.age); 
   printf("\nPRISONER'S GENDER: %s",v.sex);
   printf("\nPRISONER'S HEIGHT: %s",v.height);  
   printf("\nPRISONER'S WEIGHT: %s",v.weight); 
   printf("\nPRISONER'S CRIME: %s",v.crime); 
   printf("\nPRISONER'S CONVICTION: %s",v.conviction); 
   printf("\nPRISONER'S PRISONED DATE:%s",v.date);
   printf("\nPRISONERS PUNISHMENT DURATION:%s",v.p_duration);
   printf("\nPRISONER'S FATHER NAME:%s",v.fam.father_name);
   printf("\nPRISONER'S FATHER'S PHONE NUMBER:%s",v.fam.f_phone);
   printf("\nPRISONER'S MOTHER NAME:%s",v.fam.mother_name);
   printf("\nPRISONER'S MOTHER'S PHONE NUMBER:%s",v.fam.m_phone);
   printf("\nPRISONER'S WIFE NAME:%s",v.fam.wife_name); 
   fclose(fp); 
   printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)"); 
   scanf("%c",&options); 
   counting++; 
   } 
  else 
  { 
   printf("\nTHE RECORD DOES NOT EXIST:");
   printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)"); 
   scanf("%c",&options); 
  }
 }while(options=='Y'||options=='y');
  fclose ( fp ) ; 
  printf("\nPRESS ENTER TO EXIT EDITING MENU."); 
  getch();
}
void delete_func( )
{
 system("cls"); 
 FILE *fp,*filetemporary ; 
 struct record file ; 
 char p_name[15],anthr = 'Y' ,id[16];  
 int options,checked; 
 int x=0; 
 char passwords[8]; 
 printf("\n\n\t\t*************************\n"); 
 printf("\t\t* WELCOME TO DELETE MENU*"); 
 printf("\n\t\t*************************\n\n"); 
 printf("\nENTER PASSWORD\n"); 
 int t; 
 for( t=0;t<4;t++) 
 { 
  passwords[t]=getch(); 
  printf("*"); 
 } 
 if (strcmpi(passwords,"pass")==0) 
 { 
  printf("\n\t\t*ACCESS GRANTED*\n\n");
  while ( anthr == 'Y' || anthr == 'y' )
  {  
   printf("\n\tENTER THE NAME OF PRISONER TO BE DELETED:"); 
   fflush(stdin); 
   gets(p_name); 
   fp = fopen ("prision.txt", "rb" ) ; 
   if ( fp == NULL ) 
   { 
    printf("\nTHE FILE DOES NOT EXIST"); 
	printf("\nPRESS ANY KEY TO GO BACK."); 
	getch(); 
	return ; 
   } 
   filetemporary=fopen("temp.txt","wb"); 
   if(filetemporary==NULL) 
   { 
    printf("\nSYSTEM ERROR"); 
	printf("\nPRESS ANY KEY TO GO BACK"); 
	getch(); 
	return ; 
   } 
   printf("\n\tENTER THE ID OF RECORD TO BE DELETED:"); 
   fflush(stdin); 
   gets(id); 
   while(fread(&file,sizeof(file),1,fp)==1)
   { 
    if(strcmp(file.id,id)!=0) 
	 fwrite(&file,sizeof(file),1,filetemporary); 
   } 
   fclose(filetemporary); 
   fclose(fp); 
   remove("prision.txt"); 
   rename("temp.txt","prision.txt"); 
   printf("\nDELETED SUCCESFULLY..."); 
   getch(); 
   printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):"); 
   fflush(stdin); 
   scanf("%c",&anthr); 
  } 
   printf("\n\n\tPRESS ANY KEY TO EXIT..."); 
   getch();
 }
 else
 {
  printf("\nSorry!Invalid password\n");
  
 }
 fclose(fp);
}
   



int main() 
{

	int ch;
	printf("n\n\t********************\n");
	printf("\t\t*PRISONER RECORD*\n");
	printf("\t********************");
	while(1)
	{
		printf("\n\n\t MAIN MENU:");
		printf("\n\n\t ADD RECORD\t[1]");
		printf("\n\t EDIT RECORD\t[2]");
		printf("\n\t VIEW RECORD\t[3]");
		printf("\n\t DELETE RECORD\t[4]");
		printf("\n\t EXIT\t[5]");
		printf("\n\n\t ENTER YOUR CHOICE:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: add();
			        break;
			case 2:edit();
			       break;
			case 3:view();
			       break;
			case 4:delete_func();
			       break;        
			default: printf("\n YOU ENTERED WRONG COICE.");
			         printf("\n TRY AGAIN");
			         getch();
					 break;        
		}
		return 0;
	}
}

