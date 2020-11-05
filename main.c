#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    int year,month,day;
} Date;
typedef struct
{
    char Fname[50],Lname[50];
    Date Bdate;
    char Address[50],Email[50];
    char number[50];
} Contact;
Contact PhoneBook[100];
int c=0;
FILE *fp;
void Add_new()
{

//fp=fopen("contact.txt","a+");

    Contact a;
    printf("Enter first name \n");
    printf("--> ");

    scanf(" %[^\n]",a.Fname);

    //gets(a.Fname);
    printf("Enter last name \n");
    printf("--> ");

    scanf(" %[^\n]",a.Lname);
    // gets(a.Lname);
      printf("Enter birth date \n");
    printf("Enter day : \n");
    printf("--> ");

    scanf("%d",&a.Bdate.day);
    while(a.Bdate.day<1||a.Bdate.day>31)
    {
        printf("Wrong input Enter day again : \n");
        printf("--> ");

        scanf("%d",&a.Bdate.day);

    }
    printf("Enter month : \n");
    printf("--> ");

    scanf("%d",&a.Bdate.month);
    while(a.Bdate.month<1||a.Bdate.month>12)
    {
        printf("Wrong input Enter month again : \n");
        printf("--> ");

        scanf("%d",&a.Bdate.month);

    }
    printf("Enter year : \n");
    printf("--> ");

    scanf("%d",&a.Bdate.year);
     while(a.Bdate.year<0||a.Bdate.year>2020)
    {
        printf("Wrong input Enter year again \n");
        printf("--> ");

    scanf("%d",&a.Bdate.year);

    }

    printf("Enter Address  \n");
    printf("--> ");

    scanf(" %[^\n]",a.Address);

    //gets(a.Address);

    printf("Enter Email  \n");
    printf("--> ");

    scanf(" %[^\n]",a.Email);
    int i,k=0,j;
    //Validation  for Email
    while(!k)
    {
        for(int i=0; i<strlen(a.Email); i++)
        {

            if(a.Email[i]=='@')
            {
                for(j=i+1; j<strlen(a.Email); j++)
                {
                    if(a.Email[j]=='.')
                        k++;
                }
            }


        }
        if (k!=1)
        {
            printf("Wrong Email enter again \n");
            printf("--> ");

            scanf(" %[^\n]",a.Email);
        }
    }

    //gets(a.Email);
    printf("Enter phone number \n");
    printf("--> ");

    scanf(" %[^\n]",a.number);
    for(i=0; i<strlen(a.number); i++)
    {
        if(!isdigit(a.number[i]))
        {
            printf("Wrong input Enter again \n ");
            printf("--> ");

            scanf(" %[^\n]",a.number);
        }
    }






    PhoneBook[c]=a;
    c++;

    //fprintf(fp,"%s,%s,%s,%s,%d,%d/%d/%d\n",a.Fname,a.Lname,a.Address,a.Email,a.number,a.Bdate.day,a.Bdate.month,a.Bdate.year);

    //fclose(fp);

}
void Save()
{
    fp=fopen("phonebook.txt","w");
    int i;
    for(i=0; i<c; i++)
        fprintf(fp,"%s,%s,%d/%d/%d,%s,%s,%s\n",PhoneBook[i].Fname,PhoneBook[i].Lname,PhoneBook[i].Bdate.day,PhoneBook[i].Bdate.month,PhoneBook[i].Bdate.year,PhoneBook[i].Address,PhoneBook[i].Email,PhoneBook[i].number);
    fclose(fp);


}

void Load()
{
    char line[sizeof(Contact)];
    char *token;
    fp=fopen("phonebook.txt","r");

    while((fgets(line,sizeof(Contact),fp))!=NULL)
    {
        token=strtok(line,",");
        strcpy(PhoneBook[c].Fname,token);
        token=strtok(NULL,",");
        strcpy(PhoneBook[c].Lname,token);
         token=strtok(NULL,"-");
        PhoneBook[c].Bdate.day=atoi(token);
        token=strtok(NULL,"-");
        PhoneBook[c].Bdate.month=atoi(token);
        token=strtok(NULL,",");
        PhoneBook[c].Bdate.year=atoi(token);
        strcpy(PhoneBook[c].Address,token);
        token=strtok(NULL,",");
        strcpy(PhoneBook[c].Email,token);
        token=strtok(NULL,"\n");
        strcpy(PhoneBook[c].number,token);

        //PhoneBook[i].number=atoi(token);

        c++;
    }
    fclose(fp);

}


