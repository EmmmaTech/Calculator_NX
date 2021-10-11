#include <singleton.hpp>

struct ShouldQuit
{
    NON_COPYABLE(ShouldQuit)
    NON_MOVABLE(ShouldQuit)

    static ShouldQuit& getInstance();

    void set(bool n);
    bool get();

    private:
    ShouldQuit() = default;

    bool shouldQuit;
};