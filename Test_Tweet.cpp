//
// Created by Ray Irani on 2/11/21.
//

#include "Test_Tweet.h"
#include "DSString.h"

//Constructors

//Constructor takes a input filestream and the sentiment map
Test_Tweet::Test_Tweet(std::ifstream& inFS, std::map<DSString,int>& positive_sentiment, std::map<DSString,int>& negative_sentiment){
    //Collects data for one line of the CSV file.
    char* buffer = new char[1001]; //ensure large buffer
    inFS.getline(buffer,1000,','); //ID
    id = atol(buffer);
    inFS.getline(buffer,1000,','); //Date
    inFS.getline(buffer,1000,','); //Query
    inFS.getline(buffer,1000,','); //User
    inFS.getline(buffer,1000); //Train_Tweet
    content = buffer;
    delete[] buffer;
    predicted_sentiment = predict_sentiment(positive_sentiment,negative_sentiment); //calls helper method to predict sentiment

}

//Default constructor -- Sets all values either to 0 or -1
Test_Tweet::Test_Tweet() {
    id = 0;
    predicted_sentiment = -1;
    sentiment = -1;
    content = DSString("");
}

//Takes the input for the values as a constructor
Test_Tweet::Test_Tweet(const unsigned int identifier, const int pred_sentiment, const DSString& content_input){

    id = identifier;
    predicted_sentiment = pred_sentiment;
    content =  DSString(content_input); //creates a deep copy of content_input
    sentiment = -1;
}

//Copy constructor -- Creates deep copy
Test_Tweet::Test_Tweet(const Test_Tweet& diff_tweet){
    id = diff_tweet.id;
    predicted_sentiment = diff_tweet.predicted_sentiment;
    content =  DSString(diff_tweet.content); //creates a deep copy of content_input
    sentiment = diff_tweet.sentiment;
}

//Takes the sentiment map and the DSString content to predict the sentiment of the tweet
int Test_Tweet::predict_sentiment(std::map<DSString,int>& positive_sentiment, std::map<DSString,int>& negative_sentiment) {
    int sentiment = 0;
    std::vector<DSString> words = content.split(' '); //breaks the tweet up into words
    for(int i = 0; i < words.size(); ++i){
        sentiment += positive_sentiment[words.at(i)];//iterates through the tweet looking at the sentiment value of each word
        sentiment -= negative_sentiment[words.at(i)];
    }
    if(sentiment > 0){
        return 4;
    } else {
        return 0;
    }

}

//Assignment Operator -- Deep copy
Test_Tweet& Test_Tweet::operator= (const Test_Tweet& diff_tweet){
    id = diff_tweet.id;
    predicted_sentiment = diff_tweet.predicted_sentiment;
    content = DSString(diff_tweet.content); //creates a deep copy of content_input
    sentiment = diff_tweet.sentiment;
    return *this;
}

int Test_Tweet::get_sentiment(){
    return sentiment;
}

int Test_Tweet::get_predicted_sentiment(){
    return predicted_sentiment;
}

unsigned int Test_Tweet::get_id(){
    return id;
}

DSString& Test_Tweet::get_content() {
    return content;
}

void Test_Tweet::set_sentiment(const int sentiment_value){
    sentiment = sentiment_value;
}

