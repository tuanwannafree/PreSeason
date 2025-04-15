#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <limits>
#include <stdexcept> // Optional: for handling potential allocation errors

// Minimal necessary includes
#include <iostream>
#include <string>
#include <memory>   // For std::unique_ptr
#include <limits>   // For std::numeric_limits

class Dictionary {
private:
    struct Node {
        std::string english;
        std::string vietnamese;
        std::unique_ptr<Node> pLeft;
        std::unique_ptr<Node> pRight;

        Node(const std::string& eng, const std::string& vie)
            : english(eng), vietnamese(vie), pLeft(nullptr), pRight(nullptr) {}
    };

    std::unique_ptr<Node> root;

    bool insertHelper(std::unique_ptr<Node>& node, const std::string& eng, const std::string& vie) {
        if (node == nullptr) {
             try {
                node = std::make_unique<Node>(eng, vie);
                return true;
            } catch (const std::bad_alloc&) {
                 std::cerr << "Error: Memory allocation failed!" << std::endl;
                 return false;
            }
        }

        if (eng == node->english) {
            return false;
        } else if (eng < node->english) {
            return insertHelper(node->pLeft, eng, vie);
        } else {
            return insertHelper(node->pRight, eng, vie);
        }
    }

    Node* searchHelper(Node* node, const std::string& eng) const {
        if (node == nullptr) {
            return nullptr;
        }

        if (eng == node->english) {
            return node;
        } else if (eng < node->english) {
            return searchHelper(node->pLeft.get(), eng);
        } else {
            return searchHelper(node->pRight.get(), eng);
        }
    }

    void printLNRHelper(const Node* node) const {
        if (node != nullptr) {
            printLNRHelper(node->pLeft.get());
            std::cout << node->english << " : " << node->vietnamese << std::endl;
            printLNRHelper(node->pRight.get());
        }
    }

    bool isEmptyHelper() const {
        return root == nullptr;
    }


public:
    Dictionary() : root(nullptr) {}

    int insertWord(const std::string& eng, const std::string& vie) {
         bool success_flag = false;
         // Handle the case where the root itself might fail allocation
         if (root == nullptr) {
             try {
                 root = std::make_unique<Node>(eng, vie);
                 return 1; // Success
             } catch (const std::bad_alloc&) {
                  std::cerr << "Error: Memory allocation failed for root!" << std::endl;
                  return -1; // Memory error
             }
         }

         // If root exists, use the helper
         if (eng == root->english) return 0; // Already exists at root
         if (eng < root->english) {
            success_flag = insertHelper(root->pLeft, eng, vie);
         } else {
            success_flag = insertHelper(root->pRight, eng, vie);
         }

         if (success_flag) return 1; // Successfully inserted by helper
         // If not successful, it could be 'already exists' or 'memory error' from helper
         // Check if the node exists to differentiate (searchHelper is const, safe to call)
         if (searchHelper(root.get(), eng) != nullptr) {
             return 0; // Already exists
         } else {
             return -1; // Assumed memory error based on helper's behavior
         }
    }


    const std::string* lookupWord(const std::string& eng) const {
        Node* foundNode = searchHelper(root.get(), eng);
        if (foundNode != nullptr) {
            return &(foundNode->vietnamese);
        } else {
            return nullptr;
        }
    }

    bool updateWord(const std::string& eng, const std::string& newVie) {
        Node* foundNode = searchHelper(root.get(), eng);
        if (foundNode != nullptr) {
            foundNode->vietnamese = newVie;
            return true;
        } else {
            return false;
        }
    }

    void printAllWords() const {
        printLNRHelper(root.get());
    }

    bool isEmpty() const {
       return isEmptyHelper();
    }
};

void ShowMenu() {
    std::cout << "\n===== TU DIEN ANH-VIET (BST - Modern C++) =====" << std::endl;
    std::cout << "1. Them tu moi" << std::endl;
    std::cout << "2. Tra cuu nghia" << std::endl;
    std::cout << "3. Sua nghia cua tu" << std::endl;
    std::cout << "4. In toan bo tu dien (A-Z)" << std::endl;
    std::cout << "0. Thoat chuong trinh" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "Nhap lua chon cua ban: ";
}

int main() {
    Dictionary dict;
    int choice;
    std::string english, vietnamese, newMeaning;
    const std::string* meaningPtr;

    dict.insertWord("hi", "xin chao");
    dict.insertWord("cat", "meo");
    dict.insertWord("dog", "cho");
    dict.insertWord("walk", "di bo"); // Changed slightly for variation
    dict.insertWord("run", "chay");

    do {
        ShowMenu();
        // Basic input validation
        while (!(std::cin >> choice)) {
             std::cout << "Nhap khong hop le. Vui long nhap mot so: ";
             std::cin.clear();
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume newline

        switch (choice) {
            case 1:
                std::cout << "Nhap tu tieng Anh can them: ";
                getline(std::cin, english);
                std::cout << "Nhap nghia tieng Viet: ";
                getline(std::cin, vietnamese);
                {
                    int res = dict.insertWord(english, vietnamese);
                    if (res == 1) {
                        std::cout << "Them tu thanh cong!" << std::endl;
                    } else if (res == 0) {
                        std::cout << "Loi: Tu '" << english << "' da ton tai!" << std::endl;
                    } else {
                         std::cout << "Loi: Khong the them tu (loi bo nho?)" << std::endl;
                    }
                }
                break;
            case 2:
                std::cout << "Nhap tu tieng Anh can tra cuu: ";
                getline(std::cin, english);
                meaningPtr = dict.lookupWord(english);
                if (meaningPtr != nullptr) {
                    std::cout << "Nghia cua '" << english << "' la: " << *meaningPtr << std::endl;
                } else {
                    std::cout << "Khong tim thay tu '" << english << "' trong tu dien." << std::endl;
                }
                break;
            case 3:
                std::cout << "Nhap tu tieng Anh can sua nghia: ";
                getline(std::cin, english);
                std::cout << "Nhap nghia tieng Viet moi: ";
                getline(std::cin, newMeaning);
                if (dict.updateWord(english, newMeaning)) {
                    std::cout << "Cap nhat nghia cho tu '" << english << "' thanh cong!" << std::endl;
                } else {
                    std::cout << "Loi: Khong tim thay tu '" << english << "' de sua." << std::endl;
                }
                break;
            case 4:
                std::cout << "\n--- Danh sach tu dien (A-Z) ---" << std::endl;
                 if (dict.isEmpty()) {
                     std::cout << "(Tu dien rong)" << std::endl;
                 } else {
                     dict.printAllWords();
                 }
                std::cout << "-------------------------------" << std::endl;
                break;
            case 0:
                std::cout << "Dang thoat chuong trinh..." << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long chon lai." << std::endl;
        }
         if (choice != 0) {
              std::cout << "\nNhan Enter de tiep tuc...";
              // Wait for user to press Enter - Peek checks without consuming if buffer is empty
              while (std::cin.peek() != '\n' && std::cin.peek() != EOF) {
                  std::cin.ignore();
              }
              // If buffer was empty (just Enter pressed), ignore consumes the Enter.
              // If buffer had content cleared by previous ignore, this ignore waits for Enter.
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         }

    } while (choice != 0);

    // No need to call deleteDic, unique_ptr handles cleanup automatically
    return 0;
}