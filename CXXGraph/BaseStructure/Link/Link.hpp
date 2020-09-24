#ifndef __LINK_H__
#define __LINK_H__

#pragma once

#include <utility>
#include "BaseStructure/Node/Node.hpp"
namespace CXXGRAPH
{
	namespace BASESTRUCT
	{
		class Node;
		class Link
		{
		private:
			unsigned int id;
			std::pair<Node,Node> fromTo;

		public:
			Link(unsigned int id, Node &from, Node &to);
			~Link();

			unsigned int getId() const;
			const std::pair<Node,Node> &getFromTo() const;
			const Node &getFrom() const;
			const Node &getTo() const;
			void setFromTo(Node &from, Node& to);
			void setFrom(Node &from);
			void setTo(Node& to);

			//Operators
			bool operator==(const Link &b) const;
			bool operator<(const Link &b) const;
		};
	} // namespace BASESTRUCT
} // namespace CXXGRAPH
#endif // __LINK_H__