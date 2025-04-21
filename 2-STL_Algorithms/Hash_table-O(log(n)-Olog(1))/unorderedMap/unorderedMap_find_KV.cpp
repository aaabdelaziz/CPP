#include <iostream>
#include <unordered_map>

template<typename K, typename V>
typename std::unordered_map<K, V>::const_iterator find_value(const std::unordered_map<K, V>& map, const V& value) {
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it->second == value) {
            return it;
        }
    }
    return map.end(); // Value not found
}

int main() {
    std::unordered_map<int, std::string> myMap = {
        {1, "one"},
        {2, "two"},
        {3, "three"}
    };

    std::string value = "two";
    auto it = find_value(myMap, value);
    if (it != myMap.end()) {
        std::cout << "Key found: " << it->first << std::endl;
    } else {
        std::cout << "Value not found" << std::endl;
    }

    return 0;
}
