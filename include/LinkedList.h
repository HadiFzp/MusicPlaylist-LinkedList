#ifndef REPOS_LINKEDLIST_H
#define REPOS_LINKEDLIST_H

#include "Song.h"
#include <iostream>

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

public:
	LinkedList();
	~LinkedList();

	void append(const Song& song);
	void remove(const string& track_name);
	bool contains(const Song& song) const;
	void clear();
	int getSize() const;
	Node* getMiddle(Node* head);
	Node* merge(Node* left, Node* right);
	Node* mergeSort(Node* head);
	void sortByTrackname();
};



#endif			
