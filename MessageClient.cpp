#include "stdafx.h"
#include "MessageClient.h"
#include "MessageServer.h"
#include "Protocol.h"


CMessageClient::CMessageClient()
{
	m_iReviceBufferLen = 0;


}

CMessageClient::~CMessageClient()
{

	CZQCustomClient::~CZQCustomClient();

}

void CMessageClient::SocketRead(pBlock data, int buflen)
{
	//CZQCustomClient::SocketRead(data, buflen);
	if (buflen + m_iReviceBufferLen > MAX_REVICE_LEN)
	{
		OutputDebugString("封包超长！！！");
	}
	memset(m_ReviceBuffer, 0, MAX_REVICE_LEN);
	int ilen = 0;
	if (buflen > MAX_REVICE_LEN)
		ilen = MAX_REVICE_LEN;
	else
		ilen = buflen;
	memmove_s((char* )(m_ReviceBuffer + m_iReviceBufferLen), MAX_REVICE_LEN, data->MsgBuf, ilen);
	m_iReviceBufferLen += buflen;
	int ioffset = 0;
	int doffset = 0;
	int len = sizeof(DefaultMessage);
	while ((m_iReviceBufferLen - ioffset) >= len)
	{
		DefaultMessage * pDM = pDefaultMessage(m_ReviceBuffer);
		if (pDM->sign == SEGAMENTATION_IDENT)
		{
			int PackageLen = sizeof(DefaultMessage)+pDM->DataLength;
			if (PackageLen > MAX_REVICE_LEN)
			{
				OutputDebugString("超长的封包");
				break;
			}
			if (PackageLen + ioffset >= MAX_REVICE_LEN)
				break;
			switch (pDM->cmd)
			{
			case Msg_Cmd_NormalData:	
				doffset = sizeof(DefaultMessage) + ioffset;
				ProcClientMessage(&m_ReviceBuffer[doffset], pDM->DataLength);
				break;
			default:
				break;
			}
			ioffset += PackageLen;
		}
		else
			ioffset++;
	}
	m_iReviceBufferLen -= ioffset;
	if (m_iReviceBufferLen > 0)
		memmove_s(&m_ReviceBuffer[0], m_iReviceBufferLen, &m_ReviceBuffer[ioffset], m_iReviceBufferLen);
	else
			m_iReviceBufferLen = 0;
}

void CMessageClient::ProcClientMessage(char * buffer, int buflen)
{
	//到这里要把他搞成内部协议了
	pDefaultClientMessage pdcm = (pDefaultClientMessage)buffer;
	switch (pdcm->MsgID)
	{
	case SM_PING:
		SetAcitveTick( GetTickCount());
		break;
	case SM_Login:
		OutputDebugString("收到了login消息");
		break;
	default:
		break;
	}
	
}

void   CMessageClient::MakeDefaultMessage(char * sbuffer , int sbuflen,char*& dbuffer, int& dBuflen)
{

	char * buffer = (char *)malloc(sizeof(DefaultMessage)+sbuflen);
	pDefaultMessage msg = new DefaultMessage();
	msg->sign = 0xF4F4F4F4;
	msg->cmd = Msg_Cmd_NormalData;
	msg->DataIndex = 0;
	msg->Version = 0;
	msg->DataLength = sizeof(DefaultMessage);
	dBuflen = sizeof(DefaultMessage);
	memcpy_s(buffer, dBuflen, msg, dBuflen);
	dBuflen += sbuflen;
	memcpy_s((char *)(buffer + sizeof(DefaultMessage)), sbuflen, buffer, sbuflen);
	//这里的NEW操作的释放是需要放到外边释放的，外边释放是使用free来释放
	dbuffer = buffer;
	//free(buffer);

}

void CMessageClient::MakeClientDefalutMesssage(DWORD MsgID, DWORD wParam, DWORD lParam)
{
	DefaultClientMessge dcm;
	dcm.Handle = getsocket();
	dcm.MsgID = MsgID;
	dcm.wParam = wParam;
	dcm.lParam = lParam;
	int buflen = 0;
	char * buf = NULL;
	MakeDefaultMessage((char*)&dcm, sizeof(dcm), buf, buflen);
	SendBuffer(buf, buflen);
	free(buf);

}
