#include <blackcomb/misc/BlackcombUtils.h>

template<typename Key, typename Value>
Value BlackcombUtils::getValOrDefault(std::unordered_map<Key, Value> map, Key key, Value defaultVal) {
    Value res;
    try {
        res = map.at(key);
    } catch (std::exception e) {
        res = defaultVal;
    }
    return res;
}
