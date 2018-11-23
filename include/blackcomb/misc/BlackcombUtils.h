#ifndef BLACKCOMB_UTILS_H
#define BLACKCOMB_UTILS_H

#include <unordered_map>

/**
 * Various useful utilities.
 */
namespace BlackcombUtils {
    template <typename Key, typename Value> Value getValOrDefault(std::unordered_map<Key, Value>& map, Key& key, Value defaultVal = nullptr);
};

#endif //BLACKCOMB_UTILS_H
