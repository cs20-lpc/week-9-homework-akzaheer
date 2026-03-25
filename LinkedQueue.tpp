#include <string>
using std::string;
template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    this->head = nullptr;
    this->last = nullptr;               // set default vals
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    this->head = nullptr;
    this->last = nullptr;
    this->length = 0;
    copy(copyObj);
    }

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if (this->isEmpty()){
        throw string("Queue is empty");
    }
    return this->last->value;                // check if empty and if not return lasts(back) value
}

template <typename T>
void LinkedQueue<T>::clear() {
    // To do
    auto curr = this->head;
    while (curr != nullptr) {
        auto temp = curr;                  // go through and deleete
        curr = curr->next;
        delete temp;
    }
    this->head = nullptr;
    this->last = nullptr;       // reset
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    this->head = nullptr;
    this->last = nullptr;           // start empty just in case of errors
    this->length = 0;

    auto curr = copyObj.head;
    while(curr != nullptr){
        this->enqueue(curr->value);          // go through and add each val
        curr = curr->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (this->isEmpty()){
        throw string("Queue is empty");          // if empty
    }
    auto temp = this->head;        // Store the front
    this->head = this->head->next;      // move
    delete temp;                        // delete old front
    this->length--;                     /// change length

    if(this->head == nullptr){
        this->last = nullptr;               // if queue is empty rthen fix last
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    auto newNode = new Node;
    newNode->value = elem;                       // new node and set vals
    newNode->next = nullptr;

    if (this->isEmpty()) {
        this->head = newNode;               // if empty add new node
        this->last = newNode;
    } else {
        // attach to end
        this->last->next = newNode;         // if not emptyt add to back
        this->last = newNode;
    }
    this->length++;             // change size
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (this->isEmpty()){
        throw string("queue is empty");             // if empty throw
    }
    return this->head->value;            // retrurn first element
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
