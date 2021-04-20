#pragma once
#include"MySocket.h"
class MyClient
{
private:
	MySocket command;                 //�����׽��֣����߷���������������Ϣ���������С���Լ�ȷ�Ϸ������ķ�����Ϣ
public:
	MyClient(char* ip, u_short port, int wait_num);               //��ʼ���ͻ���
	template<typename T> void Send(int type,T temp);       //������Ϣ��������Ϣ��������Ϣ����
};

template<typename T>
inline void MyClient::Send(int type, T temp)
{
	cmd c;
	c.acc = false;
	c.size = sizeof(temp);
	c.type = type;
	command.Send(CLIENT,(char*)&c, sizeof(c), 0);
	command.Receive(CLIENT,(char*)& c, c.size, 0);
	if(c.acc)                                                                                //�յ�ȷ����Ϣ֮��������
		command.Send((char*)&temp, c.size, 0);
}
