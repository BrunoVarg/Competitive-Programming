// disable define int long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

// k-th maior elemento - O(logN) - idx em 0
s.find_by_order(k)

// qtd elementos < k - O(logN)
s.order_of_key(k)

ord_set<int> s;