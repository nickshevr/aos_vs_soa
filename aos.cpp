#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int SIZE = 100000;

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
    vector<string> searchingEmails;
    int i = 0;

    while (getline(infile, line)) {
        string* data = createUser(line);

        if (i % 100 == 0) {
            searchingEmails.push_back(data[3]);
        }

        Users[i].FirstName = data[0];
        Users[i].SecondName = data[1];
        Users[i].Password = data[2];
        Users[i].Email = data[3];
        Users[i].Gender = data[4];
        Users[i].Year = atoi(data[5].c_str());
        i++;
    }

    while (!searchingEmails.empty()) {
        string email = searchingEmails.back();
        searchingEmails.pop_back();

        User *neededUser = findUser(Users, email);

        cout << neededUser->Password  << endl;
    }

    return 0;
}