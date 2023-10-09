int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //store min weight
        vector<int> key(V,INT_MAX);
        //whether part of BST or NOT
        vector<bool> bst(V,false);
        vector<int> parent(V,-1);
        key[0]=0;
        
        //loop for 1 to N-1 as there are N-1 nodes in BST
        
        for(int i=1;i<V;i++){
            //find node with min weight in key
            int minW = INT_MAX,minV;
            for(int j=0;j<V;j++){
                if(!bst[j] && key[j]<minW){
                    minV = j;
                    minW = key[j];
                }
            }
            
            //now minV is part of bst
            bst[minV] = true;
            for(auto av : adj[minV]){
                int adjV = av[0];
                int adjW = av[1];
                //only if adj V not part of mst AND reaching av is less than previous
                if(!bst[adjV] && adjW < key[adjV]){
                    key[adjV] = adjW;
                    parent[adjV] = minV;
                }
            }
            
        }
        
        int ans = 0;
        for(int i=1;i<V;i++){
            ans = ans + key[i];
        }
        
        return ans;
    }
