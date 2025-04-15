#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <functional> // For std::function if needed, but maybe not here

class BSTree {
private:
    struct Node {
        int key;
        std::unique_ptr<Node> pLeft;
        std::unique_ptr<Node> pRight;

        Node(int k) : key(k), pLeft(nullptr), pRight(nullptr) {}
    };

    std::unique_ptr<Node> root;

    static bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i = i + 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    bool insertHelper(std::unique_ptr<Node>& node, int x) {
        if (node == nullptr) {
            try {
                node = std::make_unique<Node>(x);
                return true;
            } catch (const std::bad_alloc&) {
                std::cerr << "Memory allocation failed!" << std::endl;
                return false;
            }
        }
        if (x == node->key) {
            return false;
        } else if (x < node->key) {
            return insertHelper(node->pLeft, x);
        } else {
            return insertHelper(node->pRight, x);
        }
    }

    void inorderHelper(const Node* node) const {
        if (node != nullptr) {
            inorderHelper(node->pLeft.get());
            std::cout << node->key << " ";
            inorderHelper(node->pRight.get());
        }
    }

    void postorderHelper(const Node* node) const {
        if (node != nullptr) {
            postorderHelper(node->pLeft.get());
            postorderHelper(node->pRight.get());
            std::cout << node->key << " ";
        }
    }

    void preorderHelper(const Node* node) const {
        if (node != nullptr) {
            std::cout << node->key << " ";
            preorderHelper(node->pLeft.get());
            preorderHelper(node->pRight.get());
        }
    }

     void nrlHelper(const Node* node) const {
        if (node != nullptr) {
            std::cout << node->key << " ";
            nrlHelper(node->pRight.get());
            nrlHelper(node->pLeft.get());
        }
    }

    void rnlHelper(const Node* node) const {
        if (node != nullptr) {
            rnlHelper(node->pRight.get());
            std::cout << node->key << " ";
            rnlHelper(node->pLeft.get());
        }
    }

     void rlnHelper(const Node* node) const {
        if (node != nullptr) {
            rlnHelper(node->pRight.get());
            rlnHelper(node->pLeft.get());
            std::cout << node->key << " ";
        }
    }

    const Node* searchHelper(const Node* node, int x) const {
        if (node == nullptr || node->key == x) {
            return node;
        }
        if (x < node->key) {
            return searchHelper(node->pLeft.get(), x);
        } else {
            return searchHelper(node->pRight.get(), x);
        }
    }

    bool checkSiblingsHelper(const Node* node, int a, int b) const {
        if (node == nullptr || a == b) return false;

        bool found = false;
        if (node->pLeft != nullptr && node->pRight != nullptr) {
            if ((node->pLeft->key == a && node->pRight->key == b) ||
                (node->pLeft->key == b && node->pRight->key == a)) {
                return true;
            }
        }

        if (node->pLeft != nullptr && a < node->key && b < node->key) {
             found = checkSiblingsHelper(node->pLeft.get(), a, b);
        }
        if (!found && node->pRight != nullptr && a > node->key && b > node->key) {
             found = checkSiblingsHelper(node->pRight.get(), a, b);
        }
        return found;
    }


    int countNodesHelper(const Node* node) const {
        if (node == nullptr) return 0;
        return 1 + countNodesHelper(node->pLeft.get()) + countNodesHelper(node->pRight.get());
    }

    int countLeavesHelper(const Node* node) const {
        if (node == nullptr) return 0;
        if (node->pLeft == nullptr && node->pRight == nullptr) return 1;
        return countLeavesHelper(node->pLeft.get()) + countLeavesHelper(node->pRight.get());
    }

    int countOneChildHelper(const Node* node) const {
         if (node == nullptr) return 0;
         int count = ((node->pLeft != nullptr) != (node->pRight != nullptr));
         return count + countOneChildHelper(node->pLeft.get()) + countOneChildHelper(node->pRight.get());
    }

     int countFullNodesHelper(const Node* node) const {
         if (node == nullptr) return 0;
         int count = (node->pLeft != nullptr && node->pRight != nullptr);
         return count + countFullNodesHelper(node->pLeft.get()) + countFullNodesHelper(node->pRight.get());
     }