void search()
{
    char target_Lname[20];
    int i,k=0;
    printf("Enter target last name \n");
    printf("--> ");

    scanf("%s",target_Lname);

    for(i=0; i<c; i++)
    {
        if((strcasecmp(PhoneBook[i].Lname,target_Lname))==0)
        {
            printf("--> ");

            printf("Contact Data : \n");
            printf("First name : %s \n",PhoneBook[i].Fname);
            printf("Last name : %s \n",PhoneBook[i].Lname);
            printf("Birth date : %d/%d/%d \n",PhoneBook[i].Bdate.day,PhoneBook[i].Bdate.month,PhoneBook[i].Bdate.year);
            printf("Contact Address : %s \n",PhoneBook[i].Address);
            printf("Contact Email : %s \n",PhoneBook[i].Email);
            printf("Contact phone number : %s \n",PhoneBook[i].number);

            k++;

        }

    }
    if(k)
        printf("Contact found %d times \n",k);
    else
        printf("Contact not found\n");


    /*if(found==1)
    {
        printf("Contact Data : \n");
         printf("First name : %s \n",PhoneBook[i].Fname);
            printf("Last name : %s \n",PhoneBook[i].Lname);
        printf("Contact Address : %s \n",PhoneBook[i].Address);
        printf("Contact phone number : %s \n",PhoneBook[i].number);
        printf("Birth date : %d/%d/%d \n",PhoneBook[i].Bdate.day,PhoneBook[i].Bdate.month,PhoneBook[i].Bdate.year);
    }
    else printf("Not found \n");*/
}

void Delete()
{
    int i,j,flag=0;
    char target_Fname[20],target_Lname[20],ca;
    printf("Enter First Name \n");
    printf("--> ");

    scanf(" %[^\n]",target_Fname);
    printf("Enter Last Last \n");
    printf("--> ");

    scanf(" %[^\n]",target_Lname);

    for(i=c; i+1 ; i--)
    {
        if(!(strcasecmp((PhoneBook[i].Fname),(target_Fname))))
        {
            if(!(strcasecmp((PhoneBook[i].Lname),(target_Lname))))
            {
                flag=1;
                printf("--> ");

                printf("Contact Data : \n");
                printf("First name : %s \n",PhoneBook[i].Fname);
                printf("Last name : %s \n",PhoneBook[i].Lname);
                printf("Birth date : %d/%d/%d \n",PhoneBook[i].Bdate.day,PhoneBook[i].Bdate.month,PhoneBook[i].Bdate.year);
                printf("Contact Address : %s \n",PhoneBook[i].Address);
                printf("Contact Email : %s \n",PhoneBook[i].Email);

                printf("Contact phone number : %s \n",PhoneBook[i].number);

                printf("Do you want to delete this Contact (Y/N) ?\n");
                printf("--> ");

                scanf(" %c",&ca);
                while(ca!='y'&&ca!='Y'&&ca!='N'&&ca!='n')
                {
                    printf("Wrong choice Enter your choice again \n");
                    printf("--> ");

                    scanf(" %c",&ca);


                }
                if(ca=='Y'||ca=='y')
                {

                    for(j=i; j<c; j++)
                    {
                        strcpy(PhoneBook[j].Fname,PhoneBook[j+1].Fname);
                        strcpy(PhoneBook[j].Lname,PhoneBook[j+1].Lname);
                        PhoneBook[j].Bdate.day=PhoneBook[j+1].Bdate.day;
                        PhoneBook[j].Bdate.month==PhoneBook[j+1].Bdate.month;
                        PhoneBook[j].Bdate.year=PhoneBook[j+1].Bdate.year;
                        strcpy(PhoneBook[j].Address,PhoneBook[j+1].Address);
                                                strcpy(PhoneBook[j].Email,PhoneBook[j+1].Email);

                        strcpy(PhoneBook[j].number,PhoneBook[j+1].number);






                    }
                    c--;


                }
            }
        }



    }
    if(!flag)
        printf("Contact not found \n");
    if(flag)
    {
        printf("Do you want to Save (Y/N) ?\n");
        printf("--> ");

        scanf(" %c",&ca);
        while(ca!='y'&&ca!='Y'&&ca!='N'&&ca!='n')
        {
            printf("Wrong choice Enter your choice again \n");
            printf("--> ");

            scanf(" %c",&ca);


        }

        if(ca=='Y'||ca=='y')
        {
            Save();
        }




    }
}


