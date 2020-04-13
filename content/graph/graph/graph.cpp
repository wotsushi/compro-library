#include "graph.hpp"

int main()
{
    // 無向グラフ
    {
        graph<ll> G(4, 4);
        G.add(1, 2);
        G.add(2, 3);
        G.add(3, 4);
        G.add(1, 4);
        assert(G[1] == vector<ii>({ii(2, 1), ii(4, 1)}));
        assert(G[2] == vector<ii>({ii(1, 1), ii(3, 1)}));
        assert(G[3] == vector<ii>({ii(2, 1), ii(4, 1)}));
        assert(G[4] == vector<ii>({ii(3, 1), ii(1, 1)}));
    }
    // 重み付き無向グラフ
    {
        graph<ll> G(4, 4, true);
        G.add(1, 2, 9);
        G.add(2, 3, 8);
        G.add(3, 4, 7);
        G.add(1, 4, 6);
        assert(G[1] == vector<ii>({ii(2, 9), ii(4, 6)}));
        assert(G[2] == vector<ii>({ii(1, 9), ii(3, 8)}));
        assert(G[3] == vector<ii>({ii(2, 8), ii(4, 7)}));
        assert(G[4] == vector<ii>({ii(3, 7), ii(1, 6)}));
    }
    // 有向グラフ
    {
        graph<ll> G(4, 4, false, true);
        G.add(1, 2);
        G.add(2, 3);
        G.add(3, 4);
        G.add(4, 1);
        assert(G[1] == vector<ii>({ii(2, 1)}));
        assert(G[2] == vector<ii>({ii(3, 1)}));
        assert(G[3] == vector<ii>({ii(4, 1)}));
        assert(G[4] == vector<ii>({ii(1, 1)}));
    }
    // 重み付き有向グラフ
    {
        graph<ll> G(4, 4, true, true);
        G.add(1, 2, 9);
        G.add(2, 3, 8);
        G.add(3, 4, 7);
        G.add(4, 1, 6);
        assert(G[1] == vector<ii>({ii(2, 9)}));
        assert(G[2] == vector<ii>({ii(3, 8)}));
        assert(G[3] == vector<ii>({ii(4, 7)}));
        assert(G[4] == vector<ii>({ii(1, 6)}));
    }
    // 標準入力から無向グラフを構築
    {
        graph<ll> G(4, 4);
        string in = "1 2\n2 3\n3 4\n1 4\n";
        istringstream is(in);
        is >> G;
        assert(G[1] == vector<ii>({ii(2, 1), ii(4, 1)}));
        assert(G[2] == vector<ii>({ii(1, 1), ii(3, 1)}));
        assert(G[3] == vector<ii>({ii(2, 1), ii(4, 1)}));
        assert(G[4] == vector<ii>({ii(3, 1), ii(1, 1)}));
    }
    // 標準入力から重み付き無向グラフを構築
    {
        graph<ll> G(4, 4, true);
        string in = "1 2 9\n2 3 8\n3 4 7\n1 4 6\n";
        istringstream is(in);
        is >> G;
        assert(G[1] == vector<ii>({ii(2, 9), ii(4, 6)}));
        assert(G[2] == vector<ii>({ii(1, 9), ii(3, 8)}));
        assert(G[3] == vector<ii>({ii(2, 8), ii(4, 7)}));
        assert(G[4] == vector<ii>({ii(3, 7), ii(1, 6)}));
    }
    // 標準入力から有向グラフを構築
    {
        graph<ll> G(4, 4, false, true);
        string in = "1 2\n2 3\n3 4\n4 1\n";
        istringstream is(in);
        is >> G;
        assert(G[1] == vector<ii>({ii(2, 1)}));
        assert(G[2] == vector<ii>({ii(3, 1)}));
        assert(G[3] == vector<ii>({ii(4, 1)}));
        assert(G[4] == vector<ii>({ii(1, 1)}));
    }
    // 標準入力から重み付き有向グラフを構築
    {
        graph<ll> G(4, 4, true, true);
        string in = "1 2 9\n2 3 8\n3 4 7\n4 1 6\n";
        istringstream is(in);
        is >> G;
        assert(G[1] == vector<ii>({ii(2, 9)}));
        assert(G[2] == vector<ii>({ii(3, 8)}));
        assert(G[3] == vector<ii>({ii(4, 7)}));
        assert(G[4] == vector<ii>({ii(1, 6)}));
    }
}