     int countEvenNodesHelper(const Node* node) const {
         if (node == nullptr) return 0;
         int count = (node->key % 2 == 0) ? 1 : 0;
         return count + countEvenNodesHelper(node->pLeft.get()) + countEvenNodesHelper(node->pRight.get());
     }

     int countEvenLeavesHelper(const Node* node) const {
         if (node == nullptr) return 0;
         int count = 0;
         if(node->pLeft == nullptr && node->pRight == nullptr && node->key % 2 == 0) {
             count = 1;
         }
         return count + countEvenLeavesHelper(node->pLeft.get()) + countEvenLeavesHelper(node->pRight.get());
     }


    long long sumHelper(const Node* node) const {
        if (node == nullptr) return 0;
        return node->key + sumHelper(node->pLeft.get()) + sumHelper(node->pRight.get());
    }

    long long sumOneChildHelper(const Node* node) const {
         if (node == nullptr) return 0;
         long long current_sum = 0;
         if ((node->pLeft != nullptr) != (node->pRight != nullptr)) {
              current_sum = node->key;
         }
         return current_sum + sumOneChildHelper(node->pLeft.get()) + sumOneChildHelper(node->pRight.get());
    }

    long long sumOneChildPrimeHelper(const Node* node) const {
         if (node == nullptr) return 0;
         long long current_sum = 0;
         if (((node->pLeft != nullptr) != (node->pRight != nullptr)) && isPrime(node->key)) {
              current_sum = node->key;
         }
         return current_sum + sumOneChildPrimeHelper(node->pLeft.get()) + sumOneChildPrimeHelper(node->pRight.get());
     }

    int heightHelper(const Node* node) const {
        if (node == nullptr) return -1;
        return 1 + std::max(heightHelper(node->pLeft.get()), heightHelper(node->pRight.get()));
    }

    Node* findMinHelper(Node* node) const {
         if (node == nullptr) return nullptr;
         while (node->pLeft != nullptr) {
             node = node->pLeft.get();
         }
         return node;
     }

    std::unique_ptr<Node> deleteNodeHelper(std::unique_ptr<Node> node, int x) {
        if (node == nullptr) return nullptr;

        if (x < node->key) {
            node->pLeft = deleteNodeHelper(std::move(node->pLeft), x);
        } else if (x > node->key) {
            node->pRight = deleteNodeHelper(std::move(node->pRight), x);
        } else {
            if (node->pLeft == nullptr) {
                return std::move(node->pRight);
            } else if (node->pRight == nullptr) {
                return std::move(node->pLeft);
            } else {
                Node* minNode = findMinHelper(node->pRight.get());
                node->key = minNode->key;
                node->pRight = deleteNodeHelper(std::move(node->pRight), minNode->key);
            }
        }
        return node;
    }

    bool areIdenticalHelper(const Node* node1, const Node* node2) const {
        if (node1 == nullptr && node2 == nullptr) return true;
        if (node1 == nullptr || node2 == nullptr) return false;

        return (node1->key == node2->key &&
                areIdenticalHelper(node1->pLeft.get(), node2->pLeft.get()) &&
                areIdenticalHelper(node1->pRight.get(), node2->pRight.get()));
    }


public:
    BSTree() : root(nullptr) {}

    bool insert(int x) {
        return insertHelper(root, x);
    }

    void buildTree() {
        int n, x;
        std::cout << "Nhap so phan tu cay: ";
        std::cin >> n;
        root = nullptr;
        std::cout << "Nhap " << n << " gia tri: ";
        for (int i = 0; i < n; ++i) {
            std::cin >> x;
            insert(x);
        }
    }

    void inorder() const {
        inorderHelper(root.get());
        std::cout << std::endl;
    }

    void postorder() const {
        postorderHelper(root.get());
        std::cout << std::endl;
    }

    void preorder() const {
        preorderHelper(root.get());
        std::cout << std::endl;
    }

     void nrl() const {
        nrlHelper(root.get());
        std::cout << std::endl;
    }

    void rnl() const {
        rnlHelper(root.get());
        std::cout << std::endl;
    }

    void rln() const {
        rlnHelper(root.get());
        std::cout << std::endl;
    }

    bool search(int x) const {
        return searchHelper(root.get(), x) != nullptr;
    }

    bool checkSiblings(int a, int b) const {
        return checkSiblingsHelper(root.get(), a, b);
    }

    int countNodes() const {
        return countNodesHelper(root.get());
    }

