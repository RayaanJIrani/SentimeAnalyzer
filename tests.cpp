//
// Created by Ray Irani on 2/6/21.
//
#include "catch.hpp"
#include "DSString.h"
#include <vector>

TEST_CASE("DSStrings have properties of length and content. These properties can be compared and mutated consistently","[DSString]"){
    const char* hello_char = "hello";
    const char* goodbye_char = "goodbye";
    DSString empty = DSString();
    DSString null_char = DSString("\0");
    DSString hello = DSString(hello_char);
    DSString goodbye = DSString(goodbye_char);
    DSString combined = DSString("hellogoodbye");

    SECTION("DSStrings have a length"){
        REQUIRE(empty.getLength() == 0);
        REQUIRE(null_char.getLength() == 0);
        REQUIRE(hello.getLength() == 5);
        REQUIRE(goodbye.getLength() == 7);
        REQUIRE(combined.getLength() == 12);

    }

    SECTION("DSStrings can be compared for equivalency"){
        DSString hello_2 = DSString("hello");
        DSString goodbye_2 = DSString("goodbye");
        REQUIRE((hello == hello_2) == 1);
        REQUIRE((goodbye == goodbye_2) == 1);
        REQUIRE((hello == goodbye) == 0);
        REQUIRE((goodbye_2 == null_char) == 0);
        REQUIRE((hello_2 == null_char) == 0);
    }

    SECTION("DSStrings can be compared to char*"){
        REQUIRE((hello == hello_char) == 1);
        REQUIRE((hello == goodbye_char) == 0);
        REQUIRE((goodbye == goodbye_char) == 1);
        REQUIRE((goodbye == hello_char) == 0);
        REQUIRE((hello == "") == 0);
        REQUIRE((goodbye == "\0") == 0);
    }

    SECTION("DSStrings can be used to compared using the overloaded != operator"){
        REQUIRE((hello != goodbye) == 1);
        REQUIRE((hello != combined) == 1);
        REQUIRE((hello != null_char) == 1);
        REQUIRE((hello != hello) == 0);
        REQUIRE((empty != null_char) == 0);
    }

   SECTION("DSStrings can use the overloaded assignment operator to make a deep copy"){
        DSString test = hello; //makes hello_2 equivalent to DSString hello
        test = goodbye;
        REQUIRE((test == goodbye) == 1);
        REQUIRE((test != hello) == 1);
        test = hello;
        REQUIRE((test == hello) == 1);
        REQUIRE((test != goodbye) == 1);
        test = null_char;
        REQUIRE((test == null_char) == 1);
        REQUIRE((test != null_char) == 0);

    }

    SECTION("DSStrings can use the overloaded assignment operator to copy a char*"){
        DSString test = "hello";
        REQUIRE((test == hello) == 1);
        test = "goodbye";
        REQUIRE((test == goodbye) == 1);
        test = "";
        REQUIRE((test == "") == 1);
        REQUIRE((test == null_char) == 1);
        test = "OMG!!!! I need to tweet this like yesterday... ";
        REQUIRE((test == "OMG!!!! I need to tweet this like yesterday... ") == 1);

    }

    SECTION("The overloaded + operator can be used to append two DSStrings together"){
        DSString hello_goodbye = hello + goodbye;
        const char* best_prof = "best prof ever";
        DSString Dr_f = DSString("best") + DSString(" prof") + DSString(" ever");
        REQUIRE((hello_goodbye == combined) == 1);
        REQUIRE((Dr_f ==best_prof) == 1);
        REQUIRE(Dr_f.getLength() == strlen(best_prof));
        hello_goodbye = DSString("Mele") + DSString(" Kalikimaka");
        REQUIRE((hello_goodbye == "Mele Kalikimaka") == 1);
        hello_goodbye = " ";
        hello_goodbye = DSString("My") + hello_goodbye + DSString("way");
        REQUIRE((hello_goodbye == "My way") == 1);
    }

    SECTION("DSStrings can be use the [] operator to find a char in the DSString "){
        REQUIRE(hello[3] == hello_char[3]);
        REQUIRE(hello[3] != goodbye[3]);
        REQUIRE(combined[2] == hello[2]);
        REQUIRE(combined[0] == 'h');
        REQUIRE(goodbye[2] == 'o');
    }

    SECTION("DSString can use the < operator to determine wheter one string is alphabetically before another string"){
        REQUIRE((hello < goodbye) == 0);
        REQUIRE((goodbye < hello) == 1);
        REQUIRE((combined < hello) == 0);
        REQUIRE((combined < goodbye) == 0);
        REQUIRE((goodbye < combined) == 1);

    }

    SECTION("Substring can be used to return a DSString which is the substring of a DSString"){
        DSString sub_str = "hola coma esta";
        DSString holder = sub_str.substring(4,4);
        REQUIRE((holder == " com") == 1);
        holder = sub_str.substring(1,3);
        REQUIRE((holder == "ola") == 1);
        holder = combined.substring(0,5);
        REQUIRE((holder == "hello") == 1);
        sub_str = "yes";
        holder = sub_str.substring(0,3);
        REQUIRE((holder == sub_str) == 1);
        holder = sub_str.substring(0,1);
        REQUIRE((holder == "y") == 1);
    }


    SECTION("Find can be used to find if a DSString is a substring in another DSString"){
        DSString test = DSString("hola");
        DSString testee = DSString("ol");
        REQUIRE(test.find(testee) == 1);
        testee = "Ebola";
        REQUIRE(test.find(testee) == -1);
        test = "Ebola";
        REQUIRE(testee.find(test) == 0);
        test = "I want to wake up in a city that never sleeps NEW YORK, NEW YORK";
        testee = "NEW YORK";
        REQUIRE( test.find(testee) == 46);
        test = "I think to myself what a wonderful world";
        testee = "wonderful world";
        REQUIRE(test.find(testee) == 25);
    }

    SECTION("Split can be used to deliniate a DSString into several component DSStirngs returned in a vector"){
        //NOTE: for efficency reasons the split functions only returns substrings of length greather than 3.
        DSString test = "hello there my name is salie mae and I am seven years old. ";
        std::vector<DSString> words = test.split(' ');
        REQUIRE((words.at(1) == "there") == 1);

        test = "who am I? No who are you?";
        words = test.split(' ');
        REQUIRE((words.size() == 1) == 1);

        test = "Antidisestablismentarianism";
        words = test.split(' ');
        REQUIRE((words.size() == 1) == 1);

        test = "                  ";
        words = test.split(' ');
        REQUIRE((words.size() == 0) == 1);

        test = "New York! New York! New York!";
        words = test.split('!');
        REQUIRE((words.at(0) == "new york" ) == 1); //substring makes all output strings lowercase

        test = "было бы большой честью поговорить с вами"; //@ElonMusk -- to Vladamir Putin (Unicode codes бы as four characters)
        words = test.split(' ');
        REQUIRE((words.size() == 6) == 1);
    }

}
