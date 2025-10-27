#ifndef REPOS_LINKEDLIST_H
#define REPOS_LINKEDLIST_H

#include "Song.h"
#include <functional>

using namespace std;

class LinkedList 
{
	private:
		class Node 
		{
		public:
			Song data;
			Node* next;
			Node* prev;
			Node(const Song& song) : data(song), next(nullptr), prev(nullptr) {}
		};
		Node* head;
		Node* tail;
		int size;
		
		using CompareFunction = std::function<bool(const Song&, const Song&)>;

		Node* getMiddle(Node* start, Node* end);
		Node* merge(Node* left, Node* right, const CompareFunction& comp);
		Node* mergeSort(Node* start, Node* end, const CompareFunction& comp);



public:
	LinkedList();
	~LinkedList();

	void append(const Song& song);
	void remove(const string& track_name);
	bool contains(const Song& song) const;
	void clear();
	int getSize() const;
	

	void sort(const CompareFunction& comp);
	void sortByTrackName();
	void sortByArtistName();
	void sortByReleaseDate();
	void sortByDuration(bool ascending = true);

};



#endif			
