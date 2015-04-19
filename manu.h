
class manfuct
{
public :
    char pronum[3];
    char pronam [20];
    double rate;
    double amount;
    double quantity;
    double limit;
    double discount;
public :
    char  *getno()
    {
        return pronum;
    }
    char *getname()
    {
        return pronam;
    }
    double getamount()
    {
        return amount;
    }
    double getrate()
    {
        return rate;
    }
    double getquantity()
    {
        return quantity;
    }
    double getlimit()
    {
        return limit;
    }


void alterdata();
    void showlistitem();
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



void manfuct:: graphicalinput()
{Text q10(150,75,"Entry of Manufactured Items --->");


    Text p1(100,150,"Product Number : ");
    cin>>pronum;
    Text r1(300,150,pronum);
    Text p2(100,200," Product Name  : ");
    cin>>pronam;

    Text r2(300,200,pronam);
    Text p3(100,250,"Selling Price");
    cin>>rate;
    Text r3(300,250,rate);
    Text p4(100,300,"Quantity : ");
    cin>>quantity;
    Text r4(300,300,quantity);
    Text r5(100,350,"Discount % ");

    cin>>discount;
    Text r6(300,350,discount);
    wait(5);
}
void manfuct::getdata1()
{
    manfuct a;

    int n;
    cout<<"Enter the product :"<<endl;

    cin>>n;

    fstream file1;

    file1.open("man1",ios::in|ios::out|ios::binary|ios::app);
    for (int i=0; i<n; i++)
    {
        a.graphicalinput();
        file1.write((char*)&a,sizeof(manfuct));



    }
    file1.close();
}


void manfuct:: specificshow()
{
    const int sfb=20,sfh=20,sfx=80;string cmd;
    Rectangle spf1(sfx,150,sfb,sfh),spf2(sfx,200,sfb,sfh),sf3(sfx,250,sfb,sfh),sf4(sfx,300,sfb,sfh),sf5(sfx,350,sfb,sfh);
    Text q1(150,150,"Product Number : ");

    Text p2(150,200," Product Name  : ");

    Text p3(150,250,"Product Selling price ");

    Text p4(150,300,"Quantity : ");
    Text p5(150,350,"Discount");
    Text p6(100,470,"Cick on Rectangle To view ^^^^^");
   do{ int clickpos= getClick();
    int x= clickpos/65536;
    int y =clickpos%65536;
    if (validrect(sfx,150,x,y,sfb,sfh))
    {
        Text r1(300,150,pronum);
        wait(5);
    };
    if (validrect(sfx,200,x,y,sfb,sfh))
    {
        Text r1(300,200,pronam);
wait(5);
    }
    if (validrect(sfx,250,x,y,sfb,sfh))
    {
        Text r1(300,250,quantity );wait(5);
    }
    if (validrect(sfx,300,x,y,sfb,sfh))
    {
        Text r1(300,300,rate);wait(5);

    }if (validrect(sfx,350,x,y,sfb,sfh))
    {
        Text r1(300,350,discount);wait(5);

    }
    Text rp1(150,450,"Do you want any other information(y/N) : ");
     cin>>cmd;
    }
    while(cmd=="y"||cmd=="Y");


    wait(5);


}


void manfuct:: graphshow()
{
    Text q1(100,150,"Item Number : ");
    Text r1(300,150,pronum);
    Text p2(100,200," Item Name  : ");
    Text r2(300,200,pronam);
    Text p3(100,250,"Item Rate ");
    Text r3(300,250,rate);
    Text p4(100,300,"Quantity : ");
    Text r4(300,300,quantity);
    wait(5);
}

void manfuct::showdata1()
{
    fstream file1;
    manfuct a;
    cout<<"\n ENTER THE ITEM NO : ?\b";


    file1.open("man1",ios::in|ios::out|ios::binary|ios::app);
    char no1[100];
    cin>>no1;

    file1.seekp(0,ios::beg);
    while(file1.read((char*)&a,sizeof(a)))
    {

        if(strcmp(a.pronum,no1)==0)
            a.graphshow();
    }
    file1.close();
    wait(5);
}

void manfuct::showspecific1()
{
    int flag=1;
    fstream file1;
    manfuct a;
    cout<<"\n ENTER THE ITEM NO : ?\b";
    char no1[100];
    cin>>no1;
    file1.open("man1",ios::in|ios::out|ios::binary|ios::app);
    file1.seekp(0,ios::beg);
    while(file1.read((char*)&a,sizeof(a)))
    {

        if(strcmp(a.pronum,no1)==0){
            a.specificshow();


        flag=0;
    }
    file1.close();
    if (flag==1)cout<<"NO SUCH ITEM FOUND \n";
}}
void manfuct::deletedata()
{   Text del(250,100,"DELETE ITEM ");
    manfuct a;
         int  flag=1;
        char num[3];
        char confirm[5];
        fstream file;
        file.open("man1",ios::in|ios::out|ios::binary);
        fstream temp;
        temp.open("temp",ios::out|ios::in|ios::binary|ios::app);
        cout<<"\n item no : " ;
        cin>>num;
        file.seekp(0,ios::beg);
        while(file.read((char*)&a,sizeof(a)))
        {


        if(strcmp(a.pronum,num)==0)
            {
                a.showdata1();
                cout<<"\n Are you sure, you want to delete this record (y/n)";
                cin>>confirm;
                if(confirm=="n")
                    temp.write((char*)&a,sizeof(a));
                flag=0;
            }
            else
                temp.write((char*)&a,sizeof(a));
        }
        file.close();
        temp.close();
        remove("man1");
        rename("temp","man1");

        if(flag==1)
        {
            cout<<"\n NO such item ";


        }
        else
        {
            cout<<"DELETED SUCCESSFULLY";wait(5);

            Text D1(250,300,"Redirecting to main window");

        }
}

void manfuct::alterdata1(){
     Text del(250,100,"ALTER ITEM ");
    manfuct a;
         int  flag=1,Count;
        char num[3];
        char confirm[5];
        fstream file;


         cout<<"\n item no : " ;
        cin>>num;


        file.open("man1",ios::in|ios::out|ios::binary);
int k = 1;

 file.seekp(0,ios::beg);
  while(file.read((char*)&a,sizeof(manfuct)))
        {


        if(strcmp(a.pronum,num)==0)
            {



        cout << "Enter material rate : ?\b";
             cout<<a.rate<<endl;
             cin>>a.rate;
             Text mr2(100,200,"New Product Rate");
             Text mr1(200,200,a.rate);
             cout<<a.quantity<<endl;

             Text qr2(100,300,"New Product quantity :");
             cin>>a.quantity;
             Text qr1(200,300,a.quantity);



        file.write((char*)&a,sizeof(a));}
            } file.close();wait(10);}


