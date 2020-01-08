#include "linked_lists.h"

Node::Node(int value)
{
    this->data = value;
}

void Node::appendToTail(int value)
{
    Node* current = this;
    while (current->next != nullptr)
    {
        current = current->next.get();
    }
    current->next = std::unique_ptr<Node>(new Node(value));
}

Node* deleteNode(Node* head, int value)
{
    Node* current = head;
    if (current->data == value)
    {
        return current->next.get();
    }
    while (current->next != nullptr && current->next->data != value)
    {
        current = current->next.get();
    }
    current->next = std::move(current->next->next);
    return current;
}

Node* remove_duplicates(Node* head)
{
    Node* first = head;
    Node* second = head->next.get();
    while (second->next != nullptr)
    {
        if (first->data == second->data)
        {
            first = first->next.get();
            head = first;
        }
        second = second->next.get();
    }
    while (second->next != nullptr)
    {
        if (first->next->data == second->data)
        {
            first->next = std::move(second->next);
        }
        second = second->next.get();
    }
    return head;
}