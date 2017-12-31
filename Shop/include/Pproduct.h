#ifndef PPRODUCT_H
#define PPRODUCT_H

#include <iostream>//�������
#include <string>//string
#include <vector>//����vector

using namespace std;

class Pproduct
{
    public:
        Pproduct();//�޲�����Ʒ���캯��
        Pproduct(double p,string n,int nu,string d,string id);//�в�����ƽ���๹�캯��
        ~Pproduct();//��������

        void changePrice(double p);//�ı�۸�
        virtual double getPrice();//�õ��۸�
        virtual void show()=0;//��ȫ�麯��
        double gp();//�õ������۸�
        void changename(string n);//��������
        string getname();//�õ�����

        void changenumber(int n);//�ı�����
        int getnumber();//�õ�����

        void changeid(string i);//�ı�id
        string getid();//�õ�id
        void changedescribe(string d);//�ı�����
        string getdescribe();//�õ�����

    private:
        double Price;//�۸�
        string name;//����
        int number;//����
        string describe;//����
        string pid;//��Ʒid
};

class Pfood:public Pproduct//ʳ������
{
private://˽��
    int producetime;//����ʱ��
    int term;//������
    double Foodsize;//ʳ���С
public:

    Pfood();//ʳ���޲������캯��
    Pfood(int p,int t,double fs,double pp,string n,int nu,string d,string id);//�в������캯��
    ~Pfood();//��������

    void show();//չʾ���������常���е�����
    void fchangeproducetime(int pr);//�ı�����ʱ��

    int getproducetime();//�ĵ�����ʱ��
    void changefoodsize(double fs);//�ı�ʳ���С

    double getfoodsize();//�õ�ʳ���С
    virtual double getPrice();//�õ��۸�

    void fchangeterm(int te);//�ı�����
    int getterm();//�õ�������

    bool judgefresh();//�ж��ǲ�������
};

class Pclother:public Pproduct//�·�����
{
private:
    string color;//��ɫ
    string style;//���
public:
    Pclother(string c,string st,double p,string n,int nu,string d,string id);//�·����������캯��
    ~Pclother();//��������
    string getstyle();//�õ�����·��ķ��
    string getcolor();//�õ���ɫ
    void show();//չʾ
    void changestyle(string s);//�ı�ָ�
    void addcolor(string s);//�õ���ɫ
};

class Pbook:public Pproduct//������
{
private:
    int edition;//�õ��汾
    string press;//������
public:
    Pbook(int e,string p,double pp,string n,int nu,string d,string id);//���������캯��
    ~Pbook();//��������
    void show();//չʾ����
    void changeedition(int n);//�ı�汾
    void changepress(string p);//�ı������
    string getpress();//�õ�������
    int getedition();//�õ��汾
};
#endif // PPRODUCT_H
