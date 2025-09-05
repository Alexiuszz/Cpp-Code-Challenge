#include <iostream>

class LinkedList
{
private:
    class Node
    {
    public:
        Node *next;
        int data;
        Node(int item);
        Node(int item, Node *prevNode);
        // ~Node();
    };

    Node *head;
    Node *tail;
    int count;

public:
    LinkedList();
    /// Add element at the end of the list
    /// @param item: The element to be added
    void Add(int item);

    // Removes and returns element on the specified index
    /// @param index: The index of the element to be removed
    /// @return The removed element
    int RemoveAt(int index);
};
LinkedList::Node::Node(int item) : data(item), next(nullptr)
{
}

LinkedList::Node::Node(int item, Node *prevNode) : data(item), next(nullptr)
{
    prevNode->next = this;
}

LinkedList::LinkedList() : head(nullptr), tail(nullptr), count(0)
{
}

void LinkedList::Add(int item)
{
    if (this->head == nullptr)
    {
        this->head = new Node(item);
        this->tail = this->head;
    }
    else
    {
        Node *newNode = new Node(item, this->tail);
        this->tail = newNode;
    }
    this->count++;
}

int LinkedList::RemoveAt(int index)
{
    if (index >= count || index < 0)
    {
        throw std::out_of_range("Invalid index: " + index);

        int currIndex = 0;
        Node *currNode = this->head;
        Node *prevNode = nullptr;
        while (currIndex < index)
        {
            prevNode = currNode;
            currNode = currNode->next;
            currIndex++;
        }
    }
}

int main()
{
}
