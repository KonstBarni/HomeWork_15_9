#pragma once
#include <string>

using namespace std;

class User
{
	const string login_;
	string password_;
	string name_;
	bool admin_;

public:
	User(const string& login, const string& password, const string& name, bool admin)
		: login_(login), password_(password), name_(name), admin_(admin) {}

	const string& getUserLogin() const { return login_; }					//getters
	const string& getUserPassword() const { return password_; }
	const string& getUserName() const { return name_; }
	bool getAdmin() {return admin_;}

	void setUserPassword(const string& password) { password_ = password; }	//setters
	void setUserName(const string& name) { name_ = name; }

};