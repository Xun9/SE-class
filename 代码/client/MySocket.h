#pragma once
#pragma comment(lib, "Ws2_32.lib")
#include <SQLAPI.h>
#include<string>
#include<iostream>
#include<WinSock.h>
#include"MyStruct.h"
#include"define.h"
using namespace std;

class MySocket                                                       //�׽��ַ�װ
{
private:
	SOCKET s;
	SOCKET remote;                                                  //��Զ���������ӵ��׽��֣����ڱ���ͻ��˵�ip�˿ڵ���Ϣ
public:
	MySocket();
	void Bind(u_short port);                        //���ڷ�������
	void Listen(int num);											  //���ڷ���������
	void Accept();                                                      //���ڷ������ȴ�����
	void Receive(int c_s, char* buf, unsigned int size, int flag);        //������Ϣ���������Ϳͻ���ͨ��
	void Send(int c_s, char* buf, unsigned int size, int flag);             //������Ϣ���������Ϳͻ���ͨ��
	void Connect(char* ip,u_short port);                             //�ͻ����������ӷ����� ��Ҫ��������ip�Լ��˿�
	void Serstart(u_short port, int wait_num);        //�����������׽���
};
