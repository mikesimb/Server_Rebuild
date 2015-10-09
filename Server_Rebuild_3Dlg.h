
// Server_Rebuild_3Dlg.h : 头文件
//

#pragma once
#include "mainthread.h"

// CServer_Rebuild_3Dlg 对话框
class CServer_Rebuild_3Dlg : public CDialogEx
{
// 构造
public:
	CServer_Rebuild_3Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SERVER_REBUILD_3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
private:
	CMainThread  m_mainthread;

// 实现
protected:
	HICON m_hIcon;




	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
};
