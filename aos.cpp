#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int SIZE = 1000;

struct User {
      string FirstName;
      string SecondName;
      string Password;
      string Email;
      string Gender;
      int Year;
};

string* createUser(string& data) {
    stringstream ssin(data);
    string* arr = new string[6];
    int i = 0;

    while (ssin.good() && i < 6){
        ssin >> arr[i];
        ++i;
    }

    return arr;
};

User* findUser(User* data, string email) {
    for (int i = 0; i <= SIZE; i ++) {
        string userEmail = data[i].Email;
        int comparsion = email.compare(userEmail);

        if (comparsion == 0) {
            return &data[i];
        }
    }

    return nullptr;
}

int main() {
    ifstream infile("users.txt");
    string line;
    User *Users = new User[SIZE];
    int i = 0;

    while (getline(infile, line)) {
        string* data = createUser(line);

        Users[i].FirstName = data[0];
        Users[i].SecondName = data[1];
        Users[i].Password = data[2];
        Users[i].Email = data[3];
        Users[i].Gender = data[4];
        Users[i].Year = atoi(data[5].c_str());
        i++;
    }

    User* neededUser = findUser(Users, "GilbertosintManriquez@somemail.ru");

    cout << neededUser -> Password << neededUser -> FirstName << endl;

    return 0;
}