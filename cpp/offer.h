/*
* author	: lism2013@hotmail.com
* file		: offer.h
* cdatetime : 2017-02-05 15:19
*/

#ifndef OFFER_H
#define OFFER_H

#include <stack>
#include <stdexcept>

// Q7: use two stack to build a queue
template <typename T> class CQueue{
    public:
        CQueue(){};
        ~CQueue(){};

        void appendTail(const T& node);
        T deleteHead();
    private:
        std::stack<T> stack1;
        std::stack<T> stack2;
};

// append to tail
template <typename T>
void CQueue<T>::appendTail(const T& node){
    this->stack1.push(node);
}

// delete from head
template <typename T>
T CQueue<T>::deleteHead(){
    if (this->stack2.empty()){
        while(!this->stack1.empty()){
            this->stack2.push(this->stack1.top());
            this->stack1.pop();
        }
    }

    if (stack2.empty()){
         throw std::invalid_argument("stack empty");
    }

    T val = this->stack2.top();
    this->stack2.pop();

    return val;
}

//test cqueue
void testCQueue(){
    CQueue<int>* cq = new CQueue<int>();
    cq->appendTail(1);
    cq->appendTail(2);
    cq->appendTail(3);

    int  t;
    for (int i = 0; i < 3; i++){
        t = cq->deleteHead();
        printf("cq t=%d\n", t);
    }

    //exception
    t = cq->deleteHead();
}

#endif /* !OFFER_H */
