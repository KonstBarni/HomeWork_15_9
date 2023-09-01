#pragma once
#include <vector>
#include <exception>
#include <memory>
#include "Massage.h"
#include "hash_table/CloseHT.h"

using namespace std;

struct UserLoginExp : public exception		//исключение ошибки логина
{
	const char* what() const noexcept override { return "error: user login is busy"; }
};

struct UserNameExp : public exception		//исключение ошибки имени юзера
{
	const char* what() const noexcept override { return "error: user name is busy"; }
};

class Chat
{
	bool isChatWork_ = false;						//маркер работы чата
	vector<User> users_;							//вектор юзеров
	vector<Message>messages_;						//вектор сообщений
	shared_ptr<User> currentUser_ = nullptr;		//указатель активного пользователя
	HashTable hashPass_;

	void login();							//логин
	void registration();					//регистрация
	void showChat() const;					//показать чат
	void showAllUsersName() const;			//показать всех пользователей
	void addMessage();						//добавить сообщение
	void dellMessage();						//удалить сообщение

	vector<User>& getAllUsers() { return users_; }					//возвращает всех пользователей
	vector<Message>& getAllMessages() { return messages_; }			//возвращает сообщения
	shared_ptr<User> getUserByLogin(const string& login) const;		//возвращает пользователя по логину
	shared_ptr<User> getUserByName(const string& name) const;		//возвращает пользователя по имени

public:

	bool isChatWork() const { return isChatWork_; }				//маркер работы чата
	void start();												//старт чата
	void showLoginMenu();										//меню логина/регистрации
	void showUserMenu();										//меню пользователя
	shared_ptr<User> getCurrentUser() const { return currentUser_; }	//возвращает активного пользователя
};