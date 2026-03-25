template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    maxSize = i;             // set size
    buffer = new T[i];       // allocate

    frontIndex = 0;          // make fronmt and back index
    backIndex = i - 1;

    this->length = 0;        // queue starts empty
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (isEmpty()){     // check empty
        throw string("queue empty");
    }
    return  buffer[backIndex]; // return back element
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    delete[] buffer;      // free array
    buffer = nullptr;       // dangling pointer thing

    this->length = 0;       // reset length, back, and front
    frontIndex = 0;
    backIndex = maxSize - 1;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;       // copy max

    frontIndex = copyObj.frontIndex;   // copy front and back
    backIndex = copyObj.backIndex;

    this->length = copyObj.length;     // copy length
    buffer = new T[maxSize];    // allocate new
    for (int i = 0; i < maxSize; i++){      // copy each
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (isEmpty()){           // check empty
        throw string("Error: cannot dequeue from empty queue");
    }
    frontIndex = (frontIndex + 1) % maxSize; // advance front circularly
    this->length--;      // decrement 
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (isFull()){      // check full
        throw string("cannot enqueue into full queue");
    }
    backIndex = (backIndex + 1) % maxSize;   // advance back circularly

    buffer[backIndex] = elem;  // insert element
    this->length++;                 // incremennt
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (isEmpty()){            // check empty
        throw string("queue empty");
        }

    return buffer[frontIndex]; // return front
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
