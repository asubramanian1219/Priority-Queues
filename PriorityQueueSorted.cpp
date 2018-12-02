#include "stdafx.h"
#include "PriorityQueue.h"
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

template <class Type>
class PriorityQueueSorted :PriorityQueue<Type>
{
private:
	list<Type> pq;
	Type min;
	typename list<Type>::iterator minPos;
public:
	PriorityQueueSorted() {
		pq = {};//initialize the list
	}
	~PriorityQueueSorted() {
		cout << "The snorted priority queue is being destructed."; 

	}
	bool isEmpty() {
		if (pq.size() == 0)
			return true;//return true if size is 0 and false if not
		return false;
	}
	int size() {
		return pq.size();
	}
	void insertItem(Type data) {
		if (isEmpty()) {
			pq.insert(pq.begin(), data);//insert item into queue
			min = data;
			minPos = pq.begin();
		}
		else {
			if (data <= *minPos) {
				pq.insert(pq.begin(), data);//if element is less than the front of queue it inserts it in the front
				minPos = pq.begin();//changes position of minimum
			}
			else {
				int inserted = 0;//tells whether the item was inserted or not
				typename list<Type>::iterator past = minPos; //set both past and next equal to minpos
				typename list<Type>::iterator next = minPos;
				next++;
				for (next; next != pq.end(); next++) {//iterates through list
					if ((data <= *next)&(data >= *past)) {
						pq.insert(next, data); //inserts in between next and past
						inserted = 1;

						break;

					}
					else
						past++;//increments past
					
				}
				if (inserted == 0) { //if not inserted
					pq.insert(pq.end(), data); //inserts at end
				}


			}
			

		}

	}
	Type removeMin() {
		if (!pq.empty()) {//returns and removes the  first element
			Type temp = *pq.begin();
			pq.erase(pq.begin());

			return temp;
		}
		else
			cout << "Empty queue exception!";
	}

};

