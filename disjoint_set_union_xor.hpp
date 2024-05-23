#include <vector>

using namespace std;

class DisjointSetsUnionXor
{
public:
	int n;
	vector<int> p;
	vector<int> f;

	DisjointSetsUnionXor(void) : n(0)
	{

	}

	void resize(const int & n)
	{
		this->n = n;
		p.clear();
		p.resize(n, -1);
		f.clear();
		f.resize(n, 0);
	}

	int root(const int & u)
	{
		if (p[u] < 0)
			return u;
		else
		{
			int r = root(p[u]);
			f[u] ^= f[p[u]];
			return p[u] = r;
		}
	}

	bool union_sets(const int & u, const int & v, const int & x)
	{
		int ur = root(u), vr = root(v);
		if (ur == vr)
			return x == (f[u] ^ f[v]);
		else
		{
			if (p[ur] > p[vr])
				swap(ur, vr);
			p[ur] += p[vr];
			p[vr] = ur;
			f[vr] = f[u] ^ f[v] ^ x;
			return true;
		}
	}
};
