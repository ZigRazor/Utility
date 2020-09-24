#include "Link.hpp"

namespace CXXGRAPH
{
    namespace BASESTRUCT
    {

        Link::Link(unsigned int id, Node &from, Node &to) : fromTo(from,to)
        {
            this->id = id;
        }

        Link::~Link()
        {
        }

        unsigned int Link::getId() const
        {
            return id;
        }
        
        const std::pair<Node,Node>& Link::getFromTo() const
        {
            return fromTo;
        }

        const Node &Link::getFrom() const
        {
            return fromTo.first;
        }

        const Node &Link::getTo() const
        {
            return fromTo.second;
        }
        
        void Link::setFromTo(Node &from, Node& to) 
        {
            fromTo.first = from;
            fromTo.second = to;
        }

        void Link::setFrom(Node &from)
        {
            this->fromTo.first = from;
        }

        void Link::setTo(Node &to)
        {
            this->fromTo.second = to;
        }

        bool Link::operator==(const Link &b) const
        {
            return (id == b.id) && (fromTo == b.fromTo);
        }

        bool Link::operator<(const Link &b) const
        {
            return (id < b.id);
        }
    } // namespace BASESTRUCT
} // namespace CXXGRAPH