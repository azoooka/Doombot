#pragma once

#include <WinSock2.h>
#include <queue>
#include <iostream>

#include "Compressor.h"
#include "MsgChannel.h"

using namespace std;
class Proxy
{
public:
	Proxy();
	~Proxy();

	void EstablishConnection();
	void HandleMessag();


private:
	// Help methods
	void ChallangeServer();

	// Member variables
	SOCKET m_socket;
	sockaddr_in m_recieveAddress;

	int m_clientId;
	int m_clientChecksum;
	int m_messageSequence;

	int m_deltaTime;
	int m_frame;

	idCompressor* m_compressor;
	idMsgChannel m_msgChannel;

	WSADATA m_wsadata;

	std::queue<idBitMsg> m_messageQueue;
};
