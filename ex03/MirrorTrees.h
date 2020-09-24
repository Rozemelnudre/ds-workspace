#include <vector>

using namespace std;
namespace ds_course{

struct Node{
    private:
        int val;
        vector<Node*> children;
    public:
        Node(int vv);
        void addChild(Node* nn);
        void reflectChildren();
        void getPreorder();
        void printChildren();
        int getVal();
        vector<int> getChildren();
        vector<Node*> getChildNodes();
        vector<int> sortArr;

};
}