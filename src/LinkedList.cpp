#include "LinkedList.h"
#include <stdexcept>

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
        if (current->data.track_name == song.track_name) {
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

Node* LinkedList::getMiddle(Node* head  , Node* tail)
{
    if (!head)
        return nullptr;

    Node* left = head;
    Node* right = tail;

    while (left != right && left->next != right) {
		left = left->next;
		right = right->prev;
    }

    return left;
}

Node* LinkedList::merge(Node* left, Node* right)
{
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }

    if (left->data.track_name < right->data.track_name)
    {
        Node* curr = left;
        curr->next = merge(left->next, right);
        if (curr->next)
        {
            curr->next->prev = curr;
        }
        return curr;
    }
    else
    {
        Node* curr = right;
        curr->next = merge(left, right->next);
        if (curr->next)
        {
            curr->next->prev = curr;
        }
        return curr;
    }
}

Node* LinkedList::mergeSort(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node* mid = getMiddle(head);
    Node* half = mid->next;
    half->next = nullptr;
    if (half)
    {
        half->prev = nullptr;
    }
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);
    return merge(left, right);
}

void LinkedList::sortByTrackname() 
{
    head = mergeSort(head);
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        current->prev = prev;
        prev = current;
        current = current->next;
    }
    tail = prev;
}