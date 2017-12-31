#include "Pplatform.h"//Դ����
#include <sstream>//�ַ�����֮��ת��
#include <fstream>//�ļ��������
#include <stdio.h>
#include <Winsock2.h>//socketͨ��
Pplatform::Pplatform()//���캯��
{
    fstream fin;//�ļ��е����ڼ�¼֮����--����
    fin.open(".//log//customer.txt",fstream::in);//���ļ�
    string str,a,b,c,d,e,f,g,h,i;//�����ڶ��ļ����õ����ַ�
    int j,k,l;//double����
    double n,q;
    fin>>Pfoodeff;//��ȡ����������,���¶���
    getline(fin,str);
    fin>>Pclothereff;
    getline(fin,str);
    fin>>Pbookeff;
    getline(fin,str);
    fin>>manjianmenxian;
    getline(fin,str);
    fin>>manjianjine;
    getline(fin,str);

    while(!fin.eof())//��ί��ȡ��ȫʱ����
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
    fin.clear();//��ȡ��һ���ļ���ֹͣ
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

Pplatform::~Pplatform()//��������
{
    zhifu(-2);
    //dtor
    //customer
    ofstream fout(".//log//customer.txt");//����˿�
    fout<<Pfoodeff<<endl;//���������Ʒ �Ĵ���ϵ��
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

void Pplatform::discount()//���ۺ���/ֻ�й���Ա�ſ���ʹ��
{
    cout<<"��ѡ���ۿ�Ʒ�࣬1��ʳ�� 2���·�3���飻��12��ʳ�����"<<endl;//�wͬ�¼��ݶ������
    int num=-1;
    cin>>num;
    cout<<"�������ۿۣ�����6��������0.6"<<endl;//������ʾ
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

unsigned int RSHsh(string mas)              //hash�������ڱ����е���Ҫ���þ��ǰ��ַ���ӳ�䵽ing
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

string inttostring(int i)//�������֣�intת��Ϊstring
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

int Pplatform::idtouser(string id)//��id��Ӧ��Ӧ�Ĺ˿�
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

int Pplatform::idtoproduct(string id)//��id��Ӧ��Ӧ�Ĳ�Ʒ���޶�Ӧ����-1
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
void Pplatform::registuser()//ע�ắ������Ҫ������ʾ�û�һ����ע��
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

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)//cfenge/v ans/s bei���������ַ��������ܺ���
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

void Pplatform::ViewAllProduct()//�鿴���в�Ʒ
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
void Pplatform::hello()//�򵥵Ŀ�ʼ�������������������������ŵ�hello����/���ü򵥣��������ȹ�Ӱ��
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
string DoubleToString(double Input)//��doubleת��Ϊstring�ĺ���
{
    stringstream Oss;
    Oss<<Input;
    return Oss.str();
}
bool Pplatform::zhifu(double localjine)//֧����������֪����ʱ��ʹ��socketͨ�ţ�Ҳ���������Ĺؼ�
{
    string chuanshu;

    if(localjine>0)
    {
        string zuichu=customers[local].getPubankid();//��ʼ��һ��ʹ��
        vector <string>zhanghao;//��Ҫ�����Ǵ洢ͳһ�û��ĺܶ��˺�


        SplitString(zuichu,zhanghao,"/");//��һ���˺������Ϊ�����˺�

        cout<<"������Щ�˺ţ�"<<endl;
        for(int i=0;i<zhanghao.size();i++)//����չʾ��ż�˺Ź��û�ѡ��
            cout<<zhanghao[i]<<endl;

        cout<<"���������ѡ��"<<endl;
        int cchoic=100;//ѡ�����������ȸ�һ���Ƚϴ�ĳ�ֵ
        while(cchoic>zhanghao.size())//Ȼ���ڲ����ϵ�ʱ��һֱѭ�����룬֪���к��ʵ�ʱ�������
        {
            cin>>cchoic;
        }
        string padd;
        chuanshu=zhanghao[cchoic-1]+"/";//�����Ժ�Ҫ��Ϊ�������͵��ַ���
        //string padd;//�������룬���û�����

        cout<<"���������п����룺"<<endl;
        cin>>padd;
        chuanshu=chuanshu+padd+"/"+DoubleToString(localjine);//���˺ź�����һ���͹�ȥ
    }
    else
        chuanshu="guanbi/12345/-2";
    const char *fasong = chuanshu.c_str();//���˺�ת��Ϊsocketͨ��ʹ�õ�char*

    WORD wVersionRequested;//��ʼ��
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD( 1, 1 );//Э��ѡ��

    err = WSAStartup( wVersionRequested, &wsaData );//�����쳣
    if ( err != 0 ) {
        return false;
    }

    if ( LOBYTE( wsaData.wVersion ) != 1 ||HIBYTE( wsaData.wVersion ) != 1 ) {//�������ӷ��򷵻�false
        WSACleanup( );
        return false;
    }
    SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);

    SOCKADDR_IN addrSrv;//����socket�ṹ��
    addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");//ip��ַ
    addrSrv.sin_family=AF_INET;//Э��ѡ��
    addrSrv.sin_port=htons(6000);//�˿�ѡ��

    connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));//��������

    send(sockClient,fasong,strlen(fasong)+1,0);//socket����
    char recvBuf[50];
    recv(sockClient,recvBuf,50,0);//���ܶ���ķ���
    printf("%s\n",recvBuf);
    closesocket(sockClient);//�ر�socket�˿�
    WSACleanup();
    if(recvBuf[10]=='s'&&strlen(recvBuf)==17)
        return true;
    else
        return false;
}
void Pplatform::addlike()//���ϲ��������������Ʒ��id
{
    cout<<"��������Ҫ��ӵ���Ʒ�ı��"<<endl;
    string te;
    cin>>te;
    int ann=idtoproduct(te);

    if(ann>0)
    {
        customers[local].addlike(te);
        record t(customers[local].getPuid(),te,"addlike");//����һ����¼
        cout<<"�Ѿ����"<<customers[local].getPuid()<<"��Ʒ"<<endl;
        platrecord.push_back(t);
    }
    else
        cout<<"û�������Ʒ"<<endl;
}
void Pplatform::buy(string buyid)//����������Ҫ���ǽӿں������Ѻ��������Ӧ���ض���Ʒ��
{
    int cho=idtoproduct(buyid);//��Ӧ���ض���Ʒ��

    if(cho>0){
        int ty=cho-(cho/10)*10;//
        if(ty==1)
        {
            if(fe[cho/10].getnumber()>0)
            {
                double lingshijine=fe[cho/10].getPrice()*Pfoodeff;//���ۿۺͼ۸�������ڵļ۸�

                if(lingshijine>manjianmenxian)
                    lingshijine=lingshijine-manjianjine;//�������
                cout<<"����ʵ��Ӧ����"<<lingshijine<<endl;
                if(zhifu(lingshijine))//����֧�����������֧���ɹ��Ϳ���
                {
                    fe[cho/10].changenumber(fe[cho/10].getnumber()-1);//������һ
                    record t(customers[local].getPuid(),fe[cho/10].getid(),"buy food");//������¼

                    platrecord.push_back(t);//����¼ѹջ
                    cout<<"����ʳ��ɹ�"<<endl;
                }
                else
                {
                    cout<<"֧��ʧ�ܣ�����ʧ�ܣ�"<<endl;
                }
            }
            else
                cout<<"û���㹻������"<<endl;
        }
        else if(ty==2)
        {
            if(ce[cho/10].getnumber()>0)
            {
                double lingshijine=ce[cho/10].getPrice()*Pclothereff;

                if(lingshijine>manjianmenxian)
                    lingshijine=lingshijine-manjianjine;
                   cout<<"����ʵ��Ӧ����"<<lingshijine<<endl;
                if(zhifu(lingshijine))
                {
                    ce[cho/10].changenumber(ce[cho/10].getnumber()-1);
                    record t(customers[local].getPuid(),ce[cho/10].getid(),"buy clothe");

                    platrecord.push_back(t);
                    cout<<"�����·��ɹ�"<<endl;
                }
            }
            else
                cout<<"û���㹻������"<<endl;
        }
        else if (ty==3)
        {
            if(be[cho/10].getnumber()>0)
            {
                double lingshijine=be[cho/10].getPrice()*Pbookeff;

                if(lingshijine>manjianmenxian)
                    lingshijine=lingshijine-manjianjine;
                cout<<"����ʵ��Ӧ����"<<lingshijine<<endl;
                if(zhifu(lingshijine))
                {
                    be[cho/10].changenumber(be[cho/10].getnumber()-1);
                    record t(customers[local].getPuid(),be[cho/10].getid(),"buy book");

                    platrecord.push_back(t);
                    cout<<"�����鼮�ɹ�"<<endl;
                }
            }
            else
                cout<<"û���㹻������"<<endl;
        }
        else{
            cout<<"�������"<<endl;
        }
    }
    else{
        cout<<"��Ч��id��"<<buyid<<endl;
    }
}
void Pplatform::changeinfo()//�ı���Ϣ����
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
void Pplatform::run()//���к���
{
    hello();
    if(local!=-2)//���local=-2�˳�
    {
    cout<<"1�����ȫ����Ʒ";
    cout<<"2: ��ӵ�ϲ��"<<endl;
    cout<<"3��֧��";
    cout<<"4���޸���Ϣ"<<endl;
    cout<<"5: ����ƽ̨"<<endl;
    cout<<"6: �˳�"<<endl;
    cout<<"7: �ҵĹ��ﳵ"<<endl;
    cout<<"8: ����"<<endl;
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
                cout<<"2��������ﳵ��3������չ��ﳵ"<<endl;
                vector <string >ans;
                customers[local].getPulike(ans);
                for(int i=0;i<ans.size();i++)
                    cout<<"��ƷID��"<<ans[i]<<endl;
                int choice;
                cin>>choice;
                if(choice==2)
                {
                    cout<<"ѡ��Ҫɾ���Ĳ�Ʒ"<<endl;
                    int choi;
                    cin>>choi;
                    if(choi<ans.size())
                        customers[local].deletelike(ans[choi-1]);
                    else
                        cout<<"������Χ"<<endl;
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
                    cout<<"��Ч��ѡ��"<<endl;
                }
                break;
            }
        case 8:
            {
                    cout<<"������ؼ��֣�"<<endl;
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
                cout<<"��Ч������"<<endl;
                break;
            }
        }
        if(qquit==1)
            break;
    }
    }
}
void Pplatform::addproduct(int choice)//��Ӳ�ƽ/����Աѡ��
{
    if(choice==1)
    {
        cout<<"��������Ʒ������:";
        string name;
        cin>>name;
        cout<<"\n��������Ʒ�ļ۸�:";
        double price;
        cin>>price;
        cout<<"\n��������Ʒ������:";
        int number;
        cin>>number;
        cout<<"\n��������Ʒ������:";
        string describe;
        cin>>describe;
        cout<<"\n��������Ʒ��id:";
        string pid;
        cin>>pid;
        int producetime=time(NULL);
        cout<<"�����ڣ�"<<endl;
        int term;
        cin>>term;
        term*=60*60*24;
        cout<<"������ʳ��Ĵ�С"<<endl;
        double foodsize;
        cin>>foodsize;
        fe.push_back(Pfood(producetime,term,foodsize,price,name,number,describe,pid));
    }
    else if(choice==2)
    {
        cout<<"��������Ʒ������:";
        string name;
        cin>>name;
        cout<<"\n��������Ʒ�ļ۸�:";
        double price;
        cin>>price;
        cout<<"\n��������Ʒ������:";
        int number;
        cin>>number;
        cout<<"\n��������Ʒ������:";
        string describe;
        cin>>describe;
        cout<<"\n��������Ʒ��id:";
        string pid;
        cin>>pid;
        cout<<"\n��������";
        string style;
        cin>>style;
        cout<<"\n�������·�����ɫ���԰���ַ�/���֣�";
        string color;
        cin>>color;
        ce.push_back(Pclother(color,style,price,name,number,describe,pid));

    }
    else if(choice==3)
    {
        cout<<"��������Ʒ������:";
        string name;
        cin>>name;
        cout<<"\n��������Ʒ�ļ۸�:";
        double price;
        cin>>price;
        cout<<"\n��������Ʒ������:";
        int number;
        cin>>number;
        cout<<"\n��������Ʒ������:";
        string describe;
        cin>>describe;
        cout<<"\n��������Ʒ��id:";
        string pid;
        cin>>pid;
        cout<<"\n����������磺";
        string style;
        cin>>style;
        cout<<"\n��������";
        int edition;
        cin>>edition;
        be.push_back(Pbook(edition,style,price,name,number,describe,pid));
    }
    else
        cout<<"��Ч�����ѡ��"<<endl;
}
void Pplatform::manager()//ZHIYOU GUANLI YUAN YOU NENG LI//������
{
    cout<<"1:Ʒ���ۿ�"<<endl;
    cout<<"2:�����Ʒ"<<endl;
    cout<<"4:�鿴ͳ��"<<endl;
    cout<<"5:�����ۿ�"<<endl;
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
                cout<<"������ʳƷ���ۿۣ�";
                cin>>temp;
                if(temp>0&&temp<=1)
                    Pfoodeff=temp;
                else
                    cout<<"��Ч���ۿ�"<<endl;
                cout<<"�������·����ۿۣ�";
                cin>>temp;
                if(temp>0&&temp<=1)
                    Pclothereff=temp;
                else
                    cout<<"��Ч���ۿ�"<<endl;
                    cout<<"����������ۿۣ�";
                cin>>temp;
                if(temp>0&&temp<=1)
                    Pbookeff=temp;
                else
                    cout<<"��Ч���ۿ�"<<endl;
                    break;
            }
        case 2:
            {
                int choice;
                cout<<"����1���ʳƷ������2����·�������3�����"<<endl;

                cin>>choice;
                addproduct(choice);
                break;
            }
        case 4:
            {
                cout<<"����ͳ������"<<endl;
                break;
            }
        case 5:
            {
                cout<<"������������";
                double num;
                cin>>num;
                if(num>0)
                    manjianmenxian=num;
                cout<<"\n�������������ޣ�"<<endl;
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
            cout<<"����Ա�ټ���"<<endl;
            break;
        }

    }
}
