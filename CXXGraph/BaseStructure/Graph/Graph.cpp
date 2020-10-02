#include "Graph.hpp"
namespace CXXGRAPH
{
    namespace BASESTRUCT
    {
        Graph::Graph()
        {
        }

        Graph::Graph(std::set<Link *> &linkSet)
        {
            std::set<Link *>::const_iterator linkSetIt;
            for (linkSetIt = linkSet.begin(); linkSetIt != linkSet.end(); ++linkSetIt)
            {
                this->linkSet[(*linkSetIt)->getId()] = *linkSetIt;
                Node *from = new Node((*linkSetIt)->getFrom()->getId());
                Node *to = new Node((*linkSetIt)->getTo()->getId());
                //insert From
                if (isNodeInGraph(from))
                { //Node already exist add only link ot the node
                    nodeSet.at(from->getId())->addLink(*linkSetIt);
                }
                else
                {
                    from->addLink(*linkSetIt);
                    addNode(from);
                }
                //insert To
                if (isNodeInGraph(to))
                { //Node already exist add only link ot the node
                    nodeSet.at(to->getId())->addLink(*linkSetIt);
                }
                else
                {
                    to->addLink(*linkSetIt);
                    addNode(to);
                }
            }
        }

        Graph::Graph(std::set<Node *> &nodeSet)
        {
            std::set<Node *>::const_iterator nodeSetIt;
            for (nodeSetIt = nodeSet.begin(); nodeSetIt != nodeSet.end(); ++nodeSetIt)
            {
                this->nodeSet[(*nodeSetIt)->getId()] = *nodeSetIt;
                std::set<Link *>::const_iterator linkSetIt;
                for (linkSetIt = (*nodeSetIt)->getLinkSet().begin(); linkSetIt != (*nodeSetIt)->getLinkSet().end(); ++linkSetIt)
                {
                    if (!isLinkInGraph(*linkSetIt))
                    {
                        addLink(*linkSetIt);
                    }
                }
            }
        }

        Graph::~Graph()
        {
        }

        const std::map<unsigned int, Link *> &Graph::getLinkSet() const
        {
            return linkSet;
        }

        const std::map<unsigned int, Node *> &Graph::getNodeSet() const
        {
            return nodeSet;
        }

        void Graph::addNode(Node *node)
        {
            if (!isNodeInGraph(node))
            {
                this->nodeSet[node->getId()] = node;
                std::set<Link *>::const_iterator linkSetIt;
                for (linkSetIt = node->getLinkSet().begin(); linkSetIt != node->getLinkSet().end(); ++linkSetIt)
                {
                    if (!isLinkInGraph(*linkSetIt))
                    {
                        addLink(*linkSetIt);
                    }
                }
            }else{
                std::set<Link *>::const_iterator linkSetIt;
                for (linkSetIt = node->getLinkSet().begin(); linkSetIt != node->getLinkSet().end(); ++linkSetIt)
                {
                    if (!isLinkInGraph(*linkSetIt))
                    {
                        addLink(*linkSetIt);
                    }
                }
            }
        }

        void Graph::addLink(Link *link)
        {
            if (!isLinkInGraph(link))
            {
                this->linkSet[link->getId()] = link;
                Node *from = new Node(link->getFrom()->getId());
                Node *to = new Node(link->getTo()->getId());
                //insert From
                if (isNodeInGraph(from))
                { //Node already exist add only link ot the node
                    nodeSet.at(from->getId())->addLink(link);
                    delete from;
                    from = nullptr;
                }
                else
                {
                    from->addLink(link);
                    addNode(from);
                }
                //insert To
                if (isNodeInGraph(to))
                { //Node already exist add only link ot the node
                    nodeSet.at(to->getId())->addLink(link);
                    delete to;
                    to = nullptr;
                }
                else
                {
                    to->addLink(link);
                    addNode(to);
                }
            }else{
                Node *from = new Node(link->getFrom()->getId());
                Node *to = new Node(link->getTo()->getId());
                //insert From
                if (isNodeInGraph(from))
                { //Node already exist add only link ot the node
                    nodeSet.at(from->getId())->addLink(link);
                    delete from;
                    from = nullptr;
                }
                else
                {
                    from->addLink(link);
                    addNode(from);
                }
                //insert To
                if (isNodeInGraph(to))
                { //Node already exist add only link ot the node
                    nodeSet.at(to->getId())->addLink(link);
                    delete to;
                    to = nullptr;
                }
                else
                {
                    to->addLink(link);
                    addNode(to);
                }
            }
        }

