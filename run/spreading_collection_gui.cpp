// Copyright © 2023 Giorgio Audrito. All Rights Reserved.

/**
 * @file spreading_collection_gui.cpp
 * @brief Runs a single execution of the spreading collection case study with a graphical user interface.
 */

#include "lib/spreading_collection.hpp"

using namespace fcpp;

#ifdef __EMSCRIPTEN__
#include <emscripten.h>

using net_t = fcpp::component::interactive_simulator<fcpp::option::list>::net;

static net_t* network_ptr = nullptr;

/**
 * @brief Callback function to encapsulate network update status or create a network if it's not existing
 */
void loop() {
    if (!network_ptr) {
        static net_t network{common::make_tagged_tuple<option::name, option::texture, option::speed, option::side, option::devices, option::tvar>(
            "Spreading-Collection Composition",
            "fcpp.png",
            25,
            2000,
            300,
            10
            )};
        network_ptr = &network;
    } else (network_ptr)->update();
}
#endif


int main() {
    #ifdef __EMSCRIPTEN__
        // emscripten main loop to guarantee browser rendering without blocking cycles but with a callback function (loop)  
        emscripten_set_main_loop(loop, 0, 1);
    #else
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
    #endif

    return 0;
}