void Modify()
{
    char target_Lname[20],ca;
    int i,found=0;
    printf("Enter target last name \n");
    printf("--> ");

    scanf("%s",target_Lname);

    for(i=0; i<c; i++)
    {
        if((strcasecmp(PhoneBook[i].Lname,target_Lname))==0)
        {
            found=1;
            printf("--> ");

            printf("Contact Data : \n");
            printf("First name : %s \n",PhoneBook[i].Fname);
            printf("Last name : %s \n",PhoneBook[i].Lname);
                        printf("Birth date : %d/%d/%d \n",PhoneBook[i].Bdate.day,PhoneBook[i].Bdate.month,PhoneBook[i].Bdate.year);

            printf("Contact Address : %s \n",PhoneBook[i].Address);
            printf("Contact Email : %s \n",PhoneBook[i].Email);

            printf("Contact phone number : %s \n",PhoneBook[i].number);

            printf("Do you want to modify this contact (Y/N) ? \n");
            printf("--> ");

            scanf(" %c",&ca);
            while(ca!='y'&&ca!='Y'&&ca!='N'&&ca!='n')
            {
                printf("Wrong choice Enter your choice again \n");
                printf("--> ");

                scanf(" %c",&ca);


            }
            if(ca=='y'||ca=='Y')
            {
                printf("Enter first name \n");
                printf("--> ");

                scanf(" %[^\n]",PhoneBook[i].Fname);
                printf("Enter last name \n");
                printf("--> ");


                scanf(" %[^\n]",PhoneBook[i].Lname);
                printf("Enter birth date \n");

                printf("Enter day : \n");
                printf("--> ");

                scanf("%d",&PhoneBook[i].Bdate.day);
                printf("Enter month : \n");
                printf("--> ");

                scanf("%d",&PhoneBook[i].Bdate.month);
                printf("Enter year : \n");
                printf("--> ");

                scanf("%d",&PhoneBook[i].Bdate.year);
                printf("Enter Address  \n");
                printf("--> ");

                scanf(" %[^\n]",PhoneBook[i].Address);
                printf("Enter Email  \n");
                printf("--> ");

                scanf(" %[^\n]",PhoneBook[i].Email);

                printf("Enter phone number \n");
                printf("--> ");


                scanf(" %[^\n]",PhoneBook[i].number);

                printf("Do you want to save (Y/N) ? \n");
                printf("--> ");


                scanf(" %c",&ca);
                while(ca!='y'&&ca!='Y'&&ca!='N'&&ca!='n')
                {
                    printf("Wrong choice Enter your choice again \n");
                    printf("--> ");

                    scanf(" %c",&ca);


                }
                if(ca=='N'||ca=='n')
                    exit(0);
                else if(ca=='Y'||ca=='y')
                    Save();





            }
        }
        else
            continue;
        system("cls");




    }
    /* if(found==1){
         printf("Do you want to save (Y/N) ? \n");

     scanf(" %c",&ca);
     if(ca=='N'||ca=='n')
         exit(0);
     else if(ca=='Y'||ca=='y')
         Save();
           else
     {
         printf("Wrong choice");
         exit(0);

     }}*/
    if (found==0)
        printf("Contact not found\n");












}



