#include "gtest/gtest.h"
#include "BaseStructure/Node/Node.hpp"
#include "BaseStructure/Link/Link.hpp"
#include <algorithm>
namespace CXXGRAPH
{
    namespace BASESTRUCT
    {
        class NodeTest : public ::testing::Test
        {
        protected:
            // You can remove any or all of the following functions if their bodies would
            // be empty.

            NodeTest() : node2(2), link(1, node, &node2), link2(2, &node2, node)
            {
                // You can do set-up work for each test here.
            }

            ~NodeTest() override
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
                if (node)
                {
                    delete node;
                }
            }

            Node *node;
            Node node2;
            Link link, link2;

            // Class members declared here can be used by all tests in the test suite
            // for Foo.
        };

        TEST_F(NodeTest, Constructor_1)
        {
            node = new Node();
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getId(), INVALID_NODE_ID);
        }

        TEST_F(NodeTest, Constructor_2)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getId(), 1);
            ASSERT_TRUE(node->getLinkSet().empty());
        }

        TEST_F(NodeTest, Destructor_1)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            delete node;
            //TODO Verify something
            node = nullptr;
        }

        TEST_F(NodeTest, AddLink_1)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            node->addLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
        }

        TEST_F(NodeTest, AddLink_2)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            node->addLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            node->addLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 2);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
        }

        TEST_F(NodeTest, AddLink_3)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            node->addLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            node->addLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 2);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            //Insert a node already inserted
            node->addLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 2);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
        }

        TEST_F(NodeTest, AddLink_4)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            for (int i = 0; i < 100000; ++i)
            {
                Link *link = new Link(i, node, &node2);
                node->addLink(link);
                ASSERT_EQ(node->getNumberOfLink(), i + 1);
                ASSERT_NE(node->getLinkSet().find(link), node->getLinkSet().end());
            }
            //clean
            std::set<Link *>::const_iterator it;
            for (it = node->getLinkSet().begin(); it != node->getLinkSet().end(); ++it)
            {
                delete *it;
            }
        }

        TEST_F(NodeTest, DeleteLink_1)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            node->addLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            node->addLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 2);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            node->deleteLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            ASSERT_EQ(node->getLinkSet().find(&link2), node->getLinkSet().end());
        }
        TEST_F(NodeTest, DeleteLink_2)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            node->addLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            node->addLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 2);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            node->deleteLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            ASSERT_EQ(node->getLinkSet().find(&link), node->getLinkSet().end());
        }

        TEST_F(NodeTest, DeleteLink_3)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            node->addLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            node->addLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 2);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            node->deleteLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            ASSERT_EQ(node->getLinkSet().find(&link), node->getLinkSet().end());
            node->deleteLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            ASSERT_EQ(node->getLinkSet().find(&link2), node->getLinkSet().end());
            ASSERT_EQ(node->getLinkSet().find(&link), node->getLinkSet().end());
        }

        TEST_F(NodeTest, DeleteLink_4)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            node->addLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            node->addLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 2);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            node->deleteLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            ASSERT_EQ(node->getLinkSet().find(&link), node->getLinkSet().end());
            //Delete a link already deleted
            node->deleteLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            ASSERT_EQ(node->getLinkSet().find(&link), node->getLinkSet().end());
        }

        TEST_F(NodeTest, DeleteLink_5)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            node->addLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            //Delete link not yet inserted
            node->deleteLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            node->addLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 2);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            node->deleteLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            ASSERT_EQ(node->getLinkSet().find(&link), node->getLinkSet().end());
            node->deleteLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            ASSERT_EQ(node->getLinkSet().find(&link2), node->getLinkSet().end());
            ASSERT_EQ(node->getLinkSet().find(&link), node->getLinkSet().end());
        }

        TEST_F(NodeTest, ClearLink_1)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            node->addLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            node->clearLink();
            ASSERT_EQ(node->getNumberOfLink(), 0);
            ASSERT_EQ(node->getLinkSet().find(&link), node->getLinkSet().end());
        }

        TEST_F(NodeTest, ClearLink_2)
        {
            node = new Node(1);
            ASSERT_TRUE(node != nullptr);
            ASSERT_EQ(node->getNumberOfLink(), 0);
            node->addLink(&link);
            ASSERT_EQ(node->getNumberOfLink(), 1);
            ASSERT_NE(node->getLinkSet().find(&link), node->getLinkSet().end());
            node->addLink(&link2);
            ASSERT_EQ(node->getNumberOfLink(), 2);
            ASSERT_NE(node->getLinkSet().find(&link2), node->getLinkSet().end());
            node->clearLink();
            ASSERT_EQ(node->getNumberOfLink(), 0);
            ASSERT_EQ(node->getLinkSet().find(&link), node->getLinkSet().end());
            ASSERT_EQ(node->getLinkSet().find(&link2), node->getLinkSet().end());
        }

    } // namespace BASESTRUCT
} // namespace CXXGRAPH
