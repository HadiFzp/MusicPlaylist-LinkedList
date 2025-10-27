#include "LinkedList.h"
#include<Song.h>


LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::append(const Song& song) 
{
    Node* newNode = new Node(song);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void LinkedList::remove(const std::string& track_name) 
{
    Node* current = head;

    while (current != nullptr && current->data.track_name != track_name) {
        current = current->next;
    }

    if (current == nullptr) {
        return;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    delete current;
    size--;
}

bool LinkedList::contains(const Song& song) const 
{
    const Node* current = head;
    while (current != nullptr) {
        if (current->data.track_name == song.track_name &&
            current->data.artist_name == song.artist_name) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::clear()
{
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

int LinkedList::getSize() const 
{
    return size;
}

void LinkedList::sort(const CompareFunction& comp) {
    if (head == nullptr || head == tail) return;

    head = mergeSort(head, tail, comp);

    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        current->prev = prev;
        prev = current;
        current = current->next;
    }
    tail = prev;
}

Node* LinkedList::mergeSort(Node* start, Node* end, const CompareFunction& comp) {
    if (start == end) return start;

    Node* mid = getMiddle(start, end);
    Node* midNext = mid->next;

    mid->next = nullptr;
    if (midNext) midNext->prev = nullptr;

    Node* left = mergeSort(start, mid, comp);
    Node* right = mergeSort(midNext, end, comp);

    return merge(left, right, comp);
}

Node* LinkedList::merge(Node* left, Node* right, const CompareFunction& comp) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    if (comp(left->data, right->data)) {
        Node* curr = left;
        curr->next = merge(left->next, right, comp);
        if (curr->next) {
            curr->next->prev = curr;
        }
        return curr;
    }
    else {
        Node* curr = right;
        curr->next = merge(left, right->next, comp);
        if (curr->next) {
            curr->next->prev = curr;
        }
        return curr;
    }
}

Node* LinkedList::getMiddle(Node* start, Node* end) {
    if (!start) return nullptr;

    Node* left = start;
    Node* right = end;

    while (left != right && left->next != right) {
        left = left->next;
        right = right->prev;
    }
    return left;
}

void LinkedList::sortByTrackName() {
    sort([](const Song& a, const Song& b) {
        return a.track_name < b.track_name;
        });
}

void LinkedList::sortByArtistName() {
    sort([](const Song& a, const Song& b) {
        return a.artist_name < b.artist_name;
        });
}

void LinkedList::sortByReleaseDate() {
    sort([](const Song& a, const Song& b) {
        return a.release_date < b.release_date;
        });
}

void LinkedList::sortByDuration(bool ascending) {
    if (ascending) {
        sort([](const Song& a, const Song& b) {
            return a.length < b.length;
            });
    }
    else {
        sort([](const Song& a, const Song& b) {
            return a.length > b.length;
            });
    }
}