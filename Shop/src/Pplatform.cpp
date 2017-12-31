#include "Pplatform.h"//源代码
#include <sstream>//字符类型之间转化
#include <fstream>//文件输入输出
#include <stdio.h>
#include <Winsock2.h>//socket通信
Pplatform::Pplatform()//构造函数
{
    fstream fin;//文件中的相邻记录之间用--区分
    fin.open(".//log//customer.txt",fstream::in);//读文件
    string str,a,b,c,d,e,f,g,h,i;//定义在读文件中用到的字符
    int j,k,l;//double数字
    double n,q;
    fin>>Pfoodeff;//读取基础的属性,以下都是
    getline(fin,str);
    fin>>Pclothereff;
    getline(fin,str);
    fin>>Pbookeff;
    getline(fin,str);
    fin>>manjianmenxian;
    getline(fin,str);
    fin>>manjianjine;
    getline(fin,str);

    while(!fin.eof())//党委读取完全时继续
    {
        getline(fin,str);
        if(str.size()==0)
            break;
        getline(fin,a);
        getline(fin,b);
        getline(fin,c);
        getline(fin,d);
        getline(fin,e);
        vector<string> tem;
        getline(fin,f);
        while(f!="--")
        {
            tem.push_back(f);
            getline(fin,f);
        }
        customers.push_back(customer(tem,a,b,c,d,e));
    }
    fin.clear();//读取完一个文件就停止
    fin.close();

    fstream dfin(".//log//clother.txt",fstream::in);
    while(!dfin.eof())
    {
        getline(dfin,str);
        if(str.size()==0)
            break;
        getline(dfin,a);
        dfin>>j;
        getline(dfin,str);
        getline(dfin,b);
        getline(dfin,c);
        dfin>>n;
        getline(dfin,str);
        getline(dfin,d);
        getline(dfin,e);
        ce.push_back(Pclother(d,e,n,a,j,c,b));
        getline(dfin,str);
    }
    dfin.clear();
    dfin.close();

    fstream bfin(".//log//book.txt",fstream::in);
    while(!bfin.eof())
    {
        getline(bfin,str);
        if(str.size()==0)
            break;
        getline(bfin,a);
        bfin>>j;
        getline(bfin,str);
        getline(bfin,b);
        getline(bfin,c);
        bfin>>n;
        getline(bfin,str);
        getline(bfin,d);
        bfin>>k;
        getline(bfin,str);
        be.push_back(Pbook(k,d,n,a,j,c,b));
        getline(bfin,str);
    }
    bfin.clear();
    bfin.close();

    fstream ffin(".//log//food.txt",fstream::in);
    while(!ffin.eof())
    {
        getline(ffin,str);
        if(str.size()==0)
            break;
        getline(ffin,a);
        ffin>>j;
        getline(ffin,str);
        getline(ffin,b);
        getline(ffin,c);
        ffin>>n;
        getline(ffin,str);
        ffin>>k;
        getline(ffin,str);
        ffin>>q;
        getline(ffin,str);
        ffin>>l;
        getline(ffin,str);
        fe.push_back(Pfood(k,l,q,n,a,j,c,b));
        getline(ffin,str);
    }
    ffin.clear();
    ffin.close();

    fstream rfin(".//log//record.txt",fstream::in);
    while(!rfin.eof())
    {
       getline(rfin,str);
       if(str.size()==0)
            break;
       getline(rfin,a);
       getline(rfin,b);
       time_t ttt;
       rfin>>ttt;
       getline(rfin,str);
       getline(rfin,c);
       platrecord.push_back(record(a,b,ttt,c));
       getline(rfin,str);
    }
    rfin.clear();
    rfin.close();
}

