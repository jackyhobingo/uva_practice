#include<iostream>
#include<cstring>

using namespace std;

int array[1024];
int index_offset[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
int sumOfNow = 0;
int numberOfNow = 0;
int inputArray[15];
int sorted_input_array[15];

int get_index(bool component[]) {
    int index = 0;
    for (int i = 0; i < 10; i++) {
        if (component[i]) {
            index += index_offset[i];
        }
    }
    return index;
}

void get_IN_component(bool new_component[], bool component[]) {
    for (int i = 0; i < 10; i++) {
        new_component[i] = new_component[i] | component[i];
    }
}

void get_component(int x, bool arr[]) {
    for (int i = 0; i < 10; i++){
        arr[i] = 0; 
    }
    while(x>0) {
        arr[x%10] = 1;
        x /= 10;
    }
}
bool isNotIn(bool new_component[], bool component[]) {
    for (int i = 0; i < 10; i++) {
         if (new_component[i] & component[i])
             return false;
    }
    return true;
}

void get_iter_component(int x, bool arr[]){
    for (int i=0;i<10;i++) {
        arr[i] = x % 2;
        x /=2;
    }
}

int array_add_to(bool component[]) {
    bool new_component[10];
    int sum = 0;
    bool isBreak = false;
    for (int i = 0; i < 1024; i++) {
        get_iter_component(i, new_component);
        if(isNotIn(new_component, component)) {
            
            int index0 = get_index(new_component); // 不在裡面的 
            get_IN_component(new_component, component);
            if (array[index0]) {
                int index1 = get_index(new_component); // 在裡面的
                sum += array[index0];
               array[index1] += array[index0];
            }
            
        }
    }
    return sum;
}


void count_sum_of_now(int newInt) {

    bool arr[10];
    memset(arr, 0, sizeof(arr));

    for (int i = numberOfNow + 1; i <= newInt; i++) {
        get_component(i, arr);
        array[get_index(arr)] += 1;
        sumOfNow += 1 + array_add_to(arr);
        numberOfNow = i;
    } 

}

void contruct_array() {
    for (int i = 0; i < 1024; i++) {
        array[i] = 0;
    }
}

void test_get_component(int i) {
    bool arr[10];
    memset(arr, 0, sizeof(arr));
    get_component(i,arr);
    for(int j=0;j<10;j++) {
        cout << arr[j];
    }cout << endl;

}

int main()
{
    int T;
    contruct_array();
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int input;
        cin >> input;
        count_sum_of_now(input);
        cout << "Case "<< i << ": " << sumOfNow << endl;
        sumOfNow = 0;
        numberOfNow = 0;
        memset(array,0,sizeof(array));
    }
    
}
