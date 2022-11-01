#include <cstddef>
#include <iostream>
#include <queue>

template <typename T>
struct treeNode
{
    T *data;
    struct treeNode *left;
    struct treeNode *right;
};

/*prints the binary tree in 2-Dimensions */
template <typename T>
void printTree(treeNode<T> *root, int space)
{
    if (root == nullptr)
    {
        return;
    }
    space += 10;
    printTree(root->right, space);
    std::cout << std::endl;
    for (int i = 10; i < space; i++)
    {
        std::cout << " ";
    }
    std::cout << *(root->data) << std::endl;
    printTree(root->left, space);
}

//requires: the root of the tree and a generic value 
//effects: function which will add a node of that generic value at the highest possible level in the tree, for example
/*  1           1
  2   3 ->   2     3
4   5      4   5  6  
the left child before the right child if both are null.*/

template <typename T>
void addNode(treeNode<T> *&root, T &data)
{
    if (root == nullptr) { //intialize a root if there is no nodes at all 
        root = new treeNode<T>;
        root->data = &data;
        root->left = nullptr;
        root->right = nullptr;
    }
    else{ 
        std::queue<treeNode<T> *> q; 
        q.push(root);

        while (!q.empty()){

            treeNode<T> *temp = q.front();
            q.pop();
            if (temp->left != nullptr) { q.push(temp->left); }

            else { addNode(temp->left, data); break; }

            if (temp->right != nullptr) { q.push(temp->right); }

            else { addNode(temp->right, data); break; }
        }
    }
}

//requires: The root of the tree and a generic value 
//effects: function will delete a node that contains the generic value only if it is a leaf node with no children
//         otherwise it prints "CANNOT DELETE NODE" 
template <typename T>
void deleteNode(treeNode<T> *&root, T &data) {
    if (root == nullptr) return;

    else {

        if (root->data == &data) {
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    root = nullptr;
                }
                else std::cout << "CANNOT DELETE NODE" << std::endl;
            }
        else {
            deleteNode(root->left, data);
            deleteNode(root->right, data);
        }
       
    }
}

//requires: the root of the tree
//effects: prints zero if the root = nullptr
//         otherwise the number of the nodes in the tree including the root
template <typename T>
int treeSize(treeNode<T> *root) {
    if (root == nullptr) return 0;

    else return 1 + treeSize(root->left) + treeSize(root->right);
}

//requires: the root of the tree and an int or a char
//effects: return the size of the tree rooted at that node (if the node is found) 
//         0 otherwise  
template <typename T>
int subtreeSize(treeNode<T> *&root, T &data) {
    if (root == nullptr) return 0;

    else {
        if (root->data == &data) return treeSize(root);

        else return subtreeSize(root->left, data) + subtreeSize(root->right, data);
    }
}

/*The - postOrderPrint - function will do a post order traversal of the tree starting at the root
(and print the content of each node)*/

//requires: the root of the tree
//effects: a post order traversal of the tree starting at the root (and print the content of each node)
template <typename T>
void postOrderPrint(treeNode<T> *&root)
{
    if (root == nullptr) return;

    else {
        postOrderPrint(root->left);
        postOrderPrint(root->right);
        std::cout << *(root->data) << std::endl;
    }
}

