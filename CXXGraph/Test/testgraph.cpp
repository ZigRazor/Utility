#include "gtest/gtest.h"
#include "BaseStructure/Graph/Graph.hpp"
namespace CXXGRAPH
{
    namespace BASESTRUCT
    {
        class GraphTest : public ::testing::Test
        {
        protected:
            // You can remove any or all of the following functions if their bodies would
            // be empty.

            GraphTest() : node_1(1), node_2(2), node_3(3), link_1(1, &node_1, &node_2), link_2(2, &node_2, &node_1), link_3(3, &node_1, &node_3)
            {
                // You can do set-up work for each test here.
                node_1.addLink(&link_1);
                node_1.addLink(&link_2);
                node_2.addLink(&link_1);
                node_2.addLink(&link_2);
                linkSet_1.insert(&link_1);
                linkSet_1.insert(&link_2);
                nodeSet_1.insert(&node_1);
                nodeSet_1.insert(&node_2);
                linkSet_2.insert(&link_1);
                linkSet_3.insert(&link_2);
                nodeSet_2.insert(&node_1);
                nodeSet_3.insert(&node_2);
                linkSet_4.insert(&link_1);
                linkSet_4.insert(&link_2);
                linkSet_4.insert(&link_3);
                nodeSet_4.insert(&node_1);
                nodeSet_4.insert(&node_2);
                nodeSet_4.insert(&node_3);
            }

            ~GraphTest() override
            {
                // You can do clean-up work that doesn't throw exceptions here.
            }

            // If the constructor and destructor are not enough for setting up
            // and cleaning up each test, you can define the following methods:

            void SetUp() override
            {
                // Code here will be called immediately after the constructor (right
                // before each test).
            }

            void TearDown() override
            {
                // Code here will be called immediately after each test (right
                // before the destructor).
                if (graph)
                {
                    delete graph;
                }
            }

            // Class members declared here can be used by all tests in the test suite
            // for Foo.
            Link link_1, link_2, link_3;
            Node node_1, node_2, node_3;
            std::set<Link *> linkSet_1, linkSet_2, linkSet_3, linkSet_4;
            std::set<Node *> nodeSet_1, nodeSet_2, nodeSet_3, nodeSet_4;
            Graph *graph;
        };

        TEST_F(GraphTest, Constructor_1)
        {
            graph = new Graph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(graph->findNodeById(node_1.getId())->getNumberOfLink(), 2);
            ASSERT_EQ(graph->findNodeById(node_2.getId())->getNumberOfLink(), 2);
            ASSERT_NE(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_2.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_2.getId())->getLinkSet().end());
        }

