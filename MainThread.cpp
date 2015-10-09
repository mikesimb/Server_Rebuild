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
	//���߳�������ʱ��ʼ����������
	startServer();
	//���߳�ѭ���忪ʼ
	while (!Terminated())
	{
	   //��������Ҫ��ѭ��
		char  MainCount[255];
		sprintf_s(MainCount, 200, " ClientCount: %d\n",m_server.getClientCount() );
		//sprintf_s(MainCount, sizeof(18), "ClientCount is %d \n", m_server.getClientCount());
		

		OutputDebugString(MainCount);
		Sleep(10);
	}
	//���߳�ѭ�������
	stopServer();
	 //���߳̽�����ʱ��رշ�����
}

void CMainThread::startServer()
{
	m_server.Initialize();
}

void CMainThread::stopServer()
{
	m_server.Finalize();
}
