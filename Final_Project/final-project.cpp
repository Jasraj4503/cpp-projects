#include <iostream>
using namespace std;

// ---------------- LINKED LIST ----------------
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *head = NULL;

void insertNode(int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void displayList()
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *curr = head;

    while (curr->next != NULL && curr->next->data != value)
    {
        curr = curr->next;
    }

    if (curr->next == NULL)
    {
        cout << "Value not found\n";
        return;
    }

    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

// ---------------- MERGE SORT ----------------
void merge(int arr[], int left, int mid, int right)
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
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// ---------------- QUICK SORT ----------------
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------------- BINARY SEARCH ----------------
int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// ---------------- MAIN ----------------
int main()
{
    int arr[100];
    int n = 0;

    int choice;

    do
    {
        cout << "\n===== DATA STRUCTURE PROJECT =====\n";
        cout << "1. Insert in Linked List\n";
        cout << "2. Delete from Linked List\n";
        cout << "3. Display Linked List\n";
        cout << "4. Enter Array\n";
        cout << "5. Merge Sort\n";
        cout << "6. Quick Sort\n";
        cout << "7. Binary Search\n";
        cout << "8. Display Array\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter Value: ";
            cin >> value;
            insertNode(value);
            break;
        }

        case 2:
        {
            int value;
            cout << "Enter Value to Delete: ";
            cin >> value;
            deleteNode(value);
            break;
        }

        case 3:
            displayList();
            break;

        case 4:
        {
            cout << "Enter Size: ";
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            break;
        }

        case 5:
            mergeSort(arr, 0, n - 1);
            cout << "Array Sorted using Merge Sort\n";
            break;

        case 6:
            quickSort(arr, 0, n - 1);
            cout << "Array Sorted using Quick Sort\n";
            break;

        case 7:
        {
            int key;
            cout << "Enter Value to Search: ";
            cin >> key;

            int pos = binarySearch(arr, n, key);

            if (pos != -1)
                cout << "Found at Index " << pos << endl;
            else
                cout << "Not Found\n";

            break;
        }

        case 8:
        {
            cout << "Array: ";

            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";

            cout << endl;
            break;
        }

        case 0:
            cout << "Program Ended\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 0);

    return 0;
}