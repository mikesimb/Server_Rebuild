
// Server_Rebuild_3.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CServer_Rebuild_3App: 
// �йش����ʵ�֣������ Server_Rebuild_3.cpp
//

class CServer_Rebuild_3App : public CWinApp
{
public:
	CServer_Rebuild_3App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CServer_Rebuild_3App theApp;