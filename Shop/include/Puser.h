#ifndef PUSER_H
#define PUSER_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>//�������ɼ�¼��ʱ����õ�ǰʱ��

using namespace std;

class Puser//�û���
{
    public:
        Puser();//�޲������캯��
        Puser(string na,string id,string ba,string ad,string pa);//�в������캯��
        virtual ~Puser();//��������
        void changename(string newname);//�ı�����
        void changeid(string newid);//�ı�id
        void changebankid(string newbankid);//�ı������˻�ud
        void changeaddition(string newaddition);//�ı丽����Ϣ
        void changepassword(string newpassword);//�ı�����
        string getPuname();//�õ�����
        string getPuid();//�õ�id
        string getPubankid();//�õ�����id
        string getPuaddition();//�õ�������Ϣ
        string getpassword();//�õ�����
    private:
        string Puname;//����
        string Puid;//id
        string PuBankid;//yinhangid
        string Puaddition;//������Ϣ
        string Pupassword;//����
};
class customer:public Puser//�˿�
{
private:
    vector <string> Pulike;//ϲ���б�
public:
    customer(vector <string> &li,string na,string id,string ba,string ad,string pa);//���캯��
    ~customer();
    void addlike(string productid);//���ڵ����û������ϲ������
    void deletelike(string productid);//ɾ��ϲ��
    void getPulike(vector <string> &ans);//�õ�ϲ��vector
};

#endif // PUSER_H
