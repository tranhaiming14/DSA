#include <iostream>
#include <vector>

using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int smaller = low - 1;
    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            smaller += 1;
            swap(arr[j], arr[smaller]);
        }
    }
    swap(arr[smaller+1], arr[high]);
    return smaller + 1;

}
void quicksort(vector<int>& arr, int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);

        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot + 1, high);

    }
}
void printArray(vector<int> arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    quicksort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}