Pplatform::~Pplatform()//析构函数
{
    zhifu(-2);
    //dtor
    //customer
    ofstream fout(".//log//customer.txt");//输出顾客
    fout<<Pfoodeff<<endl;//输出各个物品 的打折系数
    fout<<Pclothereff<<endl;
    fout<<Pbookeff<<endl;
    fout<<manjianmenxian<<endl;
    fout<<manjianjine<<endl;
    int vsize=customers.size();
    for(int i=0;i<vsize;i++)
    {
        fout<<"---"<<endl;
        fout<<customers[i].getPuname()<<endl;
        fout<<customers[i].getPuid()<<endl;
        fout<<customers[i].getPubankid()<<endl;
        fout<<customers[i].getPuaddition()<<endl;
        fout<<customers[i].getpassword()<<endl;
        vector<string> ans;
        customers[i].getPulike(ans);
        for(int i=0;i<ans.size();i++)
            fout<<ans[i]<<endl;
        fout<<"--"<<endl;
    }
    fout.clear();
    fout.close();
    //book

    ofstream lout(".//log//clother.txt");
    vsize=ce.size();
    for(int i=0;i<vsize;i++)
    {
        lout<<"---"<<endl;
        lout<<ce[i].getname()<<endl;
        lout<<ce[i].getnumber()<<endl;
        lout<<ce[i].getid()<<endl;
        lout<<ce[i].getdescribe()<<endl;
        lout<<ce[i].gp()<<endl;
        lout<<ce[i].getcolor()<<endl;
        lout<<ce[i].getstyle()<<endl;
        lout<<"--"<<endl;
    }
    lout.clear();
    lout.close();

    ofstream bout(".//log//book.txt");
    vsize=be.size();
    for(int i=0;i<vsize;i++)
    {
        bout<<"---"<<endl;
        bout<<be[i].getname()<<endl;
        bout<<be[i].getnumber()<<endl;
        bout<<be[i].getid()<<endl;
        bout<<be[i].getdescribe()<<endl;
        bout<<be[i].gp()<<endl;
        bout<<be[i].getpress()<<endl;
        bout<<be[i].getedition()<<endl;
        bout<<"--"<<endl;
    }
    bout.clear();
    bout.close();

    ofstream oout(".//log//food.txt");
    vsize=fe.size();
    for(int i=0;i<vsize;i++)
    {
        oout<<"---"<<endl;
        oout<<fe[i].getname()<<endl;
        oout<<fe[i].getnumber()<<endl;
        oout<<fe[i].getid()<<endl;
        oout<<fe[i].getdescribe()<<endl;
        oout<<fe[i].gp()<<endl;
        oout<<fe[i].getproducetime()<<endl;
        oout<<fe[i].getfoodsize()<<endl;
        oout<<fe[i].getterm()<<endl;
        oout<<"--"<<endl;
    }
    oout.clear();
    oout.close();

    ofstream rout(".//log//record.txt");
    vsize=platrecord.size();
    for(int i=0;i<vsize;i++)
    {
        rout<<"---"<<endl;
        rout<<platrecord[i].Userid<<endl;
        rout<<platrecord[i].goodsid<<endl;
        rout<<platrecord[i].recordtime<<endl;
        rout<<platrecord[i].addi<<endl;
        rout<<"--"<<endl;
    }
    rout.clear();
    rout.close();

}

void Pplatform::discount()//打折函数/只有管理员才可以使用
{
    cout<<"请选择折扣品类，1：食物 2：衣服3：书；（12）食物和书"<<endl;//剋同事兼容多种情况
    int num=-1;
    cin>>num;
    cout<<"请输入折扣：打几折6折请输入0.6"<<endl;//打几折提示
    double temp=1.0;
    cin>>temp;
    switch(num)
    {
    case 1:
        Pfoodeff=temp;
        break;
    case 2:
        Pclothereff=temp;
        break;
    case 3:
        Pbookeff=temp;
        break;
    case 12:
        Pfoodeff=temp;
        Pclothereff=temp;
        break;
    case 23:
        Pbookeff=temp;
        Pclothereff=temp;
        break;
    case 13:
        Pfoodeff=temp;
        Pbookeff=temp;
        break;
    case 123:
        Pbookeff=temp;
        Pfoodeff=temp;
        Pclothereff=temp;
        break;
    default:
        cout<<"无效的输入,不引起任何改变"<<endl;
    }
}

