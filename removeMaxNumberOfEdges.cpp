// DSU class
class DSU{
public:
    vector<int> par, size;
    DSU(int n){
        par.resize(n+1, -1);
        size.resize(n+1, 1);
    }

    int findPar(int u){
        return par[u] == -1 ? u : ( par[u] = findPar(par[u]) );
    }

    bool unite(int u, int v){
        u  = findPar(u);
        v  = findPar(v);
        if( u == v ) return false;
        if(size[u] > size[v]) swap(u, v);
        par[u] = v;
        size[v] += size[u];
        return true;
    }
};


// Solution class
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& es) {
        DSU dsu1(n), dsu2(n);
        int cnt = 0;
        for(auto &e : es){
            if( e[0] == 3  ){
                if( ! dsu1.unite(e[1], e[2]) ) cnt++;
                dsu2.unite(e[1], e[2]);
            }
        }

        for(auto &e : es){
            if( e[0] == 1 && !dsu1.unite(e[1], e[2]) ) cnt++;
            else if( e[0] == 2 && !dsu2.unite(e[1], e[2]) ) cnt++;
        }

        int noOfConnectedComp = 0;
        for(int i=1; i<=n && noOfConnectedComp <= 2; i++ ){
            if( dsu1.par[i] == -1 ) noOfConnectedComp++;
            if( dsu2.par[i] == -1 ) noOfConnectedComp++;
        }
        return noOfConnectedComp == 2 ? cnt : -1;
    }
};