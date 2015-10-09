#pragma once
#include "ZQCustomIOCPServer.h"

//通用数据包定义
typedef struct _Default_Message_tag
{
	DWORD  sign;//这个是一个包的标志
	byte         Version;
	byte        cmd; //未来增加
	WORD    DataLength; //这个是一个包的数据长度
	DWORD  DataIndex;//这个应该是一个包序列

}DefaultMessage,*pDefaultMessage;


typedef  struct __Client_Message_tag
{
	DWORD  Handle; //这个是客户端的代码
	DWORD  MsgID; //这个代表消息ID
	DWORD wParam; //消息参数
	DWORD  lParam;//消息参数

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

