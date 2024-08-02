#include "Buff.h"
Buff::Buff() {
    _head_node = nullptr;
    _tail = nullptr;
    _length = 0;
    _capacity = 2;
}

Buff::~Buff() { }

void Buff::enqueue(BuffType buff) {
    // if overflow, remove first buff
    if (isFull()) {
        this->dequeue();
    }

    if (_tail == NULL) {
        _tail = new BuffNode(buff);
        _head_node = _tail;
        _length++;
    }
    else {
        BuffNode* temp = new BuffNode(buff);
        _tail->_next = temp;
        _tail = temp;
        _length++;
    }
}


void Buff::dequeue() {
    BuffNode* temp = _head_node;
    if (_head_node == NULL) {
        return;
    }

    if (temp->_next != NULL) {
        temp = temp->_next;
        delete _head_node;
        _head_node = temp;
        _length--;
        return;
    }

    delete _head_node;
    _head_node = NULL;
    _tail = NULL;
    _length--;
    
}


bool Buff::isEmpty() {
    return (_length == 0);
}

bool Buff::isFull() {
    return (_length == _capacity);
}

void Buff::print() {
    BuffNode* temp = _head_node;
    if ((_head_node == NULL) && (_tail == NULL)) {
        std::cout << "Buff is empty\n";
        return;
    }

    std::cout << "Buff list:\n";
    std::string buff = "";
    while (temp != NULL) {
        if (temp->_buffType == Heal) buff = "Heal";
        if (temp->_buffType == DoubleDamage) buff = "DoubleDamage";
        if (temp->_buffType == DoubleHeal) buff = "DoubleHeal";
        if (temp->_buffType == TripleDamage) buff = "TripleDamage";
        std::cout << buff << "\n";
        temp = temp->_next;
    }
    std::cout << "\n";
}

std::string Buff::Get_StringBuff() {
    BuffNode* temp = _head_node;
    if ((_head_node == NULL) && (_tail == NULL)) {
        return "[empty] [empty]";
    }

    int i = 0;
    std::string buff = "";
    std::string word = "";
    while (temp != NULL) {
        if (temp->_buffType == Heal) buff = "Heal";
        if (temp->_buffType == DoubleDamage) buff = "DoubleDamage";
        if (temp->_buffType == DoubleHeal) buff = "DoubleHeal";
        if (temp->_buffType == TripleDamage) buff = "TripleDamage";
        word += "[";
        word += buff;
        word += "] ";

        temp = temp->_next;
        i++;
    }
    if (i != 2) {
        word += "[empty]";
    }
    return word;
}

BuffType Buff::Get_Buff(int position) {
    BuffNode* temp = _head_node;

    if (position == 0) {
        return temp->_buffType;
    }

    while (position != 0) {
        temp = temp->_next;
        position--;
    }
    return temp->_buffType;
}
