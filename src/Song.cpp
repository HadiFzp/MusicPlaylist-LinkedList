#include "Song.h"
#include <iostream>
#include <iomanip>

Song::Song(const string& artist, const string& track, const string& date,
    const string& genre, double len, const string& topic)
    : artist_name(artist),
    track_name(track),
    release_data(date),
    genre(genre),
    length(len),
    topic(topic) {
}

void Song::display() const
{
    std::cout << "Artist:       " << artist_name << std::endl
              << "Track:        " << track_name << std::endl
              << "Release date: " << release_data << std::endl
              << "Genre:        " << genre << std::endl
              << "Topic:        " << topic << std::endl
              << "Length:       " << std::fixed << std::setprecision(2) << length << " min" << std::endl;
}