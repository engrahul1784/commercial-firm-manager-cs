#include<simplecpp>
#include<limits>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include"hc.h"
#include"manu.h"

//function defined for getclick() function

int validaterect(int cx,int cy , int x, int y, int l, int h)
{

    if(cx+(l/2) > x && cx-(l/2) < x && cy+(h/2) > y && cy-(h/2) < y) return 1;
    else return 0;
}



int strcmp1(char *a,char *b)//for comparison of two char variables
    {   int flag=1;
        for(int i=0;a[i]!='\0';i++)
        {
            if(a[i]=='\0') break;
            if(a[i]!=b[i]) {flag=0;break;}

        }
      return flag;
    }






//function defined to show'*' while entering the password
char* cpasskey(int x=-1,int y=-1) {
           int isvalid(char );
            int i,flag=0,ctr=0,ctr1=0;
            char temp[80],str[80],str2[2];
            XEvent e1;
            Text t[80];
            str2[1]='\0';
            for(i=0;;i++)
                {
                  nextEvent(e1);
                  if(x==-1) {i=0;continue;}
                  temp[i]=charFromEvent(e1);
                  if(temp[i]==8)
                            {temp[i]=' ';
                            temp[i-1]=' ';
                            str2[0]=temp[i-1];
                            x-=8;
                            Text te(x,y,str2);
                            i-=2;
                            ctr--;
                            continue;


                            }


                  if(isvalid(temp[i]))
                    flag=1;
                  if((flag==1)&&(i>=1))

                        { str[ctr]=temp[i];
                          ctr++;
                        }
                   if(temp[i]==13)
                        {
                            break;
                        }
                  if(i>=1)
                  {str2[0]='*';
                   t[i].reset(x,y,str2);

                   x+=8;
                  }

                }

              str[ctr]='\0';
              return str;
        }


// billing prepartion function and window defined here
int prdctqty[18];
int z=0;
void preparebill(){

manfuct m;
fstream file;
file.open("man1",ios::binary|ios::in|ios::out);
file.seekp(0,ios::beg);
Rectangle r78(250,250,500,500);
r78.setColor(COLOR(30,100,50));
r78.setFill();
char b[10];
Text t143(150,100,"Customer Name :");
strcpy(b,cinstr(300,100));
Text p123(300,100,b);
Text t1431(250,150,"Bill");
Text t132(100,200,"Product");
Text t1321(250,200,"Quantity");
Text t1322(350,200,"Rate");
Text t1323(420,200,"Price");
Text t1[100],t2[100],t3[100],t4[100];
int y=20,i=0;
double total=0;
while(file.read((char*)&m,sizeof(m)))
{
  t1[i]={100,200+y,m.pronam};
  t2[i]={250,200+y,prdctqty[i]};
  t3[i]={350,200+y,m.rate};
  t4[i]={420,200+y,m.rate*prdctqty[i]};

  total+=(prdctqty[i]*m.rate);

  i++;
  y=y+20;

}
Text t445454(420,450,"TOTAL = ");
Text t344345(450,450,total);
file.close();
wait(4);





}


void billing(){Rectangle r1(250,250,500,500),lr2(250,280,400,300);
r1.setColor(COLOR(0,100,400));
r1.setFill();

char product[10][100];
int productqty[100];
double productprice[10];
fstream file;
file.open("man1",ios::binary|ios::in|ios::out);
manfuct m;


while(file.read((char*)&m,sizeof(m))) //reading of data from manufactured stock in billing
{
strcpy(product[z],m.pronam);
 productprice[z]=m.rate;
 productqty[z]=m.quantity;
 z++;
}

Text t1(250,50,"Welcome to shop");

Text t2(250,100,"Select the item no.");
Text t8(120,140,"Product List ");
Text t4(250,140,"Quantity");
Text t3[100];
int y0 = 200;
int l=0;
while(l<z)
{t3[l]={100,y0,product[l]};

l++;
y0 = y0+20;}

Text t232(250,450,"Prepare Bill");


for(int i=0;i<18;i++){
prdctqty[i] = 0;}

while(true){
int v = getClick();
int x = v/65536;
int y = v%65536;

int k = 0;
int y0 = 200;

while(k<z)
{
if(validaterect(100,y0,x,y,50,10)) {
    prdctqty[k]++;
    Text t199(300,y0,prdctqty[k]);
    wait(2);}

  k++;
  y0 = y0+20;

file.close();}

if(validaterect(250,450,x,y,70,10)) {

    preparebill();
    wait(4);




}

};


wait(100);

}





