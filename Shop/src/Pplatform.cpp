#include "Pplatform.h"
#include <sstream>
#include <fstream>
Pplatform::Pplatform()
{
    //ctor
    fstream fin;
    fin.open(".//log//customer.txt",fstream::in);
    string str,a,b,c,d,e,f,g,h,i;
    int j,k,l,m;
    double n,o,p,q;
    while(!fin.eof())
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
    fin.clear();
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

Pplatform::~Pplatform()
{
    //dtor
    //customer
    ofstream fout(".//log//customer.txt");
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

void Pplatform::discount()
{
    cout<<"请选择折扣品类，1：食物 2：衣服3：书；（12）食物和书"<<endl;
    int num=-1;
    cin>>num;
    cout<<"请输入折扣：打几折6折请输入0.6"<<endl;
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

unsigned int RSHsh(string mas)              //hash函数
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

string inttostring(int i)
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

int Pplatform::idtouser(string id)
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

int Pplatform::idtoproduct(string id)
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
void Pplatform::registuser()
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

void Pplatform::ViewAllProduct()
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
void Pplatform::hello()
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

bool Pplatform::zhifu(double localjine)
{
    return true;
}
void Pplatform::addlike()
{
    cout<<"请输入想要添加的商品的编号"<<endl;
    string te;
    cin>>te;
    int ann=idtoproduct(te);
    if(ann>0)
    {
        customers[local].addlike(te);
        record t(customers[local].getPuid(),te,"addlike");
        platrecord.push_back(t);
    }
    else
        cout<<"没有这件商品"<<endl;
}
void Pplatform::buy(string buyid)
{
    int cho=idtoproduct(buyid);
    if(cho>0){
        int ty=cho-(cho/10)*10;
        if(ty==1)
        {
            if(fe[cho/10].getnumber()>0)
            {
                if(zhifu(fe[cho/10].getPrice()))
                {
                    fe[cho/10].changenumber(fe[i].getnumber()-1);

                }
            }
        }
        else if(ty==2)
        {
            for(int i=0;i<ce.size();i++)
            {
                if(ce[i].getid()==buyid)
                {
                    if(ce[i].getnumber()>0)
                        ce[i].changenumber(ce[i].getnumber()-1);
                    else
                        cout<<"数量不够了，购买失败"<<endl;
                }

            }
        }
        else if (ty==3)
        {
            for(int i=0;i<be.size();i++)
            {
                if(be[i].getid()==buyid)
                {
                    if(be[i].getnumber()>0)
                        be[i].changenumber(be[i].getnumber()-1);
                    else
                        cout<<"数量不够了，购买失败"<<endl;
                }

            }
        }
        else{
            cout<<"程序错误！"<<endl;
        }
    }
    else{
        cout<<"无效的id："<<buyid<<endl;
    }
}
void Pplatform::changeinfo()
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
void Pplatform::run()
{
    hello();
    if(local!=-2)
    {
    cout<<"1：浏览全部商品";
    cout<<"2: 添加到喜欢"<<endl;
    cout<<"3：支付";
    cout<<"4：修改信息"<<endl;
    cout<<"5: 管理平台"<<endl;
    cout<<"6: 退出"<<endl;
    cout<<"7: 我的购物车"<<endl;
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
                cout<<"请输入1代表查看购物车，2代表管理购物车，3代表买空购物车"<<endl;
                vector <string >ans;
                customers[local].getPulike(ans);
                for(int i=0;i<ans.size();i++)
                    cout<<"商品ID："<<ans[i]<<endl;
                break;
            }
        default:
            {
                cout<<"无效的输入"<<endl;
            }
        }
        if(qquit==1)
            break;
    }
    }
}
void Pplatform::manager()//ZHIYOU GUANLI YUAN YOU NENG LI
{
    cout<<"打折"<<endl;
    cout<<"品类折扣"<<endl;
    cout<<"添加商品"<<endl;
    cout<<"下架上平"<<endl;
    cout<<"退出"<<endl;
}
