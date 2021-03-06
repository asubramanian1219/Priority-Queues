// PA3 Copy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <iterator>
#include <vector> 
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include "PriorityQueueUnsorted.cpp"
#include "PriorityQueueSorted.cpp"
#include "PriorityQueueHeap.cpp"
#include "StopWatch.h"



int main()
{
	StopWatch t;
	StopWatch q;
	ifstream fileOpen;
	string filePath="numbers.txt";
	int num;
	vector<int>nums;
	fileOpen.open(filePath);
	while (!fileOpen.eof()) {
		fileOpen >> num;
		nums.push_back(num);
	}
	if (nums.at(0) == 0) {
		PriorityQueueUnsorted<int>pq;
		t.start();
		for (int n = 0; n < nums.size(); n = n + 10) {
			for (int i = 2; i < n + 2; i++) {
				pq.insertItem(nums.at(i));
				/*if (i>2&&((i - 2) % 10 == 0)) {
					cout <<t.ms()<<endl;
				}*/



			}

			//t.stop();
			//cout << "Total time: " << t.ms();
			while (!pq.isEmpty()) {
				//cout << pq.removeMin() << endl;
				pq.removeMin();
			}
			cout << t.ms()<<endl;
			t.stop();
		}
		
	}
	else if (nums.at(0) == 1) {
		PriorityQueueSorted<int>pq;
		t.start();
		for (int n = 0; n < nums.size(); n = n + 10) {
			for (int i = 2; i < n + 2; i++) {
				pq.insertItem(nums.at(i));
				/*if (i>2&&((i - 2) % 10 == 0)) {
				cout <<t.ms()<<endl;
				}*/



			}

			//t.stop();
			//cout << "Total time: " << t.ms();
			while (!pq.isEmpty()) {
				//cout << pq.removeMin() << endl;
				pq.removeMin();
			}
			cout << t.ms() << endl;
			t.stop();
		}

	}
	else {
		PriorityQueueHeap<int>pq;
		t.start();
		//for (int n = 0; n < nums.size(); n = n + 10) {
		for (int i = 2; i < nums.size(); i++) {
			pq.insertItem(nums.at(i));
		}

				/*if (i>2&&((i - 2) % 10 == 0)) {
				cout <<t.ms()<<endl;
				}*/



			

			//t.stop();
			//cout << "Total time: " << t.ms();
			while (!pq.isEmpty()) {
				//cout << pq.removeMin() << endl;
				pq.removeMin();
			}
			cout << t.ms() << endl;
			t.stop();
		//}
	}

	/*PriorityQueueHeap<int> pq;

	cout << pq.size()<<endl;
	pq.insertItem(2);
	cout << pq.removeMin()<<endl;
	pq.insertItem(4);
	pq.insertItem(1);
	pq.insertItem(45);
	pq.insertItem(3);
	cout << pq.removeMin() << endl;

	
	cout << pq.size()<<endl;
	*/
	system("pause");

	return 0;
}