//function defined to get password and username form user
void passbill(){

    char pass[] = {"awesome"};
    char str2[50];

    Rectangle r434(250,250,500,500);
r434.setColor(COLOR(250,120,35));
r434.setFill();
Text t333(250,100,"Login");
Text t434(100,300,"USERNAME");
Text t4341(100,350,"PASSWORD");
Rectangle r32(400,300,100,20);
Rectangle r33(400,350,100,20),r34(250,450,500,30);
r34.setFill(true);
r34.setColor(COLOR(100,100,50));
Text tp1(250,450,"Click here for main menu");
while(true){
int v = getClick();
int x = v/65536;
int y = v%65536;
 if(validrect(400,350,x,y,70,20)){
    strcpy(str2,cpasskey(400,350));
    if(strcmp1(pass,str2)==1){
    billing();}
if (validrect(250,450,x,y,500,50)){delay(2000);}

    else {Text t34212(250,450,"Invalid Username or Password !");
            wait(2);}}}
wait(15);

}




void userbill(){
Rectangle r434(250,250,500,500);
r434.setColor(COLOR(250,120,35));
r434.setFill();





char user[] = {"life's"};//username and password predefined for login
Text t3432(250,100,"Login");

Text t434(100,300,"USERNAME");
Text t4341(100,350,"PASSWORD");



char* cinstr(int,int);
 char* cpasskey(int ,int);
        int strcmp1(char* ,char*);

Rectangle r32(400,300,100,20);
Rectangle r33(400,350,100,20);



char str[50];

while(true){
int v = getClick();
int x = v/65536;
int y = v%65536;






if(validrect(400,300,x,y,70,20)) {
strcpy(str,cinstr(400,300));
if(strcmp1(user,str) == 1 ){passbill();


    }

    else {Text t34212(250,450,"Invalid Username or Password !");
            wait(3);}
}

    }
}







//funtion defined for credit and debit window
    void cred(){
Rectangle r549(250,250,500,500);
r549.setFill();
r549.setColor(COLOR(144,134,242));


Text t6(250,100,"CREDIT");
Text t7(120,200,"Name : ");
Text t8(300,200,"Amount");
Text t9(400,200,"Date");

 int y = 180;
Line l1(0,y,500,y);
y = y+30;
Line l99(0,y,500,y);
y = y+30;Line l2(0,y,500,y);
y = y+30;Line l3(0,y,500,y);
y = y+30;Line l4(0,y,500,y);
y = y+30;Line l5(0,y,500,y);
y = y+30;Line l6(0,y,500,y);
y = y+30;Line l7(0,y,500,y);
y = y+30;Line l8(0,y,500,y);
y = y+30;Line l9(0,y,500,y);
y = y+30;

Line l21(220,180,220,500);

Line l222(350,180,350,500);


fstream file;
file.open("Credit9991.txt",ios::in|ios::out|ios::app);

int ydir=220;char cmd[10] ;

char cre[50];
char cre2[50];
char cre3[50];

char cre4[50];
char cre5[50];
char cre6[50];


for(int i=0;i<50;i++){

    cre[i] = 0;
    cre2[i] = 0;
    cre3[i] = 0;
     cre4[i] = 0;
    cre5[i] = 0;
    cre6[i] = 0;
}

while(true){
    int v = getClick();
int x = v/65536;
int y = v%65536;


if(validaterect(120,220,x,y,100,20)){

strcpy(cre,cinstr(120,220));
Text t99(120,220,cre);

strcpy(cre2,cinstr(300,220));
Text t991(300,220,cre2);

strcpy(cre3,cinstr(400,220));
Text t5421(400,220,cre3);

strcpy(cre4,cinstr(120,250));
Text t99111(120,250,cre4);

strcpy(cre5,cinstr(300,250));
Text t9911(300,250,cre5);

strcpy(cre6,cinstr(400,250));
Text t54211(400,250,cre6);

file.write((char*)&cre,sizeof(cre));  //writing of entries into binary file
file.write((char*)&cre2,sizeof(cre2));
file.write((char*)&cre3,sizeof(cre3));
file.write((char*)&cre4,sizeof(cre4));
file.write((char*)&cre5,sizeof(cre5));
file.write((char*)&cre6,sizeof(cre6));
file.close();
break;
}

}
delay(2000);
}





