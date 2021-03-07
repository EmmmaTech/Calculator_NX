#include "gui_app.hpp"
#include "app.hpp"

int main(int argc, char* argv[]) {
    if (run_gui_app()) run_app();
    return EXIT_SUCCESS;
}
