#include "gtest/gtest.h"
#include "BaseStructure/Node/Node.hpp"
#include "BaseStructure/Link/Link.hpp"
namespace CXXGRAPH
{
    namespace BASESTRUCT
    {
        class LinkTest : public ::testing::Test
        {
        protected:
            // You can remove any or all of the following functions if their bodies would
            // be empty.

            LinkTest()
            {
                // You can do set-up work for each test here.
            }

            ~LinkTest() override
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
            }

            // Class members declared here can be used by all tests in the test suite
            // for Foo.
        };

        TEST_F(LinkTest, Constructor_1)
        {
            Link *link = new Link();
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), INVALID_LINK_ID);
            //clean
            delete link;
        }

        TEST_F(LinkTest, Constructor_2)
        {
            Node a(1);
            Node b(2);
            Link *link = new Link(1, &a, &b);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), 1);
            ASSERT_EQ(link->getFrom(), &a);
            ASSERT_EQ(link->getTo(), &b);
            //clean
            delete link;
        }

        TEST_F(LinkTest, Constructor_3)
        {
            Link *link = new Link(1, nullptr, nullptr);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), 1);
            ASSERT_EQ(link->getFrom(), nullptr);
            ASSERT_EQ(link->getTo(), nullptr);
            //clean
            delete link;
        }

        TEST_F(LinkTest, Constructor_4)
        {
            Node a(1);
            Link *link = new Link(1, &a, nullptr);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), 1);
            ASSERT_EQ(link->getFrom(), &a);
            ASSERT_EQ(link->getTo(), nullptr);
            //clean
            delete link;
        }

        TEST_F(LinkTest, Constructor_5)
        {
            Node b(2);
            Link *link = new Link(1, nullptr, &b);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), 1);
            ASSERT_EQ(link->getFrom(), nullptr);
            ASSERT_EQ(link->getTo(), &b);
            //clean
            delete link;
        }

        TEST_F(LinkTest, Constructor_6)
        {
            Link *link = new Link(1);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), 1);
            ASSERT_EQ(link->getFrom(), nullptr);
            ASSERT_EQ(link->getTo(), nullptr);
            //clean
            delete link;
        }

        TEST_F(LinkTest, Destructor_1)
        {
            Link *link = new Link();
            ASSERT_TRUE(link != nullptr);
            //clean
            delete link;
            //TODO Verify something
        }

        TEST_F(LinkTest, Destructor_2)
        {

            Link *link = new Link(1);
            ASSERT_TRUE(link != nullptr);
            //clean
            delete link;
            //TODO Verify something
        }

        TEST_F(LinkTest, Destructor_3)
        {

            Node a(1);
            Node b(2);
            Link *link = new Link(1, &a, &b);
            ASSERT_TRUE(link != nullptr);
            //clean
            delete link;
            //TODO Verify something
        }

        TEST_F(LinkTest, GetFromTo_1)
        {

            Node a(1);
            Node b(2);
            Link *link = new Link(1, &a, &b);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getFromTo().first, &a);
            ASSERT_EQ(link->getFromTo().second, &b);
            //clean
            delete link;
            
        }

        TEST_F(LinkTest, GetFrom_1)
        {

            Node a(1);
            Node b(2);
            Link *link = new Link(1, &a, &b);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getFrom(), &a);
            //clean
            delete link;
            
        }

        TEST_F(LinkTest, GetTo_1)
        {

            Node a(1);
            Node b(2);
            Link *link = new Link(1, &a, &b);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getTo(), &b);
            //clean
            delete link;
            
        }

        TEST_F(LinkTest, SetFromTo_1)
        {
            Link *link = new Link(1);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getFromTo().first, nullptr);
            ASSERT_EQ(link->getFromTo().second, nullptr);
            Node a(1);
            Node b(2);
            link->setFromTo(&a,&b);
            ASSERT_EQ(link->getFromTo().first, &a);
            ASSERT_EQ(link->getFromTo().second, &b);
            //clean
            delete link;
            
        }

        TEST_F(LinkTest, SetFrom_1)
        {
            Link *link = new Link(1);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getFrom(), nullptr);
            Node a(1);
            link->setFrom(&a);
            ASSERT_EQ(link->getFrom(), &a);
            //clean
            delete link;            
        }

        TEST_F(LinkTest, SetTo_1)
        {
            Link *link = new Link(1);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getTo(), nullptr);
            Node b(2);
            link->setTo(&b);
            ASSERT_EQ(link->getTo(), &b);
            //clean
            delete link;            
        }


        } // namespace BASESTRUCT
} // namespace CXXGRAPH