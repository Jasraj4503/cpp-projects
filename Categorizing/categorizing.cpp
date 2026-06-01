#include <iostream>
using namespace std;

class Algorithm
{
private:
    int arr[100];
    int n;

public:
    void inputArray()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    void displayArray()
    {
        cout << "Array: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Selection Sort
    void selectionSort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;

            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }

            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        cout << "Array sorted using Selection Sort.\n";
        displayArray();
    }

    // Merge Function
    void merge(int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[100], R[100];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];

        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Merge Sort
    void mergeSort(int left, int right)
    {
        if (left < right)
        {
            int mid = (left + right) / 2;

            mergeSort(left, mid);
            mergeSort(mid + 1, right);

            merge(left, mid, right);
        }
    }

    void runMergeSort()
    {
        mergeSort(0, n - 1);
        cout << "Array sorted using Merge Sort.\n";
        displayArray();
    }

    // Linear Search
    void linearSearch()
    {
        int key;
        cout << "Enter element to search: ";
        cin >> key;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                cout << "Element found at position "
                     << i + 1 << endl;
                return;
            }
        }

        cout << "Element not found.\n";
    }

    // Binary Search
    void binarySearch()
    {
        int key;
        cout << "Enter element to search: ";
        cin >> key;

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == key)
            {
                cout << "Element found at position "
                     << mid + 1 << endl;
                return;
            }
            else if (arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << "Element not found.\n";
    }

    int getSize()
    {
        return n;
    }
};

int main()
{
    Algorithm obj;

    obj.inputArray();

    int choice;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Display Array\n";
        cout << "2. Selection Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Linear Search\n";
        cout << "5. Binary Search\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.displayArray();
            break;

        case 2:
            obj.selectionSort();
            break;

        case 3:
            obj.runMergeSort();
            break;

        case 4:
            obj.linearSearch();
            break;

        case 5:
            cout << "Note: Binary Search requires sorted array.\n";
            obj.binarySearch();
            break;

        case 6:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}