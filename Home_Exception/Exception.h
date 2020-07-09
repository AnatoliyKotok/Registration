#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Exception {
public:
	string massege;

	Exception( const string& massege = "Some error") : massege(massege) {

	}
	const string& what()const {
		return massege;
	}
	
};
class LoginExists:public Exception {
public:
	LoginExists(const string& massege = "Login exists") :Exception(massege) {

	}
};
class PasswordIncorect :public Exception {
public:
	PasswordIncorect(const string& massege = "Pasword incorect") :Exception(massege) {

	}
};
class User {
public:
	User(const string login, const string password) :login(login), password(password) {

	}
	string login;
	string password;
};
class Gamil {
public:
	vector<User>user;
	void setLogin(const string& login) {
		for (size_t i = 0; i < user.size(); i++)
		{
			if (login == user[i].login) {
				throw LoginExists();
			}
			

		}
		
	}
	void setPassword(const string& password) {
		if (password.size() < 8) {
			throw PasswordIncorect("Password contains less than 8 characters");
		}
	}
	void registration(User users) {
		try {
			setLogin(users.login);
			setPassword(users.password);
			cout << "Your login->" << users.login << endl;
			cout << "Your password->" << users.password << endl;
		}
		catch (LoginExists & ex) {
			cout << ex.what() << endl;
		}
		catch (PasswordIncorect & ex) {
			cout << ex.what() << endl;
		}
		user.push_back(users);
	}
};