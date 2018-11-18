#include "blackcomb/misc/RNG.h"

misc::RNG::RNG() : generator(rd()) {}

misc::RNG::RNG(unsigned long seed) : generator(rd()) {
    generator.seed(seed);
}

/**
 * Generates a random number in a range from min to max, inclusive.
 * @tparam T The type of the number, either float, double, or long double (for int, see randInt).
 */
template<typename T>
T misc::RNG::randRange(T min, T max) {
    std::uniform_real_distribution<T> distribution(min, max);
    return distribution(generator);
}

/**
 * Generates a random real number from zero to one, inclusive.
 * @tparam T They type of the number, which must be float, double, or long double (for integer, use choice<int>({0, 1})).
 */
template<typename T>
T misc::RNG::random() {
    return random<T>(0.0, 1.0);
}

/**
 * Generates a random integer in a range from min to max, inclusive.
 * @tparam T The type of the number, which must be an integer (short, int, long, long long, and unsigned variants). For floats, see randRange type.
 */
template<typename T>
T misc::RNG::randInt(T min, T max) {
    std::uniform_int_distribution<T> distribution(min, max);
    return distribution(generator);
}

/**
 * Selects a random element from a vector.
 */
template<typename T>
T misc::RNG::choice(std::vector<T> vec) {
    return vec.at(randInt<unsigned long>(0, vec.size() - 1));
}
