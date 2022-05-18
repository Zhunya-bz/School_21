#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "Webserv.hpp"
#include "Request.hpp"
#include "Response.hpp"

class Container
{
private:
	int				_fd;
	char const 		*pSendStr;

//	std::string 	strSend;

	Request 		_request;
	Response 		_response;
	Server 			_serv_conf; // сервер из парсинга
	listeningSocket _listSock; // тут лежат все сервера с одним ip и port

	int				_chunkStatus;
	int				_readFd;
	int				_writeFd;
	int				_sendRes;
	size_t			_sizeSend;
	size_t			_sizeRemain;
	size_t			_size;
	std::string		_strBuff;

public:

	Container(int iFd, listeningSocket & listSock);
	~Container(){};

	Container(const Container &src);
	Container &operator=(const Container &rhs);

	void				setChunkStatus(int chunk) {_chunkStatus = chunk;}
	void				setReadFd(int readFd) {_readFd = readFd;}
	void				setWriteFd(int writeFd) {_writeFd = writeFd;}
	void 				setStrBuf(std::string strBuf) {_strBuff = strBuf;}

	int					getFd() const {return _fd;}
	char const *		getPSendStr() const {return pSendStr;}
	Request				getRequest() const {return _request;}
	Response			getResponse() const {return _response;}
	Server				getServerConf() const {return _serv_conf;}
	listeningSocket		getListSock() const {return _listSock;}
	int					getChunkStatus() const {return _chunkStatus;}
	int					getReadFd() const {return _readFd;}
	int					getWriteFd() const {return _writeFd;}
	int					getSendRes() const {return _sendRes;}
	size_t				getSizeSend() const {return _sizeSend;}
	size_t				getSizeRemain() const {return _sizeRemain;}
	size_t				getSize() const {return _size;}
	std::string			getStrBuff() const {return _strBuff;}

	void parseRequest();

	void prepareResp();

	void sendResp();

};
#endif
