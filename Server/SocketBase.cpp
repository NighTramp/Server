#include "stdafx.h"

SocketBase::SocketBase()
{
	if (!InitServer())
	{
		std::cout << "Объект класса SocketBase не инициализирован";
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
	//открываем конфиг на чтение
	std::fstream file(L"config.txt", std::ios::in);
	//проверяем открылся ли
	if (file.is_open())
	{
		std::cout << "Конфиг открыт успешно." << std::endl;
		//читаем из файла и инициализируем поля класса SocketBase
		std::string tmp;
		while (!file.eof())
		{
			file >> tmp;	//Читаем название переменной из конфига
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
		std::cout << "Конфиг не был открыт. Файл не найден.";
		file.close();
		return false;
	}
	counter = 0;
	file.close();
	return true;
}