

void delay_ms()
{
    getch();
}


int isvalid(char ch)
{
    if(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))||((ch>='1')&&(ch<='9')))
        return 1;
    else
        return 0;
}
int validrect(int cx, int cy,int x, int y , int l, int h)//a function created for switching canvas windows
{
    if(x- (l/2) <cx  && x + (l/2) >cx  && y-(h/2) <cy  && y+(h/2) > cy) return 1;
    else return 0;
}

char* cinstr(int x=-1,int y=-1)
{
    int isvalid(char );
    int i,flag=0,ctr=0,ctr1=0;
    char temp[80],str[80],str2[2];
    XEvent e1;
    Text t[80];
    str2[1]='\0';
    for(i=0;; i++)
    {
        nextEvent(e1);
        if(x==-1)
        {
            i=0;
            continue;
        }
        temp[i]=charFromEvent(e1);
        if(temp[i]==8)
        {
            temp[i]=' ';
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

        {
            str[ctr]=temp[i];
            ctr++;
        }
        if(temp[i]==13)
        {
            break;
        }
        if(i>=1)
        {
            str2[0]=temp[i];
            t[i].reset(x,y,str2);

            x+=8;
        }

    }

    str[ctr]='\0';
    return str;
}
class rawstock//class defined for rawstock item
{
public :
    char materialnumber[3];
    char materialname [20];
    double materialrate;
    double amount;
    double quantity;
    double limit;
public :

    void alterdata();//funtions for alter data
    void getdata1();
    void showdata1();
    void showspecific1();
    void alterdata1();
    void graphicalinput();
    void graphshow();
    void showspecific();
    void deletedata();
    void specificshow();

};



void rawstock :: alterdata()
{
    Text k1( 100,100,"Current quanity is : ");
    Text k2(250,100,quantity);
    Text k3( 100,150 ," \n Current rate is : \n ");
    Text k4(250,150,materialrate);

    Text k5( 100,250,"Enter a Quantity : ");
    cin >> quantity;
    Text k6(250,150,quantity);



    Text k10( 100,250,"Enter a Rate : ");
    cin >> materialrate;
    Text k9(250,250,materialrate);



    while (std::cout << "Enter a Quantity : ?\b" && !(std::cin >> quantity) )
    {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter. \n";
    }

    while (std::cout << "Enter Rate of the material  : ?\b" && !(std::cin >> materialrate ) )
    {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter. \n";
    }
    amount = materialrate*quantity;
}




void rinput()
{
    Rectangle in1(250,250,500,500);
    in1.setFill(true);
    in1.setColor(COLOR(240,20,20));

}
void rawstock:: graphicalinput()
{
    Text q10(100,50,"Entry of Rawstock Items --->");
    char matnum[3],matname[20];

    Text p1(100,150,"Item Number : ");
    cin>>materialnumber;
    Text r1(300,150,materialnumber);
    Text p2(100,200," Item Name  : ");
    cin>>materialname;

    Text r2(300,200,materialname);
    Text p3(100,250,"Item Rate ");
    cin>>materialrate;
    Text r3(300,250,materialrate);
    Text p4(100,300,"Quantity : ");
    cin>>quantity;
    Text r4(300,300,quantity);
    system("cls");
    wait(5);
}
void rawstock ::getdata1()
{
    rawstock a;

    int n;

    while (std::cout << "Enter number of items : ?\b" && !(std::cin >> n) )
    {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter. \n";
    }


    fstream file1;//usage of binary files to store data

    file1.open("raw4",ios::in|ios::out|ios::binary|ios::app);
    for (int i=0; i<n; i++)
    {
        a.graphicalinput();
        file1.write((char*)&a,sizeof(rawstock));



    }
    file1.close();
}


void rawstock:: specificshow()
{
    const int sfb=20,sfh=20,sfx=80;
    string cmd;
    Rectangle spf1(sfx,150,sfb,sfh),spf2(sfx,200,sfb,sfh),sf3(sfx,250,sfb,sfh),sf4(sfx,300,sfb,sfh);
    Text q1(150,150,"Item Number : ");

    Text p2(150,200," Item Name  : ");

    Text p3(150,250,"Item Rate ");

    Text p4(150,300,"Quantity : ");
    Text p5(100,470,"Cick on Rectangle To view ^^^^^");
    do
    {
        int clickpos= getClick();
        int x= clickpos/65536;
        int y =clickpos%65536;
        if (validrect(sfx,150,x,y,sfb,sfh))
        {
            Text r1(300,150,materialnumber);
            wait(5);
        };
        if (validrect(sfx,200,x,y,sfb,sfh))
        {
            Text r1(300,200,materialname);
            wait(5);
        }
        if (validrect(sfx,250,x,y,sfb,sfh))
        {
            Text r1(300,250,quantity );
            wait(5);
        }
        if (validrect(sfx,300,x,y,sfb,sfh))
        {
            Text r1(300,300,materialrate);
            wait(5);

        }
        Text rp1(150,450,"Do you want any other information(y/N) : ");
        cin>>cmd;
    }
    while(cmd=="y"||cmd=="Y");


    wait(5);


}


void rawstock:: graphshow()//Output of information of iterms
{
    Text q1(100,150,"Item Number : ");
    Text r1(300,150,materialnumber);
    Text p2(100,200," Item Name  : ");
    Text r2(300,200,materialname);
    Text p3(100,250,"Item Rate ");

    Text r3(300,250,materialrate);
    Text p4(100,300,"Quantity : ");
    Text r4(300,300,quantity);
    wait(5);
}

void rawstock::showdata1()//reading of data of rawstock from the files
{
    fstream file1;
    rawstock a;
    cout<<"\n ENTER THE ITEM NO : ?\b";


    file1.open("raw4",ios::in|ios::out|ios::binary);
    char no1[100];
    cin>>no1;

    file1.seekp(0,ios::beg);
    while(file1.read((char*)&a,sizeof(a)))
    {

        if(strcmp(a.materialnumber,no1)==0)
            a.graphshow();
        system("cls");


    }
    file1.close();
}

void rawstock::showspecific1() //reading of data from the files and showing specific information
{
    int flag=1;
    fstream file1;
    rawstock a;
    cout<<"\n ENTER THE ITEM NO : ?\b";
    char no1[100];
    cin>>no1;
    file1.open("raw4",ios::in|ios::out|ios::binary|ios::app);
    file1.seekp(0,ios::beg);
    while(file1.read((char*)&a,sizeof(a)))
    {

        if(strcmp(a.materialnumber,no1)==0)
        {
            a.specificshow();
            flag=0;
        }
        file1.close();
        if (flag==1)cout<<"NO SUCH ITEM FOUND \n";
    }
}
void rawstock::deletedata()//delete data for a file
{
    Text del(250,100,"DELETE ITEM ");
    rawstock a;
    int  flag=1;
    char num[3];
    char confirm[5];
    fstream file;
    file.open("raw4",ios::in|ios::out|ios::binary);
    fstream temp;
    temp.open("temp",ios::out|ios::in|ios::binary|ios::app);
    cout<<"\n item no : " ;
    cin>>num;
    file.seekp(0,ios::beg);
    while(file.read((char*)&a,sizeof(rawstock)))
    {


        if(strcmp(a.materialnumber,num)==0)
        {
            a.showdata1();
            cout<<"\n Are you sure, you want to delete this record (y/n)";
            cin>>confirm;
            if(confirm=="n")
                temp.write((char*)&a,sizeof(rawstock));
            flag=0;
        }
        else
            temp.write((char*)&a,sizeof(rawstock));
    }
    file.close();
    temp.close();
    remove("raw4");
    rename("temp","raw4");

    if(flag==1)
    {
        cout<<"\n NO such item ";
        delay_ms();
        system("cls");

    }
    else
    {
        cout<<"DELETED SUCCESSFULLY";
        wait(5);
        system("cls");
        Text D1(250,300,"Redirecting to main window");

    }
}

void rawstock::alterdata1()
{
    Text del(250,100,"ALTER ITEM ");
    rawstock a;
    int  flag=1,Count;
    char num[3];
    char confirm[5];
    fstream file;


    cout<<"\n Enter Item number : " ;
    cin>>num;


    file.open("raw4",ios::in|ios::out|ios::binary);

    file.seekp(0,ios::beg);
    while(file.read((char*)&a,sizeof(rawstock)))
    {


        if(strcmp(a.materialnumber,num)==0)
        {



            cout << "Enter material rate : ?\b";
            cout<<"Current Rate :"<<a.materialrate<<endl;
            cin>>a.materialrate;
            Text mr2(100,200,"New Material Rate");
            Text mr1(200,200,a.materialrate);
            cout<<"Current quantity :"<<a.quantity<<endl;
            cin>>a.quantity;
            Text qr2(100,300,"New Quantity :");
            Text qr1(200,300,a.quantity);
            file.write((char*)&a,sizeof(a));flag=0;
        }
        system("cls");
        file.close();



    }





    if(flag==1)
    {
        cout<<"\n NO such item ";
            system("cls");

    }
    else
    {
        cout<<"Updated SUCCESSFULLY";

        Text D1(250,300,"Redirecting to main window");
        wait(3);

    }}