     int countLeaves() const {
        return countLeavesHelper(root.get());
    }

     int countOneChildNodes() const {
         return countOneChildHelper(root.get());
     }

     int countFullNodes() const {
         return countFullNodesHelper(root.get());
     }

      int countEvenNodes() const {
         return countEvenNodesHelper(root.get());
     }

     int countEvenLeaves() const {
         return countEvenLeavesHelper(root.get());
     }

    long long sumAllNodes() const {
        return sumHelper(root.get());
    }

    long long sumOneChildNodes() const {
        return sumOneChildHelper(root.get());
    }

     long long sumOneChildPrimeNodes() const {
         return sumOneChildPrimeHelper(root.get());
     }


    int height() const {
        return heightHelper(root.get());
    }

    const int* findMin() const {
         const Node* minNode = findMinHelper(root.get());
         return (minNode != nullptr) ? &(minNode->key) : nullptr;
    }

    void deleteNode(int x) {
       root = deleteNodeHelper(std::move(root), x);
    }

    bool areIdentical(const BSTree& otherTree) const {
         return areIdenticalHelper(this->root.get(), otherTree.root.get());
    }

};


int main() {
    BSTree t1;
    int x, a, b;

    t1.buildTree();

    std::cout << "Inorder (LNR) traversal: ";
    t1.inorder();
    std::cout << "Postorder (LRN) traversal: ";
    t1.postorder();
    std::cout << "Preorder (NLR) traversal: ";
    t1.preorder();
    std::cout << "NRL traversal: ";
    t1.nrl();
    std::cout << "RNL traversal: ";
    t1.rnl();
    std::cout << "RLN traversal: ";
    t1.rln();

    std::cout << "Enter a value to search: ";
    std::cin >> x;
    if (t1.search(x)) {
        std::cout << x << " is found in the tree." << std::endl;
    } else {
        std::cout << x << " is not found in the tree." << std::endl;
    }

    std::cout << "Enter two values to check if they are siblings: ";
    std::cin >> a >> b;
    if (t1.checkSiblings(a, b)) {
        std::cout << a << " and " << b << " are siblings." << std::endl;
    } else {
        std::cout << a << " and " << b << " are not siblings." << std::endl;
    }

    std::cout << "Number of nodes: " << t1.countNodes() << std::endl;
    std::cout << "Number of leaf nodes: " << t1.countLeaves() << std::endl;
    std::cout << "Number of nodes with one child: " << t1.countOneChildNodes() << std::endl;
    std::cout << "Number of full nodes: " << t1.countFullNodes() << std::endl;
    std::cout << "Number of even nodes: " << t1.countEvenNodes() << std::endl;
    std::cout << "Number of even leaf nodes: " << t1.countEvenLeaves() << std::endl;
    std::cout << "Sum of all node values: " << t1.sumAllNodes() << std::endl;
    std::cout << "Sum of nodes with one child: " << t1.sumOneChildNodes() << std::endl;
    std::cout << "Sum of prime nodes with one child: " << t1.sumOneChildPrimeNodes() << std::endl;
    std::cout << "Height of the tree: " << t1.height() << std::endl;

    const int* minValPtr = t1.findMin();
    if (minValPtr) {
        std::cout << "Minimum value in the tree: " << *minValPtr << std::endl;
    } else {
        std::cout << "The tree is empty." << std::endl;
    }

    std::cout << "Enter a value to delete: ";
    std::cin >> x;
    int nodes_before = t1.countNodes();
    t1.deleteNode(x);
    int nodes_after = t1.countNodes();

    if (nodes_before > nodes_after || (nodes_before == nodes_after && !t1.search(x)) ) { // Crude check
         std::cout << x << " process handled (check tree state)." << std::endl;
         std::cout << "Inorder traversal after delete attempt: ";
         t1.inorder();
    } else {
         std::cout << x << " was not found or deletion failed." << std::endl;
    }


    std::cout << "\nBuilding second tree for comparison..." << std::endl;
    BSTree t2;
    t2.buildTree();

    std::cout << "Comparing tree 1 and tree 2..." << std::endl;
    if (t1.areIdentical(t2)) {
        std::cout << "The trees are identical." << std::endl;
    } else {
        std::cout << "The trees are not identical." << std::endl;
    }

    return 0;
}