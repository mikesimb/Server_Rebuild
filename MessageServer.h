#pragma once
#include "ZQCustomIOCPServer.h"

//ͨ�����ݰ�����
typedef struct _Default_Message_tag
{
	DWORD  sign;//�����һ�����ı�־
	byte         Version;
	byte        cmd; //δ������
	WORD    DataLength; //�����һ���������ݳ���
	DWORD  DataIndex;//���Ӧ����һ��������

}DefaultMessage,*pDefaultMessage;


typedef  struct __Client_Message_tag
{
	DWORD  Handle; //����ǿͻ��˵Ĵ���
	DWORD  MsgID; //���������ϢID
	DWORD wParam; //��Ϣ����
	DWORD  lParam;//��Ϣ����

}DefaultClientMessge,*pDefaultClientMessage;

class CMessageServer :
	public CZQCustomIOCPServer
{
public:
	CMessageServer();
	virtual ~CMessageServer();
	virtual void Initialize();
	virtual CZQCustomClient *  OnCreateClient();
private:


protected:
};

