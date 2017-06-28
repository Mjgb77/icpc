struct Trie {
	struct Node {
		int cnt, childs[27];
		Node () {
			cnt = 0;
			memset(childs,-1,sizeof(int)*27);
		}
	};
	vector <Node> V;
	Trie () {
		V.push_back(Node());
	}
	void add (const string &S) {
		int id = 0;
		V[id].cnt++;
		for (char c : S) {
			int p = c-'A';
			if (V[id].childs[p] == -1) {
				V[id].childs[p] = V.size();
				V.push_back(Node());
			}
			V[V[id].childs[p]].cnt++;
		}
	}
};
