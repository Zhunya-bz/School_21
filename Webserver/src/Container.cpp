#include "Container.hpp"

Container::Container(int iFd, listeningSocket & listSock) : _fd(iFd), pSendStr(""),  _chunkStatus(notChunk),
											 _readFd(1), _writeFd(0), _sizeSend(5000)
{
	_listSock = listSock;
}

Container::Container(const Container &src)
{
	*this = src;
}

Container &Container::operator=(const Container &rhs)
{
	if (this != &rhs)
	{
		_fd = rhs._fd;
		_chunkStatus = rhs._chunkStatus;
		_readFd = rhs._readFd;
		_writeFd = rhs._writeFd;
		_sizeSend = rhs._sizeSend;
		_sizeRemain = rhs._sizeRemain;
		_strBuff = rhs._strBuff;
		pSendStr = rhs.pSendStr;
		_request = rhs._request;
		_response = rhs._response;
		_serv_conf = rhs._serv_conf;
		_listSock = rhs._listSock;
//			strSend = rhs.strSend;
		_size = rhs._size;
	}
	return *this;
}

void Container::parseRequest()
{
//	std::cout << "Parsed fd " << _fd << std::endl;
	_request.parseRequest(_strBuff, _listSock, _serv_conf);
}

void Container::prepareResp()
{
	_response.prepareResp(_request, _serv_conf);
	_sizeRemain = _response.getResp().size();
	_size = _response.getResp().size();

}

void Container::sendResp()
{
	if (_sizeRemain < _sizeSend)
	{
		_sizeSend = _sizeRemain;
	}
	_sendRes = send(_fd, reinterpret_cast<char *>(&_response.getResp()[_size - _sizeRemain]), _sizeSend, 0);

	if (_sendRes < 0)
	{
		std::cout << strerror(errno) << std::endl;
		_sizeRemain = 0;
		return;
	}
	pSendStr += _sendRes;
	_sizeRemain -= _sendRes;
}