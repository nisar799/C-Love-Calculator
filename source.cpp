/*
Author - Nisar Ahmed.
Description - It takes two names and then calculate Love and Friendship percentage of these names.
*/

#include< conio.h>
#include< iostream.h>
#include< string.h>
#include< stdio.h>
#include< stdlib.h>

int calcPercentage(int l,int h,int ar[]);

struct nameModel
{
    char name[100];
    int isCounted[100];
}nameObject;

int main(){
    textmode(C40);
    textbackground(GREEN);
    textcolor(WHITE);
    do{
        x:
        clrscr();
        int count,a=0,ar[20],i,j;
        char name1[40],ch,name2[40],choice;
        cout<<"\n";
        cout<<"------- 799 Web Nixar Creation ---------";
        cout<<"----------------------------------------";
        cout<<"|      * Welcome To Friendship *       |";
        cout<<"|       *  & Love Calculator  *        |";
        cout<<"----------------------------------------";
        cout<<"              1.Friendship              ";
        cout<<"              2.Love                    ";
        cout<<"              3.Exit                    ";
        cout<<"       Enter Your Choice                ";
        gotoxy(28,10);
        cin>>choice;
        switch(choice)
        {
            case '1':    
			cout<<"                                        ";
            cout<<"        ----------------------          ";
            cout<<"           Enter Your Name              ";
            gotoxy(17,14);
            gets(name1);
            cout<<"        ----------------------          ";
            cout<<"       Enter Your Friend's Name         ";
            gotoxy(17,17);
            gets(name2);
            cout<<"        ----------------------          ";
            break;
        case '2': 
			cout<<"                                        ";
            cout<<"        ----------------------          ";
            cout<<"           Enter Your Name              ";
            gotoxy(17,14);
            gets(name1);
            cout<<"        ----------------------          ";
            cout<<"        Enter Your Lover's Name         ";
            gotoxy(17,17);
            gets(name2);
            cout<<"        ----------------------          ";
            break;
        case '3':
			exit(1);
            break;
        default:
			cout<<"             Wrong Choice !!            ";
            goto x;
        }
        strlwr(name1);
        strlwr(name2);
        if(choice=='1')
            strcat(name1,"friend");
        else
            strcat(name1,"love");
        strcat(name1,name2);
        strcpy(nameObject.name,name1);
        for(i=0;i< strlen(name1);i++){
            nameObject.isCounted[i]=0;
        }
        for(i=0;i< strlen(nameObject.name);i++){
            if(nameObject.isCounted[i]==0){
                ch=nameObject.name[i];
                if(ch==' ')
                    continue;
                count=1;
                nameObject.isCounted[i]=1;
                for(j=i+1;j< strlen(nameObject.name);j++){
                    if(ch==nameObject.name[j]){
                        count+=1;
                        nameObject.isCounted[j]=1;
                    }
                }
                ar[a++]=count;
            }
        }
        gotoxy(18,19);
        cout<< calcPercentage(0,(a-1),ar) << "%\n\n\n";
        cout<< "########################################";
        getch();
    }while(1);
    return 0;
}
int calcPercentage(int l,int h,int ar[])
{
    int i,r=0,j,sum;
    if((l+h)%2 == 0){
        for(i=l,j=h;i < j;i++,j--)
            ar[r++]=ar[i]+ar[j];
        ar[r++]=ar[i];
    }
    else{
        for(i=l,j=h;i < j;i++,j--)
            ar[r++]=ar[i]+ar[j];
    }
    h=r-1;
    if(l+h > 1)
        calcPercentage(l,h,ar);
    else{
        sum=0;
        for(i=0;i < 2;i++){
        if(i==0)
            sum+=ar[i]*10;
        else
            sum+=ar[i];
        }
        while(sum > 100){
            sum = (sum%10)*10 +(sum/10);
        }
    return sum;
    }
}
