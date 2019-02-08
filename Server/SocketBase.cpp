#include "stdafx.h"

SocketBase::SocketBase()
{
	if (!InitServer())
	{
		std::cout << "Объект класса SocketBase не инициализирован";
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
		std::cout << "Конфиг не был открыт. Файл не найден.";
		file.close();
		return false;
	}
	counter = 0;
	file.close();
	return true;
}