void Sort_by_Lname()
{
    Contact temp;
    int i,j;
    for(i=0; i<c-1; i++)
    {
        for(j=0; j<c-i-1; j++)
            if((strcasecmp(PhoneBook[j].Lname,PhoneBook[j+1].Lname))>0)
            {
                temp=PhoneBook[j];
                PhoneBook[j]=PhoneBook[j+1];
                PhoneBook[j+1]=temp;

            }
    }
    for(i=0; i<c; i++)
    {
        printf("%d-Contact Data : \n",i+1);
        printf("First name : %s \n",PhoneBook[i].Fname);
        printf("Last name : %s \n",PhoneBook[i].Lname);
                printf("Birth date : %d/%d/%d \n",PhoneBook[i].Bdate.day,PhoneBook[i].Bdate.month,PhoneBook[i].Bdate.year);

        printf("Contact Address : %s \n",PhoneBook[i].Address);
        printf("Contact Email : %s \n",PhoneBook[i].Email);

        printf("Contact phone number : %s \n",PhoneBook[i].number);

    }


}
void Sort_by_DOB()
{
    Contact temp;
    int i,j;
    for(i=0; i<c-1; i++)
    {
        for(j=0; j<c-i-1; j++)
        {
            if ((PhoneBook[j].Bdate.year)>(PhoneBook[j+1].Bdate.year))
            {


                temp=PhoneBook[j];
                PhoneBook[j]=PhoneBook[j+1];
                PhoneBook[j+1]=temp;

            }
            else if (((PhoneBook[j].Bdate.year)==(PhoneBook[j+1].Bdate.year))&&((PhoneBook[j].Bdate.month)>(PhoneBook[j+1].Bdate.month)))
            {
                temp=PhoneBook[j];
                PhoneBook[j]=PhoneBook[j+1];
                PhoneBook[j+1]=temp;

            }
            else   if ((((PhoneBook[j].Bdate.year)==(PhoneBook[j+1].Bdate.year))&&((PhoneBook[j].Bdate.month)>(PhoneBook[j+1].Bdate.month)))&&((PhoneBook[j].Bdate.day)>(PhoneBook[j+1].Bdate.day)))
            {
                temp=PhoneBook[j];
                PhoneBook[j]=PhoneBook[j+1];
                PhoneBook[j+1]=temp;

            }
        }
    }
    for(i=0; i<c; i++)
    {
        printf("%d-Contact Data : \n",i+1);
        printf("First name : %s \n",PhoneBook[i].Fname);
        printf("Last name : %s \n",PhoneBook[i].Lname);
                printf("Birth date : %d/%d/%d \n",PhoneBook[i].Bdate.day,PhoneBook[i].Bdate.month,PhoneBook[i].Bdate.year);

        printf("Contact Address : %s \n",PhoneBook[i].Address);
        printf("Contact Email : %s \n",PhoneBook[i].Email);

        printf("Contact phone number : %s \n",PhoneBook[i].number);


    }
}






