#pragma once
class Connection
{
private:
	std::string ip;
	std::string port;
	SOCKET connection;
public:
	Connection();
	~Connection();
};

