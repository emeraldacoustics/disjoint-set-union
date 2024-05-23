#include <vector>

using namespace std;

class DisjointSetsUnion
{
public:
	int n;
	vector<int> p;

	DisjointSetsUnion(void) : n(0)
	{

	}

	void resize(const int & n)
	{
		this->n = n;
		p.clear();
		p.resize(n, -1);
	}

	int root(const int & u)
	{
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}

	bool union_sets(const int & u, const int & v)
	{
		int ur = root(u), vr = root(v);
		if (ur == vr)
			return false;
		else
		{
			if (p[ur] > p[vr])
				swap(ur, vr);
			p[ur] += p[vr];
			p[vr] = ur;
			return true;
		}
	}
};
