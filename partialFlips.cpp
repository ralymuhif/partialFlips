#include <iostream>
#include <vector>

using namespace std;
 
// Function that reverse an array
void partialFlip(int arr[], int i)
{
    int start {0};
    int temp {0};
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}
 
// Function that find and return the index of the maximum element in an array
int findMaxArray(int arr[], int n)
{
int maxIndex {0};
for (int i {0}; i < n; ++i)
    if (arr[i] > arr[maxIndex])
            maxIndex = i;
return maxIndex;
}


 
/* Function that sorts the array using partialFlip function
 * and will return an array (used a vector since the size of the array varies)
 * of the k values (the sequence of partial flips) used to sort the array*/
vector <int> sortAlg(int *arr, int n)
{
    vector <int> result;
    /*Looping from the end of the array and reduce the size of the array
     * by one each time
    */
    for (int sizeArray = n; sizeArray > 1;
                               --sizeArray)
    {
        /* Finding the index of the maximum element in the array*/
        int maxIndex = findMaxArray(arr, sizeArray);
 
        /* Moving the maximum element to the end of the array if it's
         * not there already
        */
        if (maxIndex != sizeArray-1)
        {
            //Moving the maximum element at the beginning of the array
            partialFlip(arr, maxIndex);
 
            // Moving now the maximum element at the end of the array
            partialFlip(arr, sizeArray-1);

            // Adding the first K value for the flip in a vector
            result.push_back(maxIndex);

            // Adding the 2nd K value for the flip in a vector
            result.push_back(sizeArray-1);
            
        } 
        
    }
    // Returning the vector result containig the k values
    return result;
}

void printArray (int arr [], int n){
    cout << "[ " << arr[0];
    for (int i = 1; i < n; ++i){
        cout << ", " << arr[i];
    }
    cout << "]" <<endl;
}

void printVector (vector<int> vec) {
    cout << "[ " << vec[0];
    for (int i = 1; i < vec.size(); i++) {
        cout <<", " << vec[i] ;
    }
    cout << "]" <<endl;    
}
 

int main()
{
    // Test 1
    cout << "Test 1: " <<endl;
    int arr[] {3,2,1,4};
    
    /* Finding the number of elements in the array 
     * by dividing the number of bytes of the array with
     * the number of bytes of an element in the array
    */
    int n = sizeof(arr)/sizeof(arr[0]);   
    
    vector<int> kValues;
    cout<<"The unsorted array is : ";
    printArray(arr, n);
    
    kValues = sortAlg(arr, n);
    
    cout<<"The sorted array is : ";
    printArray(arr, n);
    
    cout << "The list of k values is : ";
    printVector(kValues);
    
    // Test 2
    cout <<"\n*************************************" <<endl;
    cout << "Test 2: " <<endl;
    int arr2[] {3,6,1,2,4,7,5};
    
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    cout<<"The unsorted array is : ";
    printArray(arr2, n2);   
    
    vector<int> k2Values;
    k2Values = sortAlg(arr2, n2);
    
    cout<<"The sorted array is : ";
    printArray(arr2, n2);
    
    cout << "The list of k values is : ";
    printVector(k2Values);
    
    // Test 3
    cout <<"\n*************************************" <<endl;
    cout << "Test 3: " <<endl;
    int arr3[] {3, 5, 2, 1, 7, 6, 4};
    
    int n3 = sizeof(arr3)/sizeof(arr3[0]);

    cout<<"The unsorted array is : ";
    printArray(arr3, n3);   
    
    vector<int> k3Values;
    k3Values = sortAlg(arr3, n3);
    
    cout<<"The sorted array is : ";
    printArray(arr3, n3);
    
    cout << "The list of k values is : ";
    printVector(k3Values);
 
    return 0;
}
