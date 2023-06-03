#include <boost/thread.hpp>
#include <iostream>
#include <vector>

using boost::condition_variable;
using boost::mutex;
using boost::unique_lock;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

mutex *mutexArray;
condition_variable *cvArray;
bool *threadWaiting;

mutex mutexMain;
condition_variable cvMain;

int currentWorkingThreads = 0;
int workingThreadsLeft = 0;

mutex mutexOutput;
mutex dataChangeMutex;

int threadNumberToStop = -1;

vector<int> currentArray;

int arraySize;

void markerThread(int threadNumber) {
    srand(threadNumber);
    while (threadNumber != threadNumberToStop) {
        {
            unique_lock<mutex> lock(mutexArray[threadNumber - 1]);
            cvArray[threadNumber - 1].wait(lock, [threadNumber] {
                return !threadWaiting[threadNumber - 1];
            });
            threadWaiting[threadNumber - 1] = true;
        }

        int amountOfMarkedElements = 0;

        int currentIndex = rand() % arraySize;
        while (currentArray[currentIndex] == 0) {
            ++amountOfMarkedElements;
            boost::this_thread::sleep_for(boost::chrono::milliseconds(5));
            {
                currentArray[currentIndex] = threadNumber;
                unique_lock<mutex> lock(dataChangeMutex);
                cout << "Thread " << threadNumber << ": "
                     << "Array[" << currentIndex << "] is set to "
                     << threadNumber << " |";

                for (int i = 0; i < arraySize; i++) {
                    cout << currentArray[i] << " ";
                }
                cout << endl;
            }
            boost::this_thread::sleep_for(boost::chrono::milliseconds(5));
            currentIndex = rand() % arraySize;
        }

        {
            unique_lock<mutex> lock(mutexOutput);
            cout << endl;
            cout << "- Thread " << threadNumber << " -" << endl;
            cout << "Was stopped by: " << currentArray[currentIndex]
                 << " at index: " << currentIndex << endl;
            cout << "After marking " << amountOfMarkedElements << " elements"
                 << endl;
            for (int i = 0; i < arraySize; i++) {
                cout << currentArray[i] << " ";
            }
            cout << endl;
        }

        currentWorkingThreads--;
        cvMain.notify_one();
        {
            unique_lock<mutex> lock(mutexArray[threadNumber - 1]);
            cvArray[threadNumber - 1].wait(lock, [threadNumber] {
                return !threadWaiting[threadNumber - 1];
            });
        }
    }

    for (int i = 0; i < arraySize; i++) {
        if (currentArray[i] == threadNumber) {
            currentArray[i] = 0;
        }
    }
}

int main(int argc, char **argv) {
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    currentArray.resize(arraySize);
    for (int i = 0; i < arraySize; i++) {
        currentArray[i] = 0;
    }
    cout << "Array size: " << arraySize << endl;

    for (int i = 0; i < arraySize; i++) {
        currentArray[i] = 0;
        cout << currentArray[i] << " ";
    }
    cout << endl;

    int numThreads;
    cout << "Enter the number of marker threads: ";
    cin >> numThreads;

    boost::thread *markers = new boost::thread[numThreads];
    mutexArray = new mutex[numThreads];
    cvArray = new condition_variable[numThreads];
    threadWaiting = new bool[numThreads];
    for (int i = 0; i < numThreads; i++) {
        markers[i] = boost::thread(markerThread, i + 1);
        threadWaiting[i] = true;
    }

    workingThreadsLeft = numThreads;
    while (workingThreadsLeft > 0) {
        currentWorkingThreads = workingThreadsLeft--;
        for (int i = 0; i < numThreads; i++) {
            threadWaiting[i] = false;
            cvArray[i].notify_one();
        }

        unique_lock<mutex> lock(mutexMain);
        cvMain.wait(lock, [] { return currentWorkingThreads == 0; });

        cout << "Enter which thread to terminate: ";
        cin >> threadNumberToStop;

        threadWaiting[threadNumberToStop - 1] = false;
        cvArray[threadNumberToStop - 1].notify_one();
        markers[threadNumberToStop - 1].join();

        cout << "Array: ";
        for (int i = 0; i < arraySize; i++) {
            cout << currentArray[i] << " ";
        }
        cout << endl;
    }

    delete[] markers;
    delete[] mutexArray;
    delete[] cvArray;
    delete[] threadWaiting;

    return 0;
}
