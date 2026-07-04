#include <iostream>
using namespace std;

int ArrayAddition(int *array, int size)
{
    int sum = 0;
    int i;
    for (i = 0; i < size;i++){
        sum += array[i];  
    }
    return sum;
}

int main()
{
    int array[]={0,1,2,3,4,5,6,7,8,9,10};
    int sum = ArrayAddition(array, sizeof(array)/sizeof(array[0]));

    cout<<"result is "<< sum <<endl;
    return 0;    
}
