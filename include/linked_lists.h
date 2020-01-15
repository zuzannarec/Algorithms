#pragma once
#include <stdint.h>
#include <iostream>
#include <memory>

class Node
{
public:
    Node(int value);
    int data;
    std::unique_ptr<Node> next = nullptr;
    void appendToTail(int value);
};

Node* deleteNode(Node* head, int value);

Node* remove_duplicates(Node* head);