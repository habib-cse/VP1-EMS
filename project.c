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

char hdnames[25];
char hdids[25];
char hdtitle[25];
int hdsal;
char hdemail[35];
long int hdphon;
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
                     printf("@@@@@@@@ YOU ARE GOING TO EDIT EMPLOYEE @@@@@@@@@\n \n");
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
    char name[25];
    char eid[10];
    char title[25];
    int sal;
    char email[35];
    long int phon;
    int edit;
    int ress,ares,aress;
    char dname[25];
    printf("PLEASE WRITE THE NAME \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2,*fd3,*fd4;
    fd1 = fopen("Human.txt","r");
    fd2 = fopen("Humantemp.txt","w");
    fd3 = fopen("All.txt","r");
    fd4 = fopen("Alltemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    while(fscanf(fd3,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,&hdsal,hdemail,&hdphon)!=EOF){
        ares = strcmp(dnames,hdnames);
        aress = strcmp(dids,hdids);
        if((ares == 0) && (aress == 0)){
           ress = strcmp(dname,dnames);
           if(ress == 0){
              printf("WHAT DO YOU WANT TO EDIT \n\n");
              printf("->-> 0 FOR ALL EDIT -<-< \n");
              printf("->-> 1 FOR NAME -<-< \n");
              printf("->-> 2 FOR E-ID -<-< \n");
              printf("->-> 3 FOR DESIGNATION -<-< \n");
              printf("->-> 4 FOR SALARY -<-< \n");
              printf("->-> 6 FOR PHON -<-< \n");
              scanf("%d",&edit);
              if(edit == 0){

                printf("*** EMPLOYEE NAME *** \n");
                scanf("%s",&name);
                 printf("*** EMPLOYEE ID *** \n");
                 scanf("%s",&eid);
                printf("*** EMPLOYEE DESIGNATION *** \n");
                scanf("%s",&title);
                printf("*** EMPLOYEE SALARRY *** \n");
                scanf("%d",&sal);
                printf("*** EMPLOYEE EMAIL *** \n");
                scanf("%s",&email);
                printf("*** EMPLOYEE PHONE *** \n");
                scanf("%ld",&phon);
                fprintf(fd2,"%s %s %s %d %s %ld\n",name,eid,title,sal,email,phon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",name,eid,title,sal,email,phon);

               casethree();
              }
              else if(edit == 1){
                printf("*** EMPLOYEE NAME *** \n");
                scanf("%s",&name);
                fprintf(fd2,"%s %s %s %d %s %ld\n",name,dids,dtitle,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",name,hdids,hdtitle,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 2){
                 printf("*** EMPLOYEE ID *** \n");
                 scanf("%s",&eid);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,eid,dtitle,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,eid,hdtitle,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 3){
                printf("*** EMPLOYEE DESIGNATION *** \n");
                scanf("%s",&title);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,title,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,title,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 4){
                printf("*** EMPLOYEE SALARRY *** \n");
                scanf("%d",&sal);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,sal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,sal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 5){
                printf("*** EMPLOYEE EMAIL *** \n");
                scanf("%s",&email);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,email,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,email,hdphon);
               casethree();
              }
              else if(edit == 6){
                printf("*** EMPLOYEE PHONE *** \n");
                scanf("%ld",&phon);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,phon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,phon);
               casethree();
              }
              else if(edit == 7){
               casethree();
              }
                else{
                    printf("*** PLEASE SELECT FORM 1 TO 6 *** \n");
                }
           }
           else{
            fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
           }
       }
       else{
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
       }
    }
    }
    fclose(fd1);
    fclose(fd2);
    fclose(fd3);
    fclose(fd4);
    remove("Human.txt");
    rename("Humantemp.txt","Human.txt");
    remove("All.txt");
    rename("Alltemp.txt","All.txt");
}
// Marketing Section Edit
void markedit(){
    char name[25];
    char eid[10];
    char title[25];
    int sal;
    char email[35];
    long int phon;
    int edit;
    int ress,ares,aress;
    char dname[25];
    printf("PLEASE WRITE THE NAME \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2,*fd3,*fd4;
    fd1 = fopen("Marketing.txt","r");
    fd2 = fopen("Marketingtemp.txt","w");
    fd3 = fopen("All.txt","r");
    fd4 = fopen("Alltemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    while(fscanf(fd3,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,&hdsal,hdemail,&hdphon)!=EOF){
        ares = strcmp(dnames,hdnames);
        aress = strcmp(dids,hdids);
        if((ares == 0) && (aress == 0)){
           ress = strcmp(dname,dnames);
           if(ress == 0){
              printf("WHAT DO YOU WANT TO EDIT \n\n");
              printf("->-> 0 FOR ALL EDIT -<-< \n");
              printf("->-> 1 FOR NAME -<-< \n");
              printf("->-> 2 FOR E-ID -<-< \n");
              printf("->-> 3 FOR DESIGNATION -<-< \n");
              printf("->-> 4 FOR SALARY -<-< \n");
              printf("->-> 6 FOR PHON -<-< \n");
              scanf("%d",&edit);
              if(edit == 0){

                printf("*** EMPLOYEE NAME *** \n");
                scanf("%s",&name);
                 printf("*** EMPLOYEE ID *** \n");
                 scanf("%s",&eid);
                printf("*** EMPLOYEE DESIGNATION *** \n");
                scanf("%s",&title);
                printf("*** EMPLOYEE SALARRY *** \n");
                scanf("%d",&sal);
                printf("*** EMPLOYEE EMAIL *** \n");
                scanf("%s",&email);
                printf("*** EMPLOYEE PHONE *** \n");
                scanf("%ld",&phon);
                fprintf(fd2,"%s %s %s %d %s %ld\n",name,eid,title,sal,email,phon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",name,eid,title,sal,email,phon);

               casethree();
              }
              else if(edit == 1){
                printf("*** EMPLOYEE NAME *** \n");
                scanf("%s",&name);
                fprintf(fd2,"%s %s %s %d %s %ld\n",name,dids,dtitle,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",name,hdids,hdtitle,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 2){
                 printf("*** EMPLOYEE ID *** \n");
                 scanf("%s",&eid);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,eid,dtitle,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,eid,hdtitle,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 3){
                printf("*** EMPLOYEE DESIGNATION *** \n");
                scanf("%s",&title);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,title,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,title,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 4){
                printf("*** EMPLOYEE SALARRY *** \n");
                scanf("%d",&sal);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,sal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,sal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 5){
                printf("*** EMPLOYEE EMAIL *** \n");
                scanf("%s",&email);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,email,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,email,hdphon);
               casethree();
              }
              else if(edit == 6){
                printf("*** EMPLOYEE PHONE *** \n");
                scanf("%ld",&phon);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,phon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,phon);
               casethree();
              }
              else if(edit == 7){
               casethree();
              }
                else{
                    printf("*** PLEASE SELECT FORM 1 TO 6 *** \n");
                }
           }
           else{
            fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
           }
       }
       else{
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
       }
    }
    }
    fclose(fd1);
    fclose(fd2);
    fclose(fd3);
    fclose(fd4);
    remove("Marketing.txt");
    rename("Marketingtemp.txt","Marketing.txt");
    remove("All.txt");
    rename("Alltemp.txt","All.txt");
}
// Accounting Section Edit
void accedit(){
    char name[25];
    char eid[10];
    char title[25];
    int sal;
    char email[35];
    long int phon;
    int edit;
    int ress,ares,aress;
    char dname[25];
    printf("PLEASE WRITE THE NAME \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2,*fd3,*fd4;
    fd1 = fopen("Accounting.txt","r");
    fd2 = fopen("Accountingtemp.txt","w");
    fd3 = fopen("All.txt","r");
    fd4 = fopen("Alltemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    while(fscanf(fd3,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,&hdsal,hdemail,&hdphon)!=EOF){
        ares = strcmp(dnames,hdnames);
        aress = strcmp(dids,hdids);
        if((ares == 0) && (aress == 0)){
           ress = strcmp(dname,dnames);
           if(ress == 0){
              printf("WHAT DO YOU WANT TO EDIT \n\n");
              printf("->-> 0 FOR ALL EDIT -<-< \n");
              printf("->-> 1 FOR NAME -<-< \n");
              printf("->-> 2 FOR E-ID -<-< \n");
              printf("->-> 3 FOR DESIGNATION -<-< \n");
              printf("->-> 4 FOR SALARY -<-< \n");
              printf("->-> 6 FOR PHON -<-< \n");
              scanf("%d",&edit);
              if(edit == 0){

                printf("*** EMPLOYEE NAME *** \n");
                scanf("%s",&name);
                 printf("*** EMPLOYEE ID *** \n");
                 scanf("%s",&eid);
                printf("*** EMPLOYEE DESIGNATION *** \n");
                scanf("%s",&title);
                printf("*** EMPLOYEE SALARRY *** \n");
                scanf("%d",&sal);
                printf("*** EMPLOYEE EMAIL *** \n");
                scanf("%s",&email);
                printf("*** EMPLOYEE PHONE *** \n");
                scanf("%ld",&phon);
                fprintf(fd2,"%s %s %s %d %s %ld\n",name,eid,title,sal,email,phon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",name,eid,title,sal,email,phon);

               casethree();
              }
              else if(edit == 1){
                printf("*** EMPLOYEE NAME *** \n");
                scanf("%s",&name);
                fprintf(fd2,"%s %s %s %d %s %ld\n",name,dids,dtitle,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",name,hdids,hdtitle,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 2){
                 printf("*** EMPLOYEE ID *** \n");
                 scanf("%s",&eid);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,eid,dtitle,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,eid,hdtitle,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 3){
                printf("*** EMPLOYEE DESIGNATION *** \n");
                scanf("%s",&title);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,title,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,title,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 4){
                printf("*** EMPLOYEE SALARRY *** \n");
                scanf("%d",&sal);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,sal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,sal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 5){
                printf("*** EMPLOYEE EMAIL *** \n");
                scanf("%s",&email);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,email,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,email,hdphon);
               casethree();
              }
              else if(edit == 6){
                printf("*** EMPLOYEE PHONE *** \n");
                scanf("%ld",&phon);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,phon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,phon);
               casethree();
              }
              else if(edit == 7){
               casethree();
              }
                else{
                    printf("*** PLEASE SELECT FORM 1 TO 6 *** \n");
                }
           }
           else{
            fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
           }
       }
       else{
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
       }



    }
    }
    fclose(fd1);
    fclose(fd2);
    fclose(fd3);
    fclose(fd4);
    remove("Accounting.txt");
    rename("Accountingtemp.txt","Accounting.txt");
    remove("All.txt");
    rename("Alltemp.txt","All.txt");
}
// Development Section Edit
void divedit(){
    char name[25];
    char eid[10];
    char title[25];
    int sal;
    char email[35];
    long int phon;
    int edit;
    int ress,ares,aress;
    char dname[25];
    printf("PLEASE WRITE THE NAME \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2,*fd3,*fd4;
    fd1 = fopen("Development.txt","r");
    fd2 = fopen("Developmenttemp.txt","w");
    fd3 = fopen("All.txt","r");
    fd4 = fopen("Alltemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    while(fscanf(fd3,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,&hdsal,hdemail,&hdphon)!=EOF){
        ares = strcmp(dnames,hdnames);
        aress = strcmp(dids,hdids);
        if((ares == 0) && (aress == 0)){
           ress = strcmp(dname,dnames);
           if(ress == 0){
              printf("WHAT DO YOU WANT TO EDIT \n\n");
              printf("->-> 0 FOR ALL EDIT -<-< \n");
              printf("->-> 1 FOR NAME -<-< \n");
              printf("->-> 2 FOR E-ID -<-< \n");
              printf("->-> 3 FOR DESIGNATION -<-< \n");
              printf("->-> 4 FOR SALARY -<-< \n");
              printf("->-> 6 FOR PHON -<-< \n");
              scanf("%d",&edit);
              if(edit == 0){

                printf("*** EMPLOYEE NAME *** \n");
                scanf("%s",&name);
                 printf("*** EMPLOYEE ID *** \n");
                 scanf("%s",&eid);
                printf("*** EMPLOYEE DESIGNATION *** \n");
                scanf("%s",&title);
                printf("*** EMPLOYEE SALARRY *** \n");
                scanf("%d",&sal);
                printf("*** EMPLOYEE EMAIL *** \n");
                scanf("%s",&email);
                printf("*** EMPLOYEE PHONE *** \n");
                scanf("%ld",&phon);
                fprintf(fd2,"%s %s %s %d %s %ld\n",name,eid,title,sal,email,phon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",name,eid,title,sal,email,phon);

               casethree();
              }
              else if(edit == 1){
                printf("*** EMPLOYEE NAME *** \n");
                scanf("%s",&name);
                fprintf(fd2,"%s %s %s %d %s %ld\n",name,dids,dtitle,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",name,hdids,hdtitle,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 2){
                 printf("*** EMPLOYEE ID *** \n");
                 scanf("%s",&eid);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,eid,dtitle,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,eid,hdtitle,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 3){
                printf("*** EMPLOYEE DESIGNATION *** \n");
                scanf("%s",&title);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,title,dsal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,title,hdsal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 4){
                printf("*** EMPLOYEE SALARRY *** \n");
                scanf("%d",&sal);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,sal,demail,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,sal,hdemail,hdphon);
               casethree();
              }
              else if(edit == 5){
                printf("*** EMPLOYEE EMAIL *** \n");
                scanf("%s",&email);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,email,dphon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,email,hdphon);
               casethree();
              }
              else if(edit == 6){
                printf("*** EMPLOYEE PHONE *** \n");
                scanf("%ld",&phon);
                fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,phon);
                fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,phon);
               casethree();
              }
              else if(edit == 7){
               casethree();
              }
                else{
                    printf("*** PLEASE SELECT FORM 1 TO 6 *** \n");
                }
           }
           else{
            fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
           }
       }
       else{
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
       }

    }
    }
    fclose(fd1);
    fclose(fd2);
    fclose(fd3);
    fclose(fd4);
    remove("Development.txt");
    rename("Developmenttemp.txt","Development.txt");
    remove("All.txt");
    rename("Alltemp.txt","All.txt");
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
    int ress,ares,aress;

    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2,*fd3,*fd4;
    fd1 = fopen("Development.txt","r");
    fd2 = fopen("Developmenttemp.txt","w");
    fd3 = fopen("All.txt","r");
    fd4 = fopen("Alltemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    while(fscanf(fd3,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,&hdsal,hdemail,&hdphon)!=EOF){
        ares = strcmp(dnames,hdnames);
        aress = strcmp(dids,hdids);
        if((ares == 0) && (aress == 0)){
           ress = strcmp(dname,dnames);
           if(ress == 0){
                fprintf(fd2,"%s",dnamess);
                fprintf(fd3,"%s",dnamess);
           }
           else{
            fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
           }
       }
       else{
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
       }

    }
    }
    fclose(fd1);
    fclose(fd2);
    fclose(fd3);
    fclose(fd4);
    remove("Development.txt");
    rename("Developmenttemp.txt","Development.txt");
    remove("All.txt");
    rename("Alltemp.txt","All.txt");
}
//Accounting Deleting employee
void accudelt(){
    char dnamess[0] = "";
    int ress,ares,aress;

    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2,*fd3,*fd4;
    fd1 = fopen("Accounting.txt","r");
    fd2 = fopen("Accountingtemp.txt","w");
    fd3 = fopen("All.txt","r");
    fd4 = fopen("Alltemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    while(fscanf(fd3,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,&hdsal,hdemail,&hdphon)!=EOF){
        ares = strcmp(dnames,hdnames);
        aress = strcmp(dids,hdids);
        if((ares == 0) && (aress == 0)){
           ress = strcmp(dname,dnames);
           if(ress == 0){
                fprintf(fd2,"%s",dnamess);
                fprintf(fd3,"%s",dnamess);
           }
           else{
            fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
           }
       }
       else{
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
       }

    }
    }
    fclose(fd1);
    fclose(fd2);
    fclose(fd3);
    fclose(fd4);
    remove("Accounting.txt");
    rename("Accountingtemp.txt","Accounting.txt");
    remove("All.txt");
    rename("Alltemp.txt","All.txt");
}

