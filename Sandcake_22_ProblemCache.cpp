#include <iostream>
#include <map>
#include <utility>

using namespace std;

typedef int index;
typedef int value;


int main() {
	map <index, value> cache_by_index;
	map <value, index> cache_by_value;
	unsigned int max_cache_size;
	cin >> max_cache_size;
	value v;
	index i;
	for (i = 0; cin >> v; ++i) {
		map <value, index> :: iterator MAP_input_value_iterator = cache_by_value.find(v);
		if (MAP_input_value_iterator != cache_by_value.end()) {
			cout << "0 ";
			cache_by_index.erase(cache_by_index.find(MAP_input_value_iterator->second));
		} else
			cout << "1 ";
		cache_by_index.insert(make_pair(i, v));
		cache_by_value[v] = i;
		if (cache_by_value.size() > max_cache_size) {
			cache_by_value.erase(cache_by_value.find((cache_by_index.begin()->second)));
			cache_by_index.erase(cache_by_index.begin());
		}
	}
	return 0;
}
