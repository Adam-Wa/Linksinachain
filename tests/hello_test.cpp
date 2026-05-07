#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"
#include "../src/link.hpp"
#include <catch2/catch_test_macros.hpp>


// Acceptance criteria 1: nodes should be objects
TEST_CASE("Node is an object that stores a Link") {
    Link* link = new Link("Steel");
    LinkedListNode* node = new LinkedListNode(link);

    REQUIRE(node->data->get_material() == "Steel");
    REQUIRE(node->next == nullptr);

    delete node->data;
    delete node;
}

// Acceptance criteria 2: create a node and attach it to an existing node
// ch.17 section 17.1.3.1 -- set next pointer to link two nodes together
TEST_CASE("Node can be attached to an existing node") {
    Link* link1 = new Link("Steel");
    Link* link2 = new Link("Iron");

    LinkedListNode* node1 = new LinkedListNode(link1);
    LinkedListNode* node2 = new LinkedListNode(link2);

    node1->next = node2;

    REQUIRE(node1->next->data->get_material() == "Iron");
    REQUIRE(node2->next == nullptr);

    delete node1->data;
    delete node2->data;
    delete node1;
    delete node2;
}

// Acceptance criteria 3: traverse from HEAD to end
// ch.17 section 17.1.3.3 -- traverse() walks curr_node->next until nullptr
TEST_CASE("Traversal from HEAD to end does not crash") {
    LinkedList list;

    list.insert(new Link("Copper"));
    list.insert(new Link("Iron"));
    list.insert(new Link("Steel"));

    REQUIRE_NOTHROW(list.traverse());
}