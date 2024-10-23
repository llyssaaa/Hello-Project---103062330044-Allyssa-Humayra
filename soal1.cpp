#include <iostream>

using namespace std;

// Definisi struktur node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menyisipkan node baru di posisi tertentu
void insertAtPosition(Node*& head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Posisi tidak valid." << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Fungsi untuk menampilkan daftar
void displayList(Node* node) {
    int count = 1;
    while (node != nullptr) {
        cout << "node " << count << ":" << node->data << endl;
        node = node->next;
        count++;
    }
}

int main() {
    Node* head = nullptr;
    int n, data, position;

    cout << "Masukkan jumlah node (3 atau lebih): ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Input data untuk node " << i << ": ";
        cin >> data;
        Node* newNode = createNode(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    cout << "Data yang dimasukkan ke dalam daftar adalah:" << endl;
    displayList(head);

    cout << "Masukkan posisi (2 hingga " << n << ") untuk memasukkan node baru: ";
    cin >> position;

    if (position < 1 || position > n + 1) {
        cout << "Posisi tidak valid." << endl;
        return 0;
    }

    cout << "Input data untuk posisi " << position << ": ";
    cin >> data;

    insertAtPosition(head, data, position);

    cout << "Setelah penyisipan, daftar baru adalah:" << endl;
    displayList(head);

    return 0;
}