int main()
{
    Load();
    while(1)
    {

        printf("\n\t\t\t\t********Phone Book********\n\n");
        printf("1-Add contact \t\t");
        printf("2-Search \t\t");
        printf("3-Delete contact \n\n");
        printf("4-Modify contact \t");
        printf("5-Print(Sort) all contacts \t\t");
        printf("6-Save contact \n\n");
        printf("7-Exit \n\n\n");
        int choice;

        printf("Enter your choice \n");
        scanf("%d",&choice);
        while((choice<=0)||(choice>=8))
        {

            printf("Wrong choice Enter your choice again \n");
            scanf("%d",&choice);
        }

        char ca;

        switch(choice)
        {
        case 1:
            system("cls");
            Add_new();
            printf("Do you want to save (Y/N) ? \n");
            printf("--> ");

            scanf(" %c",&ca);
            while(ca!='y'&&ca!='Y'&&ca!='N'&&ca!='n')
            {
                printf("Wrong choice Enter your choice again \n");
                printf("--> ");

                scanf(" %c",&ca);


            }



             if(ca=='Y'||ca=='y')
            {
                //Load();
                Save();
                printf("Data saved successfully \n");
            }



            printf("Do you want to Back to main menu (Y/N) ? \n");
            printf("--> ");

            scanf(" %c",&ca);
            while(ca!='y'&&ca!='Y'&&ca!='N'&&ca!='n')
            {
                printf("Wrong choice Enter your choice again \n");
                printf("--> ");

                scanf(" %c",&ca);


            }
            if(ca=='N'||ca=='n')
                exit(0);
            else if(ca=='Y'||ca=='y')
            {
                system("cls");
                continue;
            }
            break;

        case 2:
            system("cls");
            // Load();
            search();

            printf("Do you want to Back to main menu (Y/N) ? \n");
            printf("--> ");

            scanf(" %c",&ca);
            while(ca!='y'&&ca!='Y'&&ca!='N'&&ca!='n')
            {
                printf("Wrong choice Enter your choice again \n");
                printf("--> ");

                scanf(" %c",&ca);


            }
            if(ca=='N'||ca=='n')
                exit(0);
            else if(ca=='Y'||ca=='y')
            {
                system("cls");
                continue;
            }

            break;
        case 3:
            system("cls");
            //Load();
            Delete();


            printf("Do you want to Back to main menu (Y/N) ? \n");
            printf("--> ");

            scanf(" %c",&ca);
            while(ca!='y'&&ca!='Y'&&ca!='N'&&ca!='n')
            {
                printf("Wrong choice Enter your choice again \n");
                printf("--> ");

                scanf(" %c",&ca);


            }
            if(ca=='N'||ca=='n')
                exit(0);
            else if(ca=='Y'||ca=='y')
            {
                system("cls");
                continue;
            }


            break;
        case 4:
            system("cls");
            //Load();
            Modify();

            printf("Do you want to Back to main menu (Y/N) ? \n");
            printf("--> ");

            scanf(" %c",&ca);
            while(ca!='y'&&ca!='Y'&&ca!='N'&&ca!='n')
            {
                printf("Wrong choice Enter your choice again \n");
                printf("--> ");

                scanf(" %c",&ca);


            }
            if(ca=='N'||ca=='n')
                exit(0);
            else if(ca=='Y'||ca=='y')
            {
                system("cls");
                continue;
            }

            break;
        case 5:
            system("cls");
            //Load();
            printf("Choose How you want to sort \n");
            printf("1-Sort by Last name  \n");
            printf("2-Sort by Date of birth \n");
            printf("Enter your choice \n");
            printf("--> ");

            scanf("%d",&choice);
            while(choice!=1&&choice!=2)
            {
                printf("Wrong choice Enter your choice again \n");
                printf("--> ");

                scanf("%d",&choice);


            }
            if(choice==1)
                Sort_by_Lname();
            else if(choice==2)
                Sort_by_DOB();
            printf("Do you want to Back to main menu (Y/N) ? \n");
            printf("--> ");

            scanf(" %c",&ca);
            while(ca!='y'&&ca!='Y'&&ca!='N'&&ca!='n')
            {
                printf("Wrong choice Enter your choice again \n");
                printf("--> ");

                scanf(" %c",&ca);


            }
            if(ca=='N'||ca=='n')
                exit(0);
            else if(ca=='Y'||ca=='y')
            {
                system("cls");
                continue;
            }




            break;

        case 6:
            //Load();
            Save();
            printf("Contact Saved \n");
            printf("Do you want to Back to main menu (Y/N) ? \n");
            printf("--> ");

            scanf(" %c",&ca);
            while(ca!='y'&&ca!='Y'&&ca!='N'&&ca!='n')
            {
                printf("Wrong choice Enter your choice again \n");
                printf("--> ");

                scanf(" %c",&ca);


            }
            if(ca=='N'||ca=='n')
                exit(0);
            else if(ca=='Y'||ca=='y')
            {
                system("cls");
                continue;
            }

            break;



        case 7:
            exit(0);
            break;

            /* default:
                 printf("wrong Choice \n");
                 break;*/




        }
    }













    return 0;
}