//Marketing Deleting employee
void markdelt(){
    char dnamess[0] = "";
    int ress,ares,aress;

    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2,*fd3,*fd4;
    fd1 = fopen("Marketing.txt","r");
    fd2 = fopen("Marketingtemp.txt","w");
    fd3 = fopen("All.txt","r");
    fd4 = fopen("Alltemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    while(fscanf(fd3,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,&hdsal,hdemail,&hdphon)!=EOF){
        ares = strcmp(dnames,hdnames);
        aress = strcmp(dids,hdids);
        if((ares == 0) && (aress == 0)){
           ress = strcmp(dname,dnames);
           if(ress == 0){
                fprintf(fd2,"%s",dnamess);
                fprintf(fd3,"%s",dnamess);
           }
           else{
            fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
           }
       }
       else{
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
       }

    }
    }
    fclose(fd1);
    fclose(fd2);
    fclose(fd3);
    fclose(fd4);
    remove("Marketing.txt");
    rename("Marketingtemp.txt","Marketing.txt");
    remove("All.txt");
    rename("Alltemp.txt","All.txt");
}


//Human Deleting employee
void humdelt(){
    char dnamess[0] = "";
    int ress,ares,aress;

    char dname[25];
    printf("please insert the name \n");
    scanf("%s",&dname);
    FILE *fd1,*fd2,*fd3,*fd4;
    fd1 = fopen("Human.txt","r");
    fd2 = fopen("Humantemp.txt","w");
    fd3 = fopen("All.txt","r");
    fd4 = fopen("Alltemp.txt","w");
    while(fscanf(fd1,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    while(fscanf(fd3,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,&hdsal,hdemail,&hdphon)!=EOF){
        ares = strcmp(dnames,hdnames);
        aress = strcmp(dids,hdids);
        if((ares == 0) && (aress == 0)){
           ress = strcmp(dname,dnames);
           if(ress == 0){
                fprintf(fd2,"%s",dnamess);
                fprintf(fd3,"%s",dnamess);
           }
           else{
            fprintf(fd2,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,dsal,demail,dphon);
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
           }
       }
       else{
            fprintf(fd4,"%s %s %s %d %s %ld\n",hdnames,hdids,hdtitle,hdsal,hdemail,hdphon);
       }

    }
    }
    fclose(fd1);
    fclose(fd2);
    fclose(fd3);
    fclose(fd4);
    remove("Human.txt");
    rename("Humantemp.txt","Human.txt");
    remove("All.txt");
    rename("Alltemp.txt","All.txt");
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
void displayall(){
    FILE *fa;
    fa = fopen("All.txt","r");
    while(fscanf(fa,"%s %s %s %d %s %ld\n",dnames,dids,dtitle,&dsal,demail,&dphon)!=EOF){
    dis();
    }
    fclose(fa);
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

          printf("\xB3 5 FOR SHOW ALL EMPLOYEE   \xB3 \n");
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
            case 5:{
                system("cls");
                printf(">>>>>>> ALL DEPERTMENT'S EMPLOYEEE'S INFO <<<<<<<<\n");
                displayall();
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

void add(FILE *fd,FILE *fa){
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
    fprintf(fa,"%s %s %s %d %s %ld\n",name,eid,title,sal,email,phon);
    fclose(fd);
    fclose(fa);

}

void development(){
    int res,data;
    FILE *fd,*fa;
    fd = fopen("Development.txt","a");
    fa = fopen("All.txt","a");
    add(fd,fa);
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
    FILE *fd,*fa;
    fd = fopen("Accounting.txt","a");
    fa = fopen("All.txt","a");
    add(fd,fa);
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
    FILE *fm,*fa;
    fm = fopen("Marketing.txt","a");
    fa = fopen("All.txt","a");
    add(fm,fa);
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
    FILE *fh,*fa;
    fh = fopen("Human.txt","a");
    fa = fopen("All.txt","a");
    add(fh,fa);
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








