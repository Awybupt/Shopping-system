/*
* create by κ��
* 2017/12/12
*/

#ifndef PPLATFORM_H
#define PPLATFORM_H

#include "Pproduct.h"//��Ʒ����
#include "Puser.h"//�û�����
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;
typedef struct jiaoyirecord{//���׼�¼
    string Userid;
    //���׵�id
    string goodsid;
    //�����id������ȱʡ
    time_t recordtime;
    //�������׵�ʱ��
    string addi;
    //����˵�������繺��ʽ����������
    jiaoyirecord(string u,string g,string a)//���׼�¼�Ĺ��캯��
    {
        Userid=u;
        goodsid=g;
        recordtime=time(NULL);
        addi=a;
    }
    jiaoyirecord(string u,string g,time_t t,string a)//���׼�¼���ֳ����캯��
    {
        Userid=u;
        goodsid=g;
        recordtime=t;
        addi=a;
    }
    bool operator <(const jiaoyirecord &a)//���رȽ������
    {
        if(a.recordtime<recordtime)
            return false;
        else
            return true;
    }
}record;

class Pplatform//ƽ̨��
{
    public:
        Pplatform();
        //���캯������ȡ�ļ�
        ~Pplatform();
        //��������
        void registuser();
        //ע���û�
        void hello();
        //��ʼ�����򣬽���һЩ�򵥵��ʹ�
        void run();
        //���г����������������
        void buy(string buyid);
        //��������Ϊ�˷����Ժ�ʹ�ã������в�������������ʽ
        void manager();
        //ZHIYOU GUANLI YUAN YOU NENG LI
        void discount();
        //���׺���
        void ViewAllProduct();
        //�鿴���в�Ʒ
        void addlike();
        //��ӵ�ϲ������
        int idtouser(string id);
        //��id��Ӧ����Ӧ�Ĺ˿�
        int idtoproduct(string id);
        //�Ӹ���ƽ��Ӧ����Ӧ�Ĳ�ƽ
        void changeinfo();//�ı���Ϣ
        bool zhifu(double localjine);
        //֧������������ڲ�Ʒ
    private:

        vector<customer> customers;
        //�˿͵���Ϣ�������ݽṹ�Ļ���
        vector<Pfood> fe;
        //ʳ��
        double Pfoodeff;
        //ʳ����ۿ�ϵ���ۿ�ϵ��
        vector<Pclother> ce;
        //�·�
        double Pclothereff;
        //�·����ۿ�
        vector<Pbook> be;
        //��
        double Pbookeff;
        //����ۿ�
        double manjianmenxian;
        //�������ޣ����������Ŀ�ͼ���
        double manjianjine;
        //���������ڼ��ٵ���Ŀ
        vector<record> platrecord;
        //����ƽ̨�ļ�¼��ͳһ������������ݽṹ��������������
        int local;
        //��ǰ��¼����customers�е�λ��
        void addproduct(int choice);
        //˽�з����������ƽ��������˽�е�manager
};

#endif // PPLATFORM_H
