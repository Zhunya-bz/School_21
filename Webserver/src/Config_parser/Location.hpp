#ifndef WEBSERV_LOCATION_HPP
#define WEBSERV_LOCATION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Location
{
private:
	std::string 				_path;
	std::string 				_root;
	std::vector<std::string> 	_methods;
	std::string 				_index;
	bool 						_autoindex;
	std::string					_upload_route;
	std::string 				_redirect;
	bool 						_isGeneral;
	std::string 				_cgi_path;

public:
	Location() : _path(""), _root(""), _index(""), _autoindex(false), _isGeneral(false){};
	~Location(){};

	Location(const Location &src)
	{
		*this = src;
		return;
	};
	Location &operator=(const Location &rhs)
	{
		if (this != &rhs)
		{
			_path = rhs._path;
			_root = rhs._root;
			_methods = rhs._methods;
			_index = rhs._index;
			_autoindex = rhs._autoindex;
			_upload_route = rhs._upload_route;
			_redirect = rhs._redirect;
			_isGeneral = rhs._isGeneral;
			_cgi_path = rhs._cgi_path;
		}
		return *this;
	};

	void setPath(std::string path) { _path = path; };
	void setRoot(std::string root) { _root = root; };
	void setMethods(std::vector<std::string> methods) { _methods = methods; };
	void setIndex(std::string index) { _index = index; }
	void setAutoIndex(bool autoindex) { _autoindex = autoindex; };
	void setUploadRoute(std::string upload_route) { _upload_route = upload_route; };
	void setRedirect(std::string redirect) { _redirect = redirect; };
	void setIsGeneral(bool isGeneral) { _isGeneral = isGeneral; };
	void setCGI(std::string cgi_path) { _cgi_path = cgi_path; };

	std::string getPath() const { return (_path); };
	std::string getRoot() { return (_root); };
	std::vector<std::string> getMethods() { return (_methods); };
	std::string getIndex() { return (_index); }
	bool getAutoIndex() { return (_autoindex); };
	std::string getUploadRoute() { return (_upload_route); };
	std::string getRedirect() { return (_redirect); };
	bool getIsGeneral() { return (_isGeneral); };
	std::string getCGI() { return (_cgi_path); };
};

#endif //WEBSERV_LOCATION_HPP