#include <algorithm>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

using namespace std;

void minMax(vector<int>& nums) {
    int minNum = nums[0];
    int maxNum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        this_thread::sleep_for(chrono::milliseconds(7));
        if (nums[i] < minNum) {
            minNum = nums[i];
        }
        if (nums[i] > maxNum) {
            maxNum = nums[i];
        }
    }
    cout << "Min: " << minNum << endl;
    cout << "Max: " << maxNum << endl;
}

void calculateAverage(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    this_thread::sleep_for(chrono::milliseconds(12 * nums.size()));
    double avg = static_cast<double>(sum) / nums.size();
    cout << "Average: " << avg << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    thread t1(minMax, ref(nums));
    thread t2(calculateAverage, ref(nums));

    t1.join();
    t2.join();

    vector<int> modifiedNums(nums);
    int maxIndex =
        distance(modifiedNums.begin(),
                 max_element(modifiedNums.begin(), modifiedNums.end()));
    int minIndex =
        distance(modifiedNums.begin(),
                 min_element(modifiedNums.begin(), modifiedNums.end()));
    double avg = static_cast<double>(
                     accumulate(modifiedNums.begin(), modifiedNums.end(), 0)) /
                 modifiedNums.size();
    modifiedNums[maxIndex] = avg;
    modifiedNums[minIndex] = avg;

    cout << "New array: ";
    for (int i = 0; i < n; i++) {
        cout << modifiedNums[i] << " ";
    }
    cout << endl;

    return 0;
}
