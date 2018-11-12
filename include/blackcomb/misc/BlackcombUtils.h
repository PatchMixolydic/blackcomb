#ifndef CRAFTCLONE_UTILS_H
#define CRAFTCLONE_UTILS_H

#include <unordered_map>

namespace BlackcombUtils {
    template <typename Key, typename Value> Value getValOrDefault(std::unordered_map<Key, Value> map, Key key, Value defaultVal = nullptr);
};

#endif //CRAFTCLONE_UTILS_H
