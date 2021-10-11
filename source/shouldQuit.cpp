#include <shouldQuit.hpp>

ShouldQuit& ShouldQuit::getInstance()
{
    static ShouldQuit sq;
    return sq;
}

void ShouldQuit::set(bool n)
{
    shouldQuit = n;
}

bool ShouldQuit::get()
{
    return shouldQuit;
}