unsigned int RSHsh(string mas)              //hash函数，在本体中的主要作用就是把字符串映射到ing
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

    return (hash  & 0x3FFF);
}
int stringtoint(string s)//基本函数
{
    int num;
    stringstream ss(s);
    ss>>num;
    return num;
}

string inttostring(int i)//更具名字，int转化为string
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

int Pplatform::idtouser(string id)//从id对应响应的顾客
{
    int temp=customers.size();
    if(temp==0){
        cout<<"系统无注册用户，请先注册"<<endl;
        return -1;
    }
    for(int i=0;i<temp;i++)
    {
        if(customers[i].getPuid()==id)
            return i;
    }
    cout<<"系统当前无此用户"<<endl;
    return -1;
}

int Pplatform::idtoproduct(string id)//从id对应响应的产品，无对应返回-1
{
    int i=0;
    int j=fe.size();
    for(i=0;i<j;i++){
        if(fe[i].getid()==id){
            return i*10+1;
        }
    }
    j=ce.size();
    for(i=0;i<j;i++){
        if(ce[i].getid()==id){
            return i*10+2;
        }
    }
    j=be.size();
    for(i=0;i<j;i++){
        if(be[i].getid()==id){
            return i*10+3;
        }
    }
    return -1;
}
void Pplatform::registuser()//注册函数。主要就是提示用户一步步注册
{
    cout<<"欢迎来到注册系统"<<endl;
    //customer(vector <string> &li,string na,string id,string ba,string ad,string pa);
    string na,id,ba,ad,pa;
    cout<<"请输入姓名：";
    cin>>na;
    while(na.length()<2||na.length()>20){
        cout<<"请输入合理长度2-20的姓名：";
        cin>>na;
    }
    id=inttostring(RSHsh(na));
    cout<<"这是系统分配给你的id："<<id<<endl;
    cout<<"请输入银行账户id：";
    cin>>ba;
    while(ba.length()<8||ba.length()>20){
        cout<<"请输入合理范围内的银行账户"<<endl;
        cin>>ba;
    }
    ad="";
    cout<<"请输入密码："<<endl;
    cin>>pa;
    vector<string> tt;
    customer temp(tt,na,id,ba,ad,pa);
    customers.push_back(temp);

    record t(id,"","regist");
    platrecord.push_back(t);
}

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)//cfenge/v ans/s bei用来区分字符串，功能函数
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