//requires: the root of the tree
//effects: a pre order traversal of the tree starting at the root (and print the content of each node).
template <typename T>
void preOrderPrint(treeNode<T> *&root)
{
    if (root == nullptr) return;

    else {
        std::cout << *(root->data) << std::endl;
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
}

//requires: the root of the tree
//effects: a in order traversal of the tree starting at the root (and print the content of each node).
template <typename T>
void inOrderPrint(treeNode<T> *&root)
{
    if (root == nullptr) return;

    else
    {
        inOrderPrint(root->left);
        std::cout << *(root->data) << std::endl;
        inOrderPrint(root->right);
    }
}

int main() {
    //declare an integer root 
    treeNode<int> *root_of_int = nullptr;

    //declare another char root
    treeNode<char> *root_of_char = nullptr;

    //test cases:
        std::cout << "test case of empty tree" << std::endl;

        //First: tree is empty - the root is null
        /******************************treeSize**********************************/
        std::cout << "Tree Size: " << treeSize(root_of_int) << std::endl; //zero
        /******************************treeSize**********************************/

        /**********************delete*******************/
        int x = 64;
        deleteNode(root_of_int, x); //nothing happens
        /**********************delete*******************/

        /*****************traversal*********************/
        std::cout << "Post-Order Print: " << std::endl;
        postOrderPrint(root_of_int);//nothing happens
        std::cout << "Pre-Order Print: " << std::endl;
        preOrderPrint(root_of_int);//nothing happens
        std::cout << "In-Order Print: " << std::endl;
        inOrderPrint(root_of_int);//nothing happens
        /*****************traversal*********************/

        /*********************subtreeSize***************/
        std::cout << "Subtree Size: " << subtreeSize(root_of_int, x) << std::endl;//zero
        /*********************subtreeSize***************/

        std::cout << "test case of int tree" << std::endl;
        std::cout<< "\n"<< std::endl;
        //Second: the trees are not empty

        /**************************************test case of int tree*************************************/
        int first_int = 0;
        int second_int = 3;
        int third_int = 5;
        int forth_int = 7;

        /*****************************add node + treeSize******************************************/
        addNode(root_of_int, first_int);
        std::cout << "Integer Tree Size : " << treeSize(root_of_int) << "\n" << std::endl;//prints 1

        addNode(root_of_int, second_int);
        std::cout << "Integer Tree Size: " << treeSize(root_of_int) << "\n" << std::endl;//prints 2

        addNode(root_of_int, third_int);
        std::cout << "Integer Tree Size: " << treeSize(root_of_int) << "\n" << std::endl;//prints 3

        addNode(root_of_int, forth_int);
        std::cout << "Integer Tree Size: " << treeSize(root_of_int) << "\n" << std::endl;//prints 4
        /*****************************add node + treeSize******************************************/

        printTree(root_of_int, 0);
        /*****************traversal*********************/
        std::cout << "Post-Order Print: " << std::endl;
        postOrderPrint(root_of_int);
        std::cout << "Pre-Order Print: " << std::endl;
        preOrderPrint(root_of_int);
        std::cout << "In-Order Print: " << std::endl;
        inOrderPrint(root_of_int);
        /*****************traversal*********************/
        
        /**********************delete***********************************************************************/
        //if the node is internal
        deleteNode(root_of_int,first_int); //CANNOT DELETE NODE
        deleteNode(root_of_int,second_int); //CANNOT DELETE NODE

        //if node is leaf
        deleteNode(root_of_int,forth_int); //node is deleted
        std::cout << "Integer Tree Size: " << treeSize(root_of_int) << "\n" << std::endl;//prints 3

        //if node is not found
        deleteNode(root_of_int,forth_int); //nothing happens
        std::cout << "Integer Tree Size: " << treeSize(root_of_int) << "\n" << std::endl;//still prints 3
        /**********************delete************************************************************************/

        /*****************traversal*********************/
        std::cout << "Post-Order Print: " << std::endl;
        postOrderPrint(root_of_int); 
        std::cout << "Pre-Order Print: " << std::endl;
        preOrderPrint(root_of_int);
        std::cout << "In-Order Print: " << std::endl;
        inOrderPrint(root_of_int);
        /*****************traversal*********************/

        /*********************subtreeSize**************************************************************************************/
        //if node is root
        std::cout << "Subtree Size: " << subtreeSize(root_of_int, first_int) << std::endl;//behaves as treeSize - prints 3
        
        //if node is an internal node
        std::cout << "Subtree Size: " << subtreeSize(root_of_int, second_int) << std::endl;//prints 1 due to the deleteion of the second node
        
        //if node is leaf
        std::cout << "Subtree Size: " << subtreeSize(root_of_int, third_int) << std::endl;//prints 1

        //if node is not found
        std::cout << "Subtree Size: " << subtreeSize(root_of_int, forth_int) << std::endl;//prints 0
        /*********************subtreeSize*************************************************************************************/

        std::cout<< "\n"<< std::endl;
        /*******************************end of test case of int tree*************************************/

        std::cout << "test case of character tree" << std::endl;


        /**************************************test case of char tree*************************************/
        char first_char = 'a';
        char second_char = 'b';
        char third_char = 'c';
        char forth_char = 'd';

        /*****************************add node + treeSize******************************************/
        addNode(root_of_char , first_char );
        std::cout << "Character Tree Size : " << treeSize(root_of_char ) << "\n" << std::endl;//prints 1

        addNode(root_of_char , second_char );
        std::cout << "Character Tree Size: " << treeSize(root_of_char ) << "\n" << std::endl;//prints 2

        addNode(root_of_char , third_char );
        std::cout << "Character Tree Size: " << treeSize(root_of_char ) << "\n" << std::endl;//prints 3

        addNode(root_of_char , forth_char );
        std::cout << "Character Tree Size: " << treeSize(root_of_char ) << "\n" << std::endl;//prints 4
        /*****************************add node + treeSize******************************************/

        printTree(root_of_char , 0);
        /*****************traversal*********************/
        std::cout << "Post-Order Print : " << std::endl;
        postOrderPrint(root_of_char );
        std::cout << "Pre-Order Print : " << std::endl;
        preOrderPrint(root_of_char );
        std::cout << "In-Order Print : " << std::endl;
        inOrderPrint(root_of_char );
        /*****************traversal*********************/
        
        /**********************delete***********************************************************************/
        //if the node is internal
        deleteNode(root_of_char ,first_char ); //CANNOT DELETE NODE
        deleteNode(root_of_char ,second_char ); //CANNOT DELETE NODE

        //if node is leaf
        deleteNode(root_of_char ,forth_char ); //node is deleted
        std::cout << "Character Tree Size: " << treeSize(root_of_char ) << "\n" << std::endl;//prints 3

        //if node is not found
        deleteNode(root_of_char ,forth_char ); //nothing happens
        std::cout << "Character Tree Size: " << treeSize(root_of_char ) << "\n" << std::endl;//still prints 3
        /**********************delete************************************************************************/

        /*****************traversal*********************/
        std::cout << "Post-Order Print : " << std::endl;
        postOrderPrint(root_of_char ); 
        std::cout << "Pre-Order Print : " << std::endl;
        preOrderPrint(root_of_char );
        std::cout << "In-Order Print : " << std::endl;
        inOrderPrint(root_of_char );
        /*****************traversal*********************/

        /*********************subtreeSize**************************************************************************************/
        //if node is root
        std::cout << "Subtree Size: " << subtreeSize(root_of_char , first_char ) << std::endl;//behaves as treeSize - prints 3
        
        //if node is an internal 
        std::cout << "Subtree Size: " << subtreeSize(root_of_char , second_char ) << std::endl;//prints 1 due to the deleteion of the second node
        
        //if node is leaf
        std::cout << "Subtree Size: " << subtreeSize(root_of_char , third_char ) << std::endl;//prints 1

        //if node is not found
        std::cout << "Subtree Size: " << subtreeSize(root_of_char , forth_char ) << std::endl;//prints 0
        /*********************subtreeSize*************************************************************************************/

        /*******************************end of test case of char tree*************************************/
    return 0;
}
