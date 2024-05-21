#pragma once
class CKernelSock
{
public:
	CKernelSock();
	~CKernelSock();
public:
	bool Startup();
	BOOL CreateSocket();
	BOOL BindSocket();
	BOOL ListenSocket();


	SOCKET m_sock;
	SOCKET AcceptSocket(SOCKADDR_IN)
};

