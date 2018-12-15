#include <iostream>
#include <string>

#include "../src/StringExtra.h"

using namespace std;

int main() {
    cout << "--------------- trim ---------------" << endl;
    cout << trim("    Hello World") << endl;
    cout << trim("Hello World    ") << endl;
    cout << trim("    Hello World        ") << endl;
    cout << trim("  Hello World         ") << endl;
    cout << trim("...foo", '.') << endl;

    cout << endl << "Continue ? Press a key"; cin.get();

    cout << "--------------- explode ---------------" << endl;
    for(auto &s : explode("hello world", ' ')) cout << "|" << s << "| "; cout << endl;
    for(auto &s : explode("Lorem ipsum dolor sit amet", ' ')) cout << "|" << s << "| "; cout << endl;
    for(auto &s : explode("# comment line", '#')) cout << "|" << s << "| "; cout << endl;
    for(auto &s : explode("stuff # comment", '#')) cout << "|" << s << "| "; cout << endl;

    cout << endl << "Continue ? Press a key"; cin.get();

    cout << endl << "--------------- trim & explode ---------------" << endl;
    for(auto &s : explode("stuff # comment", '#')) cout << "|" << trim(s) << "| "; cout << endl;

    cout << endl << "Continue ? Press a key"; cin.get();

    cout << endl << "--------------- stof ---------------" << endl;
    cout << stof("13.8") << endl;
    cout << stof(".35") << endl;
    cout << stof("5") << endl;
    cout << stof("2.") << endl;

    return 0;
}