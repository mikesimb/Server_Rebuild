#pragma once
#include "ZQThread.h"
#include "MessageServer.h"
class CMainThread :
	public CZQThread
{
public:
	CMainThread();
	virtual ~CMainThread();

	void SetMainWindowHwnd(HWND value){ value = m_MainWnd; };
	HWND getMainWindowHwnd(){return m_MainWnd; };
protected:
	virtual void Execute();
private:
	void startServer();
	void stopServer();
	HWND   m_MainWnd;
	CMessageServer  m_server;

};

