#include "Node.hpp"
#include "BaseStructure/Link/Link.hpp"

namespace CXXGRAPH
{
    namespace BASESTRUCT
    {

        Node::Node()
        {
        }

        Node::~Node()
        {
        }

        unsigned int Node::getId() const
        {
            return id;
        }

        std::set<Link> Node::getLinkSet() const
        {
            return linkSet;
        }

        void Node::addLink(Link l)
        {
            linkSet.insert(l);
        }

        void Node::deleteLink(Link l)
        {
            linkSet.erase(l);
        }

        void Node::clearLink()
        {
            linkSet.clear();
        }

        unsigned int Node::getNumberOfLink() const
        {
            return linkSet.size();
        }

        bool Node::operator==(const Node &b) const
        {
        }
    } // namespace BASESTRUCT
} // namespace CXXGRAPH