int deb(){ //debit window
Rectangle r549(250,250,500,500);
r549.setFill();
r549.setColor(COLOR(200,230,150));


Text t6(250,100,"DEBIT");
Text t7(120,200,"Name : ");
Text t8(300,200,"Amount");
Text t9(400,200,"Date");

 int y = 180;
Line l1(0,y,500,y);
y = y+30;
Line l99(0,y,500,y);
y = y+30;Line l2(0,y,500,y);
y = y+30;Line l3(0,y,500,y);
y = y+30;Line l4(0,y,500,y);
y = y+30;Line l5(0,y,500,y);
y = y+30;Line l6(0,y,500,y);
y = y+30;Line l7(0,y,500,y);
y = y+30;Line l8(0,y,500,y);
y = y+30;Line l9(0,y,500,y);
y = y+30;

Line l21(220,180,220,500);

Line l222(350,180,350,500);


fstream file1;
file1.open("Debit9991.txt",ios::in|ios::out|ios::app);  //binary for storing data


char cre[50];
char cre2[50];
char cre3[50];

char cre4[50];
char cre5[50];
char cre6[50];


for(int i=0;i<50;i++){

    cre[i] = 0;
    cre2[i] = 0;
    cre3[i] = 0;
     cre4[i] = 0;
    cre5[i] = 0;
    cre6[i] = 0;
}

while(true){
    int v = getClick();
int x = v/65536;
int y = v%65536;


if(validaterect(120,220,x,y,100,20)){

strcpy(cre,cinstr(120,220));
Text t99(120,220,cre);

strcpy(cre2,cinstr(300,220));
Text t991(300,220,cre2);

strcpy(cre3,cinstr(400,220));
Text t5421(400,220,cre3);

strcpy(cre4,cinstr(120,250));
Text t9922(120,250,cre4);

strcpy(cre5,cinstr(300,250));
Text t99122(300,250,cre5);

strcpy(cre6,cinstr(400,250));
Text t542122(400,310,cre6);




file1.write((char*)&cre,sizeof(cre));
file1.write((char*)&cre2,sizeof(cre2));
file1.write((char*)&cre3,sizeof(cre3));
file1.write((char*)&cre4,sizeof(cre4));
file1.write((char*)&cre5,sizeof(cre5));
file1.write((char*)&cre6,sizeof(cre6));
file1.close();
break;
}

};
delay(2000);
}

