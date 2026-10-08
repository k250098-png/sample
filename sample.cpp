#include <iostream>
#include <string>
using namespace std;

// STEP 1: DEFINE THE STRUCT (Change fields according to question)
struct Item {
    string name;  // e.g., Assignment name, Customer name, Activity
    int keyVal;   // e.g., Due Date, Order Date, Priority, ID, Time
};

// STEP 2: INSERTION SORT
void insertionSort(Item arr[], int n) {
    for (int i = 1; i < n; i++) {
        Item key = arr[i]; // Pick current element struct
        int j = i - 1;

        // NOTE: Use '>' for Ascending (1, 2, 3...)
        // NOTE: Use '<' for Descending (10, 9, 8...)
        while (j >= 0 && arr[j].keyVal > key.keyVal) {
            arr[j + 1] = arr[j]; // Shift element right
            j--;
        }
        arr[j + 1] = key; // Place struct in correct spot
    }
}

// STEP 3A: BINARY SEARCH
int binarySearch(Item arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid].keyVal == target) 
            return mid; // Found! Returns index
        else if (arr[mid].keyVal < target) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1; // Not found
}

// STEP 3B: INTERPOLATION SEARCH (Use if values are evenly spaced/numeric)
int interpolationSearch(Item arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high && target >= arr[low].keyVal && target <= arr[high].keyVal) {
        if (arr[low].keyVal == arr[high].keyVal) {
            if (arr[low].keyVal == target) return low;
            return -1;
        }
        
        // Interpolation Formula
        int pos = low + (((double)(high - low) / (arr[high].keyVal - arr[low].keyVal)) * (target - arr[low].keyVal));
        
        if (arr[pos].keyVal == target) 
            return pos;
        if (arr[pos].keyVal < target) 
            low = pos + 1;
        else 
            high = pos - 1;
    }
    return -1; // Not found
}

// STEP 4: MAIN DRIVER PROGRAM
int main() {
    int n;
    cout << "Enter total number of items: ";
    cin >> n;

    Item arr[100]; // Fixed size array for safety

    // Input Loop
    for (int i = 0; i < n; i++) {
        cout << "Enter name and key value for item " << i + 1 << ": ";
        cin >> arr[i].name >> arr[i].keyVal;
    }

    // 1. Sort the Array
    insertionSort(arr, n);

    cout << "\nSorted Items:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << " -> " << arr[i].keyVal << endl;
    }

    // 2. Search Query
    int searchTarget;
    cout << "\nEnter key value to search: ";
    cin >> searchTarget;

    // Call Binary Search (or swap with interpolationSearch)
    int result = binarySearch(arr, n, searchTarget);

    if (result != -1) {
        cout << "Found: " << arr[result].name << " at index " << result << endl;
    } else {
        cout << "Item not found (-1)" << endl;
    }

    return 0;
}



question 2

#include <iostream>
#include <string>
using namespace std;

// STEP 1: DEFINE NODE STRUCT (Change fields according to question)
struct Node {
    int id;          // e.g., Card Rank, Coefficient, Value, Hanger Number
    string label;   // e.g., Card Suit, Variable, Team Name, Operator
    Node* next;

    Node(int val, string str = "") : id(val), label(str), next(nullptr) {}
};

// STEP 2: INSERT AT TAIL (Appends new elements to list)
void insertAtTail(Node*& head, int val, string str = "") {
    Node* newNode = new Node(val, str);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// STEP 3: DISPLAY LIST TRAVERSAL
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "[" << temp->id << " | " << temp->label << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// STEP 4: STANDARD SCENARIO PROCESSOR (Filters, Modifies, or Calculates)
void processList(Node* head) {
    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        // --- APPLY QUESTION-SPECIFIC LOGIC HERE ---
        // Example: Check condition (even/odd, matching suit, evaluation)
        if (temp->id % 2 == 0) {
            count++;
        }
        
        temp = temp->next; // Move to next node
    }
    cout << "Processing Complete. Result Count: " << count << endl;
}

// STEP 5: MAIN DRIVER PROGRAM
int main() {
    Node* head = nullptr;
    int n, val;
    string str;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter id and label for node " << i + 1 << ": ";
        cin >> val >> str;
        insertAtTail(head, val, str);
    }

    cout << "\nInitial Linked List:\n";
    printList(head);

    cout << "\nProcessing List:\n";
    processList(head);

    return 0;
}

question 3
#include <iostream>
#include <string>
using namespace std;

// ==================== ARRAY STACK ====================
struct Stack {
    int arr[100];
    int top = -1;

    void push(int val) {
        if (top < 99) {
            arr[++top] = val;
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return -1; // Underflow
    }

    int peek() {
        if (top >= 0) return arr[top];
        return -1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

// ==================== ARRAY QUEUE ====================
struct Queue {
    int arr[100];
    int front = 0;
    int rear = 0;

    void enqueue(int val) {
        if (rear < 100) {
            arr[rear++] = val;
        }
    }

    int dequeue() {
        if (front < rear) {
            return arr[front++];
        }
        return -1; // Underflow
    }

    bool isEmpty() {
        return front == rear;
    }
};

// ==================== MAIN DRIVER PROGRAM ====================
int main() {
    Stack st;
    Queue q;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    // 1. Read input and push into Stack
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        st.push(val);
    }

    // 2. Transfer from Stack to Queue (e.g., reversing order or processing)
    while (!st.isEmpty()) {
        int item = st.pop();
        
        // --- APPLY QUESTION-SPECIFIC CONDITION HERE ---
        // Example: Only enqueue positive values or modified values
        q.enqueue(item);
    }

    // 3. Process and Output from Queue
    cout << "\nProcessed Elements from Queue:\n";
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}
