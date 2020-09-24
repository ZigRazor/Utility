#include "Graph.hpp"
namespace CXXGRAPH
{
    namespace BASESTRUCT
    {
        Graph::Graph()
        {
        }
        
        Graph::Graph(std::set<Link> &linkSet) 
        {
            
        }
        
        Graph::Graph(std::set<Node> &nodeSet) 
        {
            
        }

        Graph::~Graph()
        {
        }
        
        const std::set<Link>& Graph::getLinkSet() const
        {
            return linkSet;
        }
        
        const std::set<Node>& Graph::getNodeSet() const
        {
            return nodeSet;
        }
        
        void Graph::addNode(Node &node) 
        {
            
        }
        
        void Graph::addLink(Link &link) 
        {
            
        }
        
        void Graph::deleteNode(Node &node) 
        {
            
        }
        
        void Graph::deleteLink(Link &link) 
        {
            
        }
        
        void Graph::clearGraph() 
        {
            nodeSet.clear();
            linkSet.clear();
        }
        
        void Graph::recreateGraph(std::set<Link> &linkSet) 
        {
            
        }
        
        void Graph::recreateGraph(std::set<Node> &nodeSet) 
        {
            
        }
        
        unsigned int Graph::getNumberOfLink() const
        {
            return linkSet.size();
        }
        
        unsigned int Graph::getNumberOfNode() const
        {
            return nodeSet.size();
        }
    } // namespace BASESTRUCT
} // namespace CXXGRAPH
