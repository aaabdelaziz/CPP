//============================================================================
// Name        : Inheritance.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//https://www.youtube.com/watch?v=-W-TYjL0aFE

#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel{

	string channel_name;
	string owner_name;
	int subsribers_count;	
	list<string> publish_video_title;

public:
	YouTubeChannel(string channel_name, string owner_name){
		this->owner_name = owner_name;
		this->channel_name = channel_name;
		subsribers_count = 0;
	}

	void GetChannelInfo(){

		cout << "-------------- Channel Info------------" << endl ;
		cout << "Channel owner_name: " << owner_name << endl ;
		cout << "Channel name: " << channel_name << endl ;
		cout << "Vedios in channel are.. " << endl ;
		cout << "   " << endl ;

		for( const auto& it: publish_video_title ){
			cout << "    " << it << endl; 
		}

		cout <<"Number of Channel subscribers..." << endl << subsribers_count << endl;
	
	}
	
	void Subscribe(){
		cout << "Subscribing to the channel" << "    " << subsribers_count++ << endl ;
	}

	void UnSubscribe(){
		cout <<"UnSubscribing to the channel" << "    " << subsribers_count-- << endl ;
	}

	void PublishVideo(string video_name){ 
		cout << "publishing video: " << video_name << endl;
		publish_video_title.push_back(video_name);
	}
};


class CookingYouTubeChannel : public YouTubeChannel{

public:
	CookingYouTubeChannel(string name, string owner_name):YouTubeChannel(name,owner_name){}

};
int main() {
	
	CookingYouTubeChannel channel("Ahmed's Kitchen","ahmed");
	channel.PublishVideo("Cooking Apple Pie");
	channel.PublishVideo("Cooking Meat with Rice");

	channel.Subscribe();
	channel.Subscribe();
	channel.Subscribe();
	channel.Subscribe();
	
	channel.UnSubscribe();
	
	channel.GetChannelInfo();

	return 0;
}
