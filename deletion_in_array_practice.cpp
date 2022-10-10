#include<iostream>

using namespace std;

void display(int arr[],int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
}

void indDeletion(int arr[],int ind, int size,int cap)
{   
    if(ind < size && size < cap)
    {
        cout << "\nElement " << arr[ind] << " is deleted" << endl;
        display(arr,size);

        for(int i = ind; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        cout << endl;
        size--;
        display(arr,size);
        cout << "\nDeletion Is Succcessful" << endl;
        
    }    
    else
    {
        cout << "\nDeletion Is Unsuccessful";
    }
}

int main()
{
    int arr[100] = {45,65,3,89,70};
    int size = 5 , index = 4, capacity;
    cout << endl;
    indDeletion(arr,index,size,100);

    return 0;
}