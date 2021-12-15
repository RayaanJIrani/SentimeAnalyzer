//
// Created by Ray Irani on 2/3/21.
//
#include "DSString.h"
#include <cstring>
#include <stdexcept>


    //constructors

    DSString::DSString(){
        data = new char[1];
        data[strlen(data)] = '\0'; //Ensures that data is not nullptr.
    }

    DSString::DSString(const char* input){
        int len = strlen(input);
        data = new char[len + 1]; //This allows for space for the "\0"
        strcpy(data, input);
        data[len] = '\0'; //Ensures that '\0' is added

    }

    DSString::DSString(const DSString& input){
        int len = strlen(input.data);
        data = new char[len + 1]; //This allows space for the "\0"
       strcpy(data,input.data);
        data[len] = '\0'; //Ensures that '\0' is added
    }

    // Destructor
    DSString::~DSString(){
        delete[] data; //deletes the data from the heap
    }

    //overloaded operators

    //asignment operator
    DSString& DSString::operator= (const char* assigner){
        if(data != nullptr){
            delete[] data;
        }
        int len = strlen(assigner);
        data = new char[len + 1]; //allocates data to be the same as assigner.
        strcpy(data,assigner);
        data[len] = '\0';
        return *this;
    }

    DSString& DSString::operator= (const DSString& assigner){
        if(data != nullptr){
            delete[] data;
        }
        int len = strlen(assigner.data);
        data = new char[len + 1]; //This causes a deep copy of the assigner
        strcpy(data, assigner.data);
        data[len] = '\0';
        return *this;
    }

    //appends the values of assigneer data to output
    DSString operator+ (const DSString& str1, const DSString& str2){
        char* new_data;
        if(str1.data != nullptr){
            new_data = str1.data;
        }
        if(str2.data != nullptr){
            new_data = strcat(new_data,str2.data);
        }
        return DSString(new_data);
    }


    //comparison
    bool DSString::operator== (const char* comparee){
        return strcmp(data, comparee) == 0; //The values of two strings are equivalent when strcmp == 0
    }

    bool DSString::operator== (const DSString& comparee){
        if(data == nullptr || comparee.data == nullptr){
            return (data == nullptr && comparee.data == nullptr);
        }
        return strcmp(data,comparee.data) == 0;
    }

    bool DSString::operator!= (const DSString& comparee){
        if(data == nullptr || comparee.data == nullptr){
            return !(data == nullptr && comparee.data == nullptr);
        }
        return strcmp(data,comparee.data) != 0;
    }

    bool DSString::operator< (const DSString& comparee) const{
        return std::strcmp(data,comparee.data) < 0; //returns true if this.data is before comparee.data alphabetically.
    }

    //overloads [] operator allows me to element in a DSString
    char& DSString::operator[] (const int i){
        if(i < strlen(data)) {
            return data[i];
        }
        throw std::out_of_range("Out of Range Exception from [] operator call");
    }

    //public length function
    int DSString::getLength(){
        if(data != nullptr) {
            return strlen(data);
        }
        return 0; //DSStrings with no data in data have length of 0.
    }

    int DSString::find(DSString& substr){
        int sub_str_len = strlen(substr.data);
        int len = strlen(data);
        int len_diff = len - sub_str_len; //finds diffrence between the length of *this and substr
        if( data != nullptr && substr.data != nullptr && len_diff >= 0){ //makes sure that there is data in both places and substring len is longer than
            for(int i = 0; i <= len_diff; ++i){
                if(is_substr(i, substr)){ //is_substr checks if a substr
                    return i;
                }
            }
        }
        return -1;
    }

    //This creates a susbtring the string in question (num chars does not include '\0' which is added at end
    DSString DSString::substring(int start, int numChars){
        if(data == nullptr || numChars == 0){ //checks for edge cases
            return DSString("");
        }
        if(this->getLength() < start+numChars){ //makes sure substr request does not cause a out of range exception
            throw std::out_of_range("Out of Range Exception from substring");
        }
        char new_data [numChars + 1];
        for(int i = 0; i < numChars; ++i){
            new_data[i] = std::tolower(data[i+start]); //all substrings are returned in lowercase
        }
        new_data[numChars] = '\0'; //ensures null-char added at end
        return DSString(new_data);
    }

    //Returns Null terminated string of data
    char* DSString::c_str() const{
        if(data != nullptr){
            return data;
        }
        char* out; // ensures that in an edge case a null char is returned
        out[0] = '\0';
        return out;
    }

    //Prints out string
    std::ostream& operator<< (std::ostream& os, const DSString& str){
        os << str.c_str();
        return os;
    }

    std::vector<DSString> DSString::split(char divider){
    //NOTE: for reasons of Algorithmic efficency this function only returns words with character lengths greater than 3.
        int last_split = 0;
        int len = strlen(data);
        std::vector<DSString> words; //This stores all of the words which have been split
        for(int i = 0; i < len; ++i){
            if(data[i] == divider){ //Notices the divider char
                DSString word = this->substring(last_split,i-last_split); //Creates substring wihtout divider chr
                if(i-last_split > 3) { //Removes words of length <= 3 (As per the recommendation of DR. F)
                    words.push_back(word);
                }
                last_split = i+1;
            }
        }
        if(len-last_split > 3) { //removes words len <= 3.
            DSString word = this->substring(last_split, len - last_split); //DSString from last split to end
            words.push_back(word);
        }
        return words;
    }

    int DSString::strlen(const char* input){
        return std::strlen(input);
    }

    char* DSString::strcpy(char* destination, const char* source){
        return std::strcpy(destination,source);
    }

    int DSString::strcmp(const char* str1, const char* str2 ){
        return std::strcmp(str1,str2);
    }

    char* DSString::strncpy(char* destination, const char* source, int num){
        return std::strncpy(destination,source,num);
    }

    char* DSString::strcat(char* destination, const char* source){
        char* combined = std::strcat(destination,source);
        return combined;
    }

    char* DSString::strncat (char* destination, const char* source, int num ){
        return std::strncat(destination,source,num);
    }

    bool DSString::is_substr(int start, DSString& substr){
        int substr_len = substr.getLength(); //The portion of the string which is being compared is the same as the size of the substr
        for(int i = 0; i < substr_len; ++i) {
            if (substr.data[i] != data[start+i]) { //If any char is different not substr
                return false;
            }
        }
        return true;
    }













