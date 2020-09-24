#ifndef __NODE_H__
#define __NODE_H__

#pragma once

#include <set>

namespace CXXGRAPH
{
	namespace BASESTRUCT
	{
		class Link;
		class Node
		{
		private:
		unsigned int id;
			std::set<Link> linkSet;
		public:
			Node();
			~Node();
			unsigned int getId() const;
			std::set<Link> getLinkSet() const;
			void addLink(Link l);
			void deleteLink(Link l);
			void clearLink();
			unsigned int getNumberOfLink() const;

			//Operator
			bool operator ==(const  Node &b ) const;			
		};
	} // namespace BASESTRUCT
} // namespace CXXGRAPH
#endif // __NODE_H__