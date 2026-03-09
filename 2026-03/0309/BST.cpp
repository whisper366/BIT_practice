#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

template<typename T>

struct treeNode{
    T data;
    treeNode<T>* left;
    treeNode<T>* right;
    struct BSTNode *left,*right;
};

template<typename T>
class Tree{
    private:
    treeNode<T> *root;
    //插入
    treeNode<T>* insert(treeNode<T>* node, T value){
        if(node==nullptr){
            return new treeNode<T>(value);
        }
        if(value<node->data){
            node->left=insert(node->left,value);
        }
        else if(value>node->data){
            node->right=insert(node->right,value);
        }
        return node;
    }

    //删除
    //首先寻找最小值点
    treeNode<T>*findMin(treeNode<T>*node){
        if(node==nullptr){
            return nullptr;
        }
        while(node->left){
            node=node->left;
        }
        return node;
    }
    //递归删除
    treeNode<T>* delete(treeNode<T>*node,T key){
        if(node==nullptr) return nullptr;

        if(key<node->data){
            node->left=delete(node->left,key);
        }
        else if(key>node->data){
            node->right=delete(node->right,key);
        }
        else{
            //找到了要删除的结点
            if(node->left==nullptr){
                treeNode temp=node->right;
                delete node;
                return temp;
            }
            else if(node->right==nullptr){
                treeNode temp=node->left;
                delete node;
                return temp;
            }
            else{
                //有两个子节点:找右侧最小的（后继）进行替换
                treeNode<T> *minNode=findMin(node->right);
                node->key=minNode->key;
                node->right=delete(node->right,minNode->key);
            }
        }
        return node;
    }

    //中序遍历 输出二叉树
    void inOrder(treeNode<T>* node){
        if(node!=nullptr){
            inOrder(node->left);
            cout<<node->data<<" ";
            inOrder(node->right);
        }
    }

    //释放内存
    void distroy(treeNode<T>* node){
        if(node!=nullptr){
            distroy(node->left);
            distroy(node->right);
            delete node;
        }
    }

    public:
    Tree():node(nullptr){}; //构造函数体，初始化已经在前面完成，故为空
    ~Tree(){
        destroy(node);
    }

    void insert(T value){
        //调用private中的函数，用户只需传值，无需考虑内部如何递归
        node=insert(node,value);    
    }

    void deleteNode(T value){
        node=delete(node,value);
    }

    void printinOrder(){
        cout<<"当前二叉树（中序遍历）:"<<endl;
        inOrder(node);
        cout<<endl;
    }

};

int main(){
    Tree<int>tree;

    //输入
    string line;
    int num;
    cout<<"请输入二叉树的元素（空格分隔，回车结束）:"<<endl;
    getline(cin,line);
    istringstream iss(line);

    while(iss>>num){
        tree.insert(num);
    }

    //初始化树
    tree.printinOrder();

    //读取要插入的数字
    int insertVal;
    cout<<"请输入要插入的数字："<<endl;
    cin>>insertVal;
    tree.insert(insertVal);
    cout<<"插入"<<insertVal<<"之后："<<endl;
    tree.printinOrder();

    //读取要删除的数字
    int deleteVal;
    cout << "请输入要删除的数字: ";
    cin >> deleteVal;
    tree.deleteNode(deleteVal);
    cout << "删除 " << deleteVal << " 后";
    tree.printinOrder();

    return 0;
}
