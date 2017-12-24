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
    cout<<"��ѡ���ۿ�Ʒ�࣬1��ʳ�� 2���·�3���飻��12��ʳ�����"<<endl;
    int num=-1;
    cin>>num;
    cout<<"�������ۿۣ�����6��������0.6"<<endl;
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
        cout<<"��Ч������,�������κθı�"<<endl;
    }
}

unsigned int RSHsh(string mas)              //hash����
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
int stringtoint(string s)//��������
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
        cout<<"ϵͳ��ע���û�������ע��"<<endl;
        return -1;
    }
    for(int i=0;i<temp;i++)
    {
        if(customers[i].getPuid()==id)
            return i;
    }
    cout<<"ϵͳ��ǰ�޴��û�"<<endl;
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
    cout<<"��ӭ����ע��ϵͳ"<<endl;
    //customer(vector <string> &li,string na,string id,string ba,string ad,string pa);
    string na,id,ba,ad,pa;
    cout<<"������������";
    cin>>na;
    while(na.length()<2||na.length()>20){
        cout<<"�����������2-20��������";
        cin>>na;
    }
    id=inttostring(RSHsh(na));
    cout<<"����ϵͳ��������id��"<<id<<endl;
    cout<<"�����������˻�id��";
    cin>>ba;
    while(ba.length()<8||ba.length()>20){
        cout<<"���������Χ�ڵ������˻�"<<endl;
        cin>>ba;
    }
    ad="";
    cout<<"���������룺"<<endl;
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
    cout<<"����1��2��3�鿴food/clother/book"<<endl;
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
    cout<<"��ӭ������è����ƽ̨"<<endl;
    cout<<"��,,,��"<<endl;
    cout<<"/�ݩn��\\"<<endl;
    cout<<"=: :="<<endl;
    cout<<"�t/)(\\\\�s"<<endl;
    cout<<"���������ע���˻��밴1����½�밴2���˳��밴0"<<endl;
    int choice;
    cin>>choice;

    while(choice!=0&&choice!=2&&choice!=1){

        cout<<choice<<"��Ч������"<<endl;
        cin>>choice;
    }

    if(choice==1)
        registuser();
    cout<<"���������id��";
    string inid;
    cin>>inid;
    int nn=idtouser(inid);
    if(nn!=-1){

    string temppassword;
    cout<<"���������룺";
    while(customers[nn].getpassword()!=temppassword)
        cin>>temppassword;
    local=nn;
        record t(inid,"","sign-in");
    platrecord.push_back(t);
    }
    else
    {
        cout<<"û������˺ţ�"<<endl;
        local= -2;
    }

}

bool Pplatform::zhifu(double localjine)
{
    return true;
}
void Pplatform::addlike()
{
    cout<<"��������Ҫ��ӵ���Ʒ�ı��"<<endl;
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
        cout<<"û�������Ʒ"<<endl;
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
                        cout<<"���������ˣ�����ʧ��"<<endl;
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
                        cout<<"���������ˣ�����ʧ��"<<endl;
                }

            }
        }
        else{
            cout<<"�������"<<endl;
        }
    }
    else{
        cout<<"��Ч��id��"<<buyid<<endl;
    }
}
void Pplatform::changeinfo()
{
    cout<<"��Ҫ�޸�ʲô��Ϣ��1.�޸����� 2.���°����� 3.�޸ĸ�����Ϣ 4.�޸�����"<<endl;
    int choice=-1;
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            cout<<"������������";
            string ttt;
            cin>>ttt;
            customers[local].changename(ttt);
            break;
        }
    case 2:
        {
            cout<<"����������id��";
            string ttt;
            cin>>ttt;
            customers[local].changebankid(ttt);
            break;
        }
    case 3:
        {
             cout<<"�����븽����Ϣ��";
            string ttt;
            cin>>ttt;
            customers[local].changeaddition(ttt);
            break;
        }
    case 4:
        {
             cout<<"���������룺";
            string ttt;
            cin>>ttt;
            customers[local].changepassword(ttt);
            break;
        }
    }
    cout<<"�޸ĳɹ���"<<endl;
}
void Pplatform::run()
{
    hello();
    if(local!=-2)
    {
    cout<<"1�����ȫ����Ʒ";
    cout<<"2: ��ӵ�ϲ��"<<endl;
    cout<<"3��֧��";
    cout<<"4���޸���Ϣ"<<endl;
    cout<<"5: ����ƽ̨"<<endl;
    cout<<"6: �˳�"<<endl;
    cout<<"7: �ҵĹ��ﳵ"<<endl;
    while(true){
            cout<<local;
            cout<<"����������ѡ��";
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
                cout<<"��������Ҫ�����Ʒid:"<<endl;
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
                    cout<<"�����ǹ���Ա��"<<endl;
                break;
            }
        case 6:
            {
                qquit=1;
                cout<<"ף���������!"<<endl;
                break;
            }
        case 7:
            {
                cout<<"������1����鿴���ﳵ��2��������ﳵ��3������չ��ﳵ"<<endl;
                vector <string >ans;
                customers[local].getPulike(ans);
                for(int i=0;i<ans.size();i++)
                    cout<<"��ƷID��"<<ans[i]<<endl;
                break;
            }
        default:
            {
                cout<<"��Ч������"<<endl;
            }
        }
        if(qquit==1)
            break;
    }
    }
}
void Pplatform::manager()//ZHIYOU GUANLI YUAN YOU NENG LI
{
    cout<<"����"<<endl;
    cout<<"Ʒ���ۿ�"<<endl;
    cout<<"�����Ʒ"<<endl;
    cout<<"�¼���ƽ"<<endl;
    cout<<"�˳�"<<endl;
}
