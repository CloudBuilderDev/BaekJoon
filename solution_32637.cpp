// Solution for problem 32637
#include<iostream>
#include<string>
using namespace std;

int main() {
    int capacity;
    int size;
    int is_overflow = 0;
    int underflow_count = 0;
    int big_minus = 0;
    cin >> capacity;
    cin >> size;
    int front_under = 0;  // sum when front underflow
    int* arr = new int[size];
    int sum2 =0;  // fixed sum
    for(int i=0;i<size;i++) {
        cin >> arr[i];
        if(arr[i] < 0 && (sum2 + arr[i] <= 0)) {  // also just zero define underflow ( <= )
            front_under = sum2;
            sum2 = 0;
            underflow_count++;
            if(arr[i] < big_minus) big_minus = arr[i];  // input (-x <= A <= x)
        }
        else if(arr[i] > 0 && (sum2 + arr[i] >= capacity)) { // also just full define overflow ( >= )
            sum2 = capacity;
            is_overflow = 1;
        }
        else sum2 += arr[i];
    }
    int M;
    cin >> M;
    string* this_case = new string[M];

    int* arr2 = new int[M];
    int* arr3 = new int[M]; 
    int* arr4 = new int[M]; // testing 
    
    
    for(int i=0; i<M; i++) {
        int y;
        cin >> y;
        //correct result 
        arr3[i] = y;
        int sum = 0;
        sum += y;
        for(int j=0; j<size; j++) {
            if((sum + arr[j]) < 0) {
                sum = 0;
            }
            else if((sum + arr[j] > capacity)) {
                sum = capacity;
            }
            else {
                sum += arr[j];
            }
        }
        arr2[i] = sum;
        
        //----------------------------------------------------
        //submit code
        if(is_overflow || underflow_count >= 2) {
            arr4[i] = sum2;
            this_case[i] = "is_overflow || underflow_count >= 2";
        }
        else if(underflow_count == 1) {
            int y_=0;
            if(y+front_under > capacity) y_ = capacity;
            else y_ = y+front_under;

            int depended_sum_y = y_ + big_minus;
            if(depended_sum_y<0) arr4[i] = 0;
            else arr4[i] = depended_sum_y;

            this_case[i] = "uderflow_count == 1";
        }
        else{
            arr4[i] = sum2 + y;
            if(arr4[i] > capacity) arr4[i] = capacity;
            else if(arr4[i] < 0) arr4[i] = 0;
            this_case[i] = "no underflow && no overflow";
        }
               
       // cout << arr4[i] << endl;
    }

    for(int i=0; i<M;i++){
       cout <<  to_string(arr3[i]) + " " + to_string(arr2[i]) + " " + to_string(arr4[i] ) + "    | " + this_case[i]<< endl;
       //submit 
       //cout << arr4[i] << endl;
    }
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
}   