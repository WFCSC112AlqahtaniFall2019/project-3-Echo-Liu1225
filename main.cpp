#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;
/* Name: Echo Liu
 * Project: project 3:creating bubblesort
 * Time: Oct.3rd.2019
 * Class: CSC 112
 */

// MergeSort function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd);

// BubbleSort function declaration
void swap (int *a, int *b);
void bubbleSort(int *a, int n);



int main(int argc, char* argv[]) {
    if (argc != 3) {//because we enter two numbers so that our argc can not be longer than 3
        cout << "Limit to enter two numbers. One for seed and one for size"  << endl;
        cout << endl;
        exit(1);
    }

    // get input: first is random seed, second is vector length
    int seed, length;
    seed = atoi(argv[1]);//seed is on the second position of the thing we enter;
    length = atoi(argv[2]);//length is on the third place;
    cout << "Please enter seed and length in terminal:"<< seed << length<< endl;
    srand(seed);

    vector<int> v(length); // vector to be sorted
    vector<int> t(length); // temporary workspace

    // define an integer pointer dynamically allocate an array of integers
    int * a = new int[length];
    int * x = a;
    /* your code here */

    // initialize and print input
    cout << "Unsorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // copy the random list of integers from vector to array

    // int a new array;
    for(int i=0;i<length;i++){
        a[i]=v.at(i);//we change the vector into array
    }/* your code here */

    clock_t start_mergeSort = clock();
    // sort vector using mergeSort
    mergeSort(v,t, 0, v.size() - 1);
    clock_t end_mergeSort = clock();

    // check output, make sure vector is sorted after mergeSort
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }


    clock_t start_bubbleSort = clock();
    // sort array using bubbleSort
    bubbleSort(x,length);//call the bubbleSort here to access the the bubble sort array
    /* your code here */


    clock_t end_bubbleSort = clock();

    // check output, make sure array is sorted after bubbleSort
    for(int i = 1; i < v.size(); i++) {
        assert(a[i-1] <= a[i]);
    }
    /* your code here */


    // print sorted vector after mergeSort
    cout << "Sorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // print sorted array after bubbleSort

    cout << "Bubble Sorted: "<<endl ;
    for(int i = 0 ;i <v.size();i++){
        cout<< a[i]<<'\t';
    }
    cout<<endl;

    // print elapsed time for mergeSort and bubbleSort
    double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;

    cout << " * Elapsed time for sorting a " << length << "-element array: " << endl;
    cout << "  MergeSort: " << elapsed_mergeSort << endl;
    cout << "  BubbleSort: " << elapsed_bubbleSort << endl;



    // unit test for merge
    // print out messages for the comparsion between
    // the original unit test vector's expected sorted vector and the actual one
    cout << "Swap's Unit test" << endl;
    int unitesArr[] = {1, 100};
    int unitesExpectedArr[] = {1000, 1};
    swap(unitesArr[0], unitesArr[1]);

    cout << " Expect array {1, 100} to get {100, 1}" << endl;
    cout << " In fact, we get {";
    for(int i = 0; i < 2; i++) {
        if (i == 0){
            cout << unitesArr[i] << ", ";
        }
        else{
            cout << unitesArr[i] << "}" << endl;
        }
    }
    for(int i = 0; i < 2; i++) {
        assert(unitesArr[i] == unitesExpectedArr[i]);
    }

    //do the bubblesort unit test
    cout << "BubbleSort test" << endl;
    int testArray[] = {1, 2,7,3 , 4 ,6,5};
    int unitExpected[] = {1, 2, 3, 4, 5, 6, 7};

    cout << "Expect array{1, 2,7,3,4,6,5}; to get  {1, 2, 3, 4, 5, 6, 7}" << endl;
    cout << "In fact, we get:{";
    bubbleSort(testArray, 7);
    // print the sorted vector by using a for loop
    for(int i = 0; i < 7; i++) {
        if (i != 6){
            cout << testArray[i] << ", ";
        }
        else{
            cout << testArray[i] << "}" << endl << endl;
        }
    }

    for(int i = 0; i < 7; i++) {
        assert(testArray[i] == unitExpected[i]);
    }



    return 0;
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function
void swap(int *a, int *b) {//defining swap function which is used in the bubbleSort
    int *temp;
    *temp = *a;
    *a = *b;
    *b = *temp;/* your code here */
}

// BubbleSort function
void bubbleSort(int *a, int n) {
    /* your code here */
    for (int i = 0; i < n - 1; i++) {//using for loop to make out the bubble sort list
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}/* your code here */