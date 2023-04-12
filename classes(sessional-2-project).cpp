#include <iostream>
using namespace std;

class User;
class Profile;
class MessageWall;
class Message;
class PublicProfile;
class PrivateProfile;

class User {
protected:
	string username, password;

public: 
	User(string username = "", string password = "") {
		this->username = username;
		this->password = password;
	}

	void login() {
		cout << endl << "Enter user name: ";
		cin >> username;
		cout << endl << "Enter your password: ";
		cin >> password;
	}

	void setUsername(string username) {
		this->username = username;
	}

	string getUsername() {
		return username;
	}

	void setPassword(string password) {
		this->password = password;
	}

	string getUsername() {
		return password;
	}

};

class Profile {

public:
	User user;
	virtual void display() {
        cout << endl << "Account Status: Public Profile";
        cout << endl << "Username: " << user.getUsername();
    }

};

class PrivateProfile: public Profile {
protected:
	string name, email, phone;
	
public:
	void display() {
		cout << endl << "Account Status: Private Profile";
		cout << endl << "Username: ";
		cout << endl << "Name: " << name;
	}

};

int main() {



	return 0;
}