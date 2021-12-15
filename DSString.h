#ifndef STRING
#define STRING
#pragma once

#include <iostream>
#include <cstring>
#include <vector>

class DSString{

    private:

        char* data; //stores the c-string

        int strlen(const char* input); //returns the length of the c-string

        char* strcpy(char* destination, const char* source); //copies data into new char* until '\0' reached

        int strcmp(const char* str1, const char* str2 ); //compares two strings. Returns - value if str1 smaller etc.

        char* strncpy(char* destination, const char* source, int num); //Partially copies the string

        char* strcat(char* destination, const char* source); //concaintates the source code at the back of he destination code

        char * strncat (char* destination, const char* source, int num ); //partially concatonates the destiniation with the source

        bool is_substr(int start, DSString& substr); //Helper function of find. Are the next n digits from start of *this the same as substr


    public:

       //Constructors / Destructor

        DSString(); //default constructor sets value of data to "\0"

        DSString(const char* input); //Takes *char and generates DSString

        DSString(const DSString& input); //Copy Constructor

        ~DSString(); //Destructor -- deallocates data

        //overloaded operators

        DSString& operator= (const char* assigner); //An assignment operator -- Allows for the creation of DSStrings using char*

        DSString& operator= (const DSString& assigner); //Assignment operator

        friend  DSString operator+ (const DSString& str1, const DSString& str2); //'+' operator not '+='

        bool operator== (const char* comparee); //Comparison Operator against char*

        bool operator== (const DSString& comparee); //Comparison Operator for DSStrings

        bool operator!= (const DSString& comparee);

        bool operator< (const DSString& comparee) const; //Allows for comparisons needed for std::map

        char& operator[] (const int i); //returns a single char at specific location

        //Public methods

        int getLength(); //Public strlen() method

        int find(DSString& substr); //finds if substr is a substring of *this -- returns index

        DSString substring(int start, int numChars); //Returns substring of *this -- checks for overflow errors

        char* c_str() const; //ToString() for the DSString

        friend std::ostream& operator<< (std::ostream& os, const DSString& str); //Prints out DSStrings

        std::vector<DSString> split(char divider); //Splits the DSString based upon divider -- lowercase only



};


#endif