int debshow(){                          //show of debit entries
Rectangle r549(250,250,500,500);
r549.setFill();
r549.setColor(COLOR(200,230,150));


Text t6(250,100,"DEBIT SHOW");
Text t7(120,200,"Name : ");
Text t8(300,200,"Amount");
Text t9(400,200,"Date");

 int y = 180;
Line l1(0,y,500,y);
y = y+30;
Line l99(0,y,500,y);
y = y+30;Line l2(0,y,500,y);
y = y+30;Line l3(0,y,500,y);
y = y+30;Line l4(0,y,500,y);
y = y+30;Line l5(0,y,500,y);
y = y+30;Line l6(0,y,500,y);
y = y+30;Line l7(0,y,500,y);
y = y+30;Line l8(0,y,500,y);
y = y+30;Line l9(0,y,500,y);
y = y+30;

Line l21(220,180,220,500);

Line l222(350,180,350,500);
char cre[50];
char cre2[50];
char cre3[50];

char cre4[50];
char cre5[50];
char cre6[50];


for(int i=0;i<50;i++){

    cre[i] = 0;
    cre2[i] = 0;
    cre3[i] = 0;
     cre4[i] = 0;
    cre5[i] = 0;
    cre6[i] = 0;
}

fstream file1;
file1.open("Debit9991.txt",ios::in|ios::out|ios::app);


file1.read((char*)&cre,sizeof(cre));
file1.read((char*)&cre2,sizeof(cre2));
file1.read((char*)&cre3,sizeof(cre3));
file1.read((char*)&cre4,sizeof(cre4));
file1.read((char*)&cre5,sizeof(cre5));
file1.read((char*)&cre6,sizeof(cre6));


int ydir=220;char cmd[10] ;



while(true){
    int v = getClick();
int x = v/65536;
int y = v%65536;


if(validaterect(120,220,x,y,100,20)){

Text t99(120,220,cre);


Text t991(300,220,cre2);


Text t5421(400,220,cre3);


Text t9922(120,250,cre4);


Text t99122(300,250,cre5);


Text t542122(400,250,cre6);





file1.close();

wait(6);
break;
};

delay(2000);
wait(5);
}



}
int credshow(){
Rectangle r549(250,250,500,500);
r549.setFill();
r549.setColor(COLOR(200,230,150));


Text t6(250,100,"CREDIT SHOW");
Text t7(120,200,"Name : ");
Text t8(300,200,"Amount");
Text t9(400,200,"Date");

 int y = 180;
Line l1(0,y,500,y);
y = y+30;
Line l99(0,y,500,y);
y = y+30;Line l2(0,y,500,y);
y = y+30;Line l3(0,y,500,y);
y = y+30;Line l4(0,y,500,y);
y = y+30;Line l5(0,y,500,y);
y = y+30;Line l6(0,y,500,y);
y = y+30;Line l7(0,y,500,y);
y = y+30;Line l8(0,y,500,y);
y = y+30;Line l9(0,y,500,y);
y = y+30;

Line l21(220,180,220,500);

Line l222(350,180,350,500);
char cre[50];
char cre2[50];
char cre3[50];

char cre4[50];
char cre5[50];
char cre6[50];


for(int i=0;i<50;i++){

    cre[i] = 0;
    cre2[i] = 0;
    cre3[i] = 0;
     cre4[i] = 0;
    cre5[i] = 0;
    cre6[i] = 0;
}

fstream file;
file.open("Credit9991.txt",ios::in|ios::out|ios::app);


file.read((char*)&cre,sizeof(cre));
file.read((char*)&cre2,sizeof(cre2));
file.read((char*)&cre3,sizeof(cre3));
file.read((char*)&cre4,sizeof(cre4));
file.read((char*)&cre5,sizeof(cre5));
file.read((char*)&cre6,sizeof(cre6));





while(true){
    int v = getClick();
int x = v/65536;
int y = v%65536;


if(validaterect(120,220,x,y,100,20)){

Text t99(120,220,cre);


Text t991(300,220,cre2);


Text t5421(400,220,cre3);


Text t9922(120,250,cre4);


Text t99122(300,250,cre5);


Text t542122(400,250,cre6);





file.close();

wait(10);
};

delay(2000);
wait(5);
}
}




void crdr(){ Rectangle r549(250,250,500,500); //homepage of credit and debit
r549.setFill();
r549.setColor(COLOR(150,198,230));

Rectangle r3233(100,200,100,30);
Rectangle r32343(100,300,100,30);
Rectangle r323243(300,250,100,30);
Rectangle r3233241(300,350,100,30);

Text t4(100,200,"@  Credit");
Text t44(300,350,"Show Debit");
Text t5(100,300,"@  Debit");
Text t65(300,250,"Show Credit");

while(true){
    int v = getClick();
int x = v/65536;
int y = v%65536;

if(validaterect(100,200,x,y,200,20)){
        cred();

}

if(validaterect(100,300,x,y,200,20))
{
    deb();
}
if(validaterect(350,350,x,y,200,20))
{
    debshow();
}

if(validaterect(350,250,x,y,200,20))
{
    credshow();
}

if(validaterect(450,450,x,y,100,100))
{
    delay(2000);
}

}
wait(10);





}

















    void cred1(){
Rectangle r549(250,250,500,500);
r549.setFill();
r549.setColor(COLOR(144,134,242));


Text t6(250,100,"January EXPENDITURE");
Text t7(120,200,"TYPE ");
Text t8(300,200,"Amount");
Text t9(400,200,"Date");

 int y = 180;
Line l1(0,y,500,y);
y = y+30;
Line l99(0,y,500,y);
y = y+30;Line l2(0,y,500,y);
y = y+30;Line l3(0,y,500,y);
y = y+30;Line l4(0,y,500,y);
y = y+30;Line l5(0,y,500,y);
y = y+30;Line l6(0,y,500,y);
y = y+30;Line l7(0,y,500,y);
y = y+30;Line l8(0,y,500,y);
y = y+30;Line l9(0,y,500,y);
y = y+30;

Line l21(220,180,220,500);

Line l222(350,180,350,500);


fstream file11;
file11.open("expen9991.txt",ios::in|ios::out|ios::app);

int ydir=220;char cmd[10] ;

char cre[50];
char cre2[50];
char cre3[50];

char cre4[50];
char cre5[50];
char cre6[50];


for(int i=0;i<50;i++){

    cre[i] = 0;
    cre2[i] = 0;
    cre3[i] = 0;
     cre4[i] = 0;
    cre5[i] = 0;
    cre6[i] = 0;
}

while(true){
    int v = getClick();
int x = v/65536;
int y = v%65536;


if(validaterect(120,220,x,y,100,20)){

strcpy(cre,cinstr(120,220));
Text t99(120,220,cre);

strcpy(cre2,cinstr(300,220));
Text t991(300,220,cre2);

strcpy(cre3,cinstr(400,220));
Text t5421(400,220,cre3);

strcpy(cre4,cinstr(120,250));
Text t99111(120,250,cre4);

strcpy(cre5,cinstr(300,250));
Text t9911(300,250,cre5);

strcpy(cre6,cinstr(400,250));
Text t54211(400,250,cre6);

file11.write((char*)&cre,sizeof(cre));
file11.write((char*)&cre2,sizeof(cre2));
file11.write((char*)&cre3,sizeof(cre3));
file11.write((char*)&cre4,sizeof(cre4));
file11.write((char*)&cre5,sizeof(cre5));
file11.write((char*)&cre6,sizeof(cre6));
file11.close();
break;
}

}
delay(2000);
}







