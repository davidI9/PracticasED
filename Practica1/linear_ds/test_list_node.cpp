/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "list_node.hpp"

int main(int argc, const char *argv[])
{
    int exit_code = EXIT_SUCCESS;
    try
    {
        std::cout.setf(std::ios::unitbuf); // unbuffering output.

        if (argc != 2)
        {
            std::cerr << "Usage: test_list test_case" << std::endl;
            return EXIT_FAILURE;
        }
        std::string filename = argv[1];

        std::ifstream input(argv[1]);
        if (!input)
        {
            std::cerr << "Error: could not open input filename '" << argv[1]
                      << "'." << std::endl;
            return EXIT_FAILURE;
        }
        std::vector<ListNode<int>::Ref> nodes(5);

        while (input)
        {
            std::string operation;
            input >> operation;
            if (input)
            {
                // TESTS FOR ListNode ******************************************
                if (operation == "CREATE_NODE")
                {
                    int idx;
                    input >> idx;
                    std::cout << "Creating node " << idx << " ... ";
                    nodes[idx] = ListNode<int>::create(idx);
                    std::cout << "ok." << std::endl;
                }
                else if (operation == "LINK_NODE_NEXT")
                {
                    int idx1, idx2;
                    input >> idx1 >> idx2;
                    std::cout << "Linking node " << idx2 << " as next of node "
                              << idx1 << " ... ";
                    nodes[idx1]->set_next(nodes[idx2]);
                    std::cout << "ok." << std::endl;
                }
                else if (operation == "LINK_NODE_PREV")
                {
                    int idx1, idx2;
                    input >> idx1 >> idx2;
                    std::cout << "Linking node " << idx2 << " as prev of node "
                              << idx1 << " ... ";
                    nodes[idx1]->set_prev(nodes[idx2]);
                    std::cout << "ok." << std::endl;
                }
                else if (operation == "GET_NODE_NEXT")
                {
                    int idx;
                    input >> idx;
                    std::cout << "Next item of ";
                    std::cout << nodes[idx]->item() << " is ";
                    std::cout << nodes[idx]->next()->item() << std::endl;
                }
                else if (operation == "GET_NODE_PREV")
                {
                    int idx;
                    input >> idx;
                    std::cout << "Prev item of ";
                    std::cout << nodes[idx]->item() << " is ";
                    std::cout << nodes[idx]->prev()->item() << std::endl;
                }
                else if (operation == "NODE_ITEM")
                {
                    int idx;
                    input >> idx;
                    std::cout << "Getting Node " << idx << " item: ";
                    std::cout << nodes[idx]->item() << std::endl;
                }
                else if (operation == "SET_NODE_ITEM")
                {
                    int idx, value;
                    input >> idx >> value;
                    nodes[idx]->set_item(value);
                    std::cout << "Setting node " << idx << " item to: "
                              << value << std::endl;
                }
                else
                {
                    std::cerr << "Error: operation not found '"
                              << operation << "'." << std::endl;
                    return EXIT_FAILURE;
                }
            }
        }
    }
    catch (std::runtime_error &e)
    {
        std::cerr << "Run time exception: " << e.what() << std::endl;
        exit_code = EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "Catched unknown exception!." << std::endl;
        exit_code = EXIT_FAILURE;
    }
    return exit_code;
}
