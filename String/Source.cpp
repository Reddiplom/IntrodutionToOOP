#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
//#define CONSTRUCTORS_CHECK

using namespace std;

class String {
    char* data;
    size_t length;

public:
    // Конструкторы
    String() {
        this->data = nullptr;
        this->length = 0;
        data = new char[1];
        data[0] = '\0';
        cout << "DefaultConstructor:\t" << this << endl;
    }
    String(const char* str) {
        if (str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        }
        else {
            data = new char[1];
            data[0] = '\0';
            length = 0;
        }
        cout << "Constructor:\t\t" << this << endl;
    }
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
        cout << "CopyConstructor:\t" << this << endl;
    }

    ~String() {
        delete[] data;
        cout << "Destructor:\t\t" << this << endl;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        cout << "CopyAssignment:\t\t" << this << endl;
        return *this;
    }

    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        delete[] result.data;
        result.data = new char[result.length + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }
    friend ostream& operator<<(ostream& os, const String& str) {
        os << str.data;
        return os;
    }
    size_t get_length() const { return length; }
    const char* c_str() const { return data; }
};
void main()
{
#ifdef CONSTRUCTORS_CHECK
    String str1 = "String";
    String str2 = "Hello";

    String str3 = str2;
#endif // CONSTRUCTORS_CHECK

    String str1 = "Hello";
    String str2 = "World";
    String str3;
    str3 = str1 + str2; 
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
}