#ifndef __NODE_H__
#define __NODE_H__

#pragma once

#include <set>
#include <limits>

namespace CXXGRAPH
{
	namespace BASESTRUCT
	{
		static const unsigned int INVALID_NODE_ID = std::numeric_limits<unsigned int>::max();
		class Link;
		class Node
		{
		private:
			unsigned int id;
			std::set<Link> linkSet;
			
		public:
			Node(); //NOT USE
			explicit Node(unsigned int id);
			~Node();
			unsigned int getId() const;
			const std::set<Link>& getLinkSet() const;
			void addLink(Link l);
			void deleteLink(Link l);
			void clearLink();
			unsigned int getNumberOfLink() const;

			//Operator
			bool operator==(const Node &b) const;
			bool operator<(const Node &b) const;
		};
	} // namespace BASESTRUCT
} // namespace CXXGRAPH
#endif // __NODE_H__