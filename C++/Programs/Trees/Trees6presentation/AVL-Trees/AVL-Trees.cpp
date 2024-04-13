// AVL-Trees.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class AVLNode {
private:
    std::string text;
    unsigned int height;
public:
    AVLNode* left_child = nullptr;
    AVLNode* right_child = nullptr;
    AVLNode(std::string t) : text(t), height(1) {};
    // ... 
    AVLNode* AddNode(AVLNode* node);
    AVLNode* SearchNode(std::string text);
    static AVLNode* DeleteNode(AVLNode* root, std::string text);
    int GetBFactor();
    void UpdateHeight();
    AVLNode* RotateRight();
    AVLNode* RotateLeft();
    AVLNode* Balance();
};

int AVLNode::GetBFactor() {
    unsigned int hleft = left_child ? left_child->height : 0;
    unsigned int hright = right_child ? right_child->height : 0;
    return hright - hleft;
}

void AVLNode::UpdateHeight() {
    unsigned int hleft = left_child ? left_child->height : 0;
    unsigned int hright = right_child ? right_child->height : 0;
    height = (hleft > hright ? hleft : hright) + 1;
}

AVLNode* AVLNode::Balance() {
    this->UpdateHeight();
    if (GetBFactor() == 2) {
        if (this->right_child->GetBFactor() < 0)
            this->right_child = this->right_child->RotateRight();
        return this->RotateLeft();
    }
    if (GetBFactor() == -2) {
        if (this->left_child->GetBFactor() > 0)
            this->left_child = this->left_child->RotateLeft();
        return this->RotateRight();
    }
    return this;
}

AVLNode* AVLNode::AddNode(AVLNode* node) {
    if (node->text < this->text) {
        if (!this->left_child)
            this->left_child = node;
        else
            this->left_child->AddNode(node);
    }
    else {
        if (!this->right_child)
            this->right_child = node;
        else
            this->right_child->AddNode(node);
    }
    return Balance();
}

AVLNode* RotateRight() {
    AVLNode* p = p;
    AVLNode* q = p->left_child;
    p->left_child = q->right_child;
    q->right_child = p;

    p->UpdateHeight();
    q->UpdateHeight();

    return q;
}

AVLNode* RotateLeft() {
    AVLNode* q = q;
    AVLNode* p = q->right_child;
    q->right_child = p->left_child;
    p->left_child = q;

    q->UpdateHeight();
    p->UpdateHeight();

    return p;
}
int main()
{
    
    std::cout << "Hello World!\n";
}
