#pragma once
class SocketBase
{
private:
	int amount;
	int counter;
	std::string ip;
	std::string port;
	SOCKET* Connections;
public:
	void NewConnection();
	bool InitServer();
	SocketBase();
	~SocketBase();
};

