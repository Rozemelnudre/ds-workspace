#include <vector>

using namespace std;
namespace ds_course{

struct Node{
    private:
        int val;
        vector<Node> children;
    public:
        Node(int vv);
        void addChild(Node nn);
        void reflectChildren();
        Node getPreorder(Node nn);
        int getVal();
        vector<int> getChildren();
        vector<int> sortArr;

};
}