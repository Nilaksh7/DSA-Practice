class Twitter {
    unordered_map<int,unordered_set<int>> follows;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int time;
public:
    Twitter() {
        follows.clear();
        tweets.clear();
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto& followerId : follows[userId]){
            for(auto& tweet : tweets[followerId]){
                pq.push(tweet);
            }
        }
        for(auto& tweet : tweets[userId]){
            pq.push(tweet);
        }

        int cnt = 1;
        vector<int> ans;
        while(!pq.empty() && cnt <= 10){
            int timeStamp = pq.top().first;
            int tweetId = pq.top().second;
            pq.pop();

            ans.push_back(tweetId);
            cnt++;
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */