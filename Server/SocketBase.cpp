#include "stdafx.h"

SocketBase::SocketBase()
{
	if (!InitServer())
	{
		std::cout << "������ ������ SocketBase �� ���������������";
	}
	connections = new Connection[amount];
}

SocketBase::~SocketBase()
{
	delete[] connections;
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
			if (tmp == "socket_amount:")
			{
				file >> amount;
			}
			else
			{
				file >> tmp;
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