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
#pragma once

class Train_Tweet {
    private:
        int sentiment; //This number is either -1 for undefined, 0 for negative, or 4 for positive
        DSString content; //This is the body of the tweet.

    public:

        //Constructors
        Train_Tweet(); //Default Constructor

        Train_Tweet(std::ifstream& inFS); //uses filestream to generate tweet


        Train_Tweet(const int sentiment_value, const DSString& content_input); //Takes input values to create tweet

        Train_Tweet(const Train_Tweet& diff_tweet); //copy consturctor -- creates a deep copy


        //Overloaded Operators
        Train_Tweet& operator= (const Train_Tweet& diff_tweet); //Assignment operator

        //Acessors
        int get_sentiment();

        DSString& get_content();

};
