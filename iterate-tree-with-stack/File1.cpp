#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <boost/shared_ptr.hpp>
#include <algorithm>
#include <stack>
#include <map>

using namespace boost;
using namespace std;

class Object
{
public:
    Object(const string setName) : objName(setName){};

    string objName;
    multimap<string, shared_ptr<Object> > subObjects;

    void AddSub(const string &name, shared_ptr<Object> sub)
    {
        subObjects.insert(make_pair(name, sub));
    }
};

void iterateTree(const shared_ptr<Object> &currentNode)
{
    stack<shared_ptr<Object> > myStack;
    myStack.push(currentNode);

    cout << "Push to stack: " << currentNode->objName << endl;

    while(myStack.size() > 0)
    {
        shared_ptr<Object> currentObject = myStack.top();
        myStack.pop();

        cout << "Pop out of stack: " << currentObject->objName << endl;

        if(!currentObject->subObjects.empty()){
            multimap<string, shared_ptr<Object> >::const_iterator itrSubObjects = currentObject->subObjects.begin();

            for( ; itrSubObjects != currentObject->subObjects.end(); ++itrSubObjects){
                //cout << itrSubObjects->first << ": [" << &itrSubObjects->second << "]" << endl;
                myStack.push(itrSubObjects->second);
                cout << "Push to stack: " << itrSubObjects->first << endl;
            }
        }
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    shared_ptr<Object> root(new Object("Root Object"));

    shared_ptr<Object> leaf(new Object("Leaf Object"));
    root->AddSub("Leaf Object", leaf);

    shared_ptr<Object> node(new Object("Node Object"));
        shared_ptr<Object> subLeaf(new Object("Sub Leaf Object"));
        shared_ptr<Object> subNode(new Object("Sub Node Object"));
            shared_ptr<Object> subsubLeaf(new Object("Sub Sub Leaf Object"));
            shared_ptr<Object> subsubLeafDuplicate(new Object("Sub Sub Leaf Object"));
            subNode->AddSub("Sub Sub Leaf Object", subsubLeaf);
            subNode->AddSub("Sub Sub Leaf Object", subsubLeafDuplicate);
        node->AddSub("Sub Leaf Object", subLeaf);
        node->AddSub("Sub Node Object", subNode);
    root->AddSub("Node Object", node);

    shared_ptr<Object> node2(new Object("Node 2 Object"));
        shared_ptr<Object> subLeaf2(new Object("Sub Leaf 2 Object"));
        node2->AddSub("Sub Leaf 2 Object", subLeaf2);
    root->AddSub("Node 2 Object", node2);

    iterateTree(root);

    system("pause");
    return 0;
}
