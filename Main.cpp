#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ArrayQueue.hpp"  // arr q - wed lab
#include "LinkedQueue.hpp" // ll q - mon lab
using namespace std;

// factory - returns diff q type depending on if u pass size or not
class QueueFactory {
public:

    // no len = ll q (no max)
    static Queue<int>* GetQueue(){
        return new LinkedQueue<int>();
    }
    // len given = arr q (fixed max)
    static Queue<int>* GetQueue(int size){
        return new ArrayQueue<int>(size);
    }
};
// sim 1
void simulation1() {
    cout << "Simulation 1: Ticket Counter" << endl;

    Queue<int>* q = QueueFactory::GetQueue(10);  // arr q w max 10
    ArrayQueue<int>* aq = (ArrayQueue<int>*)q;   // cast so we can use isFull

    int came = 0;  // ppl who joined
    int left = 0;  // ppl served
    int away = 0;  // ppl turned away

    for (int i = 0; i < 100; i++){
        int n = (rand() % 3) - 1;  // rand -1 to 1
        if (n < 0) {
            if (!q->isEmpty()){
                q->dequeue();  // rm from front
                left++;
            }
        } else{
            if (aq->isFull()) {
                away++;  // full, cant join
            } else{
                q->enqueue(i);  // add to back, val doesnt matter
                came++;
            }
        }
    }
    cout << "arrived: " << came << endl;
    cout << "served: " << left << endl;
    cout << "turned away: " << away << endl;                     // print stuff
    cout << "left in line: " << q->getLength() << endl;
    delete q;  // free mem
    cout << endl;
}

// sim 2
void simulation2() {
    cout << "Simulation 2: Bank Line" << endl;
    Queue<int>* q = QueueFactory::GetQueue();  // ll q, no max

    int came = 0;  // ppl who showed up
    int left = 0;  // ppl done
    for (int i = 0; i < 100; i++){
        int n = (rand() % 4) - 1;  // rand -1 to 2
        if (n < 0){
            
            if (!q->isEmpty()) {
                q->dequeue();  // rm from front
                left++;
            }
        } else{
            q->enqueue(i);  // add to back, no limit so always works
            came++;
        }
    }
    cout << "arrived: " << came << endl;
    cout << "served: " << left << endl;                     // print stuff
    cout << "left in line: " << q->getLength() << endl;
    delete q;  // free mem
    cout << endl;
}

int main() {

    srand(time(0));  // seed so nums r diff each run
    simulation1();
    simulation2();

    return 0;
}