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

            LinkTest() : a(1), b(2)
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
                if (link)
                {
                    delete link;
                }
            }

            // Class members declared here can be used by all tests in the test suite
            // for Foo.
            Link *link;
            Node a, b;
        };

        TEST_F(LinkTest, Constructor_1)
        {
            link = new Link();
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), INVALID_LINK_ID);
        }

        TEST_F(LinkTest, Constructor_2)
        {
            link = new Link(1, &a, &b);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), 1);
            ASSERT_EQ(link->getFrom(), &a);
            ASSERT_EQ(link->getTo(), &b);
        }

        TEST_F(LinkTest, Constructor_3)
        {
            link = new Link(1, nullptr, nullptr);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), 1);
            ASSERT_EQ(link->getFrom(), nullptr);
            ASSERT_EQ(link->getTo(), nullptr);
        }

        TEST_F(LinkTest, Constructor_4)
        {
            link = new Link(1, &a, nullptr);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), 1);
            ASSERT_EQ(link->getFrom(), &a);
            ASSERT_EQ(link->getTo(), nullptr);
        }

        TEST_F(LinkTest, Constructor_5)
        {
            link = new Link(1, nullptr, &b);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), 1);
            ASSERT_EQ(link->getFrom(), nullptr);
            ASSERT_EQ(link->getTo(), &b);
        }

        TEST_F(LinkTest, Constructor_6)
        {
            link = new Link(1);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getId(), 1);
            ASSERT_EQ(link->getFrom(), nullptr);
            ASSERT_EQ(link->getTo(), nullptr);
        }

        TEST_F(LinkTest, Destructor_1)
        {
            link = new Link();
            ASSERT_TRUE(link != nullptr);
            delete link;
            //TODO Verify something
            link = nullptr;
        }

        TEST_F(LinkTest, Destructor_2)
        {

            link = new Link(1);
            ASSERT_TRUE(link != nullptr);
            delete link;
            //TODO Verify something
            link = nullptr;
        }

        TEST_F(LinkTest, Destructor_3)
        {

            Node a(1);
            Node b(2);
            link = new Link(1, &a, &b);
            ASSERT_TRUE(link != nullptr);
            delete link;
            //TODO Verify something
            link = nullptr;
        }

        TEST_F(LinkTest, GetFromTo_1)
        {
            link = new Link(1, &a, &b);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getFromTo().first, &a);
            ASSERT_EQ(link->getFromTo().second, &b);
        }

        TEST_F(LinkTest, GetFrom_1)
        {
            link = new Link(1, &a, &b);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getFrom(), &a);
        }

        TEST_F(LinkTest, GetTo_1)
        {
            link = new Link(1, &a, &b);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getTo(), &b);
        }

        TEST_F(LinkTest, SetFromTo_1)
        {
            link = new Link(1);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getFromTo().first, nullptr);
            ASSERT_EQ(link->getFromTo().second, nullptr);
            link->setFromTo(&a, &b);
            ASSERT_EQ(link->getFromTo().first, &a);
            ASSERT_EQ(link->getFromTo().second, &b);
        }

        TEST_F(LinkTest, SetFrom_1)
        {
            link = new Link(1);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getFrom(), nullptr);
            link->setFrom(&a);
            ASSERT_EQ(link->getFrom(), &a);
        }

        TEST_F(LinkTest, SetTo_1)
        {
            link = new Link(1);
            ASSERT_TRUE(link != nullptr);
            ASSERT_EQ(link->getTo(), nullptr);
            link->setTo(&b);
            ASSERT_EQ(link->getTo(), &b);
        }

    } // namespace BASESTRUCT
} // namespace CXXGRAPH