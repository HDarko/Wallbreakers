#include <thread>
int arraySize=10;
vector<int> temp(aarraySize,0);

void MergeSort(vector<int>& temp,vector<int>& array, int lowerBound, int upperBound)
{
    if(lowerBound==upperBound)
    {
        return;
    }
    int mid = (lowerbound+ upperbound) >> 1;
    
    MergeSort( temp,array, lowerBound, mid);
    MergeSort( temp,array, mid+1, upperBound);
    Merge(temp,array, lowerBound, mid+1, upperBound);
    
    
}

void Merge (vector<int>& temp,vector<int>& array int low, int mid, int upper)
{
    int tempLow=low;
    int tempMid= mid-1;
    int index=0;
    while(low<=tempMid && mid<=upper)
    {
        if(array[low] < array[mid])
        {
             tempArray[index++]= array[low++];
        }
        else
        {
             tempArray[index++]= array[mid++];
        }
       
    }
    
      while(low<=tempMid)
    {
        tempArray[index++]= array[low++];
    }
     while(mid<=upper)
    {
        tempArray[index++]= array[mid++];
    }
    
    for (int offset=0; offset<upper-templow+1; offset++)
    {
        array[tempLow+offset]=tempArray[offset];
    }
}
   
 //Create 2 threads for the mergedSort here
thread first(MergeSort,temp,array,0,array.size()/2);
    if (first.joinable())
{
	//main is blocked until funcTest1 is not finished
	first.join();
}


thread second(MergeSort,temp,array,(array.size()/2)+1,array.size()-1);
    if (second.joinable())
{

	second.join();
}
        

