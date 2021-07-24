#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;
struct info{
    string name,lname,pass,bil;
    long long int tell,acid,wallet;
};
void entre();
string defaultpass();
void display(vector<info> &arr,int x,int size);
void read(vector<info> &arr,fstream &file,int size);
void write(vector<info> &arr,fstream &file,int size);
void en(string c,long long int &sign,int len);
void enstr(string c,string &k);
void log(vector<info> &arr,int size);
void extend(vector<info> &arr,int &size);
void search(vector<info> &arr,long long int a,string b,int &x,bool &flag);
void del(vector<info> &arr,int &size);
void arrange(vector<info> &arr,int size);
void arrangeinve(vector<info> &arr,int size);
void manual(vector<info> &arr,int size);
void menulog(vector<info> &arr,int size,int row);
int main()
{
    int size=-1;
    fstream fil("C:/Users/AHMADREZA/Desktop/fileproject.txt",ios::in|ios::out);
    //fil<<"ahmadreza mohammadi ahmad3303 9123545654 543000 6037995743569182";
    string set;
    while(fil){getline(fil,set);size++;}
    fil.close();
    fstream file("C:/Users/AHMADREZA/Desktop/fileproject.txt",ios::in|ios::out);
    vector<info> arr(size);
    bool flag=true;
    while(flag){
    read(arr,file,size);
    char sel;
    cout<<"1.SIGN IN::\n____________________\n\n2.SIGN UP::\n____________________\n\n3.DELETE USER::\n____________________\n\n"
          "4.ARRANGEMENT::\n____________________\n\n5.LIST OF ACCOUNTS::\n____________________\n\n"
          "6.EXIT::\n____________________\n\n\n\nENTRE: ";
    cin>>sel;
    int a=sel,x=-1;
    switch(a){
    case 49:system("cls");log(arr,size);entre();break;
    case 50:system("cls");extend(arr,size);entre();break;
    case 51:system("cls");del(arr,size);entre();break;
    case 52:{
        system("cls");
        bool flag1=true;
        while(flag1){
        cout<<"1.BY NAME (ASCENDING)::\n_________________________\n\n2.BY NAME (DESCENDING)::\n_________________________\n\n"
              "3.MANUAL::\n_________________________\n\n4.EXIT::\n_________________________\n\n\n\nENTRE: ";
        cin>>sel;
        a=sel;
        switch(a){
        case 49:system("cls");arrange(arr,size);break;
        case 50:system("cls");arrangeinve(arr,size);break;
        case 51:system("cls");manual(arr,size);break;
        case 52:system("cls");flag1=false;break;
        default:system("cls");
        }
        entre();}break;}
    case 53:system("cls");display(arr,x,size);entre();break;
    case 54:system("cls");flag=false;break;
    default:system("cls");
    }
    }
    ofstream F("C:/Users/AHMADREZA/Desktop/fileproject.txt",ofstream::out|ofstream::trunc);
    F.close();
    fstream fi("C:/Users/AHMADREZA/Desktop/fileproject.txt",ios::in|ios::out);
    write(arr,fi,size);
    fi.close();
    system("pause");
    return 0;
}
void entre(){
    char sel;
    cout<<"\n\nentre any kay: ";
    cin>>sel;
    system("cls");
}
string defaultpass(){
    srand(time(0));
    int f=rand()%(999999-100000+1)+100000;
    string F;
    F=to_string(f);
    F.push_back('B');
    F.push_back('A');
    return F;
}
void display(vector<info> &arr,int x,int size){
    system("cls");
    if(x<0){
    for(int c=0;c<size;c++){
        cout<<"<PERSON "<<c+1<<">\n__________\n\nNAME: "<<arr[c].name<<"\nLAST NAME: "<<arr[c].lname<<"\nPASSWORD: "
           <<arr[c].pass<<"\nTELL: 0"<<arr[c].tell<<"\nWALLET: "<<arr[c].wallet<<"\nACCOUNT ID: "<<arr[c].acid<<"\n"
           "_______________________________\n\n\n";
    }
    }
    else{
        cout<<"<RESULT>\n__________\n\nNAME: "<<arr[x].name<<"\nLAST NAME: "<<arr[x].lname<<"\nPASSWORD: "
         <<arr[x].pass<<"\nTELL: 0"<<arr[x].tell<<"\nWALLET: "<<arr[x].wallet<<"\nACCOUNT ID: "<<arr[x].acid<<"\n"
         "_______________________________\n";
    }
}
void read(vector<info> &arr,fstream &file,int size){
    for(int c=0;c<size;c++){
        string Bil,Bil1;
        file>>arr[c].name>>arr[c].lname>>arr[c].pass>>arr[c].tell>>arr[c].wallet>>arr[c].acid>>Bil;
        if(Bil=="-"){
            getline(file,Bil);
            Bil+=Bil1;
            arr[c].bil=Bil;
        }
    }
}
void write(vector<info> &arr,fstream &file,int size){
    for(int c=0;c<size;c++){
        file<<arr[c].name<<" "<<arr[c].lname<<" "<<arr[c].pass<<" "<<
        arr[c].tell<<" "<<arr[c].wallet<<" "<<arr[c].acid;
        if(arr[c].bil.size()>0)
            file<<arr[c].bil<<endl;
        else file<<" .\n";
    }
}
void en(string c,long long int &sign,int len){
    int counter=0;
    long long int s=0,x=-1;
    char ch;
    bool flag=true;
    while(flag){
        system("cls");
        cout<<c;
        cin>>s;
        x=s;
        counter=0;
        while(x!=0){
            x/=10;
            counter++;
        }
        if(len!=0&&len!=counter){
            cout<<"[INVALID LENGTH]\nPRESS ANY KAY (REDO): ";
            cin>>ch;
        }
        else if(s>0){
            sign=s;
            flag=false;
        }
        else{
            cout<<"\nINCORRECT\nPRESS ANY KAY (REDO): ";
            cin>>ch;
        }
    }
}
void enstr(string c,string &k){
    system("cls");
    cout<<c;
    getline(cin,k);
    if(c.length()!=21){
    int I=k.length();
    for(int i=0;i<I;i++)
        if(k[i]>64&&k[i]<91)k[i]+=32;
    }
}
void log(vector<info> &arr,int size){
    string b;
    long long int a=0;
    cout<<"ACCOUNT ID: ";
    cin>>a;
    getline(cin,b);
    cout<<"PASSWORD: ";
    getline(cin,b);
    int x=-1;
    bool flag=false;
    search(arr,a,b,x,flag);
    if(flag) menulog(arr,size,x);
    else if(x!=-1){
        cout<<"\n[NOT EXIST]\nFORGET YOUR PASSWORD? (y=YES): ";
        char ch;
        cin>>ch;
        if(ch=='y'||ch=='Y'){
            system("cls");
            string k="ENTRE YOUR PHONE NUMBER: ";
            long long int num;
            int len=10;
            en(k,num,len);
            if(arr[x].tell==num) menulog(arr,size,x);
            else cout<<"\n[NOT EXIST]\n";
        }
    }
    else cout<<"\n[NOT EXIST]\n";
}
void extend(vector<info> &arr,int &size){
    bool flag=true;
    string c,k;
    long long int sign1=0,sign2=0,len=16,Len=10;
    c="ENTRE YOUR ACCOUNT ID: ";
    en(c,sign1,len);
    k="ENTRE YOUR PHONE NUMBER: ";
    en(k,sign2,Len);
    for(int i=0;arr[i].name!="\0";i++)
        if(arr[i].acid==sign1||arr[i].tell==sign2){
            flag=false;
            cout<<"\nINCORRECT";
        }
    if(flag){
        size++;
        arr.resize(size);
        arr.shrink_to_fit();
        arr[size-1].acid=sign1;
        arr[size-1].tell=sign2;
        c="ENTRE THE EMOUNT OF MONEY: ";
        len=0;
        en(c,sign1,len);
        arr[size-1].wallet=sign1;
        c="ENTRE YOUR NAME: ";
        getline(cin,k);
        enstr(c,k);
        arr[size-1].name=k;
        c="ENTRE YOUR LAST NAME: ";
        enstr(c,k);
        arr[size-1].lname=k;
        char ch;
        cout<<"DO YOU WANT DEFAULT PASSWORD? (y=YES): ";
        cin.get(ch);
        if(ch=='y'||ch=='Y'){
            arr[size-1].pass=defaultpass();
        }
        else{
            getline(cin,k);
            bool fla=true;
            while(fla){
            c="ENTRE YOUR PASSWORD: ";
            enstr(c,k);
            if(k.length()>=8){
                arr[size-1].pass=k;
                fla=false;
            }
            else{
                char ch;cout<<"\n[INVALID LENGTH]\nPRESS ANY KAY (REDO): ";
                cin>>ch;
                getline(cin,k);
            }
            }
            }
        display(arr,size-1,size);
    }
}
void search(vector<info> &arr,long long int a,string b,int &x,bool &flag){
    for(int i=0;arr[i].name!="\0";i++){
        if(arr[i].acid==a){
            if(arr[i].pass==b)
                flag=true;
            x=i;
        }
    }
}
void del(vector<info> &arr,int &size){
    long long int a;
    int i=0,len=16,x=-1;
    string r="ENTRE ACCOUNT ID: ";
    en(r,a,len);
    for(i=0;i<size;i++)
        if(arr[i].acid==a){
        x=i;
        break;
    }
    if(x>=0){
        cout<<"[DONE]";
        arr.erase(arr.begin()+i);
        size-=1;
    }
    else cout<<"[NOT EXIST]";
}
void arrange(vector<info> &arr,int size){
    for(int i=0;i<size;i++)
    {
        int si,SI=arr[i].name[0];
        for(int j=i+1;j<size;j++)
        {
            si=arr[j].name[0];
            int count=0;
            while(SI==si){
                SI=arr[i].name[count];
                si=arr[j].name[count];
                count++;
            }
            if(SI>si){
                info temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"[DONE]";
}
void arrangeinve(vector<info> &arr,int size){
    for(int i=0;i<size;i++)
    {
        int si,SI=arr[i].name[0];
        for(int j=i+1;j<size;j++)
        {
            si=arr[j].name[0];
            int count=0;
            while(SI==si){
                SI=arr[i].name[count];
                si=arr[j].name[count];
                count++;
            }
            if(SI<si){
                info temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"[DONE]";
}
void manual(vector<info> &arr,int size){
    info temp;
    int i=-1,I=-1;
    cout<<"SWAP FIRST WITH SECOND (ENTRE TWO INDEX):\n";
    cin>>i>>I;
    if(I<size&&i<size){
    temp=arr[i];
    arr[i]=arr[I];
    arr[I]=temp;
    cout<<"[DONE]";
    }
    else cout<<"[INVALID INDEX]";
}
void menulog(vector<info> &arr,int size,int row){
    system("cls");
    bool flag=true;
    while(flag){
    cout<<"HI <"<<arr[row].name<<">\n\n"<<"1.INFORMATION::\n___________________\n\n2.TOP UP::"
          "\n___________________\n\n3.DEPOSIT::\n___________________\n\n4.CHANGE PASSWORD::\n___________________\n\n"
          "5.TRANSACTIONS::\n___________________\n\n6.EXIT::\n___________________\n\n\n\nENTRE: ";
    char sel;
    cin>>sel;
    int s=sel;
    switch(s)
    {
    case 49:system("cls");display(arr,row,size);entre();break;
    case 50:
    {
        system("cls");
        string c="ENTRE THE EMOUNT OF MONEY: ";
        int len=0;
        long long int sign=0;
        en(c,sign,len);
        arr[row].wallet+=sign;
        cout<<"ACCOUNT BALANCE: "<<arr[row].wallet<<endl;
        arr[row].bil+=" - CHARGE: ";
        arr[row].bil+=to_string(sign);
        entre();
        break;
    }
    case 51:{
        system("cls");
        string c="PAYMENT ACCOUNT ID: ";
        int len=16;
        long long int sign=0;
        en(c,sign,len);
        bool flag=false;
        int rowdest=0;
        for(rowdest=0;rowdest<size;rowdest++)
            if(arr[rowdest].acid==sign&&rowdest!=row)
            {
                flag=true;
                break;
            }
        system("cls");
        if(flag){
            c="[ACCOUNT OWNER (NAME): ";
            c+=arr[rowdest].name;
            c+="]\n[LAST NAME: ";
            c+=arr[rowdest].lname;
            c+="]\n____________________________\n\nENTRE VALUE: ";
            len=0;
            en(c,sign,len);
            if(arr[row].wallet-sign>=0){
            int timei=time(0);
            string pass,input;
            pass=defaultpass();
            while(flag){
                system("cls");
                getline(cin,input);
                cout<<"OTP: <<"<<pass<<">>\nTMIE: 60 SECOND\n\nENTRE: ";
                getline(cin,input);
                if(time(0)-timei<=60){
                if(input==pass){
                    arr[row].wallet-=sign;
                    arr[rowdest].wallet+=sign;
                    long long int strs=sign;
                    c=to_string(strs);
                    arr[row].bil+=" - PAYMENT TO ";
                    long long int stra=arr[rowdest].acid;
                    string account=to_string(stra);
                    arr[row].bil+=account;
                    arr[row].bil+=" : ";
                    arr[row].bil+=c;
                    arr[rowdest].bil+=" - RECIVE FROM ";
                    stra=arr[row].acid;
                    account=to_string(stra);
                    arr[rowdest].bil+=account;
                    arr[rowdest].bil+=" : ";
                    arr[rowdest].bil+=c;
                    cout<<"\n[DONE]\n";
                    flag=false;
                }
                else {cout<<"[INVALID PASSWORD]\n";entre();}
                }
                else{
                    flag=false;
                    cout<<"[TIME ENDED]\n";
                }
            }
            }
            else cout<<"\n[YOU DONT HAVE ENOUGH MONEY]\n";

        }
        else{
            cout<<"INCORRECT\n";
        }
        entre();
        break;
    }
    case 52:
    {
        system("cls");
        string k,c="ENTRE YOUR PASSWORD: ";
        bool flag=true;
        getline(cin,k);
        while(flag)
        {
        enstr(c,k);
        if(k.length()>=8&&k!=arr[row].pass){
            arr[row].pass=k;
            flag=false;
        }
        else if(k.length()>=8){
            char ch;
            cout<<"ENTERED PASSWORD MUST BE DIFFERENT FROM OLD (REDO): ";
            cin>>ch;
            getline(cin,k);
        }

        else{
            char ch;
            cout<<"[INVALID LENGTH]\nPRESS ANY KAY (REDO): ";
            cin>>ch;
            getline(cin,k);
        }
        }
        entre();
        break;
    }
    case 53:{
        system("cls");
        if(arr[row].bil.size()>0)
            cout<<arr[row].bil<<endl;
        else
            cout<<"YOU DON'T HAVE ANY TRANSACTIONS\n";
        entre();
        break;
    }
    case 54:system("cls");flag=false;break;
    default:system("cls");
    }
    }
}
