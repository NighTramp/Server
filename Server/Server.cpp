// Server.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"


int main()
{
	setlocale(LC_ALL, "Russian_Russia.1251");//��������� ��������� ��� ������ �������� ����� 
	
											 //WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SocketBase Base;
	
	system("pause");
    return 0;
}

