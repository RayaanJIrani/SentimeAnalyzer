//
// Created by Ray Irani on 2/14/21.
//

#ifndef SENTIMENTANALYZER_MANAGER_H
#define SENTIMENTANALYZER_MANAGER_H
#include "DSString.h"
#include "Train_Tweet.h"
#include "Test_Tweet.h"

#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <iomanip>
#pragma once
#endif //SENTIMENTANALYZER_MANAGER_H
using namespace std;

//This removes the first line of the csv file
void read_header(ifstream& inFS);

//Reads through the training data and generates a vector of tweets for each line
vector<Train_Tweet>& record_all_tweets(ifstream& inFS, char* file_name, vector<Train_Tweet>& tweets);

//This function takes in the tweets breaks them up into words then adds the words to the map.
void generate_sentiment(vector<Train_Tweet> tweets, map<DSString,int>& positive_sentiment, map<DSString,int>& negative_sentimet);

//Generates a map of predicted sentiment by iterating through the test_dataset csv
void predict_sentiment(ifstream& inFS, char* file_name, map<DSString,int>& positive_sentiment, map<DSString,int>& negative_sentiment ,map<int,int>& predicted_sentiments);

//Reads the test_sentiment file and compares the sentiment in that document to map made of the ID and predicted sentiment
//Any inaccurate tweets are added to a vector of incorrect tweet id's
void determine_incorrect(ifstream& inFS, char* file_name,vector<unsigned int>& incorrect_vals, map<int,int>& predictions);

//Using an output file stream, accuracy, and vector of incorrect tweets to generate output
void create_output(ofstream& outFS, DSString& output_name, vector<unsigned int> incorrect, double accuracy);
