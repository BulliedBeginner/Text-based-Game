#pragma once
#include <iostream>
#include "BuffNode.h"

class Buff
{
public:
    BuffNode* _head_node;
    BuffNode* _tail;
    int _length;
    int _capacity;

    Buff();
    ~Buff();

    void dequeue();
    void enqueue(BuffType buff);
    bool isEmpty();
    bool isFull();
    void print();
    std::string Get_StringBuff();
    BuffType Get_Buff(int position);
};

