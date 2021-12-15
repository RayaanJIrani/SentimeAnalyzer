//
// Created by Ray Irani on 2/11/21.
//

#ifndef INC_21S_PA01_TWEET_H
#define INC_21S_PA01_TWEET_H

#endif //INC_21S_PA01_TWEET_H
#include "DSString.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#pragma once

class Test_Tweet {
private:
    int sentiment; //This number is either -1 for undefined, 0 for negative, or 4 for positive

    int predicted_sentiment; //This is either -1 for undefined, 0 for negative, or 4 for positive

    unsigned int id; //This is the ID associated with the tweet

    DSString content; //This is the body of the tweet.

    //Takes the sentiment map and the DSString content to predict the sentiment of the tweet
    int predict_sentiment(std::map<DSString,int>& positive_sentiment, std::map<DSString,int>& negative_sentiment);

public:

    //Constructors
    Test_Tweet(); //Default Constructor

    //Constructor takes a input filestream and the sentiment map
    Test_Tweet(std::ifstream& inFS, std::map<DSString,int>& positive_sentiment, std::map<DSString,int>& negative_sentiment);

    //Takes the input for the values as a constructor
    Test_Tweet(const unsigned int identifier, const int pred_sentiment, const DSString& content_input);

    Test_Tweet(const Test_Tweet& diff_tweet); //copy consturctor -- creates a deep copy


    //Overloaded Operators
    Test_Tweet& operator= (const Test_Tweet& diff_tweet); //Assignment operator

    //Acessors
    int get_sentiment();
    int get_predicted_sentiment();
    unsigned int get_id();
    DSString& get_content();

    //Mutators

    //This can be used alongside the prediction constructor to identify accuracy
    void set_sentiment(const int sentiment_value);

};

