#include <tuple>

#include "context_test.h"
#include <plank/src/test.h>
#include <tmp/src/test.h>

/*    using namespace om636;

*/

int main(int argc, const char* argv[])
{
    using namespace std;
    using namespace om636;

    run_context_test();
    run_math_test<void>();

    return 0;
}
