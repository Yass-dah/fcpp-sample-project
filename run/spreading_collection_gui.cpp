// Copyright © 2023 Giorgio Audrito. All Rights Reserved.

/**
 * @file spreading_collection_gui.cpp
 * @brief Runs a single execution of the spreading collection case study with a graphical user interface.
 */

#include "lib/spreading_collection.hpp"

using namespace fcpp;

int main() {
    using net_t = component::interactive_simulator<option::list>::net;
    net_t network{common::make_tagged_tuple<option::name, option::texture, option::speed, option::side, option::devices, option::tvar>(
        "Spreading-Collection Composition",
        "fcpp.png",
        25,
        2000,
        1000,
        10
        )};
        network.run();

    return 0;
}
