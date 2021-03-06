#include "stdafx.h"
#include "MainThread.h"


CMainThread::CMainThread()
{
}


CMainThread::~CMainThread()
{
}

void CMainThread::Execute()
{
	//主线程启动的时候开始启动服务器
	startServer();
	//主线程循环体开始
	while (!Terminated())
	{
	   //这里做主要主循环
		char  MainCount[255];
		sprintf_s(MainCount, 200, " ClientCount: %d\n",m_server.getClientCount() );
		//sprintf_s(MainCount, sizeof(18), "ClientCount is %d \n", m_server.getClientCount());
		

		OutputDebugString(MainCount);
		Sleep(10);
	}
	//主线程循环体结束
	stopServer();
	 //主线程结束的时候关闭服务器
}

void CMainThread::startServer()
{
	m_server.Initialize();
}

void CMainThread::stopServer()
{
	m_server.Finalize();
}