int credshow1(){//funtion defined to show expenditure show window
Rectangle r549(250,250,500,500);
r549.setFill();
r549.setColor(COLOR(200,230,150));


Text t6(250,100,"January EXPENDITURE SHOW");
Text t7(120,200,"TYPE");
Text t8(300,200,"Amount");
Text t9(400,200,"Date");

 int y = 180;
Line l1(0,y,500,y);
y = y+30;
Line l99(0,y,500,y);
y = y+30;Line l2(0,y,500,y);
y = y+30;Line l3(0,y,500,y);
y = y+30;Line l4(0,y,500,y);
y = y+30;Line l5(0,y,500,y);
y = y+30;Line l6(0,y,500,y);
y = y+30;Line l7(0,y,500,y);
y = y+30;Line l8(0,y,500,y);
y = y+30;Line l9(0,y,500,y);
y = y+30;

Line l21(220,180,220,500);

Line l222(350,180,350,500);
char cre[50];
char cre2[50];
char cre3[50];

char cre4[50];
char cre5[50];
char cre6[50];


for(int i=0;i<50;i++){

    cre[i] = 0;
    cre2[i] = 0;
    cre3[i] = 0;
     cre4[i] = 0;
    cre5[i] = 0;
    cre6[i] = 0;
}

fstream file11;
file11.open("expen9991.txt",ios::in|ios::out|ios::app);


file11.read((char*)&cre,sizeof(cre));
file11.read((char*)&cre2,sizeof(cre2));
file11.read((char*)&cre3,sizeof(cre3));
file11.read((char*)&cre4,sizeof(cre4));
file11.read((char*)&cre5,sizeof(cre5));
file11.read((char*)&cre6,sizeof(cre6));






while(true){
    int v = getClick();
int x = v/65536;
int y = v%65536;


if(validaterect(120,220,x,y,100,30)){

Text t99(120,220,cre);


Text t991(300,220,cre2);


Text t5421(400,220,cre3);


Text t9922(120,250,cre4);


Text t99122(300,250,cre5);


Text t542122(400,250,cre6);





file11.close();

wait(6);
break;
};

delay(2000);
wait(5);
}
}
void expwin(){
Rectangle r1(250,250,500,500);

Rectangle r9898(250,50,50,30);
Text t657(230,50,"Show");

Rectangle(30,450,50,30);
Text t4570(30,450,"Back");

int x=100;int y=50,l=50,p=100;Rectangle q1(x,y,100,30);y+=35;
Rectangle q2(x,y,100,30);y+=35;
Rectangle q3(x,y,100,30);y+=35;
Rectangle q4(x,y,100,30);y+=35;
Rectangle q5(x,y,100,30);y+=35;
Rectangle q6(x,y,100,30);y+=35;x+=200;
Rectangle q7(x,y,100,30);y+=35;
Rectangle q8(x,y,100,30);y+=35;
Rectangle q9(x,y,100,30);y+=35;
Rectangle q10(x,y,100,30);y+=35;
Rectangle q11(x,y,100,30);y+=35;
Rectangle q12(x,y,100,30);

Text m1(p,l,"January");l+=35;
Text m2(p,l,"February");l+=35;
Text m3(p,l,"March");l+=35;
Text m4(p,l,"April");l+=35;
Text m5(p,l,"May");l+=35;
Text m6(p,l,"June");l+=35;p+=200;
Text m7(p,l,"July");l+=35;
Text m8(p,l,"August");l+=35;
Text m9(p,l,"September");l+=35;
Text m10(p,l,"October");l+=35;
Text m11(p,l,"November");l+=35;Text m12(p,l,"December");l+=35;
while(true){
 int clickpos= getClick();
    int x= clickpos/65536;
    int y =clickpos%65536;



if (validaterect(100,50,x,y,100,30)){

    cred1();

}

if (validaterect(250,50,x,y,50,30)){

    credshow1();

}

if(validaterect(30,450,x,y,50,30)){
 break;
}

}
delay(2000);
wait (10);

}


