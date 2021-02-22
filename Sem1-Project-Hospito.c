/* incluing libs*/
#include<stdio.h>
#include<windows.h> // gotoxy()
#include<conio.h> // delay(), getch()
#include<ctype.h> // toupper()
#include<string.h> // strcmp(), strcpy(), strlen()
#include<stdlib.h>

char answer = 0;
int ok, valid, j;

//Declaring the Fxns
void wlcmScreen(void); // goto ln 53
void title(void); // goto ln 
void mainMenu(void); // goto ln 117
void loginScreen(void); // goto ln 73
void addRecord(void); // goto ln 161
void list(void); // goto ln 336
void searchRecord(void); // goto ln 
void editRecord(void); // goto ln 
void deleteRecord(void); // goto ln 
void exitProgram(void); // goto ln 

/// setting the position of the text cursor
void gotoxy( short x, short y){
    COORD coord= {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
} 

// global variables
struct patient{
    int Age;
    char Gender;
    char FirstName[20];
    char LastName[20];
    char ContactNo[13];
    char Email[30];
    char Doctor[20];
    char Problem[20];
    char Address[30];
};

struct patient p , temp3;

/// Main fxn
 void main (void){
    wlcmScreen();
    title();
    loginScreen();
}

//wlcm screen
void wlcmScreen(void){

    printf("\n\n\n\n\n\n  \t\t\t\t******************************* ");
    printf("\n \t\t\t\t * Welcome to\t\t*");
    printf("\n\t\t\t\t * Hospito \t\t *");
    printf("\n\t\t\t\t *******************************");
    printf("\n\n\n\n\n \t\t To Continue, Press any Key...");

    getch(); // wait for response

    System("cls"); // clear screen
}

/// title
void title(void){
    printf("\n\n\n ----------------------------------");
    printf("\n\t\t\t\t    Hospito      ");
    printf("\n\n\n ----------------------------------");
}

/// Login Screen
void loginScreen(void){

    int i=1;
    char username[20];
    char password[20];
    char og_username[100]="oblate.in";
    char og_password[20]="oblate.tech";

    do
    {
        printf("\n\n\n\n \t\t\t\t Enter Username and Password");
        print("\n\n\n\t\t\t\t Usernsme: ");
        scanf("%s", &username);
        print("\n\n\n\t\t\t\t Password: ");
        scanf("%s", &password);

        //checking id and pass
        //TODO: system to check from various id pass
        if (strcmp(username,og_username)==0 && strcmp(password,og_password)==0){

            printf("\n\n\n\t\t\t\t\t Login Succesful.... \n\n\n \t\t\t\t Press any key...");
            getch();
            mainMenu();
            break;
        }
        else
        {
            printf("\n\t\t\t Username and Password did not match... try again. %i th chance out of 3 ", i);
            i++;
            getch();
        }
    } while (i<=3);

    if (i>3)
    {
        printf("\n\n\n \t\t\t You have 0 attempts left. Close and try again....");
        getch();
        exitProgram();
    }
    System("cls");  
    
}

/// main menu 
void mainMenu(void){
    System("cls");
    
    int choice;
    title();

    printf("\n\n\n\n\n \t\t\t\t");
     printf("1. Add Patient Record\n\n \t\t\t\t ");
     printf("2. List of Patient Records \n \t\t\t\t");
     printf("3. Search Patient Records\n  \t\t\t\t");
     printf("4. Edit Patient Records\n  \t\t\t\t"); 
     printf("5. Delete Patient Records\n  \t\t\t\t ");
     printf("6. Exit \n");
    
    printf("Enter your choice from 1 to 6 - ");
    scanf("%i", &choice);

    switch (choice)
    {
    case 1:
        addRecord();
        break;
    case 2:
        list();
        break;
    case 3:
        searchRecord();
        break;
    case 4:
         editRecord();
         break;
    case 5:
        deleteRecord();
        break;
    case 6:
        exitProgram();
        break;
    default:
        printf("\n\n\n \t\t\t Enter correct choice");
        getch();
    }
}

/// add patient
void addRecord(void){

    System("cls");
    title();

    char ans;
    FILE*file; // file pointer
    file= fopen("Record2.dat","a"); // opening file in write mode

    printf("\n\n\n \t\t\t\t !!!!!!!!!!!!!!!!!!! Add Patient Record !!!!!!!!!!!!!!!!!!! \n\n");

    // first name 
    A:
    printf("\t\t\t\t First Name: ");
    scanf("%s", p.FirstName);
    p.FirstName[0]=toupper(p.FirstName[0]);

    if (strlen(p.FirstName)>20 || strlen(p.FirstName)<1){
        printf(" \n \t\t First name can be upto 20 char and cant be null \n");
        goto A;
    }
    else{
        for(j=0;j<strlen(p.FirstName); j++){
            if (isalpha(p.FirstName[j])){
                valid=1;
            }else{
                valid= 0;
                break;
            }
        }
        if (!valid){
            printf("\n \t\t First Name contains Invalid character. Enter Again.. \n");
            goto A;
        }
    }

        // last name 
    B:
    printf("\t\t\t\t Last Name: ");
    scanf("%s", p.LastName);
    p.LastName[0]=toupper(p.LastName[0]);

    if (strlen(p.LastName)>20 || strlen(p.LastName)<1){
        printf(" \n \t\t Last name can be upto 20 char and cant be null \n");
        goto B;
    }
    else{
        for(j=0;j<strlen(p.LastName); j++){
            if (isalpha(p.LastName[j])){
                valid=1;
            }else{
                valid= 0;
                break;
            }
        }
        if (!valid){
            printf("\n \t\t Last Name contains Invalid character. Enter Again.. \n");
            goto B;
        }
    }

    // gender
    
  C:
   printf("\n \t\t\t Gender[M/F]: ");
   scanf("%s",p.Gender);
   if (toupper(p.Gender)=='M' || toupper(p.Gender)=='F'){
      ok =1;
   }else{
        ok = 0;
   }
   if(!ok){
          printf("\n \t\t\t Gender contains Invalid value. Enter M or F");
      goto C;
   } 

   // age
    printf("\n \t\t\t Age: ");
    scanf("%i", &p.Age);

  // Address
    
    do
    {
        D:
    printf("\n \t\t\t Addresss: ");
    scanf("%s", p.Address);
    p.Address[0]=toupper(p.Address[0]);
    
    if(strlen(p.Address)<30 || strlen(p.Address)>3){
        printf("\n \t\t Keep the Address b/w 3 and 30 characters");
        goto D;
        
    }
    } while (!valid);
    
    // Contact No
    do
    {
        E:
        printf("\n\t\t\t Contact no -");
        scanf("%s",p.ContactNo);

        if(strlen(p.ContactNo)!=10){
            printf("\n\t\t Contact no must 10 digit long ");
            goto E;
        }else{
            for(j=0;j<strlen(p.ContactNo);j++){
                if(isdigit(p.ContactNo[j])){
                    valid=1;
                }else{
                    valid=0;
                    break;                    
                }
            }
            if(!valid){
                printf("\n\t\t\t Contact no should be all digits");
                goto E;
            }
        }
    } while (!valid);

    // Email
    do
    {
    
        printf("\n \t\t\t Email : ");
        scanf("%s",p.Email);

    } while (!valid);

    //Problem

    do
    {
        printf("\n \t\t\t Problem : ");
        scanf("%s", p.Problem);
        p.Problem[0]=toupper(p.Problem);
    } while (!valid);

    //Doctor

    do
    {
        printf("\n \t\t\t Doctor : ");
        scanf("%s", p.Doctor);
        p.Doctor[0]=toupper(p.Doctor);
    } while (!valid);
    
    // Printing Recorded Info
    fgets(file,"%s %s %c %i %s %s %s %s %s",p.FirstName, p.LastName ,p.Gender , p.Age, p.ContactNo ,p.Email, p.Address , p.Problem, p.Doctor);
    printf("\n \t\t\t Information Recorded Successfully....");
    fclose(file); 
    
    // adding more or not
    X:
    getch();
    printf("\n\n\t\t\t Do you want to Add more Record(Y/N) ?");
    scanf("%c", ans);
    if(toupper(ans) == 'Y'){
        addRecord();
    }
    else if(toupper(ans)=='N'){
        printf("\n\n\t\tClick any key to return to main menu");
        getch();
        mainMenu();
    }
    else{
        printf("\n\t\t\t Enter Either Y or N");
        goto X;
    }
}

/* ....Patient List.....*/
void list(){
    int row,sno=1;
    System("cls");
    title();
    FILE *file;
    file= fopen("Record2.dat","r");
    printf("\n\n\t\t\t .....List of Records.....\n");
    gotoxy(2,15);
    printf("Full Name");
    gotoxy(20,15);
    printf("Gender");
    gotoxy(32,15);
    printf("Age");
    gotoxy(37,15);
    printf("Address");
    gotoxy(49,15);
    printf("Contact No");
    gotoxy(64,15);
    printf("Email");
    gotoxy(88,15);
    printf("Problem");
    gotoxy(98,15);
    printf("Doctor\n");
    printf("****************************************************************************************************************");

    row=17;
    while (fscanf(file,"%s %s %c %i %s %s %s %s %s",p.FirstName, p.LastName ,p.Gender , p.Age, p.ContactNo ,p.Email, p.Address , p.Problem, p.Doctor))
    {
        gotoxy(0,row);
        printf("%i",sno);
        gotoxy(2,row);
        printf("%s %s",p.FirstName,p.LastName);
        gotoxy(20,row);
        printf("%c",p.Gender);
        gotoxy(32,row);
        printf("%i",p.Age);
        gotoxy(37,row);
        printf("%s",p.Address);
        gotoxy(49,row);
        printf("%s",p.ContactNo);
        gotoxy(64,row);
        printf("%s",p.Email);
        gotoxy(88,row);
        printf("%s",p.Problem);
        gotoxy(98,row);
        printf("%s",p.Doctor);
        row++;
        sno++;   
    }
    fclose(file);
    printf("\n \t\t Press any key to return to Main Menu");
    getch();
    mainMenu();
    
}

/*  .... Search Patient ....*/
void searchRecord(void){
    char name[20];
    char ans;
    System("cls");

    FILE *file;
    file = fopen("Record2.dat","r");

    title();
    printf("\n\n\t\t\t ......Search patients...... /n");
    printf("\n\n\t\t Enter patient name : ");
    scanf("%s",name);

    fflush(stdin);
    name[0]=toupper(name[0]);

    while (fscanf(file,"%s %s %c %i %s %s %s %s %s",p.FirstName, p.LastName ,p.Gender , p.Age, p.ContactNo ,p.Email, p.Address , p.Problem, p.Doctor))
    {
        if(strcmp(p.FirstName,name)==0){
        gotoxy(2,15);
        printf("Full Name");
        gotoxy(20,15);
        printf("Gender");
        gotoxy(32,15);
        printf("Age");
        gotoxy(37,15);
        printf("Address");
        gotoxy(49,15);
        printf("Contact No");
        gotoxy(64,15);
        printf("Email");
        gotoxy(88,15);
        printf("Problem");
        gotoxy(98,15);
        printf("Doctor\n");
        break;
        }
    }
    if(strcmp(p.FirstName,name)!=0){
        gotoxy(5,10);
        printf("Record Not Found!");
        getch();
    }
    fclose(file);
    Y:
    getch();
    printf("\n\n\t\t\t Do you want to search againd(Y/N) ?");
    scanf("%c", ans);
    if(toupper(ans) == 'Y'){
        searchRecord();
    }
    else if(toupper(ans)=='N'){
        printf("\n\n\t\tClick any key to return to main menu");
        getch();
        mainMenu();
    }
    else{
        printf("\n\t\t\t Enter Either Y or N");
        goto Y;
    }
}


/*    ..... Editing Record.....  */

void editRecord(void){
    FILE *file, *tf;
    int i,b, valid=0;
    char ch;
    char name[20];
    System("cls");
    title();
    tf=fopen("temp2.dat","w+");
    file = fopen("Record2.dat","r");

    if(file==NULL){
        printf("\n\t Can't Open File");
        getch();
        mainMenu();
    }

    printf("\n\n\t\t\t ......Edit Patient Record...... \n");
    gotoxy(12,13);
    printf("Enter First name: ");
    scanf("%s",name);

    fflush(stdin);
    name[0]=toupper(name[0]);

    gotoxy(12,15);
    if(tf==NULL){
        printf("\n Cant open file");
        getch();
        mainMenu();
    }

    while (fscanf(file,"%s %s %c %i %s %s %s %s %s",p.FirstName, p.LastName ,p.Gender , p.Age, p.Address, p.ContactNo ,p.Email, p.Problem, p.Doctor))
    {
        if(strcmp(p.FirstName,name)==0){
            
            valid=1;
            gotoxy(25,17);
            printf(" Existing Record");
            gotoxy(10,19);
            printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.FirstName, p.LastName, p.Gender, p.Age, p.Address ,p.ContactNo, p.Email, p.Problem, p.Doctor);
            
            gotoxy(12,22);
            printf(" Enter First Name : ");
            scanf("%s",p.FirstName);

            gotoxy(12,24);
            printf("Enter LAst Name : ");
            scanf("%s",p.LastName);

            gotoxy(12,26);
            printf("Enger Gender : ");
            scanf("%s",p.Gender);

            gotoxy(12,28);
            printf("Age");
            scanf("%s",p.Age);

            gotoxy(12,30);
            printf(" Address");
            scanf("%s",p.Address);

            gotoxy(12,32);
            printf("Contact No : ");
            scanf("%s",p.ContactNo);

            gotoxy(12,34);
            printf(" Email : ");
            scanf("%s",p.Email);

            gotoxy(12,36);
            printf("Problem : ");
            scanf("%s",p.Problem);

            gotoxy(12,38);
            printf("Doctor : ");
            scanf("%s",p.Doctor);

            printf(" \n Are you sure? If yes Press U");

            ch=getche(); // get character predifined method

            if(toupper(ch)=='U'){

            fprintf(tf,"%s %s %c %i %s %s %s %s %s",p.FirstName, p.LastName ,p.Gender , p.Age, p.Address, p.ContactNo ,p.Email, p.Problem, p.Doctor);
            printf("\n\n \t\t Patient Record Updated");
            }else{
            fprintf(tf,"%s %s %c %i %s %s %s %s %s",p.FirstName, p.LastName ,p.Gender , p.Age, p.Address, p.ContactNo ,p.Email, p.Problem, p.Doctor);
            }
        }
    }
        if(!valid){
            printf("\n\t\t No Record Found");
        }

        fclose(tf);
        fclose(file);
        remove("Record2.dat"); // removing the original file
        rename("temp2.dat","Record2.dat"); // renameing the temp file to original witch edited records

        getch();
        mainMenu();
}

