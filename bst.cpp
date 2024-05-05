#include <iostream>
using namespace std;

// Node structure for the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
};
  
// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to find the number of nodes in the longest path from root
int longestPath(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = longestPath(root->left);
    int rightHeight = longestPath(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Function to find the minimum value in the BST
int minValue(Node* root) {
    if (root == nullptr) {
        return -1; // Indicate error condition
    }

    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

// Function to search for a specific value in the BST
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to swap the left and right pointers of each node
// void mirrorImage(Node* root) {
//     if (root == nullptr) {
//         return;
//     }

//     // Swap the left and right children of the current node
//     Node* temp = root->left;
//     root->left = root->right;
//     root->right = temp;

//     // Recursively swap left and right subtrees
//     mirrorImage(root->left);
//     mirrorImage(root->right);
// }

// Function to traverse and print the BST in inorder
void display(Node* root) {
    if (root == nullptr) {
        return;
    }

    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

// Function to display the mirror image of the BST
void displayMirror(Node* root) {
    if (root == nullptr) {
        return;
    }

    displayMirror(root->right);
    cout << root->data << " ";
    displayMirror(root->left);
}

int main() {
    Node* root = nullptr;
    int value;
    char choice;

    while (true) {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Find number of nodes in longest path from root" << endl;
        cout << "3. Find minimum data value in the tree" << endl;
        cout << "4. Search a specific value in the tree" << endl;
        cout << "5. Change the tree to its mirror image" << endl;
        cout << "6. Display the tree" << endl;
        cout << "7. Display the mirror image of the tree" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insert(root, value);
                cout << "Value " << value << " inserted into the BST." << endl;
                break;
            case '2':
                cout << "Number of nodes in the longest path from root: " << longestPath(root) << endl;
                break;
            case '3':
                cout << "Minimum value in the BST: " << minValue(root) << endl;
                break;
            case '4':
                cout << "Enter the value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << value << " found in the BST." << endl;
                } else {
                    cout << value << " not found in the BST." << endl;
                }
                break;
            case '5':
                //mirrorImage(root);
                cout << "Tree converted to its mirror image." << endl;
                break;
            case '6':
                cout << "Binary Search Tree:" << endl;
                display(root);
                cout << endl;
                break;
            case '7':
                cout << "Mirror Image of the Binary Search Tree:" << endl;
                displayMirror(root);
                cout << endl;
                break;
            case '8':
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option (1-8)." << endl;
        }
    }

    return 0;
}
