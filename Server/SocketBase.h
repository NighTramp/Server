#pragma once
class SocketBase
{
private:
	int amount;
	int counter;
	Connection* connections;
public:
	void NewConnection();
	bool InitServer();
	SocketBase();
	~SocketBase();
};

