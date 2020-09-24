#ifndef __GRAPH_H__
#define __GRAPH_H__

#pragma once

#include <set>
#include "BaseStructure/Node/Node.hpp"
#include "BaseStructure/Link/Link.hpp"

namespace CXXGRAPH
{
	namespace BASESTRUCT
	{
		class Graph
		{
		private:
			std::set<Link> linkSet;
			std::set<Node> nodeSet;

		public:
			Graph();
			Graph(std::set<Link> &linkSet);
			Graph(std::set<Node> &nodeSet);
			~Graph();
			const std::set<Link> &getLinkSet() const;
			const std::set<Node> &getNodeSet() const;
			void addNode(Node &node);
			void addLink(Link &link);
			void deleteNode(Node &node);
			void deleteLink(Link &link);
			void clearGraph();
			void recreateGraph(std::set<Link> &linkSet);
			void recreateGraph(std::set<Node> &nodeSet);
			unsigned int getNumberOfLink() const;
			unsigned int getNumberOfNode() const;
		};
	} // namespace BASESTRUCT
} // namespace CXXGRAPH
#endif // __GRAPH_H__