#include"MySocket.h"
MySocket::MySocket()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	s = socket(AF_INET, SOCK_STREAM, 0);
	remote = socket(AF_INET, SOCK_STREAM, 0);
	if (SOCKET_ERROR == s) {
		cout << "�׽��ִ�����ʧ��!" << endl;
	}
	else {
		cout << "�׽��ִ����ɹ�!" << endl;
	}
}

void MySocket::Bind(u_short port)
{
	sockaddr_in socketAddr;  //һ���󶨵�ַ:��IP��ַ,�ж˿ں�,��Э����
	socketAddr.sin_family = AF_INET;
	socketAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	socketAddr.sin_port = htons(port);
	int bRes = bind(s, (SOCKADDR*)&socketAddr, sizeof(SOCKADDR));	//��ע���һ����Ǽǵ�ǿ������ת��
	if (SOCKET_ERROR == bRes) {
		cout << "��ʧ��!" << endl;
	}
	else {
		cout << "�󶨳ɹ�!" << endl;
	}
}

void MySocket::Listen(int num)
{
	int lLen = listen(s, num);	//�����ĵڶ�����������:�ܴ�Ŷ��ٸ��ͻ�������,��������̵�ʱ�������Ŷ
	if (SOCKET_ERROR == lLen) {
		cout << "����ʧ��!" << endl;
	}
	else {
		cout << "�����ɹ�!" << endl;
	}
}

void MySocket::Accept()
{
	sockaddr_in revClientAddr;
	remote = INVALID_SOCKET;	//��ʼ��һ�����ܵĿͻ���socket
	int _revSize = sizeof(sockaddr_in);
	remote = accept(s, (SOCKADDR*)&revClientAddr, &_revSize);
	if (INVALID_SOCKET == remote) {
		cout << "����˽�������ʧ��!" << endl;
	}
	else {
		cout << "����˽�������ɹ�!" << endl;
	}
}

void MySocket::Receive(int c_s, char* buf, unsigned int size, int flag)
{
	if (c_s == CLIENT)
		remote = s;
	int reLen = recv(remote, buf, size, flag);
	if (SOCKET_ERROR == reLen) {
		cout << "����˽�������ʧ��" << endl;
	}
	else {
		cout << "���������ܵ�����:    " << endl;
	}
}

void MySocket::Send(int c_s, char* buf, unsigned int size, int flag)
{
	if (c_s == CLIENT)
		remote = s;
	int sLen = send(remote, buf, size, flag);
	if (SOCKET_ERROR == sLen) {
		cout << "��������ʧ��" << endl;
	}
	else {
		cout << "�Ѿ����͵�����:    " << endl;
	}
}
void MySocket::Connect(char* ip, u_short port)
{
	sockaddr_in addrSrv;
	s = socket(AF_INET, SOCK_STREAM, 0);                    
	addrSrv.sin_addr.S_un.S_addr = inet_addr("ip");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(port);
	connect(s, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
}

void MySocket::Serstart(u_short port, int wait_num)
{
	Bind(port);
	Listen(wait_num);
	Accept();
}


