#include "stdafx.h"

SocketBase::SocketBase()
{
	if (!InitServer())
	{
		std::cout << "������ ������ SocketBase �� ���������������";
	}
	Connections = new SOCKET[amount];
}

SocketBase::~SocketBase()
{
	delete[] Connections;
}

void SocketBase::NewConnection()
{

}

bool SocketBase::InitServer()
{
	//��������� ������ �� ������
	std::fstream file(L"config.txt", std::ios::in);
	//��������� �������� ��
	if (file.is_open())
	{
		std::cout << "������ ������ �������." << std::endl;
		//������ �� ����� � �������������� ���� ������ SocketBase
		std::string tmp;
		while (!file.eof())
		{
			file >> tmp;	//������ �������� ���������� �� �������
			if (tmp == "server_ip:")
			{
				file >> ip;
			}
			else if (tmp == "server_port:")
			{
				file >> port;
			}
			else if (tmp == "socket_amount:")
			{
				file >> amount;
			}
		}
	}
	else
	{
		std::cout << "������ �� ��� ������. ���� �� ������.";
		file.close();
		return false;
	}
	counter = 0;
	file.close();
	return true;
}