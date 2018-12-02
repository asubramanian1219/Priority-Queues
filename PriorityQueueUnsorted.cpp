#include "stdafx.h"
#include "PriorityQueue.h"
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

template <class Type>
class PriorityQueueUnsorted :PriorityQueue<Type>
{
private:
	list<Type> pq;
	Type min;
	typename list<Type>::iterator minPos;
public:
	PriorityQueueUnsorted() {
		pq = {};
	}
	~PriorityQueueUnsorted() {
		cout << "The unsorted priority queue is being destructed.";

	}
	bool isEmpty() {
		if (pq.size() == 0)
			return true;
		return false;
	}
	int size() {
		return pq.size();
	}
	void insertItem(Type data) {
		if (isEmpty()) {
			pq.insert(pq.begin(), data);//inserts item at front
			min = data;
			minPos = pq.begin();
		}
		else {
			pq.insert(pq.begin(), data);//inserts at front
			if (data < min) {//if inserted element is less than current min
				min = data;//changes the min element and position
				minPos = pq.begin();
			}
		}

	}
	Type removeMin() {
		if (!pq.empty()) {
			Type temp = min;//removes min
			pq.erase(minPos);
			if (!isEmpty()) {
				minPos = min_element(pq.begin(), pq.end());//finds the new min
				min = *minPos;
			}
			return temp;
		}
		else
			cout << "Empty queue exception!"; //can't remove element from empty queue
	}
	

};

