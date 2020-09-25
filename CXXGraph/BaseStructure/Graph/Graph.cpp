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
            std::set<Link>::const_iterator linkSetIt;
            for (linkSetIt = linkSet.begin(); linkSetIt != linkSet.end(); ++linkSetIt)
            {
                this->linkSet[linkSetIt->getId()] = *linkSetIt;
                Node from(linkSetIt->getFrom().getId());
                Node to(linkSetIt->getTo().getId());
                //insert From
                if (isNodeInGraph(from))
                { //Node already exist add only link ot the node
                    nodeSet.at(from.getId()).addLink(*linkSetIt);
                }
                else
                {
                    from.addLink(*linkSetIt);
                    nodeSet[from.getId()] = from;
                }
                //insert To
                if (isNodeInGraph(to))
                { //Node already exist add only link ot the node
                    nodeSet.at(to.getId()).addLink(*linkSetIt);
                }
                else
                {
                    to.addLink(*linkSetIt);
                    nodeSet[to.getId()] = to;
                }
            }
        }

        Graph::Graph(std::set<Node> &nodeSet)
        {
            std::set<Node>::const_iterator nodeSetIt;
            for (nodeSetIt = nodeSet.begin(); nodeSetIt != nodeSet.end(); ++nodeSetIt)
            {
                this->nodeSet[nodeSetIt->getId()] = *nodeSetIt;
                std::set<Link>::const_iterator linkSetIt;
                for (linkSetIt = nodeSetIt->getLinkSet().begin(); linkSetIt != nodeSetIt->getLinkSet().end(); ++linkSetIt)
                {
                    if (!isLinkInGraph(*linkSetIt))
                    {
                        this->linkSet[linkSetIt->getId()] = *linkSetIt;
                    }
                }
            }
        }

        Graph::~Graph()
        {
        }

        const std::map<unsigned int, Link> &Graph::getLinkSet() const
        {
            return linkSet;
        }

        const std::map<unsigned int, Node> &Graph::getNodeSet() const
        {
            return nodeSet;
        }

        void Graph::addNode(Node &node)
        {
            if (!isNodeInGraph(node))
            {
                this->nodeSet[node.getId()] = node;
                std::set<Link>::const_iterator linkSetIt;
                for (linkSetIt = node.getLinkSet().begin(); linkSetIt != node.getLinkSet().end(); ++linkSetIt)
                {
                    if (!isLinkInGraph(*linkSetIt))
                    {
                        this->linkSet[linkSetIt->getId()] = *linkSetIt;
                    }
                }
            }
        }

        void Graph::addLink(Link &link)
        {
            if (!isLinkInGraph(link))
            {
                this->linkSet[link.getId()] = link;
                Node from(link.getFrom().getId());
                Node to(link.getTo().getId());
                //insert From
                if (isNodeInGraph(from))
                { //Node already exist add only link ot the node
                    nodeSet.at(from.getId()).addLink(link);
                }
                else
                {
                    from.addLink(link);
                    nodeSet[from.getId()] = from;
                }
                //insert To
                if (isNodeInGraph(to))
                { //Node already exist add only link ot the node
                    nodeSet.at(to.getId()).addLink(link);
                }
                else
                {
                    to.addLink(link);
                    nodeSet[to.getId()] = to;
                }
            }
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
            this->linkSet.clear();
            this->nodeSet.clear();
            std::set<Link>::const_iterator linkSetIt;
            for (linkSetIt = linkSet.begin(); linkSetIt != linkSet.end(); linkSetIt++)
            {
                this->linkSet[linkSetIt->getId()] = *linkSetIt;
                Node from(linkSetIt->getFrom().getId());
                Node to(linkSetIt->getTo().getId());
                //insert From
                if (isNodeInGraph(from))
                { //Node already exist add only link ot the node
                    this->nodeSet.at(from.getId()).addLink(*linkSetIt);
                }
                else
                {
                    from.addLink(*linkSetIt);
                    this->nodeSet[from.getId()] = from;
                }
                //insert To
                if (isNodeInGraph(to))
                { //Node already exist add only link ot the node
                    this->nodeSet.at(to.getId()).addLink(*linkSetIt);
                }
                else
                {
                    to.addLink(*linkSetIt);
                    this->nodeSet[to.getId()] = to;
                }
            }
        }

        void Graph::recreateGraph(std::set<Node> &nodeSet)
        {
            this->linkSet.clear();
            this->nodeSet.clear();
            std::set<Node>::const_iterator nodeSetIt;
            for (nodeSetIt = nodeSet.begin(); nodeSetIt != nodeSet.end(); nodeSetIt++)
            {
                this->nodeSet[nodeSetIt->getId()] = *nodeSetIt;
                std::set<Link>::const_iterator linkSetIt;
                for (linkSetIt = nodeSetIt->getLinkSet().begin(); linkSetIt != nodeSetIt->getLinkSet().end(); linkSetIt++)
                {
                    if (!isLinkInGraph(*linkSetIt))
                    {
                        this->linkSet[linkSetIt->getId()] = *linkSetIt;
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

        bool Graph::isNodeInGraph(const Node &node) const
        {
            return (nodeSet.find(node.getId()) != nodeSet.end());
        }

        bool Graph::isLinkInGraph(const Link &link) const
        {
            return (linkSet.find(link.getId()) != linkSet.end());
        }

    } // namespace BASESTRUCT
} // namespace CXXGRAPH