        TEST_F(GraphTest, Constructor_2)
        {
            graph = new Graph(nodeSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
        }

        TEST_F(GraphTest, Constructor_3)
        {
            graph = new Graph(linkSet_2);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 1);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(graph->findNodeById(node_1.getId())->getNumberOfLink(), 1);
            ASSERT_EQ(graph->findNodeById(node_2.getId())->getNumberOfLink(), 1);
            ASSERT_NE(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_2.getId())->getLinkSet().end());
            ASSERT_EQ(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_EQ(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_2.getId())->getLinkSet().end());
        }

        TEST_F(GraphTest, Constructor_4)
        {
            graph = new Graph(linkSet_3);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 1);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(graph->findNodeById(node_1.getId())->getNumberOfLink(), 1);
            ASSERT_EQ(graph->findNodeById(node_2.getId())->getNumberOfLink(), 1);
            ASSERT_EQ(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_EQ(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_2.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_2.getId())->getLinkSet().end());
        }

        TEST_F(GraphTest, Constructor_5)
        {
            graph = new Graph(nodeSet_2);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
        }

        TEST_F(GraphTest, Constructor_6)
        {
            graph = new Graph(nodeSet_3);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
        }

        TEST_F(GraphTest, Constructor_7)
        {
            graph = new Graph();
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, Destructor_1)
        {
            graph = new Graph(nodeSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            delete graph;
            //TODO Verify something
            graph = nullptr;
        }

        TEST_F(GraphTest, Destructor_2)
        {
            graph = new Graph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            delete graph;
            //TODO Verify something
            graph = nullptr;
        }

        TEST_F(GraphTest, GetLinkSet_1)
        {
            graph = new Graph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            std::map<unsigned int, Link *>::const_iterator it;
            for (it = graph->getLinkSet().begin(); it != graph->getLinkSet().end(); ++it)
            {
                ASSERT_NE(linkSet_1.find(it->second), linkSet_1.end());
            }
            std::set<Link *>::const_iterator it2;
            for (it2 = linkSet_1.begin(); it2 != linkSet_1.end(); ++it2)
            {
                ASSERT_NE(graph->getLinkSet().find((*it2)->getId()), graph->getLinkSet().end());
            }
        }

        TEST_F(GraphTest, GetNodeSet_1)
        {
            graph = new Graph(nodeSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            std::map<unsigned int, Node *>::const_iterator it;
            for (it = graph->getNodeSet().begin(); it != graph->getNodeSet().end(); ++it)
            {
                ASSERT_NE(nodeSet_1.find(it->second), nodeSet_1.end());
            }
            std::set<Node *>::const_iterator it2;
            for (it2 = nodeSet_1.begin(); it2 != nodeSet_1.end(); ++it2)
            {
                ASSERT_NE(graph->getNodeSet().find((*it2)->getId()), graph->getNodeSet().end());
            }
        }

        TEST_F(GraphTest, AddNode_1)
        {
            graph = new Graph();
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
            graph->addNode(&node_1);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            
        }

        TEST_F(GraphTest, AddNode_2)
        {
            graph = new Graph();
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
            graph->addNode(&node_2);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            
        }

        TEST_F(GraphTest, AddNode_3)
        {
            graph = new Graph();
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
            graph->addNode(&node_1);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            graph->addNode(&node_2);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            
        }

        TEST_F(GraphTest, AddNode_4)
        {
            graph = new Graph(linkSet_2);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 1);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(graph->findNodeById(node_1.getId())->getNumberOfLink(), 1);
            ASSERT_EQ(graph->findNodeById(node_2.getId())->getNumberOfLink(), 1);
            ASSERT_NE(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_2.getId())->getLinkSet().end());
            ASSERT_EQ(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_EQ(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_2.getId())->getLinkSet().end());
            graph->addNode(&node_1);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, AddNode_5)
        {
            graph = new Graph(nodeSet_2);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            graph->addNode(&node_1);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, AddLink_1)
        {
            graph = new Graph();
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
            graph->addLink(&link_1);
            ASSERT_EQ(graph->getNumberOfLink(), 1);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
        }
        
        TEST_F(GraphTest, AddLink_2)
        {
            graph = new Graph();
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
            graph->addLink(&link_2);
            ASSERT_EQ(graph->getNumberOfLink(), 1);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, AddLink_3)
        {
            graph = new Graph();
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
            graph->addLink(&link_1);
            ASSERT_EQ(graph->getNumberOfLink(), 1);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            graph->addLink(&link_2);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
        }
        
        TEST_F(GraphTest, AddLink_4)
        {
            graph = new Graph(linkSet_2);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 1);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            graph->addLink(&link_2);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, AddLink_5)
        {
            graph = new Graph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            graph->addLink(&link_2);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, DeleteNode_1)
        {
            graph = new Graph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            graph->deleteNode(&node_1);
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, DeleteNode_2)
        {
            graph = new Graph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            graph->deleteNode(&node_2);
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, DeleteNode_3)
        {
            graph = new Graph(linkSet_4);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 3);
            ASSERT_EQ(graph->getNumberOfNode(), 3);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isLinkInGraph(&link_3));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_3));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_3.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_3.getId())->getTo()), node_3);
            graph->deleteNode(&node_2);
            ASSERT_EQ(graph->getNumberOfLink(), 1);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isLinkInGraph(&link_3));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_3));
        }

        TEST_F(GraphTest, DeleteLink_1)
        {
            graph = new Graph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            graph->deleteLink(&link_1);
            ASSERT_EQ(graph->getNumberOfLink(), 1);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, DeleteLink_2)
        {
            graph = new Graph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            graph->deleteLink(&link_2);
            ASSERT_EQ(graph->getNumberOfLink(), 1);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, DeleteLink_3)
        {
            graph = new Graph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            graph->deleteLink(&link_1);
            ASSERT_EQ(graph->getNumberOfLink(), 1);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            graph->deleteLink(&link_2);
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, ClearGraph_1)
        {
            graph = new Graph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            graph->clearGraph();
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
        }

        TEST_F(GraphTest, RecreateGraph_1)
        {
            graph = new Graph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(graph->findNodeById(node_1.getId())->getNumberOfLink(), 2);
            ASSERT_EQ(graph->findNodeById(node_2.getId())->getNumberOfLink(), 2);
            ASSERT_NE(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_2.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_2.getId())->getLinkSet().end());
            graph->clearGraph();
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
            graph->recreateGraph(linkSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(graph->findNodeById(node_1.getId())->getNumberOfLink(), 2);
            ASSERT_EQ(graph->findNodeById(node_2.getId())->getNumberOfLink(), 2);
            ASSERT_NE(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_1.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_1.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_1), graph->findNodeById(node_2.getId())->getLinkSet().end());
            ASSERT_NE(graph->findNodeById(node_2.getId())->getLinkSet().find(&link_2), graph->findNodeById(node_2.getId())->getLinkSet().end());
        }

        TEST_F(GraphTest, RecreateGraph_2)
        {
            graph = new Graph(nodeSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
            graph->clearGraph();
            ASSERT_EQ(graph->getNumberOfLink(), 0);
            ASSERT_EQ(graph->getNumberOfNode(), 0);
            ASSERT_FALSE(graph->isLinkInGraph(&link_1));
            ASSERT_FALSE(graph->isLinkInGraph(&link_2));
            ASSERT_FALSE(graph->isNodeInGraph(&node_1));
            ASSERT_FALSE(graph->isNodeInGraph(&node_2));
            graph->recreateGraph(nodeSet_1);
            ASSERT_TRUE(graph != nullptr);
            ASSERT_EQ(graph->getNumberOfLink(), 2);
            ASSERT_EQ(graph->getNumberOfNode(), 2);
            ASSERT_TRUE(graph->isLinkInGraph(&link_1));
            ASSERT_TRUE(graph->isLinkInGraph(&link_2));
            ASSERT_TRUE(graph->isNodeInGraph(&node_1));
            ASSERT_TRUE(graph->isNodeInGraph(&node_2));
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getFrom()), node_1);
            ASSERT_EQ(*(graph->findLinkById(link_1.getId())->getTo()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getFrom()), node_2);
            ASSERT_EQ(*(graph->findLinkById(link_2.getId())->getTo()), node_1);
        }
        


    } // namespace BASESTRUCT
} // namespace CXXGRAPH