#include "sBank.h"

//
//  sBank.cpp
//  System
//
//  Created by 魏晓 on 11/11/17.
//  Copyright © 2017 魏晓. All rights reserved.
//
#include <stdio.h>
#include <Winsock2.h>
#include <fstream>
#include <sstream>

int stringtoint(string s)//基本函数：作用就是把string转换为int数据
{
    int num;
    stringstream ss(s);
    ss>>num;
    return num;
}

string inttostring(int i)//基本函数：作用是把int转换为string
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

unsigned int RSHash(string mas) //hash函数。映射函数
{
    const char *str = mas.c_str();
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * a + (*str++);
        a *= b;
    }

    return (hash  & 0x3FFF);//定义返回hash字符串的长度
}

sBankinterface::sBankinterface()//初始化程序,从文件读取内容并且构建数组
{
    fstream fin;
    fin.open(".//log//personlogfile.txt",fstream::in);//首先读取人员名单
    string str;

    while(!fin.eof())//档文件不结束的时候
    {
        getline(fin,str);//读取一个开头的无用行字符
        if(1>str.size())//如果遇到行为就结束
            break;
        banker temp=banker();
        getline(fin,temp.bankusername);

        getline(fin,temp.bankuserid);
        getline(fin,temp.bankuseridcard);
        getline(fin,temp.bankuserpassword);
        getline(fin,temp.banktype);
        fin>>temp.userbalance;
        getline(fin,str);

        if(5<temp.bankuserid.length())
            bankerlist.insert(std::pair<string,banker>(temp.bankuserid,temp));//吧读取到的一整条信息加载到内存
        getline(fin,str);

    }

    fin.sync();
    fin.close();

    fstream gin;
    gin.open(".//log//logfile.txt",fstream::in);
     while(!gin.eof()){//读取银行的种类名称
        getline(gin,str);
        if("----"==str)
            break;
        bankname.push_back(str);
    }

    bankrecord tempcord=Transactionrecord(0,"","","",0.0);//先声明一个空记录

    while(!gin.eof())
    {
        getline(gin,str);
        //cout<<str<<endl;
        if(3>=str.length())
            break;
        gin>>tempcord.bankrecarditime;
        getline(gin,str);//读取输入double之后剩下的换行字符
        getline(gin,tempcord.bankrecordid);
        getline(gin,tempcord.bankrecordtype);
        getline(gin,tempcord.bankaddition);

        gin>>tempcord.bankrecordnum;
        getline(gin,str);

        BTrecord.push_back(tempcord);//最后把记录压入到占中
        getline(gin,str);
    }
    gin.sync();
    gin.close();

}

sBankinterface::~sBankinterface()//保存内存中的数据
{
    ofstream fout(".//log//personlogfile.txt");
    map<string,banker>::iterator it;

     for(it=bankerlist.begin();it!=bankerlist.end();++it)
     {
         fout<<"---"<<endl;
         fout<<(it->second).bankusername<<endl;
         fout<<(it->second).bankuserid<<endl;
         fout<<(it->second).bankuseridcard<<endl;
         fout<<(it->second).bankuserpassword<<endl;
         fout<<(it->second).banktype<<endl;
         fout<<(it->second).userbalance<<endl;
         fout<<"--"<<endl;
     }
    fout.close();//关闭文件输入流

    ofstream gout(".//log//logfile.txt");

    for(auto i:bankname)
        gout<<i<<endl;
    gout<<"----"<<endl;

    for(auto a:BTrecord)
    {
        gout<<"---"<<endl;
        gout<<a.bankrecarditime<<endl;
        gout<<a.bankrecordid<<endl;
        gout<<a.bankrecordtype<<endl;
        gout<<a.bankaddition<<endl;
        gout<<a.bankrecordnum<<endl;
        gout<<"--"<<endl;
    }
    gout.close();
    cout<<"信息保存完整，非常感谢你使用这个系统"<<endl;
}

bool sBankinterface::banklogin(string a,string b)//登陆函数
{
    if(bankerlist[a].bankuserpassword==b){
        nowlocal=a;
        cout<<"you have login success,your id is:"<<a<<endl;
        return true;
    }
    return false;
}

void sBankinterface::banksignout(){//登出函数
    nowlocal="error";
    cout<<"sign out!"<<endl;
}

