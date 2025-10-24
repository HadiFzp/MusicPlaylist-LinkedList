#ifndef REPOS_SONG_H
#define REPOS_SONG_H

#include <string>
using namespace std;

class Song {
public:
	string artist_name;
	string track_name;
	string release_data;
	string genre;
	string topic;
	double length;

	Song(const string& artist, const string& track, const string& date,
		const string& genre, double len, const string& topic)

	void display() const;
};

#endif 