        void Graph::deleteNode(const Node *node)
        {
            if (isNodeInGraph(node))
            {
                Node *nodeToErase = nodeSet.at(node->getId());
                std::set<Link *>::const_iterator linkSetIt;
                for (linkSetIt = nodeToErase->getLinkSet().begin(); linkSetIt != nodeToErase->getLinkSet().end(); ++linkSetIt)
                {
                    if (isLinkInGraph(*linkSetIt))
                    { //maybe useless check
                        if (nodeToErase->getId() == (*linkSetIt)->getFrom()->getId())
                        {
                            if (isNodeInGraph((*linkSetIt)->getTo()))
                            {
                                if (nodeSet.at((*linkSetIt)->getTo()->getId())->getNumberOfLink() > 1)
                                {
                                    //Remove Link
                                    nodeSet.at((*linkSetIt)->getTo()->getId())->deleteLink(*linkSetIt);
                                }
                                else
                                {
                                    //no more link, node isolated!
                                    nodeSet.erase(nodeSet.find((*linkSetIt)->getTo()->getId()));
                                }
                            }
                        }
                        else if (nodeToErase->getId() == (*linkSetIt)->getTo()->getId())
                        {
                            if (isNodeInGraph((*linkSetIt)->getFrom()))
                            {
                                if (nodeSet.at((*linkSetIt)->getFrom()->getId())->getNumberOfLink() > 1)
                                {
                                    //Remove Link
                                    nodeSet.at((*linkSetIt)->getFrom()->getId())->deleteLink(*linkSetIt);
                                }
                                else
                                {
                                    //no more link, node isolated!
                                    nodeSet.erase(nodeSet.find((*linkSetIt)->getFrom()->getId()));
                                }
                            }
                        }
                        else
                        {
                            //Something goes wrong
                        }

                        linkSet.erase(linkSet.find((*linkSetIt)->getId()));
                    }
                }

                nodeSet.erase(nodeSet.find(nodeToErase->getId()));
            }
        }

        void Graph::deleteLink(const Link *link)
        {
            if (isLinkInGraph(link))
            {
                Link *linkToErase = linkSet.at(link->getId());
                if (isNodeInGraph(linkToErase->getFrom()))
                {                    
                    if (nodeSet.at(linkToErase->getFrom()->getId())->getNumberOfLink() > 1)
                    {                        
                        //Remove Link
                        nodeSet.at(linkToErase->getFrom()->getId())->deleteLink(linkToErase);
                    }
                    else
                    {
                        //no more link, node isolated!
                        nodeSet.erase(nodeSet.find(linkToErase->getFrom()->getId()));
                    }
                }
                if (isNodeInGraph(linkToErase->getTo()))
                {
                    if (nodeSet.at(linkToErase->getTo()->getId())->getNumberOfLink() > 1)
                    {
                        //Remove Link
                        nodeSet.at(linkToErase->getTo()->getId())->deleteLink(linkToErase);
                    }
                    else
                    {
                        //no more link, node isolated!
                        nodeSet.erase(nodeSet.find(linkToErase->getTo()->getId()));
                    }
                }

                linkSet.erase(linkSet.find(linkToErase->getId()));
            }
        }

        void Graph::clearGraph()
        {
            nodeSet.clear();
            linkSet.clear();
        }

        void Graph::recreateGraph(std::set<Link *> &linkSet)
        {
            this->linkSet.clear();
            this->nodeSet.clear();
            std::set<Link *>::const_iterator linkSetIt;
            for (linkSetIt = linkSet.begin(); linkSetIt != linkSet.end(); ++linkSetIt)
            {
                this->linkSet[(*linkSetIt)->getId()] = *linkSetIt;
                Node *from = new Node((*linkSetIt)->getFrom()->getId());
                Node *to = new Node((*linkSetIt)->getTo()->getId());
                //insert From
                if (isNodeInGraph(from))
                { //Node already exist add only link ot the node
                    this->nodeSet.at(from->getId())->addLink(*linkSetIt);
                }
                else
                {
                    from->addLink(*linkSetIt);
                    addNode(from);
                }
                //insert To
                if (isNodeInGraph(to))
                { //Node already exist add only link ot the node
                    this->nodeSet.at(to->getId())->addLink(*linkSetIt);
                }
                else
                {
                    to->addLink(*linkSetIt);
                    addNode(to);
                }
            }
        }

        void Graph::recreateGraph(std::set<Node *> &nodeSet)
        {
            this->linkSet.clear();
            this->nodeSet.clear();
            std::set<Node *>::const_iterator nodeSetIt;
            for (nodeSetIt = nodeSet.begin(); nodeSetIt != nodeSet.end(); ++nodeSetIt)
            {
                this->nodeSet[(*nodeSetIt)->getId()] = *nodeSetIt;
                std::set<Link *>::const_iterator linkSetIt;
                for (linkSetIt = (*nodeSetIt)->getLinkSet().begin(); linkSetIt != (*nodeSetIt)->getLinkSet().end(); ++linkSetIt)
                {
                    if (!isLinkInGraph(*linkSetIt))
                    {
                        this->linkSet[(*linkSetIt)->getId()] = *linkSetIt;
                    }
                }
            }
        }

        unsigned int Graph::getNumberOfLink() const
        {
            return linkSet.size();
        }

        unsigned int Graph::getNumberOfNode() const
        {
            return nodeSet.size();
        }

        bool Graph::isNodeInGraph(const Node *node) const
        {
            return (nodeSet.find(node->getId()) != nodeSet.end());
        }

        bool Graph::isLinkInGraph(const Link *link) const
        {
            return (linkSet.find(link->getId()) != linkSet.end());
        }
        
        const Node* Graph::findNodeById(unsigned int id) const
        {
            return (nodeSet.find(id) != nodeSet.end()) ? nodeSet.at(id) : nullptr;
        }
        
        const Link* Graph::findLinkById(unsigned int id) const
        {
            return (linkSet.find(id) != linkSet.end()) ? linkSet.at(id) : nullptr;
        }

    } // namespace BASESTRUCT
} // namespace CXXGRAPH
