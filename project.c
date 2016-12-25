#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

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
      printf("\xB3 5 FOR EXIT                     \xB3 \n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");

}
void development(){
    FILE *fd;
    char name[25];
    char title[25];
    int sal;
    char email[35];
    char phon[15];
    printf("*** EMPLOYEE NAME *** \n");
    scanf("%s",&name);
    printf("*** EMPLOYEE TITLE *** \n");
    scanf("%s",&title);
    printf("*** EMPLOYEE SALARRY *** \n");
    scanf("%d",&sal);
    printf("*** EMPLOYEE PHONE *** \n");
    scanf("%s",&phon);
    printf("*** EMPLOYEE EMAIL *** \n");
    scanf("%s",&email);
    fd = fopen("dev.txt","a");
    fprintf(fd,"%s   %s  %d   %s   %s \n",name,title,sal,email,phon);
    fclose(fd);
    printf("********** DATA INSERTED SUCESSFULLY ********* \n");
}


int main(){

    int s = 0;
    system("COLOR 57");
    int pass,ch,sec;
    printf("********* WELCOME TO HI-TECH SOFTWORE SOLUTION ************ \n");
    printf("~~~~~~~~ PLEASE ENTER YOUR PASSWORD ~~~~~~~~~\n");
    scanf("%d",&pass);
    if(pass == 12){
        system("COLOR 71");

        do{
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
          menu();
          scanf("%d",&ch);
          switch(ch){
            case 1:{do{
                section();
                  scanf("%d",&sec);
                  switch(sec){
                    case 1:{
                        development();
                        break;
                    }
                    case 2:{
                        printf("you select case 2 \n");
                        break;
                    }
                    case 3:{
                        printf("you select case 3 \n");
                        break;
                    }
                    case 4:{
                        printf("you select case 3 \n");
                        break;
                    }
                    case 5:{
                        break;
                    }
                  }
                  }

                while(ch != 0);
            }
          }
          }


          while(ch != 0);


    }
    else{
        printf("Password isn't correct ");
    }

}








