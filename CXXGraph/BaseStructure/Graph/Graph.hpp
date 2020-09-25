#ifndef __GRAPH_H__
#define __GRAPH_H__

#pragma once

#include <map>
#include "BaseStructure/Node/Node.hpp"
#include "BaseStructure/Link/Link.hpp"

namespace CXXGRAPH
{
	namespace BASESTRUCT
	{
		class Graph
		{
		private:
			std::map<unsigned int,Link> linkSet;
			std::map<unsigned int,Node> nodeSet;

		public:
			Graph();
			Graph(std::set<Link> &linkSet);
			Graph(std::set<Node> &nodeSet);
			~Graph();
			const std::map<unsigned int,Link> &getLinkSet() const;
			const std::map<unsigned int,Node> &getNodeSet() const;
			void addNode(Node &node);
			void addLink(Link &link);
			void deleteNode(Node &node);
			void deleteLink(Link &link);
			void clearGraph();
			void recreateGraph(std::set<Link> &linkSet);
			void recreateGraph(std::set<Node> &nodeSet);
			unsigned int getNumberOfLink() const;
			unsigned int getNumberOfNode() const;
			bool isNodeInGraph(const Node &node) const;
			bool isLinkInGraph(const Link &link) const;
			Node& findNodeById(unsigned int id) const;
			Link& findLinkById(unsigned int id) const;
		};
	} // namespace BASESTRUCT
} // namespace CXXGRAPH
#endif // __GRAPH_H__