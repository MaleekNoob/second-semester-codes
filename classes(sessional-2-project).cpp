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

class Profile: public User {
protected:
	User user;

public:
	virtual void func() = 0;

	virtual void display() {
		cout << "\nUsername: " << user.getUsername();
	}

};

class PrivateProfile: public Profile {
protected:
	string name, email;
	Profile* p;
	
public:
	PrivateProfile(string name = "", string email = "") {
		this->name = name;
		this->email = email;
	}

	void display() {
		cout << endl << "Account Status: Private Profile";
		cout << endl << "Username: " << p->getUsername();
		cout << endl << "Name: " << name;
		cout << endl << "Email: " << email;
	}

};

class PublicProfile {
protected:
	string contactInfo, interest;
	Profile* p;

public:
	PublicProfile(string contactInfo = "", string interest = "", Profile* p = nullptr) {
		this->contactInfo = contactInfo;
		this->interest = interest;
		this->p = p;
	}

	void display() {
		cout << endl << "Account Status: Public Profile";
		cout << endl << "Username: " << p->getUsername();
		cout << endl << "ContactInfo: " << contactInfo;
		cout << endl << "Interest: " << interest;
	}
};

class MessageWall {
protected:
	User user;

public:
	void addMessage() {
		cout << endl << "Add a message: ";
	}

	void removeMessage();
};

class Message {
	User sender, reciever;
	int timestamp;
	MessageWall* message_wall;

public:
	void post() {
		
	}
};

int main() {



	return 0;
}