/*    . ...... Delete Record .....*/

void deleteRecord(void){
    FILE *file, *tf;
    int found=0;
    char name[20];
    System("cls");
    title();
    tf=fopen("temp_file2.dat","w+");
    file = fopen("Record2.dat","r");
    printf("\n\n\t\t\t ......Edit Patient Record...... \n");
    gotoxy(12,8);
    printf("Enter Patient name: ");
    fflush(stdin);
    gets(name);
    name[0]=toupper(name[0]);

    while (fscanf(file,"%s %s %c %i %s %s %s %s %s",p.FirstName, p.LastName ,p.Gender , p.Age, p.Address, p.ContactNo ,p.Email, p.Problem, p.Doctor))
    {
        if(strcmp(p.FirstName,name)!=0){
        fprintf(tf,"%s %s %c %i %s %s %s %s %s",p.FirstName, p.LastName ,p.Gender , p.Age, p.Address, p.ContactNo ,p.Email, p.Problem, p.Doctor);
        }
        else{
        printf("%s %s %c %i %s %s %s %s %s",p.FirstName, p.LastName ,p.Gender , p.Age, p.Address, p.ContactNo ,p.Email, p.Problem, p.Doctor);
        found=1;
        }
    }
    if(found==0){
        printf("\n\n\t\t\t Record nnot found");
        getch();
        mainMenu();
    }
    else{
        fclose(file);
        fclose(tf);
        remove("Record2.dat");
        rename("temp_file2.dat","Record2.dat");

        printf("\n\n \t\t\t Record Deleted Successfully");
        getch();
        mainMenu();

    }
}

/*   .....Exit .....*/
void exitProgram(void){
    System("cls");
    title();
    printf("\n\n\n \t\t\t Exiting....");
    getch();
}