#include <iostream>
#include <string>
using namespace std;

int main()
{
    string in;

    while (getline(cin, in))
    {
        // Get name substr
        size_t nameOffset = 11;
        size_t andOffset = in.find(" and", nameOffset);
        string name = in.substr(nameOffset, andOffset - nameOffset);

        // Get age substr
        size_t ageOffset = in.find("I am") + 5;
        size_t yearsOffset = in.find(" years");
        string ageStr = in.substr(ageOffset, yearsOffset - ageOffset);

        // Convert age to int
        int age = stoi(ageStr);
        int ageDiff = age / 10; // How many years younger you look

        cout << name << ", you look younger. I thought you were " << age - ageDiff << " years old." << endl;
    }

    return 0;
}
