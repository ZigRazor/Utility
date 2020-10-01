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
			std::map<unsigned int, Link *> linkSet;
			std::map<unsigned int, Node *> nodeSet;

		public:
			Graph();
			explicit Graph(std::set<Link *> &linkSet);
			explicit Graph(std::set<Node *> &nodeSet);
			~Graph();
			const std::map<unsigned int, Link *> &getLinkSet() const;
			const std::map<unsigned int, Node *> &getNodeSet() const;
			void addNode(Node *node);
			void addLink(Link *link);
			void deleteNode(const Node *node);
			void deleteLink(const Link *link);
			void clearGraph();
			void recreateGraph(std::set<Link *> &linkSet);
			void recreateGraph(std::set<Node *> &nodeSet);
			unsigned int getNumberOfLink() const;
			unsigned int getNumberOfNode() const;
			bool isNodeInGraph(const Node *node) const;
			bool isLinkInGraph(const Link *link) const;
			const Node *findNodeById(unsigned int id) const;
			const Link *findLinkById(unsigned int id) const;
		};
	} // namespace BASESTRUCT
} // namespace CXXGRAPH
#endif // __GRAPH_H__