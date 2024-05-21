#include "pch.h"
#include "CKernelSock.h"

CKernelSock::CKernelSock()
{
}

CKernelSock::~CKernelSock()
{
}

bool CKernelSock::Startup()
{
	WSADATA wsa;
	int ret=WSAStartup(MAKEWORD(2, 2), &wsa);
	if (ret != 0) 
	{
		return false;
	}
	return TRUE;
}

BOOL CKernelSock::CreateSocket()
{ 
	m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_sock == INVALID_SOCKET) 
	{
		return FALSE;
	}
	return TRUE;
}

BOOL CKernelSock::BindSocket()
{
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	int ret = bind(m_sock, (sockaddr*)&addr, sizeof(addr));
	if (ret == SOCKET_ERROR) 
	{
		return FALSE;
	}
	return TRUE;
}

BOOL CKernelSock::ListenSocket()
{
	int ret = listen(m_sock, SOMAXCONN);
	if (ret == SOCKET_ERROR) 
	{
		return FALSE;
	}
	return TRUE
	return 0;
}
