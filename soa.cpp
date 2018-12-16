#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int SIZE = 100000;

struct Users {
      string FirstName[100000];
      string SecondName[100000];
      string Password[100000];
      string Email[100000];
      string Gender[100000];
      int Year[100000];
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

string* findUserPassword(Users* data, string email) {
    for (int i = 0; i <= SIZE; i ++) {
        string userEmail = data->Email[i];
        int comparsion = email.compare(userEmail);

        if (comparsion == 0) {
            return &data->Password[i];
        }
    }

    return nullptr;
}

int main() {
    ifstream infile("users.txt");
    string line;
    Users *users = new Users();
    vector<string> searchingEmails;
    int i = 0;

    while (getline(infile, line)) {
        string* data = createUser(line);

        if (i % 100 == 0) {
            searchingEmails.push_back(data[3]);
        }

        users -> FirstName[i] = data[0];
        users -> SecondName[i] = data[1];
        users -> Password[i] = data[2];
        users -> Email[i] = data[3];
        users -> Gender[i] = data[4];
        users -> Year[i] = atoi(data[5].c_str());
        i++;
    }

    while (!searchingEmails.empty()) {
        string email = searchingEmails.back();
        searchingEmails.pop_back();

        string* userPassword = findUserPassword(users, email);

        cout << *userPassword << endl;
    }

    return 0;
}