#include "stdafx.h"
#include "MessageServer.h"
#include "MessageClient.h"


CMessageServer::CMessageServer()
{
}


CMessageServer::~CMessageServer()
{
}

void CMessageServer::Initialize()
{
	CZQCustomIOCPServer::Initialize();
	m_CreateSocketClient = std::bind(&CMessageServer::OnCreateClient, this);
}

CZQCustomClient * CMessageServer::OnCreateClient()
{
	return new CMessageClient();
}
