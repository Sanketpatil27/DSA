#include<iostream>

using namespace std;

int main()
{
    int *a = (int *)malloc(3 * sizeof(int));

    cout << "ENter an array" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (a[i] > a[j])    
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            
        }
        
    }
    cout << "Sorted array: ";

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}