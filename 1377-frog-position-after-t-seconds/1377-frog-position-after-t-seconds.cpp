class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        queue< pair< int,pair< int,double>>> q; //for storing node , time taken , and probabilty for the same
        
        int visit[101] = {0};
        
        map< int,vector< int>> mp;
        
        for(auto x: edges){
            
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
            
        }//create the links for dfs traversal
        
        q.push({1,{0,1}});//initially time = 0 and probability = 0 for 1st node 
        
        visit[1] = 1;
        double ans=-1;
        while(!q.empty()){
            
            int s = q.size();
            
            for(int i=0;i< s;i++){
                
                auto p = q.front();
                int src = p.first;
                int time = p.second.first;
                double prob = p.second.second;
                q.pop();
                
                if(src==target && time<=t){
                    ans = prob;
                    
                    int vis_remaining = 0;//for checking if the required node does not have any unvisited connections
                    //becasue if there is any unvisited node remaining then the frog will jump there and cannot come back as the required node is now visited
                    
                    for(auto x: mp[src]){
                        if(visit[x]==0){
                            vis_remaining++;
                        }
                    }
                        
                    if(vis_remaining!=0 && time< t){
                        ans = 0.0*prob; //make ans to 0
                        
                    }
                    break;
                }
                
                int vis = 0;
                //now for calculating the probability we need to know the number of paths frog can take
                for(auto x: mp[src]){
                    
                    if(visit[x]==0){
                        vis++;
                    }
                }
                for(auto x:mp[src]){
                    if(visit[x]==0){
                        double p_t = 1.0*double(1.0/double(vis)); //probablity for going to the next path
                        q.push({x,{time+1,prob*p_t}});
                        visit[x] = 1;
                    }
                }
                
            }
            
            if(ans !=-1)
                break;
            
        }
        
        if(ans==-1){
            return 0.0;
        }
        return ans;
    }
};