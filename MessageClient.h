#pragma once
#include "ZQCustomClient.h"

#define MAX_REVICE_LEN   256
#define SEGAMENTATION_IDENT 0xF4F4F4F4
#define Msg_Cmd_NormalData   0
class CMessageClient :
	public CZQCustomClient
{
public:
	CMessageClient();
	virtual ~CMessageClient();
	
	virtual void SocketRead(pBlock data, int buflen);
	void ProcClientMessage(char * buffer,int buflen);
	void  MakeDefaultMessage(char * sbuffer, int sbuflen, char*&  dbuffer, int& dBuflen);
	void  MakeClientDefalutMesssage(DWORD MsgID, DWORD wParam, DWORD lParam);
	//virtual CZQCustomClient* OnCreateClient() =0;

protected:
	



private:
	int m_iReviceBufferLen;
	char  m_ReviceBuffer[MAX_REVICE_LEN];


};

