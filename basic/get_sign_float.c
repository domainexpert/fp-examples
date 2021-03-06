
#include <klee/klee.h>

int calculate_output(float x, float y)
{
    float z;

    if (x < 5) {
        z = x + y;
    } else {
        z = x * y;
    }
    return z;
}

int main()
{
    float output;
    float input_x, input_y;
    
    klee_make_symbolic(&input_x, sizeof(input_x), "input_x");
    klee_make_symbolic(&input_y, sizeof(input_y), "input_y");

    klee_track_error(&input_x, "input_x_error");
    klee_track_error(&input_y, "input_y_error");
 
    output = calculate_output(input_x, input_y);

    klee_bound_error(output, 1.3);
    
    return 0;
}
