#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

char dnames[25];
char dids[25];
char dtitle[25];
int dsal;
char demail[35];
long int dphon;
int n,i;


void menu(){
          printf("\xB2\xB2\xB2 1 FOR ADD NEW EMPLOYEE     \xB2\xB2\xB2 \n");
          printf("\xB2\xB2\xB2 2 FOR SEARCHING EMPLOYEE   \xB2\xB2\xB2 \n");
          printf("\xB2\xB2\xB2 3 FOR EDIT EMPLOYEE        \xB2\xB2\xB2 \n");
          printf("\xB2\xB2\xB2 4 FOR DELETE EMPLOYEE      \xB2\xB2\xB2 \n");
          printf("\xB2\xB2\xB2 0 FOR EXIT                 \xB2\xB2\xB2 \n");
          printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");

}
void section(){
      system("COLOR 57");
      printf("~~~~~~~~ PLEASE SELECT THE SECTION ~~~~~~~~~\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
      printf("\xB3 1 FOR DEVELOPMENT SECTION      \xB3 \n");
      printf("\xB3 2 FOR ACCUNTING SECTION        \xB3 \n");
      printf("\xB3 3 FOR MARKETING SECTION        \xB3 \n");
      printf("\xB3 4 FOR HUMAN RESOURCE SECTION   \xB3 \n");
      printf("\xB3 0 FOR BACK TO HOME                     \xB3 \n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");

}
void simpleSelect(){
    printf("-- WRITE  -> all <- FOR DISPLAY ALL DATA \n");
    printf("-- WRITE -> name <- FOR SEARCH BY NAME \n");
    printf("-- WRITE -> id <- FOR SEARCH BY ID \n");
    printf("-- WRITE -> back <- FOR BACK TO SEARCH MENU \n");
}
void home(){
    int ch;
        do{
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
              menu();
              scanf("%d",&ch);

            system("cls");
              switch(ch){
                case 1:{
                     printf("@@@@@@@@ YOU ARE GOING TO ADD EMPLOYEE @@@@@@@@@\n \n");
                    caseone();
                    break;
                }
                case 2:{
                     printf("@@@@@@@@ YOU ARE GOING TO DISPLAY EMPLOYEE @@@@@@@@@\n \n");
                     casetwo();
                     break;

                }
                case 3:{
                     printf("@@@@@@@@ YOU ARE GOING TO DELETE EMPLOYEE @@@@@@@@@\n \n");
                     casethree();
                     break;

                }
                case 4:{
                     printf("@@@@@@@@ YOU ARE GOING TO DELETE EMPLOYEE @@@@@@@@@\n \n");
                     casefour();
                     break;

                }
                case 0:exit(0);
                break;
                default:printf("PLEASE SELECT FROM 0 TO 4 \n");
                break;
              }
          }
          while(ch != 0);
}
//Edit function
void casethree(){
    int sec3;
    section();
    scanf("%d",&sec3);
    if(sec3 == 1){
       divedit();
    }
    else if(sec3 == 2){
       accedit();
    }
    else if(sec3 == 3){
       markedit();
    }
    else if(sec3 == 4){
       humanedit();
    }
    else{
        printf("PLEASE SELECT FROM 1 TO 4 \n");
    }


}
// Human Section Edit
void humanedit(){
    int ress;
    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2;
    fd1 = fopen("Human.txt","r");
    fd2 = fopen("Humantemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
       ress = strcmp(dname,dnames);
       if(ress == 0){
           add(fd2);
       }
       else{
        fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
       }
    }
    fclose(fd1);
    fclose(fd2);
    remove("Human.txt");
    rename("Humantemp.txt","Human.txt");
}
// Marketing Section Edit
void markedit(){
    int ress;
    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2;
    fd1 = fopen("Marketing.txt","r");
    fd2 = fopen("Marketingtemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
       ress = strcmp(dname,dnames);
       if(ress == 0){
           add(fd2);
       }
       else{
        fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
       }
    }
    fclose(fd1);
    fclose(fd2);
    remove("Marketing.txt");
    rename("Marketingtemp.txt","Marketing.txt");
}
// ACCunting Section Edit
void accedit(){
    int ress;
    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2;
    fd1 = fopen("Accounting.txt","r");
    fd2 = fopen("Accountingtemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
       ress = strcmp(dname,dnames);
       if(ress == 0){
           add(fd2);
       }
       else{
        fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
       }
    }
    fclose(fd1);
    fclose(fd2);
    remove("Accounting.txt");
    rename("Accountingtemp.txt","Accounting.txt");
}
// Development Section Edit
void divedit(){
    int ress;
    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2;
    fd1 = fopen("Development.txt","r");
    fd2 = fopen("Developmenttemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
       ress = strcmp(dname,dnames);
       if(ress == 0){
           add(fd2);
       }
       else{
        fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
       }
    }
    fclose(fd1);
    fclose(fd2);
    remove("Development.txt");
    rename("Developmenttemp.txt","Development.txt");
}





//Deleting employee
void casefour(){
    int sec4;
    section();
    scanf("%d",&sec4);
    if(sec4 == 1){
       divdelt();
    }
    else if(sec4 == 2){
       accudelt();
    }
    else if(sec4 == 3){
       markdelt();
    }
    else if(sec4 == 4){
       humdelt();
    }
    else{
        printf("PLEASE SELECT FROM 1 TO 4 \n");
    }
}
//Development Deleting employee
void divdelt(){
    char dnamess[0] = "";
    int ress;

    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2;
    fd1 = fopen("Development.txt","r");
    fd2 = fopen("Developmenttemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
       ress = strcmp(dname,dnames);
       if(ress == 0){
          fprintf(fd2,"%s",dnamess);
       }
       else{

       fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
       }
    }
    fclose(fd1);
    fclose(fd2);
    remove("Development.txt");
    rename("Developmenttemp.txt","Development.txt");
}
//Accounting Deleting employee
void accudelt(){
    char dnamess[0] = "";
    int ress;

    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2;
    fd1 = fopen("Accounting.txt","r");
    fd2 = fopen("Accountingtemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
       ress = strcmp(dname,dnames);
       if(ress == 0){
          fprintf(fd2,"%s",dnamess);
       }
       else{

       fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
       }
    }
    fclose(fd1);
    fclose(fd2);
    remove("Accounting.txt");
    rename("Accountingtemp.txt","Accounting.txt");
}

//Marketing Deleting employee
void markdelt(){
    char dnamess[0] = "";
    int ress;

    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2;
    fd1 = fopen("Marketing.txt","r");
    fd2 = fopen("Marketingtemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
       ress = strcmp(dname,dnames);
       if(ress == 0){
          fprintf(fd2,"%s",dnamess);
       }
       else{

       fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
       }
    }
    fclose(fd1);
    fclose(fd2);
    remove("Marketing.txt");
    rename("Marketingtemp.txt","Marketing.txt");
}

//Human Resource Deleting employee
void humdelt(){
    char dnamess[0] = "";
    int ress;

    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2;
    fd1 = fopen("Human.txt","r");
    fd2 = fopen("Humantemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
       ress = strcmp(dname,dnames);
       if(ress == 0){
          fprintf(fd2,"%s",dnamess);
       }
       else{

       fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
       }
    }
    fclose(fd1);
    fclose(fd2);
    remove("Human.txt");
    rename("Humantemp.txt","Human.txt");
}



void dis(){
        printf("***->> Name: %s \n",dnames);
        printf("***->> EID : %s \n",dids);
        printf("***->> DESIGNATION : %s \n",dtitle);
        printf("***->> SALARY : %d \n",dsal);
        printf("***->> EMAIL : %s \n",demail);
        printf("***->> PHON : %ld \n\n",dphon);
}
// Didplay all data ****
void display(){
    FILE *ft;
    ft = fopen("Development.txt","r");
    while(fscanf(ft,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    dis();
    }
    fclose(ft);
}
void display_a(){
    FILE *ft;
    ft = fopen("Accounting.txt","r");
    while(fscanf(ft,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    dis();
    }
    fclose(ft);
}
void display_m(){
    FILE *ft;
    ft = fopen("Marketing.txt","r");
    while(fscanf(ft,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    dis();
    }
    fclose(ft);
}
void display_h(){
    FILE *ft;
    ft = fopen("Human.txt","r");
    while(fscanf(ft,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    dis();
    }
    fclose(ft);
}

//Display by Name ****


void display_name(char dname[]){
    FILE *dtf;
    dtf = fopen("Development.txt","r");
    data(dtf,dname);
}
void display_aname(char dname[]){
    FILE *dtf;
    dtf = fopen("Accounting.txt","r");
    data(dtf,dname);
}
void display_mname(char dname[]){
    FILE *dtf;
    dtf = fopen("Marketing.txt","r");
    data(dtf,dname);
}
void display_hname(char dname[]){
    FILE *dtf;
    dtf = fopen("Human.txt","r");
    data(dtf,dname);
}

// display by Id ***********
void display_did(char did[]){
    FILE *dtf;
    dtf = fopen("Development.txt","r");
    data_id(dtf,did);
}
void display_aid(char did[]){
    FILE *dtf;
    dtf = fopen("Accounting.txt","r");
    data_id(dtf,did);
}
void display_mid(char did[]){
    FILE *dtf;
    dtf = fopen("Marketing.txt","r");
    data_id(dtf,did);
}
void display_hid(char did[]){
    FILE *dtf;
    dtf = fopen("Human.txt","r");
    data_id(dtf,did);
}

//Search by Id
void data_id(FILE *dtf,char aid[]){
    int dres,i;
        while(fscanf(dtf,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
       dres = strcmp(aid,dids);
       if(dres == 0){
            dis();
            i = 1;
       }
    }
    if(i == 0){
        printf("***--->> No record is Available <<---*** \n");
    }
    fclose(dtf);
}
// search by name
void data(FILE *dtf,char dname[]){
    int dres,i = 0;

        while(fscanf(dtf,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
       dres = strcmp(dnames,dname);
       if(dres == 0){
        dis();
        i = 1;
       }
    }
    if(i == 0){
        printf("***--->> No record is Available <<---*** \n");
    }
    fclose(dtf);
}

void casetwo(){
    int sec2,id;
    char cmp[25],dname[25],did[15];
    do{
        section();
          scanf("%d",&sec2);
          switch(sec2){
            case 1:{
                printf(">>>>>>> YOU HAVE SELECTED DEVELOPMENT SECTION <<<<<<<<\n");
                do{
                simpleSelect();
                scanf("%s",&cmp);
                if(strcmp(cmp,"all") == 0){
                    system("cls");
                    display();
                }
                if(strcmp(cmp,"name") == 0){
                    printf("------> EMPLOYEE'S NAME <------- \n");
                    scanf("%s",&dname);
                    system("cls");
                    display_name(dname);
                }
                if(strcmp(cmp,"id") == 0){
                    printf("------> EMPLOYEE'S ID <------- \n");
                    scanf("%s",&did);
                    system("cls");
                    display_did(did);
                }
                if(strcmp(cmp,"back") == 0){
                    casetwo();
                }
                }
                while(cmp!="back");
                break;
            }
            case 2:{
                printf(">>>>>>> YOU HAVE SELECTED ACCOUNTING SECTION <<<<<<<<\n");
                do{
                simpleSelect();
                scanf("%s",&cmp);
                if(strcmp(cmp,"all") == 0){
                    system("cls");
                    display_a();
                }
                if(strcmp(cmp,"name") == 0){
                    printf("------> EMPLOYEE'S NAME <------- \n");
                    scanf("%s",&dname);
                    system("cls");
                    display_aname(dname);
                }
                if(strcmp(cmp,"id") == 0){
                    printf("------> EMPLOYEE'S ID <------- \n");
                    scanf("%s",&did);
                    system("cls");
                    display_aid(did);
                }
                if(strcmp(cmp,"back") == 0){
                    casetwo();
                }
                }
                while(cmp!="back");
                break;

            }
            case 3:{
                printf(">>>>>>> YOU HAVE SELECTED MARKETING SECTION <<<<<<<<\n");
                do{
                simpleSelect();
                scanf("%s",&cmp);
                if(strcmp(cmp,"all") == 0){
                    system("cls");
                    display_m();
                }
                if(strcmp(cmp,"name") == 0){
                    printf("------> EMPLOYEE'S NAME <------- \n");
                    scanf("%s",&dname);
                    system("cls");
                    display_mname(dname);
                }
                if(strcmp(cmp,"id") == 0){
                    printf("------> EMPLOYEE'S ID <------- \n");
                    scanf("%s",&did);
                    system("cls");
                    display_mid(did);
                }
                if(strcmp(cmp,"back") == 0){
                    casetwo();
                }
                }
                while(cmp!="back");
                break;
            }
            case 4:{
                printf(">>>>>>> YOU HAVE SELECTED HUMANRESOURCE SECTION <<<<<<<<\n");
                do{
                simpleSelect();
                scanf("%s",&cmp);
                if(strcmp(cmp,"all") == 0){
                    system("cls");
                    display_h();
                }
                if(strcmp(cmp,"name") == 0){
                    printf("------> EMPLOYEE'S NAME <------- \n");
                    scanf("%s",&dname);
                    system("cls");
                    display_hname(dname);
                }
                if(strcmp(cmp,"id") == 0){
                    printf("------> EMPLOYEE'S ID <------- \n");
                    scanf("%s",&did);
                    system("cls");
                    display_hid(did);
                }
                if(strcmp(cmp,"back") == 0){
                    casetwo();
                }
                }
                while(cmp!="back");
                break;
            }
            case 0:home();
          }
        }
        while(sec2 != 0);
}


void caseone(){
    int sec;
    do{
        section();
          scanf("%d",&sec);
        system("cls");
          switch(sec){
            case 1:{
                system("cls");
                printf(">>>>>>> YOU HAVE SELECTED DEVELOPMENT SECTION <<<<<<<<\n");
                development();
                break;

            }
            case 2:{
                system("cls");
                printf(">>>>>>> YOU HAVE SELECTED ACCOUNTING SECTION <<<<<<<<\n");
                accounting();
                break;
            }
            case 3:{
                system("cls");
                printf(">>>>>>> YOU HAVE SELECTED MARKETING SECTION <<<<<<<<\n");
                marketing();
                break;
            }
            case 4:{
                system("cls");
                printf(">>>>>>> YOU HAVE SELECTED HUMANRESOURCE SECTION <<<<<<<<\n");
                human();
                break;
            }
            case 0:home();
          }
        }
        while(sec != 0);
}

int sucess(){
    char y[5]= "y";
    char yes[5];
    int cmp;
    printf("********** DATA INSERTED SUCESSFULLY ********* \n");
    printf("********** DO YOU WANT TO ADD MORE DATA ? ********* \n");
    printf("PRESS y IF YES -- PRESS n IF NOT \n");
    scanf("%s",&yes);
    cmp = strcmp(y,yes);
    if(cmp == 0){
       return 0;
    }
    else{
        return 1;
    }
}

void add(FILE *fd){
    int back;
    char name[25];
    char eid[10];
    char title[25];
    int sal;
    char email[35];
    long int phon;
    printf("*** WRITE 'back' TO GO SELECTION MENU *** \n");
    printf("*** EMPLOYEE NAME *** \n");
    scanf("%s",&name);
    back = strcmp(name,"back");
    if(back == 0){
      caseone();
    }
    printf("*** EMPLOYEE ID *** \n");
    scanf("%s",&eid);
    back = strcmp(eid,"back");
    if(back == 0){
      caseone();
    }
    printf("*** EMPLOYEE DESIGNATION *** \n");
    scanf("%s",&title);
    back = strcmp(title,"back");
    if(back == 0){
      caseone();
    }
    printf("*** EMPLOYEE SALARRY *** \n");
    scanf("%d",&sal);
    back = strcmp(title,"back");
    if(back == 0){
      caseone();
    }
    printf("*** EMPLOYEE EMAIL *** \n");
    scanf("%s",&email);
    back = strcmp(email,"back");
    if(back == 0){
      caseone();
    }
    printf("*** EMPLOYEE PHONE *** \n");
    scanf("%ld",&phon);
    fprintf(fd,"%s %s %s %d %s %ld\n",name,eid,title,sal,email,phon);
    fclose(fd);

}

void development(){
    int res,data;
    FILE *fd;
    fd = fopen("Development.txt","a");
    add(fd);
    res = sucess();
    if(res == 0){
       printf("PRESS 1 FOR ADDING THIS SELECTED SECTION \n");
       printf("PRESS 0 FOR GO BACK TO OTHER SECTION \n");
       scanf("%d",&data);
       if(data == 1){
          development();
       }
       else{
            caseone();
       }
    }
    else{
        home();
    }
}

void accounting(){
    int ares,data;
    FILE *fd;
    fd = fopen("Accounting.txt","a");
    add(fd);
    ares = sucess();
    if(ares == 0){
       printf("PRESS 1 FOR ADDING THIS SELECTED SECTION \n");
       printf("PRESS 0 FOR GO BACK TO OTHER SECTION \n");
       scanf("%d",&data);
       if(data == 1){
          accounting();
       }
       else{
            caseone();
       }
    }
    else{
        home();
    }
}

void marketing(){
    int mres,data;
    FILE *fm;
    fm = fopen("Marketing.txt","a");
    add(fm);
    mres = sucess();
    if(mres == 0){
       printf("PRESS 1 FOR ADDING THIS SELECTED SECTION \n");
       printf("PRESS 0 FOR GO BACK TO OTHER SECTION \n");
       scanf("%d",&data);
       if(data == 1){
          marketing();
       }
       else{
            caseone();
       }
    }
    else{
        home();
    }
}

void human(){
    int fres,data;
    FILE *fh;
    fh = fopen("Human.txt","a");
    add(fh);
    fres = sucess();
    if(fres == 0){
       printf("PRESS 1 FOR ADDING THIS SELECTED SECTION \n");
       printf("PRESS 0 FOR GO BACK TO OTHER SECTION \n");
       scanf("%d",&data);
       if(data == 1){
          human();
       }
       else{
            caseone();
       }
    }
    else{
        home();
    }
}

int main(){
    int s = 0;
    int i;
    system("COLOR 57");
    char pass[5];
    printf("********* WELCOME TO HI-TECH SOFTWORE SOLUTION ************ \n");
    for(i=0;i<5;i++){

        printf("~~~~~~~~ PLEASE ENTER YOUR PASSWORD ~~~~~~~~~\n");
        scanf("%s",&pass);
        s = strcmp(pass,"habib");
        if(s == 0){
            system("cls");
            printf("********* PLEASE SELECT YOUR CHOICE ************ \n");
            home();
        }
        else{
            printf("Password isn't correct \n");
        }
    }

}