void window1()   //rawstock homepage
{

    Rectangle r1(650,350,1400,700);
    r1.setFill(true);
    r1.setColor(COLOR(124,20,140));
    Text t1(350,50,"RAW STOCK");
    const double bfx=150 ,bfy= 150,blx=150,bly= 200 ,bwidth=150,bheight=35,sfx=150,sfy=250,afx=150,afy=300,lfx=150,lfy=350;
    Rectangle buttonI (bfx,bfy,bwidth,bheight),bottonD(blx,bly,bwidth,bheight);
    Rectangle buttonSD(sfx,sfy,bwidth,bheight),buttonAD (afx,afy,bwidth,bheight),buttonSL (lfx,lfy,bwidth,bheight);
    Text tf(bfx,bfy," ENTER ITEMS "),tg(blx,bly,"SHOW DATA"),ts(sfx,sfy,"SHOW SPECIFIC");
    Text tk(afx,afy ,("ALTER DATA")),tl(lfx,lfy,"DELETE ITEM");
    Rectangle r5(250,450,500,30);
    r5.setFill(true);

    r5.setColor(COLOR(100,250,0));
    Text tb(250,450,"Click Here For Main Menu <---");


    rawstock a;
shuru :
while(true){
    int clickpos= getClick();
    int cx= clickpos/65536;
    int cy =clickpos%65536;

    if (bfx-bwidth/2 <cx && cx<=bfx+bwidth/2&&bfy-bheight/2<=cy && cy <=bfy+bheight/2)
    {
        Rectangle rak1(250,250,500,500);
        rak1.setFill(true);
        rak1.setColor(COLOR(150,150,150));
        a.getdata1();

        goto shuru;


    }

    if (validrect(150,200,cx,cy,150,35))               //conditions of validating click
    {
        Rectangle rak1(250,250,500,500);
        rak1.setFill(true);
        rak1.setColor(COLOR(150,150,150));
        wait(5);
        a.showdata1();
        goto shuru;
    }
    if(sfx-bwidth/2 <cx && cx<=sfx+bwidth/2&&sfy-bheight/2<=cy && cy <=sfy+bheight/2)
    {
        Rectangle rak1(250,250,500,500);
        rak1.setFill(true);
        rak1.setColor(COLOR(150,150,150));

        a.showspecific1();
        goto shuru;

    }

    if (lfx-bwidth/2 <cx && cx<=lfx+bwidth/2&&lfy-bheight/2<=cy && cy <=lfy+bheight/2)
    {
        Rectangle rak1(250,250,500,500);
        rak1.setFill(true);
        rak1.setColor(COLOR(150,150,150));
        a.deletedata();
        goto shuru;
    }
    if (afx-bwidth/2 <cx && cx<=afx+bwidth/2&&afy-bheight/2<=cy && cy <=afy+bheight/2)
    {
        Rectangle rak1(250,250,500,500);
        rak1.setFill(true);
        rak1.setColor(COLOR(150,150,150));
        a.alterdata1();
        goto shuru;
    }

    if( validrect(250,450,cx,cy,500,50))
    {
        break;
    };
}
delay(1000);
}