void sBankinterface::bankregister()//注册银行
{
    cout<<"You have these choice:"<<endl;
    for(auto i:bankname)//输出可以选择的银行的名单
        cout<<i<<"\t";

    cout<<"\nPlease input the sort number to choice:";
    int choice=999;
    while(choice>=bankname.size()||choice<0)//当输入不在可选范围内的时候继续读
        cin>>choice;
    banker temp=banker();

        temp.banktype=bankname[choice-1];//选择注册的银行

    cout<<"\nPlease input your User Name:";
    cin>>temp.bankusername;

    time_t nowtime;//时间默认为当时发生的时间
    nowtime=time(NULL);
    temp.bankuserid=(inttostring(nowtime%100000)+inttostring(RSHash(temp.bankusername)));//id的构成规则

    cout<<"your ID"<<temp.bankuserid;
    cout<<"\nPlease input your User Card ID:";
    cin>>temp.bankuseridcard;//输入身份证号码

    cout<<"\nPlease input your User Password:";
    while(true){//当输入的密码不符合规则的时候连续输入
        cin>>temp.bankuserpassword;
        if(temp.bankuserpassword.length()>8)
            break;
        cout<<"your Password is too short!"<<endl;
    }
    bankerlist.insert(std::pair<string,banker>(temp.bankuserid,temp));
    //生成记录
    time_t a=time(NULL);
    string b=temp.bankuserid;
    string c="register";
    string d="...";
    double e=0.0;
    BTrecord.push_back(bankrecord(a,b,c,d,e));//
    cout<<"Congratulate! you have register succsed"<<endl;
}

void sBankinterface::banktransfer(string distination,double b)//转账
{
    if((b<bankerlist[nowlocal].userbalance)&&b>0){
        bankerlist[nowlocal].userbalance-=b;
        cout<<bankerlist[nowlocal].bankusername<<"Successful debit!"<<endl;
        bankerlist[distination].userbalance+=b;
        cout<<bankerlist[distination].bankusername<<"Successful receipt"<<endl;
        time_t a=time(NULL);
        string bb=nowlocal;
        string c="transfer";
        string d="to"+distination;
        double e=b;
        BTrecord.push_back(bankrecord(a,bb,c,d,e));
    }
    else if(0>=b){
        cout<<"Useless number!"<<endl;
    }
    else
        cout<<"Invalid target account / balance deficit"<<endl;
}

int sBankinterface::quicktransfer(string owner, string pass, string distination, double b)//快速转账
{
    //map<string, banker>::iterator it =bankerlist.find(owner);
    if(bankerlist[owner].bankuserpassword==pass)
    {
        if(bankerlist[owner].userbalance>b){
            bankerlist[distination].userbalance+=b;
            bankerlist[owner].userbalance-=b;
            time_t a=time(NULL);
            string bb=nowlocal;
            string c="transfer";
            string d="to"+distination;
            double e=b;
            BTrecord.push_back(bankrecord(a,bb,c,d,e));
            return 1;
        }
        else{
            return -2;//bu gou
        }
    }
    else{
        return -1;//mei ren
    }
    //return -3;
}

string sBankinterface::getlocal()//得到当前登录的人
{
    return nowlocal;
}

void sBankinterface::bankchangeinformation()//改变信息
{
    cout<<"Please input that you want change:"<<endl;
    cout<<"1:name\t2:idcard\t3:password";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            cout<<"\nPlease input your new name:";
            cin>>bankerlist[nowlocal].bankusername;
            cout<<"\nChange success!"<<endl;
            break;
        }
        case 2:
        {
            cout<<"\nPlease input your new ID:";
            cin>>bankerlist[nowlocal].bankuseridcard;
            cout<<"\nChange success!"<<endl;
            break;
        }
        case 3:
        {
            cout<<"\nPlease input your new password:";
            while(true){
                cin>>bankerlist[nowlocal].bankuserpassword;
                if(bankerlist[nowlocal].bankuserpassword.length()>8)
                    break;
                cout<<"your Password is too short!"<<endl;
            }
            cout<<"\nChange success!"<<endl;
            break;
        }
        default:
            cout<<"Useless choice!"<<endl;
    }
}

void sBankinterface::Moneydeal()//金钱交易
{
    cout<<"Positive numbers represent deposits, and negative numbers represent withdrawals:";
    double choice;
    cin>>choice;
    if(choice>0){
        bankerlist[nowlocal].userbalance+=choice;

        time_t a=time(NULL);
        string b=nowlocal;
        string c="save";
        string d="...";
        double e=choice;
        BTrecord.push_back(bankrecord(a,b,c,d,e));//产生记录
    }
    else{
        if(bankerlist[nowlocal].userbalance+choice>0){
            bankerlist[nowlocal].userbalance+=choice;//+加钱

            time_t a=time(NULL);
            string b=nowlocal;
            string c="Take";
            string d="...";
            double e=-choice;
            BTrecord.push_back(bankrecord(a,b,c,d,e));//产生记录

        }
        else
            cout<<"You don't have that much money"<<endl;//如果超过就输出这句话
    }
}

void sBankinterface::getinformation()//得到信息
{
    map<string,banker>::iterator it;

    for(it=bankerlist.begin();it!=bankerlist.end();it++)//输出所有员工的名字和id
    {
        cout<<(it->second).bankusername<<endl;
        cout<<(it->second).bankuserid<<endl;
        cout<<endl;
    }
    for(auto w:BTrecord){//输出相关的记录
        if(w.bankrecordid==nowlocal){
            cout<<"time:"<<w.bankrecarditime;
            cout<<"type:"<<w.bankrecordtype<<endl;
        }
    }
    time_t a=time(NULL);
    string b=nowlocal;
    string c="getinformation";
    string d="name//id";
    double e=0.0;
    BTrecord.push_back(bankrecord(a,b,c,d,e));//加载记录
}
void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)//cfenge/v ans/s bei
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));

    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}
