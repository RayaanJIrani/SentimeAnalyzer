//
// Created by Ray Irani on 2/11/21.
//

#include "Train_Tweet.h"
#include "DSString.h"

    //Constructors

    //Default Constructor
    Train_Tweet::Train_Tweet() {
        sentiment = -1;
        content = DSString("");
    }

    //uses filestream to generate tweet
    Train_Tweet::Train_Tweet(std::ifstream& inFS){
        //Collects data for one line of the CSV file.
        char* buffer = new char[1001]; //160 character limit of tweets (in Ye Olde days) + 1 null char
        inFS.getline(buffer,1000,','); //gets the first portion of the line up to the ','
        sentiment = atoi(buffer); //ASCII code for '0' is 48
        inFS.getline(buffer,1000,','); //ID
        inFS.getline(buffer,1000,','); //Date
        inFS.getline(buffer,1000,','); //Query
        inFS.getline(buffer,1000,','); //User
        inFS.getline(buffer,1000); //Train_Tweet
        content = buffer;
        delete[] buffer;

    }

    //Takes input values to create tweet
    Train_Tweet::Train_Tweet(const int sentiment_value, const DSString& content_input){
        content = content_input;
        sentiment = sentiment_value;
    }

    //copy consturctor -- creates a deep copy
    Train_Tweet::Train_Tweet(const Train_Tweet& diff_tweet){
        content =  DSString(diff_tweet.content); //creates a deep copy of content_input
        //Warning this may cause time delays due to copying
        sentiment = diff_tweet.sentiment;
    }


    Train_Tweet& Train_Tweet::operator= (const Train_Tweet& diff_tweet){
        content = DSString(diff_tweet.content); //creates a deep copy of content_input
        sentiment = diff_tweet.sentiment;
        return *this;
    }

    int Train_Tweet::get_sentiment(){
        return sentiment;
    }


    DSString& Train_Tweet::get_content() {
        return (content);
    }






