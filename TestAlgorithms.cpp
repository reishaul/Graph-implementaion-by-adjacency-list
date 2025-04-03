//reishaul!@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Graph/Graph.hpp"
#include "../Algorithms/Algorithms.hpp"
#include <sstream>

using namespace graph;

TEST_CASE("BFS Tests") {
    SUBCASE("BFS on connected graph ") {
        // create graph for example
        graph::Graph g(5);
        g.addEdge(0, 1, 10);
        g.addEdge(0, 2, 6);
        g.addEdge(0, 3, 5);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 4);

        Graph bfs_tree = Algorithms::bfs(g, 0);
        
        // save the output
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        bfs_tree.print_graph();
        
        // recover the original output
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output = 
            "Node 0: (1, weight: 10) (2, weight: 6) (3, weight: 5) \n"
            "Node 1: (0, weight: 10) \n"
            "Node 2: (0, weight: 6) \n"
            "Node 3: (0, weight: 5) \n"
            "Node 4: \n";

        CHECK(actual_output == expected_output);
    }

    SUBCASE("BFS on graph with singles nodes") {
        graph::Graph g(5);
        
        Graph bfs_tree = Algorithms::bfs(g, 0);
        
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        bfs_tree.print_graph();
        
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output =
            "Node 0: \n"
            "Node 1: \n"
            "Node 2: \n"
            "Node 3: \n"
            "Node 4: \n";

        CHECK(actual_output == expected_output);
    }
}

TEST_CASE("DFS Tests") {
    SUBCASE("DFS on connected graph") {
        Graph g(5);
        g.addEdge(0, 1, 10);
        g.addEdge(0, 2, 6);
        g.addEdge(0, 3, 5);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 4);

        Graph dfs_tree = Algorithms::dfs(g, 0);
        
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        dfs_tree.print_graph();
        
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output =
            "Node 0: (3, weight: 5) \n"
            "Node 1: \n"
            "Node 2: \n"
            "Node 3: (1, weight: 15) (2, weight: 4) \n"
            "Node 4: \n";

        CHECK(actual_output == expected_output);
    }

    SUBCASE("DFS on graph with one node only") {
        Graph g_single(1);
        Graph dfs_tree_single = Algorithms::dfs(g_single, 0);
        
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        dfs_tree_single.print_graph();
        
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output = "Node 0: \n";

        CHECK(actual_output == expected_output);
    }
    SUBCASE("DFS on 5 singles nodes") {
        Graph g_single(5);
        Graph dfs_tree_singles = Algorithms::dfs(g_single, 0);
        
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        dfs_tree_singles.print_graph();
        
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output =
            "Node 0: \n"
            "Node 1: \n"
            "Node 2: \n"
            "Node 3: \n"
            "Node 4: \n";

        CHECK(actual_output == expected_output);
    }
}

TEST_CASE("Dijkstra Tests") {
    SUBCASE("Dijkstra on connected graph") {
        Graph g(5); 
        g.addEdge(0, 1, 10);
        g.addEdge(0, 2, 6);
        g.addEdge(0, 3, 5);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 4);

        Graph dijkstra_tree = Algorithms::dijkstra(g, 0);
        
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        dijkstra_tree.print_graph();
        
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output =
            "Node 0: (3, weight: 5) (2, weight: 6) (1, weight: 10) \n"
            "Node 1: \n"
            "Node 2: \n"
            "Node 3: \n"
            "Node 4: (4, weight: 2147483647) \n";

        CHECK(actual_output == expected_output);
    }

    SUBCASE("Dijkstra on one node graph ") {
        Graph g(1);
        Graph dijkstra_tree = Algorithms::dijkstra(g, 0);
        
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        dijkstra_tree.print_graph();
        
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output = "Node 0: \n";

        CHECK(actual_output == expected_output);
    }

    SUBCASE("Dijkstra on a disconnected graph"){
        Graph g(4);
        
        Graph dijkstra_tree = Algorithms::dijkstra(g, 0);
        
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        dijkstra_tree.print_graph();
        
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output =
            "Node 0: \n"
            "Node 1: (1, weight: 2147483647) \n"
            "Node 2: (2, weight: 2147483647) \n"
            "Node 3: (3, weight: 2147483647) \n";

        CHECK(actual_output == expected_output);
    }
}

TEST_CASE("Prim Tests") {
    SUBCASE("Prim on regular graph ") {
        Graph g(5);
        g.addEdge(0, 1, 10);
        g.addEdge(0, 2, 6);
        g.addEdge(0, 3, 5);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 4);

        Graph prim_tree = Algorithms::prim(g);
        
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        prim_tree.print_graph();
        
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output =
            "Node 0: (3, weight: 5) (1, weight: 10) \n"
            "Node 1: \n"
            "Node 2: \n"
            "Node 3: (2, weight: 4) \n"
            "Node 4: \n";

        CHECK(actual_output == expected_output);
    }

    SUBCASE("Prim on disconnected graph") {
        Graph g(5);
        g.addEdge(0, 1, 10);
        g.addEdge(0, 3, 5);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 4, 4);

        Graph prim_tree = Algorithms::prim(g);
        
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        prim_tree.print_graph();
        
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output =
            "Node 0: (3, weight: 5) (1, weight: 10) \n"
            "Node 1: \n"
            "Node 2: \n"
            "Node 3: \n"
            "Node 4: \n";

        CHECK(actual_output == expected_output);
    }
}

TEST_CASE("Kruskal Tests") {
    SUBCASE("Kruskal on regular graph ") {
        Graph g(5);
        g.addEdge(0, 1, 10);
        g.addEdge(0, 3, 5);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 4);

        Graph mst = Algorithms::kruskal(g);
        
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        mst.print_graph();
        
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output =
            "Node 0: (1, weight: 10) (3, weight: 5) \n"
            "Node 1: (0, weight: 10) \n"
            "Node 2: (3, weight: 4) \n"
            "Node 3: (0, weight: 5) (2, weight: 4) \n"
            "Node 4: \n";

        CHECK(actual_output == expected_output);
    }

    SUBCASE("Kruskal on disconnected graph ") {
        Graph g(4);
        g.addEdge(0, 1, 10);
        g.addEdge(2, 3, 5);

        Graph mst = Algorithms::kruskal(g);
        
        std::ostringstream output_stream;
        auto old_buf = std::cout.rdbuf(output_stream.rdbuf());
        
        mst.print_graph();
        
        std::cout.rdbuf(old_buf);
        
        std::string actual_output = output_stream.str();
        std::string expected_output =
            "Node 0: (1, weight: 10) \n"
            "Node 1: (0, weight: 10) \n"
            "Node 2: (3, weight: 5) \n"
            "Node 3: (2, weight: 5) \n";

        CHECK(actual_output == expected_output);
    }
}