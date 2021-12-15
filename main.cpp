#include <iostream>
#include <fstream>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "DSString.h"
#include "Train_Tweet.h"
#include "Test_Tweet.h"
#include "manager.h"
#include <vector>
#include <cstring> //used only as a buffer before placing into DSString
#include <map>
#include <iomanip>
#define CATCH_CONFIG_MAIN


int main(int argc, char* argv[]) {
    if(argc == 1) {
        Catch::Session session = Catch::Session();
        session.run(); //This runs the tests for the DSString class which can be found in Tests.cpp

    } else { //This runs when there are multiple input files

        ifstream inFS; //Opens the FStream
        std::vector<Train_Tweet> processed_tweets; //Vector of all tweets from the training data
        processed_tweets = record_all_tweets(inFS, argv[1], processed_tweets); //Reads file and creates tweets

        std::map<DSString,int> positive_vals; //map of positive vals
        std::map<DSString,int> negative_vals; //map of negative vals
        generate_sentiment(processed_tweets,positive_vals,negative_vals); //given training tweets generates sentiment vals

        std::map<int,int> sentiment_predictions; //Key:ID , Value: Sentiment Value
        predict_sentiment(inFS,argv[2],positive_vals,negative_vals,sentiment_predictions); //predicts values for the test tweets


        std::vector<unsigned int> incorrect_predictions; //vector of the incorrect tweets
        determine_incorrect(inFS,argv[3],incorrect_predictions,sentiment_predictions); //determines which tweets were inacuratly classified

        double accuracy = (sentiment_predictions.size() - incorrect_predictions.size()); //calculates number correct
        accuracy /= sentiment_predictions.size(); //divides by total to find accuracy

        ofstream outFS; //opens the output file stream
        DSString output_name(argv[4]); //sets the name of the output file to argv[4]
        create_output(outFS,output_name,incorrect_predictions,accuracy); //Generates output file including accuracu and incorrect vals

    }

    return 0;

}




