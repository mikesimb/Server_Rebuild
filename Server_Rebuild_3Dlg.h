
// Server_Rebuild_3Dlg.h : ͷ�ļ�
//

#pragma once
#include "mainthread.h"

// CServer_Rebuild_3Dlg �Ի���
class CServer_Rebuild_3Dlg : public CDialogEx
{
// ����
public:
	CServer_Rebuild_3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SERVER_REBUILD_3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
private:
	CMainThread  m_mainthread;

// ʵ��
protected:
	HICON m_hIcon;




	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
};
