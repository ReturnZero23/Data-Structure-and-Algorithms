#include <iostream>
#include <time.h>
#include <stdlib.h>

template<typename T>
void BubbleSort(T* array, const int size){
    for(int i = 0; i < size; i++){
        bool flag = false;
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = true;
            }
        }
        if(!flag) break;
    }
};

template<typename T>
void InsertionSort(T* Array, const int size){
    if(size <= 1)return;
    
    for(size_t i = 1; i < size; i++)
    {
        int InsertData = Array[i];
        for(size_t j = 0; j < i; j++)
        {
            if(InsertData < Array[j]){
                for(size_t k = i; k > j; k--)
                {
                    Array[k] = Array[k-1];
                }
                Array[j] = InsertData;
                break;
            }
        }
    }
};

template<typename T>
void SelectionSort(T* Array, const int size){
    
};

template<typename T>
void Merge(T* array, const int indexA, const int sizeA, const int indexB, const int sizeB){
    int* temp =new int[sizeA+sizeB];
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < sizeA && j < sizeB){
        if(array[i + indexA] < array[j + indexB]){
            temp[k] = array[i + indexA];
            i++;
        }else{
            temp[k] = array[j + indexB];
            j++;
        }
        k++;
    }

    while(i < sizeA){
        temp[k] = array[i + indexA];
        i++;
        k++;
    }

    while(j < sizeB){
        temp[k] = array[j + indexB];
        j++;
        k++;
    }

    int size = sizeA + sizeB;
    for(int i = 0; i < size; i++){
        array[indexA + i] = temp[i];
    };
}

template<typename T>
void MergeSortInner(T* Array, const int indexA, const int indexB){
    if((indexB-indexA) == 0) return;
    if((indexB-indexA) == 1){
        if(Array[indexA] > Array[indexB]){
            int temp = Array[indexA];
            Array[indexA] = Array[indexB];
            Array[indexB] = temp;
        }
        return;
    }

    int midIndex = static_cast<int>((indexB - indexA)/2.0) + indexA;
    MergeSortInner(Array,indexA,midIndex);
    MergeSortInner(Array,midIndex + 1,indexB);

    Merge(Array,indexA, midIndex-indexA+1, midIndex + 1, indexB-midIndex);
    return;
};

template<typename T>
void MergeSort(T* Array, const int size){
    MergeSortInner(Array,0,size-1);
};



#define SIZE 100000

int main(){
    srand((unsigned)time(NULL));
    int Array1[SIZE];
    for(size_t i = 0; i < SIZE; i++)
        Array1[i] = rand()%200;

    clock_t start_time=clock();
    BubbleSort(Array1,SIZE);
    clock_t end_time=clock();
    for(int i = 0 ; i < SIZE ; i++){
        //std::cout << Array1[i] << ",";
    }
    std::cout << std::endl;
    std::cout<< SIZE << " Elements Bubble sort Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<std::endl;

    int Array2[SIZE];
    for(size_t i = 0; i < SIZE; i++)
        Array2[i] = rand()%200;
    start_time=clock();
    InsertionSort(Array2,SIZE);
    end_time=clock();
    for(int i = 0 ; i < SIZE ; i++){
        //std::cout << Array2[i] << ",";
    }
    std::cout << std::endl;
    std::cout<< SIZE << " Elements Insertion Sort Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<std::endl;

    int Array3[SIZE];
    for(size_t i = 0; i < SIZE; i++)
        Array3[i] = rand()%200;
    start_time=clock();
    MergeSort(Array3,SIZE);
    end_time=clock();
    for(int i = 0 ; i < SIZE ; i++){
        //std::cout << Array3[i] << ",";
    }
    std::cout << std::endl;
    std::cout<< SIZE << " Elements Merge Sort Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<std::endl;
    return 0;
}