void window2()//window defined for manufactured product window
{
    manfuct a;


    Rectangle r1( 250,250,500,500);
    r1.setFill(true);
    r1.setColor(COLOR(255,200,0));
    Text t1(250,50, "MANUFACTURED PRODUCTS "); const double bfx=150 ,bfy= 150,blx=150,bly= 200 ,bwidth=150,bheight=35,sfx=150,sfy=250,afx=150,afy=300,lfx=150,lfy=350;
    Rectangle buttonI (bfx,bfy,bwidth,bheight),bottonD(blx,bly,bwidth,bheight);
    Rectangle buttonSD(sfx,sfy,bwidth,bheight),buttonAD (afx,afy,bwidth,bheight),buttonSL (lfx,lfy,bwidth,bheight);
    Text tf(bfx,bfy," ENTER ITEMS "),tg(blx,bly,"SHOW DATA"),ts(sfx,sfy,"SHOW SPECIFIC");
    Text tk(afx,afy ,("ALTER DATA")),tl(lfx,lfy,"DELETE ITEM");
    Rectangle r5(250,450,500,30);
    r5.setFill(true);
    r5.setColor(COLOR(100,250,0));
    Text tb(250,450,"Click Here For Main Menu <---");


shuru ://initial point point defined
while(true){
    int clickpos= getClick();
    int cx= clickpos/65536;
    int cy =clickpos%65536;

    if (bfx-bwidth/2 <cx && cx<=bfx+bwidth/2&&bfy-bheight/2<=cy && cy <=bfy+bheight/2)
    {
        Rectangle rak1(250,250,500,500);
        rak1.setFill(true);
        rak1.setColor(COLOR(150,150,150));
        a.getdata1();//get information regarding product

        goto shuru;


    }

    if (validrect(150,200,cx,cy,150,35))
    {
        Rectangle rak1(250,250,500,500);
        rak1.setFill(true);
        rak1.setColor(COLOR(150,150,150));
        wait(5);
        a.showdata1();//show information regarding product
        goto shuru;
    }
    if(sfx-bwidth/2 <cx && cx<=sfx+bwidth/2&&sfy-bheight/2<=cy && cy <=sfy+bheight/2)
    {
        Rectangle rak1(250,250,500,500);
        rak1.setFill(true);
        rak1.setColor(COLOR(150,150,150));

        a.showspecific1();//show specific information
        goto shuru;

    }

    if (lfx-bwidth/2 <cx && cx<=lfx+bwidth/2&&lfy-bheight/2<=cy && cy <=lfy+bheight/2)
    {
        Rectangle rak1(250,250,500,500);
        rak1.setFill(true);
        rak1.setColor(COLOR(150,150,150));
        a.deletedata();//delete the item
        goto shuru;
    }
    if (afx-bwidth/2 <cx && cx<=afx+bwidth/2&&afy-bheight/2<=cy && cy <=afy+bheight/2)
    {
        Rectangle rak1(250,250,500,500);
        rak1.setFill(true);
        rak1.setColor(COLOR(150,150,150));
        a.alterdata1();//alter the information
        goto shuru;
    }

    if( validrect(250,450,cx,cy,500,50))
    {
    break;
    };
}delay(1000);

}





void get_details()// information regarding frim
{


    Rectangle v1(250,250,500,500);
    v1.setFill(true);
    v1.setColor(COLOR(100,175,250));
    Text s1(250,50," Comapany Details ");
    const int  a1=100,a2=200,b2=250,c2=300,w1=100,h1=20;
    Rectangle v2(a1,a2,w1,h1),v3(a1,b2,w1,h1),v4(a1,c2,w1,h1),v5(250,450,400,20),v6(a1,340,w1,h1),v7(a1,375,w1,h1);


    Text s2(a1,a2,"Firm Name ");
    Text s3(a1,b2,"Firm Type ");
    Text s4(a1,c2,"Owner Name ");
    Text s5(a1,340,"Address  ");
    Text s6(a1,375,"Contact NO ");
    Text s7(250,450,"Click Here To Procced ---> ");


    char firm_name[100],Firm_type[100],Owner_Name[100],Address[100],Contactno[100];
    cout<<"Input 1.Firm Name \n";
    cout<<"2. Firm Type\n";
    cout<<"3.OwnerName \n";
    cout<<"4.Address \n";
    cout<<"5. Conatct \n";

    strcpy(firm_name,cinstr(250,200));
    Text s8(250,200,firm_name);


    strcpy(Firm_type,cinstr(250,250));
    Text s9(250,250,Firm_type);

    strcpy(Owner_Name,cinstr(250,300));
    Text sa(250,300,Owner_Name);


    strcpy(Address,cinstr(250,340));
    Text sa1(250,340,Address);


    strcpy(Contactno,cinstr(250,375));
    Text sa2(250,375,Contactno);


    int clickpos= getClick();
    int x= clickpos/65536;
    int y =clickpos%65536;
    if( validrect(250,450,x,y,500,50))
    {
        window1();
    };

}
























