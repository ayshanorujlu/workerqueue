#include<iostream>
#include<assert.h>
#include<queue>
#include<vector>
#include<Windows.h>
using namespace std;

class Worker {
public:
	static int idCounter;
	int id;
	string name;
	string surname;
	int age;
	int pageCount;
	Worker() {
		id = idCounter++;
		name = "";
		surname = "";
		age = 0;
		pageCount = 0;
	}
	Worker(string name, string surname, int age, int pageCount) {
		id = idCounter++;
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->pageCount = pageCount;
	}
	void Show() {
		cout << "Id:" << id << endl;
		cout << "Name:" << name << endl;
		cout << "Surname:" << surname << endl;
		cout << "Age:" << age << endl;
		cout << "Page Count:" << pageCount << endl;
	}
};
int Worker::idCounter = 100;
class WorkerQueue {
public:
	vector<Worker>workers;
	bool IsEmpty()const { return workers.empty(); }
	void Push(const Worker worker) {
		workers.push_back(worker);
	}
	void Pop() {
		if (!workers.empty())
			workers.erase(workers.begin());
	}
	Worker& Front() {
		return workers.front();
	}
};
class Printer {
public:
	WorkerQueue queue;
	void AddWorker(const Worker worker) {
		queue.Push(worker);
	}
	void Start() {
		while (!queue.IsEmpty()) {
			Worker worker = queue.Front();
			while (worker.pageCount > 0) {
				system("cls");
				worker.Show();
				Sleep(1000);

				worker.pageCount--;
			}
			queue.Pop();
		}
	}
};
void main() {
	Printer p;
	p.AddWorker(Worker("nargiz", "orujova", 19, 5));
	p.AddWorker(Worker("ayshan", "efendiyeva", 20, 7));
	p.AddWorker(Worker("jahangir", "aliyev", 17, 8));
	p.AddWorker(Worker("turan", "mamedov", 15, 10));
	p.Start();
}