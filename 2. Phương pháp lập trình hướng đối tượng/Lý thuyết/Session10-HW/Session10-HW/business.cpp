#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <regex>
#include <string>
#include <sstream>
using namespace std;

tuple<bool, int, string, int> getInteger(int left, int right)
{
    bool success = false;
    int errorCode = 0;
    string message = "";
    int data = 0;
    
    string buffer;
    getline(cin, buffer);
    
    if (buffer.length() == 0) {
        success = false;
        errorCode = 1;
        message = "Chuoi khong the de trong";
    } else {
        string pattern = "\\d+";
        
        if (regex_match (buffer, regex(pattern))) {
            data = stoi(buffer);
            
            if (data < left || right < data ) {
                success = false;
                errorCode = 4;
                
                stringstream builder;
                builder << "So nhap vao phai trong doan [" << left << ", " << right << "]";
                message = builder.str();
            } else {
                success = true;
            }
        } else {
            success = false;
            errorCode = 2;
            message = "Dinh dang so khong dung"; // Invalid number format
        }
    } 
    
    auto result = make_tuple(success, errorCode, message, data);
    return result;
}