void title()//function window of the project
{
    int clickPos;
    Rectangle r1(250,250,500,500);
    r1.setFill(true);
    r1.setColor(COLOR(0,125,125));

    Text t1( 225,150,"COMMERCIAL FIRM MANAGER ");

    Text t2(225,200,"Made By : ");
    Text t3(250,225,"Rahul Chaplot (140040066)");
    Text t4 (250,250,"Vinayak Suthar (140040036)");
    Text t5 (250,275,"Shubham Patil (14D170015)");


    const double bfx=100 ,bfy= 325,blx=100,bly= 355 ,bwidth=100,bheight=25;
    Rectangle buttonF (bfx,bfy,bwidth,bheight),bottonL(blx,bly,bwidth,bheight);
    Text tf(bfx,bfy,"Raw Stock "),tg(blx,bly,"Product Stock ");

    const double fx=100 ,fy= 390,lx=100,ly= 420 ,width=100,height=25;
    const double ax=100,ay=450;
    Rectangle buttona (fx,fy,width,height),bottonb(lx,ly,width,height);
    Text tf1(fx,fy," Expenditure "),tg1(lx,ly,"Credit & Debit ");
    Rectangle adc(ax,ay,width,height);
    Text az(ax,ay,"Billing");

    while(true)
    {
        int clickpos= getClick();
        int x= clickpos/65536;
        int y =clickpos%65536;

        if (validrect(100,325,x,y,100,25))
        {
            window1();
        };
        if (validrect(100,365,x,y,100,25))
        {
        window2();
        };
        if (validrect (100,390,x,y,100,25)){
            Rectangle p12(250,250,500,500);
            p12.setFill(true);
            p12.setColor(COLOR(200,150,150));
            expwin();
        }
        if (validrect (100,425,x,y,100,25)){
            crdr();
        }
        if (validrect(100,450,x,y,100,25))
        {
            userbill();
        }
    }

    wait(10);



}





























void compinfo() //information window
{

    Rectangle v1(250,250,500,500);
    v1.setFill(true);
    v1.setColor(COLOR(255,170,0));
    Text s1(250,50," COMPANY Information");
    const int  a1=100,a2=200,b2=250,c2=300,w1=100,h1=20;

Rectangle v5(250,400,400,20);
    v5.setFill(true);
    v5.setColor(COLOR(25,170,255));

    Text s2(a1,a2,"Add Comapany");
    Text s5(250,400,"Click Here To Procced ---> ");


   while(true){ int clickpos= getClick();
    int x= clickpos/65536;
    int y =clickpos%65536;
    if( validrect(250,400,x,y,400,20))
    {
        title();
    };
    if( validrect(100,200,x,y,100,20))
    {
        get_details();
    };


}}
















void window() // main Window
{
    initCanvas("Front",500,500);
    Rectangle r1(250,250,500,500 ),r2(250,250,450,450);
    r1.setFill(true);
    r1.setColor(COLOR(240,100,180));
    r2.setFill(true);
    r2.setColor(COLOR(180,45,0));
    Text t1(  250,125,"  WELCOME TO COMMERCIAL FIRM MANAGER ");
    Rectangle r4(100,350,20,100 ),r5 (140,325,20,150),r6(180,370,20,60),r7(220,340,20,120),r8(220,300,20,200) ;
    r8.setFill(true);
    r8.setColor(COLOR(0,100,180));
    r4.setFill(true);
    r4.setColor(COLOR(240,100,0));
    r5.setFill(true);
    r5.setColor(COLOR(20,10,180));
    r6.setFill(true);
    r6.setColor(COLOR(240,0,180));
    r7.setFill(true);
    r7.setColor(COLOR(100,100,180));

    Rectangle r9(250,440,400,30);
    r9.setFill(true);
    r9.setColor(COLOR(60,160,160));
    Text t2(250,440, "CLICK HERE TO CONTINUE ----->");
    const int ax=700,ay=550,width=800,height=30;
   while(true){ int clickpos= getClick();
    int x= clickpos/65536;
    int y =clickpos%65536;
    if (validrect(250,440,x,y,400,30))
    {
        compinfo();
    }
    }

    wait(5);
}

main_program
{window();}