double stringToNum(const string& str)//string头num
{
    stringstream ss(str);
    double num;
    ss >> num;
    return num;
}
int sBankinterface::jianting()//监听端口的的函数
{
    WORD wVersionRequested;
    WSADATA wsaData;//加载
    int err;

    wVersionRequested = MAKEWORD( 1, 1 );

    err = WSAStartup( wVersionRequested, &wsaData );
    if ( err != 0 )
    {
        return -1;//错误码-1，err
    }

    if ( LOBYTE( wsaData.wVersion ) != 1 ||HIBYTE( wsaData.wVersion ) != 1 )
    {
        WSACleanup( );//释放 socket
        return -2;
    }
    SOCKET sockSrv=socket(AF_INET,SOCK_STREAM,0);

    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(6000);//监听端口6000

    bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));//绑定

    listen(sockSrv,5);
    int jianjian=1;
    SOCKADDR_IN addrClient;
    int len=sizeof(SOCKADDR);
    while(true)
    {
        SOCKET sockConn=accept(sockSrv,(SOCKADDR*)&addrClient,&len);
        char sendBuf[50];
        //sendBuf="success";
        //sprintf(sendBuf,"%s",inet_ntoa(addrClient.sin_addr));
        //send(sockConn,sendBuf,strlen(sendBuf)+1,0);
        char recvBuf[50];
        recv(sockConn,recvBuf,50,0);
        string str=recvBuf;
        vector <string> ansq;
        SplitString(str,ansq,"/");
        //cout<<str<<endl;
        string usr=ansq[0];
        cout<<"pay id:"<<usr<<endl;
        string pas=ansq[1];
        cout<<"id-password:"<<pas<<endl;
        string num=ansq[2];
        double sum=stringToNum(num);
        cout<<"account:"<<sum<<endl;
        int ans=quicktransfer(usr,pas,"2521616198",sum);
        if(ans==1)
        {
            sprintf(sendBuf,"%s-success",inet_ntoa(addrClient.sin_addr));
            send(sockConn,sendBuf,strlen(sendBuf)+1,0);
        }
        else
        {
            sprintf(sendBuf,"%s-fail",inet_ntoa(addrClient.sin_addr));
            send(sockConn,sendBuf,strlen(sendBuf)+1,0);
        }
        //printf("%s",recvBuf);
        //cout<<str<<endl;

        closesocket(sockConn);
        if(sum<0)
            break;
    }
    return 0;
}
int sBankinterface::sBankrun()//与逆行函数
{
    cout<<"Welcome to the bank system!"<<endl;
    while(true)//注册
    {
        cout<<"1:Login\t2:Registration\t3:signout:"<<endl;
        int choice;
        cin>>choice;
        if(choice==2){
            bankregister();
            break;
        }
        else if(choice==1)
            break;
        else if(choice==3)
            return 0;
        else
            cout<<"Useless choice!"<<endl;
    }

    while(true)//登陆
    {
        cout<<"Please input your Id:";
        string a,b;
        cin>>a;
        cout<<"Please input your password:";
        cin>>b;
        if(banklogin(a, b))
            break;
    }

    //cout<<"Now, your informaiton is:";
    //cout<<"ID:"<<bankerlist[nowlocal].bankuserid<<"\tBanlance:"<<bankerlist[nowlocal].userbalance<<endl;
    cout<<"you can do these jobs:\n0.reload\n1.signout\n2.transfer\n3.change information\n4.money deal\n5.getinformation\n6.register"<<endl;//选择
    while(true)//循环执行命令
    {
        cout<<"Loading"<<"ID:"<<bankerlist[nowlocal].bankuserid<<"\tBanlance:"<<bankerlist[nowlocal].userbalance<<endl;//循环展示银行当前用户的信息
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 0:
                banksignout();
                while(true)//登陆
                {
                    cout<<"Please input your Id:";
                    string a,b;
                    cin>>a;
                    cout<<"\nPlease input your password:";
                    cin>>b;
                    if(banklogin(a, b))
                        break;
                }
                break;
            case 1:
                return 1;
                break;
            case 2:
                {
                    cout<<"Please input ID and number!";
                string a;
                cin>>a;
                    cout<<"next";
                double b;
                cin>>b;
                banktransfer(a,b);
                break;
            }
            case 3:
                bankchangeinformation();
                break;
            case 4:
                Moneydeal();
                break;
            case 5:
                getinformation();
                break;
            case 6:{
                bankregister();
                break;
            }

            default:
                break;
        }
    }
}