void Pplatform::ViewAllProduct()//查看所有产品
{
    cout<<"输入1，2，3查看food/clother/book"<<endl;
    string tem;
    cin>>tem;
    vector<string> temp;
    SplitString(tem,temp,",");
    for(int i=0;i<temp.size();i++)
    {
        if(stringtoint(temp[i])==1)
        {
            int sss=fe.size();
            for(int j=0;j<sss;j++)
                fe[j].show();
        }
        else if(stringtoint(temp[i])==2)
        {
            int sss=ce.size();
            for(int j=0;j<sss;j++)
                ce[j].show();
        }
        else if(stringtoint(temp[i])==3)
        {
            int sss=be.size();
            for(int j=0;j<sss;j++)
                be[j].show();
        }
    }
}
void Pplatform::hello()//简单的开始函数，害怕主函数过大，所以优的hello函数/作用简单，无其他先关影响
{
    cout<<"欢迎来到天猫购物平台"<<endl;
    cout<<"∧,,,∧"<<endl;
    cout<<"/≥﹏≤\\"<<endl;
    cout<<"=: :="<<endl;
    cout<<"╰/)(\\\\╯"<<endl;
    cout<<"如果你是想注册账户请按1，登陆请按2，退出请按0"<<endl;
    int choice;
    cin>>choice;

    while(choice!=0&&choice!=2&&choice!=1){

        cout<<choice<<"无效的输入"<<endl;
        cin>>choice;
    }

    if(choice==1)
        registuser();
    cout<<"请输入你的id：";
    string inid;
    cin>>inid;
    int nn=idtouser(inid);
    if(nn!=-1){

    string temppassword;
    cout<<"请输入密码：";
    while(customers[nn].getpassword()!=temppassword)
        cin>>temppassword;
    local=nn;
        record t(inid,"","sign-in");
    platrecord.push_back(t);
    }
    else
    {
        cout<<"没有这个账号！"<<endl;
        local= -2;
    }

}
string DoubleToString(double Input)//把double转化为string的函数
{
    stringstream Oss;
    Oss<<Input;
    return Oss.str();
}
bool Pplatform::zhifu(double localjine)//支付函数，在知乎的时候使用socket通信，也是这个程序的关键
{
    string chuanshu;

    if(localjine>0)
    {
        string zuichu=customers[local].getPubankid();//开始的一段使用
        vector <string>zhanghao;//主要作用是存储统一用户的很多账号


        SplitString(zuichu,zhanghao,"/");//把一个账号整体分为可用账号

        cout<<"你有这些账号："<<endl;
        for(int i=0;i<zhanghao.size();i++)//首先展示所偶账号供用户选择
            cout<<zhanghao[i]<<endl;

        cout<<"请输入你的选择："<<endl;
        int cchoic=100;//选择向量，首先给一个比较大的初值
        while(cchoic>zhanghao.size())//然后在不符合的时候一直循环输入，知道有合适的时候在输出
        {
            cin>>cchoic;
        }
        string padd;
        chuanshu=zhanghao[cchoic-1]+"/";//定义以后要作为变量发送的字符串
        //string padd;//定义密码，供用户输入

        cout<<"请输入银行卡密码："<<endl;
        cin>>padd;
        chuanshu=chuanshu+padd+"/"+DoubleToString(localjine);//把账号和密码一起发送过去
    }
    else
        chuanshu="guanbi/12345/-2";
    const char *fasong = chuanshu.c_str();//将账号转换为socket通信使用的char*

    WORD wVersionRequested;//初始化
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD( 1, 1 );//协议选择

    err = WSAStartup( wVersionRequested, &wsaData );//定义异常
    if ( err != 0 ) {
        return false;
    }

    if ( LOBYTE( wsaData.wVersion ) != 1 ||HIBYTE( wsaData.wVersion ) != 1 ) {//建立连接否则返回false
        WSACleanup( );
        return false;
    }
    SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);

    SOCKADDR_IN addrSrv;//声明socket结构体
    addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");//ip地址
    addrSrv.sin_family=AF_INET;//协议选择
    addrSrv.sin_port=htons(6000);//端口选择

    connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));//建立连接

    send(sockClient,fasong,strlen(fasong)+1,0);//socket发送
    char recvBuf[50];
    recv(sockClient,recvBuf,50,0);//接受对面的返回
    printf("%s\n",recvBuf);
    closesocket(sockClient);//关闭socket端口
    WSACleanup();
    if(recvBuf[10]=='s'&&strlen(recvBuf)==17)
        return true;
    else
        return false;
}
void Pplatform::addlike()//添加喜欢函数，根据商品的id
{
    cout<<"请输入想要添加的商品的编号"<<endl;
    string te;
    cin>>te;
    int ann=idtoproduct(te);

    if(ann>0)
    {
        customers[local].addlike(te);
        record t(customers[local].getPuid(),te,"addlike");//增加一条记录
        cout<<"已经添加"<<customers[local].getPuid()<<"商品"<<endl;
        platrecord.push_back(t);
    }
    else
        cout<<"没有这件商品"<<endl;
}
void Pplatform::buy(string buyid)//购买函数，主要就是接口函数，把函数输入对应到特定的品类
{
    int cho=idtoproduct(buyid);//对应到特定的品类

    if(cho>0){
        int ty=cho-(cho/10)*10;//
        if(ty==1)
        {
            if(fe[cho/10].getnumber()>0)
            {
                double lingshijine=fe[cho/10].getPrice()*Pfoodeff;//由折扣和价格算出现在的价格

                if(lingshijine>manjianmenxian)
                    lingshijine=lingshijine-manjianjine;//满减金额
                cout<<"您的实际应付金额："<<lingshijine<<endl;
                if(zhifu(lingshijine))//调用支付函数，如果支付成功就可以
                {
                    fe[cho/10].changenumber(fe[cho/10].getnumber()-1);//数量减一
                    record t(customers[local].getPuid(),fe[cho/10].getid(),"buy food");//产生记录

                    platrecord.push_back(t);//将记录压栈
                    cout<<"购买食物成功"<<endl;
                }
                else
                {
                    cout<<"支付失败，购买失败！"<<endl;
                }
            }
            else
                cout<<"没有足够的数量"<<endl;
        }
        else if(ty==2)
        {
            if(ce[cho/10].getnumber()>0)
            {
                double lingshijine=ce[cho/10].getPrice()*Pclothereff;

                if(lingshijine>manjianmenxian)
                    lingshijine=lingshijine-manjianjine;
                   cout<<"您的实际应付金额："<<lingshijine<<endl;
                if(zhifu(lingshijine))
                {
                    ce[cho/10].changenumber(ce[cho/10].getnumber()-1);
                    record t(customers[local].getPuid(),ce[cho/10].getid(),"buy clothe");

                    platrecord.push_back(t);
                    cout<<"购买衣服成功"<<endl;
                }
            }
            else
                cout<<"没有足够的数量"<<endl;
        }
        else if (ty==3)
        {
            if(be[cho/10].getnumber()>0)
            {
                double lingshijine=be[cho/10].getPrice()*Pbookeff;

                if(lingshijine>manjianmenxian)
                    lingshijine=lingshijine-manjianjine;
                cout<<"您的实际应付金额："<<lingshijine<<endl;
                if(zhifu(lingshijine))
                {
                    be[cho/10].changenumber(be[cho/10].getnumber()-1);
                    record t(customers[local].getPuid(),be[cho/10].getid(),"buy book");

                    platrecord.push_back(t);
                    cout<<"购买书籍成功"<<endl;
                }
            }
            else
                cout<<"没有足够的数量"<<endl;
        }
        else{
            cout<<"程序错误！"<<endl;
        }
    }
    else{
        cout<<"无效的id："<<buyid<<endl;
    }
}
void Pplatform::changeinfo()//改变信息函数
{
    cout<<"你要修改什么信息，1.修改姓名 2.重新绑定银行 3.修改附加信息 4.修改密码"<<endl;
    int choice=-1;
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            cout<<"请输入姓名：";
            string ttt;
            cin>>ttt;
            customers[local].changename(ttt);
            break;
        }
    case 2:
        {
            cout<<"请输入银行id：";
            string ttt;
            cin>>ttt;
            customers[local].changebankid(ttt);
            break;
        }
    case 3:
        {
             cout<<"请输入附加信息：";
            string ttt;
            cin>>ttt;
            customers[local].changeaddition(ttt);
            break;
        }
    case 4:
        {
             cout<<"请输入密码：";
            string ttt;
            cin>>ttt;
            customers[local].changepassword(ttt);
            break;
        }
    }
    cout<<"修改成功！"<<endl;
}
int str_dist(const string source,const string target)
{
    //step 1

    int n=source.length();
    int m=target.length();
    if (m==0) return n;
    if (n==0) return m;
    //Construct a matrix
    typedef vector< vector<int> >  Tmatrix;
    Tmatrix matrix(n+1);
    for(int i=0; i<=n; i++)  matrix[i].resize(m+1);

    //step 2 Initialize

    for(int i=1;i<=n;i++) matrix[i][0]=i;
    for(int i=1;i<=m;i++) matrix[0][i]=i;

     //step 3
     for(int i=1;i<=n;i++)
     {
        const char si=source[i-1];
        //step 4
        for(int j=1;j<=m;j++)
        {

            const char dj=target[j-1];
            //step 5
            int cost;
            if(si==dj){
                cost=0;
            }
            else{
                cost=1;
            }
            //step 6
            const int above=matrix[i-1][j]+1;
            const int left=matrix[i][j-1]+1;
            const int diag=matrix[i-1][j-1]+cost;
            matrix[i][j]=min(above,min(left,diag));

        }
     }//step7
      return matrix[n][m];
}
void Pplatform::run()//运行函数
{
    hello();
    if(local!=-2)//如果local=-2退出
    {
    cout<<"1：浏览全部商品";
    cout<<"2: 添加到喜欢"<<endl;
    cout<<"3：支付";
    cout<<"4：修改信息"<<endl;
    cout<<"5: 管理平台"<<endl;
    cout<<"6: 退出"<<endl;
    cout<<"7: 我的购物车"<<endl;
    cout<<"8: 搜索"<<endl;
    while(true){
            cout<<local;
            cout<<"请输入您的选择：";
        int choice;
        int qquit=0;
        cin>>choice;
        while(choice>11||choice<1)
            cin>>choice;
        switch(choice){
        case 1:
            {
                ViewAllProduct();
                break;
            }
        case 2:
            {
                addlike();
                break;
            }
        case 3:
            {
                string inn;
                cout<<"请输入你要买的商品id:"<<endl;
                cin>>inn;
                buy(inn);
                break;

            }
        case 4:
            {
                changeinfo();
                break;
            }
        case 5:
            {
                if(customers[local].getPuaddition()=="manager")
                    manager();
                else
                    cout<<"您不是管理员！"<<endl;
                break;
            }
        case 6:
            {
                qquit=1;
                cout<<"祝您生活愉快!"<<endl;
                break;
            }
        case 7:
            {
                cout<<"2代表管理购物车，3代表买空购物车"<<endl;
                vector <string >ans;
                customers[local].getPulike(ans);
                for(int i=0;i<ans.size();i++)
                    cout<<"商品ID："<<ans[i]<<endl;
                int choice;
                cin>>choice;
                if(choice==2)
                {
                    cout<<"选择要删除的产品"<<endl;
                    int choi;
                    cin>>choi;
                    if(choi<ans.size())
                        customers[local].deletelike(ans[choi-1]);
                    else
                        cout<<"超出范围"<<endl;
                }
                else if(choice==3)
                {
                    for(int i=0;i<ans.size();i++)
                    {
                        buy(ans[i]);
                    }
                    for(int i=0;i<ans.size();i++)
                    {
                        customers[local].deletelike(ans[i]);
                    }
                }
                else{
                    cout<<"无效的选择"<<endl;
                }
                break;
            }
        case 8:
            {
                    cout<<"请输入关键字："<<endl;
                    string target;
                    cin>>target;
                    int sss=fe.size();
                    for(int j=0;j<sss;j++)
                    {
                         if(str_dist(target,fe[j].getname())<=2)
                            fe[j].show();
                    }
                    sss=ce.size();
                    for(int j=0;j<sss;j++)
                    {
                         if(str_dist(target,ce[j].getname())<=2)
                            ce[j].show();
                    }
                    sss=be.size();
                    for(int j=0;j<sss;j++)
                    {
                         if(str_dist(target,be[j].getname())<=2)
                            be[j].show();
                    }

            }
        default:
            {
                cout<<"无效的输入"<<endl;
                break;
            }
        }
        if(qquit==1)
            break;
    }
    }
}
void Pplatform::addproduct(int choice)//添加铲平/管理员选项
{
    if(choice==1)
    {
        cout<<"请输入商品的名字:";
        string name;
        cin>>name;
        cout<<"\n请输入商品的价格:";
        double price;
        cin>>price;
        cout<<"\n请输入商品的数量:";
        int number;
        cin>>number;
        cout<<"\n请输入商品的描述:";
        string describe;
        cin>>describe;
        cout<<"\n请输入商品的id:";
        string pid;
        cin>>pid;
        int producetime=time(NULL);
        cout<<"保质期："<<endl;
        int term;
        cin>>term;
        term*=60*60*24;
        cout<<"请输入食物的大小"<<endl;
        double foodsize;
        cin>>foodsize;
        fe.push_back(Pfood(producetime,term,foodsize,price,name,number,describe,pid));
    }
    else if(choice==2)
    {
        cout<<"请输入商品的名字:";
        string name;
        cin>>name;
        cout<<"\n请输入商品的价格:";
        double price;
        cin>>price;
        cout<<"\n请输入商品的数量:";
        int number;
        cin>>number;
        cout<<"\n请输入商品的描述:";
        string describe;
        cin>>describe;
        cout<<"\n请输入商品的id:";
        string pid;
        cin>>pid;
        cout<<"\n请输入风格：";
        string style;
        cin>>style;
        cout<<"\n请输入衣服的颜色，以半角字符/区分：";
        string color;
        cin>>color;
        ce.push_back(Pclother(color,style,price,name,number,describe,pid));

    }
    else if(choice==3)
    {
        cout<<"请输入商品的名字:";
        string name;
        cin>>name;
        cout<<"\n请输入商品的价格:";
        double price;
        cin>>price;
        cout<<"\n请输入商品的数量:";
        int number;
        cin>>number;
        cout<<"\n请输入商品的描述:";
        string describe;
        cin>>describe;
        cout<<"\n请输入商品的id:";
        string pid;
        cin>>pid;
        cout<<"\n请输入出版社：";
        string style;
        cin>>style;
        cout<<"\n请输入版次";
        int edition;
        cin>>edition;
        be.push_back(Pbook(edition,style,price,name,number,describe,pid));
    }
    else
        cout<<"无效的添加选择"<<endl;
}
void Pplatform::manager()//ZHIYOU GUANLI YUAN YOU NENG LI//管理类
{
    cout<<"1:品类折扣"<<endl;
    cout<<"2:添加商品"<<endl;
    cout<<"4:查看统计"<<endl;
    cout<<"5:满减折扣"<<endl;
    cout<<"6.quit"<<endl;
    while(true)
    {
        int choice;
        cin>>choice;
        bool quit =false;
        switch(choice)
        {
        case 1:
            {
                double temp;
                cout<<"请输入食品的折扣：";
                cin>>temp;
                if(temp>0&&temp<=1)
                    Pfoodeff=temp;
                else
                    cout<<"无效的折扣"<<endl;
                cout<<"请输入衣服的折扣：";
                cin>>temp;
                if(temp>0&&temp<=1)
                    Pclothereff=temp;
                else
                    cout<<"无效的折扣"<<endl;
                    cout<<"请输入书的折扣：";
                cin>>temp;
                if(temp>0&&temp<=1)
                    Pbookeff=temp;
                else
                    cout<<"无效的折扣"<<endl;
                    break;
            }
        case 2:
            {
                int choice;
                cout<<"输入1添加食品，输入2添加衣服，输入3添加书"<<endl;

                cin>>choice;
                addproduct(choice);
                break;
            }
        case 4:
            {
                cout<<"购买活动统计如下"<<endl;
                break;
            }
        case 5:
            {
                cout<<"请输入满减金额：";
                double num;
                cin>>num;
                if(num>0)
                    manjianmenxian=num;
                cout<<"\n请输入满减门限："<<endl;
                cin>>num;
                if(num>0&&num<manjianmenxian)
                    manjianjine=num;
                    break;
            }
        default:
            {
                quit=true;
            }
        }
        if(quit)
        {
            cout<<"管理员再见！"<<endl;
            break;
        }

    }
}
