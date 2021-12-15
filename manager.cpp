//
// Created by Ray Irani on 2/14/21.
//

#include "DSString.h"
#include "Train_Tweet.h"
#include "Test_Tweet.h"
#include "manager.h"
#include <vector>
#include <map>
#include <fstream>

using namespace std;

//This removes the first line of the csv file
void read_header(ifstream& inFS){
    char* buffer = new char[101];
    inFS.getline(buffer,100); //gets the input for the first line of the csv file
    delete[] buffer;
}

//Reads through the training data and generates a vector of tweets for each line
vector<Train_Tweet>& record_all_tweets(ifstream& inFS, char* file_name, vector<Train_Tweet>& tweets){
    inFS.open(file_name);
    read_header(inFS);
    for(int i = 0; i < 20000; i ++){
        //Train_Tweet(&inFS) reads a line of the file and creates a Train_Tweet based on that reading
        //processes_tweets.push_back() subsequently pushes that tweet to the end of a vector containing
        //all processed tweets
        tweets.push_back(Train_Tweet(inFS)); //every line becomes a tweet which is added to the vector
    }
    inFS.close(); //This closes the file
    return tweets;
}

//This function takes in the tweets breaks them up into words then adds the words to the map.
void generate_sentiment(vector<Train_Tweet> tweets, map<DSString,int>& positive_sentiment, map<DSString,int>& negative_sentiment){
    for(int i = 0; i < tweets.size(); ++i){ //Iterate through the vector of tweets
        //Create an vector of DSStrings which is formed by dividing each tweet at every space
        std::vector<DSString> words = tweets.at(i).get_content().split(' ');
        //Update the map with regards to the information stored in the array
        for(int j = 0; j < words.size(); ++j){
            DSString key = words.at(j);
            if(tweets.at(i).get_sentiment() == 4){ //If sentiment is positive
                auto location = positive_sentiment.find(key); //find location of key
                if(location == positive_sentiment.end()){ //If the key is not in the map
                    positive_sentiment[key] = 1; //set the value to 1
                } else {
                    positive_sentiment[key] = positive_sentiment[key] + 1; //increment the value up by one
                }
            } else { //If negative sentiment
                auto location = negative_sentiment.find(key); //try to find location of key
                if(location == negative_sentiment.end()){
                    negative_sentiment[key] = 1; //If key not in map set value to 0
                } else {
                    negative_sentiment[key] = negative_sentiment[key] + 1; //increment value by one
                }
            }
        }
    }
}

//Generates a map of predicted sentiment by iterating through the test_dataset csv
void predict_sentiment(ifstream& inFS, char* file_name, map<DSString,int>& positive_sentiment, map<DSString,int>& negative_sentiment , map<int,int>& predicted_sentiments){
    inFS.open(file_name);
    read_header(inFS);
    for(int i = 0; i < 10000; i++) { //iterates through the file
        //initalizes a test_tweet which by reading a line of the csv and comparing it to the sentiment map
        Test_Tweet tweet(inFS, positive_sentiment,negative_sentiment);
        predicted_sentiments[tweet.get_id()] = tweet.get_predicted_sentiment(); //Maps the id to the predicted sentiment

    }
    inFS.close();
}

//Reads the test_sentiment file and compares the sentiment in that document to map made of the ID and predicted sentiment
//Any inaccurate tweets are added to a vector of incorrect tweet id's
void determine_incorrect(ifstream& inFS, char* file_name,vector<unsigned int>& incorrect_vals, map<int,int>& predictions){
    inFS.open(file_name);
    read_header(inFS);
    for(int i = 0; i < 10000; i++){ //iterates through the file
        char* buffer = new char[101];
        inFS.getline(buffer,100,',');
        int sentiment = atoi(buffer); //Reads the sentiment from each line
        inFS.getline(buffer,100);
        unsigned int id = atol(buffer); //Reads the id from each line
        if(predictions[id] != sentiment){
            incorrect_vals.push_back(id); //Adds any incorrect predictions id's to a vector.
        }
        delete[] buffer; //Deallocates memory buffer
    }
    inFS.close();
}

//Using an output file stream, accuracy, and vector of incorrect tweets to generate output
void create_output(ofstream& outFS, DSString& output_name, vector<unsigned int> incorrect, double accuracy){
    outFS.open(output_name.c_str());
    outFS << std::setprecision(3) << accuracy << std::endl;
    for(int i = 0; i < incorrect.size(); ++i){ //Iterates through the vector of incorrect tweets
        outFS << incorrect.at(i) << std::endl;
    }
    outFS.close();
}


