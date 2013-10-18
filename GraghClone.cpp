/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (node==NULL) return NULL;
        
        
        struct NodeParent {
            UndirectedGraphNode * node;
            UndirectedGraphNode *parent;
            NodeParent(UndirectedGraphNode * node_, UndirectedGraphNode * parent_ ){
                node=node_;
                parent=parent_;
            }
        };
        vector <int> label; //to mark node copied
        stack <NodeParent> s;
        UndirectedGraphNode *copynode;
        
        UndirectedGraphNode *head=NULL;
        bool firstnode=true;
        
        //apply dfs
        NodeParent node_p(node,NULL);
        s.push(node_p);
        
        while (!s.empty()){
            NodeParent curnode_p=s.top();
            s.pop();
            
            if (find(label.begin(),label.end(),curnode_p.node->label)==label.end()){//not copied yet
                //copy curnode
                copynode=new UndirectedGraphNode(curnode_p.node->label);
                if (curnode_p.parent!=NULL){
                    curnode_p.parent->neighbors.push_back(copynode);
                } else {head=copynode;}
                
                label.push_back(copynode->label); //copy marked
                //if (firstnode) {head=copynode;firstnode=false;}
                UndirectedGraphNode *parent;
                parent=copynode;
                for (auto it=curnode_p.node->neighbors.begin(); it!=curnode_p.node->neighbors.end(); ++it){

					//check if the node already copied before push in
					if (find(label.begin(),label.end(),(*it)->label)!=label.end()){  //node already copied
						parent->neighbors.push_back(*it);}  //link parent's neghbor to it
					else {
						node_p=NodeParent(*it, parent);
						s.push(node_p);
					}
                }
                
            }
         }
        
        return head;
    }
};