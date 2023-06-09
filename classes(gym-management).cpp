#include <iostream>
using namespace std;

static int userCount = 0;
static int trainerCount = 0;

void validateCnic(string &cnic) {
    while (cnic.length() != 13) {
        cout << "Invalid CNIC! Enter again: ";
        cin >> cnic;
    }
}

class Equipment {};

class User {
    private:
    string id, name, password, gender;
    User* u;
    int numberOfUsers;
    bool status;

    public:
    User(string id = "N/A", string name = "N/A", string password = "N/A", string gender = "N/A", bool status = false) {
        this->id = id;
        this->name = name;
        this->password = password;
        this->gender = gender;
        this->status = status;
        numberOfUsers = 0;
        u = new User[numberOfUsers];
    }

    void Register() {
        string id, name, password, gender;
        cout << endl << "Enter your name: ";
        cin >> name;
        cout << endl << "Set your password: ";
        cin >> password;
        cout << endl << "Enter your gender: ";
        cin >> gender;
        
        numberOfUsers++;
        User* temp = new User[numberOfUsers];
        for (int i = 0; i < numberOfUsers - 1; i++) {
            temp[i] = this->u[i];
        }
        userCount++;
        id = to_string(userCount);
        temp[numberOfUsers - 1] = User(id, name, password, gender, true);
        delete[] u;
        u = temp;
    }

    bool Login() {
        string name, password;
        cout << endl << "Enter your name: ";
        cin >> name;
        cout << endl << "Enter your password: ";
        cin >> password;

        for (int i = 0; i < numberOfUsers; i++) {
            if (u[i].name == name && u[i].password == password) {
                return true;
            }
        }

        return false;
    }

    void Edit() {
        cout << endl << "Enter your  name: ";
        string temp_name;
        cin >> temp_name;
        cout << endl << "Enter your password: ";
        string temp_password;
        cin >> temp_password;

        for (int i = 0; i < numberOfUsers; i++) {
            if (temp_name == u[i].name && temp_password == u[i].password) 
            {
                cout << "Enter you new password: ";
                cin >> temp_password;
                u[i].setPassword(temp_password);
                return;
            }
        }

        cout << "Error! User not found" << endl;
    }

    //getters and setters

    string getId() {
        return id;
    }

    void setId(string id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setPassword(string password) {
        this->password = password;
    }

    string getPassword() {
        return password;
    }

    string getGender() {
        return gender;
    }

    void setGender(string gender) {
        this->gender = gender;
    }

    void setStatus(bool status) {
        this->status = status;
    }

    bool getStatus() {
        return status;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
        cout << "Gender: " << gender << endl;
        cout << "Status: " << status << endl;
    }

    friend ostream& operator<<(ostream& out, const User u) {
        out << "ID: " << u.id << endl;
        out << "Name: " << u.name << endl;
        out << "Password: " << u.password << endl;
        out << "Gender: " << u.gender << endl;
        out << "Status: " << u.status << endl;

        return out;
    }

    void view() {
        for (int i = 0; i < numberOfUsers; i++) {
            u[i].display();
        }
    }

};

class Admin {
    private:
        string username, password;
        Admin *a;
        int numberOfAdmins = 0;
    public:
        Admin(string username = "N/A", string password = "N/A") {
            this->username = username;
            this->password = password;
            numberOfAdmins = 0;
            a = new Admin[numberOfAdmins];
        }

        bool login() {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            for (int i = 0; i < numberOfAdmins; i++) {
                if (a[i].username == username && a[i].password == password) {
                    return true;
                }
            }

            return false;
        }

        void add(Admin a) {
            numberOfAdmins++;
            Admin *temp = new Admin[numberOfAdmins];
            for (int i = 0; i < numberOfAdmins - 1; i++) {
                temp[i] = this->a[i];
            }
            temp[numberOfAdmins - 1] = a;
            delete [] this->a;
            this->a = temp;
            cout << "Admin added successfully!" << endl;
        }

        void update(Admin a) {
            for (int i = 0; i < numberOfAdmins; i++) {
                if (this->a[i].username == a.getUsername()) {
                    this->a[i] = a;
                    cout << "Admin updated successfully!" << endl;
                    return;
                }
            }
            cout << "Admin not found!" << endl;
        }

        void deleteUser(Admin a) {
            for (int i = 0; i < numberOfAdmins; i++) {
                if (this->a[i].username == a.getUsername()) {
                    for (int j = i; j < numberOfAdmins - 1; j++) {
                        this->a[j] = this->a[j + 1];
                    }
                    numberOfAdmins--;
                    cout << "Admin deleted successfully!" << endl;
                    return;
                }
            }
        }

        //getter and setters

        string getUsername() {
            return username;
        }

        void setUsername(string username) {
            this->username = username;
        }

        string getPassword() {
            return password;
        }

        void setPassword(string password) {
            this->password = password;
        }

        void display() {
            cout << "Username: " << username << endl;
            cout << "Password: " << password << endl;
        }

        friend ostream& operator<<(ostream& out, Admin& a) {
            for (int i = 0; i < a.numberOfAdmins; i++) {
                cout << endl << "Admin " << i + 1 << endl;
                a.a[i].display();
            }

            return out;
        }
};

class Trainer {
    private:
    string id, name, password, cnic;
    int age, numberOfTrainers ;
    Trainer* t;

    public:
    Trainer(string id = "N/A", string name = "N/A", string password = "N/A", string cnic = "N/A", int age = 0) {
        this->id = id;
        this->name = name;
        this->password = password;
        this->cnic = cnic;
        this->age = age;
        numberOfTrainers = 0;
        t = new Trainer[numberOfTrainers];
    }

    // getters and setters

    void Register() {

        cout << endl << "Enter your cnic: ";
        cin >> cnic;
        validateCnic(cnic);
        cout << endl << "Enter your name: ";
        cin >> name;
        cout << endl << "Set your password: ";
        cin >> password;
        cout << endl << "Enter your age: ";
        cin >> age;

        numberOfTrainers++;
        trainerCount++;
        Trainer* temp = new Trainer[numberOfTrainers];
        for (int i = 0; i < numberOfTrainers - 1; i++) {
            temp[i] = this->t[i];
        }
        temp[numberOfTrainers - 1] = Trainer(to_string(trainerCount), name, password, cnic, age);
        delete [] this->t;
        this->t = temp;
        cout << "Trainer added successfully!" << endl;
    }

    bool Login() {
        cout << "Enter your cnic: ";
        cin >> cnic;
        cout << "Enter your password: ";
        cin >> password;

        for (int i = 0; i < numberOfTrainers; i++) {
            if (t[i].cnic == cnic && t[i].password == password) {
                return true;
            }
        }

        return false;
    }

    void getEquipment();

    string getId() {
        return id;
    }

    void setId(string id) {
        this->id = id;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getCnic() {
        return cnic;
    }

    void setCnic(string cnic) {
        this->cnic = cnic;
    }

    int getAge() {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }
};

int main() {

    User u;
    Admin* a = new Admin("Regan", "Pa(rg@153x");
    cout << "Hello World";
    for (int i = 0; i < 3; i++) {
        u.Register();
    }
    u.view();


    return 0;
}